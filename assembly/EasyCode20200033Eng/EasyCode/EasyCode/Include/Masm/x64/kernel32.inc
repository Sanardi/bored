; ======================================================;
;                                                       ;
;  kernel32.inc for Easy Code 2.0 64-bit Masm projects  ;
;                   (version 1.0.12)                    ;
;                                                       ;
;          Copyright © Ramon Sala - 2015-2021           ;
;                                                       ;
; ======================================================;

IFNDEF KERNEL32_INC
KERNEL32_INC     EQU     1

IFNDEF ANYSIZE_ARRAY
    ANYSIZE_ARRAY                               EQU     1
ENDIF

IFNDEF EXCEPTION_MAXIMUM_PARAMETERS
    EXCEPTION_MAXIMUM_PARAMETERS                EQU     15
ENDIF

IFDEF APP_WIN64
    MAX_NATURAL_ALIGNMENT                       EQU     QWORD
ELSE
    MAX_NATURAL_ALIGNMENT                       EQU     DWORD
ENDIF

IFNDEF UCSCHAR_INVALID_CHARACTER
    UCSCHAR_INVALID_CHARACTER                   EQU     0FFFFFFFFH
    MIN_UCSCHAR                                 EQU     0
    MAX_UCSCHAR                                 EQU     0010FFFFH
ENDIF

MAXLONGLONG                                     EQU     7FFFFFFFFFFFFFFFH

GUID_MAX_POWER_SAVINGS                          EQU     {0A1841308H, 03541H, 04FABH, {0BCH, 081H, 0F7H, 015H, 056H, 0F2H, 00BH, 04AH}}
GUID_MIN_POWER_SAVINGS                          EQU     {08C5E7FDAH, 0E8BFH, 04A96H, {09AH, 085H, 0A6H, 0E2H, 03AH, 08CH, 063H, 05CH}}
GUID_TYPICAL_POWER_SAVINGS                      EQU     {0381B4222H, 0F694H, 041F0H, {096H, 085H, 0FFH, 05BH, 0B2H, 060H, 0DFH, 02EH}}
NO_SUBGROUP_GUID                                EQU     {0FEA3413EH, 07E05H, 04911H, {09AH, 071H, 070H, 003H, 031H, 0F1H, 0C2H, 094H}}
ALL_POWERSCHEMES_GUID                           EQU     {068A1E95EH, 013EAH, 041E1H, {080H, 011H, 00CH, 049H, 06CH, 0A4H, 090H, 0B0H}}
GUID_POWERSCHEME_PERSONALITY                    EQU     {0245D8541H, 03943H, 04422H, {0B0H, 025H, 013H, 0A7H, 084H, 0F6H, 079H, 0B7H}}
GUID_ACTIVE_POWERSCHEME                         EQU     {031F9F286H, 05084H, 042FEH, {0B7H, 020H, 02BH, 002H, 064H, 099H, 037H, 063H}}
GUID_VIDEO_SUBGROUP                             EQU     {07516B95FH, 0F776H, 04464H, {08CH, 053H, 006H, 016H, 07FH, 040H, 0CCH, 099H}}
GUID_VIDEO_POWERDOWN_TIMEOUT                    EQU     {03C0BC021H, 0C8A8H, 04E07H, {0A9H, 073H, 06BH, 014H, 0CBH, 0CBH, 02BH, 07EH}}
GUID_VIDEO_ANNOYANCE_TIMEOUT                    EQU     {082DBCF2DH, 0CD67H, 040C5H, {0BFH, 0DCH, 09FH, 01AH, 05CH, 0CDH, 046H, 063H}}
GUID_VIDEO_ADAPTIVE_PERCENT_INCREASE            EQU     {0EED904DFH, 0B142H, 04183H, {0B1H, 00BH, 05AH, 011H, 097H, 0A3H, 078H, 064H}}
GUID_VIDEO_DIM_TIMEOUT                          EQU     {017AAA29BH, 08B43H, 04B94H, {0AAH, 0FEH, 035H, 0F6H, 04DH, 0AAH, 0F1H, 0EEH}}
GUID_VIDEO_ADAPTIVE_POWERDOWN                   EQU     {090959D22H, 0D6A1H, 049B9H, {0AFH, 093H, 0BCH, 0E8H, 085H, 0ADH, 033H, 05BH}}
GUID_MONITOR_POWER_ON                           EQU     {002731015H, 04510H, 04526H, {099H, 0E6H, 0E5H, 0A1H, 07EH, 0BDH, 01AH, 0EAH}}
GUID_DEVICE_POWER_POLICY_VIDEO_BRIGHTNESS       EQU     {0ADED5E82H, 0B909H, 04619H, {099H, 049H, 0F5H, 0D7H, 01DH, 0ACH, 00BH, 0CBH}}
GUID_DEVICE_POWER_POLICY_VIDEO_DIM_BRIGHTNESS   EQU     {0F1FBFDE2H, 0A960H, 04165H, {09FH, 088H, 050H, 066H, 079H, 011H, 0CEH, 096H}}
GUID_VIDEO_CURRENT_MONITOR_BRIGHTNESS           EQU     {08FFEE2C6H, 02D01H, 046BEH, {0ADH, 0B9H, 039H, 08AH, 0DDH, 0C5H, 0B4H, 0FFH}}
GUID_VIDEO_ADAPTIVE_DISPLAY_BRIGHTNESS          EQU     {0FBD9AA66H, 09553H, 04097H, {0BAH, 044H, 0EDH, 06EH, 09DH, 065H, 0EAH, 0B8H}}
GUID_SESSION_DISPLAY_STATE                      EQU     {073A5E93AH, 05BB1H, 04F93H, {089H, 05BH, 0DBH, 0D0H, 0DAH, 085H, 059H, 067H}}
GUID_CONSOLE_DISPLAY_STATE                      EQU     {06FE69556H, 0704AH, 047A0H, {08FH, 024H, 0C2H, 08DH, 093H, 06FH, 0DAH, 047H}}
GUID_ALLOW_DISPLAY_REQUIRED                     EQU     {0A9CEB8DAH, 0CD46H, 044FBH, {0A9H, 08BH, 002H, 0AFH, 069H, 0DEH, 046H, 023H}}
GUID_DISK_SUBGROUP                              EQU     {00012EE47H, 09041H, 04B5DH, {09BH, 077H, 053H, 05FH, 0BAH, 08BH, 014H, 042H}}
GUID_DISK_POWERDOWN_TIMEOUT                     EQU     {06738E2C4H, 0E8A5H, 04A42H, {0B1H, 06AH, 0E0H, 040H, 0E7H, 069H, 075H, 06EH}}
GUID_DISK_BURST_IGNORE_THRESHOLD                EQU     {080E3C60EH, 0BB94H, 04AD8H, {0BBH, 0E0H, 00DH, 031H, 095H, 0EFH, 0C6H, 063H}}
GUID_DISK_ADAPTIVE_POWERDOWN                    EQU     {0396A32E1H, 0499AH, 040B2H, {091H, 024H, 0A9H, 06AH, 0FEH, 070H, 076H, 067H}}
GUID_SLEEP_SUBGROUP                             EQU     {0238C9FA8H, 00AADH, 041EDH, {083H, 0F4H, 097H, 0BEH, 024H, 02CH, 08FH, 020H}}
GUID_SLEEP_IDLE_THRESHOLD                       EQU     {081CD32E0H, 07833H, 044F3H, {087H, 037H, 070H, 081H, 0F3H, 08DH, 01FH, 070H}}
GUID_STANDBY_TIMEOUT                            EQU     {029F6C1DBH, 086DAH, 048C5H, {09FH, 0DBH, 0F2H, 0B6H, 07BH, 01FH, 044H, 0DAH}}
GUID_UNATTEND_SLEEP_TIMEOUT                     EQU     {07BC4A2F9H, 0D8FCH, 04469H, {0B0H, 07BH, 033H, 0EBH, 078H, 05AH, 0ACH, 0A0H}}
GUID_HIBERNATE_TIMEOUT                          EQU     {09D7815A6H, 07EE4H, 0497EH, {088H, 088H, 051H, 05AH, 005H, 0F0H, 023H, 064H}}
GUID_HIBERNATE_FASTS4_POLICY                    EQU     {094AC6D29H, 073CEH, 041A6H, {080H, 09FH, 063H, 063H, 0BAH, 021H, 0B4H, 07EH}}
GUID_CRITICAL_POWER_TRANSITION                  EQU     {0B7A27025H, 0E569H, 046c2H, {0A5H, 004H, 02BH, 096H, 0CAH, 0D2H, 025H, 0A1H}}
GUID_SYSTEM_AWAYMODE                            EQU     {098A7F580H, 001F7H, 048AAH, {09CH, 00FH, 044H, 035H, 02CH, 029H, 0E5H, 0C0H}}
GUID_ALLOW_AWAYMODE                             EQU     {025DFA149H, 05DD1H, 04736H, {0B5H, 0ABH, 0E8H, 0A3H, 07BH, 05BH, 081H, 087H}}
GUID_ALLOW_STANDBY_STATES                       EQU     {0ABFC2519H, 03608H, 04C2AH, {094H, 0EAH, 017H, 01BH, 00EH, 0D5H, 046H, 0ABH}}
GUID_ALLOW_RTC_WAKE                             EQU     {0BD3B718AH, 00680H, 04D9DH, {08AH, 0B2H, 0E1H, 0D2H, 0B4H, 0ACH, 080H, 06DH}}
GUID_ALLOW_SYSTEM_REQUIRED                      EQU     {0A4B195F5H, 08225H, 047D8H, {080H, 012H, 09DH, 041H, 036H, 097H, 086H, 0E2H}}
GUID_SYSTEM_BUTTON_SUBGROUP                     EQU     {04F971E89H, 0EEBDH, 04455H, {0A8H, 0DEH, 09EH, 059H, 004H, 00EH, 073H, 047H}}
GUID_POWERBUTTON_ACTION                         EQU     {07648EFA3H, 0DD9CH, 04E3EH, {0B5H, 066H, 050H, 0F9H, 029H, 038H, 062H, 080H}}
GUID_POWERBUTTON_ACTION_FLAGS                   EQU     {0857E7FACH, 0034BH, 04704H, {0ABH, 0B1H, 0BCH, 0A5H, 04AH, 0A3H, 014H, 078H}}
GUID_SLEEPBUTTON_ACTION                         EQU     {096996BC0H, 0AD50H, 047ECH, {092H, 03BH, 06FH, 041H, 087H, 04DH, 0D9H, 0EBH}}
GUID_SLEEPBUTTON_ACTION_FLAGS                   EQU     {02A160AB1H, 0B69DH, 04743H, {0B7H, 018H, 0BFH, 014H, 041H, 0D5H, 0E4H, 093H}}
GUID_USERINTERFACEBUTTON_ACTION                 EQU     {0A7066653H, 08D6CH, 040A8H, {091H, 00EH, 0A1H, 0F5H, 04BH, 084H, 0C7H, 0E5H}}
GUID_LIDCLOSE_ACTION                            EQU     {05CA83367H, 06E45H, 0459FH, {0A2H, 07BH, 047H, 06BH, 01DH, 001H, 0C9H, 036H}}
GUID_LIDCLOSE_ACTION_FLAGS                      EQU     {097E969ACH, 00D6CH, 04D08H, {092H, 07CH, 0D7H, 0BDH, 07AH, 0D7H, 085H, 07BH}}
GUID_LIDOPEN_POWERSTATE                         EQU     {099FF10E7H, 023B1H, 04C07H, {0A9H, 0D1H, 05CH, 032H, 006H, 0D7H, 041H, 0B4H}}
GUID_BATTERY_SUBGROUP                           EQU     {0E73A048DH, 0BF27H, 04F12H, {097H, 031H, 08BH, 020H, 076H, 0E8H, 089H, 01FH}}
GUID_BATTERY_DISCHARGE_ACTION_0                 EQU     {0637EA02FH, 0BBCBH, 04015H, {08EH, 02CH, 0A1H, 0C7H, 0B9H, 0C0H, 0B5H, 046H}}
GUID_BATTERY_DISCHARGE_LEVEL_0                  EQU     {09A66D8D7H, 04FF7H, 04EF9H, {0B5H, 0A2H, 05AH, 032H, 06CH, 0A2H, 0A4H, 069H}}
GUID_BATTERY_DISCHARGE_FLAGS_0                  EQU     {05DBB7C9FH, 038E9H, 040D2H, {097H, 049H, 04FH, 08AH, 00EH, 09FH, 064H, 00FH}}
GUID_BATTERY_DISCHARGE_ACTION_1                 EQU     {0D8742DCBH, 03E6AH, 04B3CH, {0B3H, 0FEH, 037H, 046H, 023H, 0CDH, 0CFH, 006H}}
GUID_BATTERY_DISCHARGE_LEVEL_1                  EQU     {08183BA9AH, 0E910H, 048DAH, {087H, 069H, 014H, 0AEH, 06DH, 0C1H, 017H, 00AH}}
GUID_BATTERY_DISCHARGE_FLAGS_1                  EQU     {0BCDED951H, 0187BH, 04D05H, {0BCH, 0CCH, 0F7H, 0E5H, 019H, 060H, 0C2H, 058H}}
GUID_BATTERY_DISCHARGE_ACTION_2                 EQU     {0421CBA38H, 01A8EH, 04881H, {0ACH, 089H, 0E3H, 03AH, 08BH, 004H, 0ECH, 0E4H}}
GUID_BATTERY_DISCHARGE_LEVEL_2                  EQU     {007A07CA2H, 0ADAFH, 040D7H, {0B0H, 077H, 053H, 03AH, 0ADH, 0EDH, 01BH, 0FAH}}
GUID_BATTERY_DISCHARGE_FLAGS_2                  EQU     {07FD2F0C4H, 0FEB7H, 04DA3H, {081H, 017H, 0E3H, 0FBH, 0EDH, 0C4H, 065H, 082H}}
GUID_BATTERY_DISCHARGE_ACTION_3                 EQU     {080472613H, 09780H, 0455EH, {0B3H, 008H, 072H, 0D3H, 000H, 03CH, 0F2H, 0F8H}}
GUID_BATTERY_DISCHARGE_LEVEL_3                  EQU     {058AFD5A6H, 0C2DDH, 047D2H, {09FH, 0BFH, 0EFH, 070H, 0CCH, 05CH, 059H, 065H}}
GUID_BATTERY_DISCHARGE_FLAGS_3                  EQU     {073613CCFH, 0DBFAH, 04279H, {083H, 056H, 049H, 035H, 0f6H, 0bfH, 062H, 0F3H}}
GUID_PROCESSOR_SETTINGS_SUBGROUP                EQU     {054533251H, 082BEH, 04824H, {096H, 0C1H, 047H, 0B6H, 00BH, 074H, 00DH, 000H}}
GUID_PROCESSOR_THROTTLE_POLICY                  EQU     {057027304H, 04AF6H, 04104H, {092H, 060H, 0E3H, 0D9H, 052H, 048H, 0FCH, 036H}}
GUID_PROCESSOR_THROTTLE_MAXIMUM                 EQU     {0BC5038F7H, 023E0H, 04960H, {096H, 0DAH, 033H, 0ABH, 0AFH, 059H, 035H, 0ECH}}
GUID_PROCESSOR_THROTTLE_MINIMUM                 EQU     {0893DEE8EH, 02BEFH, 041E0H, {089H, 0C6H, 0B5H, 05DH, 009H, 029H, 096H, 04CH}}
GUID_PROCESSOR_ALLOW_THROTTLING                 EQU     {03B04D4FDH, 01CC7H, 04F23H, {0ABH, 01CH, 0D1H, 033H, 078H, 019H, 0C4H, 0BBH}}
GUID_PROCESSOR_IDLESTATE_POLICY                 EQU     {068F262A7H, 0F621H, 04069H, {0B9H, 0A5H, 048H, 074H, 016H, 09BH, 0E2H, 03CH}}
GUID_PROCESSOR_PERFSTATE_POLICY                 EQU     {0BBDC3814H, 018E9H, 04463H, {08AH, 055H, 0D1H, 097H, 032H, 07CH, 045H, 0C0H}}
GUID_PROCESSOR_PERF_INCREASE_THRESHOLD          EQU     {006CADF0EH, 064EDH, 0448AH, {089H, 027H, 0CEH, 07BH, 0F9H, 00EH, 0B3H, 05DH}}
GUID_PROCESSOR_PERF_DECREASE_THRESHOLD          EQU     {012A0AB44H, 0FE28H, 04FA9H, {0B3H, 0BDH, 04BH, 064H, 0F4H, 049H, 060H, 0A6H}}
GUID_PROCESSOR_PERF_INCREASE_POLICY             EQU     {0465E1F50H, 0B610H, 0473AH, {0ABH, 058H, 000H, 0D1H, 007H, 07DH, 0C4H, 018H}}
GUID_PROCESSOR_PERF_DECREASE_POLICY             EQU     {040FBEFC7H, 02E9DH, 04D25H, {0A1H, 085H, 00CH, 0FDH, 085H, 074H, 0BAH, 0C6H}}
GUID_PROCESSOR_PERF_INCREASE_TIME               EQU     {0984CF492H, 03BEDH, 04488H, {0A8H, 0F9H, 042H, 086H, 0C9H, 07BH, 0F5H, 0AAH}}
GUID_PROCESSOR_PERF_DECREASE_TIME               EQU     {0D8EDEB9BH, 095CFH, 04F95H, {0A7H, 03CH, 0B0H, 061H, 097H, 036H, 093H, 0C8H}}
GUID_PROCESSOR_PERF_TIME_CHECK                  EQU     {04D2B0152H, 07D5CH, 0498BH, {088H, 0E2H, 034H, 034H, 053H, 092H, 0A2H, 0C5H}}
GUID_PROCESSOR_PERF_BOOST_POLICY                EQU     {045BCC044H, 0D885H, 043E2H, {086H, 005H, 0EEH, 00EH, 0C6H, 0E9H, 06BH, 059H}}
GUID_SYSTEM_COOLING_POLICY                      EQU     {094D3A615H, 0A899H, 04AC5H, {0AEH, 02BH, 0E4H, 0D8H, 0F6H, 034H, 036H, 07FH}}
GUID_LOCK_CONSOLE_ON_WAKE                       EQU     {00E796BDBH, 0100DH, 047D6H, {0A2H, 0D5H, 0F7H, 0D2H, 0DAH, 0A5H, 01FH, 051H}}
GUID_DEVICE_IDLE_POLICY                         EQU     {04FAAB71AH, 092E5H, 04726H, {0B5H, 031H, 022H, 045H, 059H, 067H, 02DH, 019H}}
GUID_PPM_PERFSTATE_CHANGE_GUID                  EQU     {0A5B32DDDH, 07F39H, 04ABCH, {0B8H, 092H, 090H, 00EH, 043H, 0B5H, 09EH, 0BBH}}
GUID_PPM_PERFSTATE_DOMAIN_CHANGE_GUID           EQU     {0995E6B7FH, 0D653H, 0497AH, {0B9H, 078H, 036H, 0A3H, 00CH, 029H, 0BFH, 001H}}
GUID_PPM_IDLESTATE_CHANGE_GUID                  EQU     {04838FE4FH, 0F71CH, 04E51H, {09EH, 0CCH, 084H, 030H, 0A7H, 0ACH, 04CH, 06CH}}
GUID_PPM_PERFSTATES_DATA_GUID                   EQU     {05708CC20H, 07D40H, 04BF4H, {0B4H, 0AAH, 02BH, 001H, 033H, 08DH, 001H, 026H}}
GUID_PPM_IDLESTATES_DATA_GUID                   EQU     {0BA138E10H, 0E250H, 04AD7H, {086H, 016H, 0CFH, 01AH, 07AH, 0D4H, 010H, 0E7H}}
GUID_PPM_IDLE_ACCOUNTING_GUID                   EQU     {0E2A26F78H, 0AE07H, 04EE0H, {0A3H, 00FH, 0CEH, 054H, 0F5H, 05AH, 094H, 0CDH}}
GUID_PPM_THERMALCONSTRAINT_GUID                 EQU     {0A852C2C8H, 01A4CH, 0423BH, {08CH, 02CH, 0F3H, 00DH, 082H, 093H, 01AH, 088H}}
GUID_PPM_PERFMON_PERFSTATE_GUID                 EQU     {07FD18652H, 00CFEH, 040D2H, {0B0H, 0A1H, 00BH, 006H, 06AH, 087H, 075H, 09EH}}
GUID_PPM_THERMAL_POLICY_CHANGE_GUID             EQU     {048F377B8H, 06880H, 04C7BH, {08BH, 0DCH, 038H, 001H, 076H, 0C6H, 065H, 04DH}}
GUID_NULL                                       EQU     {000000000H, 00000H, 00000H, {000H, 000H, 000H, 000H, 000H, 000H, 000H, 000H}}

ANSI_NULL                                       EQU     0
UNICODE_NULL                                    EQU     0

MINCHAR                                         EQU     80H
MAXCHAR                                         EQU     7FH
MINSHORT                                        EQU     8000H
MAXSHORT                                        EQU     7FFFH
MINLONG                                         EQU     80000000H
MAXLONG                                         EQU     07FFFFFFFH
MAXBYTE                                         EQU     0FFH
MAXWORD                                         EQU     0FFFFH
MAXDWORD                                        EQU     0FFFFFFFFH

NLS_VALID_LOCALE_MASK                           EQU     000FFFFFH

VER_SERVER_NT                                   EQU     80000000H
VER_WORKSTATION_NT                              EQU     40000000H
VER_SUITE_SMALLBUSINESS                         EQU     00000001H
VER_SUITE_ENTERPRISE                            EQU     00000002H
VER_SUITE_BACKOFFICE                            EQU     00000004H
VER_SUITE_COMMUNICATIONS                        EQU     00000008H
VER_SUITE_TERMINAL                              EQU     00000010H
VER_SUITE_SMALLBUSINESS_RESTRICTED              EQU     00000020H
VER_SUITE_EMBEDDEDNT                            EQU     00000040H
VER_SUITE_DATACENTER                            EQU     00000080H
VER_SUITE_SINGLEUSERTS                          EQU     00000100H
VER_SUITE_PERSONAL                              EQU     00000200H
VER_SUITE_BLADE                                 EQU     00000400H
VER_SUITE_EMBEDDED_RESTRICTED                   EQU     00000800H
VER_SUITE_SECURITY_APPLIANCE                    EQU     00001000H
VER_SUITE_STORAGE_SERVER                        EQU     00002000H
VER_SUITE_COMPUTE_SERVER                        EQU     00004000H
VER_SUITE_WH_SERVER                             EQU     00008000H

ActivationContextBasicInformation               EQU     1
ActivationContextDetailedInformation            EQU     2
AssemblyDetailedInformationInActivationContext  EQU     3
FileInformationInAssemblyOfAssemblyInActivationContext  EQU 4
RunlevelInformationInActivationContext          EQU     5
CompatibilityInformationInActivationContext     EQU     6
ActivationContextManifestResourceName           EQU     7
MaxActivationContextInfoClass                   EQU     8

AssemblyDetailedInformationInActivationContxt   EQU     3
FileInformationInAssemblyOfAssemblyInActivationContxt   EQU 4

PRODUCT_UNDEFINED                               EQU     00000000H

PRODUCT_ULTIMATE                                EQU     00000001H
PRODUCT_HOME_BASIC                              EQU     00000002H
PRODUCT_HOME_PREMIUM                            EQU     00000003H
PRODUCT_ENTERPRISE                              EQU     00000004H
PRODUCT_HOME_BASIC_N                            EQU     00000005H
PRODUCT_BUSINESS                                EQU     00000006H
PRODUCT_STANDARD_SERVER                         EQU     00000007H
PRODUCT_DATACENTER_SERVER                       EQU     00000008H
PRODUCT_SMALLBUSINESS_SERVER                    EQU     00000009H
PRODUCT_ENTERPRISE_SERVER                       EQU     0000000AH
PRODUCT_STARTER                                 EQU     0000000BH
PRODUCT_DATACENTER_SERVER_CORE                  EQU     0000000CH
PRODUCT_STANDARD_SERVER_CORE                    EQU     0000000DH
PRODUCT_ENTERPRISE_SERVER_CORE                  EQU     0000000EH
PRODUCT_ENTERPRISE_SERVER_IA64                  EQU     0000000FH
PRODUCT_BUSINESS_N                              EQU     00000010H
PRODUCT_WEB_SERVER                              EQU     00000011H
PRODUCT_CLUSTER_SERVER                          EQU     00000012H
PRODUCT_HOME_SERVER                             EQU     00000013H
PRODUCT_STORAGE_EXPRESS_SERVER                  EQU     00000014H
PRODUCT_STORAGE_STANDARD_SERVER                 EQU     00000015H
PRODUCT_STORAGE_WORKGROUP_SERVER                EQU     00000016H
PRODUCT_STORAGE_ENTERPRISE_SERVER               EQU     00000017H
PRODUCT_SERVER_FOR_SMALLBUSINESS                EQU     00000018H
PRODUCT_SMALLBUSINESS_SERVER_PREMIUM            EQU     00000019H
PRODUCT_HOME_PREMIUM_N                          EQU     0000001AH
PRODUCT_ENTERPRISE_N                            EQU     0000001BH
PRODUCT_ULTIMATE_N                              EQU     0000001CH
PRODUCT_WEB_SERVER_CORE                         EQU     0000001DH
PRODUCT_MEDIUMBUSINESS_SERVER_MANAGEMENT        EQU     0000001EH
PRODUCT_MEDIUMBUSINESS_SERVER_SECURITY          EQU     0000001FH
PRODUCT_MEDIUMBUSINESS_SERVER_MESSAGING         EQU     00000020H
PRODUCT_SERVER_FOUNDATION                       EQU     00000021H
PRODUCT_HOME_PREMIUM_SERVER                     EQU     00000022H
PRODUCT_SERVER_FOR_SMALLBUSINESS_V              EQU     00000023H
PRODUCT_STANDARD_SERVER_V                       EQU     00000024H
PRODUCT_DATACENTER_SERVER_V                     EQU     00000025H
PRODUCT_ENTERPRISE_SERVER_V                     EQU     00000026H
PRODUCT_DATACENTER_SERVER_CORE_V                EQU     00000027H
PRODUCT_STANDARD_SERVER_CORE_V                  EQU     00000028H
PRODUCT_ENTERPRISE_SERVER_CORE_V                EQU     00000029H
PRODUCT_HYPERV                                  EQU     0000002AH
PRODUCT_STORAGE_EXPRESS_SERVER_CORE             EQU     0000002BH
PRODUCT_STORAGE_STANDARD_SERVER_CORE            EQU     0000002CH
PRODUCT_STORAGE_WORKGROUP_SERVER_CORE           EQU     0000002DH
PRODUCT_STORAGE_ENTERPRISE_SERVER_CORE          EQU     0000002EH
PRODUCT_STARTER_N                               EQU     0000002FH
PRODUCT_PROFESSIONAL                            EQU     00000030H
PRODUCT_PROFESSIONAL_N                          EQU     00000031H
PRODUCT_SB_SOLUTION_SERVER                      EQU     00000032H
PRODUCT_SERVER_FOR_SB_SOLUTIONS                 EQU     00000033H
PRODUCT_STANDARD_SERVER_SOLUTIONS               EQU     00000034H
PRODUCT_STANDARD_SERVER_SOLUTIONS_CORE          EQU     00000035H
PRODUCT_SB_SOLUTION_SERVER_EM                   EQU     00000036H
PRODUCT_SERVER_FOR_SB_SOLUTIONS_EM              EQU     00000037H
PRODUCT_SOLUTION_EMBEDDEDSERVER                 EQU     00000038H
PRODUCT_SOLUTION_EMBEDDEDSERVER_CORE            EQU     00000039H
PRODUCT_SMALLBUSINESS_SERVER_PREMIUM_CORE       EQU     0000003FH
PRODUCT_ESSENTIALBUSINESS_SERVER_MGMT           EQU     0000003BH
PRODUCT_ESSENTIALBUSINESS_SERVER_ADDL           EQU     0000003CH
PRODUCT_ESSENTIALBUSINESS_SERVER_MGMTSVC        EQU     0000003DH
PRODUCT_ESSENTIALBUSINESS_SERVER_ADDLSVC        EQU     0000003EH
PRODUCT_CLUSTER_SERVER_V                        EQU     00000040H
PRODUCT_EMBEDDED                                EQU     00000041H
PRODUCT_STARTER_E                               EQU     00000042H
PRODUCT_HOME_BASIC_E                            EQU     00000043H
PRODUCT_HOME_PREMIUM_E                          EQU     00000044H
PRODUCT_PROFESSIONAL_E                          EQU     00000045H
PRODUCT_ENTERPRISE_E                            EQU     00000046H
PRODUCT_ULTIMATE_E                              EQU     00000047H
PRODUCT_UNLICENSED                              EQU     0ABCDABCDH

LOCALE_USER_DEFAULT                             EQU     0400H

LOCALE_SYSTEM_DEFAULT                           EQU     2048
LOCALE_NOUSEROVERRIDE                           EQU     80000000H

LANG_NEUTRAL                                    EQU     00H
LANG_INVARIANT                                  EQU     7FH

LANG_AFRIKAANS                                  EQU     36H
LANG_ALBANIAN                                   EQU     1CH
LANG_ALSATIAN                                   EQU     84H
LANG_AMHARIC                                    EQU     5EH
LANG_ARABIC                                     EQU     01H
LANG_ARMENIAN                                   EQU     2BH
LANG_ASSAMESE                                   EQU     4DH
LANG_AZERI                                      EQU     2CH
LANG_AZERBAIJANI                                EQU     2CH
LANG_BANGLA                                     EQU     45H
LANG_BASHKIR                                    EQU     6dH
LANG_BASQUE                                     EQU     2DH
LANG_BELARUSIAN                                 EQU     23H
LANG_BENGALI                                    EQU     45H
LANG_BRETON                                     EQU     7EH
LANG_BOSNIAN                                    EQU     1AH
LANG_BOSNIAN_NEUTRAL                            EQU     781AH
LANG_BULGARIAN                                  EQU     02H
LANG_CATALAN                                    EQU     03H
LANG_CENTRAL_KURDISH                            EQU     92H
LANG_CHEROKEE                                   EQU     5CH
LANG_CHINESE                                    EQU     04H
LANG_CHINESE_SIMPLIFIED                         EQU     04H
LANG_CHINESE_TRADITIONAL                        EQU     7C04H
LANG_CORSICAN                                   EQU     83H
LANG_CROATIAN                                   EQU     1AH
LANG_CZECH                                      EQU     05H
LANG_DANISH                                     EQU     06H
LANG_DARI                                       EQU     8CH
LANG_DIVEHI                                     EQU     65H
LANG_DUTCH                                      EQU     13H
LANG_ENGLISH                                    EQU     09H
LANG_ESTONIAN                                   EQU     25H
LANG_FAEROESE                                   EQU     38H
LANG_FARSI                                      EQU     29H
LANG_FILIPINO                                   EQU     64H
LANG_FINNISH                                    EQU     0BH
LANG_FRENCH                                     EQU     0CH
LANG_FRISIAN                                    EQU     62H
LANG_FULAH                                      EQU     67H
LANG_GALICIAN                                   EQU     56H
LANG_GEORGIAN                                   EQU     37H
LANG_GERMAN                                     EQU     07H
LANG_GREEK                                      EQU     08H
LANG_GREENLANDIC                                EQU     6FH
LANG_GUJARATI                                   EQU     47H
LANG_HAUSA                                      EQU     68H
LANG_HAWAIIAN                                   EQU     75H
LANG_HEBREW                                     EQU     0DH
LANG_HINDI                                      EQU     39H
LANG_HUNGARIAN                                  EQU     0EH
LANG_ICELANDIC                                  EQU     0FH
LANG_IGBO                                       EQU     70H
LANG_INDONESIAN                                 EQU     21H
LANG_INUKTITUT                                  EQU     5DH
LANG_IRISH                                      EQU     3CH
LANG_ITALIAN                                    EQU     10H
LANG_JAPANESE                                   EQU     11H
LANG_KANNADA                                    EQU     4BH
LANG_KASHMIRI                                   EQU     60H
LANG_KAZAK                                      EQU     3FH
LANG_KHMER                                      EQU     53H
LANG_KICHE                                      EQU     86H
LANG_KINYARWANDA                                EQU     87H
LANG_KONKANI                                    EQU     57H
LANG_KOREAN                                     EQU     12H
LANG_KYRGYZ                                     EQU     40H
LANG_LAO                                        EQU     54H
LANG_LATVIAN                                    EQU     26H
LANG_LITHUANIAN                                 EQU     27H
LANG_LOWER_SORBIAN                              EQU     2EH
LANG_LUXEMBOURGISH                              EQU     6EH
LANG_MACEDONIAN                                 EQU     2FH
LANG_MALAY                                      EQU     3EH
LANG_MALAYALAM                                  EQU     4CH
LANG_MALTESE                                    EQU     3AH
LANG_MANIPURI                                   EQU     58H
LANG_MAORI                                      EQU     81H
LANG_MAPUDUNGUN                                 EQU     7AH
LANG_MARATHI                                    EQU     4EH
LANG_MOHAWK                                     EQU     7CH
LANG_MONGOLIAN                                  EQU     50H
LANG_NEPALI                                     EQU     61H
LANG_NORWEGIAN                                  EQU     14H
LANG_OCCITAN                                    EQU     82H
LANG_ODIA                                       EQU     48H
LANG_ORIYA                                      EQU     48H
LANG_PASHTO                                     EQU     63H
LANG_PERSIAN                                    EQU     29H
LANG_POLISH                                     EQU     15H
LANG_PORTUGUESE                                 EQU     16H
LANG_PULAR                                      EQU     67H
LANG_PUNJABI                                    EQU     46H
LANG_QUECHUA                                    EQU     6BH
LANG_ROMANIAN                                   EQU     18H
LANG_ROMANSH                                    EQU     17H
LANG_RUSSIAN                                    EQU     19H
LANG_SAKHA                                      EQU     85H
LANG_SAMI                                       EQU     3BH
LANG_SANSKRIT                                   EQU     4FH
LANG_SCOTTISH_GAELIC                            EQU     91H
LANG_SERBIAN                                    EQU     1AH
LANG_SERBIAN_NEUTRAL                            EQU     7C1AH
LANG_SINDHI                                     EQU     59H
LANG_SINHALESE                                  EQU     5BH
LANG_SLOVAK                                     EQU     1BH
LANG_SLOVENIAN                                  EQU     24H
LANG_SOTHO                                      EQU     6CH
LANG_SPANISH                                    EQU     0AH
LANG_SWAHILI                                    EQU     41H
LANG_SWEDISH                                    EQU     1DH
LANG_SYRIAC                                     EQU     5AH
LANG_TAJIK                                      EQU     28H
LANG_TAMAZIGHT                                  EQU     5FH
LANG_TAMIL                                      EQU     49H
LANG_TATAR                                      EQU     44H
LANG_TELUGU                                     EQU     4AH
LANG_THAI                                       EQU     1EH
LANG_TIBETAN                                    EQU     51H
LANG_TIGRIGNA                                   EQU     73H
LANG_TIGRINYA                                   EQU     73H
LANG_TSWANA                                     EQU     32H
LANG_TURKISH                                    EQU     1FH
LANG_TURKMEN                                    EQU     42H
LANG_UIGHUR                                     EQU     80H
LANG_UKRAINIAN                                  EQU     22H
LANG_UPPER_SORBIAN                              EQU     2EH
LANG_URDU                                       EQU     20H
LANG_UZBEK                                      EQU     43H
LANG_VALENCIAN                                  EQU     03H
LANG_VIETNAMESE                                 EQU     2AH
LANG_WELSH                                      EQU     52H
LANG_WOLOF                                      EQU     88H
LANG_XHOSA                                      EQU     34H
LANG_YAKUT                                      EQU     85H
LANG_YI                                         EQU     78H
LANG_YORUBA                                     EQU     6AH
LANG_ZULU                                       EQU     35H

SUBLANG_NEUTRAL                                 EQU     00H
SUBLANG_DEFAULT                                 EQU     01H
SUBLANG_SYS_DEFAULT                             EQU     02H
SUBLANG_CUSTOM_DEFAULT                          EQU     03H
SUBLANG_CUSTOM_UNSPECIFIED                      EQU     04H
SUBLANG_UI_CUSTOM_DEFAULT                       EQU     05H

SUBLANG_AFRIKAANS_SOUTH_AFRICA                  EQU     01H
SUBLANG_ALBANIAN_ALBANIA                        EQU     01H
SUBLANG_ALSATIAN_FRANCE                         EQU     01H
SUBLANG_AMHARIC_ETHIOPIA                        EQU     01H
SUBLANG_ARABIC_SAUDI_ARABIA                     EQU     01H
SUBLANG_ARABIC_IRAQ                             EQU     02H
SUBLANG_ARABIC_EGYPT                            EQU     03H
SUBLANG_ARABIC_LIBYA                            EQU     04H
SUBLANG_ARABIC_ALGERIA                          EQU     05H
SUBLANG_ARABIC_MOROCCO                          EQU     06H
SUBLANG_ARABIC_TUNISIA                          EQU     07H
SUBLANG_ARABIC_OMAN                             EQU     08H
SUBLANG_ARABIC_YEMEN                            EQU     09H
SUBLANG_ARABIC_SYRIA                            EQU     0AH
SUBLANG_ARABIC_JORDAN                           EQU     0BH
SUBLANG_ARABIC_LEBANON                          EQU     0CH
SUBLANG_ARABIC_KUWAIT                           EQU     0DH
SUBLANG_ARABIC_UAE                              EQU     0EH
SUBLANG_ARABIC_BAHRAIN                          EQU     0FH
SUBLANG_ARABIC_QATAR                            EQU     10H
SUBLANG_ARMENIAN_ARMENIA                        EQU     01H
SUBLANG_ASSAMESE_INDIA                          EQU     01H
SUBLANG_AZERI_LATIN                             EQU     01H
SUBLANG_AZERI_CYRILLIC                          EQU     02H
SUBLANG_AZERBAIJANI_AZERBAIJAN_LATIN            EQU     01H
SUBLANG_AZERBAIJANI_AZERBAIJAN_CYRILLIC         EQU     02H
SUBLANG_BANGLA_INDIA                            EQU     01H
SUBLANG_BANGLA_BANGLADESH                       EQU     02H
SUBLANG_BASHKIR_RUSSIA                          EQU     01H
SUBLANG_BASQUE_BASQUE                           EQU     01H
SUBLANG_BELARUSIAN_BELARUS                      EQU     01H
SUBLANG_BENGALI_INDIA                           EQU     01H
SUBLANG_BENGALI_BANGLADESH                      EQU     02H
SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_LATIN        EQU     05H
SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_CYRILLIC     EQU     08H
SUBLANG_BRETON_FRANCE                           EQU     01H
SUBLANG_BULGARIAN_BULGARIA                      EQU     01H
SUBLANG_CATALAN_CATALAN                         EQU     01H
SUBLANG_CENTRAL_KURDISH_IRAQ                    EQU     01H
SUBLANG_CHEROKEE_CHEROKEE                       EQU     01H
SUBLANG_CHINESE_TRADITIONAL                     EQU     01H
SUBLANG_CHINESE_SIMPLIFIED                      EQU     02H
SUBLANG_CHINESE_HONGKONG                        EQU     03H
SUBLANG_CHINESE_SINGAPORE                       EQU     04H
SUBLANG_CHINESE_MACAU                           EQU     05H
SUBLANG_CORSICAN_FRANCE                         EQU     01H
SUBLANG_CZECH_CZECH_REPUBLIC                    EQU     01H
SUBLANG_CROATIAN_CROATIA                        EQU     01H
SUBLANG_CROATIAN_BOSNIA_HERZEGOVINA_LATIN       EQU     04H
SUBLANG_DANISH_DENMARK                          EQU     01H
SUBLANG_DARI_AFGHANISTAN                        EQU     01H
SUBLANG_DIVEHI_MALDIVES                         EQU     01H
SUBLANG_DUTCH                                   EQU     01H
SUBLANG_DUTCH_BELGIAN                           EQU     02H
SUBLANG_ENGLISH_US                              EQU     01H
SUBLANG_ENGLISH_UK                              EQU     02H
SUBLANG_ENGLISH_AUS                             EQU     03H
SUBLANG_ENGLISH_CAN                             EQU     04H
SUBLANG_ENGLISH_NZ                              EQU     05H
SUBLANG_ENGLISH_EIRE                            EQU     06H
SUBLANG_ENGLISH_SOUTH_AFRICA                    EQU     07H
SUBLANG_ENGLISH_JAMAICA                         EQU     08H
SUBLANG_ENGLISH_CARIBBEAN                       EQU     09H
SUBLANG_ENGLISH_BELIZE                          EQU     0AH
SUBLANG_ENGLISH_TRINIDAD                        EQU     0BH
SUBLANG_ENGLISH_ZIMBABWE                        EQU     0CH
SUBLANG_ENGLISH_PHILIPPINES                     EQU     0DH
SUBLANG_ENGLISH_INDIA                           EQU     10H
SUBLANG_ENGLISH_MALAYSIA                        EQU     11H
SUBLANG_ENGLISH_SINGAPORE                       EQU     12H
SUBLANG_ESTONIAN_ESTONIA                        EQU     01H
SUBLANG_FAEROESE_FAROE_ISLANDS                  EQU     01H
SUBLANG_FILIPINO_PHILIPPINES                    EQU     01H
SUBLANG_FINNISH_FINLAND                         EQU     01H
SUBLANG_FRENCH                                  EQU     01H
SUBLANG_FRENCH_BELGIAN                          EQU     02H
SUBLANG_FRENCH_CANADIAN                         EQU     03H
SUBLANG_FRENCH_SWISS                            EQU     04H
SUBLANG_FRENCH_LUXEMBOURG                       EQU     05H
SUBLANG_FRENCH_MONACO                           EQU     06H
SUBLANG_FRISIAN_NETHERLANDS                     EQU     01H
SUBLANG_FULAH_SENEGAL                           EQU     02H
SUBLANG_GALICIAN_GALICIAN                       EQU     01H
SUBLANG_GEORGIAN_GEORGIA                        EQU     01H
SUBLANG_GERMAN                                  EQU     01H
SUBLANG_GERMAN_SWISS                            EQU     02H
SUBLANG_GERMAN_AUSTRIAN                         EQU     03H
SUBLANG_GERMAN_LUXEMBOURG                       EQU     04H
SUBLANG_GERMAN_LIECHTENSTEIN                    EQU     05H
SUBLANG_GREEK_GREECE                            EQU     01H
SUBLANG_GREENLANDIC_GREENLAND                   EQU     01H
SUBLANG_GUJARATI_INDIA                          EQU     01H
SUBLANG_HAUSA_NIGERIA_LATIN                     EQU     01H
SUBLANG_HAWAIIAN_US                             EQU     01H
SUBLANG_HEBREW_ISRAEL                           EQU     01H
SUBLANG_HINDI_INDIA                             EQU     01H
SUBLANG_HUNGARIAN_HUNGARY                       EQU     01H
SUBLANG_ICELANDIC_ICELAND                       EQU     01H
SUBLANG_IGBO_NIGERIA                            EQU     01H
SUBLANG_INDONESIAN_INDONESIA                    EQU     01H
SUBLANG_INUKTITUT_CANADA                        EQU     01H
SUBLANG_INUKTITUT_CANADA_LATIN                  EQU     02H
SUBLANG_IRISH_IRELAND                           EQU     02H
SUBLANG_ITALIAN                                 EQU     01H
SUBLANG_ITALIAN_SWISS                           EQU     02H
SUBLANG_JAPANESE_JAPAN                          EQU     01H
SUBLANG_KANNADA_INDIA                           EQU     01H
SUBLANG_KASHMIRI_SASIA                          EQU     02H
SUBLANG_KASHMIRI_INDIA                          EQU     02H
SUBLANG_KAZAK_KAZAKHSTAN                        EQU     01H
SUBLANG_KHMER_CAMBODIA                          EQU     01H
SUBLANG_KICHE_GUATEMALA                         EQU     01H
SUBLANG_KINYARWANDA_RWANDA                      EQU     01H
SUBLANG_KONKANI_INDIA                           EQU     01H
SUBLANG_KOREAN                                  EQU     01H
SUBLANG_KYRGYZ_KYRGYZSTAN                       EQU     01H
SUBLANG_LAO_LAO                                 EQU     01H
SUBLANG_LATVIAN_LATVIA                          EQU     01H
SUBLANG_LITHUANIAN                              EQU     01H
SUBLANG_LOWER_SORBIAN_GERMANY                   EQU     02H
SUBLANG_LUXEMBOURGISH_LUXEMBOURG                EQU     01H
SUBLANG_MACEDONIAN_MACEDONIA                    EQU     01H
SUBLANG_MALAY_MALAYSIA                          EQU     01H
SUBLANG_MALAY_BRUNEI_DARUSSALAM                 EQU     02H
SUBLANG_MALAYALAM_INDIA                         EQU     01H
SUBLANG_MALTESE_MALTA                           EQU     01H
SUBLANG_MAORI_NEW_ZEALAND                       EQU     01H
SUBLANG_MAPUDUNGUN_CHILE                        EQU     01H
SUBLANG_MARATHI_INDIA                           EQU     01H
SUBLANG_MOHAWK_MOHAWK                           EQU     01H
SUBLANG_MONGOLIAN_CYRILLIC_MONGOLIA             EQU     01H
SUBLANG_MONGOLIAN_PRC                           EQU     02H
SUBLANG_NEPALI_INDIA                            EQU     02H
SUBLANG_NEPALI_NEPAL                            EQU     01H
SUBLANG_NORWEGIAN_BOKMAL                        EQU     01H
SUBLANG_NORWEGIAN_NYNORSK                       EQU     02H
SUBLANG_OCCITAN_FRANCE                          EQU     01H
SUBLANG_ODIA_INDIA                              EQU     01H
SUBLANG_ORIYA_INDIA                             EQU     01H
SUBLANG_PASHTO_AFGHANISTAN                      EQU     01H
SUBLANG_PERSIAN_IRAN                            EQU     01H
SUBLANG_POLISH_POLAND                           EQU     01H
SUBLANG_PORTUGUESE                              EQU     02H
SUBLANG_PORTUGUESE_BRAZILIAN                    EQU     01H
SUBLANG_PULAR_SENEGAL                           EQU     02H
SUBLANG_PUNJABI_INDIA                           EQU     01H
SUBLANG_PUNJABI_PAKISTAN                        EQU     02H
SUBLANG_QUECHUA_BOLIVIA                         EQU     01H
SUBLANG_QUECHUA_ECUADOR                         EQU     02H
SUBLANG_QUECHUA_PERU                            EQU     03H
SUBLANG_ROMANIAN_ROMANIA                        EQU     01H
SUBLANG_ROMANSH_SWITZERLAND                     EQU     01H
SUBLANG_RUSSIAN_RUSSIA                          EQU     01H
SUBLANG_SAKHA_RUSSIA                            EQU     01H
SUBLANG_SAMI_NORTHERN_NORWAY                    EQU     01H
SUBLANG_SAMI_NORTHERN_SWEDEN                    EQU     02H
SUBLANG_SAMI_NORTHERN_FINLAND                   EQU     03H
SUBLANG_SAMI_LULE_NORWAY                        EQU     04H
SUBLANG_SAMI_LULE_SWEDEN                        EQU     05H
SUBLANG_SAMI_SOUTHERN_NORWAY                    EQU     06H
SUBLANG_SAMI_SOUTHERN_SWEDEN                    EQU     07H
SUBLANG_SAMI_SKOLT_FINLAND                      EQU     08H
SUBLANG_SAMI_INARI_FINLAND                      EQU     09H
SUBLANG_SANSKRIT_INDIA                          EQU     01H
SUBLANG_SCOTTISH_GAELIC                         EQU     01H
SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_LATIN        EQU     06H
SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_CYRILLIC     EQU     07H
SUBLANG_SERBIAN_MONTENEGRO_LATIN                EQU     0BH
SUBLANG_SERBIAN_MONTENEGRO_CYRILLIC             EQU     0CH
SUBLANG_SERBIAN_SERBIA_LATIN                    EQU     09H
SUBLANG_SERBIAN_SERBIA_CYRILLIC                 EQU     0AH
SUBLANG_SERBIAN_CROATIA                         EQU     01H
SUBLANG_SERBIAN_LATIN                           EQU     02H
SUBLANG_SERBIAN_CYRILLIC                        EQU     03H
SUBLANG_SINDHI_INDIA                            EQU     01H
SUBLANG_SINDHI_PAKISTAN                         EQU     02H
SUBLANG_SINDHI_AFGHANISTAN                      EQU     02H
SUBLANG_SINHALESE_SRI_LANKA                     EQU     01H
SUBLANG_SOTHO_NORTHERN_SOUTH_AFRICA             EQU     01H
SUBLANG_SLOVAK_SLOVAKIA                         EQU     01H
SUBLANG_SLOVENIAN_SLOVENIA                      EQU     01H
SUBLANG_SPANISH                                 EQU     01H
SUBLANG_SPANISH_MEXICAN                         EQU     02H
SUBLANG_SPANISH_MODERN                          EQU     03H
SUBLANG_SPANISH_GUATEMALA                       EQU     04H
SUBLANG_SPANISH_COSTA_RICA                      EQU     05H
SUBLANG_SPANISH_PANAMA                          EQU     06H
SUBLANG_SPANISH_DOMINICAN_REPUBLIC              EQU     07H
SUBLANG_SPANISH_VENEZUELA                       EQU     08H
SUBLANG_SPANISH_COLOMBIA                        EQU     09H
SUBLANG_SPANISH_PERU                            EQU     0AH
SUBLANG_SPANISH_ARGENTINA                       EQU     0BH
SUBLANG_SPANISH_ECUADOR                         EQU     0CH
SUBLANG_SPANISH_CHILE                           EQU     0DH
SUBLANG_SPANISH_URUGUAY                         EQU     0EH
SUBLANG_SPANISH_PARAGUAY                        EQU     0FH
SUBLANG_SPANISH_BOLIVIA                         EQU     10H
SUBLANG_SPANISH_EL_SALVADOR                     EQU     11H
SUBLANG_SPANISH_HONDURAS                        EQU     12H
SUBLANG_SPANISH_NICARAGUA                       EQU     13H
SUBLANG_SPANISH_PUERTO_RICO                     EQU     14H
SUBLANG_SPANISH_US                              EQU     15H
SUBLANG_SWAHILI_KENYA                           EQU     01H
SUBLANG_SWEDISH                                 EQU     01H
SUBLANG_SWEDISH_FINLAND                         EQU     02H
SUBLANG_SYRIAC_SYRIA                            EQU     01H
SUBLANG_TAJIK_TAJIKISTAN                        EQU     01H
SUBLANG_TAMAZIGHT_ALGERIA_LATIN                 EQU     02H
SUBLANG_TAMAZIGHT_MOROCCO_TIFINAGH              EQU     04H
SUBLANG_TAMIL_INDIA                             EQU     01H
SUBLANG_TAMIL_SRI_LANKA                         EQU     02H
SUBLANG_TATAR_RUSSIA                            EQU     01H
SUBLANG_TELUGU_INDIA                            EQU     01H
SUBLANG_THAI_THAILAND                           EQU     01H
SUBLANG_TIBETAN_PRC                             EQU     01H
SUBLANG_TIGRIGNA_ERITREA                        EQU     02H
SUBLANG_TIGRINYA_ERITREA                        EQU     02H
SUBLANG_TIGRINYA_ETHIOPIA                       EQU     01H
SUBLANG_TSWANA_BOTSWANA                         EQU     02H
SUBLANG_TSWANA_SOUTH_AFRICA                     EQU     01H
SUBLANG_TURKISH_TURKEY                          EQU     01H
SUBLANG_TURKMEN_TURKMENISTAN                    EQU     01H
SUBLANG_UIGHUR_PRC                              EQU     01H
SUBLANG_UKRAINIAN_UKRAINE                       EQU     01H
SUBLANG_UPPER_SORBIAN_GERMANY                   EQU     01H
SUBLANG_URDU_PAKISTAN                           EQU     01H
SUBLANG_URDU_INDIA                              EQU     02H
SUBLANG_UZBEK_LATIN                             EQU     01H
SUBLANG_UZBEK_CYRILLIC                          EQU     02H
SUBLANG_VALENCIAN_VALENCIA                      EQU     02H
SUBLANG_VIETNAMESE_VIETNAM                      EQU     01H
SUBLANG_WELSH_UNITED_KINGDOM                    EQU     01H
SUBLANG_WOLOF_SENEGAL                           EQU     01H
SUBLANG_XHOSA_SOUTH_AFRICA                      EQU     01H
SUBLANG_YAKUT_RUSSIA                            EQU     01H
SUBLANG_YI_PRC                                  EQU     01H
SUBLANG_YORUBA_NIGERIA                          EQU     01H
SUBLANG_ZULU_SOUTH_AFRICA                       EQU     01H

SORT_DEFAULT                                    EQU     0H

SORT_JAPANESE_XJIS                              EQU     0H
SORT_JAPANESE_UNICODE                           EQU     1H
SORT_JAPANESE_RADICALSTROKE                     EQU     4H

SORT_CHINESE_BIG5                               EQU     0H
SORT_CHINESE_PRCP                               EQU     0H
SORT_CHINESE_UNICODE                            EQU     1H
SORT_CHINESE_PRC                                EQU     2H
SORT_CHINESE_BOPOMOFO                           EQU     3H
SORT_CHINESE_RADICALSTROKE                      EQU     4H

SORT_KOREAN_KSC                                 EQU     0H
SORT_KOREAN_UNICODE                             EQU     1H

SORT_GERMAN_PHONE_BOOK                          EQU     1H

SORT_HUNGARIAN_DEFAULT                          EQU     0H
SORT_HUNGARIAN_TECHNICAL                        EQU     1H

SORT_GEORGIAN_TRADITIONAL                       EQU     0H
SORT_GEORGIAN_MODERN                            EQU     1H

LOCALE_NAME_MAX_LENGTH                          EQU     85

LOCALE_CUSTOM_DEFAULT                           EQU     ((LANG_NEUTRAL OR (SUBLANG_CUSTOM_DEFAULT SHL 10)) OR (SORT_DEFAULT SHL 16))
LOCALE_CUSTOM_UNSPECIFIED                       EQU     ((LANG_NEUTRAL OR (SUBLANG_CUSTOM_UNSPECIFIED SHL 10)) OR (SORT_DEFAULT SHL 16))
LOCALE_CUSTOM_UI_DEFAULT                        EQU     ((LANG_NEUTRAL OR (SUBLANG_UI_CUSTOM_DEFAULT SHL 10)) OR (SORT_DEFAULT SHL 16))
LOCALE_NEUTRAL                                  EQU     ((LANG_NEUTRAL OR (SUBLANG_NEUTRAL SHL 10)) OR (SORT_DEFAULT SHL 16))
LOCALE_INVARIANT                                EQU     ((LANG_INVARIANT OR (SUBLANG_NEUTRAL SHL 10)) OR (SORT_DEFAULT SHL 16))

LANG_SYSTEM_DEFAULT                             EQU     ((SUBLANG_SYS_DEFAULT SHL 10) OR LANG_NEUTRAL)
LANG_USER_DEFAULT                               EQU     ((SUBLANG_DEFAULT SHL 10) OR LANG_NEUTRAL)

LOCALE_TRANSIENT_KEYBOARD1                      EQU     02000H
LOCALE_TRANSIENT_KEYBOARD2                      EQU     02400H
LOCALE_TRANSIENT_KEYBOARD3                      EQU     02800H
LOCALE_TRANSIENT_KEYBOARD4                      EQU     02C00H

LOCALE_UNASSIGNED_LCID                          EQU     LOCALE_CUSTOM_UNSPECIFIED

STATUS_WAIT_0                                   EQU     000000000H
STATUS_ABANDONED_WAIT_0                         EQU     000000080H
STATUS_USER_APC                                 EQU     0000000C0H
STATUS_TIMEOUT                                  EQU     000000102H
STATUS_PENDING                                  EQU     000000103H
DBG_EXCEPTION_HANDLED                           EQU     000010001H
DBG_CONTINUE                                    EQU     000010002H
STATUS_SEGMENT_NOTIFICATION                     EQU     040000005H
DBG_TERMINATE_THREAD                            EQU     040010003H
DBG_TERMINATE_PROCESS                           EQU     040010004H
DBG_CONTROL_C                                   EQU     040010005H
DBG_PRINTEXCEPTION_C                            EQU     040010006H
DBG_RIPEXCEPTION                                EQU     040010007H
DBG_CONTROL_BREAK                               EQU     040010008H
DBG_COMMAND_EXCEPTION                           EQU     040010009H
STATUS_GUARD_PAGE_VIOLATION                     EQU     080000001H
STATUS_DATATYPE_MISALIGNMENT                    EQU     080000002H
STATUS_BREAKPOINT                               EQU     080000003H
STATUS_SINGLE_STEP                              EQU     080000004H
STATUS_LONGJUMP                                 EQU     080000026H
STATUS_UNWIND_CONSOLIDATE                       EQU     080000029H
DBG_EXCEPTION_NOT_HANDLED                       EQU     080010001H
STATUS_ACCESS_VIOLATION                         EQU     0C0000005H
STATUS_IN_PAGE_ERROR                            EQU     0C0000006H
STATUS_INVALID_HANDLE                           EQU     0C0000008H
STATUS_INVALID_PARAMETER                        EQU     0C000000DH
STATUS_NO_MEMORY                                EQU     0C0000017H
STATUS_ILLEGAL_INSTRUCTION                      EQU     0C000001DH
STATUS_NONCONTINUABLE_EXCEPTION                 EQU     0C0000025H
STATUS_INVALID_DISPOSITION                      EQU     0C0000026H
STATUS_ARRAY_BOUNDS_EXCEEDED                    EQU     0C000008CH
STATUS_FLOAT_DENORMAL_OPERAND                   EQU     0C000008DH
STATUS_FLOAT_DIVIDE_BY_ZERO                     EQU     0C000008EH
STATUS_FLOAT_INEXACT_RESULT                     EQU     0C000008FH
STATUS_FLOAT_INVALID_OPERATION                  EQU     0C0000090H
STATUS_FLOAT_OVERFLOW                           EQU     0C0000091H
STATUS_FLOAT_STACK_CHECK                        EQU     0C0000092H
STATUS_FLOAT_UNDERFLOW                          EQU     0C0000093H
STATUS_INTEGER_DIVIDE_BY_ZERO                   EQU     0C0000094H
STATUS_INTEGER_OVERFLOW                         EQU     0C0000095H
STATUS_PRIVILEGED_INSTRUCTION                   EQU     0C0000096H
STATUS_STACK_OVERFLOW                           EQU     0C00000FDH
STATUS_DLL_NOT_FOUND                            EQU     0C0000135H
STATUS_ORDINAL_NOT_FOUND                        EQU     0C0000138H
STATUS_ENTRYPOINT_NOT_FOUND                     EQU     0C0000139H
STATUS_CONTROL_C_EXIT                           EQU     0C000013AH
STATUS_DLL_INIT_FAILED                          EQU     0C0000142H
STATUS_POSSIBLE_DEADLOCK                        EQU     0C0000194H
STATUS_FLOAT_MULTIPLE_FAULTS                    EQU     0C00002B4H
STATUS_FLOAT_MULTIPLE_TRAPS                     EQU     0C00002B5H
STATUS_REG_NAT_CONSUMPTION                      EQU     0C00002C9H
STATUS_STACK_BUFFER_OVERRUN                     EQU     0C0000409H
STATUS_INVALID_CRUNTIME_PARAMETER               EQU     0C0000417H
STATUS_ASSERTION_FAILURE                        EQU     0C0000420H
STATUS_SXS_EARLY_DEACTIVATION                   EQU     0C015000FH
STATUS_SXS_INVALID_DEACTIVATION                 EQU     0C0150010H

MAXIMUM_WAIT_OBJECTS                            EQU     64
MAXIMUM_SUSPEND_COUNT                           EQU     MAXCHAR

EXCEPTION_NONCONTINUABLE                        EQU     01H
EXCEPTION_UNWINDING                             EQU     02H
EXCEPTION_EXIT_UNWIND                           EQU     04H
EXCEPTION_STACK_INVALID                         EQU     08H
EXCEPTION_NESTED_CALL                           EQU     010H
EXCEPTION_TARGET_UNWIND                         EQU     020H
EXCEPTION_COLLIDED_UNWIND                       EQU     040H
EXCEPTION_UNWIND                                EQU     (EXCEPTION_UNWINDING OR EXCEPTION_EXIT_UNWIND OR \
                                                        EXCEPTION_TARGET_UNWIND OR EXCEPTION_COLLIDED_UNWIND)

DELETE                                          EQU     000010000H
READ_CONTROL                                    EQU     000020000H
WRITE_DAC                                       EQU     000040000H
WRITE_OWNER                                     EQU     000080000H
SYNCHRONIZE                                     EQU     000100000H

STANDARD_RIGHTS_REQUIRED                        EQU     0000F0000H
STANDARD_RIGHTS_READ                            EQU     READ_CONTROL
STANDARD_RIGHTS_WRITE                           EQU     READ_CONTROL
STANDARD_RIGHTS_EXECUTE                         EQU     READ_CONTROL
STANDARD_RIGHTS_ALL                             EQU     0001F0000H

SPECIFIC_RIGHTS_ALL                             EQU     00000FFFFH

ACCESS_SYSTEM_SECURITY                          EQU     001000000H

MAXIMUM_ALLOWED                                 EQU     002000000H

GENERIC_READ                                    EQU     080000000H
GENERIC_WRITE                                   EQU     040000000H
GENERIC_EXECUTE                                 EQU     020000000H
GENERIC_ALL                                     EQU     010000000H

SID_HASH_SIZE                                   EQU     32
SID_HASH_ENTRY                                  TYPEDEF ULONG_PTR

SID_REVISION                                    EQU     1
SID_MAX_SUB_AUTHORITIES                         EQU     15
SID_RECOMMENDED_SUB_AUTHORITIES                 EQU     1

SECURITY_NULL_SID_AUTHORITY                     EQU     {0,0,0,0,0,0}
SECURITY_WORLD_SID_AUTHORITY                    EQU     {0,0,0,0,0,1}
SECURITY_LOCAL_SID_AUTHORITY                    EQU     {0,0,0,0,0,2}
SECURITY_CREATOR_SID_AUTHORITY                  EQU     {0,0,0,0,0,3}
SECURITY_NON_UNIQUE_AUTHORITY                   EQU     {0,0,0,0,0,4}
SECURITY_RESOURCE_MANAGER_AUTHORITY             EQU     {0,0,0,0,0,9}
SECURITY_NULL_RID                               EQU     000000000H
SECURITY_WORLD_RID                              EQU     000000000H
SECURITY_LOCAL_RID                              EQU     000000000H
SECURITY_LOCAL_LOGON_RID                        EQU     000000001H
SECURITY_CREATOR_OWNER_RID                      EQU     000000000H
SECURITY_CREATOR_GROUP_RID                      EQU     000000001H
SECURITY_CREATOR_OWNER_SERVER_RID               EQU     000000002H
SECURITY_CREATOR_GROUP_SERVER_RID               EQU     000000003H
SECURITY_CREATOR_OWNER_RIGHTS_RID               EQU     000000004H

SECURITY_NT_AUTHORITY                           EQU     {0,0,0,0,0,5}

SECURITY_DIALUP_RID                             EQU     000000001H
SECURITY_NETWORK_RID                            EQU     000000002H
SECURITY_BATCH_RID                              EQU     000000003H
SECURITY_INTERACTIVE_RID                        EQU     000000004H
SECURITY_LOGON_IDS_RID                          EQU     000000005H
SECURITY_LOGON_IDS_RID_COUNT                    EQU     3
SECURITY_SERVICE_RID                            EQU     000000006H
SECURITY_ANONYMOUS_LOGON_RID                    EQU     000000007H
SECURITY_PROXY_RID                              EQU     000000008H
SECURITY_ENTERPRISE_CONTROLLERS_RID             EQU     000000009H
SECURITY_SERVER_LOGON_RID                       EQU     SECURITY_ENTERPRISE_CONTROLLERS_RID>
SECURITY_PRINCIPAL_SELF_RID                     EQU     00000000AH
SECURITY_AUTHENTICATED_USER_RID                 EQU     00000000BH
SECURITY_RESTRICTED_CODE_RID                    EQU     00000000CH
SECURITY_TERMINAL_SERVER_RID                    EQU     00000000DH
SECURITY_REMOTE_LOGON_RID                       EQU     00000000EH
SECURITY_THIS_ORGANIZATION_RID                  EQU     00000000FH
SECURITY_IUSER_RID                              EQU     000000011H
SECURITY_LOCAL_SYSTEM_RID                       EQU     000000012H
SECURITY_LOCAL_SERVICE_RID                      EQU     000000013H
SECURITY_NETWORK_SERVICE_RID                    EQU     000000014H
SECURITY_NT_NON_UNIQUE                          EQU     000000015H
SECURITY_NT_NON_UNIQUE_SUB_AUTH_COUNT           EQU     3
SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID    EQU     000000016H
SECURITY_BUILTIN_DOMAIN_RID                     EQU     000000020H
SECURITY_WRITE_RESTRICTED_CODE_RID              EQU     000000021H
SECURITY_PACKAGE_BASE_RID                       EQU     000000040H
SECURITY_PACKAGE_RID_COUNT                      EQU     2
SECURITY_PACKAGE_NTLM_RID                       EQU     00000000AH
SECURITY_PACKAGE_SCHANNEL_RID                   EQU     00000000EH
SECURITY_PACKAGE_DIGEST_RID                     EQU     000000015H
SECURITY_CRED_TYPE_BASE_RID                     EQU     000000041H
SECURITY_CRED_TYPE_RID_COUNT                    EQU     2
SECURITY_CRED_TYPE_THIS_ORG_CERT_RID            EQU     000000001H
SECURITY_MIN_BASE_RID                           EQU     000000050H
SECURITY_SERVICE_ID_BASE_RID                    EQU     000000050H
SECURITY_SERVICE_ID_RID_COUNT                   EQU     6
SECURITY_RESERVED_ID_BASE_RID                   EQU     000000051H
SECURITY_APPPOOL_ID_BASE_RID                    EQU     000000052H
SECURITY_APPPOOL_ID_RID_COUNT                   EQU     6
SECURITY_VIRTUALSERVER_ID_BASE_RID              EQU     000000053H
SECURITY_VIRTUALSERVER_ID_RID_COUNT             EQU     6
SECURITY_USERMODEDRIVERHOST_ID_BASE_RID         EQU     000000054H
SECURITY_USERMODEDRIVERHOST_ID_RID_COUNT        EQU     6
SECURITY_CLOUD_INFRASTRUCTURE_SERVICES_ID_BASE_RID  EQU 000000055H
SECURITY_CLOUD_INFRASTRUCTURE_SERVICES_ID_RID_COUNT EQU 6
SECURITY_WMIHOST_ID_BASE_RID                    EQU     000000056H
SECURITY_WMIHOST_ID_RID_COUNT                   EQU     6
SECURITY_TASK_ID_BASE_RID                       EQU     000000057H
SECURITY_NFS_ID_BASE_RID                        EQU     000000058H
SECURITY_COM_ID_BASE_RID                        EQU     000000059H
SECURITY_WINDOW_MANAGER_BASE_RID                EQU     00000005AH
SECURITY_RDV_GFX_BASE_RID                       EQU     00000005BH
SECURITY_DASHOST_ID_BASE_RID                    EQU     00000005CH
SECURITY_DASHOST_ID_RID_COUNT                   EQU     6
SECURITY_VIRTUALACCOUNT_ID_RID_COUNT            EQU     6
SECURITY_MAX_BASE_RID                           EQU     00000006FH
SECURITY_MAX_ALWAYS_FILTERED                    EQU     0000003E7H
SECURITY_MIN_NEVER_FILTERED                     EQU     0000003E8H
SECURITY_OTHER_ORGANIZATION_RID                 EQU     0000003E8H
SECURITY_WINDOWSMOBILE_ID_BASE_RID              EQU     000000070H

DOMAIN_USER_RID_ADMIN                           EQU     0000001F4H
DOMAIN_USER_RID_GUEST                           EQU     0000001F5H
DOMAIN_USER_RID_KRBTGT                          EQU     0000001F6H
DOMAIN_USER_RID_MAX                             EQU     0000003E7H

DOMAIN_GROUP_RID_ADMINS                         EQU     000000200H
DOMAIN_GROUP_RID_USERS                          EQU     000000201H
DOMAIN_GROUP_RID_GUESTS                         EQU     000000202H
DOMAIN_GROUP_RID_COMPUTERS                      EQU     000000203H
DOMAIN_GROUP_RID_CONTROLLERS                    EQU     000000204H
DOMAIN_GROUP_RID_CERT_ADMINS                    EQU     000000205H
DOMAIN_GROUP_RID_SCHEMA_ADMINS                  EQU     000000206H
DOMAIN_GROUP_RID_ENTERPRISE_ADMINS              EQU     000000207H
DOMAIN_GROUP_RID_POLICY_ADMINS                  EQU     000000208H
DOMAIN_GROUP_RID_READONLY_CONTROLLERS           EQU     000000209H
DOMAIN_GROUP_RID_CLONEABLE_CONTROLLERS          EQU     00000020AH
DOMAIN_GROUP_RID_CDC_RESERVED                   EQU     00000020CH
DOMAIN_GROUP_RID_PROTECTED_USERS                EQU     00000020DH

DOMAIN_ALIAS_RID_ADMINS                         EQU     000000220H
DOMAIN_ALIAS_RID_USERS                          EQU     000000221H
DOMAIN_ALIAS_RID_GUESTS                         EQU     000000222H
DOMAIN_ALIAS_RID_POWER_USERS                    EQU     000000223H

DOMAIN_ALIAS_RID_ACCOUNT_OPS                    EQU     000000224H
DOMAIN_ALIAS_RID_SYSTEM_OPS                     EQU     000000225H
DOMAIN_ALIAS_RID_PRINT_OPS                      EQU     000000226H
DOMAIN_ALIAS_RID_BACKUP_OPS                     EQU     000000227H

DOMAIN_ALIAS_RID_REPLICATOR                     EQU     000000228H
DOMAIN_ALIAS_RID_RAS_SERVERS                    EQU     000000229H
DOMAIN_ALIAS_RID_PREW2KCOMPACCESS               EQU     00000022AH
DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS           EQU     00000022BH
DOMAIN_ALIAS_RID_NETWORK_CONFIGURATION_OPS      EQU     00000022CH
DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS EQU     00000022DH
DOMAIN_ALIAS_RID_MONITORING_USERS               EQU     00000022EH
DOMAIN_ALIAS_RID_LOGGING_USERS                  EQU     00000022FH
DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS            EQU     000000230H
DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS             EQU     000000231H
DOMAIN_ALIAS_RID_DCOM_USERS                     EQU     000000232H
DOMAIN_ALIAS_RID_IUSERS                         EQU     000000238H
DOMAIN_ALIAS_RID_CRYPTO_OPERATORS               EQU     000000239H
DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_GROUP     EQU     00000023BH
DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_GROUP EQU     00000023CH
DOMAIN_ALIAS_RID_EVENT_LOG_READERS_GROUP        EQU     00000023DH
DOMAIN_ALIAS_RID_CERTSVC_DCOM_ACCESS_GROUP      EQU     00000023EH
DOMAIN_ALIAS_RID_RDS_REMOTE_ACCESS_SERVERS      EQU     00000023FH
DOMAIN_ALIAS_RID_RDS_ENDPOINT_SERVERS           EQU     000000240H
DOMAIN_ALIAS_RID_RDS_MANAGEMENT_SERVERS         EQU     000000241H
DOMAIN_ALIAS_RID_HYPER_V_ADMINS                 EQU     000000242H
DOMAIN_ALIAS_RID_ACCESS_CONTROL_ASSISTANCE_OPS  EQU     000000243H
DOMAIN_ALIAS_RID_REMOTE_MANAGEMENT_USERS        EQU     000000244H

SECURITY_MANDATORY_LABEL_AUTHORITY              EQU     {0,0,0,0,0,16}
SECURITY_MANDATORY_UNTRUSTED_RID                EQU     000000000H
SECURITY_MANDATORY_LOW_RID                      EQU     000001000H
SECURITY_MANDATORY_MEDIUM_RID                   EQU     000002000H
SECURITY_MANDATORY_MEDIUM_PLUS_RID              EQU     (SECURITY_MANDATORY_MEDIUM_RID + 0100H)
SECURITY_MANDATORY_HIGH_RID                     EQU     000003000H
SECURITY_MANDATORY_SYSTEM_RID                   EQU     000004000H
SECURITY_MANDATORY_PROTECTED_PROCESS_RID        EQU     000005000H

SECURITY_MANDATORY_MAXIMUM_USER_RID             EQU     SECURITY_MANDATORY_SYSTEM_RID

WinNullSid                                      EQU     0
WinWorldSid                                     EQU     1
WinLocalSid                                     EQU     2
WinCreatorOwnerSid                              EQU     3
WinCreatorGroupSid                              EQU     4
WinCreatorOwnerServerSid                        EQU     5
WinCreatorGroupServerSid                        EQU     6
WinNtAuthoritySid                               EQU     7
WinDialupSid                                    EQU     8
WinNetworkSid                                   EQU     9
WinBatchSid                                     EQU     10
WinInteractiveSid                               EQU     11
WinServiceSid                                   EQU     12
WinAnonymousSid                                 EQU     13
WinProxySid                                     EQU     14
WinEnterpriseControllersSid                     EQU     15
WinSelfSid                                      EQU     16
WinAuthenticatedUserSid                         EQU     17
WinRestrictedCodeSid                            EQU     18
WinTerminalServerSid                            EQU     19
WinRemoteLogonIdSid                             EQU     20
WinLogonIdsSid                                  EQU     21
WinLocalSystemSid                               EQU     22
WinLocalServiceSid                              EQU     23
WinNetworkServiceSid                            EQU     24
WinBuiltinDomainSid                             EQU     25
WinBuiltinAdministratorsSid                     EQU     26
WinBuiltinUsersSid                              EQU     27
WinBuiltinGuestsSid                             EQU     28
WinBuiltinPowerUsersSid                         EQU     29
WinBuiltinAccountOperatorsSid                   EQU     30
WinBuiltinSystemOperatorsSid                    EQU     31
WinBuiltinPrintOperatorsSid                     EQU     32
WinBuiltinBackupOperatorsSid                    EQU     33
WinBuiltinReplicatorSid                         EQU     34
WinBuiltinPreWindows2000CompatibleAccessSid     EQU     35
WinBuiltinRemoteDesktopUsersSid                 EQU     36
WinBuiltinNetworkConfigurationOperatorsSid      EQU     37
WinAccountAdministratorSid                      EQU     38
WinAccountGuestSid                              EQU     39
WinAccountKrbtgtSid                             EQU     40
WinAccountDomainAdminsSid                       EQU     41
WinAccountDomainUsersSid                        EQU     42
WinAccountDomainGuestsSid                       EQU     43
WinAccountComputersSid                          EQU     44
WinAccountControllersSid                        EQU     45
WinAccountCertAdminsSid                         EQU     46
WinAccountSchemaAdminsSid                       EQU     47
WinAccountEnterpriseAdminsSid                   EQU     48
WinAccountPolicyAdminsSid                       EQU     49
WinAccountRasAndIasServersSid                   EQU     50
WinNTLMAuthenticationSid                        EQU     51
WinDigestAuthenticationSid                      EQU     52
WinSChannelAuthenticationSid                    EQU     53
WinThisOrganizationSid                          EQU     54
WinOtherOrganizationSid                         EQU     55
WinBuiltinIncomingForestTrustBuildersSid        EQU     56
WinBuiltinPerfMonitoringUsersSid                EQU     57
WinBuiltinPerfLoggingUsersSid                   EQU     58
WinBuiltinAuthorizationAccessSid                EQU     59
WinBuiltinTerminalServerLicenseServersSid       EQU     60
WinBuiltinDCOMUsersSid                          EQU     61
WinBuiltinIUsersSid                             EQU     62
WinIUserSid                                     EQU     63
WinBuiltinCryptoOperatorsSid                    EQU     64
WinUntrustedLabelSid                            EQU     65
WinLowLabelSid                                  EQU     66
WinMediumLabelSid                               EQU     67
WinHighLabelSid                                 EQU     68
WinSystemLabelSid                               EQU     69
WinWriteRestrictedCodeSid                       EQU     70
WinCreatorOwnerRightsSid                        EQU     71
WinCacheablePrincipalsGroupSid                  EQU     72
WinNonCacheablePrincipalsGroupSid               EQU     73
WinEnterpriseReadonlyControllersSid             EQU     74
WinAccountReadonlyControllersSid                EQU     75
WinBuiltinEventLogReadersGroup                  EQU     76
WinNewEnterpriseReadonlyControllersSid          EQU     77
WinBuiltinCertSvcDComAccessGroup                EQU     78
WinMediumPlusLabelSid                           EQU     79
WinLocalLogonSid                                EQU     80
WinConsoleLogonSid                              EQU     81
WinThisOrganizationCertificateSid               EQU     82

SYSTEM_LUID                                     EQU     {03E7H,00H}
ANONYMOUS_LOGON_LUID                            EQU     {03E6H,00H}
LOCALSERVICE_LUID                               EQU     {03E5H,00H}
NETWORKSERVICE_LUID                             EQU     {03E4H,00H}
IUSER_LUID                                      EQU     {03E3H,00H}

SE_GROUP_MANDATORY                              EQU     000000001H
SE_GROUP_ENABLED_BY_DEFAULT                     EQU     000000002H
SE_GROUP_ENABLED                                EQU     000000004H
SE_GROUP_OWNER                                  EQU     000000008H
SE_GROUP_USE_FOR_DENY_ONLY                      EQU     000000010H
SE_GROUP_INTEGRITY                              EQU     000000020H
SE_GROUP_INTEGRITY_ENABLED                      EQU     000000040H
SE_GROUP_LOGON_ID                               EQU     0C0000000H
SE_GROUP_RESOURCE                               EQU     020000000H

SE_GROUP_VALID_ATTRIBUTES                       EQU     (SE_GROUP_MANDATORY OR SE_GROUP_ENABLED_BY_DEFAULT OR \
                                                        SE_GROUP_ENABLED OR SE_GROUP_OWNER OR \
                                                        SE_GROUP_USE_FOR_DENY_ONLY OR SE_GROUP_LOGON_ID OR \
                                                        SE_GROUP_RESOURCE OR SE_GROUP_INTEGRITY)

ACL_REVISION                                    EQU     2
ACL_REVISION1                                   EQU     1
ACL_REVISION2                                   EQU     2
ACL_REVISION3                                   EQU     3
ACL_REVISION4                                   EQU     4
ACL_REVISION_DS                                 EQU     4

MIN_ACL_REVISION                                EQU     ACL_REVISION2
MAX_ACL_REVISION                                EQU     ACL_REVISION4

ACCESS_MIN_MS_ACE_TYPE                          EQU     00H
ACCESS_ALLOWED_ACE_TYPE                         EQU     00H
ACCESS_DENIED_ACE_TYPE                          EQU     01H
SYSTEM_AUDIT_ACE_TYPE                           EQU     02H
SYSTEM_ALARM_ACE_TYPE                           EQU     03H
ACCESS_MAX_MS_V2_ACE_TYPE                       EQU     03H

ACCESS_ALLOWED_COMPOUND_ACE_TYPE                EQU     04H
ACCESS_MAX_MS_V3_ACE_TYPE                       EQU     04H

ACCESS_MIN_MS_OBJECT_ACE_TYPE                   EQU     05H
ACCESS_ALLOWED_OBJECT_ACE_TYPE                  EQU     05H
ACCESS_DENIED_OBJECT_ACE_TYPE                   EQU     06H
SYSTEM_AUDIT_OBJECT_ACE_TYPE                    EQU     07H
SYSTEM_ALARM_OBJECT_ACE_TYPE                    EQU     08H
ACCESS_MAX_MS_OBJECT_ACE_TYPE                   EQU     08H

ACCESS_MAX_MS_V4_ACE_TYPE                       EQU     08H
ACCESS_MAX_MS_ACE_TYPE                          EQU     08H
ACCESS_ALLOWED_CALLBACK_ACE_TYPE                EQU     09H
ACCESS_DENIED_CALLBACK_ACE_TYPE                 EQU     0AH
ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE         EQU     0BH
ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE          EQU     0CH
SYSTEM_AUDIT_CALLBACK_ACE_TYPE                  EQU     0DH
SYSTEM_ALARM_CALLBACK_ACE_TYPE                  EQU     0EH
SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE           EQU     0FH
SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE           EQU     010H

SYSTEM_MANDATORY_LABEL_ACE_TYPE                 EQU     011H
SYSTEM_RESOURCE_ATTRIBUTE_ACE_TYPE              EQU     012H
SYSTEM_SCOPED_POLICY_ID_ACE_TYPE                EQU     013H
SYSTEM_PROCESS_TRUST_LABEL_ACE_TYPE             EQU     014H
ACCESS_MAX_MS_V5_ACE_TYPE                       EQU     014H

SYSTEM_MANDATORY_LABEL_NO_WRITE_UP              EQU     01H
SYSTEM_MANDATORY_LABEL_NO_READ_UP               EQU     02H
SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP            EQU     04H

SYSTEM_MANDATORY_LABEL_VALID_MASK               EQU     (SYSTEM_MANDATORY_LABEL_NO_WRITE_UP OR \
                                                        SYSTEM_MANDATORY_LABEL_NO_READ_UP OR \
                                                        SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP)

OBJECT_INHERIT_ACE                              EQU     01H
CONTAINER_INHERIT_ACE                           EQU     02H
NO_PROPAGATE_INHERIT_ACE                        EQU     04H
INHERIT_ONLY_ACE                                EQU     08H
INHERITED_ACE                                   EQU     010H
VALID_INHERIT_FLAGS                             EQU     01FH

SUCCESSFUL_ACCESS_ACE_FLAG                      EQU     040H
FAILED_ACCESS_ACE_FLAG                          EQU     080H

ACE_OBJECT_TYPE_PRESENT                         EQU     01H
ACE_INHERITED_OBJECT_TYPE_PRESENT               EQU     02H

SECURITY_DESCRIPTOR_REVISION                    EQU     1
SECURITY_DESCRIPTOR_REVISION1                   EQU     1

SECURITY_DESCRIPTOR_MIN_LENGTH                  EQU     SIZEOF SECURITY_DESCRIPTOR

SE_OWNER_DEFAULTED                              EQU     00001H
SE_GROUP_DEFAULTED                              EQU     00002H
SE_DACL_PRESENT                                 EQU     00004H
SE_DACL_DEFAULTED                               EQU     00008H
SE_SACL_PRESENT                                 EQU     00010H
SE_SACL_DEFAULTED                               EQU     00020H
SE_DACL_AUTO_INHERIT_REQ                        EQU     00100H
SE_SACL_AUTO_INHERIT_REQ                        EQU     00200H
SE_DACL_AUTO_INHERITED                          EQU     00400H
SE_SACL_AUTO_INHERITED                          EQU     00800H
SE_DACL_PROTECTED                               EQU     01000H
SE_SACL_PROTECTED                               EQU     02000H
SE_RM_CONTROL_VALID                             EQU     04000H
SE_SELF_RELATIVE                                EQU     08000H

ACCESS_OBJECT_GUID                              EQU     0
ACCESS_PROPERTY_SET_GUID                        EQU     1
ACCESS_PROPERTY_GUID                            EQU     2
ACCESS_MAX_LEVEL                                EQU     4

AUDIT_ALLOW_NO_PRIVILEGE                        EQU     01H

ACCESS_DS_SOURCE_A                              EQU     <DS>
ACCESS_DS_SOURCE_W                              EQU     L("DS")
ACCESS_DS_OBJECT_TYPE_NAME_A                    EQU     <Directory Service Object>
ACCESS_DS_OBJECT_TYPE_NAME_W                    EQU     L("Directory Service Object")

SE_PRIVILEGE_ENABLED_BY_DEFAULT                 EQU     000000001H
SE_PRIVILEGE_ENABLED                            EQU     000000002H
SE_PRIVILEGE_REMOVED                            EQU     000000004H
SE_PRIVILEGE_USED_FOR_ACCESS                    EQU     080000000H

SE_PRIVILEGE_VALID_ATTRIBUTES                   EQU     (SE_PRIVILEGE_ENABLED_BY_DEFAULT OR SE_PRIVILEGE_ENABLED OR \
                                                        SE_PRIVILEGE_REMOVED OR SE_PRIVILEGE_USED_FOR_ACCESS)

PRIVILEGE_SET_ALL_NECESSARY                     EQU     1

SE_CREATE_TOKEN_NAME                            EQU     TEXT("SeCreateTokenPrivilege")
SE_ASSIGNPRIMARYTOKEN_NAME                      EQU     TEXT("SeAssignPrimaryTokenPrivilege")
SE_LOCK_MEMORY_NAME                             EQU     TEXT("SeLockMemoryPrivilege")
SE_INCREASE_QUOTA_NAME                          EQU     TEXT("SeIncreaseQuotaPrivilege")
SE_UNSOLICITED_INPUT_NAME                       EQU     TEXT("SeUnsolicitedInputPrivilege")
SE_MACHINE_ACCOUNT_NAME                         EQU     TEXT("SeMachineAccountPrivilege")
SE_TCB_NAME                                     EQU     TEXT("SeTcbPrivilege")
SE_SECURITY_NAME                                EQU     TEXT("SeSecurityPrivilege")
SE_TAKE_OWNERSHIP_NAME                          EQU     TEXT("SeTakeOwnershipPrivilege")
SE_LOAD_DRIVER_NAME                             EQU     TEXT("SeLoadDriverPrivilege")
SE_SYSTEM_PROFILE_NAME                          EQU     TEXT("SeSystemProfilePrivilege")
SE_SYSTEMTIME_NAME                              EQU     TEXT("SeSystemtimePrivilege")
SE_PROF_SINGLE_PROCESS_NAME                     EQU     TEXT("SeProfileSingleProcessPrivilege")
SE_INC_BASE_PRIORITY_NAME                       EQU     TEXT("SeIncreaseBasePriorityPrivilege")
SE_CREATE_PAGEFILE_NAME                         EQU     TEXT("SeCreatePagefilePrivilege")
SE_CREATE_PERMANENT_NAME                        EQU     TEXT("SeCreatePermanentPrivilege")
SE_BACKUP_NAME                                  EQU     TEXT("SeBackupPrivilege")
SE_RESTORE_NAME                                 EQU     TEXT("SeRestorePrivilege")
SE_SHUTDOWN_NAME                                EQU     TEXT("SeShutdownPrivilege")
SE_DEBUG_NAME                                   EQU     TEXT("SeDebugPrivilege")
SE_AUDIT_NAME                                   EQU     TEXT("SeAuditPrivilege")
SE_SYSTEM_ENVIRONMENT_NAME                      EQU     TEXT("SeSystemEnvironmentPrivilege")
SE_CHANGE_NOTIFY_NAME                           EQU     TEXT("SeChangeNotifyPrivilege")
SE_REMOTE_SHUTDOWN_NAME                         EQU     TEXT("SeRemoteShutdownPrivilege")
SE_UNDOCK_NAME                                  EQU     TEXT("SeUndockPrivilege")
SE_SYNC_AGENT_NAME                              EQU     TEXT("SeSyncAgentPrivilege")
SE_ENABLE_DELEGATION_NAME                       EQU     TEXT("SeEnableDelegationPrivilege")
SE_MANAGE_VOLUME_NAME                           EQU     TEXT("SeManageVolumePrivilege")
SE_IMPERSONATE_NAME                             EQU     TEXT("SeImpersonatePrivilege")
SE_CREATE_GLOBAL_NAME                           EQU     TEXT("SeCreateGlobalPrivilege")
SE_TRUSTED_CREDMAN_ACCESS_NAME                  EQU     TEXT("SeTrustedCredManAccessPrivilege")
SE_RELABEL_NAME                                 EQU     TEXT("SeRelabelPrivilege")
SE_INC_WORKING_SET_NAME                         EQU     TEXT("SeIncreaseWorkingSetPrivilege")
SE_TIME_ZONE_NAME                               EQU     TEXT("SeTimeZonePrivilege")
SE_CREATE_SYMBOLIC_LINK_NAME                    EQU     TEXT("SeCreateSymbolicLinkPrivilege")

TOKEN_ASSIGN_PRIMARY                            EQU     00001H
TOKEN_DUPLICATE                                 EQU     00002H
TOKEN_IMPERSONATE                               EQU     00004H
TOKEN_QUERY                                     EQU     00008H
TOKEN_QUERY_SOURCE                              EQU     00010H
TOKEN_ADJUST_PRIVILEGES                         EQU     00020H
TOKEN_ADJUST_GROUPS                             EQU     00040H
TOKEN_ADJUST_DEFAULT                            EQU     00080H
TOKEN_ADJUST_SESSIONID                          EQU     00100H

TOKEN_ALL_ACCESS_P                              EQU     (STANDARD_RIGHTS_REQUIRED OR TOKEN_ASSIGN_PRIMARY OR \
                                                        TOKEN_DUPLICATE OR TOKEN_IMPERSONATE OR TOKEN_QUERY OR \
                                                        TOKEN_ADJUST_PRIVILEGES OR TOKEN_ADJUST_GROUPS OR \
                                                        TOKEN_ADJUST_DEFAULT)

IFDEF APP_WIN64
    TOKEN_ALL_ACCESS                            EQU     TOKEN_ALL_ACCESS_P
ELSE
    TOKEN_ALL_ACCESS                            EQU     (TOKEN_ALL_ACCESS_P OR TOKEN_ADJUST_SESSIONID)
ENDIF

TOKEN_READ                                      EQU     (STANDARD_RIGHTS_READ OR TOKEN_QUERY)
TOKEN_WRITE                                     EQU     (STANDARD_RIGHTS_WRITE OR TOKEN_ADJUST_PRIVILEGES OR \
                                                        TOKEN_ADJUST_GROUPS OR TOKEN_ADJUST_DEFAULT)
TOKEN_EXECUTE                                   EQU     STANDARD_RIGHTS_EXECUTE
TOKEN_TRUST_CONSTRAINT_MASK                     EQU     (STANDARD_RIGHTS_READ OR TOKEN_QUERY OR TOKEN_QUERY_SOURCE)

POLICY_AUDIT_SUBCATEGORY_COUNT                  EQU     56

TOKEN_SOURCE_LENGTH                             EQU     8

TOKEN_MANDATORY_POLICY_OFF                      EQU     00H
TOKEN_MANDATORY_POLICY_NO_WRITE_UP              EQU     01H
TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN          EQU     02H
TOKEN_MANDATORY_POLICY_VALID_MASK               EQU     (TOKEN_MANDATORY_POLICY_NO_WRITE_UP OR TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN)

SECURITY_DYNAMIC_TRACKING                       EQU     TRUE
SECURITY_STATIC_TRACKING                        EQU     FALSE
SECURITY_CONTEXT_TRACKING_MODE                  TYPEDEF BOOLEAN
PSECURITY_CONTEXT_TRACKING_MODE                 TYPEDEF XPTR

DISABLE_MAX_PRIVILEGE                           EQU     01H
SANDBOX_INERT                                   EQU     02H
LUA_TOKEN                                       EQU     04H
WRITE_RESTRICTED                                EQU     08H

OWNER_SECURITY_INFORMATION                      EQU     000000001H
GROUP_SECURITY_INFORMATION                      EQU     000000002H
DACL_SECURITY_INFORMATION                       EQU     000000004H
SACL_SECURITY_INFORMATION                       EQU     000000008H
LABEL_SECURITY_INFORMATION                      EQU     000000010H
ATTRIBUTE_SECURITY_INFORMATION                  EQU     000000020H
SCOPE_SECURITY_INFORMATION                      EQU     000000040H
PROCESS_TRUST_LABEL_SECURITY_INFORMATION        EQU     000000080H
BACKUP_SECURITY_INFORMATION                     EQU     000010000H

PROTECTED_DACL_SECURITY_INFORMATION             EQU     080000000H
PROTECTED_SACL_SECURITY_INFORMATION             EQU     040000000H
UNPROTECTED_DACL_SECURITY_INFORMATION           EQU     020000000H
UNPROTECTED_SACL_SECURITY_INFORMATION           EQU     010000000H

PROCESS_TERMINATE                               EQU     00001H
PROCESS_CREATE_THREAD                           EQU     00002H
PROCESS_SET_SESSIONID                           EQU     00004H
PROCESS_VM_OPERATION                            EQU     00008H
PROCESS_VM_READ                                 EQU     00010H
PROCESS_VM_WRITE                                EQU     00020H
PROCESS_DUP_HANDLE                              EQU     00040H
PROCESS_CREATE_PROCESS                          EQU     00080H
PROCESS_SET_QUOTA                               EQU     00100H
PROCESS_SET_INFORMATION                         EQU     00200H
PROCESS_QUERY_INFORMATION                       EQU     00400H
PROCESS_SUSPEND_RESUME                          EQU     00800H
PROCESS_QUERY_LIMITED_INFORMATION               EQU     01000H
PROCESS_SET_LIMITED_INFORMATION                 EQU     02000H

IF NTDDI_VERSION LT NTDDI_VISTA
    PROCESS_ALL_ACCESS                          EQU     (STANDARD_RIGHTS_REQUIRED OR SYNCHRONIZE OR 0FFFH)
ELSE
    PROCESS_ALL_ACCESS                          EQU     (STANDARD_RIGHTS_REQUIRED OR SYNCHRONIZE OR 0FFFFH)
ENDIF

IFDEF APP_WIN64
    MAXIMUM_PROCESSORS                          EQU     64
ELSE
    MAXIMUM_PROCESSORS                          EQU     32
ENDIF 

THREAD_TERMINATE                                EQU     00001H
THREAD_SUSPEND_RESUME                           EQU     00002H
THREAD_GET_CONTEXT                              EQU     00008H
THREAD_SET_CONTEXT                              EQU     00010H
THREAD_QUERY_INFORMATION                        EQU     00040H
THREAD_SET_INFORMATION                          EQU     00020H
THREAD_SET_THREAD_TOKEN                         EQU     00080H
THREAD_IMPERSONATE                              EQU     00100H
THREAD_DIRECT_IMPERSONATION                     EQU     00200H
THREAD_SET_LIMITED_INFORMATION                  EQU     00400H
THREAD_QUERY_LIMITED_INFORMATION                EQU     00800H
THREAD_RESUME                                   EQU     01000H

IF NTDDI_VERSION LT NTDDI_VISTA
    THREAD_ALL_ACCESS                           EQU     (STANDARD_RIGHTS_REQUIRED OR SYNCHRONIZE OR 03FFH)
ELSE
    THREAD_ALL_ACCESS                           EQU     (STANDARD_RIGHTS_REQUIRED OR SYNCHRONIZE OR 0FFFFH)
ENDIF

JOB_OBJECT_ASSIGN_PROCESS                       EQU     00001H
JOB_OBJECT_SET_ATTRIBUTES                       EQU     00002H
JOB_OBJECT_QUERY                                EQU     00004H
JOB_OBJECT_TERMINATE                            EQU     00008H
JOB_OBJECT_SET_SECURITY_ATTRIBUTES              EQU     00010H
JOB_OBJECT_ALL_ACCESS                           EQU     (STANDARD_RIGHTS_REQUIRED OR SYNCHRONIZE OR 01FH)

FLS_MAXIMUM_AVAILABLE                           EQU     128
TLS_MINIMUM_AVAILABLE                           EQU     64

THREAD_BASE_PRIORITY_LOWRT                      EQU     15
THREAD_BASE_PRIORITY_MAX                        EQU     2
THREAD_BASE_PRIORITY_MIN                        EQU     (-2)
THREAD_BASE_PRIORITY_IDLE                       EQU     (-15)

JOB_OBJECT_TERMINATE_AT_END_OF_JOB              EQU     0
JOB_OBJECT_POST_AT_END_OF_JOB                   EQU     1

JOB_OBJECT_MSG_END_OF_JOB_TIME                  EQU     1
JOB_OBJECT_MSG_END_OF_PROCESS_TIME              EQU     2
JOB_OBJECT_MSG_ACTIVE_PROCESS_LIMIT             EQU     3
JOB_OBJECT_MSG_ACTIVE_PROCESS_ZERO              EQU     4
JOB_OBJECT_MSG_NEW_PROCESS                      EQU     6
JOB_OBJECT_MSG_EXIT_PROCESS                     EQU     7
JOB_OBJECT_MSG_ABNORMAL_EXIT_PROCESS            EQU     8
JOB_OBJECT_MSG_PROCESS_MEMORY_LIMIT             EQU     9
JOB_OBJECT_MSG_JOB_MEMORY_LIMIT                 EQU     10
JOB_OBJECT_MSG_NOTIFICATION_LIMIT               EQU     11
JOB_OBJECT_MSG_JOB_CYCLE_TIME_LIMIT             EQU     12

JOB_OBJECT_MSG_MINIMUM                          EQU     1
JOB_OBJECT_MSG_MAXIMUM                          EQU     12
JOB_OBJECT_VALID_COMPLETION_FILTER              EQU     (((1 SHL (JOB_OBJECT_MSG_MAXIMUM + 1))) - 1) - ((1 SHL JOB_OBJECT_MSG_MINIMUM) - 1)

OB_OBJECT_LIMIT_WORKINGSET                     EQU     000000001H
JOB_OBJECT_LIMIT_PROCESS_TIME                   EQU     000000002H
JOB_OBJECT_LIMIT_JOB_TIME                       EQU     000000004H
JOB_OBJECT_LIMIT_ACTIVE_PROCESS                 EQU     000000008H
JOB_OBJECT_LIMIT_AFFINITY                       EQU     000000010H
JOB_OBJECT_LIMIT_PRIORITY_CLASS                 EQU     000000020H
JOB_OBJECT_LIMIT_PRESERVE_JOB_TIME              EQU     000000040H
JOB_OBJECT_LIMIT_SCHEDULING_CLASS               EQU     000000080H

JOB_OBJECT_LIMIT_PROCESS_MEMORY                 EQU     000000100H
JOB_OBJECT_LIMIT_JOB_MEMORY                     EQU     000000200H
JOB_OBJECT_LIMIT_DIE_ON_UNHANDLED_EXCEPTION     EQU     000000400H
JOB_OBJECT_LIMIT_BREAKAWAY_OK                   EQU     000000800H
JOB_OBJECT_LIMIT_SILENT_BREAKAWAY_OK            EQU     000001000H
JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE              EQU     000002000H
JOB_OBJECT_LIMIT_SUBSET_AFFINITY                EQU     000004000H
JOB_OBJECT_LIMIT_RESERVED3                      EQU     000008000H
JOB_OBJECT_LIMIT_RESERVED4                      EQU     000010000H
JOB_OBJECT_LIMIT_RESERVED5                      EQU     000020000H
JOB_OBJECT_LIMIT_RESERVED6                      EQU     000040000H

JOB_OBJECT_LIMIT_JOB_READ_BYTES                 EQU     000010000H
JOB_OBJECT_LIMIT_JOB_WRITE_BYTES                EQU     000020000H
JOB_OBJECT_LIMIT_RATE_CONTROL                   EQU     000040000H

JOB_OBJECT_LIMIT_VALID_FLAGS                    EQU     00007FFFFH

JOB_OBJECT_BASIC_LIMIT_VALID_FLAGS              EQU     0000000FFH
JOB_OBJECT_EXTENDED_LIMIT_VALID_FLAGS           EQU     000007FFFH
JOB_OBJECT_NOTIFICATION_LIMIT_VALID_FLAGS       EQU     000070204H
JOB_OBJECT_RESERVED_LIMIT_VALID_FLAGS           EQU     00007FFFFH

JOB_OBJECT_UILIMIT_NONE                         EQU     000000000H
JOB_OBJECT_UILIMIT_HANDLES                      EQU     000000001H
JOB_OBJECT_UILIMIT_READCLIPBOARD                EQU     000000002H
JOB_OBJECT_UILIMIT_WRITECLIPBOARD               EQU     000000004H
JOB_OBJECT_UILIMIT_SYSTEMPARAMETERS             EQU     000000008H
JOB_OBJECT_UILIMIT_DISPLAYSETTINGS              EQU     000000010H
JOB_OBJECT_UILIMIT_GLOBALATOMS                  EQU     000000020H
JOB_OBJECT_UILIMIT_DESKTOP                      EQU     000000040H
JOB_OBJECT_UILIMIT_EXITWINDOWS                  EQU     000000080H
JOB_OBJECT_UILIMIT_ALL                          EQU     0000000FFH

JOB_OBJECT_UI_VALID_FLAGS                       EQU     0000000FFH

JOB_OBJECT_SECURITY_NO_ADMIN                    EQU     000000001H
JOB_OBJECT_SECURITY_RESTRICTED_TOKEN            EQU     000000002H
JOB_OBJECT_SECURITY_ONLY_TOKEN                  EQU     000000004H
JOB_OBJECT_SECURITY_FILTER_TOKENS               EQU     000000008H
JOB_OBJECT_SECURITY_VALID_FLAGS                 EQU     00000000FH

EVENT_MODIFY_STATE                              EQU     00002H
EVENT_ALL_ACCESS                                EQU     (STANDARD_RIGHTS_REQUIRED OR SYNCHRONIZE OR 03H)
MUTANT_QUERY_STATE                              EQU     00001H
MUTANT_ALL_ACCESS                               EQU     (STANDARD_RIGHTS_REQUIRED OR SYNCHRONIZE OR MUTANT_QUERY_STATE)
SEMAPHORE_MODIFY_STATE                          EQU     00002H
SEMAPHORE_ALL_ACCESS                            EQU     (STANDARD_RIGHTS_REQUIRED OR SYNCHRONIZE OR 03H)

TIMER_QUERY_STATE                               EQU     00001H
TIMER_MODIFY_STATE                              EQU     00002H
TIMER_ALL_ACCESS                                EQU     (STANDARD_RIGHTS_REQUIRED OR SYNCHRONIZE OR TIMER_QUERY_STATE OR TIMER_MODIFY_STATE)

TIME_ZONE_ID_UNKNOWN                            EQU     0
TIME_ZONE_ID_STANDARD                           EQU     1
TIME_ZONE_ID_DAYLIGHT                           EQU     2

PROCESSOR_INTEL_386                             EQU     386
PROCESSOR_INTEL_486                             EQU     486
PROCESSOR_INTEL_PENTIUM                         EQU     586
PROCESSOR_INTEL_IA64                            EQU     2200
PROCESSOR_AMD_X8664                             EQU     8664
PROCESSOR_MIPS_R4000                            EQU     4000
PROCESSOR_ALPHA_21064                           EQU     21064
PROCESSOR_PPC_601                               EQU     601
PROCESSOR_PPC_603                               EQU     603
PROCESSOR_PPC_604                               EQU     604
PROCESSOR_PPC_620                               EQU     620
PROCESSOR_HITACHI_SH3                           EQU     10003
PROCESSOR_HITACHI_SH3E                          EQU     10004
PROCESSOR_HITACHI_SH4                           EQU     10005
PROCESSOR_MOTOROLA_821                          EQU     821
PROCESSOR_SHx_SH3                               EQU     103
PROCESSOR_SHx_SH4                               EQU     104
PROCESSOR_STRONGARM                             EQU     2577
PROCESSOR_ARM720                                EQU     1824
PROCESSOR_ARM820                                EQU     2080
PROCESSOR_ARM920                                EQU     2336
PROCESSOR_ARM_7TDMI                             EQU     70001
PROCESSOR_OPTIL                                 EQU     0494FH

PROCESSOR_ARCHITECTURE_INTEL                    EQU     0
PROCESSOR_ARCHITECTURE_MIPS                     EQU     1
PROCESSOR_ARCHITECTURE_ALPHA                    EQU     2
PROCESSOR_ARCHITECTURE_PPC                      EQU     3
PROCESSOR_ARCHITECTURE_SHX                      EQU     4
PROCESSOR_ARCHITECTURE_ARM                      EQU     5
PROCESSOR_ARCHITECTURE_IA64                     EQU     6
PROCESSOR_ARCHITECTURE_ALPHA64                  EQU     7
PROCESSOR_ARCHITECTURE_MSIL                     EQU     8
PROCESSOR_ARCHITECTURE_AMD64                    EQU     9
PROCESSOR_ARCHITECTURE_IA32_ON_WIN64            EQU     10

PROCESSOR_ARCHITECTURE_NEUTRAL                  EQU     11
PROCESSOR_ARCHITECTURE_UNKNOWN                  EQU     0FFFFH

PF_FLOATING_POINT_PRECISION_ERRATA              EQU     0
PF_FLOATING_POINT_EMULATED                      EQU     1
PF_COMPARE_EXCHANGE_DOUBLE                      EQU     2
PF_MMX_INSTRUCTIONS_AVAILABLE                   EQU     3
PF_PPC_MOVEMEM_64BIT_OK                         EQU     4
PF_ALPHA_BYTE_INSTRUCTIONS                      EQU     5
PF_XMMI_INSTRUCTIONS_AVAILABLE                  EQU     6
PF_3DNOW_INSTRUCTIONS_AVAILABLE                 EQU     7
PF_RDTSC_INSTRUCTION_AVAILABLE                  EQU     8
PF_PAE_ENABLED                                  EQU     9
PF_XMMI64_INSTRUCTIONS_AVAILABLE                EQU     10
PF_SSE_DAZ_MODE_AVAILABLE                       EQU     11
PF_NX_ENABLED                                   EQU     12
PF_SSE3_INSTRUCTIONS_AVAILABLE                  EQU     13
PF_COMPARE_EXCHANGE128                          EQU     14
PF_COMPARE64_EXCHANGE128                        EQU     15
PF_CHANNELS_ENABLED                             EQU     16
PF_XSAVE_ENABLED                                EQU     17
PF_ARM_VFP_32_REGISTERS_AVAILABLE               EQU     18
PF_ARM_NEON_INSTRUCTIONS_AVAILABLE              EQU     19
PF_SECOND_LEVEL_ADDRESS_TRANSLATION             EQU     20
PF_VIRT_FIRMWARE_ENABLED                        EQU     21
PF_RDWRFSGSBASE_AVAILABLE                       EQU     22
PF_FASTFAIL_AVAILABLE                           EQU     23
PF_ARM_DIVIDE_INSTRUCTION_AVAILABLE             EQU     24
PF_ARM_64BIT_LOADSTORE_ATOMIC                   EQU     25
PF_ARM_EXTERNAL_CACHE_AVAILABLE                 EQU     26
PF_ARM_FMAC_INSTRUCTIONS_AVAILABLE              EQU     27
PF_RDRAND_INSTRUCTION_AVAILABLE                 EQU     28

SECTION_QUERY                                   EQU     00001H
SECTION_MAP_WRITE                               EQU     00002H
SECTION_MAP_READ                                EQU     00004H
SECTION_MAP_EXECUTE                             EQU     00008H
SECTION_EXTEND_SIZE                             EQU     00010H
SECTION_MAP_EXECUTE_EXPLICIT                    EQU     00020H
SECTION_ALL_ACCESS                              EQU     (STANDARD_RIGHTS_REQUIRED OR SECTION_QUERY OR SECTION_MAP_WRITE OR \
                                                        SECTION_MAP_READ OR SECTION_MAP_EXECUTE OR SECTION_EXTEND_SIZE)

SESSION_QUERY_ACCESS                            EQU     00001H
SESSION_MODIFY_ACCESS                           EQU     00002H
SESSION_ALL_ACCESS                              EQU     (STANDARD_RIGHTS_REQUIRED OR SESSION_QUERY_ACCESS OR SESSION_MODIFY_ACCESS)

PAGE_NOACCESS                                   EQU     001H
PAGE_READONLY                                   EQU     002H
PAGE_READWRITE                                  EQU     004H
PAGE_WRITECOPY                                  EQU     008H
PAGE_EXECUTE                                    EQU     010H
PAGE_EXECUTE_READ                               EQU     020H
PAGE_EXECUTE_READWRITE                          EQU     040H
PAGE_EXECUTE_WRITECOPY                          EQU     080H

PAGE_GUARD                                      EQU     0100H
PAGE_NOCACHE                                    EQU     0200H
PAGE_WRITECOMBINE                               EQU     0400H
PAGE_REVERT_TO_FILE_MAP                         EQU     080000000H

MEM_COMMIT                                      EQU     01000H
MEM_RESERVE                                     EQU     02000H
MEM_DECOMMIT                                    EQU     04000H
MEM_RELEASE                                     EQU     08000H
MEM_FREE                                        EQU     010000H
MEM_PRIVATE                                     EQU     020000H
MEM_MAPPED                                      EQU     040000H
MEM_RESET                                       EQU     080000H
MEM_TOP_DOWN                                    EQU     0100000H
MEM_WRITE_WATCH                                 EQU     0200000H
MEM_PHYSICAL                                    EQU     0400000H
MEM_ROTATE                                      EQU     0800000H
MEM_DIFFERENT_IMAGE_BASE_OK                     EQU     0800000H
MEM_RESET_UNDO                                  EQU     01000000H
MEM_LARGE_PAGES                                 EQU     020000000H
MEM_4MB_PAGES                                   EQU     080000000H

SEC_IMAGE                                       EQU     01000000H
MEM_IMAGE                                       EQU     SEC_IMAGE

WRITE_WATCH_FLAG_RESET                          EQU     001H

FILE_READ_DATA                                  EQU     00001H
FILE_LIST_DIRECTORY                             EQU     00001H
FILE_WRITE_DATA                                 EQU     00002H
FILE_ADD_FILE                                   EQU     00002H

FILE_APPEND_DATA                                EQU     00004H
FILE_ADD_SUBDIRECTORY                           EQU     00004H
FILE_CREATE_PIPE_INSTANCE                       EQU     00004H
FILE_READ_EA                                    EQU     00008H
FILE_WRITE_EA                                   EQU     00010H
FILE_EXECUTE                                    EQU     00020H
FILE_TRAVERSE                                   EQU     00020H
FILE_DELETE_CHILD                               EQU     00040H
FILE_READ_ATTRIBUTES                            EQU     00080H
FILE_WRITE_ATTRIBUTES                           EQU     00100H

FILE_ALL_ACCESS                                 EQU     (STANDARD_RIGHTS_REQUIRED OR SYNCHRONIZE OR 01FFH)
FILE_GENERIC_READ                               EQU     (STANDARD_RIGHTS_READ OR FILE_READ_DATA OR FILE_READ_ATTRIBUTES OR \
                                                        FILE_READ_EA OR SYNCHRONIZE)
FILE_GENERIC_WRITE                              EQU     (STANDARD_RIGHTS_WRITE OR FILE_WRITE_DATA OR \
                                                        FILE_WRITE_ATTRIBUTES OR FILE_WRITE_EA OR \
                                                        FILE_APPEND_DATA OR SYNCHRONIZE)
FILE_GENERIC_EXECUTE                            EQU     (STANDARD_RIGHTS_EXECUTE OR FILE_READ_ATTRIBUTES OR \
                                                        FILE_EXECUTE OR SYNCHRONIZE)

FILE_SHARE_READ                                 EQU     000000001H
FILE_SHARE_WRITE                                EQU     000000002H
FILE_SHARE_DELETE                               EQU     000000004H

FILE_ATTRIBUTE_READONLY                         EQU     000000001H
FILE_ATTRIBUTE_HIDDEN                           EQU     000000002H
FILE_ATTRIBUTE_SYSTEM                           EQU     000000004H
FILE_ATTRIBUTE_DIRECTORY                        EQU     000000010H
FILE_ATTRIBUTE_ARCHIVE                          EQU     000000020H
FILE_ATTRIBUTE_DEVICE                           EQU     000000040H
FILE_ATTRIBUTE_NORMAL                           EQU     000000080H
FILE_ATTRIBUTE_TEMPORARY                        EQU     000000100H
FILE_ATTRIBUTE_SPARSE_FILE                      EQU     000000200H
FILE_ATTRIBUTE_REPARSE_POINT                    EQU     000000400H
FILE_ATTRIBUTE_COMPRESSED                       EQU     000000800H
FILE_ATTRIBUTE_OFFLINE                          EQU     000001000H
FILE_ATTRIBUTE_NOT_CONTENT_INDEXED              EQU     000002000H
FILE_ATTRIBUTE_ENCRYPTED                        EQU     000004000H
FILE_ATTRIBUTE_INTEGRITY_STREAM                 EQU     000008000H
FILE_ATTRIBUTE_VIRTUAL                          EQU     000010000H
FILE_ATTRIBUTE_NO_SCRUB_DATA                    EQU     000020000H
FILE_ATTRIBUTE_EA                               EQU     000040000H

FILE_NOTIFY_CHANGE_FILE_NAME                    EQU     000000001H
FILE_NOTIFY_CHANGE_DIR_NAME                     EQU     000000002H
FILE_NOTIFY_CHANGE_ATTRIBUTES                   EQU     000000004H
FILE_NOTIFY_CHANGE_SIZE                         EQU     000000008H
FILE_NOTIFY_CHANGE_LAST_WRITE                   EQU     000000010H
FILE_NOTIFY_CHANGE_LAST_ACCESS                  EQU     000000020H
FILE_NOTIFY_CHANGE_CREATION                     EQU     000000040H
FILE_NOTIFY_CHANGE_SECURITY                     EQU     000000100H

FILE_ACTION_ADDED                               EQU     000000001H
FILE_ACTION_REMOVED                             EQU     000000002H
FILE_ACTION_MODIFIED                            EQU     000000003H
FILE_ACTION_RENAMED_OLD_NAME                    EQU     000000004H
FILE_ACTION_RENAMED_NEW_NAME                    EQU     000000005H

FILE_CASE_SENSITIVE_SEARCH                      EQU     000000001H
FILE_CASE_PRESERVED_NAMES                       EQU     000000002H
FILE_UNICODE_ON_DISK                            EQU     000000004H
FILE_PERSISTENT_ACLS                            EQU     000000008H
FILE_FILE_COMPRESSION                           EQU     000000010H
FILE_VOLUME_QUOTAS                              EQU     000000020H
FILE_SUPPORTS_SPARSE_FILES                      EQU     000000040H
FILE_SUPPORTS_REPARSE_POINTS                    EQU     000000080H
FILE_SUPPORTS_REMOTE_STORAGE                    EQU     000000100H
FILE_VOLUME_IS_COMPRESSED                       EQU     000008000H
FILE_SUPPORTS_OBJECT_IDS                        EQU     000010000H
FILE_SUPPORTS_ENCRYPTION                        EQU     000020000H
FILE_NAMED_STREAMS                              EQU     000040000H
FILE_READ_ONLY_VOLUME                           EQU     000080000H
FILE_SEQUENTIAL_WRITE_ONCE                      EQU     000100000H
FILE_SUPPORTS_TRANSACTIONS                      EQU     000200000H
FILE_SUPPORTS_HARD_LINKS                        EQU     000400000H
FILE_SUPPORTS_EXTENDED_ATTRIBUTES               EQU     000800000H
FILE_SUPPORTS_OPEN_BY_FILE_ID                   EQU     001000000H
FILE_SUPPORTS_USN_JOURNAL                       EQU     002000000H
FILE_SUPPORTS_INTEGRITY_STREAMS                 EQU     004000000H
FILE_INVALID_FILE_ID                            EQU     (-1)

MAILSLOT_NO_MESSAGE                             EQU     (-1)
MAILSLOT_WAIT_FOREVER                           EQU     (-1)

MAXIMUM_REPARSE_DATA_BUFFER_SIZE                EQU     (16 * 1024)

IO_REPARSE_TAG_RESERVED_ZERO                    EQU     0
IO_REPARSE_TAG_RESERVED_ONE                     EQU     1
IO_REPARSE_TAG_RESERVED_RANGE                   EQU     IO_REPARSE_TAG_RESERVED_ONE

IO_REPARSE_TAG_MOUNT_POINT                      EQU     0A0000003H
IO_REPARSE_TAG_HSM                              EQU     0C0000004H
IO_REPARSE_TAG_HSM2                             EQU     080000006H
IO_REPARSE_TAG_SIS                              EQU     080000007H
IO_REPARSE_TAG_WIM                              EQU     080000008H
IO_REPARSE_TAG_CSV                              EQU     080000009H
IO_REPARSE_TAG_DFS                              EQU     08000000AH
IO_REPARSE_TAG_SYMLINK                          EQU     0A000000CH
IO_REPARSE_TAG_DFSR                             EQU     080000012H
IO_REPARSE_TAG_DEDUP                            EQU     080000013H
IO_REPARSE_TAG_NFS                              EQU     080000014H
IO_REPARSE_TAG_FILE_PLACEHOLDER                 EQU     080000015H
IO_REPARSE_TAG_WOF                              EQU     080000017H

IO_COMPLETION_MODIFY_STATE                      EQU     00002H
IO_COMPLETION_ALL_ACCESS                        EQU     (STANDARD_RIGHTS_REQUIRED OR SYNCHRONIZE OR 03H)

DUPLICATE_CLOSE_SOURCE                          EQU     000000001H
DUPLICATE_SAME_ACCESS                           EQU     000000002H

POWER_SYSTEM_MAXIMUM                            EQU     7

ES_SYSTEM_REQUIRED                              EQU     000000001H
ES_DISPLAY_REQUIRED                             EQU     000000002H
ES_USER_PRESENT                                 EQU     000000004H
ES_AWAYMODE_REQUIRED                            EQU     000000040H
ES_CONTINUOUS                                   EQU     080000000H

IMAGE_DOS_SIGNATURE                             EQU     05A4DH
IMAGE_OS2_SIGNATURE                             EQU     0454EH
IMAGE_OS2_SIGNATURE_LE                          EQU     0454CH
IMAGE_VXD_SIGNATURE                             EQU     0454CH
IMAGE_NT_SIGNATURE                              EQU     000004550H

IMAGE_SIZEOF_FILE_HEADER                        EQU     20

IMAGE_FILE_RELOCS_STRIPPED                      EQU     00001H
IMAGE_FILE_EXECUTABLE_IMAGE                     EQU     00002H
IMAGE_FILE_LINE_NUMS_STRIPPED                   EQU     00004H
IMAGE_FILE_LOCAL_SYMS_STRIPPED                  EQU     00008H
IMAGE_FILE_AGGRESIVE_WS_TRIM                    EQU     00010H
IMAGE_FILE_LARGE_ADDRESS_AWARE                  EQU     00020H
IMAGE_FILE_BYTES_REVERSED_LO                    EQU     00080H
IMAGE_FILE_32BIT_MACHINE                        EQU     00100H
IMAGE_FILE_DEBUG_STRIPPED                       EQU     00200H
IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP              EQU     00400H
IMAGE_FILE_NET_RUN_FROM_SWAP                    EQU     00800H
IMAGE_FILE_SYSTEM                               EQU     01000H
IMAGE_FILE_DLL                                  EQU     02000H
IMAGE_FILE_UP_SYSTEM_ONLY                       EQU     04000H
IMAGE_FILE_BYTES_REVERSED_HI                    EQU     08000H

IMAGE_FILE_MACHINE_UNKNOWN                      EQU     0
IMAGE_FILE_MACHINE_I386                         EQU     014cH
IMAGE_FILE_MACHINE_R3000                        EQU     0162H
IMAGE_FILE_MACHINE_R4000                        EQU     0166H
IMAGE_FILE_MACHINE_R10000                       EQU     0168H
IMAGE_FILE_MACHINE_WCEMIPSV2                    EQU     0169H
IMAGE_FILE_MACHINE_ALPHA                        EQU     0184H
IMAGE_FILE_MACHINE_POWERPC                      EQU     01F0H
IMAGE_FILE_MACHINE_SH3                          EQU     01a2H
IMAGE_FILE_MACHINE_SH3E                         EQU     01a4H
IMAGE_FILE_MACHINE_SH4                          EQU     01a6H
IMAGE_FILE_MACHINE_ARM                          EQU     01c0H
IMAGE_FILE_MACHINE_THUMB                        EQU     01c2H
IMAGE_FILE_MACHINE_IA64                         EQU     0200H
IMAGE_FILE_MACHINE_MIPS16                       EQU     0266H
IMAGE_FILE_MACHINE_MIPSFPU                      EQU     0366H
IMAGE_FILE_MACHINE_MIPSFPU16                    EQU     0466H
IMAGE_FILE_MACHINE_ALPHA64                      EQU     0284H
IMAGE_FILE_MACHINE_AXP64                        EQU     IMAGE_FILE_MACHINE_ALPHA64
IMAGE_FILE_MACHINE_CEF                          EQU     0C0EFH
IMAGE_FILE_MACHINE_EBC                          EQU     0EBCH
IMAGE_FILE_MACHINE_AMD64                        EQU     8664H
IMAGE_FILE_MACHINE_M32R                         EQU     9041H
IMAGE_FILE_MACHINE_CEE                          EQU     0C0EEH

IMAGE_SIZEOF_ROM_OPTIONAL_HEADER                EQU     56
IMAGE_SIZEOF_STD_OPTIONAL_HEADER                EQU     28
IMAGE_SIZEOF_NT_OPTIONAL32_HEADER               EQU     224
IMAGE_SIZEOF_NT_OPTIONAL64_HEADER               EQU     240

IMAGE_NT_OPTIONAL_HDR32_MAGIC                   EQU     10bH
IMAGE_NT_OPTIONAL_HDR64_MAGIC                   EQU     20bH
IMAGE_ROM_OPTIONAL_HDR_MAGIC                    EQU     107H

IMAGE_SUBSYSTEM_UNKNOWN                         EQU     0
IMAGE_SUBSYSTEM_NATIVE                          EQU     1
IMAGE_SUBSYSTEM_WINDOWS_GUI                     EQU     2
IMAGE_SUBSYSTEM_WINDOWS_CUI                     EQU     3
IMAGE_SUBSYSTEM_OS2_CUI                         EQU     5
IMAGE_SUBSYSTEM_POSIX_CUI                       EQU     7
IMAGE_SUBSYSTEM_NATIVE_WINDOWS                  EQU     8
IMAGE_SUBSYSTEM_WINDOWS_CE_GUI                  EQU     9
IMAGE_SUBSYSTEM_EFI_APPLICATION                 EQU     10
IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER         EQU     11
IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER              EQU     12
IMAGE_SUBSYSTEM_EFI_ROM                         EQU     13
IMAGE_SUBSYSTEM_XBOX                            EQU     14
IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION        EQU     16

IMAGE_DLLCHARACTERISTICS_NO_BIND                EQU     0800H
IMAGE_DLLCHARACTERISTICS_WDM_DRIVER             EQU     2000H
IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE  EQU     8000H
IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE           EQU     0040H
IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY        EQU     0080H
IMAGE_DLLCHARACTERISTICS_NX_COMPAT              EQU     0100H
IMAGE_DLLCHARACTERISTICS_NO_ISOLATION           EQU     0200H
IMAGE_DLLCHARACTERISTICS_NO_SEH                 EQU     0400H

IMAGE_DIRECTORY_ENTRY_EXPORT                    EQU     0
IMAGE_DIRECTORY_ENTRY_IMPORT                    EQU     1
IMAGE_DIRECTORY_ENTRY_RESOURCE                  EQU     2
IMAGE_DIRECTORY_ENTRY_EXCEPTION                 EQU     3
IMAGE_DIRECTORY_ENTRY_SECURITY                  EQU     4
IMAGE_DIRECTORY_ENTRY_BASERELOC                 EQU     5
IMAGE_DIRECTORY_ENTRY_DEBUG                     EQU     6
IMAGE_DIRECTORY_ENTRY_COPYRIGHT                 EQU     7
IMAGE_DIRECTORY_ENTRY_ARCHITECTURE              EQU     7
IMAGE_DIRECTORY_ENTRY_GLOBALPTR                 EQU     8
IMAGE_DIRECTORY_ENTRY_TLS                       EQU     9
IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG               EQU     10
IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT              EQU     11
IMAGE_DIRECTORY_ENTRY_IAT                       EQU     12
IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT              EQU     13
IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR            EQU     14

IMAGE_SIZEOF_SHORT_NAME                         EQU     8
IMAGE_SIZEOF_SECTION_HEADER                     EQU     40

IMAGE_SIZEOF_SYMBOL                             EQU     18

IMAGE_SYM_UNDEFINED                             EQU     0
IMAGE_SYM_ABSOLUTE                              EQU     (-1)
IMAGE_SYM_DEBUG                                 EQU     (-2)

IMAGE_SYM_TYPE_NULL                             EQU     0000H
IMAGE_SYM_TYPE_VOID                             EQU     0001H
IMAGE_SYM_TYPE_CHAR                             EQU     0002H
IMAGE_SYM_TYPE_SHORT                            EQU     0003H
IMAGE_SYM_TYPE_INT                              EQU     0004H
IMAGE_SYM_TYPE_LONG                             EQU     0005H
IMAGE_SYM_TYPE_FLOAT                            EQU     0006H
IMAGE_SYM_TYPE_DOUBLE                           EQU     0007H
IMAGE_SYM_TYPE_STRUCT                           EQU     0008H
IMAGE_SYM_TYPE_UNION                            EQU     0009H
IMAGE_SYM_TYPE_ENUM                             EQU     000AH
IMAGE_SYM_TYPE_MOE                              EQU     000BH
IMAGE_SYM_TYPE_BYTE                             EQU     000CH
IMAGE_SYM_TYPE_WORD                             EQU     000DH
IMAGE_SYM_TYPE_UINT                             EQU     000EH
IMAGE_SYM_TYPE_DWORD                            EQU     000FH
IMAGE_SYM_TYPE_PCODE                            EQU     8000H

IMAGE_SYM_DTYPE_NULL                            EQU     0
IMAGE_SYM_DTYPE_POINTER                         EQU     1
IMAGE_SYM_DTYPE_FUNCTION                        EQU     2
IMAGE_SYM_DTYPE_ARRAY                           EQU     3

IMAGE_SYM_CLASS_END_OF_FUNCTION                 EQU     (-1)
IMAGE_SYM_CLASS_NULL                            EQU     0000H
IMAGE_SYM_CLASS_AUTOMATIC                       EQU     0001H
IMAGE_SYM_CLASS_EXTERNAL                        EQU     0002H
IMAGE_SYM_CLASS_STATIC                          EQU     0003H
IMAGE_SYM_CLASS_REGISTER                        EQU     0004H
IMAGE_SYM_CLASS_EXTERNAL_DEF                    EQU     0005H
IMAGE_SYM_CLASS_LABEL                           EQU     0006H
IMAGE_SYM_CLASS_UNDEFINED_LABEL                 EQU     0007H
IMAGE_SYM_CLASS_MEMBER_OF_STRUCT                EQU     0008H
IMAGE_SYM_CLASS_ARGUMENT                        EQU     0009H
IMAGE_SYM_CLASS_STRUCT_TAG                      EQU     000AH
IMAGE_SYM_CLASS_MEMBER_OF_UNION                 EQU     000BH
IMAGE_SYM_CLASS_UNION_TAG                       EQU     000CH
IMAGE_SYM_CLASS_TYPE_DEFINITION                 EQU     000DH
IMAGE_SYM_CLASS_UNDEFINED_STATIC                EQU     000EH
IMAGE_SYM_CLASS_ENUM_TAG                        EQU     000FH
IMAGE_SYM_CLASS_MEMBER_OF_ENUM                  EQU     0010H
IMAGE_SYM_CLASS_REGISTER_PARAM                  EQU     0011H
IMAGE_SYM_CLASS_BIT_FIELD                       EQU     0012H

IMAGE_SYM_CLASS_FAR_EXTERNAL                    EQU     0044H

IMAGE_SYM_CLASS_BLOCK                           EQU     0064H
IMAGE_SYM_CLASS_FUNCTION                        EQU     0065H
IMAGE_SYM_CLASS_END_OF_STRUCT                   EQU     0066H
IMAGE_SYM_CLASS_FILE                            EQU     0067H
IMAGE_SYM_CLASS_SECTION                         EQU     0068H
IMAGE_SYM_CLASS_WEAK_EXTERNAL                   EQU     0069H

IMAGE_SIZEOF_AUX_SYMBOL                         EQU     18

IMAGE_COMDAT_SELECT_NODUPLICATES                EQU     1
IMAGE_COMDAT_SELECT_ANY                         EQU     2
IMAGE_COMDAT_SELECT_SAME_SIZE                   EQU     3
IMAGE_COMDAT_SELECT_EXACT_MATCH                 EQU     4
IMAGE_COMDAT_SELECT_ASSOCIATIVE                 EQU     5
IMAGE_COMDAT_SELECT_LARGEST                     EQU     6
IMAGE_COMDAT_SELECT_NEWEST                      EQU     7

IMAGE_WEAK_EXTERN_SEARCH_NOLIBRARY              EQU     1
IMAGE_WEAK_EXTERN_SEARCH_LIBRARY                EQU     2
IMAGE_WEAK_EXTERN_SEARCH_ALIAS                  EQU     3

IMAGE_SIZEOF_RELOCATION                         EQU     10

IMAGE_REL_I386_ABSOLUTE                         EQU     0000H
IMAGE_REL_I386_DIR16                            EQU     0001H
IMAGE_REL_I386_REL16                            EQU     0002H
IMAGE_REL_I386_DIR32                            EQU     0006H
IMAGE_REL_I386_DIR32NB                          EQU     0007H
IMAGE_REL_I386_SEG12                            EQU     0009H
IMAGE_REL_I386_SECTION                          EQU     000AH
IMAGE_REL_I386_SECREL                           EQU     000BH
IMAGE_REL_I386_REL32                            EQU     0014H

IMAGE_REL_MIPS_ABSOLUTE                         EQU     0000H
IMAGE_REL_MIPS_REFHALF                          EQU     0001H
IMAGE_REL_MIPS_REFWORD                          EQU     0002H
IMAGE_REL_MIPS_JMPADDR                          EQU     0003H
IMAGE_REL_MIPS_REFHI                            EQU     0004H
IMAGE_REL_MIPS_REFLO                            EQU     0005H
IMAGE_REL_MIPS_GPREL                            EQU     0006H
IMAGE_REL_MIPS_LITERAL                          EQU     0007H
IMAGE_REL_MIPS_SECTION                          EQU     000AH
IMAGE_REL_MIPS_SECREL                           EQU     000BH
IMAGE_REL_MIPS_SECRELLO                         EQU     000CH
IMAGE_REL_MIPS_SECRELHI                         EQU     000DH
IMAGE_REL_MIPS_TOKEN                            EQU     000EH
IMAGE_REL_MIPS_JMPADDR16                        EQU     0010H
IMAGE_REL_MIPS_REFWORDNB                        EQU     0022H
IMAGE_REL_MIPS_PAIR                             EQU     0025H

IMAGE_REL_ALPHA_ABSOLUTE                        EQU     0000H
IMAGE_REL_ALPHA_REFLONG                         EQU     0001H
IMAGE_REL_ALPHA_REFQUAD                         EQU     0002H
IMAGE_REL_ALPHA_GPREL32                         EQU     0003H
IMAGE_REL_ALPHA_LITERAL                         EQU     0004H
IMAGE_REL_ALPHA_LITUSE                          EQU     0005H
IMAGE_REL_ALPHA_GPDISP                          EQU     0006H
IMAGE_REL_ALPHA_BRADDR                          EQU     0007H
IMAGE_REL_ALPHA_HINT                            EQU     0008H
IMAGE_REL_ALPHA_INLINE_REFLONG                  EQU     0009H
IMAGE_REL_ALPHA_REFHI                           EQU     000AH
IMAGE_REL_ALPHA_REFLO                           EQU     000BH
IMAGE_REL_ALPHA_PAIR                            EQU     000CH
IMAGE_REL_ALPHA_MATCH                           EQU     000DH
IMAGE_REL_ALPHA_SECTION                         EQU     000EH
IMAGE_REL_ALPHA_SECREL                          EQU     000FH
IMAGE_REL_ALPHA_REFLONGNB                       EQU     0010H
IMAGE_REL_ALPHA_SECRELLO                        EQU     0011H
IMAGE_REL_ALPHA_SECRELHI                        EQU     0012H
IMAGE_REL_ALPHA_REFQ3                           EQU     0013H
IMAGE_REL_ALPHA_REFQ2                           EQU     0014H
IMAGE_REL_ALPHA_REFQ1                           EQU     0015H
IMAGE_REL_ALPHA_GPRELLO                         EQU     0016H
IMAGE_REL_ALPHA_GPRELHI                         EQU     0017H

IMAGE_REL_PPC_ABSOLUTE                          EQU     0000H
IMAGE_REL_PPC_ADDR64                            EQU     0001H
IMAGE_REL_PPC_ADDR32                            EQU     0002H
IMAGE_REL_PPC_ADDR24                            EQU     0003H
IMAGE_REL_PPC_ADDR16                            EQU     0004H
IMAGE_REL_PPC_ADDR14                            EQU     0005H
IMAGE_REL_PPC_REL24                             EQU     0006H
IMAGE_REL_PPC_REL14                             EQU     0007H
IMAGE_REL_PPC_TOCREL16                          EQU     0008H
IMAGE_REL_PPC_TOCREL14                          EQU     0009H

IMAGE_REL_PPC_ADDR32NB                          EQU     000AH
IMAGE_REL_PPC_SECREL                            EQU     000BH
IMAGE_REL_PPC_SECTION                           EQU     000CH
IMAGE_REL_PPC_IFGLUE                            EQU     000DH
IMAGE_REL_PPC_IMGLUE                            EQU     000EH
IMAGE_REL_PPC_SECREL16                          EQU     000FH
IMAGE_REL_PPC_REFHI                             EQU     0010H
IMAGE_REL_PPC_REFLO                             EQU     0011H
IMAGE_REL_PPC_PAIR                              EQU     0012H
IMAGE_REL_PPC_SECRELLO                          EQU     0013H
IMAGE_REL_PPC_SECRELHI                          EQU     0014H
IMAGE_REL_PPC_GPREL                             EQU     0015H
IMAGE_REL_PPC_TOKEN                             EQU     0016H

IMAGE_REL_PPC_TYPEMASK                          EQU     00FFH

IMAGE_REL_PPC_NEG                               EQU     0100H
IMAGE_REL_PPC_BRTAKEN                           EQU     0200H
IMAGE_REL_PPC_BRNTAKEN                          EQU     0400H
IMAGE_REL_PPC_TOCDEFN                           EQU     0800H

IMAGE_REL_SH3_ABSOLUTE                          EQU     0000H
IMAGE_REL_SH3_DIRECT16                          EQU     0001H
IMAGE_REL_SH3_DIRECT32                          EQU     0002H
IMAGE_REL_SH3_DIRECT8                           EQU     0003H
IMAGE_REL_SH3_DIRECT8_WORD                      EQU     0004H
IMAGE_REL_SH3_DIRECT8_LONG                      EQU     0005H
IMAGE_REL_SH3_DIRECT4                           EQU     0006H
IMAGE_REL_SH3_DIRECT4_WORD                      EQU     0007H
IMAGE_REL_SH3_DIRECT4_LONG                      EQU     0008H
IMAGE_REL_SH3_PCREL8_WORD                       EQU     0009H
IMAGE_REL_SH3_PCREL8_LONG                       EQU     000AH
IMAGE_REL_SH3_PCREL12_WORD                      EQU     000BH
IMAGE_REL_SH3_STARTOF_SECTION                   EQU     000CH
IMAGE_REL_SH3_SIZEOF_SECTION                    EQU     000DH
IMAGE_REL_SH3_SECTION                           EQU     000EH
IMAGE_REL_SH3_SECREL                            EQU     000FH
IMAGE_REL_SH3_DIRECT32_NB                       EQU     0010H
IMAGE_REL_SH3_GPREL4_LONG                       EQU     0011H
IMAGE_REL_SH3_TOKEN                             EQU     0012H
IMAGE_REL_SHM_PCRELPT                           EQU     0013H
IMAGE_REL_SHM_REFLO                             EQU     0014H
IMAGE_REL_SHM_REFHALF                           EQU     0015H
IMAGE_REL_SHM_RELLO                             EQU     0016H
IMAGE_REL_SHM_RELHALF                           EQU     0017H
IMAGE_REL_SHM_PAIR                              EQU     0018H

IMAGE_REL_SH_NOMODE                             EQU     8000H

IMAGE_REL_ARM_ABSOLUTE                          EQU     0000H
IMAGE_REL_ARM_ADDR32                            EQU     0001H
IMAGE_REL_ARM_ADDR32NB                          EQU     0002H
IMAGE_REL_ARM_BRANCH24                          EQU     0003H
IMAGE_REL_ARM_BRANCH11                          EQU     0004H
IMAGE_REL_ARM_TOKEN                             EQU     0005H
IMAGE_REL_ARM_GPREL12                           EQU     0006H
IMAGE_REL_ARM_GPREL7                            EQU     0007H
IMAGE_REL_ARM_BLX24                             EQU     0008H
IMAGE_REL_ARM_BLX11                             EQU     0009H
IMAGE_REL_ARM_SECTION                           EQU     000EH
IMAGE_REL_ARM_SECREL                            EQU     000FH

IMAGE_REL_AM_ABSOLUTE                           EQU     0000H
IMAGE_REL_AM_ADDR32                             EQU     0001H
IMAGE_REL_AM_ADDR32NB                           EQU     0002H
IMAGE_REL_AM_CALL32                             EQU     0003H
IMAGE_REL_AM_FUNCINFO                           EQU     0004H
IMAGE_REL_AM_REL32_1                            EQU     0005H
IMAGE_REL_AM_REL32_2                            EQU     0006H
IMAGE_REL_AM_SECREL                             EQU     0007H
IMAGE_REL_AM_SECTION                            EQU     0008H
IMAGE_REL_AM_TOKEN                              EQU     0009H

IMAGE_REL_AMD64_ABSOLUTE                        EQU     0000H
IMAGE_REL_AMD64_ADDR64                          EQU     0001H
IMAGE_REL_AMD64_ADDR32                          EQU     0002H
IMAGE_REL_AMD64_ADDR32NB                        EQU     0003H
IMAGE_REL_AMD64_REL32                           EQU     0004H
IMAGE_REL_AMD64_REL32_1                         EQU     0005H
IMAGE_REL_AMD64_REL32_2                         EQU     0006H
IMAGE_REL_AMD64_REL32_3                         EQU     0007H
IMAGE_REL_AMD64_REL32_4                         EQU     0008H
IMAGE_REL_AMD64_REL32_5                         EQU     0009H
IMAGE_REL_AMD64_SECTION                         EQU     000AH
IMAGE_REL_AMD64_SECREL                          EQU     000BH
IMAGE_REL_AMD64_SECREL7                         EQU     000CH
IMAGE_REL_AMD64_TOKEN                           EQU     000DH
IMAGE_REL_AMD64_SREL32                          EQU     000EH
IMAGE_REL_AMD64_PAIR                            EQU     000FH
IMAGE_REL_AMD64_SSPAN32                         EQU     0010H

IMAGE_REL_IA64_ABSOLUTE                         EQU     0000H
IMAGE_REL_IA64_IMM14                            EQU     0001H
IMAGE_REL_IA64_IMM22                            EQU     0002H
IMAGE_REL_IA64_IMM64                            EQU     0003H
IMAGE_REL_IA64_DIR32                            EQU     0004H
IMAGE_REL_IA64_DIR64                            EQU     0005H
IMAGE_REL_IA64_PCREL21B                         EQU     0006H
IMAGE_REL_IA64_PCREL21M                         EQU     0007H
IMAGE_REL_IA64_PCREL21F                         EQU     0008H
IMAGE_REL_IA64_GPREL22                          EQU     0009H
IMAGE_REL_IA64_LTOFF22                          EQU     000AH
IMAGE_REL_IA64_SECTION                          EQU     000BH
IMAGE_REL_IA64_SECREL22                         EQU     000CH
IMAGE_REL_IA64_SECREL64I                        EQU     000DH
IMAGE_REL_IA64_SECREL32                         EQU     000EH
IMAGE_REL_IA64_LTOFF64                          EQU     000FH
IMAGE_REL_IA64_DIR32NB                          EQU     0010H
IMAGE_REL_IA64_SREL22                           EQU     0011H
IMAGE_REL_IA64_UREL22                           EQU     0012H
IMAGE_REL_IA64_SREL32                           EQU     0013H
IMAGE_REL_IA64_UREL32                           EQU     0014H
IMAGE_REL_IA64_ADDEND                           EQU     001FH

IMAGE_REL_CEF_ABSOLUTE                          EQU     0000H
IMAGE_REL_CEF_ADDR32                            EQU     0001H
IMAGE_REL_CEF_ADDR64                            EQU     0002H
IMAGE_REL_CEF_ADDR32NB                          EQU     0003H
IMAGE_REL_CEF_SECTION                           EQU     0004H
IMAGE_REL_CEF_SECREL                            EQU     0005H
IMAGE_REL_CEF_TOKEN                             EQU     0006H

IMAGE_REL_CEE_ABSOLUTE                          EQU     0000H
IMAGE_REL_CEE_ADDR32                            EQU     0001H
IMAGE_REL_CEE_ADDR64                            EQU     0002H
IMAGE_REL_CEE_ADDR32NB                          EQU     0003H
IMAGE_REL_CEE_SECTION                           EQU     0004H
IMAGE_REL_CEE_SECREL                            EQU     0005H
IMAGE_REL_CEE_TOKEN                             EQU     0006H

IMAGE_REL_M32R_ABSOLUTE                         EQU     0000H
IMAGE_REL_M32R_ADDR32                           EQU     0001H
IMAGE_REL_M32R_ADDR32NB                         EQU     0002H
IMAGE_REL_M32R_ADDR24                           EQU     0003H
IMAGE_REL_M32R_GPREL16                          EQU     0004H
IMAGE_REL_M32R_PCREL24                          EQU     0005H
IMAGE_REL_M32R_PCREL16                          EQU     0006H
IMAGE_REL_M32R_PCREL8                           EQU     0007H
IMAGE_REL_M32R_REFHALF                          EQU     0008H
IMAGE_REL_M32R_REFHI                            EQU     0009H
IMAGE_REL_M32R_REFLO                            EQU     000AH
IMAGE_REL_M32R_PAIR                             EQU     000BH
IMAGE_REL_M32R_SECTION                          EQU     000CH
IMAGE_REL_M32R_SECREL32                         EQU     000DH
IMAGE_REL_M32R_TOKEN                            EQU     000EH

IMAGE_REL_EBC_ABSOLUTE                          EQU     0000H
IMAGE_REL_EBC_ADDR32NB                          EQU     0001H
IMAGE_REL_EBC_REL32                             EQU     0002H
IMAGE_REL_EBC_SECTION                           EQU     0003H
IMAGE_REL_EBC_SECREL                            EQU     0004H

IMAGE_SIZEOF_LINENUMBER                         EQU     6
IMAGE_SIZEOF_BASE_RELOCATION                    EQU     8

IMAGE_REL_BASED_ABSOLUTE                        EQU     0
IMAGE_REL_BASED_HIGH                            EQU     1
IMAGE_REL_BASED_LOW                             EQU     2
IMAGE_REL_BASED_HIGHLOW                         EQU     3
IMAGE_REL_BASED_HIGHADJ                         EQU     4
IMAGE_REL_BASED_MIPS_JMPADDR                    EQU     5
IMAGE_REL_BASED_SECTION                         EQU     6
IMAGE_REL_BASED_REL32                           EQU     7

IMAGE_REL_BASED_MIPS_JMPADDR16                  EQU     9
IMAGE_REL_BASED_IA64_IMM64                      EQU     9
IMAGE_REL_BASED_DIR64                           EQU     10
IMAGE_REL_BASED_HIGH3ADJ                        EQU     11

IMAGE_ARCHIVE_START_SIZE                        EQU     8
IMAGE_ARCHIVE_START                             EQU     A("!<arch>", 10)
IMAGE_ARCHIVE_END                               EQU     A("`", 10)
IMAGE_ARCHIVE_PAD                               EQU     10
IMAGE_ARCHIVE_LINKER_MEMBER                     EQU     </               >
IMAGE_ARCHIVE_LONGNAMES_MEMBER                  EQU     <//              >

IMAGE_ORDINAL_FLAG64                            EQU     8000000000000000H
IMAGE_ORDINAL_FLAG32                            EQU     80000000H

IMAGE_RESOURCE_NAME_IS_STRING                   EQU     80000000H
IMAGE_RESOURCE_DATA_IS_DIRECTORY                EQU     80000000H

IMAGE_DEBUG_TYPE_UNKNOWN                        EQU     0
IMAGE_DEBUG_TYPE_COFF                           EQU     1
IMAGE_DEBUG_TYPE_CODEVIEW                       EQU     2
IMAGE_DEBUG_TYPE_FPO                            EQU     3
IMAGE_DEBUG_TYPE_MISC                           EQU     4
IMAGE_DEBUG_TYPE_EXCEPTION                      EQU     5
IMAGE_DEBUG_TYPE_FIXUP                          EQU     6
IMAGE_DEBUG_TYPE_OMAP_TO_SRC                    EQU     7
IMAGE_DEBUG_TYPE_OMAP_FROM_SRC                  EQU     8
IMAGE_DEBUG_TYPE_BORLAND                        EQU     9
IMAGE_DEBUG_TYPE_RESERVED10                     EQU     10
IMAGE_DEBUG_TYPE_CLSID                          EQU     11

FRAME_FPO                                       EQU     0
FRAME_TRAP                                      EQU     1
FRAME_TSS                                       EQU     2
FRAME_NONFPO                                    EQU     3

SIZEOF_RFPO_DATA                                EQU     16

IMAGE_DEBUG_MISC_EXENAME                        EQU     1

IMAGE_SEPARATE_DEBUG_SIGNATURE                  EQU     4944H
IMAGE_SEPARATE_DEBUG_FLAGS_MASK                 EQU     8000H
IMAGE_SEPARATE_DEBUG_MISMATCH                   EQU     8000H

IMPORT_OBJECT_HDR_SIG2                          EQU     0FFFFH

N_BTMASK                                        EQU     000FH
N_TMASK                                         EQU     0030H
N_TMASK1                                        EQU     00C0H
N_TMASK2                                        EQU     00F0H
N_BTSHFT                                        EQU     4
N_TSHIFT                                        EQU     2

FAST_FAIL_LEGACY_GS_VIOLATION                   EQU     0
FAST_FAIL_VTGUARD_CHECK_FAILURE                 EQU     1
FAST_FAIL_STACK_COOKIE_CHECK_FAILURE            EQU     2
FAST_FAIL_CORRUPT_LIST_ENTRY                    EQU     3
FAST_FAIL_INCORRECT_STACK                       EQU     4
FAST_FAIL_INVALID_ARG                           EQU     5
FAST_FAIL_GS_COOKIE_INIT                        EQU     6
FAST_FAIL_FATAL_APP_EXIT                        EQU     7
FAST_FAIL_RANGE_CHECK_FAILURE                   EQU     8
FAST_FAIL_UNSAFE_REGISTRY_ACCESS                EQU     9
FAST_FAIL_GUARD_ICALL_CHECK_FAILURE             EQU     10
FAST_FAIL_GUARD_WRITE_CHECK_FAILURE             EQU     11
FAST_FAIL_INVALID_FIBER_SWITCH                  EQU     12
FAST_FAIL_INVALID_SET_OF_CONTEXT                EQU     13
FAST_FAIL_INVALID_REFERENCE_COUNT               EQU     14
FAST_FAIL_INVALID_JUMP_BUFFER                   EQU     18
FAST_FAIL_MRDATA_MODIFIED                       EQU     19
FAST_FAIL_CERTIFICATION_FAILURE                 EQU     20
FAST_FAIL_INVALID_EXCEPTION_CHAIN               EQU     21
FAST_FAIL_CRYPTO_LIBRARY                        EQU     22
FAST_FAIL_INVALID_CALL_IN_DLL_CALLOUT           EQU     23
FAST_FAIL_INVALID_IMAGE_BASE                    EQU     24
FAST_FAIL_DLOAD_PROTECTION_FAILURE              EQU     25
FAST_FAIL_UNSAFE_EXTENSION_CALL                 EQU     26
FAST_FAIL_INVALID_FAST_FAIL_CODE                EQU     0FFFFFFFFH

HEAP_NO_SERIALIZE                               EQU     00000001H
HEAP_GROWABLE                                   EQU     00000002H
HEAP_GENERATE_EXCEPTIONS                        EQU     00000004H
HEAP_ZERO_MEMORY                                EQU     00000008H
HEAP_REALLOC_IN_PLACE_ONLY                      EQU     00000010H
HEAP_TAIL_CHECKING_ENABLED                      EQU     00000020H
HEAP_FREE_CHECKING_ENABLED                      EQU     00000040H
HEAP_DISABLE_COALESCE_ON_FREE                   EQU     00000080H
HEAP_CREATE_ALIGN_16                            EQU     00010000H
HEAP_CREATE_ENABLE_TRACING                      EQU     00020000H
HEAP_MAXIMUM_TAG                                EQU     0FFFH
HEAP_PSEUDO_TAG_FLAG                            EQU     8000H
HEAP_TAG_SHIFT                                  EQU     18

IS_TEXT_UNICODE_ASCII16                         EQU     0001H
IS_TEXT_UNICODE_REVERSE_ASCII16                 EQU     0010H
IS_TEXT_UNICODE_STATISTICS                      EQU     0002H
IS_TEXT_UNICODE_REVERSE_STATISTICS              EQU     0020H
IS_TEXT_UNICODE_CONTROLS                        EQU     0004H
IS_TEXT_UNICODE_REVERSE_CONTROLS                EQU     0040H
IS_TEXT_UNICODE_SIGNATURE                       EQU     0008H
IS_TEXT_UNICODE_REVERSE_SIGNATURE               EQU     0080H
IS_TEXT_UNICODE_ILLEGAL_CHARS                   EQU     0100H
IS_TEXT_UNICODE_ODD_LENGTH                      EQU     0200H
IS_TEXT_UNICODE_DBCS_LEADBYTE                   EQU     0400H
IS_TEXT_UNICODE_NULL_BYTES                      EQU     1000H
IS_TEXT_UNICODE_UNICODE_MASK                    EQU     000FH
IS_TEXT_UNICODE_REVERSE_MASK                    EQU     00F0H
IS_TEXT_UNICODE_NOT_UNICODE_MASK                EQU     0F00H
IS_TEXT_UNICODE_NOT_ASCII_MASK                  EQU     0F000H

COMPRESSION_FORMAT_NONE                         EQU     0000H
COMPRESSION_FORMAT_DEFAULT                      EQU     0001H
COMPRESSION_FORMAT_LZNT1                        EQU     0002H
COMPRESSION_FORMAT_XPRESS                       EQU     0003H
COMPRESSION_FORMAT_XPRESS_HUFF                  EQU     0004H
COMPRESSION_ENGINE_STANDARD                     EQU     0000H
COMPRESSION_ENGINE_MAXIMUM                      EQU     0100H
COMPRESSION_ENGINE_HIBER                        EQU     0200H

MESSAGE_RESOURCE_UNICODE                        EQU     0001H

VER_EQUAL                                       EQU     1
VER_GREATER                                     EQU     2
VER_GREATER_EQUAL                               EQU     3
VER_LESS                                        EQU     4
VER_LESS_EQUAL                                  EQU     5
VER_AND                                         EQU     6
VER_OR                                          EQU     7

VER_CONDITION_MASK                              EQU     7
VER_NUM_BITS_PER_CONDITION_MASK                 EQU     3

VER_MINORVERSION                                EQU     0000001H
VER_MAJORVERSION                                EQU     0000002H
VER_BUILDNUMBER                                 EQU     0000004H
VER_PLATFORMID                                  EQU     0000008H
VER_SERVICEPACKMINOR                            EQU     0000010H
VER_SERVICEPACKMAJOR                            EQU     0000020H
VER_SUITENAME                                   EQU     0000040H
VER_PRODUCT_TYPE                                EQU     0000080H

VER_NT_WORKSTATION                              EQU     0000001H
VER_NT_DOMAIN_CONTROLLER                        EQU     0000002H
VER_NT_SERVER                                   EQU     0000003H

VER_PLATFORM_WIN32s                             EQU     0
VER_PLATFORM_WIN32_WINDOWS                      EQU     1
VER_PLATFORM_WIN32_NT                           EQU     2
VER_PLATFORM_WIN32_CE                           EQU     3

RTL_CRITSECT_TYPE                               EQU     0
RTL_RESOURCE_TYPE                               EQU     1

SEF_DACL_AUTO_INHERIT                           EQU     01H
SEF_SACL_AUTO_INHERIT                           EQU     02H
SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT               EQU     04H
SEF_AVOID_PRIVILEGE_CHECK                       EQU     08H
SEF_AVOID_OWNER_CHECK                           EQU     10H
SEF_DEFAULT_OWNER_FROM_PARENT                   EQU     20H
SEF_DEFAULT_GROUP_FROM_PARENT                   EQU     40H
SEF_MACL_NO_WRITE_UP                            EQU     100H
SEF_MACL_NO_READ_UP                             EQU     200H
SEF_MACL_NO_EXECUTE_UP                          EQU     0400H
SEF_AI_USE_EXTRA_PARAMS                         EQU     0800H
SEF_AVOID_OWNER_RESTRICTION                     EQU     01000H
SEF_MACL_VALID_FLAGS                            EQU     (SEF_MACL_NO_WRITE_UP OR SEF_MACL_NO_READ_UP OR SEF_MACL_NO_EXECUTE_UP)

WT_EXECUTEDEFAULT                               EQU     00000000H
WT_EXECUTEINIOTHREAD                            EQU     00000001H
WT_EXECUTEINUITHREAD                            EQU     00000002H
WT_EXECUTEINWAITTHREAD                          EQU     00000004H
WT_EXECUTEONLYONCE                              EQU     00000008H
WT_EXECUTEINTIMERTHREAD                         EQU     00000020H
WT_EXECUTELONGFUNCTION                          EQU     00000010H
WT_EXECUTEINPERSISTENTIOTHREAD                  EQU     00000040H
WT_EXECUTEINPERSISTENTTHREAD                    EQU     00000080H
WT_TRANSFER_IMPERSONATION                       EQU     00000100H

WT_EXECUTEINLONGTHREAD                          EQU     00000010H
WT_EXECUTEDELETEWAIT                            EQU     00000008H

DLL_PROCESS_ATTACH                              EQU     1
DLL_THREAD_ATTACH                               EQU     2
DLL_THREAD_DETACH                               EQU     3
DLL_PROCESS_DETACH                              EQU     0

EVENTLOG_SEQUENTIAL_READ                        EQU     0001H
EVENTLOG_SEEK_READ                              EQU     0002H
EVENTLOG_FORWARDS_READ                          EQU     0004H
EVENTLOG_BACKWARDS_READ                         EQU     0008H

EVENTLOG_SUCCESS                                EQU     0000H
EVENTLOG_ERROR_TYPE                             EQU     0001H
EVENTLOG_WARNING_TYPE                           EQU     0002H
EVENTLOG_INFORMATION_TYPE                       EQU     0004H
EVENTLOG_AUDIT_SUCCESS                          EQU     0008H
EVENTLOG_AUDIT_FAILURE                          EQU     0010H

EVENTLOG_START_PAIRED_EVENT                     EQU     0001H
EVENTLOG_END_PAIRED_EVENT                       EQU     0002H
EVENTLOG_END_ALL_PAIRED_EVENTS                  EQU     0004H
EVENTLOG_PAIRED_EVENT_ACTIVE                    EQU     0008H
EVENTLOG_PAIRED_EVENT_INACTIVE                  EQU     0010H

MAXLOGICALLOGNAMESIZE                           EQU     256

KEY_QUERY_VALUE                                 EQU     0001H
KEY_SET_VALUE                                   EQU     0002H
KEY_CREATE_SUB_KEY                              EQU     0004H
KEY_ENUMERATE_SUB_KEYS                          EQU     0008H
KEY_NOTIFY                                      EQU     0010H
KEY_CREATE_LINK                                 EQU     0020H
KEY_WOW64_32KEY                                 EQU     0200H
KEY_WOW64_64KEY                                 EQU     0100H
KEY_WOW64_RES                                   EQU     0300H

KEY_READ                                        EQU     ((STANDARD_RIGHTS_READ OR KEY_QUERY_VALUE OR KEY_ENUMERATE_SUB_KEYS OR KEY_NOTIFY) AND (NOT SYNCHRONIZE))
KEY_WRITE                                       EQU     ((STANDARD_RIGHTS_WRITE OR KEY_SET_VALUE OR KEY_CREATE_SUB_KEY) AND (NOT SYNCHRONIZE))
KEY_ALL_ACCESS                                  EQU     ((STANDARD_RIGHTS_ALL OR KEY_QUERY_VALUE OR KEY_SET_VALUE OR KEY_CREATE_SUB_KEY OR KEY_ENUMERATE_SUB_KEYS OR KEY_NOTIFY OR KEY_CREATE_LINK) AND (NOT SYNCHRONIZE))
KEY_EXECUTE                                     EQU     KEY_READ

IFNDEF ADVAPI32_INC
    REG_OPTION_NON_VOLATILE                    EQU     00000000H
    REG_OPTION_VOLATILE                        EQU     00000001H
    REG_OPTION_CREATE_LINK                     EQU     00000002H
    REG_OPTION_BACKUP_RESTORE                  EQU     00000004H
    REG_OPTION_OPEN_LINK                       EQU     00000008H
    REG_CREATED_NEW_KEY                        EQU     00000001H
    REG_OPENED_EXISTING_KEY                    EQU     00000002H

    REG_NONE                                   EQU     0
    REG_SZ                                     EQU     1
    REG_EXPAND_SZ                              EQU     2
    REG_BINARY                                 EQU     3
    REG_DWORD                                  EQU     4
    REG_DWORD_LITTLE_ENDIAN                    EQU     4
    REG_DWORD_BIG_ENDIAN                       EQU     5
    REG_LINK                                   EQU     6
    REG_MULTI_SZ                               EQU     7
    REG_RESOURCE_LIST                          EQU     8
    REG_FULL_RESOURCE_DESCRIPTOR               EQU     9
    REG_RESOURCE_REQUIREMENTS_LIST             EQU     10
    REG_QWORD                                  EQU     11
    REG_QWORD_LITTLE_ENDIAN                    EQU     11
        
    REG_NOTIFY_CHANGE_NAME                     EQU     00000001H
    REG_NOTIFY_CHANGE_ATTRIBUTES               EQU     00000002H
    REG_NOTIFY_CHANGE_LAST_SET                 EQU     00000004H
    REG_NOTIFY_CHANGE_SECURITY                 EQU     00000008H

    REG_NOTIFY_THREAD_AGNOSTIC                 EQU     10000000H
ENDIF

REG_OPTION_RESERVED                             EQU     00000000H
REG_LEGAL_OPTION                                EQU     (REG_OPTION_RESERVED OR REG_OPTION_NON_VOLATILE OR REG_OPTION_VOLATILE OR REG_OPTION_CREATE_LINK OR REG_OPTION_BACKUP_RESTORE OR REG_OPTION_OPEN_LINK)
REG_LEGAL_CHANGE_FILTER                         EQU     (REG_NOTIFY_CHANGE_NAME OR REG_NOTIFY_CHANGE_ATTRIBUTES OR REG_NOTIFY_CHANGE_LAST_SET OR REG_NOTIFY_CHANGE_SECURITY)

REG_STANDARD_FORMAT                             EQU     1
REG_LATEST_FORMAT                               EQU     2
REG_NO_COMPRESSION                              EQU     4

REG_WHOLE_HIVE_VOLATILE                         EQU     00000001H
REG_REFRESH_HIVE                                EQU     00000002H
REG_NO_LAZY_FLUSH                               EQU     00000004H
REG_FORCE_RESTORE                               EQU     00000008H
REG_APP_HIVE                                    EQU     00000010H
REG_PROCESS_PRIVATE                             EQU     00000020H
REG_START_JOURNAL                               EQU     00000040H
REG_HIVE_EXACT_FILE_GROWTH                      EQU     00000080H
REG_HIVE_NO_RM                                  EQU     00000100H
REG_HIVE_SINGLE_LOG                             EQU     00000200H
REG_BOOT_HIVE                                   EQU     00000400H
REG_LOAD_HIVE_OPEN_HANDLE                       EQU     00000800H
REG_FLUSH_HIVE_FILE_GROWTH                      EQU     00001000H

REG_FORCE_UNLOAD                                EQU     1

SERVICE_KERNEL_DRIVER                           EQU     00000001H
SERVICE_FILE_SYSTEM_DRIVER                      EQU     00000002H
SERVICE_ADAPTER                                 EQU     00000004H
SERVICE_RECOGNIZER_DRIVER                       EQU     00000008H
SERVICE_DRIVER                                  EQU     (SERVICE_KERNEL_DRIVER OR SERVICE_FILE_SYSTEM_DRIVER OR SERVICE_RECOGNIZER_DRIVER)

SERVICE_WIN32_OWN_PROCESS                       EQU     00000010H
SERVICE_WIN32_SHARE_PROCESS                     EQU     00000020H
SERVICE_WIN32                                   EQU     (SERVICE_WIN32_OWN_PROCESS OR SERVICE_WIN32_SHARE_PROCESS)

SERVICE_INTERACTIVE_PROCESS                     EQU     00000100H

SERVICE_TYPE_ALL                                EQU     (SERVICE_WIN32 OR SERVICE_ADAPTER OR SERVICE_DRIVER OR SERVICE_INTERACTIVE_PROCESS)

SERVICE_BOOT_START                              EQU     00000000H
SERVICE_SYSTEM_START                            EQU     00000001H
SERVICE_AUTO_START                              EQU     00000002H
SERVICE_DEMAND_START                            EQU     00000003H
SERVICE_DISABLED                                EQU     00000004H

SERVICE_ERROR_IGNORE                            EQU     00000000H
SERVICE_ERROR_NORMAL                            EQU     00000001H
SERVICE_ERROR_SEVERE                            EQU     00000002H
SERVICE_ERROR_CRITICAL                          EQU     00000003H

CM_SERVICE_NETWORK_BOOT_LOAD                    EQU     00000001H
CM_SERVICE_VIRTUAL_DISK_BOOT_LOAD               EQU     00000002H
CM_SERVICE_USB_DISK_BOOT_LOAD                   EQU     00000004H
CM_SERVICE_SD_DISK_BOOT_LOAD                    EQU     00000008H
CM_SERVICE_USB3_DISK_BOOT_LOAD                  EQU     00000010H
CM_SERVICE_MEASURED_BOOT_LOAD                   EQU     00000020H
CM_SERVICE_VERIFIER_BOOT_LOAD                   EQU     00000040H
CM_SERVICE_WINPE_BOOT_LOAD                      EQU     00000080H

CM_SERVICE_VALID_PROMOTION_MASKA                EQU     (CM_SERVICE_NETWORK_BOOT_LOAD OR CM_SERVICE_VIRTUAL_DISK_BOOT_LOAD OR \
                                                        CM_SERVICE_USB_DISK_BOOT_LOAD OR CM_SERVICE_SD_DISK_BOOT_LOAD OR \
                                                        CM_SERVICE_USB3_DISK_BOOT_LOAD OR CM_SERVICE_MEASURED_BOOT_LOAD)
CM_SERVICE_VALID_PROMOTION_MASKB                EQU     (CM_SERVICE_VERIFIER_BOOT_LOAD OR CM_SERVICE_WINPE_BOOT_LOAD)
CM_SERVICE_VALID_PROMOTION_MASK                 EQU     (CM_SERVICE_VALID_PROMOTION_MASKA OR CM_SERVICE_VALID_PROMOTION_MASKB)

TAPE_ERASE_SHORT                                EQU     0
TAPE_ERASE_LONG                                 EQU     1

TAPE_LOAD                                       EQU     0
TAPE_UNLOAD                                     EQU     1
TAPE_TENSION                                    EQU     2
TAPE_LOCK                                       EQU     3
TAPE_UNLOCK                                     EQU     4
TAPE_FORMAT                                     EQU     5

TAPE_SETMARKS                                   EQU     0
TAPE_FILEMARKS                                  EQU     1
TAPE_SHORT_FILEMARKS                            EQU     2
TAPE_LONG_FILEMARKS                             EQU     3

TAPE_ABSOLUTE_POSITION                          EQU     0
TAPE_LOGICAL_POSITION                           EQU     1
TAPE_PSEUDO_LOGICAL_POSITION                    EQU     2

TAPE_REWIND                                     EQU     0
TAPE_ABSOLUTE_BLOCK                             EQU     1
TAPE_LOGICAL_BLOCK                              EQU     2
TAPE_PSEUDO_LOGICAL_BLOCK                       EQU     3
TAPE_SPACE_END_OF_DATA                          EQU     4
TAPE_SPACE_RELATIVE_BLOCKS                      EQU     5
TAPE_SPACE_FILEMARKS                            EQU     6
TAPE_SPACE_SEQUENTIAL_FMKS                      EQU     7
TAPE_SPACE_SETMARKS                             EQU     8
TAPE_SPACE_SEQUENTIAL_SMKS                      EQU     9

TAPE_DRIVE_FIXED                                EQU     00000001H
TAPE_DRIVE_SELECT                               EQU     00000002H
TAPE_DRIVE_INITIATOR                            EQU     00000004H
TAPE_DRIVE_ERASE_SHORT                          EQU     00000010H
TAPE_DRIVE_ERASE_LONG                           EQU     00000020H
TAPE_DRIVE_ERASE_BOP_ONLY                       EQU     00000040H
TAPE_DRIVE_ERASE_IMMEDIATE                      EQU     00000080H
TAPE_DRIVE_TAPE_CAPACITY                        EQU     00000100H
TAPE_DRIVE_TAPE_REMAINING                       EQU     00000200H
TAPE_DRIVE_FIXED_BLOCK                          EQU     00000400H
TAPE_DRIVE_VARIABLE_BLOCK                       EQU     00000800H
TAPE_DRIVE_WRITE_PROTECT                        EQU     00001000H
TAPE_DRIVE_EOT_WZ_SIZE                          EQU     00002000H
TAPE_DRIVE_ECC                                  EQU     00010000H
TAPE_DRIVE_COMPRESSION                          EQU     00020000H
TAPE_DRIVE_PADDING                              EQU     00040000H
TAPE_DRIVE_REPORT_SMKS                          EQU     00080000H
TAPE_DRIVE_GET_ABSOLUTE_BLK                     EQU     00100000H
TAPE_DRIVE_GET_LOGICAL_BLK                      EQU     00200000H
TAPE_DRIVE_SET_EOT_WZ_SIZE                      EQU     00400000H
TAPE_DRIVE_EJECT_MEDIA                          EQU     01000000H
TAPE_DRIVE_CLEAN_REQUESTS                       EQU     02000000H
TAPE_DRIVE_SET_CMP_BOP_ONLY                     EQU     04000000H
TAPE_DRIVE_RESERVED_BIT                         EQU     80000000H
TAPE_DRIVE_LOAD_UNLOAD                          EQU     80000001H
TAPE_DRIVE_TENSION                              EQU     80000002H
TAPE_DRIVE_LOCK_UNLOCK                          EQU     80000004H
TAPE_DRIVE_REWIND_IMMEDIATE                     EQU     80000008H
TAPE_DRIVE_SET_BLOCK_SIZE                       EQU     80000010H
TAPE_DRIVE_LOAD_UNLD_IMMED                      EQU     80000020H
TAPE_DRIVE_TENSION_IMMED                        EQU     80000040H
TAPE_DRIVE_LOCK_UNLK_IMMED                      EQU     80000080H
TAPE_DRIVE_SET_ECC                              EQU     80000100H
TAPE_DRIVE_SET_COMPRESSION                      EQU     80000200H
TAPE_DRIVE_SET_PADDING                          EQU     80000400H
TAPE_DRIVE_SET_REPORT_SMKS                      EQU     80000800H
TAPE_DRIVE_ABSOLUTE_BLK                         EQU     80001000H
TAPE_DRIVE_ABS_BLK_IMMED                        EQU     80002000H
TAPE_DRIVE_LOGICAL_BLK                          EQU     80004000H
TAPE_DRIVE_LOG_BLK_IMMED                        EQU     80008000H
TAPE_DRIVE_END_OF_DATA                          EQU     80010000H
TAPE_DRIVE_RELATIVE_BLKS                        EQU     80020000H
TAPE_DRIVE_FILEMARKS                            EQU     80040000H
TAPE_DRIVE_SEQUENTIAL_FMKS                      EQU     80080000H
TAPE_DRIVE_SETMARKS                             EQU     80100000H
TAPE_DRIVE_SEQUENTIAL_SMKS                      EQU     80200000H
TAPE_DRIVE_REVERSE_POSITION                     EQU     80400000H
TAPE_DRIVE_SPACE_IMMEDIATE                      EQU     80800000H
TAPE_DRIVE_WRITE_SETMARKS                       EQU     81000000H
TAPE_DRIVE_WRITE_FILEMARKS                      EQU     82000000H
TAPE_DRIVE_WRITE_SHORT_FMKS                     EQU     84000000H
TAPE_DRIVE_WRITE_LONG_FMKS                      EQU     88000000H
TAPE_DRIVE_WRITE_MARK_IMMED                     EQU     90000000H
TAPE_DRIVE_FORMAT                               EQU     0A0000000H
TAPE_DRIVE_FORMAT_IMMEDIATE                     EQU     0C0000000H
TAPE_DRIVE_HIGH_FEATURES                        EQU     80000000H

TAPE_FIXED_PARTITIONS                           EQU     0
TAPE_SELECT_PARTITIONS                          EQU     1
TAPE_INITIATOR_PARTITIONS                       EQU     2

TAPE_QUERY_DRIVE_PARAMETERS                     EQU     0
TAPE_QUERY_MEDIA_CAPACITY                       EQU     1
TAPE_CHECK_FOR_DRIVE_PROBLEM                    EQU     2
TAPE_QUERY_IO_ERROR_DATA                        EQU     3
TAPE_QUERY_DEVICE_ERROR_DATA                    EQU     4

SIZE_OF_80387_REGISTERS                         EQU     80

CONTEXT_i386                                    EQU     00010000H
CONTEXT_i486                                    EQU     00010000H
CONTEXT_AMD64                                   EQU     100000H
CONTEXT_IA64                                    EQU     00080000H

MAXIMUM_SUPPORTED_EXTENSION                     EQU     512

LEGACY_SAVE_AREA_LENGTH                         EQU     SIZEOF XMM_SAVE_AREA32

EXCEPTION_READ_FAULT                            EQU     0
EXCEPTION_WRITE_FAULT                           EQU     1
EXCEPTION_EXECUTE_FAULT                         EQU     8

UNWIND_HISTORY_TABLE_SIZE                       EQU     12

SidTypeUser                                     EQU     1
SidTypeGroup                                    EQU     2
SidTypeDomain                                   EQU     3
SidTypeAlias                                    EQU     4
SidTypeWellKnownGroup                           EQU     5
SidTypeDeletedAccount                           EQU     6
SidTypeInvalid                                  EQU     7
SidTypeUnknown                                  EQU     8
SidTypeComputer                                 EQU     9

AclRevisionInformation                          EQU     1
AclSizeInformation                              EQU     2

AuditEventObjectAccess                          EQU     0
AuditEventDirectoryServiceAccess                EQU     1

SecurityAnonymous                               EQU     0
SecurityIdentification                          EQU     1
SecurityImpersonation                           EQU     2
SecurityDelegation                              EQU     3

SECURITY_MAX_IMPERSONATION_LEVEL                EQU     SecurityDelegation
SECURITY_MIN_IMPERSONATION_LEVEL                EQU     SecurityAnonymous
DEFAULT_IMPERSONATION_LEVEL                     EQU     SecurityImpersonation

TokenPrimary                                    EQU     1
TokenImpersonation                              EQU     2

TokenElevationTypeDefault                       EQU     1
TokenElevationTypeFull                          EQU     2
TokenElevationTypeLimited                       EQU     3

TokenUser                                       EQU     1
TokenGroups                                     EQU     2
TokenPrivileges                                 EQU     3
TokenOwner                                      EQU     4
TokenPrimaryGroup                               EQU     5
TokenDefaultDacl                                EQU     6
TokenSource                                     EQU     7
TokenType                                       EQU     8
TokenImpersonationLevel                         EQU     9
TokenStatistics                                 EQU     10
TokenRestrictedSids                             EQU     11
TokenSessionId                                  EQU     12
TokenGroupsAndPrivileges                        EQU     13
TokenSessionReference                           EQU     14
TokenSandBoxInert                               EQU     15
TokenAuditPolicy                                EQU     16
TokenOrigin                                     EQU     17
TokenElevationType                              EQU     18
TokenLinkedToken                                EQU     19
TokenElevation                                  EQU     20
TokenHasRestrictions                            EQU     21
TokenAccessInformation                          EQU     22
TokenVirtualizationAllowed                      EQU     23
TokenVirtualizationEnabled                      EQU     24
TokenIntegrityLevel                             EQU     25
TokenUIAccess                                   EQU     26
TokenMandatoryPolicy                            EQU     27
TokenLogonSid                                   EQU     28
MaxTokenInfoClass                               EQU     29

MandatoryLevelUntrusted                         EQU     0
MandatoryLevelLow                               EQU     1
MandatoryLevelMedium                            EQU     2
MandatoryLevelHigh                              EQU     3
MandatoryLevelSystem                            EQU     4
MandatoryLevelSecureProcess                     EQU     5
MandatoryLevelCount                             EQU     6

JobObjectBasicAccountingInformation             EQU     1
JobObjectBasicLimitInformation                  EQU     2
JobObjectBasicProcessIdList                     EQU     3
JobObjectBasicUIRestrictions                    EQU     4
JobObjectSecurityLimitInformation               EQU     5
JobObjectEndOfJobTimeInformation                EQU     6
JobObjectAssociateCompletionPortInformation     EQU     7
JobObjectBasicAndIoAccountingInformation        EQU     8
JobObjectExtendedLimitInformation               EQU     9
JobObjectJobSetInformation                      EQU     10
MaxJobObjectInfoClass                           EQU     11

RelationProcessorCore                           EQU     0
RelationNumaNode                                EQU     1
RelationCache                                   EQU     2
RelationProcessorPackage                        EQU     3

CacheUnified                                    EQU     0
CacheInstruction                                EQU     1
CacheData                                       EQU     2
CacheTrace                                      EQU     3

LTP_PC_SMT                                      EQU     01H
CACHE_FULLY_ASSOCIATIVE                         EQU     0FFH

FLUSH_FLAGS_FILE_DATA_ONLY                      EQU     00000001H

LT_DONT_CARE                                    EQU     0
LT_LOWEST_LATENCY                               EQU     1

DIAGNOSTIC_REASON_VERSION                       EQU     0

DIAGNOSTIC_REASON_SIMPLE_STRING                 EQU     00000001H
DIAGNOSTIC_REASON_DETAILED_STRING               EQU     00000002H
DIAGNOSTIC_REASON_NOT_SPECIFIED                 EQU     80000000H
DIAGNOSTIC_REASON_INVALID_FLAGS                 EQU     (NOT 80000003H)

POWER_REQUEST_CONTEXT_VERSION                   EQU     0

POWER_REQUEST_CONTEXT_SIMPLE_STRING             EQU     00000001H
POWER_REQUEST_CONTEXT_DETAILED_STRING           EQU     00000002H

PowerRequestDisplayRequired                     EQU     0
PowerRequestSystemRequired                      EQU     1
PowerRequestAwayModeRequired                    EQU     2
PowerRequestMaximum                             EQU     3

PowerSystemUnspecified                          EQU     0
PowerSystemWorking                              EQU     1
PowerSystemSleeping1                            EQU     2
PowerSystemSleeping2                            EQU     3
PowerSystemSleeping3                            EQU     4
PowerSystemHibernate                            EQU     5
PowerSystemShutdown                             EQU     6
PowerSystemMaximum                              EQU     7

PowerActionNone                                 EQU     0
PowerActionReserved                             EQU     1
PowerActionSleep                                EQU     2
PowerActionHibernate                            EQU     3
PowerActionShutdown                             EQU     4
PowerActionShutdownReset                        EQU     5
PowerActionShutdownOff                          EQU     6
PowerActionWarmEject                            EQU     7

PowerDeviceUnspecified                          EQU     0
PowerDeviceD0                                   EQU     1
PowerDeviceD1                                   EQU     2
PowerDeviceD2                                   EQU     3
PowerDeviceD3                                   EQU     4
PowerDeviceMaximum                              EQU     5

PDCAP_D0_SUPPORTED                              EQU     00000001H
PDCAP_D1_SUPPORTED                              EQU     00000002H
PDCAP_D2_SUPPORTED                              EQU     00000004H
PDCAP_D3_SUPPORTED                              EQU     00000008H
PDCAP_WAKE_FROM_D0_SUPPORTED                    EQU     00000010H
PDCAP_WAKE_FROM_D1_SUPPORTED                    EQU     00000020H
PDCAP_WAKE_FROM_D2_SUPPORTED                    EQU     00000040H
PDCAP_WAKE_FROM_D3_SUPPORTED                    EQU     00000080H
PDCAP_WARM_EJECT_SUPPORTED                      EQU     00000100H

SystemPowerPolicyAc                             EQU     0
SystemPowerPolicyDc                             EQU     1
VerifySystemPolicyAc                            EQU     2
VerifySystemPolicyDc                            EQU     3
SystemPowerCapabilities                         EQU     4
SystemBatteryState                              EQU     5
SystemPowerStateHandler                         EQU     6
ProcessorStateHandler                           EQU     7
SystemPowerPolicyCurrent                        EQU     8
AdministratorPowerPolicy                        EQU     9
SystemReserveHiberFile                          EQU     10
ProcessorInformation                            EQU     11
SystemPowerInformation                          EQU     12
ProcessorStateHandler2                          EQU     13
LastWakeTime                                    EQU     14
LastSleepTime                                   EQU     15
SystemExecutionState                            EQU     16
SystemPowerStateNotifyHandler                   EQU     17
ProcessorPowerPolicyAc                          EQU     18
ProcessorPowerPolicyDc                          EQU     19
VerifyProcessorPowerPolicyAc                    EQU     20
VerifyProcessorPowerPolicyDc                    EQU     21
ProcessorPowerPolicyCurrent                     EQU     22
SystemPowerStateLogging                         EQU     23
SystemPowerLoggingEntry                         EQU     24
SetPowerSettingValue                            EQU     25
NotifyUserPowerSetting                          EQU     26
PowerInformationLevelUnused0                    EQU     27
PowerInformationLevelUnused1                    EQU     28
SystemVideoState                                EQU     29
TraceApplicationPowerMessage                    EQU     30
TraceApplicationPowerMessageEnd                 EQU     31
ProcessorPerfStates                             EQU     32
ProcessorIdleStates                             EQU     33
ProcessorCap                                    EQU     34
SystemWakeSource                                EQU     35
SystemHiberFileInformation                      EQU     36
TraceServicePowerMessage                        EQU     37
ProcessorLoad                                   EQU     38
PowerShutdownNotification                       EQU     39
MonitorCapabilities                             EQU     40
SessionPowerInit                                EQU     41
SessionDisplayState                             EQU     42
PowerRequestCreate                              EQU     43
PowerRequestAction                              EQU     44
GetPowerRequestList                             EQU     45
ProcessorInformationEx                          EQU     46
NotifyUserModeLegacyPowerEvent                  EQU     47
GroupPark                                       EQU     48
ProcessorIdleDomains                            EQU     49
WakeTimerList                                   EQU     50
SystemHiberFileSize                             EQU     51
PowerInformationLevelMaximum                    EQU     52

PO_TRANSITION_VETO_TYPE_WINDOW                  EQU     00000001H
PO_TRANSITION_VETO_TYPE_SERVICE                 EQU     00000002H
PO_TRANSITION_VETO_TYPE_DRIVER                  EQU     00000004H

PO_TRANSITION_VETO_TYPE_ALL                     EQU     (PO_TRANSITION_VETO_TYPE_WINDOW OR PO_TRANSITION_VETO_TYPE_SERVICE)

PoAc                                            EQU     0
PoDc                                            EQU     1
PoHot                                           EQU     2
PoConditionMaximum                              EQU     3

POWER_SETTING_VALUE_VERSION                     EQU     01H

PlatformRoleUnspecified                         EQU     0
PlatformRoleDesktop                             EQU     1
PlatformRoleMobile                              EQU     2
PlatformRoleWorkstation                         EQU     3
PlatformRoleEnterpriseServer                    EQU     4
PlatformRoleSOHOServer                          EQU     5
PlatformRoleAppliancePC                         EQU     6
PlatformRolePerformanceServer                   EQU     7
PlatformRoleSlate                               EQU     8
PlatformRoleMaximum                             EQU     9

POWER_PLATFORM_ROLE_V1                          EQU     1
POWER_PLATFORM_ROLE_V1_MAX                      EQU     8

POWER_PLATFORM_ROLE_V2                          EQU     2
POWER_PLATFORM_ROLE_V2_MAX                      EQU     9

IF NTDDI_VERSION GE NTDDI_WIN8
    POWER_PLATFORM_ROLE_VERSION                 EQU     POWER_PLATFORM_ROLE_V2
    POWER_PLATFORM_ROLE_VERSION_MAX             EQU     POWER_PLATFORM_ROLE_V2_MAX
ELSE
    POWER_PLATFORM_ROLE_VERSION                 EQU     POWER_PLATFORM_ROLE_V1
    POWER_PLATFORM_ROLE_VERSION_MAX             EQU     POWER_PLATFORM_ROLE_V1_MAX
ENDIF

DeviceWakeSourceType                            EQU     0
FixedWakeSourceType                             EQU     1

FixedWakeSourcePowerButton                      EQU     0
FixedWakeSourceSleepButton                      EQU     1
FixedWakeSourceRtc                              EQU     2

PROC_IDLE_BUCKET_COUNT                          EQU     6

ACPI_PPM_SOFTWARE_ALL                           EQU     0FCH
ACPI_PPM_SOFTWARE_ANY                           EQU     0FDH
ACPI_PPM_HARDWARE_ALL                           EQU     0FEH
MS_PPM_SOFTWARE_ALL                             EQU     01H

POWER_ACTION_QUERY_ALLOWED                      EQU     00000001H
POWER_ACTION_UI_ALLOWED                         EQU     00000002H
POWER_ACTION_OVERRIDE_APPS                      EQU     00000004H
POWER_ACTION_PSEUDO_TRANSITION                  EQU     08000000H
POWER_ACTION_LIGHTEST_FIRST                     EQU     10000000H
POWER_ACTION_LOCK_CONSOLE                       EQU     20000000H
POWER_ACTION_DISABLE_WAKES                      EQU     40000000H
POWER_ACTION_CRITICAL                           EQU     80000000H

POWER_LEVEL_USER_NOTIFY_TEXT                    EQU     00000001H
POWER_LEVEL_USER_NOTIFY_SOUND                   EQU     00000002H
POWER_LEVEL_USER_NOTIFY_EXEC                    EQU     00000004H
POWER_USER_NOTIFY_BUTTON                        EQU     00000008H
POWER_USER_NOTIFY_SHUTDOWN                      EQU     00000010H
POWER_FORCE_TRIGGER_RESET                       EQU     80000000H

BATTERY_DISCHARGE_FLAGS_EVENTCODE_MASK          EQU     00000007H
BATTERY_DISCHARGE_FLAGS_ENABLE                  EQU     80000000H

NUM_DISCHARGE_POLICIES                          EQU     4
DISCHARGE_POLICY_CRITICAL                       EQU     0
DISCHARGE_POLICY_LOW                            EQU     1

PROCESSOR_IDLESTATE_POLICY_COUNT                EQU     03H

PO_THROTTLE_NONE                                EQU     0
PO_THROTTLE_CONSTANT                            EQU     1
PO_THROTTLE_DEGRADE                             EQU     2
PO_THROTTLE_ADAPTIVE                            EQU     3
PO_THROTTLE_MAXIMUM                             EQU     4

PERFSTATE_POLICY_CHANGE_IDEAL                   EQU     00H
PERFSTATE_POLICY_CHANGE_SINGLE                  EQU     01H
PERFSTATE_POLICY_CHANGE_ROCKET                  EQU     02H
PERFSTATE_POLICY_CHANGE_MAX                     EQU     PERFSTATE_POLICY_CHANGE_ROCKET

ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION EQU     1
ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION      EQU     2
ACTIVATION_CONTEXT_SECTION_WINDOW_CLASS_REDIRECTION EQU 3
ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION EQU   4
ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION EQU 5
ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION EQU 6
ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION EQU   7
ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_TABLE EQU 8
ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES       EQU     9
ACTIVATION_CONTEXT_SECTION_APPLICATION_SETTINGS EQU     10
ACTIVATION_CONTEXT_SECTION_COMPATIBILITY_INFO   EQU     11

IMAGE_SCN_TYPE_REG                              EQU     00000000H
IMAGE_SCN_TYPE_DSECT                            EQU     00000001H
IMAGE_SCN_TYPE_NOLOAD                           EQU     00000002H
IMAGE_SCN_TYPE_GROUP                            EQU     00000004H
IMAGE_SCN_TYPE_NO_PAD                           EQU     00000008H
IMAGE_SCN_TYPE_COPY                             EQU     00000010H

IMAGE_SCN_CNT_CODE                              EQU     00000020H
IMAGE_SCN_CNT_INITIALIZED_DATA                  EQU     00000040H
IMAGE_SCN_CNT_UNINITIALIZED_DATA                EQU     00000080H

IMAGE_SCN_LNK_OTHER                             EQU     00000100H
IMAGE_SCN_LNK_INFO                              EQU     00000200H
IMAGE_SCN_TYPE_OVER                             EQU     00000400H
IMAGE_SCN_LNK_REMOVE                            EQU     00000800H
IMAGE_SCN_LNK_COMDAT                            EQU     00001000H

IMAGE_SCN_NO_DEFER_SPEC_EXC                     EQU     00004000H
IMAGE_SCN_GPREL                                 EQU     00008000H
IMAGE_SCN_MEM_FARDATA                           EQU     00008000H
IMAGE_SCN_MEM_PURGEABLE                         EQU     00020000H
IMAGE_SCN_MEM_16BIT                             EQU     00020000H
IMAGE_SCN_MEM_LOCKED                            EQU     00040000H
IMAGE_SCN_MEM_PRELOAD                           EQU     00080000H

IMAGE_SCN_ALIGN_1BYTES                          EQU     00100000H
IMAGE_SCN_ALIGN_2BYTES                          EQU     00200000H
IMAGE_SCN_ALIGN_4BYTES                          EQU     00300000H
IMAGE_SCN_ALIGN_8BYTES                          EQU     00400000H
IMAGE_SCN_ALIGN_16BYTES                         EQU     00500000H
IMAGE_SCN_ALIGN_32BYTES                         EQU     00600000H
IMAGE_SCN_ALIGN_64BYTES                         EQU     00700000H
IMAGE_SCN_ALIGN_128BYTES                        EQU     00800000H
IMAGE_SCN_ALIGN_256BYTES                        EQU     00900000H
IMAGE_SCN_ALIGN_512BYTES                        EQU     00A00000H
IMAGE_SCN_ALIGN_1024BYTES                       EQU     00B00000H
IMAGE_SCN_ALIGN_2048BYTES                       EQU     00C00000H
IMAGE_SCN_ALIGN_4096BYTES                       EQU     00D00000H
IMAGE_SCN_ALIGN_8192BYTES                       EQU     00E00000H
IMAGE_SCN_ALIGN_MASK                            EQU     00F00000H

IMAGE_SCN_LNK_NRELOC_OVFL                       EQU     01000000H
IMAGE_SCN_MEM_DISCARDABLE                       EQU     02000000H
IMAGE_SCN_MEM_NOT_CACHED                        EQU     04000000H
IMAGE_SCN_MEM_NOT_PAGED                         EQU     08000000H
IMAGE_SCN_MEM_SHARED                            EQU     10000000H
IMAGE_SCN_MEM_EXECUTE                           EQU     20000000H
IMAGE_SCN_MEM_READ                              EQU     40000000H
IMAGE_SCN_MEM_WRITE                             EQU     80000000H

IMAGE_SCN_SCALE_INDEX                           EQU     00000001H

IMAGE_AUX_SYMBOL_TYPE_TOKEN_DEF                 EQU     1

IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR                 EQU     60

IMPORT_OBJECT_CODE                              EQU     0
IMPORT_OBJECT_DATA                              EQU     1
IMPORT_OBJECT_CONST                             EQU     2

IMPORT_OBJECT_ORDINAL                           EQU     0
IMPORT_OBJECT_NAME                              EQU     1
IMPORT_OBJECT_NAME_NO_PREFIX                    EQU     2
IMPORT_OBJECT_NAME_UNDECORATE                   EQU     3

RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO         EQU     001000000H
RTL_CRITICAL_SECTION_FLAG_DYNAMIC_SPIN          EQU     002000000H
RTL_CRITICAL_SECTION_FLAG_STATIC_INIT           EQU     004000000H
RTL_CRITICAL_SECTION_FLAG_RESOURCE_TYPE         EQU     008000000H
RTL_CRITICAL_SECTION_FLAG_FORCE_DEBUG_INFO      EQU     010000000H
RTL_CRITICAL_SECTION_ALL_FLAG_BITS              EQU     0FF000000H
RTL_CRITICAL_SECTION_FLAG_RESERVED              EQU     RTL_CRITICAL_SECTION_ALL_FLAG_BITS AND (NOT (RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO OR RTL_CRITICAL_SECTION_FLAG_DYNAMIC_SPIN OR RTL_CRITICAL_SECTION_FLAG_RESOURCE_TYPE OR RTL_CRITICAL_SECTION_FLAG_FORCE_DEBUG_INFO))
RTL_CRITICAL_SECTION_DEBUG_FLAG_STATIC_INIT     EQU     000000001H

RTL_SRWLOCK_INIT                                EQU     0

RTL_CONDITION_VARIABLE_INIT                     EQU     00H
RTL_CONDITION_VARIABLE_LOCKMODE_SHARED          EQU     01H

ACTIVATION_CONTEXT_PATH_TYPE_NONE               EQU     1
ACTIVATION_CONTEXT_PATH_TYPE_WIN32_FILE         EQU     2
ACTIVATION_CONTEXT_PATH_TYPE_URL                EQU     3
ACTIVATION_CONTEXT_PATH_TYPE_ASSEMBLYREF        EQU     4

ACTCTX_RUN_LEVEL_UNSPECIFIED                    EQU     0
ACTCTX_RUN_LEVEL_AS_INVOKER                     EQU     1
ACTCTX_RUN_LEVEL_HIGHEST_AVAILABLE              EQU     2
ACTCTX_RUN_LEVEL_REQUIRE_ADMIN                  EQU     3
ACTCTX_RUN_LEVEL_NUMBERS                        EQU     4

MAX_SUPPORTED_OS_NUM                            EQU     4

TRANSACTION_MANAGER_VOLATILE                    EQU     000000001H
TRANSACTION_MANAGER_COMMIT_DEFAULT              EQU     000000000H
TRANSACTION_MANAGER_COMMIT_SYSTEM_VOLUME        EQU     000000002H
TRANSACTION_MANAGER_COMMIT_SYSTEM_HIVES         EQU     000000004H
TRANSACTION_MANAGER_COMMIT_LOWEST               EQU     000000008H
TRANSACTION_MANAGER_CORRUPT_FOR_RECOVERY        EQU     000000010H
TRANSACTION_MANAGER_CORRUPT_FOR_PROGRESS        EQU     000000020H
TRANSACTION_MANAGER_MAXIMUM_OPTION              EQU     00000003FH

TRANSACTION_DO_NOT_PROMOTE                      EQU     000000001H
TRANSACTION_MAXIMUM_OPTION                      EQU     000000001H

TRANSACTION_NOTIFY_MASK                         EQU     03FFFFFFFH
TRANSACTION_NOTIFY_PREPREPARE                   EQU     000000001H
TRANSACTION_NOTIFY_PREPARE                      EQU     000000002H
TRANSACTION_NOTIFY_COMMIT                       EQU     000000004H
TRANSACTION_NOTIFY_ROLLBACK                     EQU     000000008H
TRANSACTION_NOTIFY_PREPREPARE_COMPLETE          EQU     000000010H
TRANSACTION_NOTIFY_PREPARE_COMPLETE             EQU     000000020H
TRANSACTION_NOTIFY_COMMIT_COMPLETE              EQU     000000040H
TRANSACTION_NOTIFY_ROLLBACK_COMPLETE            EQU     000000080H
TRANSACTION_NOTIFY_RECOVER                      EQU     000000100H
TRANSACTION_NOTIFY_SINGLE_PHASE_COMMIT          EQU     000000200H
TRANSACTION_NOTIFY_DELEGATE_COMMIT              EQU     000000400H
TRANSACTION_NOTIFY_RECOVER_QUERY                EQU     000000800H
TRANSACTION_NOTIFY_ENLIST_PREPREPARE            EQU     000001000H
TRANSACTION_NOTIFY_LAST_RECOVER                 EQU     000002000H
TRANSACTION_NOTIFY_INDOUBT                      EQU     000004000H
TRANSACTION_NOTIFY_PROPAGATE_PULL               EQU     000008000H
TRANSACTION_NOTIFY_PROPAGATE_PUSH               EQU     000010000H
TRANSACTION_NOTIFY_MARSHAL                      EQU     000020000H
TRANSACTION_NOTIFY_ENLIST_MASK                  EQU     000040000H
TRANSACTION_NOTIFY_RM_DISCONNECTED              EQU     001000000H
TRANSACTION_NOTIFY_TM_ONLINE                    EQU     002000000H
TRANSACTION_NOTIFY_COMMIT_REQUEST               EQU     004000000H
TRANSACTION_NOTIFY_PROMOTE                      EQU     008000000H
TRANSACTION_NOTIFY_PROMOTE_NEW                  EQU     010000000H
TRANSACTION_NOTIFY_REQUEST_OUTCOME              EQU     020000000H
TRANSACTION_NOTIFY_COMMIT_FINALIZE              EQU     040000000H

TRANSACTIONMANAGER_QUERY_INFORMATION            EQU     00001H
TRANSACTIONMANAGER_SET_INFORMATION              EQU     00002H
TRANSACTIONMANAGER_RECOVER                      EQU     00004H
TRANSACTIONMANAGER_RENAME                       EQU     00008H
TRANSACTIONMANAGER_CREATE_RM                    EQU     00010H
TRANSACTIONMANAGER_BIND_TRANSACTION             EQU     00020H
TRANSACTIONMANAGER_GENERIC_READ                 EQU     (STANDARD_RIGHTS_READ OR TRANSACTIONMANAGER_QUERY_INFORMATION)
TRANSACTIONMANAGER_GENERIC_WRITE                EQU     (STANDARD_RIGHTS_WRITE OR TRANSACTIONMANAGER_SET_INFORMATION OR \
                                                        TRANSACTIONMANAGER_RECOVER OR TRANSACTIONMANAGER_RENAME OR \
                                                        TRANSACTIONMANAGER_CREATE_RM)
TRANSACTIONMANAGER_GENERIC_EXECUTE              EQU     STANDARD_RIGHTS_EXECUTE
TRANSACTIONMANAGER_ALL_ACCESS                   EQU     (STANDARD_RIGHTS_REQUIRED OR TRANSACTIONMANAGER_GENERIC_READ OR \
                                                        TRANSACTIONMANAGER_GENERIC_WRITE OR TRANSACTIONMANAGER_GENERIC_EXECUTE OR \
                                                        TRANSACTIONMANAGER_BIND_TRANSACTION)

TRANSACTION_QUERY_INFORMATION                   EQU     00001H
TRANSACTION_SET_INFORMATION                     EQU     00002H
TRANSACTION_ENLIST                              EQU     00004H
TRANSACTION_COMMIT                              EQU     00008H
TRANSACTION_ROLLBACK                            EQU     00010H
TRANSACTION_PROPAGATE                           EQU     00020H
TRANSACTION_RIGHT_RESERVED1                     EQU     00040H

TRANSACTION_GENERIC_READ                        EQU     (STANDARD_RIGHTS_READ OR TRANSACTION_QUERY_INFORMATION OR SYNCHRONIZE)
TRANSACTION_GENERIC_WRITE                       EQU     (STANDARD_RIGHTS_WRITE OR TRANSACTION_SET_INFORMATION OR \
                                                        TRANSACTION_COMMIT OR TRANSACTION_ENLIST OR TRANSACTION_ROLLBACK OR \
                                                        TRANSACTION_PROPAGATE OR SYNCHRONIZE)
TRANSACTION_GENERIC_EXECUTE                     EQU     (STANDARD_RIGHTS_EXECUTE OR TRANSACTION_COMMIT OR \
                                                        TRANSACTION_ROLLBACK OR SYNCHRONIZE)
TRANSACTION_ALL_ACCESS                          EQU     (STANDARD_RIGHTS_REQUIRED OR TRANSACTION_GENERIC_READ OR \
                                                        TRANSACTION_GENERIC_WRITE OR TRANSACTION_GENERIC_EXECUTE)
TRANSACTION_RESOURCE_MANAGER_RIGHTS             EQU     (TRANSACTION_GENERIC_READ OR STANDARD_RIGHTS_WRITE OR \
                                                        TRANSACTION_SET_INFORMATION OR TRANSACTION_ENLIST OR \
                                                        TRANSACTION_ROLLBACK OR TRANSACTION_PROPAGATE OR SYNCHRONIZE)

RESOURCEMANAGER_QUERY_INFORMATION               EQU     00001H
RESOURCEMANAGER_SET_INFORMATION                 EQU     00002H
RESOURCEMANAGER_RECOVER                         EQU     00004H
RESOURCEMANAGER_ENLIST                          EQU     00008H
RESOURCEMANAGER_GET_NOTIFICATION                EQU     00010H
RESOURCEMANAGER_REGISTER_PROTOCOL               EQU     00020H
RESOURCEMANAGER_COMPLETE_PROPAGATION            EQU     00040H

RESOURCEMANAGER_GENERIC_READ                    EQU     (STANDARD_RIGHTS_READ OR RESOURCEMANAGER_QUERY_INFORMATION OR SYNCHRONIZE)
RESOURCEMANAGER_GENERIC_WRITEA                  EQU     (STANDARD_RIGHTS_WRITE OR RESOURCEMANAGER_SET_INFORMATION OR \
                                                        RESOURCEMANAGER_RECOVER OR RESOURCEMANAGER_ENLIST OR \
                                                        RESOURCEMANAGER_GET_NOTIFICATION OR RESOURCEMANAGER_REGISTER_PROTOCOL)
RESOURCEMANAGER_GENERIC_WRITEB                  EQU     (RESOURCEMANAGER_COMPLETE_PROPAGATION OR SYNCHRONIZE)
RESOURCEMANAGER_GENERIC_WRITE                   EQU     (RESOURCEMANAGER_GENERIC_WRITEA OR RESOURCEMANAGER_GENERIC_WRITEB)
RESOURCEMANAGER_GENERIC_EXECUTE                 EQU     (STANDARD_RIGHTS_EXECUTE OR RESOURCEMANAGER_RECOVER OR \
                                                        RESOURCEMANAGER_ENLIST OR RESOURCEMANAGER_GET_NOTIFICATION OR \
                                                        RESOURCEMANAGER_COMPLETE_PROPAGATION OR SYNCHRONIZE)
RESOURCEMANAGER_ALL_ACCESS                      EQU     (STANDARD_RIGHTS_REQUIRED OR RESOURCEMANAGER_GENERIC_READ OR \
                                                        RESOURCEMANAGER_GENERIC_WRITE OR RESOURCEMANAGER_GENERIC_EXECUTE)

RESOURCE_MANAGER_VOLATILE                       EQU     000000001H
RESOURCE_MANAGER_COMMUNICATION                  EQU     000000002H
RESOURCE_MANAGER_MAXIMUM_OPTION                 EQU     000000003H

ENLISTMENT_QUERY_INFORMATION                    EQU     00001H
ENLISTMENT_SET_INFORMATION                      EQU     00002H
ENLISTMENT_RECOVER                              EQU     00004H
ENLISTMENT_SUBORDINATE_RIGHTS                   EQU     00008H
ENLISTMENT_SUPERIOR_RIGHTS                      EQU     00010H
ENLISTMENT_GENERIC_READ                         EQU     (STANDARD_RIGHTS_READ OR ENLISTMENT_QUERY_INFORMATION)
ENLISTMENT_GENERIC_WRITE                        EQU     (STANDARD_RIGHTS_WRITE OR ENLISTMENT_SET_INFORMATION OR \
                                                        ENLISTMENT_RECOVER OR ENLISTMENT_SUBORDINATE_RIGHTS OR \
                                                        ENLISTMENT_SUPERIOR_RIGHTS)
ENLISTMENT_GENERIC_EXECUTE                      EQU     (STANDARD_RIGHTS_EXECUTE OR ENLISTMENT_RECOVER OR \
                                                        ENLISTMENT_SUBORDINATE_RIGHTS OR ENLISTMENT_SUPERIOR_RIGHTS)
ENLISTMENT_ALL_ACCESS                           EQU     (STANDARD_RIGHTS_REQUIRED OR ENLISTMENT_GENERIC_READ OR \
                                                        ENLISTMENT_GENERIC_WRITE OR ENLISTMENT_GENERIC_EXECUTE)

CRM_PROTOCOL_EXPLICIT_MARSHAL_ONLY              EQU     000000001H
CRM_PROTOCOL_DYNAMIC_MARSHAL_INFO               EQU     000000002H
CRM_PROTOCOL_MAXIMUM_OPTION                     EQU     000000003H

ENLISTMENT_SUPERIOR EQU     000000001H
ENLISTMENT_MAXIMUM_OPTION                       EQU     000000001H

KTM_MARSHAL_BLOB_VERSION_MAJOR                  EQU     1
KTM_MARSHAL_BLOB_VERSION_MINOR                  EQU     1
MAX_TRANSACTION_DESCRIPTION_LENGTH              EQU     64
MAX_RESOURCEMANAGER_DESCRIPTION_LENGTH          EQU     64

COMIMAGE_FLAGS_ILONLY                           EQU     00000001H
COMIMAGE_FLAGS_32BITREQUIRED                    EQU     00000002H
COMIMAGE_FLAGS_IL_LIBRARY                       EQU     00000004H
COMIMAGE_FLAGS_STRONGNAMESIGNED                 EQU     00000008H
COMIMAGE_FLAGS_NATIVE_ENTRYPOINT                EQU     00000010H
COMIMAGE_FLAGS_TRACKDEBUGDATA                   EQU     00010000H
COR_VERSION_MAJOR_V2                            EQU     2
COR_VERSION_MAJOR                               EQU     2
COR_VERSION_MINOR                               EQU     5
COR_DELETED_NAME_LENGTH                         EQU     8
COR_VTABLEGAP_NAME_LENGTH                       EQU     8
NATIVE_TYPE_MAX_CB                              EQU     1
COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE            EQU     0FFH
IMAGE_COR_MIH_METHODRVA                         EQU     01H
IMAGE_COR_MIH_EHRVA                             EQU     02H
IMAGE_COR_MIH_BASICBLOCK                        EQU     08H
COR_VTABLE_32BIT                                EQU     01H
COR_VTABLE_64BIT                                EQU     02H
COR_VTABLE_FROM_UNMANAGED                       EQU     04H
COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN      EQU     08H
COR_VTABLE_CALL_MOST_DERIVED                    EQU     10H
IMAGE_COR_EATJ_THUNK_SIZE                       EQU     20H
MAX_CLASS_NAME                                  EQU     1024
MAX_PACKAGE_NAME                                EQU     1024

IF (NTDDI_VERSION GE NTDDI_WIN8)
    VRL_PREDEFINED_CLASS_BEGIN                  EQU     (1 SHL 0)
    VRL_CUSTOM_CLASS_BEGIN                      EQU     (1 SHL 8)
    VRL_CLASS_CONSISTENCY                       EQU     (VRL_PREDEFINED_CLASS_BEGIN SHL 0)
    VRL_ENABLE_KERNEL_BREAKS                    EQU     (1 SHL 31)

    CTMF_INCLUDE_APPCONTAINER                   EQU     000000001H
    CTMF_VALID_FLAGS                            EQU     CTMF_INCLUDE_APPCONTAINER
ENDIF

IF (NTDDI_VERSION GT NTDDI_WIN8)
    HEAP_OPTIMIZE_RESOURCES_CURRENT_VERSION     EQU     1

    HEAP_OPTIMIZE_RESOURCES_INFORMATION STRUCT ALIGNMODE
        Version DD  ?
        Flags   DD  ?
    HEAP_OPTIMIZE_RESOURCES_INFORMATION     ENDS
ENDIF

RTL_RUN_ONCE_INIT                               EQU     0
RTL_RUN_ONCE_CHECK_ONLY                         EQU     000000001H
RTL_RUN_ONCE_ASYNC                              EQU     000000002H
RTL_RUN_ONCE_INIT_FAILED                        EQU     000000004H

RTL_RUN_ONCE_CTX_RESERVED_BITS                  EQU     2

IMAGE_BASE                                      EQU     400000H


;======================================== Structures ======================================;
IFNDEF GUID
    GUID STRUCT ALIGNMODE
        Data1   DD  ?
        Data2   DW  ?
        Data3   DW  ?
        Data4   DB  8 DUP(?)
    GUID ENDS
ENDIF

FLOAT128 STRUCT ALIGNMODE
    LowPart     DQ  ?
    HighPart    DQ  ?
FLOAT128 ENDS

IFNDEF LARGE_INTEGER
    LARGE_INTEGER UNION ALIGNMODE
        STRUCT
            LowPart  DD ?
            HighPart DD ?
        ENDS
        QuadPart     DQ ?
    LARGE_INTEGER ENDS
ENDIF

IFNDEF ULARGE_INTEGER
    ULARGE_INTEGER STRUCT ALIGNMODE
        STRUCT
            LowPart  DD ?
            HighPart DD ?
        ENDS
        QuadPart     DQ ?
    ULARGE_INTEGER ENDS
ENDIF

IFNDEF LIST_ENTRY
    LIST_ENTRY STRUCT ALIGNMODE
        Flink   XPTR ?
        Blink   XPTR ?
    LIST_ENTRY ENDS
ENDIF

IFNDEF COORD
    COORD STRUCT ALIGNMODE
        X DW ?
        Y DW ?
    COORD ENDS
ENDIF

IFNDEF CONSOLE_FONT_INFO
    CONSOLE_FONT_INFO STRUCT ALIGNMODE
        nFont      DD    ?
        dwFontSize COORD <>
    CONSOLE_FONT_INFO ENDS
ENDIF

IFNDEF OSVERSIONINFOEX
    IFNDEF OSVERSIONINFOEXA
        OSVERSIONINFOEXA Struct ALIGNMODE
            dwOSVersionInfoSize DD  ?
            dwMajorVersion      DD  ?
            dwMinorVersion      DD  ?
            dwBuildNumber       DD  ?
            dwPlatformId        DD  ?
            szCSDVersion        DB  128 DUP(?)
            wServicePackMajor   DW  ?
            wServicePackMinor   DW  ?
            wSuiteMask          DW  ?
            wProductType        DB  ?
            wReserved           DB  ?
        OSVERSIONINFOEXA EndS
    ENDIF

    IFNDEF OSVERSIONINFOEXW
        OSVERSIONINFOEXW Struct ALIGNMODE
            dwOSVersionInfoSize DD  ?
            dwMajorVersion      DD  ?
            dwMinorVersion      DD  ?
            dwBuildNumber       DD  ?
            dwPlatformId        DD  ?
            szCSDVersion        DW  128 Dup(?)
            wServicePackMajor   DW  ?
            wServicePackMinor   DW  ?
            wSuiteMask          DW  ?
            wProductType        DB  ?
            wReserved           DB  ?
        OSVERSIONINFOEXW EndS
    ENDIF

    IFDEF APP_UNICODE
        OSVERSIONINFOEX EQU <OSVERSIONINFOEXW>
    ELSE
        OSVERSIONINFOEX EQU <OSVERSIONINFOEXA>
    ENDIF
ENDIF

POWER_PLATFORM_INFORMATION STRUCT ALIGNMODE
    Role    ENUM    ?
    AoAc    BOOLEAN ?
POWER_PLATFORM_INFORMATION ENDS

SINGLE_LIST_ENTRY STRUCT ALIGNMODE
    Next    XPTR ?
SINGLE_LIST_ENTRY ENDS

SLIST_ENTRY STRUCT ALIGNMODE
    Next    XPTR ?
SLIST_ENTRY ENDS

LIST_ENTRY32 STRUCT ALIGNMODE
    Flink   DD  ?
    Blink   DD  ?
LIST_ENTRY32 ENDS

LIST_ENTRY64 STRUCT ALIGNMODE
    Flink   ULONGLONG ?
    Blink   ULONGLONG ?
LIST_ENTRY64 ENDS

OBJECTID STRUCT ALIGNMODE
    Lineage     GUID <>
    Uniquifier  DD   ?
OBJECTID ENDS

M128A STRUCT ALIGNMODE
    _Low    ULONGLONG ?
    _High   ULONGLONG ?
M128A ENDS

XSAVE_FORMAT STRUCT ALIGNMODE
    ControlWord     DW  ?
    StatusWord      DW  ?
    TagWord         DB  ?
    Reserved1       DB  ?
    ErrorOpcode     DW  ?
    ErrorOffset     DD  ?
    ErrorSelector   DW  ?
    Reserved2       DW  ?
    DataOffset      DD  ?
    DataSelector    DW  ?
    Reserved3       DW  ?
    MxCsr           DD  ?
    MxCsr_Mask      DD  ?
    FloatRegisters  M128A 8 DUP(<>)
    IFDEF APP_WIN64
        XmmRegisters M128A 16 DUP(<>)
    ELSE
        XmmRegisters M128A 8 DUP(<>)
    ENDIF 
    Reserved4       DB  96 DUP(?)
XSAVE_FORMAT ENDS


IFNDEF XMM_SAVE_AREA32_DEFINED
	XMM_SAVE_AREA32_DEFINED EQU 1
	XMM_SAVE_AREA32 STRUCT ALIGNMODE
		ControlWord     UINT16  ?
		StatusWord      UINT16  ?
		TagWord         DB  ?
		Reserved1       DB  ?
		ErrorOpcode     UINT16  ?
		ErrorOffset     ULONG32 ?
		ErrorSelector   UINT16  ?
		Reserved2       UINT16  ?
		DataOffset      ULONG32 ?
		DataSelector    UINT16  ?
		Reserved3       UINT16  ?
		MxCsr           ULONG32 ?
		MxCsr_Mask      ULONG32 ?
		FloatRegisters  M128A 8 DUP(<>)
		XmmRegisters    M128A 16 DUP(<>)
		Reserved4       DB  96 DUP(?)
	XMM_SAVE_AREA32 ENDS
ENDIF

IFNDEF FLOATING_SAVE_AREA_DEFINED
	FLOATING_SAVE_AREA_DEFINED EQU 1
	FLOATING_SAVE_AREA STRUCT ALIGNMODE
		ControlWord     DD  ?
		StatusWord      DD  ?
		TagWord         DD  ?
		ErrorOffset     DD  ?
		ErrorSelector   DD  ?
		DataOffset      DD  ?
		DataSelector    DD  ?
		RegisterArea    DB  SIZE_OF_80387_REGISTERS DUP(?)
		Cr0NpxState     DD  ?
	FLOATING_SAVE_AREA ENDS
ENDIF

RUNTIME_FUNCTION STRUCT ALIGNMODE
    BeginAddress        DD  ?
    EndAddress          DD  ?
    UnwindInfoAddress   DD  ?
RUNTIME_FUNCTION ENDS
PRUNTIME_FUNCTION                               TYPEDEF XPTR

IFDEF APP_WIN64
    CONTEXT_CONTROL                             EQU     (CONTEXT_AMD64 OR 01H)
    CONTEXT_INTEGER                             EQU     (CONTEXT_AMD64 OR 02H)
    CONTEXT_SEGMENTS                            EQU     (CONTEXT_AMD64 OR 04H)
    CONTEXT_FLOATING_POINT                      EQU     (CONTEXT_AMD64 OR 08H)
    CONTEXT_DEBUG_REGISTERS                     EQU     (CONTEXT_AMD64 OR 10H)

    CONTEXT_FULL                                EQU     (CONTEXT_CONTROL OR CONTEXT_INTEGER OR CONTEXT_FLOATING_POINT)

    CONTEXT_ALL                                 EQU     (CONTEXT_CONTROL OR CONTEXT_INTEGER OR CONTEXT_SEGMENTS OR CONTEXT_FLOATING_POINT OR CONTEXT_DEBUG_REGISTERS)

    CONTEXT_EXCEPTION_ACTIVE                    EQU     08000000H
    CONTEXT_SERVICE_ACTIVE                      EQU     10000000H
    CONTEXT_EXCEPTION_REQUEST                   EQU     40000000H
    CONTEXT_EXCEPTION_REPORTING                 EQU     80000000H

    CONTEXT STRUCT ALIGNMODE
        P1Home       DWORD64 ?
        P2Home       DWORD64 ?
        P3Home       DWORD64 ?
        P4Home       DWORD64 ?
        P5Home       DWORD64 ?
        P6Home       DWORD64 ?
        ContextFlags DD      ?
        MxCsr        DD      ?
        regCs        DW      ?
        regDs        DW      ?
        regEs        DW      ?
        regFs        DW      ?
        regGs        DW      ?
        regSs        DW      ?
        regFlag      DD      ?
        _Dr0         DWORD64 ?
        _Dr1         DWORD64 ?
        _Dr2         DWORD64 ?
        _Dr3         DWORD64 ?
        _Dr6         DWORD64 ?
        _Dr7         DWORD64 ?
        regRax       DWORD64 ?
        regRcx       DWORD64 ?
        regRdx       DWORD64 ?
        regRbx       DWORD64 ?
        regRsp       DWORD64 ?
        regRbp       DWORD64 ?
        regRsi       DWORD64 ?
        regRdi       DWORD64 ?
        regR8        DWORD64 ?
        regR9        DWORD64 ?
        regR10       DWORD64 ?
        regR11       DWORD64 ?
        regR12       DWORD64 ?
        regR13       DWORD64 ?
        regR14       DWORD64 ?
        regR15       DWORD64 ?
        regRip       DWORD64 ?
        UNION u
            FltSave XMM_SAVE_AREA32 <>
            STRUCT s
                Header   M128A 2 DUP(<>)
                Legacy   M128A 8 DUP(<>)
                regXmm0  M128A <>
                regXmm1  M128A <>
                regXmm2  M128A <>
                regXmm3  M128A <>
                regXmm4  M128A <>
                regXmm5  M128A <>
                regXmm6  M128A <>
                regXmm7  M128A <>
                regXmm8  M128A <>
                regXmm9  M128A <>
                regXmm10 M128A <>
                regXmm11 M128A <>
                regXmm12 M128A <>
                regXmm13 M128A <>
                regXmm14 M128A <>
                regXmm15 M128A <>
            ENDS
        ENDS
        VectorRegister       M128A 26 DUP(<>)
        VectorControl        DWORD64 ?
        DebugControl         DWORD64 ?
        LastBranchToRip      DWORD64 ?
        LastBranchFromRip    DWORD64 ?
        LastExceptionToRip   DWORD64 ?
        LastExceptionFromRip DWORD64 ?
    CONTEXT ENDS

    UNWIND_HISTORY_TABLE_ENTRY STRUCT ALIGNMODE
        ImageBase       DQ  ?
        Gp              DQ  ?
        FunctionEntry   PRUNTIME_FUNCTION ?
    UNWIND_HISTORY_TABLE_ENTRY ENDS

    UNWIND_HISTORY_TABLE STRUCT ALIGNMODE
        Count       DD  ?
        LocalHint   DB  ?
        GlobalHint  DB  ?
        Search      DB  ?
        Once        DB  ?
        LowAddress  DQ  ?
        HighAddress DQ  ?
        Entry       UNWIND_HISTORY_TABLE_ENTRY UNWIND_HISTORY_TABLE_SIZE DUP(<>)
    UNWIND_HISTORY_TABLE ENDS

    KNONVOLATILE_CONTEXT_POINTERS STRUCT ALIGNMODE
        UNION u
            FloatingContext XPTR 16 DUP(?)
            STRUCT
                _Xmm0  XPTR ?
                _Xmm1  XPTR ?
                _Xmm2  XPTR ?
                _Xmm3  XPTR ?
                _Xmm4  XPTR ?
                _Xmm5  XPTR ?
                _Xmm6  XPTR ?
                _Xmm7  XPTR ?
                _Xmm8  XPTR ?
                _Xmm9  XPTR ?
                _Xmm10 XPTR ?
                _Xmm11 XPTR ?
                _Xmm12 XPTR ?
                _Xmm13 XPTR ?
                _Xmm14 XPTR ?
                _Xmm15 XPTR ?
            ENDS
        ENDS

        UNION u2
            IntegerContext XPTR 16 DUP(?)
            STRUCT
                _Rax   XPTR ?
                _Rcx   XPTR ?
                _Rdx   XPTR ?
                _Rbx   XPTR ?
                _Rsp   XPTR ?
                _Rbp   XPTR ?
                _Rsi   XPTR ?
                _Rdi   XPTR ?
                _R8    XPTR ?
                _R9    XPTR ?
                _R10   XPTR ?
                _R11   XPTR ?
                _R12   XPTR ?
                _R13   XPTR ?
                _R14   XPTR ?
                _R15   XPTR ?
            ENDS
        ENDS
    KNONVOLATILE_CONTEXT_POINTERS ENDS

    FRAME_POINTERS STRUCT ALIGNMODE
        MemoryStackFp   ULONGLONG ?
        BackingStoreFp  ULONGLONG ?
    FRAME_POINTERS ENDS
ELSE
    CONTEXT_CONTROL                             EQU     (CONTEXT_i386 OR 00000001H)
    CONTEXT_INTEGER                             EQU     (CONTEXT_i386 OR 00000002H)
    CONTEXT_SEGMENTS                            EQU     (CONTEXT_i386 OR 00000004H)
    CONTEXT_FLOATING_POINT                      EQU     (CONTEXT_i386 OR 00000008H)
    CONTEXT_DEBUG_REGISTERS                     EQU     (CONTEXT_i386 OR 00000010H)
    CONTEXT_EXTENDED_REGISTERS                  EQU     (CONTEXT_i386 OR 00000020H)
    CONTEXT_FULL                                EQU     (CONTEXT_CONTROL OR CONTEXT_INTEGER OR CONTEXT_SEGMENTS)
    CONTEXT_ALL                                 EQU     (CONTEXT_CONTROL OR CONTEXT_INTEGER OR CONTEXT_SEGMENTS OR CONTEXT_FLOATING_POINT OR CONTEXT_DEBUG_REGISTERS OR CONTEXT_EXTENDED_REGISTERS)

    CONTEXT STRUCT ALIGNMODE
        ContextFlags        DD  ?
        _Dr0                DD  ?
        _Dr1                DD  ?
        _Dr2                DD  ?
        _Dr3                DD  ?
        _Dr6                DD  ?
        _Dr7                DD  ?
        FloatSave           FLOATING_SAVE_AREA <>
        regGs               DD  ?
        regFs               DD  ?
        regEs               DD  ?
        regDs               DD  ?
        regEdi              DD  ?
        regEsi              DD  ?
        regEbx              DD  ?
        regEdx              DD  ?
        regEcx              DD  ?
        regEax              DD  ?
        regEbp              DD  ?
        regEip              DD  ?
        regCs               DD  ?
        regFlag             DD  ?
        regEsp              DD  ?
        regSs               DD  ?
        ExtendedRegisters   DB MAXIMUM_SUPPORTED_EXTENSION DUP(?)
    CONTEXT ENDS

    UNWIND_HISTORY_TABLE_ENTRY STRUCT ALIGNMODE
        ImageBase     DD    ?
        FunctionEntry PRUNTIME_FUNCTION ?
    UNWIND_HISTORY_TABLE_ENTRY ENDS

    UNWIND_HISTORY_TABLE STRUCT ALIGNMODE
        Count       DD  ?
        LocalHint   DB  ?
        GlobalHint  DB  ?
        Search      DB  ?
        Once        DB  ?
        LowAddress  DD  ?
        HighAddress DD  ?
        Entry       UNWIND_HISTORY_TABLE_ENTRY UNWIND_HISTORY_TABLE_SIZE DUP(<>)
    UNWIND_HISTORY_TABLE ENDS
ENDIF
PCONTEXT                                        TYPEDEF XPTR

IFNDEF EXCEPTION_RECORD
    EXCEPTION_RECORD STRUCT ALIGNMODE
        ExceptionCode        DD    ?
        ExceptionFlags       DD    ?
        ExceptionRecord      XPTR  ?
        ExceptionAddress     PVOID ?
        NumberParameters     DD    ?
        ExceptionInformation XPTR  EXCEPTION_MAXIMUM_PARAMETERS DUP(?)
    EXCEPTION_RECORD ENDS
    PEXCEPTION_RECORD                               TYPEDEF XPTR
ENDIF

IFNDEF DISPATCHER_CONTEXT
    DISPATCHER_CONTEXT Struct ALIGNMODE
        ControlPc        ULONG64 ? 
        ImageBase        ULONG64 ?
        FunctionEntry    LPVOID  ?
        EstablisherFrame ULONG64 ?
        TargetIp         ULONG64 ?
        ContextRecord    LPVOID  ?
        LanguageHandler  LPVOID  ?
        HandlerData      LPVOID  ?
        HistoryTable     LPVOID  ?
        ScopeIndex       ULONG   ?
        Fill0            ULONG   ?
    DISPATCHER_CONTEXT ENDS
ENDIF

EXCEPTION_RECORD32 STRUCT ALIGNMODE
    ExceptionCode        DD ?
    ExceptionFlags       DD ?
    ExceptionRecord      DD ?
    ExceptionAddress     DD ?
    NumberParameters     DD ?
    ExceptionInformation DD EXCEPTION_MAXIMUM_PARAMETERS DUP(?)
EXCEPTION_RECORD32 ENDS

EXCEPTION_RECORD64 STRUCT ALIGNMODE
    ExceptionCode        DD ?
    ExceptionFlags       DD ?
    ExceptionRecord      DQ ?
    ExceptionAddress     DQ ?
    NumberParameters     DD ?
    __unusedAlignment    DD ?
    ExceptionInformation DQ EXCEPTION_MAXIMUM_PARAMETERS DUP(?)
EXCEPTION_RECORD64 ENDS

EXCEPTION_POINTERS STRUCT ALIGNMODE
    ExceptionRecord XPTR ?
    ContextRecord   XPTR ?
EXCEPTION_POINTERS ENDS

GENERIC_MAPPING STRUCT ALIGNMODE
    GenericRead     ACCESS_MASK ?
    GenericWrite    ACCESS_MASK ?
    GenericExecute  ACCESS_MASK ?
    GenericAll      ACCESS_MASK ?
GENERIC_MAPPING ENDS

LUID_AND_ATTRIBUTES STRUCT ALIGNMODE
    Luid            LUID <>
    Attributes      DD  ?
LUID_AND_ATTRIBUTES ENDS

SID_IDENTIFIER_AUTHORITY STRUCT ALIGNMODE
    Value   DB 6 DUP(?)
SID_IDENTIFIER_AUTHORITY ENDS

SID STRUCT ALIGNMODE
    Revision            DB  ?
    SubAuthorityCount   DB  ?
    IdentifierAuthority SID_IDENTIFIER_AUTHORITY <>
    SubAuthority        DD  ?
SID ENDS

SID_AND_ATTRIBUTES STRUCT ALIGNMODE
    Sid         XPTR ?
    Attributes  DD   ?
SID_AND_ATTRIBUTES ENDS

SID_AND_ATTRIBUTES_HASH STRUCT ALIGNMODE
    SidCount    DD   ?
    SidAttr     XPTR ?
    Hash        SID_HASH_ENTRY SID_HASH_SIZE DUP(?)
SID_AND_ATTRIBUTES_HASH ENDS

ACL STRUCT ALIGNMODE
    AclRevision DB  ?
    Sbz1        DB  ?
    AclSize     DW  ?
    AceCount    DW  ?
    Sbz2        DW  ?
ACL ENDS

ACE_HEADER STRUCT ALIGNMODE
    AceType     DB  ?
    AceFlags    DB  ?
    AceSize     DW  ?
ACE_HEADER ENDS

ACCESS_ALLOWED_ACE STRUCT ALIGNMODE
    Header      ACE_HEADER <>
    _Mask       ACCESS_MASK ?
    SidStart    DD  ?
ACCESS_ALLOWED_ACE ENDS

ACCESS_DENIED_ACE STRUCT ALIGNMODE
    Header      ACE_HEADER <>
    _Mask       ACCESS_MASK ?
    SidStart    DD  ?
ACCESS_DENIED_ACE ENDS

SYSTEM_AUDIT_ACE STRUCT ALIGNMODE
    Header   ACE_HEADER <>
    _Mask    ACCESS_MASK ?
    SidStart DD ?
SYSTEM_AUDIT_ACE ENDS

SYSTEM_ALARM_ACE STRUCT ALIGNMODE
    Header   ACE_HEADER <>
    _Mask    ACCESS_MASK ?
    SidStart DD ?
SYSTEM_ALARM_ACE ENDS

SYSTEM_RESOURCE_ATTRIBUTE_ACE STRUCT ALIGNMODE
    Header      ACE_HEADER <>
    imask       ACCESS_MASK ?
    SidStart    DD  ?
SYSTEM_RESOURCE_ATTRIBUTE_ACE ENDS

SYSTEM_SCOPED_POLICY_ID_ACE STRUCT ALIGNMODE
    Header      ACE_HEADER <>
    imask       ACCESS_MASK ?
    SidStart    DD  ?
SYSTEM_SCOPED_POLICY_ID_ACE ENDS

SYSTEM_MANDATORY_LABEL_ACE STRUCT ALIGNMODE
    Header      ACE_HEADER <>
    _Mask       ACCESS_MASK ?
    SidStart    DD  ?
SYSTEM_MANDATORY_LABEL_ACE ENDS

SYSTEM_PROCESS_TRUST_LABEL_ACE STRUCT ALIGNMODE
    Header      ACE_HEADER <>
    _Mask       ACCESS_MASK ?
    SidStart    DD  ?
SYSTEM_PROCESS_TRUST_LABEL_ACE ENDS

ACCESS_ALLOWED_OBJECT_ACE STRUCT ALIGNMODE
    Header              ACE_HEADER <>
    _Mask               ACCESS_MASK ?
    Flags               DD  ?
    ObjectType          GUID <>
    InheritedObjectType GUID <>
    SidStart            DD  ?
ACCESS_ALLOWED_OBJECT_ACE ENDS

ACCESS_DENIED_OBJECT_ACE STRUCT ALIGNMODE
    Header              ACE_HEADER <>
    _Mask               ACCESS_MASK ?
    Flags               DD  ?
    ObjectType          GUID <>
    InheritedObjectType GUID <>
    SidStart            DD  ?
ACCESS_DENIED_OBJECT_ACE ENDS

SYSTEM_AUDIT_OBJECT_ACE STRUCT ALIGNMODE
    Header              ACE_HEADER <>
    _Mask               ACCESS_MASK ?
    Flags               DD  ?
    ObjectType          GUID <>
    InheritedObjectType GUID <>
    SidStart            DD  ?
SYSTEM_AUDIT_OBJECT_ACE ENDS

SYSTEM_ALARM_OBJECT_ACE STRUCT ALIGNMODE
    Header              ACE_HEADER <>
    _Mask               ACCESS_MASK ?
    Flags               DD  ?
    ObjectType          GUID <>
    InheritedObjectType GUID <>
    SidStart            DD  ?
SYSTEM_ALARM_OBJECT_ACE ENDS

ACCESS_ALLOWED_CALLBACK_ACE STRUCT ALIGNMODE
    Header      ACE_HEADER <>
    _Mask       ACCESS_MASK ?
    SidStart    DD  ?
ACCESS_ALLOWED_CALLBACK_ACE ENDS

ACCESS_DENIED_CALLBACK_ACE STRUCT ALIGNMODE
    Header      ACE_HEADER <>
    _Mask       ACCESS_MASK ?
    SidStart    DD  ?
ACCESS_DENIED_CALLBACK_ACE ENDS

SYSTEM_AUDIT_CALLBACK_ACE STRUCT ALIGNMODE
    Header      ACE_HEADER <>
    _Mask       ACCESS_MASK ?
    SidStart    DD  ?
SYSTEM_AUDIT_CALLBACK_ACE ENDS

SYSTEM_ALARM_CALLBACK_ACE STRUCT ALIGNMODE
    Header      ACE_HEADER <>
    _Mask       ACCESS_MASK ?
    SidStart    DD  ?
SYSTEM_ALARM_CALLBACK_ACE ENDS

ACCESS_ALLOWED_CALLBACK_OBJECT_ACE STRUCT ALIGNMODE
    Header              ACE_HEADER <>
    _Mask               DD  ?
    Flags               DD  ?
    ObjectType          GUID <>
    InheritedObjectType GUID <>
    SidStart            DD  ?
ACCESS_ALLOWED_CALLBACK_OBJECT_ACE ENDS

ACCESS_DENIED_CALLBACK_OBJECT_ACE STRUCT ALIGNMODE
    Header              ACE_HEADER <>
    _Mask               ACCESS_MASK ?
    Flags               DD  ?
    ObjectType          GUID <>
    InheritedObjectType GUID <>
    SidStart            DD  ?
ACCESS_DENIED_CALLBACK_OBJECT_ACE ENDS

SYSTEM_AUDIT_CALLBACK_OBJECT_ACE STRUCT ALIGNMODE
    Header              ACE_HEADER <>
    _Mask               ACCESS_MASK ?
    Flags               DD  ?
    ObjectType          GUID <>
    InheritedObjectType GUID <>
    SidStart            DD  ?
SYSTEM_AUDIT_CALLBACK_OBJECT_ACE ENDS

SYSTEM_ALARM_CALLBACK_OBJECT_ACE STRUCT ALIGNMODE
    Header              ACE_HEADER <>
    _Mask               ACCESS_MASK ?
    Flags               DD  ?
    ObjectType          GUID <>
    InheritedObjectType GUID <>
    SidStart            DD  ?
SYSTEM_ALARM_CALLBACK_OBJECT_ACE ENDS

ACL_REVISION_INFORMATION STRUCT ALIGNMODE
    AclRevision     DD  ?
ACL_REVISION_INFORMATION ENDS

ACL_SIZE_INFORMATION STRUCT ALIGNMODE
    AceCount        DD  ?
    AclBytesInUse   DD  ?
    AclBytesFree    DD  ?
ACL_SIZE_INFORMATION ENDS

SECURITY_DESCRIPTOR_RELATIVE STRUCT ALIGNMODE
    Revision    DB  ?
    Sbz1        DB  ?
    Control     DW  ?
    Owner       DD  ?
    _Group      DD  ?
    Sacl        DD  ?
    Dacl        DD  ?
SECURITY_DESCRIPTOR_RELATIVE ENDS

SECURITY_DESCRIPTOR STRUCT ALIGNMODE
    Revision    DB      ?
    Sbz1        DB      ?
    Control     USHORT  ?
    Owner       DD      ?
    _Group      DD      ?
    Sacl        DD      ?
    Dacl        DD      ?
SECURITY_DESCRIPTOR ENDS

SECURITY_OBJECT_AI_PARAMS STRUCT ALIGNMODE
    _Size           DD  ?
    ConstraintMask  DD  ?
SECURITY_OBJECT_AI_PARAMS ENDS

OBJECT_TYPE_LIST STRUCT ALIGNMODE
    Level       DW  ?
    Sbz         DW  ?
    ObjectType  XPTR ?
OBJECT_TYPE_LIST ENDS

PRIVILEGE_SET STRUCT ALIGNMODE
    PrivilegeCount  DD  ?
    Control         DD  ?
    Privilege       LUID_AND_ATTRIBUTES ANYSIZE_ARRAY DUP(<>)
PRIVILEGE_SET ENDS

ACCESS_REASON                                   TYPEDEF DWORD

ACCESS_REASONS STRUCT ALIGNMODE
    Data    ACCESS_REASON 32 DUP(?)
ACCESS_REASONS ENDS

SE_SECURITY_DESCRIPTOR STRUCT ALIGNMODE
    _Size               DD   ?
    Flags               DD   ?
    SecurityDescriptor  XPTR ?
SE_SECURITY_DESCRIPTOR ENDS

SE_ACCESS_REQUEST STRUCT ALIGNMODE
    _Size                   DD   ?
    SeSecurityDescriptor    XPTR ?
    DesiredAccess           ACCESS_MASK ?
    PreviouslyGrantedAccess ACCESS_MASK ?
    PrincipalSelfSid        XPTR ?
    GenericMapping          XPTR ?
    ObjectTypeListCount     DD   ?
    ObjectTypeList          XPTR ?
SE_ACCESS_REQUEST ENDS

SE_ACCESS_REPLY STRUCT ALIGNMODE
    _Size           DD   ?
    ResultListCount DD   ?
    GrantedAccess   XPTR ?
    AccessStatus    XPTR ?
    AccessReason    XPTR ?
    Privileges      XPTR ?
SE_ACCESS_REPLY ENDS

TOKEN_USER STRUCT ALIGNMODE
    User    SID_AND_ATTRIBUTES <>
TOKEN_USER ENDS

TOKEN_GROUPS STRUCT ALIGNMODE
    GroupCount  DD  ?
    Groups      SID_AND_ATTRIBUTES ANYSIZE_ARRAY DUP(<>)
TOKEN_GROUPS ENDS

TOKEN_PRIVILEGES STRUCT ALIGNMODE
    PrivilegeCount  DD ?
    Privileges      LUID_AND_ATTRIBUTES ANYSIZE_ARRAY DUP(<>)
TOKEN_PRIVILEGES ENDS

TOKEN_OWNER STRUCT ALIGNMODE
    Owner   XPTR ?
TOKEN_OWNER ENDS

TOKEN_PRIMARY_GROUP STRUCT ALIGNMODE
    PrimaryGroup    XPTR ?
TOKEN_PRIMARY_GROUP ENDS

TOKEN_USER_CLAIMS STRUCT ALIGNMODE
    UserClaims  XPTR ?
TOKEN_USER_CLAIMS ENDS

TOKEN_DEVICE_CLAIMS STRUCT ALIGNMODE
    DeviceClaims    XPTR ?
TOKEN_DEVICE_CLAIMS ENDS

TOKEN_GROUPS_AND_PRIVILEGES STRUCT ALIGNMODE
    SidCount            DD  ?
    SidLength           DD  ?
    Sids                XPTR ?
    RestrictedSidCount  DD  ?
    RestrictedSidLength DD  ?
    RestrictedSids      XPTR ?
    PrivilegeCount      DD  ?
    PrivilegeLength     DD  ?
    Privileges          XPTR ?
    AuthenticationId    LUID <>
TOKEN_GROUPS_AND_PRIVILEGES ENDS

TOKEN_LINKED_TOKEN STRUCT ALIGNMODE
    LinkedToken     HANDLE ?
TOKEN_LINKED_TOKEN ENDS

TOKEN_ELEVATION STRUCT ALIGNMODE
    TokenIsElevated DD  ?
TOKEN_ELEVATION ENDS

TOKEN_MANDATORY_LABEL STRUCT ALIGNMODE
    _Label  SID_AND_ATTRIBUTES <>
TOKEN_MANDATORY_LABEL ENDS

TOKEN_MANDATORY_POLICY STRUCT ALIGNMODE
    Policy  DD  ?
TOKEN_MANDATORY_POLICY ENDS

TOKEN_ACCESS_INFORMATION STRUCT ALIGNMODE
    SidHash             XPTR ?
    RestrictedSidHash   XPTR ?
    Privileges          XPTR ?
    AuthenticationId    LUID <>
    _TokenType          DD   ?
    ImpersonationLevel  DD   ?
    MandatoryPolicy     TOKEN_MANDATORY_POLICY <>
    Flags               DD   ?
    AppContainerNumber  DD   ?
    PackageSid          XPTR ?
    CapabilitiesHash    XPTR ?
    TrustLevelSid       XPTR ?
TOKEN_ACCESS_INFORMATION ENDS

TOKEN_DEFAULT_DACL STRUCT ALIGNMODE
    DefaultDacl XPTR ?
TOKEN_DEFAULT_DACL ENDS

TOKEN_AUDIT_POLICY STRUCT ALIGNMODE
    PerUserPolicy   DB  ((POLICY_AUDIT_SUBCATEGORY_COUNT SHR 1) + 1) DUP(?)
TOKEN_AUDIT_POLICY ENDS

TOKEN_SOURCE STRUCT ALIGNMODE
    SourceName       CHAR TOKEN_SOURCE_LENGTH DUP(?)
    SourceIdentifier LUID <>
TOKEN_SOURCE ENDS

TOKEN_STATISTICS STRUCT ALIGNMODE
    TokenId             LUID <>
    AuthenticationId    LUID <>
    ExpirationTime      LARGE_INTEGER <>
    _TokenType          DD  ?
    ImpersonationLevel  DD  ?
    DynamicCharged      DD  ?
    DynamicAvailable    DD  ?
    GroupCount          DD  ?
    PrivilegeCount      DD  ?
    ModifiedId          LUID <>
TOKEN_STATISTICS ENDS

TOKEN_CONTROL STRUCT ALIGNMODE
    TokenId          LUID <>
    AuthenticationId LUID <>
    ModifiedId       LUID <>
    _TokenSource     TOKEN_SOURCE <>
TOKEN_CONTROL ENDS

TOKEN_ORIGIN STRUCT ALIGNMODE
    OriginatingLogonSession LUID <>
TOKEN_ORIGIN ENDS

TOKEN_APPCONTAINER_INFORMATION STRUCT ALIGNMODE
    TokenAppContainer   XPTR ?
TOKEN_APPCONTAINER_INFORMATION ENDS

TOKEN_SID_INFORMATION STRUCT ALIGNMODE
    Sid     XPTR ?
TOKEN_SID_INFORMATION ENDS

SECURITY_QUALITY_OF_SERVICE STRUCT ALIGNMODE
    _Length             DD  ?
    ImpersonationLevel  DD  ?
    ContextTrackingMode SECURITY_CONTEXT_TRACKING_MODE ?
    EffectiveOnly       DB  ?
SECURITY_QUALITY_OF_SERVICE ENDS

SE_IMPERSONATION_STATE STRUCT ALIGNMODE
    Token           XPTR ?
    CopyOnOpen      BOOLEAN ?
    EffectiveOnly   BOOLEAN ?
    Level           DD   ?
SE_IMPERSONATION_STATE ENDS

NT_TIB STRUCT ALIGNMODE
    ExceptionList   XPTR  ?
    StackBase       PVOID ?
    StackLimit      PVOID ?
    SubSystemTib    PVOID ?
    UNION u
        FiberData   PVOID ?
        Version     DD    ?
    ENDS
    ArbitraryUserPointer PVOID ?
    Self            XPTR ?
NT_TIB ENDS

NT_TIB32 STRUCT ALIGNMODE
    ExceptionList   DD  ?
    StackBase       DD  ?
    StackLimit      DD  ?
    SubSystemTib    DD  ?
    UNION u
        FiberData   DD  ?
        Version     DD  ?
    ENDS
    ArbitraryUserPointer DD ?
    Self            DD  ?
NT_TIB32 ENDS

NT_TIB64 STRUCT ALIGNMODE
    ExceptionList   DQ  ?
    StackBase       DQ  ?
    StackLimit      DQ  ?
    SubSystemTib    DQ  ?
    UNION u
        FiberData   DQ  ?
        Version     DD  ?
    ENDS
    ArbitraryUserPointer DQ ?
    Self            DQ  ?
NT_TIB64 ENDS

IFNDEF QUOTA_LIMITS_DEFINED
    QUOTA_LIMITS_DEFINED Equ 1
    QUOTA_LIMITS STRUCT ALIGNMODE
        PagedPoolLimit          SIZE_T  ?
        NonPagedPoolLimit       SIZE_T  ?
        MinimumWorkingSetSize   SIZE_T  ?
        MaximumWorkingSetSize   SIZE_T  ?
        PagefileLimit           SIZE_T  ?
        TimeLimit               LARGE_INTEGER <>
    QUOTA_LIMITS ENDS
ENDIF

RATE_QUOTA_LIMIT UNION ALIGNMODE
    RateData   ULONG ?
    STRUCT s
        RatePercent ULONG ?
        Reserved0   ULONG ?
    ENDS
RATE_QUOTA_LIMIT ENDS

QUOTA_LIMITS_EX STRUCT ALIGNMODE
    PagedPoolLimit          SIZE_T  ?
    NonPagedPoolLimit       SIZE_T  ?
    MinimumWorkingSetSize   SIZE_T  ?
    MaximumWorkingSetSize   SIZE_T  ?
    PagefileLimit           SIZE_T  ?
    TimeLimit               LARGE_INTEGER <>
    WorkingSetLimit         SIZE_T  ?
    Reserved2               SIZE_T  ?
    Reserved3               SIZE_T  ?
    Reserved4               SIZE_T  ?
    Flags                   ULONG   ?
    CpuRateLimit            RATE_QUOTA_LIMIT <>
QUOTA_LIMITS_EX ENDS

IO_COUNTERS STRUCT ALIGNMODE
    ReadOperationCount  ULONGLONG ?
    WriteOperationCount ULONGLONG ?
    OtherOperationCount ULONGLONG ?
    ReadTransferCount   ULONGLONG ?
    WriteTransferCount  ULONGLONG ?
    OtherTransferCount  ULONGLONG ?
IO_COUNTERS ENDS

JOBOBJECT_BASIC_ACCOUNTING_INFORMATION STRUCT ALIGNMODE
    TotalUserTime               LARGE_INTEGER <>
    TotalKernelTime             LARGE_INTEGER <>
    ThisPeriodTotalUserTime     LARGE_INTEGER <>
    ThisPeriodTotalKernelTime   LARGE_INTEGER <>
    TotalPageFaultCount         DD  ?
    TotalProcesses              DD  ?
    ActiveProcesses             DD  ?
    TotalTerminatedProcesses    DD  ?
JOBOBJECT_BASIC_ACCOUNTING_INFORMATION ENDS

JOBOBJECT_BASIC_LIMIT_INFORMATION STRUCT ALIGNMODE
    PerProcessUserTimeLimit LARGE_INTEGER <>
    PerJobUserTimeLimit     LARGE_INTEGER <>
    LimitFlags              DD  ?
    MinimumWorkingSetSize   SIZE_T ?
    MaximumWorkingSetSize   SIZE_T ?
    ActiveProcessLimit      DD  ?
    Affinity                ULONG_PTR ?
    PriorityClass           DD  ?
    SchedulingClass         DD  ?
JOBOBJECT_BASIC_LIMIT_INFORMATION ENDS

JOBOBJECT_EXTENDED_LIMIT_INFORMATION STRUCT ALIGNMODE
    BasicLimitInformation   JOBOBJECT_BASIC_LIMIT_INFORMATION <>
    IoInfo                  IO_COUNTERS <>
    ProcessMemoryLimit      SIZE_T ?
    JobMemoryLimit          SIZE_T ?
    PeakProcessMemoryUsed   SIZE_T ?
    PeakJobMemoryUsed       SIZE_T ?
JOBOBJECT_EXTENDED_LIMIT_INFORMATION ENDS

JOBOBJECT_BASIC_PROCESS_ID_LIST STRUCT ALIGNMODE
    NumberOfAssignedProcesses   DD  ?
    NumberOfProcessIdsInList    DD  ?
    ProcessIdList               ULONG_PTR 1 DUP(?)
JOBOBJECT_BASIC_PROCESS_ID_LIST ENDS

JOBOBJECT_BASIC_UI_RESTRICTIONS STRUCT ALIGNMODE
    UIRestrictionsClass DD  ?
JOBOBJECT_BASIC_UI_RESTRICTIONS ENDS

JOBOBJECT_SECURITY_LIMIT_INFORMATION STRUCT ALIGNMODE
    SecurityLimitFlags  DD   ?
    JobToken            HANDLE ?
    SidsToDisable       XPTR ?
    PrivilegesToDelete  XPTR ?
    RestrictedSids      XPTR ?
JOBOBJECT_SECURITY_LIMIT_INFORMATION ENDS

JOBOBJECT_END_OF_JOB_TIME_INFORMATION STRUCT ALIGNMODE
    EndOfJobTimeAction  DD  ?
JOBOBJECT_END_OF_JOB_TIME_INFORMATION ENDS

JOBOBJECT_ASSOCIATE_COMPLETION_PORT STRUCT ALIGNMODE
    CompletionKey   PVOID ?
    CompletionPort  HANDLE ?
JOBOBJECT_ASSOCIATE_COMPLETION_PORT ENDS

JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION STRUCT ALIGNMODE
    BasicInfo   JOBOBJECT_BASIC_ACCOUNTING_INFORMATION <>
    IoInfo      IO_COUNTERS <>
JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION ENDS

CACHE_DESCRIPTOR STRUCT ALIGNMODE
    Level           DB  ?
    Associativity   DB  ?
    LineSize        DW  ?
    _Size           DD  ?
    _Type           DD  ?
CACHE_DESCRIPTOR ENDS

SYSTEM_LOGICAL_PROCESSOR_INFORMATION STRUCT ALIGNMODE
    ProcessorMask       ULONG_PTR ?
    Relationship        DD  ?
    UNION u
        STRUCT ProcessorCore
            Flags       DB  ?
        ENDS
        STRUCT NumaNode
            NodeNumber  DD  ?
        ENDS
        Cache           CACHE_DESCRIPTOR <>
        Reserved        ULONGLONG 2 DUP(?)
    ENDS
SYSTEM_LOGICAL_PROCESSOR_INFORMATION ENDS

IFNDEF MEMORY_BASIC_INFORMATION_DEFINED
	MEMORY_BASIC_INFORMATION_DEFINED EQU 1
	MEMORY_BASIC_INFORMATION STRUCT ALIGNMODE
		BaseAddress         XPTR ?
		AllocationBase      XPTR ?
		AllocationProtect   DD   ?
		RegionSize          XPTR ?
		State               DD   ?
		Protect             DD   ?
		_Type               DD   ?
	MEMORY_BASIC_INFORMATION ENDS
ENDIF

MEMORY_BASIC_INFORMATION32 STRUCT ALIGNMODE
    BaseAddress         DD  ?
    AllocationBase      DD  ?
    AllocationProtect   DD  ?
    RegionSize          DD  ?
    State               DD  ?
    Protect             DD  ?
    _Type               DD  ?
MEMORY_BASIC_INFORMATION32 ENDS

MEMORY_BASIC_INFORMATION64 STRUCT ALIGNMODE
    BaseAddress         ULONGLONG ?
    AllocationBase      ULONGLONG ?
    AllocationProtect   DD  ?
    __alignment1        DD  ?
    RegionSize          ULONGLONG ?
    State               DD  ?
    Protect             DD  ?
    _Type               DD  ?
    __alignment2        DD  ?
MEMORY_BASIC_INFORMATION64 ENDS

FILE_NOTIFY_INFORMATION STRUCT ALIGNMODE
    NextEntryOffset DD  ?
    Action          DD  ?
    FileNameLength  DD  ?
    FileName        WCHAR 1 DUP(?)
FILE_NOTIFY_INFORMATION ENDS

FILE_SEGMENT_ELEMENT UNION ALIGNMODE
    Buffer      XPTR ?
    Alignment   ULONGLONG ?
FILE_SEGMENT_ELEMENT ENDS

GREPBUF STRUCT ALIGNMODE
    DataBuffer  XPTR ?
GREPBUF ENDS

REPARSE_GUID_DATA_BUFFER STRUCT ALIGNMODE
    ReparseTag           DD ?
    ReparseDataLength    DW ?
    Reserved             DW ?
    ReparseGuid          GUID <>
    GenericReparseBuffer GREPBUF <>
REPARSE_GUID_DATA_BUFFER ENDS

CM_POWER_DATA STRUCT ALIGNMODE
    PD_Size                 ULONG ?
    PD_MostRecentPowerState DD    ?
    PD_Capabilities         ULONG ?
    PD_D1Latency            ULONG ?
    PD_D2Latency            ULONG ?
    PD_D3Latency            ULONG ?
    PD_PowerStateMapping    DD POWER_SYSTEM_MAXIMUM DUP(?)
    PD_DeepestSystemWake    DD    ?
CM_POWER_DATA ENDS

PO_TRANSITION_VETO_REASON STRUCT ALIGNMODE
    ResourceId       DD ?
    ModuleNameOffset DD ?
PO_TRANSITION_VETO_REASON ENDS

PO_TRANSITION_VETO_WINDOW STRUCT ALIGNMODE
    Handle  HANDLE ?
PO_TRANSITION_VETO_WINDOW ENDS

PO_TRANSITION_VETO_SERVICE STRUCT ALIGNMODE
    ServiceNameOffset   DD  ?
PO_TRANSITION_VETO_SERVICE ENDS

PO_TRANSITION_VETO_DRIVER STRUCT ALIGNMODE
    InstancePathOffset  DD  ?
    DriverNameOffset    DD  ?
PO_TRANSITION_VETO_DRIVER ENDS

PO_TRANSITION_VETO STRUCT ALIGNMODE
    _Type       DD  ?
    Reason      PO_TRANSITION_VETO_REASON <>
    ProcessId   DD  ?
    UNION u
        Window  PO_TRANSITION_VETO_WINDOW <>
        Service PO_TRANSITION_VETO_SERVICE <>
        Driver  PO_TRANSITION_VETO_DRIVER <>
    ENDS
PO_TRANSITION_VETO ENDS

PO_TRANSITION_VETOES STRUCT ALIGNMODE
    Count   DD  ?
    Vetoes  PO_TRANSITION_VETO ANYSIZE_ARRAY DUP(<>)
PO_TRANSITION_VETOES ENDS

SET_POWER_SETTING_VALUE STRUCT ALIGNMODE
    Version         ULONG ?
    Guid            GUID  <>
    PowerCondition  DD    ?
    DataLength      ULONG ?
    Data            UCHAR ANYSIZE_ARRAY DUP(?)
SET_POWER_SETTING_VALUE ENDS

NOTIFY_USER_POWER_SETTING STRUCT ALIGNMODE
    Guid    GUID <>
NOTIFY_USER_POWER_SETTING ENDS

APPLICATIONLAUNCH_SETTING_VALUE STRUCT ALIGNMODE
    ActivationTime   LARGE_INTEGER <>
    Flags            ULONG ?
    ButtonInstanceID ULONG ?
APPLICATIONLAUNCH_SETTING_VALUE ENDS

PO_WAKE_SOURCE_HEADER STRUCT ALIGNMODE
    _Type   ENUM  ?
    _Size   ULONG ?
PO_WAKE_SOURCE_HEADER ENDS

PO_WAKE_SOURCE_DEVICE STRUCT ALIGNMODE
    Header       PO_WAKE_SOURCE_HEADER <>
    InstancePath WCHAR ?
PO_WAKE_SOURCE_DEVICE ENDS

PO_WAKE_SOURCE_FIXED STRUCT ALIGNMODE
    Header              PO_WAKE_SOURCE_HEADER <>
    FixedWakeSourceType ENUM ?
PO_WAKE_SOURCE_FIXED ENDS

PO_WAKE_SOURCE_INFO STRUCT ALIGNMODE
    Count   ULONG ?
    Offsets ULONG ?
PO_WAKE_SOURCE_INFO ENDS

PO_WAKE_SOURCE_HISTORY STRUCT ALIGNMODE
    Count   ULONG ?
    Offsets ULONG ?
PO_WAKE_SOURCE_HISTORY ENDS

BATTERY_REPORTING_SCALE STRUCT ALIGNMODE
    Granularity ULONG ?
    Capacity    ULONG ?
BATTERY_REPORTING_SCALE ENDS

PPM_SIMULATED_PROCESSOR_LOAD STRUCT ALIGNMODE
    Enabled     BOOLEAN ?
    PercentBusy UCHAR MAXIMUM_PROCESSORS DUP(?)
PPM_SIMULATED_PROCESSOR_LOAD ENDS

PPM_WMI_LEGACY_PERFSTATE STRUCT ALIGNMODE
    Frequency        ULONG ?
    Flags            ULONG ?
    PercentFrequency ULONG ?
PPM_WMI_LEGACY_PERFSTATE ENDS

PPM_WMI_IDLE_STATE STRUCT ALIGNMODE
    Latency         ULONG ?
    Power           ULONG ?
    TimeCheck       ULONG ?
    PromotePercent  ULONG ?
    DemotePercent   ULONG ?
    StateType       ULONG ?
    Reserved        ULONG ?
    StateFlags      ULONG ?
    Context         ULONG ?
    IdleHandler     ULONG ?
    Reserved1       ULONG ?
PPM_WMI_IDLE_STATE ENDS

PPM_WMI_IDLE_STATES STRUCT ALIGNMODE
    _Type            ULONG   ?
    Count            ULONG   ?
    TargetState      ULONG   ?
    OldState         ULONG   ?
    TargetProcessors ULONG64 ?
    State            PPM_WMI_IDLE_STATE ANYSIZE_ARRAY DUP(<>)
PPM_WMI_IDLE_STATES ENDS

PPM_WMI_PERF_STATE STRUCT ALIGNMODE
    Frequency        ULONG   ?
    Power            ULONG   ?
    PercentFrequency UCHAR   ?
    IncreaseLevel    UCHAR   ?
    DecreaseLevel    UCHAR   ?
    _Type            UCHAR   ?
    IncreaseTime     ULONG   ?
    DecreaseTime     ULONG   ?
    Control          ULONG64 ?
    Status           ULONG64 ?
    HitCount         ULONG   ?
    Reserved1        ULONG   ?
    Reserved2        ULONG64 ?
    Reserved3        ULONG64 ?
PPM_WMI_PERF_STATE ENDS

PPM_WMI_PERF_STATES STRUCT ALIGNMODE
    Count               ULONG   ?
    MaxFrequency        ULONG   ?
    CurrentState        ULONG   ?
    MaxPerfState        ULONG   ?
    MinPerfState        ULONG   ?
    LowestPerfState     ULONG   ?
    ThermalConstraint   ULONG   ?
    BusyAdjThreshold    UCHAR   ?
    PolicyType          UCHAR   ?
    _Type               UCHAR   ?
    Reserved            UCHAR   ?
    TimerInterval       ULONG   ?
    TargetProcessors    ULONG64 ?
    PStateHandler       ULONG   ?
    PStateContext       ULONG   ?
    TStateHandler       ULONG   ?
    TStateContext       ULONG   ?
    FeedbackHandler     ULONG   ?
    Reserved1           ULONG   ?
    Reserved2           ULONG64 ?
    State               PPM_WMI_PERF_STATE ANYSIZE_ARRAY DUP(<>)
PPM_WMI_PERF_STATES ENDS

PPM_IDLE_STATE_ACCOUNTING STRUCT ALIGNMODE
    IdleTransitions     ULONG   ?
    FailedTransitions   ULONG   ?
    InvalidBucketIndex  ULONG   ?
    TotalTime           ULONG64 ?
    IdleTimeBuckets     ULONG   PROC_IDLE_BUCKET_COUNT DUP(?)
PPM_IDLE_STATE_ACCOUNTING ENDS

PPM_IDLE_ACCOUNTING STRUCT ALIGNMODE
    StateCount          ULONG   ?
    TotalTransitions    ULONG   ?
    ResetCount          ULONG   ?
    StartTime           ULONG64 ?
    State               PPM_IDLE_STATE_ACCOUNTING ANYSIZE_ARRAY DUP(<>)
PPM_IDLE_ACCOUNTING ENDS

PPM_PERFSTATE_EVENT STRUCT ALIGNMODE
    State       ULONG ?
    Status      ULONG ?
    Latency     ULONG ?
    Speed       ULONG ?
    Processor   ULONG ?
PPM_PERFSTATE_EVENT ENDS

PPM_PERFSTATE_DOMAIN_EVENT STRUCT ALIGNMODE
    State       ULONG   ?
    Latency     ULONG   ?
    Speed       ULONG   ?
    Processors  ULONG64 ?
PPM_PERFSTATE_DOMAIN_EVENT ENDS

PPM_IDLESTATE_EVENT STRUCT ALIGNMODE
    NewState    ULONG   ?
    OldState    ULONG   ?
    Processors  ULONG64 ?
PPM_IDLESTATE_EVENT ENDS

PPM_THERMALCHANGE_EVENT STRUCT ALIGNMODE
    ThermalConstraint   ULONG   ?
    Processors          ULONG64 ?
PPM_THERMALCHANGE_EVENT ENDS

PPM_THERMAL_POLICY_EVENT STRUCT ALIGNMODE
    Mode        UCHAR   ?
    Processors  ULONG64 ?
PPM_THERMAL_POLICY_EVENT ENDS

POWER_ACTION_POLICY STRUCT ALIGNMODE
    Action      ENUM  ?
    Flags       ULONG ?
    EventCode   ULONG ?
POWER_ACTION_POLICY ENDS

SYSTEM_POWER_LEVEL STRUCT ALIGNMODE
    Enable          BOOLEAN ?
    Spare           UCHAR 3 DUP(?)
    BatteryLevel    ULONG ?
    PowerPolicy     POWER_ACTION_POLICY <>
    MinSystemState  ENUM  ?
SYSTEM_POWER_LEVEL ENDS

SYSTEM_POWER_POLICY STRUCT ALIGNMODE
    Revision            ULONG   ?
    PowerButton         POWER_ACTION_POLICY <>
    SleepButton         POWER_ACTION_POLICY <>
    LidClose            POWER_ACTION_POLICY <>
    LidOpenWake         ENUM    ?
    Reserved            ULONG   ?
    Idle                POWER_ACTION_POLICY <>
    IdleTimeout         ULONG   ?
    IdleSensitivity     UCHAR   ?
    DynamicThrottle     UCHAR   ?
    Spare2              UCHAR   2 DUP(?)
    MinSleep            ENUM    ?
    MaxSleep            ENUM    ?
    ReducedLatencySleep ENUM    ?
    WinLogonFlags       ULONG   ?
    Spare3              ULONG   ?
    DozeS4Timeout       ULONG   ?
    BroadcastCapacityResolution ULONG ?
    DischargePolicy     SYSTEM_POWER_LEVEL NUM_DISCHARGE_POLICIES DUP(<>)
    VideoTimeout        ULONG   ?
    VideoDimDisplay     BOOLEAN ?
    VideoReserved       ULONG   3 DUP(?)
    SpindownTimeout     ULONG   ?
    OptimizeForPower    BOOLEAN ?
    FanThrottleTolerance UCHAR  ?
    ForcedThrottle      UCHAR   ?
    MinThrottle         UCHAR   ?
    OverThrottled       POWER_ACTION_POLICY <>
SYSTEM_POWER_POLICY ENDS

PROCESSOR_IDLESTATE_INFO STRUCT ALIGNMODE
    TimeCheck       ULONG ?
    DemotePercent   UCHAR ?
    PromotePercent  UCHAR ?
    Spare           UCHAR 2 DUP(?)
PROCESSOR_IDLESTATE_INFO ENDS

PROCESSOR_IDLESTATE_POLICY STRUCT ALIGNMODE
    Revision       UINT16 ?
    UNION Flags
        AsWORD     UINT16 ?
        STRUCT s
            AllowScaling DW ?
            Disabled     DW ? 
            Reserved     DW ?
        ENDS
    ENDS
    PolicyCount    ULONG32 ?
    Policy         PROCESSOR_IDLESTATE_INFO PROCESSOR_IDLESTATE_POLICY_COUNT DUP(<>)
PROCESSOR_IDLESTATE_POLICY ENDS

PROCESSOR_POWER_POLICY_INFO STRUCT ALIGNMODE
    TimeCheck       ULONG ?
    DemoteLimit     ULONG ?
    PromoteLimit    ULONG ?
    DemotePercent   UCHAR ?
    PromotePercent  UCHAR ?
    Spare           UCHAR 2 DUP(?)
    Reserved        ULONG ?
    AllowPromotion  ULONG ?
    AllowDemotion   ULONG ?
PROCESSOR_POWER_POLICY_INFO ENDS

PROCESSOR_POWER_POLICY STRUCT ALIGNMODE
    Revision        DD  ?
    DynamicThrottle DB  ?
    Spare           DB  3 DUP(?)
    DisableCStates  DD  ?
    Reserved        DD  ?
    PolicyCount     DD  ?
    Policy          PROCESSOR_POWER_POLICY_INFO 3 DUP(<>)
PROCESSOR_POWER_POLICY ENDS

PROCESSOR_PERFSTATE_POLICY STRUCT ALIGNMODE
    Revision            ULONG32 ?
    MaxThrottle         DB      ?
    MinThrottle         DB      ?
    BusyAdjThreshold    DB      ?
    UNION u
        Spare           DB      ?
        UNION Flags
            AsBYTE      DB      ?
            STRUCT s
                NoDomainAccounting UINT8 ?
                IncreasePolicy     UINT8 ?
                DecreasePolicy     UINT8 ?
                Reserved           UINT8 ?
            ENDS
        ENDS
    ENDS
    TimeCheck           ULONG32 ?
    IncreaseTime        ULONG32 ?
    DecreaseTime        ULONG32 ?
    IncreasePercent     ULONG32 ?
    DecreasePercent     ULONG32 ?
PROCESSOR_PERFSTATE_POLICY ENDS

ADMINISTRATOR_POWER_POLICY STRUCT ALIGNMODE
    MinSleep            ENUM  ?
    MaxSleep            ENUM  ?
    MinVideoTimeout     ULONG ?
    MaxVideoTimeout     ULONG ?
    MinSpindownTimeout  ULONG ?
    MaxSpindownTimeout  ULONG ?
ADMINISTRATOR_POWER_POLICY ENDS

SYSTEM_POWER_CAPABILITIES STRUCT ALIGNMODE
    PowerButtonPresent      BOOLEAN ?
    SleepButtonPresent      BOOLEAN ?
    LidPresent              BOOLEAN ?
    SystemS1                BOOLEAN ?
    SystemS2                BOOLEAN ?
    SystemS3                BOOLEAN ?
    SystemS4                BOOLEAN ?
    SystemS5                BOOLEAN ?
    HiberFilePresent        BOOLEAN ?
    FullWake                BOOLEAN ?
    VideoDimPresent         BOOLEAN ?
    ApmPresent              BOOLEAN ?
    UpsPresent              BOOLEAN ?
    ThermalControl          BOOLEAN ?
    ProcessorThrottle       BOOLEAN ?
    ProcessorMinThrottle    BYTE    ?
    ProcessorMaxThrottle    BYTE    ?
    HiberBoot               BOOLEAN ?
    WakeAlarmPresent        BOOLEAN ?
    AoAc                    BOOLEAN ?
    DiskSpinDown            BOOLEAN ?
    spare3                  BYTE    8 DUP(?)
    SystemBatteriesPresent  BOOLEAN ?
    BatteriesAreShortTerm   BOOLEAN ?
    BatteryScale            BATTERY_REPORTING_SCALE 3 DUP(<>)
    AcOnLineWake            ENUM    ?
    SoftLidWake             ENUM    ?
    RtcWake                 ENUM    ?
    MinDeviceWakeState      ENUM    ?
    DefaultLowLatencyWake   ENUM    ?
SYSTEM_POWER_CAPABILITIES ENDS

SYSTEM_BATTERY_STATE STRUCT ALIGNMODE
    AcOnLine          BOOLEAN ?  
    BatteryPresent    BOOLEAN ?
    Charging          BOOLEAN ?
    Discharging       BOOLEAN ?
    Spare1            BOOLEAN 4 DUP(?)
    MaxCapacity       DD ?
    RemainingCapacity DD ?
    Rate              DD ?
    EstimatedTime     DD ?
    DefaultAlert1     DD ?
    DefaultAlert2     DD ?
SYSTEM_BATTERY_STATE ENDS

IMAGE_DOS_HEADER STRUCT ALIGNMODE
    e_magic     DW   ?
    e_cblp      DW   ?
    e_cp        DW   ?
    e_crlc      DW   ?
    e_cparhdr   DW   ?
    e_minalloc  DW   ?
    e_maxalloc  DW   ?
    e_ss        DW   ?
    e_sp        DW   ?
    e_csum      DW   ?
    e_ip        DW   ?
    e_cs        DW   ?
    e_lfarlc    DW   ?
    e_ovno      DW   ?
    e_res       DW   4 DUP(?)
    e_oemid     DW   ?
    e_oeminfo   DW   ?
    e_res2      DW   10 DUP(?)
    e_lfanew    LONG ?
IMAGE_DOS_HEADER ENDS

IMAGE_OS2_HEADER STRUCT ALIGNMODE
    ne_magic        DW   ?
    ne_ver          DB   ?
    ne_rev          DB   ?
    ne_enttab       DW   ?
    ne_cbenttab     DW   ?
    ne_crc          LONG ?
    ne_flags        DW   ?
    ne_autodata     DW   ?
    ne_heap         DW   ?
    ne_stack        DW   ?
    ne_csip         DD   ?
    ne_sssp         DD   ?
    ne_cseg         DW   ?
    ne_cmod         DW   ?
    ne_cbnrestab    DW   ?
    ne_segtab       DW   ?
    ne_rsrctab      DW   ?
    ne_restab       DW   ?
    ne_modtab       DW   ?
    ne_imptab       DW   ?
    ne_nrestab      DD   ?
    ne_cmovent      DW   ?
    ne_align        DW   ?
    ne_cres         DW   ?
    ne_exetyp       DB   ?
    ne_flagsothers  DB   ?
    ne_pretthunks   DW   ?
    ne_psegrefbytes DW   ?
    ne_swaparea     DW   ?
    ne_expver       DW   ?
IMAGE_OS2_HEADER ENDS

IMAGE_VXD_HEADER STRUCT ALIGNMODE
    e32_magic           DW  ?
    e32_border          DB  ?
    e32_worder          DB  ?
    e32_level           DD  ?
    e32_cpu             DW  ?
    e32_os              DW  ?
    e32_ver             DD  ?
    e32_mflags          DD  ?
    e32_mpages          DD  ?
    e32_startobj        DD  ?
    e32_eip             DD  ?
    e32_stackobj        DD  ?
    e32_esp             DD  ?
    e32_pagesize        DD  ?
    e32_lastpagesize    DD  ?
    e32_fixupsize       DD  ?
    e32_fixupsum        DD  ?
    e32_ldrsize         DD  ?
    e32_ldrsum          DD  ?
    e32_objtab          DD  ?
    e32_objcnt          DD  ?
    e32_objmap          DD  ?
    e32_itermap         DD  ?
    e32_rsrctab         DD  ?
    e32_rsrccnt         DD  ?
    e32_restab          DD  ?
    e32_enttab          DD  ?
    e32_dirtab          DD  ?
    e32_dircnt          DD  ?
    e32_fpagetab        DD  ?
    e32_frectab         DD  ?
    e32_impmod          DD  ?
    e32_impmodcnt       DD  ?
    e32_impproc         DD  ?
    e32_pagesum         DD  ?
    e32_datapage        DD  ?
    e32_preload         DD  ?
    e32_nrestab         DD  ?
    e32_cbnrestab       DD  ?
    e32_nressum         DD  ?
    e32_autodata        DD  ?
    e32_debuginfo       DD  ?
    e32_debuglen        DD  ?
    e32_instpreload     DD  ?
    e32_instdemand      DD  ?
    e32_heapsize        DD  ?
    e32_res3            DB  12 DUP(?)
    e32_winresoff       DD  ?
    e32_winreslen       DD  ?
    e32_devid           DW  ?
    e32_ddkver          DW  ?
IMAGE_VXD_HEADER ENDS

IMAGE_FILE_HEADER STRUCT ALIGNMODE
    Machine              DW ?
    NumberOfSections     DW ?
    TimeDateStamp        DD ?
    PointerToSymbolTable DD ?
    NumberOfSymbols      DD ?
    SizeOfOptionalHeader DW ?
    Characteristics      DW ?
IMAGE_FILE_HEADER ENDS

IMAGE_DATA_DIRECTORY STRUCT ALIGNMODE
    VirtualAddress  DD  ?
    _Size           DD  ?
IMAGE_DATA_DIRECTORY ENDS

IMAGE_NUMBEROF_DIRECTORY_ENTRIES                EQU     16

IMAGE_OPTIONAL_HEADER32 STRUCT ALIGNMODE
    Magic                       DW  ?
    MajorLinkerVersion          DB  ?
    MinorLinkerVersion          DB  ?
    SizeOfCode                  DD  ?
    SizeOfInitializedData       DD  ?
    SizeOfUninitializedData     DD  ?
    AddressOfEntryPoint         DD  ?
    BaseOfCode                  DD  ?
    BaseOfData                  DD  ?
    ImageBase                   DD  ?
    SectionAlignment            DD  ?
    FileAlignment               DD  ?
    MajorOperatingSystemVersion DW  ?
    MinorOperatingSystemVersion DW  ?
    MajorImageVersion           DW  ?
    MinorImageVersion           DW  ?
    MajorSubsystemVersion       DW  ?
    MinorSubsystemVersion       DW  ?
    Win32VersionValue           DD  ?
    SizeOfImage                 DD  ?
    SizeOfHeaders               DD  ?
    CheckSum                    DD  ?
    Subsystem                   DW  ?
    DllCharacteristics          DW  ?
    SizeOfStackReserve          DD  ?
    SizeOfStackCommit           DD  ?
    SizeOfHeapReserve           DD  ?
    SizeOfHeapCommit            DD  ?
    LoaderFlags                 DD  ?
    NumberOfRvaAndSizes         DD  ?
    DataDirectory               IMAGE_DATA_DIRECTORY IMAGE_NUMBEROF_DIRECTORY_ENTRIES DUP(<>)
IMAGE_OPTIONAL_HEADER32 ENDS

IMAGE_OPTIONAL_HEADER64 STRUCT ALIGNMODE
    Magic                       DW        ?
    MajorLinkerVersion          DB        ?
    MinorLinkerVersion          DB        ?
    SizeOfCode                  DD        ?
    SizeOfInitializedData       DD        ?
    SizeOfUninitializedData     DD        ?
    AddressOfEntryPoint         DD        ?
    BaseOfCode                  DD        ?
    ImageBase                   ULONGLONG ?
    SectionAlignment            DD        ?
    FileAlignment               DD        ?
    MajorOperatingSystemVersion DW        ?
    MinorOperatingSystemVersion DW        ?
    MajorImageVersion           DW        ?
    MinorImageVersion           DW        ?
    MajorSubsystemVersion       DW        ?
    MinorSubsystemVersion       DW        ?
    Win32VersionValue           DD        ?
    SizeOfImage                 DD        ?
    SizeOfHeaders               DD        ?
    CheckSum                    DD        ?
    Subsystem                   DW        ?
    DllCharacteristics          DW        ?
    SizeOfStackReserve          ULONGLONG ?
    SizeOfStackCommit           ULONGLONG ?
    SizeOfHeapReserve           ULONGLONG ?
    SizeOfHeapCommit            ULONGLONG ?
    LoaderFlags                 DD        ?
    NumberOfRvaAndSizes         DD        ?
    DataDirectory               IMAGE_DATA_DIRECTORY IMAGE_NUMBEROF_DIRECTORY_ENTRIES DUP(<>)
IMAGE_OPTIONAL_HEADER64 ENDS

IMAGE_ROM_OPTIONAL_HEADER STRUCT ALIGNMODE
    Magic                   DW  ?
    MajorLinkerVersion      DB  ?
    MinorLinkerVersion      DB  ?
    SizeOfCode              DD  ?
    SizeOfInitializedData   DD  ?
    SizeOfUninitializedData DD  ?
    AddressOfEntryPoint     DD  ?
    BaseOfCode              DD  ?
    BaseOfData              DD  ?
    BaseOfBss               DD  ?
    GprMask                 DD  ?
    CprMask                 DD  4 DUP(?)
    GpValue                 DD  ?
IMAGE_ROM_OPTIONAL_HEADER ENDS

IMAGE_NT_HEADERS32 STRUCT ALIGNMODE
    Signature       DD  ?
    FileHeader      IMAGE_FILE_HEADER <> 
    OptionalHeader  IMAGE_OPTIONAL_HEADER32 <> 
IMAGE_NT_HEADERS32 ENDS

IMAGE_NT_HEADERS64 STRUCT ALIGNMODE
    Signature       DD  ?
    FileHeader      IMAGE_FILE_HEADER <>
    OptionalHeader  IMAGE_OPTIONAL_HEADER64 <>
IMAGE_NT_HEADERS64 ENDS

IMAGE_NT_HEADERS STRUCT ALIGNMODE
    Signature       DD  ?
    FileHeader      IMAGE_FILE_HEADER <>
    OptionalHeader  IMAGE_OPTIONAL_HEADER32 <>
IMAGE_NT_HEADERS ENDS

IMAGE_ROM_HEADERS STRUCT ALIGNMODE
    FileHeader      IMAGE_FILE_HEADER <>
    OptionalHeader  IMAGE_ROM_OPTIONAL_HEADER <>
IMAGE_ROM_HEADERS ENDS

ANON_OBJECT_HEADER STRUCT ALIGNMODE
    Sig1            USHORT ?
    Sig2            USHORT ?
    Version         USHORT ?
    Machine         USHORT ?
    TimeDateStamp   UINT   ?
    ClassID         GUID   <>
    SizeOfData      UINT   ?
ANON_OBJECT_HEADER ENDS

ANON_OBJECT_HEADER_V2 STRUCT ALIGNMODE
    Sig1            USHORT ?
    Sig2            USHORT ?
    Version         USHORT ?
    Machine         USHORT ?
    TimeDateStamp   UINT   ?
    ClassID         GUID <>
    SizeOfData      UINT   ?
    Flags           UINT   ?
    MetaDataSize    UINT   ?
    MetaDataOffset  UINT   ?
ANON_OBJECT_HEADER_V2 ENDS

IMAGE_SECTION_HEADER STRUCT ALIGNMODE
    _Name                DB  IMAGE_SIZEOF_SHORT_NAME DUP(?)
    UNION Misc
        PhysicalAddress  DD  ?
        VirtualSize      DD  ?
    ENDS
    VirtualAddress       DD  ?
    SizeOfRawData        DD  ?
    PointerToRawData     DD  ?
    PointerToRelocations DD  ?
    PointerToLinenumbers DD  ?
    NumberOfRelocations  DW  ?
    NumberOfLinenumbers  DW  ?
    Characteristics      DD  ?
IMAGE_SECTION_HEADER ENDS

IMAGE_SYMBOL STRUCT ALIGNMODE
    UNION N
        ShortName       UINT8  8 DUP(?)
        STRUCT _Name
            _Short      DD     ?
            Long        DD     ?
        ENDS
        LongName        XPTR   2 DUP(?)
    ENDS
    Value               UINT32 ?
    SectionNumber       INT16  ?
    _Type               UINT16 ?
    StorageClass        UINT8  ?
    NumberOfAuxSymbols  UINT8  ?
IMAGE_SYMBOL ENDS

IMAGE_AUX_SYMBOL UNION ALIGNMODE
    STRUCT Sym
        TagIndex            UINT32  ?
        UNION Misc
            STRUCT LnSz
                Linenumber  UINT16  ?
                _Size       UINT16  ?
            ENDS
            TotalSize       UINT32  ?
        ENDS
        UNION Function
            STRUCT Function
                PointerToLinenumber   UINT32  ?
                PointerToNextFunction UINT32  ?
            ENDS
            STRUCT Array
                Dimension   UINT16  4 DUP(?)
            ENDS
        ENDS
        TvIndex             UINT16  ?
    ENDS
    STRUCT File
        _Name               UINT8   IMAGE_SIZEOF_SYMBOL DUP(?)
    ENDS
    STRUCT Section
        _Length             UINT32  ?
        NumberOfRelocations UINT16  ?
        NumberOfLinenumbers UINT16  ?
        CheckSum            UINT32  ?
        Number              DW      ?
        Selection           BYTE    ?
    ENDS
IMAGE_AUX_SYMBOL ENDS

IMAGE_AUX_SYMBOL_TOKEN_DEF STRUCT ALIGNMODE
    bAuxType            DB  ?
    bReserved           DB  ?
    SymbolTableIndex    DD  ?
    rgbReserved         DB  12 DUP(?)
IMAGE_AUX_SYMBOL_TOKEN_DEF ENDS

IMAGE_RELOCATION STRUCT ALIGNMODE
    UNION u
        VirtualAddress  UINT32 ?
        RelocCount      UINT32 ?
    ENDS
    SymbolTableIndex    UINT32 ?
    _Type               UINT16 ?
IMAGE_RELOCATION ENDS

IMAGE_LINENUMBER STRUCT ALIGNMODE
    UNION _Type
        SymbolTableIndex    DD  ?
        VirtualAddress      DD  ?
    ENDS
    Linenumber              DW  ?
IMAGE_LINENUMBER ENDS

IMAGE_BASE_RELOCATION STRUCT ALIGNMODE
    VirtualAddress  DD  ?
    SizeOfBlock     DD  ?
    TypeOffset      DW  1 DUP(?)  
IMAGE_BASE_RELOCATION ENDS

IMAGE_ARCHIVE_MEMBER_HEADER STRUCT ALIGNMODE
    _Name       DB  16 DUP(?)
    _Date       DB  12 DUP(?)
    UserID      DB  6  DUP(?)
    GroupID     DB  6  DUP(?)
    Mode        DB  8  DUP(?)
    _Size       DB  10 DUP(?)
    EndHeader   DB  2  DUP(?)
IMAGE_ARCHIVE_MEMBER_HEADER ENDS

IMAGE_EXPORT_DIRECTORY STRUCT ALIGNMODE
    Characteristics         DD      ?
    TimeDateStamp           DD      ?
    MajorVersion            DW      ?
    MinorVersion            DW      ?
    _Name                   DD      ?
    Base                    DD      ?
    NumberOfFunctions       DD      ?
    NumberOfNames           DD      ?
    AddressOfFunctions      DD      ?
    AddressOfNames          DD      ?
    AddressOfNameOrdinals   DD      ?
IMAGE_EXPORT_DIRECTORY ENDS

IMAGE_IMPORT_BY_NAME STRUCT ALIGNMODE
    Hint    DW  ?
    _Name   DB  ?
IMAGE_IMPORT_BY_NAME ENDS

IMAGE_THUNK_DATA64 STRUCT ALIGNMODE
    UNION u1
        ForwarderString LPBYTE ?
        Function        XPTR   ?
        Ordinal         DD     ?
        AddressOfData   XPTR   ?
    ENDS
IMAGE_THUNK_DATA64 ENDS

IMAGE_THUNK_DATA32 STRUCT ALIGNMODE
    UNION u1
        ForwarderString LPBYTE ?
        Function        XPTR   ?
        Ordinal         DQ     ?
        AddressOfData   XPTR   ?
    ENDS
IMAGE_THUNK_DATA32 ENDS

IMAGE_TLS_DIRECTORY32 STRUCT ALIGNMODE
    StartAddressOfRawData   DD  ?
    EndAddressOfRawData     DD  ?
    AddressOfIndex          DD  ?
    AddressOfCallBacks      DD  ?
    SizeOfZeroFill          DD  ?
    Characteristics         DD  ?
IMAGE_TLS_DIRECTORY32 ENDS

IMAGE_TLS_DIRECTORY64 STRUCT ALIGNMODE
    StartAddressOfRawData   DQ  ?
    EndAddressOfRawData     DQ  ?
    AddressOfIndex          DQ  ?
    AddressOfCallBacks      DQ  ?
    SizeOfZeroFill          DD  ?
    Characteristics         DD  ?
IMAGE_TLS_DIRECTORY64 ENDS

IFDEF APP_WIN64
    IMAGE_ORDINAL_FLAG                          EQU     IMAGE_ORDINAL_FLAG64
    IMAGE_THUNK_DATA                            TYPEDEF IMAGE_THUNK_DATA64
    IMAGE_TLS_DIRECTORY                         TYPEDEF IMAGE_TLS_DIRECTORY64
ELSE
    IMAGE_ORDINAL_FLAG                          EQU     IMAGE_ORDINAL_FLAG32
    IMAGE_THUNK_DATA                            TYPEDEF IMAGE_THUNK_DATA32
    IMAGE_TLS_DIRECTORY                         TYPEDEF IMAGE_TLS_DIRECTORY32
ENDIF 

IMAGE_IMPORT_DESCRIPTOR STRUCT ALIGNMODE
    UNION u
        Characteristics     DD   ?
        OriginalFirstThunk  XPTR ?
    ENDS
    TimeDateStamp           DD   ?
    ForwarderChain          DD   ?
    _Name                   DD   ?
    FirstThunk              XPTR ?
IMAGE_IMPORT_DESCRIPTOR ENDS

IMAGE_BOUND_IMPORT_DESCRIPTOR STRUCT ALIGNMODE
    TimeDateStamp               DD  ?
    OffsetModuleName            DW  ?
    NumberOfModuleForwarderRefs DW  ?
IMAGE_BOUND_IMPORT_DESCRIPTOR ENDS

IMAGE_BOUND_FORWARDER_REF STRUCT ALIGNMODE
    TimeDateStamp       DD  ?
    OffsetModuleName    DW  ?
    Reserved            DW  ?
IMAGE_BOUND_FORWARDER_REF ENDS

IMAGE_RESOURCE_DIRECTORY STRUCT ALIGNMODE
    Characteristics      DD ?
    TimeDateStamp        DD ?
    MajorVersion         DW ?
    MinorVersion         DW ?
    NumberOfNamedEntries DW ?
    NumberOfIdEntries    DW ?
IMAGE_RESOURCE_DIRECTORY ENDS

IMAGE_RESOURCE_DIRECTORY_STRING STRUCT ALIGNMODE
    _Length     DW   ?
    NameString  CHAR ?
IMAGE_RESOURCE_DIRECTORY_STRING ENDS

IMAGE_RESOURCE_DIR_STRING_U STRUCT ALIGNMODE
    _Length     DW    ?
    NameString  WCHAR ?
IMAGE_RESOURCE_DIR_STRING_U ENDS

IMAGE_RESOURCE_DATA_ENTRY STRUCT ALIGNMODE
    OffsetToData    DD  ?
    _size           DD  ?
    CodePage        DD  ?
    Reserved        DD  ?
IMAGE_RESOURCE_DATA_ENTRY ENDS

IMAGE_LOAD_CONFIG_DIRECTORY32 STRUCT ALIGNMODE
    _Size                           DD    ?
    TimeDateStamp                   DD    ?
    MajorVersion                    DW    ?
    MinorVersion                    DW    ?
    GlobalFlagsClear                DD    ?
    GlobalFlagsSet                  DD    ?
    CriticalSectionDefaultTimeout   DD    ?
    DeCommitFreeBlockThreshold      DD    ?
    DeCommitTotalFreeThreshold      DD    ?
    LockPrefixTable                 DD    ?
    MaximumAllocationSize           DD    ?
    VirtualMemoryThreshold          DD    ?
    ProcessHeapFlags                DD    ?
    ProcessAffinityMask             DD    ?
    CSDVersion                      DW    ?
    Reserved1                       DW    ?
    EditList                        DD    ?
    SecurityCookie                  DD    ?
    SEHandlerTable                  DD    ?
    SEHandlerCount                  DD    ?
IMAGE_LOAD_CONFIG_DIRECTORY32 ENDS

IMAGE_LOAD_CONFIG_DIRECTORY64 STRUCT ALIGNMODE
    _Size                           DD    ?
    TimeDateStamp                   DD    ?
    MajorVersion                    DW    ?
    MinorVersion                    DW    ?
    GlobalFlagsClear                DD    ?
    GlobalFlagsSet                  DD    ?
    CriticalSectionDefaultTimeout   DD    ?
    DeCommitFreeBlockThreshold      ULONGLONG ?
    DeCommitTotalFreeThreshold      ULONGLONG ?
    LockPrefixTable                 ULONGLONG ?
    MaximumAllocationSize           ULONGLONG ?
    VirtualMemoryThreshold          ULONGLONG ?
    ProcessAffinityMask             ULONGLONG ?
    ProcessHeapFlags                DD    ?
    CSDVersion                      DW    ?
    Reserved1                       DW    ?
    EditList                        ULONGLONG ?
    SecurityCookie                  ULONGLONG ?
    SEHandlerTable                  ULONGLONG ?
    SEHandlerCount                  ULONGLONG ?
IMAGE_LOAD_CONFIG_DIRECTORY64 ENDS

IFDEF APP_WIN64
    IMAGE_LOAD_CONFIG_DIRECTORY                 TYPEDEF IMAGE_LOAD_CONFIG_DIRECTORY64
ELSE
    IMAGE_LOAD_CONFIG_DIRECTORY                 TYPEDEF IMAGE_LOAD_CONFIG_DIRECTORY32
ENDIF

IMAGE_RUNTIME_FUNCTION_ENTRY STRUCT ALIGNMODE
    BeginAddress        XPTR ?
    EndAddress          XPTR ?
    UnwindInfoAddress   XPTR ?
IMAGE_RUNTIME_FUNCTION_ENTRY ENDS

IMAGE_IA64_RUNTIME_FUNCTION_ENTRY               TYPEDEF IMAGE_RUNTIME_FUNCTION_ENTRY

UNWIND_CODE UNION ALIGNMODE
    STRUCT s
        CodeOffset UBYTE  ?
        UnwindOp   UBYTE  ?
        OpInfo     UBYTE  ?
    ENDS
    FrameOffset    USHORT ?
UNWIND_CODE ENDS

UNWIND_INFO STRUCT ALIGNMODE
    Version         UBYTE ?
    Flags           UBYTE ?
    SizeOfProlog    UBYTE ?
    CountOfCodes    UBYTE ?
    FrameRegister   UBYTE ?
    FrameOffset     UBYTE ?
    UnwindCode      UNWIND_CODE 1 DUP(<>)
UNWIND_INFO ENDS

IMAGE_CE_RUNTIME_FUNCTION_ENTRY STRUCT ALIGNMODE
    FuncStart     UINT ?
    PrologLen     UINT ?
    FuncLen       UINT ?
    ThirtyTwoBit  UINT ?
    ExceptionFlag UINT ?
IMAGE_CE_RUNTIME_FUNCTION_ENTRY ENDS

IMAGE_DEBUG_DIRECTORY STRUCT ALIGNMODE
    Characteristics     DD  ?
    TimeDateStamp       DD  ?
    MajorVersion        DW  ?
    MinorVersion        DW  ?
    _Type               DD  ?
    SizeOfData          DD  ?
    AddressOfRawData    DD  ?
    PointerToRawData    DD  ?
IMAGE_DEBUG_DIRECTORY ENDS

IMAGE_COFF_SYMBOLS_HEADER STRUCT ALIGNMODE
    NumberOfSymbols         DD  ?
    LvaToFirstSymbol        DD  ?
    NumberOfLinenumbers     DD  ?
    LvaToFirstLinenumber    DD  ?
    RvaToFirstByteOfCode    DD  ?
    RvaToLastByteOfCode     DD  ?
    RvaToFirstByteOfData    DD  ?
    RvaToLastByteOfData     DD  ?
IMAGE_COFF_SYMBOLS_HEADER ENDS

FPO_DATA STRUCT ALIGNMODE
    ulOffStart  DD  ?
    cbProcSize  DD  ?
    cdwLocals   DD  ?
    cdwParams   DW  ?
    cbProlog    DW  ?
    cbRegs      DW  ?
    fHasSEH     DW  ?
    fUseBP      DW  ?
    reserved    DW  ?
    cbFrame     DW  ?
FPO_DATA ENDS

IMAGE_DEBUG_MISC STRUCT ALIGNMODE
    DataType    UINT32 ?
    _Length     UINT32 ?
    Unicode     UINT8  ?
    Reserved    UINT8  3 DUP(?)
    Data        UINT8  ?
IMAGE_DEBUG_MISC ENDS

IMAGE_FUNCTION_ENTRY32 STRUCT ALIGNMODE
    StartingAddress DD  ?
    EndingAddress   DD  ?
    EndOfPrologue   DD  ?
IMAGE_FUNCTION_ENTRY32 ENDS

IMAGE_FUNCTION_ENTRY64 STRUCT ALIGNMODE
    StartingAddress ULONGLONG ?
    EndingAddress   ULONGLONG ?
    UNION u
        EndOfPrologue       ULONGLONG ?
        UnwindInfoAddress   ULONGLONG ?
    ENDS
IMAGE_FUNCTION_ENTRY64 ENDS

IFDEF APP_WIN64
    IMAGE_FUNCTION_ENTRY EQU <IMAGE_FUNCTION_ENTRY64>
ELSE
    IMAGE_FUNCTION_ENTRY EQU <IMAGE_FUNCTION_ENTRY32>
ENDIF

IMAGE_SEPARATE_DEBUG_HEADER STRUCT ALIGNMODE
    Signature           DW  ?
    Flags               DW  ?
    Machine             DW  ?
    Characteristics     DW  ?
    TimeDateStamp       DD  ?
    CheckSum            DD  ?
    ImageBase           DD  ?
    SizeOfImage         DD  ?
    NumberOfSections    DD  ?
    ExportedNamesSize   DD  ?
    DebugDirectorySize  DD  ?
    SectionAlignment    DD  ?
    Reserved            DD  2 DUP(?)
IMAGE_SEPARATE_DEBUG_HEADER ENDS

IMAGE_ARCHITECTURE_ENTRY STRUCT ALIGNMODE
    FixupInstRVA    DD  ?
    NewInst         DD  ?
IMAGE_ARCHITECTURE_ENTRY ENDS

IMPORT_OBJECT_HEADER STRUCT ALIGNMODE
    Sig1            DW  ?
    Sig2            DW  ?
    Version         DW  ?
    Machine         DW  ?
    TimeDateStamp   DD  ?
    SizeOfData      DD  ?
    UNION u
        Ordinal     DW  ?
        Hint        DW  ?
    ENDS
    _Type           DW  ?
    NameType        DW  ?
    Reserved        DW  ?
IMPORT_OBJECT_HEADER ENDS

MESSAGE_RESOURCE_ENTRY STRUCT ALIGNMODE
    _Length     DW  ?
    Flags       DW  ?
    _Text       DB  1 DUP(?)
MESSAGE_RESOURCE_ENTRY ENDS

MESSAGE_RESOURCE_BLOCK STRUCT ALIGNMODE
    LowId           DD  ?
    HighId          DD  ?
    OffsetToEntries DD  ?
MESSAGE_RESOURCE_BLOCK ENDS

MESSAGE_RESOURCE_DATA STRUCT ALIGNMODE
    NumberOfBlocks  DD  ?
    Blocks          MESSAGE_RESOURCE_BLOCK 1 DUP(<>)
MESSAGE_RESOURCE_DATA ENDS

RTL_CRITICAL_SECTION_DEBUG STRUCT ALIGNMODE
    _Type                   DW   ?
    CreatorBackTraceIndex   DW   ?
    CriticalSection         XPTR ?
    ProcessLocksList        LIST_ENTRY <>
    EntryCount              DD   ?
    ContentionCount         DD   ?
    Spare                   DD   2 DUP(?)
RTL_CRITICAL_SECTION_DEBUG ENDS
RTL_RESOURCE_DEBUG                              TYPEDEF RTL_CRITICAL_SECTION_DEBUG

RTL_CRITICAL_SECTION STRUCT ALIGNMODE
    DebugInfo       XPTR  ?
    LockCount       LONG  ?
    RecursionCount  LONG  ?
    OwningThread    PVOID ?
    LockSemaphore   PVOID ?
    SpinCount       ULONG ?
RTL_CRITICAL_SECTION ENDS

RTL_SRWLOCK STRUCT ALIGNMODE
    UNION
        STRUCT
            Locked         UINT64 ?
            Waiting        UINT64 ?
            Waking         UINT64 ?
            MultipleShared UINT64 ?
            Shared         UINT64 ?
        ENDS
        Value       UINT64 ?
        _Ptr        PVOID  ?
    ENDS
RTL_SRWLOCK ENDS

RTL_CONDITION_VARIABLE STRUCT ALIGNMODE
    _Ptr    PVOID ?
RTL_CONDITION_VARIABLE ENDS

EVENTLOGRECORD STRUCT ALIGNMODE
    _Length             DD  ?
    Reserved            DD  ?
    RecordNumber        DD  ?
    TimeGenerated       DD  ?
    TimeWritten         DD  ?
    EventID             DD  ?
    EventType           DW  ?
    NumStrings          DW  ?
    EventCategory       DW  ?
    ReservedFlags       DW  ?
    ClosingRecordNumber DD  ?
    StringOffset        DD  ?
    UserSidLength       DD  ?
    UserSidOffset       DD  ?
    DataLength          DD  ?
    DataOffset          DD  ?
EVENTLOGRECORD ENDS

EVENTSFORLOGFILE STRUCT ALIGNMODE
    ulSize              ULONG ?
    szLogicalLogFile    WCHAR MAXLOGICALLOGNAMESIZE DUP(?)
    ulNumRecords        ULONG ?
    pEventLogRecords    EVENTLOGRECORD <>
EVENTSFORLOGFILE ENDS

PACKEDEVENTINFO STRUCT ALIGNMODE
    ulSize                  ULONG ?
    ulNumEventsForLogFile   ULONG ?
    ulOffsets               ULONG ?
PACKEDEVENTINFO ENDS

ACTIVATION_CONTEXT_QUERY_INDEX STRUCT ALIGNMODE
    ulAssemblyIndex         ULONG ?
    ulFileIndexInAssembly   ULONG ?
ACTIVATION_CONTEXT_QUERY_INDEX ENDS

ASSEMBLY_FILE_DETAILED_INFORMATION STRUCT ALIGNMODE
    ulFlags             DD   ?
    ulFilenameLength    DD   ?
    ulPathLength        DD   ?
    lpFileName          XPTR ?
    lpFilePath          XPTR ?
ASSEMBLY_FILE_DETAILED_INFORMATION ENDS

ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION STRUCT ALIGNMODE
    ulFlags                             DD   ?
    ulEncodedAssemblyIdentityLength     DD   ?
    ulManifestPathType                  DD   ?
    ulManifestPathLength                DD   ?
    liManifestLastWriteTime             LARGE_INTEGER <>
    ulPolicyPathType                    DD   ?
    ulPolicyPathLength                  DD   ?
    liPolicyLastWriteTime               LARGE_INTEGER <>
    ulMetadataSatelliteRosterIndex      DD   ?
    ulManifestVersionMajor              DD   ?
    ulManifestVersionMinor              DD   ?
    ulPolicyVersionMajor                DD   ?
    ulPolicyVersionMinor                DD   ?
    ulAssemblyDirectoryNameLength       DD   ?
    lpAssemblyEncodedAssemblyIdentity   XPTR ?
    lpAssemblyManifestPath              XPTR ?
    lpAssemblyPolicyPath                XPTR ?
    lpAssemblyDirectoryName             XPTR ?
    ulFileCount                         DD   ?
ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION ENDS

ACTIVATION_CONTEXT_RUN_LEVEL_INFORMATION STRUCT ALIGNMODE
    ulFlags     DD   ?
    RunLevel    ENUM ?
    UiAccess    DD   ?
ACTIVATION_CONTEXT_RUN_LEVEL_INFORMATION ENDS

COMPATIBILITY_CONTEXT_ELEMENT STRUCT ALIGNMODE
    Id      GUID <> 
    _Type   DW   ?
COMPATIBILITY_CONTEXT_ELEMENT ENDS

ACTIVATION_CONTEXT_DETAILED_INFORMATION STRUCT ALIGNMODE
    dwFlags                         DD   ?
    ulFormatVersion                 DD   ?
    ulAssemblyCount                 DD   ?
    ulRootManifestPathType          DD   ?
    ulRootManifestPathChars         DD   ?
    ulRootConfigurationPathType     DD   ?
    ulRootConfigurationPathChars    DD   ?
    ulAppDirPathType                DD   ?
    ulAppDirPathChars               DD   ?
    lpRootManifestPath              XPTR ?
    lpRootConfigurationPath         XPTR ?
    lpAppDirPath                    XPTR ?
ACTIVATION_CONTEXT_DETAILED_INFORMATION ENDS

ACTIVATION_CONTEXT_COMPATIBILITY_INFORMATION STRUCT ALIGNMODE
    ElementCount    DD  ?
    Elements        COMPATIBILITY_CONTEXT_ELEMENT <>
ACTIVATION_CONTEXT_COMPATIBILITY_INFORMATION ENDS

SUPPORTED_OS_INFO STRUCT ALIGNMODE
    OsCount         DW  ?
    MitigationExist DW  ?
    OsList          DW  MAX_SUPPORTED_OS_NUM DUP(?)
SUPPORTED_OS_INFO ENDS

HARDWARE_COUNTER_DATA STRUCT ALIGNMODE
    _Type       DD  ?
    Reserved    DD  ?
    Value       DQ  ?
HARDWARE_COUNTER_DATA ENDS

PERFORMANCE_DATA STRUCT ALIGNMODE
    _Size               DW  ?
    Version             DB  ?
    HwCountersCount     DB  ?
    ContextSwitchCount  DD  ?
    WaitReasonBitMap    DQ  ?
    CycleTime           DQ  ?
    RetryCount          DD  ?
    Reserved            DD  ?
    HwCounters          HARDWARE_COUNTER_DATA 16 DUP(<>)
PERFORMANCE_DATA ENDS

TAPE_ERASE STRUCT ALIGNMODE
    _Type       DD  ?
    Immediate   DB  ?
TAPE_ERASE ENDS

TAPE_PREPARE STRUCT ALIGNMODE
    Operation   DD  ?
    Immediate   DB  ?
TAPE_PREPARE ENDS

TAPE_WRITE_MARKS STRUCT ALIGNMODE
    _Type       DD  ?
    Count       DD  ?
    Immediate   DB  ?
TAPE_WRITE_MARKS ENDS

TAPE_GET_POSITION STRUCT ALIGNMODE
    _Type       DD  ?
    Partition   DD  ?
    _Offset     LARGE_INTEGER <>
TAPE_GET_POSITION ENDS

TAPE_SET_POSITION STRUCT ALIGNMODE
    Method      DD  ?
    Partition   DD  ?
    _Offset     LARGE_INTEGER <>
    Immediate   DB  ?
TAPE_SET_POSITION ENDS

TAPE_GET_DRIVE_PARAMETERS STRUCT ALIGNMODE
    ECC                     DB  ?
    Compression             DB  ?
    DataPadding             DB  ?
    ReportSetmarks          DB  ?
    DefaultBlockSize        DD  ?
    MaximumBlockSize        DD  ?
    MinimumBlockSize        DD  ?
    MaximumPartitionCount   DD  ?
    FeaturesLow             DD  ?
    FeaturesHigh            DD  ?
    EOTWarningZoneSize      DD  ?
TAPE_GET_DRIVE_PARAMETERS ENDS

TAPE_SET_DRIVE_PARAMETERS STRUCT ALIGNMODE
    ECC                 DB  ?
    Compression         DB  ?
    DataPadding         DB  ?
    ReportSetmarks      DB  ?
    EOTWarningZoneSize  DD  ?
TAPE_SET_DRIVE_PARAMETERS ENDS

TAPE_GET_MEDIA_PARAMETERS STRUCT ALIGNMODE
    Capacity        LARGE_INTEGER <>
    Remaining       LARGE_INTEGER <>
    BlockSize       DD  ?
    PartitionCount  DD  ?
    WriteProtected  DB  ?
TAPE_GET_MEDIA_PARAMETERS ENDS

TAPE_SET_MEDIA_PARAMETERS STRUCT ALIGNMODE
    BlockSize   DD  ?
TAPE_SET_MEDIA_PARAMETERS ENDS

TAPE_CREATE_PARTITION STRUCT ALIGNMODE
    Method  DD  ?
    Count   DD  ?
    _Size   DD  ?
TAPE_CREATE_PARTITION ENDS

TAPE_WMI_OPERATIONS STRUCT ALIGNMODE
    Method          DD    ?
    DataBufferSize  DD    ?
    DataBuffer      PVOID ?
TAPE_WMI_OPERATIONS ENDS

TRANSACTION_BASIC_INFORMATION STRUCT ALIGNMODE
    TransactionId   GUID <>
    State           DD   ?
    Outcome         DD   ?
TRANSACTION_BASIC_INFORMATION ENDS

TRANSACTIONMANAGER_BASIC_INFORMATION STRUCT ALIGNMODE
    TmIdentity   GUID <>
    VirtualClock LARGE_INTEGER <>
TRANSACTIONMANAGER_BASIC_INFORMATION ENDS

TRANSACTIONMANAGER_LOG_INFORMATION STRUCT ALIGNMODE
    LogIdentity GUID <>
TRANSACTIONMANAGER_LOG_INFORMATION ENDS

TRANSACTIONMANAGER_LOGPATH_INFORMATION STRUCT ALIGNMODE
    LogPathLength   DD    ?
    LogPath         WCHAR 1 DUP(?)
TRANSACTIONMANAGER_LOGPATH_INFORMATION ENDS

TRANSACTIONMANAGER_RECOVERY_INFORMATION STRUCT ALIGNMODE
    LastRecoveredLsn ULONGLONG ?
TRANSACTIONMANAGER_RECOVERY_INFORMATION ENDS

TRANSACTIONMANAGER_OLDEST_INFORMATION STRUCT ALIGNMODE
    OldestTransactionGuid GUID <>
TRANSACTIONMANAGER_OLDEST_INFORMATION ENDS

TRANSACTION_PROPERTIES_INFORMATION STRUCT ALIGNMODE
    IsolationLevel      DD    ?
    IsolationFlags      DD    ?
    Timeout             LARGE_INTEGER <>
    Outcome             DD    ?
    DescriptionLength   DD    ?
    Description         WCHAR 1 DUP(?)
TRANSACTION_PROPERTIES_INFORMATION ENDS

TRANSACTION_BIND_INFORMATION STRUCT ALIGNMODE
    TmHandle HANDLE ?
TRANSACTION_BIND_INFORMATION ENDS

TRANSACTION_ENLISTMENT_PAIR STRUCT ALIGNMODE
    EnlistmentId        GUID <>
    ResourceManagerId   GUID <>
TRANSACTION_ENLISTMENT_PAIR ENDS

TRANSACTION_ENLISTMENTS_INFORMATION STRUCT ALIGNMODE
    NumberOfEnlistments DD  ?
    EnlistmentPair      TRANSACTION_ENLISTMENT_PAIR 1 DUP(<>)
TRANSACTION_ENLISTMENTS_INFORMATION ENDS

TRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION STRUCT ALIGNMODE
    SuperiorEnlistmentPair TRANSACTION_ENLISTMENT_PAIR <>
TRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION ENDS

TRANSACTION_LIST_ENTRY STRUCT ALIGNMODE
    uow GUID <>
TRANSACTION_LIST_ENTRY ENDS

TRANSACTION_LIST_INFORMATION STRUCT ALIGNMODE
    NumberOfTransactions    DD  ?
    TransactionInformation  TRANSACTION_LIST_ENTRY 1 DUP(<>)
TRANSACTION_LIST_INFORMATION ENDS

RESOURCEMANAGER_BASIC_INFORMATION STRUCT ALIGNMODE
    ResourceManagerId   GUID  <>
    DescriptionLength   DD    ?
    Description         WCHAR 1 DUP(?)
RESOURCEMANAGER_BASIC_INFORMATION ENDS

RESOURCEMANAGER_COMPLETION_INFORMATION STRUCT ALIGNMODE
    IoCompletionPortHandle  HANDLE ?
    CompletionKey           XPTR ?
RESOURCEMANAGER_COMPLETION_INFORMATION ENDS

ENLISTMENT_BASIC_INFORMATION    STRUCT ALIGNMODE
    EnlistmentId        GUID <>
    TransactionId       GUID <>
    ResourceManagerId   GUID <>
ENLISTMENT_BASIC_INFORMATION ENDS

ENLISTMENT_CRM_INFORMATION STRUCT ALIGNMODE
    CrmTransactionManagerId GUID <>
    CrmResourceManagerId    GUID <>
    CrmEnlistmentId         GUID <>
ENLISTMENT_CRM_INFORMATION ENDS

KTMOBJECT_CURSOR STRUCT ALIGNMODE
    LastQuery       GUID <>
    ObjectIdCount   DD   ?
    ObjectIds       GUID 1 DUP(<>)
KTMOBJECT_CURSOR ENDS

TP_POOL_STACK_INFORMATION STRUCT ALIGNMODE
    StackReserve    DD  ?
    StackCommit     DD  ?
TP_POOL_STACK_INFORMATION ENDS

TP_CALLBACK_ENVIRON_V3 STRUCT ALIGNMODE
    Version                     DD   ?
    Pool                        XPTR ?
    CleanupGroup                XPTR ?
    CleanupGroupCancelCallback  XPTR ?
    RaceDll                     PVOID ?
    ActivationContext           XPTR ?
    FinalizationCallback        XPTR ?
    UNION u
        Flags                   DD   ?
        STRUCT s
            LongFunction        ULONG32 ?
            Persistent          ULONG32 ?
            _Private            ULONG32 ?
        ENDS
    ENDS
    CallbackPriority            DD   ?
    _Size                       DD   ?
TP_CALLBACK_ENVIRON_V3 ENDS
TP_CALLBACK_ENVIRON                             TYPEDEF TP_CALLBACK_ENVIRON_V3

TP_CALLBACK_ENVIRON_V1 STRUCT ALIGNMODE
    Version                     DD    ?
    Pool                        XPTR  ?
    CleanupGroup                XPTR  ?
    CleanupGroupCancelCallback  XPTR  ?
    RaceDll                     PVOID ?
    ActivationContext           XPTR  ?
    FinalizationCallback        XPTR  ?
    UNION u
        Flags                   DD    ?
        STRUCT s
            LongFunction        DD    ?
            Persistent          DD    ?
            _Private            DD    ?
        ENDS
    ENDS
TP_CALLBACK_ENVIRON_V1 ENDS

TRANSACTION_NOTIFICATION STRUCT ALIGNMODE
    TransactionKey          XPTR ?
    TransactionNotification DD   ?
    TmVirtualClock          LARGE_INTEGER <>
    ArgumentLength          DD   ?
TRANSACTION_NOTIFICATION ENDS

TRANSACTION_NOTIFICATION_RECOVERY_ARGUMENT STRUCT ALIGNMODE
    EnlistmentId    GUID <>
    uow             GUID <>
TRANSACTION_NOTIFICATION_RECOVERY_ARGUMENT ENDS

TRANSACTION_NOTIFICATION_TM_ONLINE_ARGUMENT STRUCT ALIGNMODE
    TmIdentity  GUID <>
    Flags       DD   ?
TRANSACTION_NOTIFICATION_TM_ONLINE_ARGUMENT ENDS

TRANSACTION_NOTIFICATION_SAVEPOINT_ARGUMENT STRUCT ALIGNMODE
    SavepointId DD  ?
TRANSACTION_NOTIFICATION_SAVEPOINT_ARGUMENT ENDS

TRANSACTION_NOTIFICATION_PROPAGATE_ARGUMENT STRUCT ALIGNMODE
    PropagationCookie   DD   ?
    uow                 GUID <>
    TmIdentity          GUID <>
    BufferLength        DD   ?
TRANSACTION_NOTIFICATION_PROPAGATE_ARGUMENT ENDS

TRANSACTION_NOTIFICATION_MARSHAL_ARGUMENT STRUCT ALIGNMODE
    MarshalCookie   DD   ?
    uow             GUID <>
TRANSACTION_NOTIFICATION_MARSHAL_ARGUMENT ENDS

KCRM_MARSHAL_HEADER STRUCT ALIGNMODE
    VersionMajor DD ?
    VersionMinor DD ?
    NumProtocols DD ?
    Unused       DD ?
KCRM_MARSHAL_HEADER ENDS

KCRM_TRANSACTION_BLOB STRUCT ALIGNMODE
    uow             GUID <>
    TmIdentity      GUID <>
    IsolationLevel  DD   ?
    IsolationFlags  DD   ?
    Timeout         DD   ?
    Description     DW   MAX_TRANSACTION_DESCRIPTION_LENGTH DUP(?)
KCRM_TRANSACTION_BLOB ENDS

KCRM_PROTOCOL_BLOB STRUCT ALIGNMODE
    ProtocolId              GUID <>
    StaticInfoLength        DD   ?
    TransactionIdInfoLength DD   ?
    Unused1                 DD   ?
    Unused2                 DD   ?
KCRM_PROTOCOL_BLOB ENDS

IMAGE_COR20_HEADER STRUCT ALIGNMODE
    cb                  ULONG  ?
    MajorRuntimeVersion USHORT ?
    MinorRuntimeVersion USHORT ?
    MetaData            IMAGE_DATA_DIRECTORY <>
    Flags               ULONG  ?
    UNION u
        EntryPointToken USHORT ?
        EntryPointRVA   USHORT ?
    ENDS
    Resources               IMAGE_DATA_DIRECTORY <>
    StrongNameSignature     IMAGE_DATA_DIRECTORY <>
    CodeManagerTable        IMAGE_DATA_DIRECTORY <>
    VTableFixups            IMAGE_DATA_DIRECTORY <>
    ExportAddressTableJumps IMAGE_DATA_DIRECTORY <>
    ManagedNativeHeader     IMAGE_DATA_DIRECTORY <>
IMAGE_COR20_HEADER ENDS

RTL_RUN_ONCE UNION ALIGNMODE
    aPtr PVOID ?
RTL_RUN_ONCE ENDS

RTL_BARRIER STRUCT ALIGNMODE
    Reserved1   DD   ?
    Reserved2   DD   ?
    Reserved3   XPTR 2 DUP(?)
    Reserved4   DD   ?
    Reserved5   DD   ?
RTL_BARRIER ENDS

IFNDEF PROCESSOR_NUMBER
    PROCESSOR_NUMBER STRUCT ALIGNMODE
        _Group   DW  ?
        Number   DB  ?
        Reserved DB  ?
    PROCESSOR_NUMBER ENDS
ENDIF

GROUP_AFFINITY STRUCT ALIGNMODE
    _Mask    ULONG_PTR ?
    _Group   DW        ?
    Reserved DW        3 Dup(?)
GROUP_AFFINITY ENDS

;======================================== Functions =======================================;
IF (NTDDI_VERSION GE NTDDI_WINXP)
    IFDEF APP_WIN64
        IFNDEF __C_specific_handler
            __C_specific_handler PROTO :XPTR, :XWORD, :XPTR, :XPTR
        ENDIF
        IFNDEF __chkstk
            __chkstk PROTO
        ENDIF
    ENDIF
ENDIF
_hread PROTO :XWORD, :LPVOID, :XWORD
_hwrite PROTO :XWORD, :LPCSTR, :XWORD
_lclose PROTO :XWORD
_lcreat PROTO :LPCSTR, :XWORD
_llseek PROTO :XWORD, :XWORD, :XWORD
_lopen PROTO :LPCSTR, :XWORD
_lread PROTO :XWORD, :LPVOID, :XWORD
_lwrite PROTO :XWORD, :LPCSTR, :XWORD
AddAtomA PROTO :LPCTSTR
AddAtomW PROTO :LPCWSTR
AllocConsole PROTO
AreFileApisANSI PROTO
BackupRead PROTO :HANDLE, :LPBYTE, :XWORD, :LPDWORD, :XWORD, :XWORD, :LPVOID
BackupSeek PROTO :HANDLE, :XWORD, :XWORD, :LPDWORD, :LPDWORD, :LPVOID
BackupWrite PROTO :HANDLE, :LPBYTE, :XWORD, :LPDWORD, :XWORD, :XWORD, :LPVOID
Beep PROTO :XWORD, :XWORD
BeginUpdateResourceA Proto :LPCTSTR, :XWORD
BeginUpdateResourceW PROTO :LPCWSTR, :XWORD
BuildCommDCBA Proto :LPCTSTR, :XPTR
BuildCommDCBAndTimeoutsA Proto :LPCTSTR, :XPTR, :XPTR
BuildCommDCBAndTimeoutsW PROTO :LPCWSTR, :XPTR, :XPTR
BuildCommDCBW Proto :LPCWSTR, :XPTR
CallNamedPipeA Proto :XPTR, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD
CallNamedPipeW PROTO :XPTR, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD
ClearCommBreak PROTO :HANDLE
ClearCommError PROTO :HANDLE, :LPDWORD, :XPTR
CloseHandle PROTO :HANDLE
CloseProfileUserMapping PROTO
CommConfigDialogA Proto :LPCTSTR, :HWND, :XPTR
CommConfigDialogW PROTO :LPCWSTR, :HWND, :XPTR
CompareFileTime PROTO :XPTR, :XPTR
CompareStringA Proto :XWORD, :XWORD, :LPCTSTR, :XWORD, :LPCTSTR, :XWORD
CompareStringW PROTO :XWORD, :XWORD, :LPCWSTR, :XWORD, :LPCWSTR, :XWORD
ConnectNamedPipe PROTO :HANDLE, :XPTR
ContinueDebugEvent PROTO :XWORD, :XWORD, :XWORD
ConvertDefaultLocale PROTO :XWORD
CopyFileA Proto :LPCTSTR, :LPCTSTR, :XWORD
CopyFileW PROTO :LPCWSTR, :LPCWSTR, :XWORD
CreateConsoleScreenBuffer PROTO :XWORD, :XWORD, :XPTR, :XWORD, :LPVOID
CreateDirectoryA Proto :LPCTSTR, :XPTR
CreateDirectoryExA Proto :LPCTSTR, :LPCTSTR, :XPTR
CreateDirectoryExW PROTO :LPCWSTR, :LPCWSTR, :XPTR
CreateDirectoryW PROTO :LPCWSTR, :XPTR
CreateEventA Proto :XPTR, :XWORD, :XWORD, :LPCTSTR
CreateEventW Proto :XPTR, :XWORD, :XWORD, :LPCWSTR
CreateFileA Proto :LPCTSTR, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD, :HANDLE
CreateFileMappingA PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :XWORD, :LPCTSTR
CreateFileMappingW PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :XWORD, :LPCWSTR
CreateFileW PROTO :LPCWSTR, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD, :HANDLE
CreateIoCompletionPort PROTO :HANDLE, :HANDLE, :ULONG_PTR, :XWORD
CreateMailslotA PROTO :LPCTSTR, :XWORD, :XWORD, :XPTR
CreateMailslotW PROTO :LPCWSTR, :XWORD, :XWORD, :XPTR
CreateMutexA PROTO :XPTR, :XWORD, :LPCTSTR
CreateMutexW PROTO :XPTR, :XWORD, :LPCWSTR
CreateNamedPipeA PROTO :LPCTSTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
CreateNamedPipeW PROTO :LPCWSTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
CreatePipe PROTO :XPTR, :XPTR, :XPTR, :XWORD
CreateProcessA PROTO :LPCTSTR, :LPTSTR, :XPTR, :XPTR, :XWORD, :XWORD, :LPVOID, :LPCTSTR, :XPTR, :XPTR
CreateProcessW PROTO :LPCWSTR, :LPWSTR, :XPTR, :XPTR, :XWORD, :XWORD, :LPVOID, :LPCWSTR, :XPTR, :XPTR
CreateRemoteThread PROTO :HANDLE, :XPTR, :SIZE_T, :XPTR, :LPVOID, :XWORD, :LPDWORD
CreateSemaphoreA PROTO :XPTR, :XWORD, :XWORD, :LPCTSTR
CreateSemaphoreW PROTO :XPTR, :XWORD, :XWORD, :LPCWSTR
CreateTapePartition PROTO :HANDLE, :XWORD, :XWORD, :XWORD
CreateThread PROTO :XPTR, :SIZE_T, :XPTR, :LPVOID, :XWORD, :LPDWORD
CreateToolhelp32Snapshot PROTO :XWORD, :XWORD
DebugActiveProcess PROTO :XWORD
DebugBreak PROTO
DefineDosDeviceA PROTO :XWORD, :LPCTSTR, :LPCTSTR
DefineDosDeviceW PROTO :XWORD, :LPCWSTR, :LPCWSTR
DeleteAtom PROTO :XWORD
DeleteCriticalSection PROTO :XPTR
DeleteFileA PROTO :LPCTSTR
DeleteFileW PROTO :LPCWSTR
DeviceIoControl PROTO :HANDLE, :XWORD, :LPVOID, :XWORD, :LPVOID, :XWORD, :LPDWORD, :XPTR
DisableThreadLibraryCalls PROTO :HMODULE
DisconnectNamedPipe PROTO :HANDLE
DosDateTimeToFileTime PROTO :XWORD, :XWORD, :XPTR
DuplicateHandle PROTO :HANDLE, :HANDLE, :HANDLE, :XPTR, :XWORD, :XWORD, :XWORD
EndUpdateResourceA PROTO :HANDLE, :XWORD
EndUpdateResourceW PROTO :HANDLE, :XWORD
EnterCriticalSection PROTO :XPTR
EnumCalendarInfoA PROTO :XPTR, :XWORD, :XWORD, :XWORD
EnumCalendarInfoW PROTO :XPTR, :XWORD, :XWORD, :XWORD
EnumDateFormatsA PROTO :XPTR, :XWORD, :XWORD
EnumDateFormatsW PROTO :XPTR, :XWORD, :XWORD
EnumResourceLanguagesA PROTO :HMODULE, :LPCTSTR, :LPCTSTR, :XPTR, :LONG_PTR
EnumResourceLanguagesW PROTO :HMODULE, :LPCWSTR, :LPCWSTR, :XPTR, :LONG_PTR
EnumResourceNamesA PROTO :HMODULE, :LPCTSTR, :XPTR, :LONG_PTR
EnumResourceNamesW PROTO :HMODULE, :LPCWSTR, :XPTR, :LONG_PTR
EnumResourceTypesA PROTO :HMODULE, :XPTR, :LONG_PTR
EnumResourceTypesW PROTO :HMODULE, :XPTR, :LONG_PTR
EnumSystemCodePagesA PROTO :XPTR, :XWORD
EnumSystemCodePagesW PROTO :XPTR, :XWORD
EnumSystemLocalesA PROTO :XPTR, :XWORD
EnumSystemLocalesW PROTO :XPTR, :XWORD
EnumTimeFormatsA PROTO :XPTR, :XWORD, :XWORD
EnumTimeFormatsW PROTO :XPTR, :XWORD, :XWORD
EraseTape PROTO :HANDLE, :XWORD, :XWORD
EscapeCommFunction PROTO :HANDLE, :XWORD
ExitProcess PROTO :XWORD
ExitThread PROTO :XWORD
ExpandEnvironmentStringsA PROTO :LPCTSTR, :LPTSTR, :XWORD
ExpandEnvironmentStringsW PROTO :LPCWSTR, :LPWSTR, :XWORD
FatalAppExitA PROTO :XWORD, :LPCTSTR
FatalAppExitW PROTO :XWORD, :LPCWSTR
FatalExit PROTO :XWORD
FileTimeToDosDateTime PROTO :XPTR, :LPWORD, :LPWORD
FileTimeToLocalFileTime PROTO :XPTR, :XPTR
FileTimeToSystemTime PROTO :XPTR, :XPTR
FillConsoleOutputAttribute PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :LPDWORD
FillConsoleOutputCharacterA Proto :HANDLE, :XWORD, :XWORD, :XWORD, :LPDWORD
FillConsoleOutputCharacterW PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :LPDWORD
FindAtomA PROTO :LPCTSTR
FindAtomW PROTO :LPCWSTR
FindClose PROTO :HANDLE
FindCloseChangeNotification PROTO :HANDLE
FindFirstChangeNotificationA PROTO :LPCTSTR, :XWORD, :XWORD
FindFirstChangeNotificationW PROTO :LPCWSTR, :XWORD, :XWORD
FindFirstFileA PROTO :LPCTSTR, :XPTR
FindFirstFileW PROTO :LPCWSTR, :XPTR
FindNextChangeNotification PROTO :HANDLE
FindNextFileA PROTO :HANDLE, :XPTR
FindNextFileW PROTO :HANDLE, :XPTR
FindResourceA PROTO :HMODULE, :LPCTSTR, :LPCTSTR
FindResourceExA PROTO :HMODULE, :LPCTSTR, :LPCTSTR, :XWORD
FindResourceExW PROTO :HMODULE, :LPCWSTR, :LPCWSTR, :XWORD
FindResourceW PROTO :HMODULE, :LPCWSTR, :LPCWSTR
FlushConsoleInputBuffer PROTO :HANDLE
FlushFileBuffers PROTO :HANDLE
FlushInstructionCache PROTO :HANDLE, :LPCVOID, :SIZE_T
FlushViewOfFile PROTO :LPCVOID, :SIZE_T
FoldStringA PROTO :XWORD, :LPCTSTR, :XWORD, :LPTSTR, :XWORD
FoldStringW PROTO :XWORD, :LPCWSTR, :XWORD, :LPWSTR, :XWORD
FormatMessageA PROTO :XWORD, :LPCVOID, :XWORD, :XWORD, :LPTSTR, :XWORD, :XPTR
FormatMessageW PROTO :XWORD, :LPCVOID, :XWORD, :XWORD, :LPWSTR, :XWORD, :XPTR
FreeConsole PROTO
FreeEnvironmentStringsA PROTO :LPTSTR
FreeEnvironmentStringsW PROTO :LPWSTR
FreeLibrary PROTO :HMODULE
FreeLibraryAndExitThread PROTO :HMODULE, :XWORD
FreeResource PROTO :XWORD
GenerateConsoleCtrlEvent PROTO :XWORD, :XWORD
GetACP PROTO
GetAtomNameA PROTO :XWORD, :LPTSTR, :XWORD
GetAtomNameW PROTO :XWORD, :LPWSTR, :XWORD
GetBinaryTypeA PROTO :LPCTSTR, :LPDWORD
GetBinaryTypeW PROTO :LPCTSTR, :LPDWORD
GetCommandLineA PROTO
GetCommandLineW PROTO
GetCommConfig PROTO :HANDLE, :XPTR, :LPDWORD
GetCommMask PROTO :HANDLE, :LPDWORD
GetCommModemStatus PROTO :HANDLE, :LPDWORD
GetCommProperties PROTO :HANDLE, :XPTR
GetCommState PROTO :HANDLE, :XPTR
GetCommTimeouts PROTO :HANDLE, :XPTR
GetCompressedFileSizeA PROTO :LPCTSTR, :LPDWORD
GetCompressedFileSizeW PROTO :LPCWSTR, :LPDWORD
GetComputerNameA PROTO :LPTSTR, :LPDWORD
GetComputerNameW PROTO :LPWSTR, :LPDWORD
GetConsoleCP PROTO
GetConsoleCursorInfo PROTO :HANDLE, :XPTR
GetConsoleMode PROTO :HANDLE, :LPDWORD
GetConsoleOutputCP PROTO
GetConsoleScreenBufferInfo PROTO :HANDLE, :XPTR
GetConsoleTitleA PROTO :LPTSTR, :XWORD
GetConsoleTitleW PROTO :LPWSTR, :XWORD
GetCPInfo PROTO :XWORD, :XPTR
GetCurrencyFormatA PROTO :XWORD, :XWORD, :LPCTSTR, :XPTR, :LPTSTR,  :XWORD
GetCurrencyFormatW PROTO :XWORD, :XWORD, :LPCWSTR, :XPTR, :LPWSTR,  :XWORD
GetCurrentDirectoryA PROTO :XWORD, :LPTSTR
GetCurrentDirectoryW PROTO :XWORD, :LPWSTR
GetCurrentProcess PROTO
GetCurrentProcessId PROTO
GetCurrentThread PROTO
GetCurrentThreadId PROTO
GetDateFormatA PROTO :XWORD, :XWORD, :XPTR, :LPCTSTR, :LPTSTR, :XWORD
GetDateFormatW PROTO :XWORD, :XWORD, :XPTR, :LPCWSTR, :LPWSTR, :XWORD
GetDefaultCommConfigA PROTO :LPCTSTR, :XPTR, :LPDWORD
GetDefaultCommConfigW PROTO :LPCWSTR, :XPTR, :LPDWORD
GetDiskFreeSpaceA PROTO :LPCTSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD
GetDiskFreeSpaceExA PROTO :LPCTSTR, :XPTR, :XPTR, :XPTR
GetDiskFreeSpaceExW PROTO :LPCWSTR, :XPTR, :XPTR, :XPTR
GetDiskFreeSpaceW PROTO :LPCWSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD
GetDriveTypeA PROTO :LPCTSTR
GetDriveTypeW PROTO :LPCWSTR
GetEnvironmentStringsA PROTO
GetEnvironmentStringsW PROTO
GetEnvironmentVariableA PROTO :LPCTSTR, :LPTSTR, :XWORD
GetEnvironmentVariableW PROTO :LPCWSTR, :LPWSTR, :XWORD
IF (NTDDI_VERSION EQ NTDDI_WIN95 OR NTDDI_VERSION EQ NTDDI_WIN98_ME OR NTDDI_VERSION GE NTDDI_VISTA)
    GetErrorMode PROTO
ENDIF
GetExitCodeProcess PROTO :HANDLE, :LPDWORD
GetExitCodeThread PROTO :HANDLE, :LPDWORD
GetFileAttributesA PROTO :LPCTSTR
GetFileAttributesW PROTO :LPCWSTR
GetFileInformationByHandle PROTO :HANDLE, :XPTR
GetFileSize PROTO :HANDLE, :XPTR
GetFileTime PROTO :HANDLE, :XPTR, :XPTR, :XPTR
GetFileType PROTO :HANDLE
GetFullPathNameA PROTO :LPCTSTR, :XWORD, :LPTSTR, :LPTSTR
GetFullPathNameW PROTO :LPCWSTR, :XWORD, :LPWSTR, :LPWSTR
IF (NTDDI_VERSION EQ NTDDI_WIN95 OR NTDDI_VERSION EQ NTDDI_WIN98_ME OR NTDDI_VERSION EQ NTDDI_WINXP OR NTDDI_VERSION EQ NTDDI_VISTA)
    GetHandleContext PROTO :HANDLE
    SetHandleContext PROTO :XWORD, :XWORD
ENDIF
GetHandleInformation PROTO :HANDLE, :LPDWORD
GetLargestConsoleWindowSize PROTO :HANDLE
GetLastError PROTO
GetLocaleInfoA PROTO :XWORD, :XWORD, :LPTSTR, :XWORD
GetLocaleInfoW PROTO :XWORD, :XWORD, :LPWSTR, :XWORD
GetLocalTime PROTO :XPTR
GetLogicalDrives PROTO
GetLogicalDriveStringsA PROTO :XWORD, :LPTSTR
GetLogicalDriveStringsW PROTO :XWORD, :LPWSTR
GetMailslotInfo PROTO :HANDLE, :LPWORD, :LPWORD, :LPWORD, :LPWORD
GetModuleFileNameA PROTO :HMODULE, :LPTSTR, :XWORD
GetModuleFileNameW PROTO :HMODULE, :LPWSTR, :XWORD
GetModuleHandleA PROTO :LPCTSTR
GetModuleHandleW PROTO :LPCWSTR
GetNamedPipeHandleStateA PROTO :HANDLE, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD
GetNamedPipeHandleStateW PROTO :HANDLE, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD
GetNamedPipeInfo PROTO :HANDLE, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD
GetNumberFormatA PROTO :XWORD, :XWORD, :LPCTSTR, :XPTR, :LPTSTR, :XWORD
GetNumberFormatW PROTO :XWORD, :XWORD, :LPCWSTR, :XPTR, :LPWSTR, :XWORD
GetNumberOfConsoleInputEvents PROTO :HANDLE, :LPDWORD
GetNumberOfConsoleMouseButtons PROTO :LPDWORD
GetOEMCP PROTO
GetOverlappedResult PROTO :HANDLE, :XPTR, :LPDWORD, :XWORD
GetPriorityClass PROTO :HANDLE
GetPrivateProfileIntA PROTO :LPCTSTR, :LPCTSTR, :XWORD, :LPCTSTR
GetPrivateProfileIntW PROTO :LPCWSTR, :LPCWSTR, :XWORD, :LPCWSTR
GetPrivateProfileSectionA PROTO :LPCTSTR, :LPTSTR, :XWORD, :LPCTSTR
GetPrivateProfileSectionNamesA PROTO :LPTSTR, :XWORD, :LPCTSTR
GetPrivateProfileSectionNamesW PROTO :LPWSTR, :XWORD, :LPCWSTR
GetPrivateProfileSectionW PROTO :LPCWSTR, :LPWSTR, :XWORD, :LPCWSTR
GetPrivateProfileStringA PROTO :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPTSTR, :XWORD, :LPCTSTR
GetPrivateProfileStringW PROTO :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPWSTR, :XWORD, :LPCWSTR
GetPrivateProfileStructA PROTO :LPCTSTR, :LPCTSTR, :LPVOID, :XWORD, :LPCTSTR
GetPrivateProfileStructW PROTO :LPCWSTR, :LPCWSTR, :LPVOID, :XWORD, :LPCWSTR
GetProcAddress PROTO :HMODULE, :LPCSTR
GetProcessAffinityMask PROTO :HANDLE, :XPTR, :XPTR
GetProcessHeap PROTO
GetProcessHeaps PROTO :XWORD, :XPTR
GetProcessShutdownParameters PROTO :LPDWORD, :LPDWORD
GetProcessTimes PROTO :HANDLE, :XPTR, :XPTR, :XPTR, :XPTR
GetProcessVersion PROTO :XWORD
GetProcessWorkingSetSize PROTO :HANDLE, :XPTR, :XPTR
GetProfileIntA PROTO :LPCTSTR, :LPCTSTR, :XWORD
GetProfileIntW PROTO :LPCWSTR, :LPCWSTR, :XWORD
GetProfileSectionA PROTO :LPCTSTR, :LPTSTR, :XWORD
GetProfileSectionW PROTO :LPCWSTR, :LPWSTR, :XWORD
GetProfileStringA PROTO :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPTSTR, :XWORD
GetProfileStringW PROTO :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPWSTR, :XWORD
GetQueuedCompletionStatus PROTO :HANDLE, :LPDWORD, :XPTR, :XPTR, :XWORD
GetShortPathNameA PROTO :LPCTSTR, :LPTSTR, :XWORD
GetShortPathNameW PROTO :LPCWSTR, :LPWSTR, :XWORD
GetStartupInfoA PROTO :XPTR
GetStartupInfoW PROTO :XPTR
GetStdHandle PROTO :XWORD
GetStringTypeA PROTO :XWORD, :XWORD, :LPCSTR, :XWORD, :LPWORD
GetStringTypeExA PROTO :XWORD, :XWORD, :LPCTSTR, :XWORD, :LPWORD
GetStringTypeExW PROTO :XWORD, :XWORD, :LPCWSTR, :XWORD, :LPWORD
GetStringTypeW PROTO :XWORD, :XWORD, :LPWSTR, :XWORD, :LPWORD
GetSystemDefaultLangID PROTO
GetSystemDefaultLCID PROTO
GetSystemDirectoryA PROTO :LPTSTR, :XWORD
GetSystemDirectoryW PROTO :LPWSTR, :XWORD
GetSystemInfo PROTO :XPTR
GetSystemPowerStatus PROTO :XPTR
GetSystemTime PROTO :XPTR
GetSystemTimeAdjustment PROTO :XPTR, :XPTR, :XPTR
GetSystemTimeAsFileTime PROTO :XPTR
GetTapeParameters PROTO :HANDLE, :XWORD, :LPDWORD, :LPVOID
GetTapePosition PROTO :HANDLE, :XWORD, :LPDWORD, :LPDWORD, :LPDWORD
GetTapeStatus PROTO :HANDLE
GetTempFileNameA PROTO :LPCTSTR, :LPCTSTR, :XWORD, :LPTSTR
GetTempFileNameW PROTO :LPCWSTR, :LPCWSTR, :XWORD, :LPWSTR
GetTempPathA PROTO :XWORD, :LPTSTR
GetTempPathW PROTO :XWORD, :LPWSTR
GetThreadContext PROTO :HANDLE, :XPTR
GetThreadLocale PROTO
GetThreadPriority PROTO :HANDLE
GetThreadSelectorEntry PROTO :HANDLE, :XWORD, :XPTR
GetThreadTimes PROTO :HANDLE, :XPTR, :XPTR, :XPTR, :XPTR
GetTickCount PROTO
GetTimeFormatA PROTO :XWORD, :XWORD, :XPTR, :LPCTSTR, :LPTSTR, :XWORD
GetTimeFormatW PROTO :XWORD, :XWORD, :XPTR, :LPCWSTR, :LPWSTR, :XWORD
GetTimeZoneInformation PROTO :XPTR
GetUserDefaultLangID PROTO
GetUserDefaultLCID PROTO
GetUserNameA PROTO :LPTSTR, :LPDWORD
GetUserNameW PROTO :LPTSTR, :LPDWORD
GetVersion PROTO
GetVersionExA PROTO :XPTR
GetVersionExW PROTO :XPTR
GetVolumeInformationA PROTO :LPCTSTR, :LPTSTR, :XWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPTSTR, :XWORD
GetVolumeInformationW PROTO :LPCWSTR, :LPWSTR, :XWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPWSTR, :XWORD
GetWindowsDirectoryA PROTO :LPCTSTR, :XWORD
GetWindowsDirectoryW PROTO :LPCWSTR, :XWORD
GlobalAddAtomA PROTO :LPCTSTR
GlobalAddAtomW PROTO :LPCWSTR
GlobalAlloc PROTO :XWORD, :SIZE_T
GlobalCompact PROTO :HGLOBAL
GlobalDeleteAtom PROTO :XWORD
GlobalFindAtomA PROTO :LPCTSTR
GlobalFindAtomW PROTO :LPCWSTR
GlobalFix PROTO :HGLOBAL
GlobalFlags PROTO :HGLOBAL
GlobalFree PROTO :HGLOBAL
GlobalGetAtomNameA PROTO :XWORD, :LPTSTR, :XWORD
GlobalGetAtomNameW PROTO :XWORD, :LPWSTR, :XWORD
GlobalHandle PROTO :LPCVOID
GlobalLock PROTO :HGLOBAL
GlobalMemoryStatus PROTO :XPTR
GlobalReAlloc PROTO :HGLOBAL, :SIZE_T, :XWORD
GlobalSize PROTO :HGLOBAL
GlobalUnfix PROTO :HGLOBAL
GlobalUnlock PROTO :HGLOBAL
GlobalUnWire PROTO :HGLOBAL
GlobalWire PROTO :HGLOBAL
Heap32First PROTO :XPTR, :XWORD, :ULONG_PTR
Heap32ListFirst PROTO :HANDLE, :XPTR
Heap32ListNext PROTO :HANDLE, :XPTR
Heap32Next PROTO :XPTR
HeapAlloc PROTO :HANDLE, :XWORD, :SIZE_T
HeapCompact PROTO :HANDLE, :XWORD
HeapCreate PROTO :XWORD, :SIZE_T, :SIZE_T
HeapDestroy PROTO :HANDLE
HeapFree PROTO :HANDLE, :XWORD, :LPVOID
HeapLock PROTO :HANDLE
HeapReAlloc PROTO :HANDLE, :XWORD, :LPVOID, :SIZE_T
HeapSize PROTO :HANDLE, :XWORD, :LPCVOID
HeapUnlock PROTO :HANDLE
HeapValidate PROTO :HANDLE, :XWORD, :LPCVOID
HeapWalk PROTO :HANDLE, :XPTR
InitAtomTable PROTO :XWORD
InitializeCriticalSection PROTO :XPTR
InterlockedDecrement PROTO :XPTR
InterlockedExchange PROTO :XPTR, :XWORD
InterlockedIncrement PROTO :XPTR
IsBadCodePtr PROTO :XPTR
IsBadHugeReadPtr PROTO :XPTR, :XWORD
IsBadHugeWritePtr PROTO :XPTR, :XWORD
IsBadReadPtr PROTO :LPVOID, :UINT_PTR
IsBadStringPtrA PROTO :LPCTSTR, :UINT_PTR
IsBadStringPtrW PROTO :LPCWSTR, :UINT_PTR
IsBadWritePtr PROTO :LPVOID, :UINT_PTR
IsDBCSLeadByte PROTO :XWORD
IsDBCSLeadByteEx PROTO :XWORD, :XWORD
IsValidCodePage PROTO :XWORD
IsValidLocale PROTO :XWORD, :XWORD
LCMapStringA PROTO :XWORD, :XWORD, :LPCTSTR, :XWORD, :LPTSTR, :XWORD
LCMapStringW PROTO :XWORD, :XWORD, :LPCWSTR, :XWORD, :LPWSTR, :XWORD
LeaveCriticalSection PROTO :XPTR
LoadLibraryA PROTO :LPCTSTR
LoadLibraryExA PROTO :LPCTSTR, :HANDLE, :XWORD
LoadLibraryExW PROTO :LPCWSTR, :HANDLE, :XWORD
LoadLibraryW PROTO :LPCWSTR
LoadModule PROTO :LPCSTR, :LPVOID
LoadResource PROTO :HMODULE, :HRSRC
LocalAlloc PROTO :XWORD, :SIZE_T
LocalCompact PROTO :HLOCAL
LocalFileTimeToFileTime PROTO :XPTR, :XPTR
LocalFlags PROTO :HLOCAL
LocalFree PROTO :HLOCAL
LocalHandle PROTO :LPCVOID
LocalLock PROTO :HLOCAL
LocalReAlloc PROTO :HLOCAL, :SIZE_T, :XWORD
LocalShrink PROTO :HLOCAL, :XWORD
LocalSize PROTO :HLOCAL
LocalUnlock PROTO :HLOCAL
LockFile PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :XWORD
LockFileEx PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
LockResource PROTO :HGLOBAL
lstrcatA PROTO :LPTSTR, :LPCTSTR
lstrcatW PROTO :LPWSTR, :LPCWSTR
lstrcmpA PROTO :LPCTSTR, :LPCTSTR
lstrcmpiA PROTO :LPCTSTR, :LPCTSTR
lstrcmpiW PROTO :LPCWSTR, :LPCWSTR
lstrcmpW PROTO :LPCWSTR, :LPCWSTR
lstrcpyA PROTO :LPTSTR, :LPCTSTR
lstrcpynA PROTO :LPTSTR, :LPCTSTR, :XWORD
lstrcpynW PROTO :LPWSTR, :LPCWSTR, :XWORD
lstrcpyW PROTO :LPWSTR, :LPCWSTR
lstrlenA PROTO :LPCTSTR
lstrlenW PROTO :LPCWSTR
MapViewOfFile PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :SIZE_T
MapViewOfFileEx PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :SIZE_T, :LPVOID
MoveFileA PROTO :LPCTSTR, :LPCTSTR
MoveFileExA PROTO :LPCTSTR, :LPCTSTR, :XWORD
MoveFileExW PROTO :LPCWSTR, :LPCWSTR, :XWORD
MoveFileW PROTO :LPCWSTR, :LPCWSTR
MulDiv PROTO :XWORD, :XWORD, :XWORD
MultiByteToWideChar PROTO :XWORD, :XWORD, :LPCSTR, :XWORD, :LPWSTR, :XWORD
OpenEventA PROTO :XWORD, :XWORD, :LPCTSTR
OpenEventW PROTO :XWORD, :XWORD, :LPCWSTR
OpenFile PROTO :LPCSTR, :XPTR, :XWORD
OpenFileMappingA PROTO :XWORD, :XWORD, :LPCTSTR
OpenFileMappingW PROTO :XWORD, :XWORD, :LPCWSTR
OpenMutexA PROTO :XWORD, :XWORD, :LPCTSTR
OpenMutexW PROTO :XWORD, :XWORD, :LPCWSTR
OpenProcess PROTO :XWORD, :XWORD, :XWORD
OpenProfileUserMapping PROTO
OpenSemaphoreA PROTO :XWORD, :XWORD, :LPCTSTR
OpenSemaphoreW PROTO :XWORD, :XWORD, :LPCWSTR
OutputDebugStringA PROTO :LPCTSTR
OutputDebugStringW PROTO :LPCWSTR
PeekConsoleInputA PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD
PeekConsoleInputW PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD
PeekNamedPipe PROTO :HANDLE, :LPVOID, :XWORD, :LPDWORD, :LPDWORD, :LPDWORD
PostQueuedCompletionStatus PROTO :HANDLE, :XWORD, :ULONG_PTR, :XPTR
PrepareTape PROTO :HANDLE, :XWORD, :XWORD
PulseEvent PROTO :HANDLE
PurgeComm PROTO :HANDLE, :XWORD
QueryDosDeviceA PROTO :LPCTSTR, :LPTSTR, :XWORD
QueryDosDeviceW PROTO :LPCWSTR, :LPWSTR, :XWORD
QueryPerformanceCounter PROTO :XPTR
QueryPerformanceFrequency PROTO :XPTR
QueueUserAPC PROTO :XPTR, :HANDLE, :ULONG_PTR
RaiseException PROTO :XWORD, :XWORD, :XWORD, :XPTR
ReadConsoleA PROTO :HANDLE, :LPVOID, :XWORD, :LPDWORD, :LPVOID
ReadConsoleInputA PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD
ReadConsoleInputW PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD
ReadConsoleOutputA PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :XPTR
ReadConsoleOutputAttribute PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :LPDWORD
ReadConsoleOutputCharacterA PROTO :HANDLE, :LPTSTR, :XWORD, :XWORD, :LPDWORD
ReadConsoleOutputCharacterW PROTO :HANDLE, :LPWSTR, :XWORD, :XWORD, :LPDWORD
ReadConsoleOutputW PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :XPTR
ReadConsoleW PROTO :HANDLE, :LPVOID, :XWORD, :LPDWORD, :LPVOID
ReadFile PROTO :HANDLE, :LPVOID, :XWORD, :LPDWORD, :XPTR
ReadFileEx PROTO :HANDLE, :LPVOID, :XWORD, :XPTR, :XPTR
ReadProcessMemory PROTO :HANDLE, :LPCVOID, :LPVOID, :SIZE_T, :SIZE_T
ReleaseMutex PROTO :HANDLE
ReleaseSemaphore PROTO :HANDLE, :XWORD, :LPLONG
RemoveDirectoryA PROTO :LPCTSTR
RemoveDirectoryW PROTO :LPCWSTR
ResetEvent PROTO :HANDLE
ResumeThread PROTO :HANDLE
RtlFillMemory PROTO :XPTR, :SIZE_T, :XWORD
RtlMoveMemory PROTO :XPTR, :XPTR, :SIZE_T
RtlUnwind PROTO :PVOID, :PVOID, :XPTR, :PVOID
RtlZeroMemory PROTO :XPTR, :SIZE_T
ScrollConsoleScreenBufferA PROTO :HANDLE, :XPTR, :XPTR, :XWORD, :XPTR
ScrollConsoleScreenBufferW PROTO :HANDLE, :XPTR, :XPTR, :XWORD, :XPTR
SearchPathA PROTO :LPCTSTR, :LPCTSTR, :LPCTSTR, :XWORD, :LPTSTR, :LPTSTR
SearchPathW PROTO :LPCWSTR, :LPCWSTR, :LPCWSTR, :XWORD, :LPWSTR, :LPWSTR
SetCommBreak PROTO :HANDLE
SetCommConfig PROTO :HANDLE, :XPTR, :XWORD
SetCommMask PROTO :HANDLE, :XWORD
SetCommState PROTO :HANDLE, :XPTR
SetCommTimeouts PROTO :HANDLE, :XPTR
SetComputerNameA PROTO :LPCTSTR
SetComputerNameW PROTO :LPCWSTR
SetConsoleActiveScreenBuffer PROTO :HANDLE
SetConsoleCP PROTO :XWORD
SetConsoleCtrlHandler PROTO :XPTR, :XWORD
SetConsoleCursorInfo PROTO :HANDLE, :XPTR
SetConsoleCursorPosition PROTO :HANDLE, :XWORD
SetConsoleMode PROTO :HANDLE, :XWORD
SetConsoleOutputCP PROTO :XWORD
SetConsoleScreenBufferSize PROTO :HANDLE, :XWORD
SetConsoleTextAttribute PROTO :HANDLE, :XWORD
SetConsoleTitleA PROTO :LPCTSTR
SetConsoleTitleW PROTO :LPCWSTR
SetConsoleWindowInfo PROTO :HANDLE, :XWORD, :XPTR
SetCurrentDirectoryA PROTO :LPCTSTR
SetCurrentDirectoryW PROTO :LPCWSTR
SetDefaultCommConfigA PROTO :LPCTSTR, :XPTR, :XWORD
SetDefaultCommConfigW PROTO :LPCWSTR, :XPTR, :XWORD
SetEndOfFile PROTO :HANDLE
SetEnvironmentVariableA PROTO :LPCTSTR, :LPCTSTR
SetEnvironmentVariableW PROTO :LPCWSTR, :LPCWSTR
SetErrorMode PROTO :XWORD
SetEvent PROTO :HANDLE
SetFileApisToANSI PROTO
SetFileApisToOEM PROTO
SetFileAttributesA PROTO :LPCTSTR, :XWORD
SetFileAttributesW PROTO :LPCWSTR, :XWORD
SetFilePointer PROTO :HANDLE, :XWORD, :XPTR, :XWORD
SetFileTime PROTO :HANDLE, :XPTR, :XPTR, :XPTR
SetHandleCount PROTO :XWORD
SetHandleInformation PROTO :HANDLE, :XWORD, :XWORD
SetLastError PROTO :XWORD
SetLocaleInfoA PROTO :XWORD, :XWORD, :LPTSTR
SetLocaleInfoW PROTO :XWORD, :XWORD, :LPWSTR
SetLocalTime PROTO :XPTR
SetMailslotInfo PROTO :HANDLE, :XWORD
SetNamedPipeHandleState PROTO :HANDLE, :LPDWORD, :LPDWORD, :LPDWORD
SetPriorityClass PROTO :HANDLE, :XWORD
SetProcessShutdownParameters PROTO :XWORD, :XWORD
SetProcessWorkingSetSize PROTO :HANDLE, :SIZE_T, :SIZE_T
SetStdHandle PROTO :XWORD, :HANDLE
SetSystemPowerState PROTO :XWORD, :XWORD
SetSystemTime PROTO :XPTR
SetSystemTimeAdjustment PROTO :XWORD, :XWORD
SetTapeParameters PROTO :HANDLE, :XWORD, :LPVOID
SetTapePosition PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SetThreadAffinityMask PROTO :HANDLE, :XPTR
SetThreadContext PROTO :HANDLE, :XPTR
SetThreadLocale PROTO :XWORD
SetThreadPriority PROTO :HANDLE, :XWORD
SetTimeZoneInformation PROTO :XPTR
SetUnhandledExceptionFilter PROTO :XPTR
SetupComm PROTO :HANDLE, :XWORD, :XWORD
SetVolumeLabelA PROTO :LPCTSTR, :LPCTSTR
SetVolumeLabelW PROTO :LPCWSTR, :LPCWSTR
SizeofResource PROTO :HMODULE, :HRSRC
Sleep PROTO :XWORD
SleepEx PROTO :XWORD, :XWORD
SuspendThread PROTO :HANDLE
SystemTimeToFileTime PROTO :XPTR, :XPTR
SystemTimeToTzSpecificLocalTime PROTO :XPTR, :XPTR, :XPTR
TerminateProcess PROTO :HANDLE, :XWORD
TerminateThread PROTO :HANDLE, :XWORD
Thread32First PROTO :HANDLE, :XPTR
Thread32Next PROTO :HANDLE, :XPTR
TlsAlloc PROTO
TlsFree PROTO :XWORD
TlsGetValue PROTO :XWORD
TlsSetValue PROTO :XWORD, :LPVOID
Toolhelp32ReadProcessMemory PROTO :XWORD, :LPCVOID, :LPVOID, :SIZE_T, :SIZE_T
TransactNamedPipe PROTO :HANDLE, :LPVOID, :XWORD, :LPVOID, :XWORD, :LPDWORD, :XPTR
TransmitCommChar PROTO :HANDLE, :XWORD
UnhandledExceptionFilter PROTO :XPTR
UnlockFile PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :XWORD
UnlockFileEx PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :XPTR
UnmapViewOfFile PROTO :LPCVOID
UpdateResourceA PROTO :HANDLE, :LPCTSTR, :LPCTSTR, :XWORD, :LPVOID, :XWORD
UpdateResourceW PROTO :HANDLE, :LPCWSTR, :LPCWSTR, :XWORD, :LPVOID, :XWORD
VerLanguageNameA PROTO :XWORD, :LPTSTR, :XWORD
VerLanguageNameW PROTO :XWORD, :LPWSTR, :XWORD
VirtualAlloc PROTO :LPVOID, :SIZE_T, :XWORD, :XWORD
VirtualFree PROTO :LPVOID, :SIZE_T, :XWORD
VirtualLock PROTO :LPVOID, :SIZE_T
VirtualProtect PROTO :LPVOID, :SIZE_T, :XWORD, :XPTR
VirtualProtectEx PROTO :HANDLE, :LPVOID, :SIZE_T, :XWORD, :XPTR
VirtualQuery PROTO :LPVOID, :XPTR, :SIZE_T
VirtualQueryEx PROTO :HANDLE, :LPVOID, :XPTR, :SIZE_T
VirtualUnlock PROTO :LPVOID, :SIZE_T
WaitCommEvent PROTO :HANDLE, :LPDWORD, :XPTR
WaitForDebugEvent PROTO :XPTR, :XWORD
WaitForMultipleObjects PROTO :XWORD, :XPTR, :XWORD, :XWORD
WaitForMultipleObjectsEx PROTO :XWORD, :XPTR, :XWORD, :XWORD, :XWORD
WaitForSingleObject PROTO :HANDLE, :XWORD
WaitForSingleObjectEx PROTO :HANDLE, :XWORD, :XWORD
WaitNamedPipeA PROTO :XPTR, :XWORD
WaitNamedPipeW PROTO :XPTR, :XWORD
WideCharToMultiByte PROTO :XWORD, :XWORD, :LPWSTR, :XWORD, :LPSTR, :XWORD, :LPCSTR, :LPBOOL
WinExec PROTO :LPCSTR, :XWORD
WriteConsoleA PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD, :LPVOID
WriteConsoleInputA PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD
WriteConsoleInputW PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD
WriteConsoleOutputA PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :XPTR
WriteConsoleOutputAttribute PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :LPDWORD
WriteConsoleOutputCharacterA PROTO :HANDLE, :LPCTSTR, :XWORD, :XWORD, :LPDWORD
WriteConsoleOutputCharacterW PROTO :HANDLE, :LPCWSTR, :XWORD, :XWORD, :LPDWORD
WriteConsoleOutputW PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :XPTR
WriteConsoleW PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD, :LPVOID
WriteFile PROTO :HANDLE, :LPCVOID, :XWORD, :LPDWORD, :XPTR
WriteFileEx PROTO :HANDLE, :LPCVOID, :XWORD, :XPTR, :XPTR
WritePrivateProfileSectionA PROTO :LPCTSTR, :LPCTSTR, :LPCTSTR
WritePrivateProfileSectionW PROTO :LPCWSTR, :LPCWSTR, :LPCWSTR
WritePrivateProfileStringA PROTO :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR
WritePrivateProfileStringW PROTO :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR
WritePrivateProfileStructA PROTO :LPCTSTR, :LPCTSTR, :LPVOID, :XWORD, :XPTR
WritePrivateProfileStructW PROTO :LPCWSTR, :LPCWSTR, :LPVOID, :XWORD, :XPTR
WriteProcessMemory PROTO :HANDLE, :LPVOID, :LPCVOID, :SIZE_T, :SIZE_T
WriteProfileSectionA PROTO :LPCTSTR, :LPCTSTR
WriteProfileSectionW PROTO :LPCWSTR, :LPCWSTR
WriteProfileStringA PROTO :LPCTSTR, :LPCTSTR, :LPCTSTR
WriteProfileStringW PROTO :LPCWSTR, :LPCWSTR, :LPCWSTR
WriteTapemark PROTO :HANDLE, :XWORD, :XWORD, :XWORD

GetFreeSpace EQU <GlobalMemoryStatus>

LockSegment EQU <GlobalFix>
UnlockSegment EQU <GlobalUnfix>
GetCurrentTime EQU <GetTickCount>
MoveMemory EQU <RtlMoveMemory>
FillMemory EQU <RtlFillMemory>
ZeroMemory EQU <RtlZeroMemory>

IF (NTDDI_VERSION GE NTDDI_WIN98_ME)
    CancelDeviceWakeupRequest PROTO :HANDLE
    CancelIo PROTO :HANDLE
    ConvertThreadToFiber PROTO :XPTR
    CopyFileExA PROTO :LPCTSTR, :LPCTSTR, :XPTR, :LPVOID, :LPBOOL, :XWORD
    CopyFileExW PROTO :LPCWSTR, :LPCWSTR, :XPTR, :LPVOID, :LPBOOL, :XWORD
    CreateFiber PROTO :SIZE_T, :XPTR, :LPVOID
    CreateWaitableTimerA PROTO :XPTR, :XWORD, :LPCTSTR
    CreateWaitableTimerW PROTO :XPTR, :XWORD, :LPCWSTR
    DeleteFiber PROTO :LPVOID
    EnumCalendarInfoExA PROTO :XPTR, :XWORD, :XWORD, :XWORD
    EnumCalendarInfoExW PROTO :XPTR, :XWORD, :XWORD, :XWORD
    EnumDateFormatsExA PROTO :XPTR, :XWORD, :XWORD
    EnumDateFormatsExW PROTO :XPTR, :XWORD, :XWORD
    FindFirstFileExA PROTO :LPCTSTR, :XWORD, :LPVOID, :XWORD, :LPVOID, :XWORD
    FindFirstFileExW PROTO :LPCWSTR, :XWORD, :LPVOID, :XWORD, :LPVOID, :XWORD
    GetCalendarInfoA PROTO :XWORD, :XWORD, :XWORD, :LPTSTR, :XWORD, :LPDWORD
    GetCalendarInfoW PROTO :XWORD, :XWORD, :XWORD, :LPWSTR, :XWORD, :LPDWORD
    GetCPInfoExA PROTO :XWORD, :XWORD, :XPTR
    GetCPInfoExW PROTO :XWORD, :XWORD, :XPTR
    GetDevicePowerState PROTO :HANDLE, :LPBOOL
    GetFileAttributesExA PROTO :LPCTSTR, :XWORD, :LPVOID
    GetFileAttributesExW PROTO :LPCWSTR, :XWORD, :LPVOID
    IF (NTDDI_VERSION NE NTDDI_WINNT4)
        GetLongPathNameA PROTO :LPCTSTR, :LPTSTR, :XWORD
        GetLongPathNameW PROTO :LPCWSTR, :LPWSTR, :XWORD
        RequestDeviceWakeup PROTO :HANDLE
        RequestWakeupLatency PROTO :XWORD
        ResetWriteWatch PROTO :LPVOID, :SIZE_T
        SetCalendarInfoA PROTO :XWORD, :XWORD, :XWORD, :LPCTSTR
        SetCalendarInfoW PROTO :XWORD, :XWORD, :XWORD, :LPCWSTR
        SetMessageWaitingIndicator PROTO :HANDLE, :XWORD
        IFDEF APP_UNICODE
            GetLongPathName EQU <GetLongPathNameW>
            SetCalendarInfo EQU <SetCalendarInfoW>
        ELSE
            GetLongPathName EQU <GetLongPathNameA>
            SetCalendarInfo EQU <SetCalendarInfoA>
        ENDIF
    ENDIF
    GetProcessPriorityBoost PROTO :HANDLE, :XPTR
    GetThreadPriorityBoost PROTO :HANDLE, :XPTR
    IsDebuggerPresent PROTO
    IsProcessorFeaturePresent PROTO :XWORD
    IsSystemResumeAutomatic PROTO
    OpenWaitableTimerA PROTO :XWORD, :XWORD, :LPCTSTR
    OpenWaitableTimerW PROTO :XWORD, :XWORD, :LPCWSTR
    ReadDirectoryChangesW PROTO :HANDLE, :LPVOID, :XWORD, :XWORD, :XWORD, :LPDWORD, :XPTR, :XPTR
    ReadFileScatter PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD, :XPTR
    SetCriticalSectionSpinCount PROTO :XPTR, :XWORD
    SetProcessAffinityMask PROTO :HANDLE, :XWORD
    SetProcessPriorityBoost PROTO :HANDLE, :XWORD
    SetThreadExecutionState PROTO :XWORD
    SetThreadIdealProcessor PROTO :HANDLE, :XWORD
    SetThreadPriorityBoost PROTO :HANDLE, :XWORD
    SetWaitableTimer PROTO :HANDLE, :XPTR, :XWORD, :XPTR, :LPVOID, :XWORD
    SignalObjectAndWait PROTO :HANDLE, :HANDLE, :XWORD, :XWORD
    SwitchToFiber PROTO :LPVOID
    SwitchToThread PROTO
    VirtualAllocEx PROTO :HANDLE, :LPVOID, :SIZE_T, :XWORD, :XWORD
    VirtualFreeEx PROTO :HANDLE, :LPVOID, :SIZE_T, :XWORD
    WriteFileGather PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD, :XPTR
    IFDEF APP_UNICODE
        CopyFileEx EQU <CopyFileExW>
        CreateWaitableTimer EQU <CreateWaitableTimerW>
        EnumCalendarInfoEx EQU <EnumCalendarInfoExW>
        EnumDateFormatsEx EQU <EnumDateFormatsExW>
        FindFirstFileEx EQU <FindFirstFileExW>
        GetCalendarInfo EQU <GetCalendarInfoW>
        GetCPInfoEx EQU <GetCPInfoExW>
        GetFileAttributesEx EQU <GetFileAttributesExW>
        OpenWaitableTimer EQU <OpenWaitableTimerW>
    ELSE
        CopyFileEx EQU <CopyFileExA>
        CreateWaitableTimer EQU <CreateWaitableTimerA>
        EnumCalendarInfoEx EQU <EnumCalendarInfoExA>
        EnumDateFormatsEx EQU <EnumDateFormatsExA>
        FindFirstFileEx EQU <FindFirstFileExA>
        GetCalendarInfo EQU <GetCalendarInfoA>
        GetCPInfoEx EQU <GetCPInfoExA>
        GetFileAttributesEx EQU <GetFileAttributesExA>
        OpenWaitableTimer EQU <OpenWaitableTimerA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINNT4)
    AddConsoleAliasA PROTO :LPCTSTR, :LPCTSTR, :LPCTSTR
    AddConsoleAliasW PROTO :LPCWSTR, :LPCWSTR, :LPCWSTR
    ConsoleMenuControl PROTO :HANDLE, :XWORD, :XWORD
    CreateTimerQueue PROTO
    DuplicateConsoleHandle PROTO :HANDLE, :XWORD, :XWORD, :XWORD
    ExitVDM PROTO :XWORD, :XWORD
    ExpungeConsoleCommandHistoryA PROTO :XWORD
    ExpungeConsoleCommandHistoryW PROTO :XWORD
    GetConsoleAliasA PROTO :LPTSTR, :LPTSTR, :XWORD, :LPTSTR
    GetConsoleAliasesA PROTO :LPTSTR, :XWORD, :LPTSTR
    GetConsoleAliasesW PROTO :LPWSTR, :XWORD, :LPWSTR
    GetConsoleAliasesLengthA PROTO :LPTSTR
    GetConsoleAliasesLengthW PROTO :LPWSTR
    GetConsoleAliasExesA PROTO :LPTSTR, :XWORD
    GetConsoleAliasExesW PROTO :LPWSTR, :XWORD
    GetConsoleAliasExesLengthA PROTO
    GetConsoleAliasExesLengthW PROTO
    GetConsoleAliasW PROTO :LPWSTR, :LPWSTR, :XWORD, :LPWSTR
    GetModuleHandleExA PROTO :XWORD, :LPCTSTR, :XPTR
    GetModuleHandleExW PROTO :XWORD, :LPCWSTR, :XPTR
    GetNextVDMCommand PROTO :XPTR
    GetNumberOfConsoleFonts PROTO
    GetProcessIoCounters PROTO :HANDLE, :XPTR
    GetVDMCurrentDirectories PROTO :XWORD, :XPTR
    InvalidateConsoleDIBits PROTO :HANDLE, :XPTR
    OpenConsoleW PROTO :LPCWSTR, :XWORD, :XWORD, :XWORD
    ReadConsoleInputExA PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD, :XWORD
    ReadConsoleInputExW PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD, :XWORD
    SetConsoleCursor PROTO :HANDLE, :HCURSOR
    SetConsoleHardwareState PROTO :XPTR, :XWORD
    SetConsoleIcon PROTO :HICON
    SetConsoleMaximumWindowSize PROTO :HANDLE, :XWORD
    SetConsoleNumberOfCommandsA PROTO :XWORD, :XWORD
    SetConsoleNumberOfCommandsW PROTO :XWORD, :XWORD
    SetConsolePalette PROTO :XPTR
    SetLastConsoleEventActive PROTO
    SetVDMCurrentDirectories PROTO :XWORD, :XWORD
    ShowConsoleCursor PROTO :HANDLE, :XWORD
    VerifyVersionInfoA PROTO :XPTR, :XWORD, :XWORD
    VerifyVersionInfoW PROTO :XPTR, :XWORD, :XWORD
    IFDEF APP_UNICODE
        AddConsoleAlias EQU <AddConsoleAliasW>
        ExpungeConsoleCommandHistory EQU <ExpungeConsoleCommandHistoryW>
        GetConsoleAlias EQU <GetConsoleAliasW>
        GetConsoleAliasExes EQU <GetConsoleAliasExesW>
        GetConsoleAliasExesLength EQU <GetConsoleAliasExesLengthW>
        GetConsoleAliases EQU <GetConsoleAliasesW>
        GetConsoleAliasesLength EQU <GetConsoleAliasesLengthW>
        GetModuleHandleEx EQU   <GetModuleHandleExW>
        ReadConsoleInputEx EQU <ReadConsoleInputExW>
        SetConsoleNumberOfCommands EQU <SetConsoleNumberOfCommandsW>
        VerifyVersionInfo EQU <VerifyVersionInfoW>
    ELSE
        AddConsoleAlias EQU <AddConsoleAliasA>
        ExpungeConsoleCommandHistory EQU <ExpungeConsoleCommandHistoryA>
        GetConsoleAlias EQU <GetConsoleAliasA>
        GetConsoleAliasExes EQU <GetConsoleAliasExesA>
        GetConsoleAliasExesLength EQU <GetConsoleAliasExesLengthA>
        GetConsoleAliases EQU <GetConsoleAliasesA>
        GetConsoleAliasesLength EQU <GetConsoleAliasesLengthA>
        GetModuleHandleEx EQU   <GetModuleHandleExA>
        ReadConsoleInputEx EQU <ReadConsoleInputExA>
        SetConsoleNumberOfCommands EQU <SetConsoleNumberOfCommandsA>
        VerifyVersionInfo EQU <VerifyVersionInfoA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN2K)
    AllocateUserPhysicalPages PROTO :HANDLE, :XPTR, :XPTR
    AssignProcessToJobObject PROTO :HANDLE, :HANDLE
    BindIoCompletionCallback PROTO :HANDLE, :XPTR, :XWORD
    ChangeTimerQueueTimer PROTO :HANDLE, :HANDLE, :XWORD, :XWORD
    CreateHardLinkA PROTO :LPCTSTR, :LPCTSTR, :XPTR
    CreateHardLinkW PROTO :LPCWSTR, :LPCWSTR, :XPTR
    CreateJobObjectA PROTO :XPTR, :LPCTSTR
    CreateJobObjectW PROTO :XPTR, :LPCWSTR
    CreateTimerQueueTimer PROTO :XPTR, :HANDLE, :XPTR, :PVOID, :XWORD, :XWORD, :XWORD
    DelayLoadFailureHook PROTO :LPCSTR, :LPCSTR
    DeleteTimerQueue PROTO :HANDLE
    DeleteVolumeMountPointA PROTO :LPCTSTR
    DeleteVolumeMountPointW PROTO :LPCWSTR
    DnsHostnameToComputerNameA PROTO :LPCTSTR, :LPTSTR, :LPDWORD
    DnsHostnameToComputerNameW PROTO :LPCWSTR, :LPWSTR, :LPDWORD
    DosPathToSessionPathA PROTO :XWORD, :LPTSTR, :LPTSTR
    DosPathToSessionPathW PROTO :XWORD, :LPWSTR, :LPWSTR
    EnumLanguageGroupLocalesA PROTO :XPTR, :XWORD, :XWORD, :LONG_PTR
    EnumLanguageGroupLocalesW PROTO :XPTR, :XWORD, :XWORD, :LONG_PTR
    EnumSystemLanguageGroupsA PROTO :XPTR, :XWORD, :LONG_PTR
    EnumSystemLanguageGroupsW PROTO :XPTR, :XWORD, :LONG_PTR
    EnumUILanguagesA PROTO :XPTR, :XWORD, :LONG_PTR
    EnumUILanguagesW PROTO :XPTR, :XWORD, :LONG_PTR
    FindFirstVolumeA PROTO :LPTSTR, :XWORD
    FindFirstVolumeMountPointA PROTO :LPTSTR, :LPTSTR, :XWORD
    FindFirstVolumeMountPointW PROTO :LPWSTR, :LPWSTR, :XWORD
    FindFirstVolumeW PROTO :LPWSTR, :XWORD
    FindNextVolumeA PROTO :HANDLE, :LPTSTR, :XWORD
    FindNextVolumeMountPointA PROTO :HANDLE, :LPTSTR, :XWORD
    FindNextVolumeMountPointW PROTO :HANDLE, :LPWSTR, :XWORD
    FindNextVolumeW PROTO :HANDLE, :LPWSTR, :XWORD
    FindVolumeClose PROTO :HANDLE
    FindVolumeMountPointClose PROTO :HANDLE
    FreeUserPhysicalPages PROTO :HANDLE, :XPTR, :XPTR
    GetComputerNameExA PROTO :XWORD, :LPTSTR, :LPDWORD
    GetComputerNameExW PROTO :XWORD, :LPWSTR, :LPDWORD
    GetConsoleNlsMode PROTO
    GetConsoleWindow PROTO
    GetFileSizeEx PROTO :HANDLE, :XPTR
    GetSystemDefaultUILanguage PROTO
    GetSystemWindowsDirectoryA PROTO :LPTSTR, :XWORD
    GetSystemWindowsDirectoryW PROTO :LPWSTR, :XWORD
    GetUserDefaultUILanguage PROTO
    GetVolumeNameForVolumeMountPointA PROTO :LPCTSTR, :LPTSTR, :XWORD
    GetVolumeNameForVolumeMountPointW PROTO :LPCWSTR, :LPWSTR, :XWORD
    GetVolumePathNameA PROTO :LPCTSTR, :LPTSTR, :XWORD
    GetVolumePathNameW PROTO :LPCWSTR, :LPWSTR, :XWORD
    GlobalMemoryStatusEx PROTO :XPTR
    IsValidLanguageGroup PROTO :XWORD, :XWORD
    MapUserPhysicalPages PROTO :PVOID, :ULONG_PTR, :XPTR
    MapUserPhysicalPagesScatter PROTO :PVOID, :ULONG_PTR, :XPTR
    MoveFileWithProgressA PROTO :LPCTSTR, :LPCTSTR, :XPTR, :LPVOID, :XWORD
    MoveFileWithProgressW PROTO :LPCWSTR, :LPCWSTR, :XPTR, :LPVOID, :XWORD
    IF (NTDDI_VERSION LT NTDDI_VISTA)
        OpenDataFile PROTO :XWORD, :XWORD
    ENDIF
    OpenJobObjectA PROTO :XWORD, :XWORD, :LPCTSTR
    OpenJobObjectW PROTO :XWORD, :XWORD, :LPCWSTR
    OpenThread PROTO :XWORD, :XWORD, :XWORD
    PrivCopyFileExW PROTO :LPCWSTR, :LPCWSTR, :XPTR, :LPVOID, :LPBOOL, :XWORD
    ProcessIdToSessionId PROTO :XWORD, :XPTR
    QueryInformationJobObject PROTO :HANDLE, :XWORD, :LPVOID, :XWORD, :LPDWORD
    RegisterWaitForSingleObject PROTO :XPTR, :HANDLE, :XPTR, :PVOID, :XWORD, :XWORD
    ReplaceFileA PROTO :LPCTSTR, :LPCTSTR, :LPCTSTR, :XWORD, :LPVOID, :LPVOID
    ReplaceFileW PROTO :LPCWSTR, :LPCWSTR, :LPCWSTR, :XWORD, :LPVOID, :LPVOID
    SetComputerNameExA PROTO :XWORD, :LPCTSTR
    SetComputerNameExW PROTO :XWORD, :LPCWSTR
    SetConsoleNlsMode PROTO :HANDLE, :XWORD
    SetConsoleOS2OemFormat PROTO :XWORD
    SetFilePointerEx PROTO :HANDLE, :XWORD, :XPTR, :XWORD
    SetInformationJobObject PROTO :HANDLE, :XWORD, :LPVOID, :XWORD
    SetTermsrvAppInstallMode PROTO :XWORD
    SetTimerQueueTimer PROTO :HANDLE, :XPTR, :PVOID, :XWORD, :XWORD, :XWORD
    SetVolumeMountPointA PROTO :LPCTSTR, :LPCTSTR
    SetVolumeMountPointW PROTO :LPCWSTR, :LPCWSTR
    TerminateJobObject PROTO :HANDLE, :XWORD
    UnregisterWait PROTO :HANDLE
    VerSetConditionMask PROTO :XWORD, :XWORD, :XWORD
    IFDEF APP_UNICODE
        CreateHardLink EQU <CreateHardLinkW>
        CreateJobObject EQU <CreateJobObjectW>
        DeleteVolumeMountPoint EQU <DeleteVolumeMountPointW>
        DnsHostnameToComputerName EQU <DnsHostnameToComputerNameW>
        DosPathToSessionPath EQU <DosPathToSessionPathW>
        EnumLanguageGroupLocales EQU <EnumLanguageGroupLocalesW>
        EnumSystemLanguageGroups EQU <EnumSystemLanguageGroupsW>
        EnumUILanguages EQU <EnumUILanguagesW>
        FindActCtxSectionString EQU <FindActCtxSectionStringW>
        FindFirstVolume EQU <FindFirstVolumeW>
        FindFirstVolumeMountPoint EQU <FindFirstVolumeMountPointW>
        FindNextVolume EQU <FindNextVolumeW>
        FindNextVolumeMountPoint EQU <FindNextVolumeMountPointW>
        GetComputerNameEx EQU <GetComputerNameExW>
        GetSystemWindowsDirectory EQU <GetSystemWindowsDirectoryW>
        GetVolumeNameForVolumeMountPoint EQU <GetVolumeNameForVolumeMountPointW>
        GetVolumePathName EQU <GetVolumePathNameW>
        MoveFileWithProgress EQU <MoveFileWithProgressW>
        OpenJobObject EQU <OpenJobObjectW>
        ReplaceFile EQU <ReplaceFileW>
        SetComputerNameEx EQU <SetComputerNameExW>
        SetVolumeMountPoint EQU <SetVolumeMountPointW>
    ELSE
        CreateHardLink EQU <CreateHardLinkA>
        CreateJobObject EQU <CreateJobObjectA>
        DeleteVolumeMountPoint EQU <DeleteVolumeMountPointA>
        DnsHostnameToComputerName EQU <DnsHostnameToComputerNameA>
        DosPathToSessionPath EQU <DosPathToSessionPathA>
        EnumLanguageGroupLocales EQU <EnumLanguageGroupLocalesA>
        EnumSystemLanguageGroups EQU <EnumSystemLanguageGroupsA>
        EnumUILanguages EQU <EnumUILanguagesA>
        FindActCtxSectionString EQU <FindActCtxSectionStringA>
        FindFirstVolume EQU <FindFirstVolumeA>
        FindFirstVolumeMountPoint EQU <FindFirstVolumeMountPointA>
        FindNextVolume EQU <FindNextVolumeA>
        FindNextVolumeMountPoint EQU <FindNextVolumeMountPointA>
        GetComputerNameEx EQU <GetComputerNameExA>
        GetSystemWindowsDirectory EQU <GetSystemWindowsDirectoryA>
        GetVolumeNameForVolumeMountPoint EQU <GetVolumeNameForVolumeMountPointA>
        GetVolumePathName EQU <GetVolumePathNameA>
        MoveFileWithProgress EQU <MoveFileWithProgressA>
        OpenJobObject EQU <OpenJobObjectA>
        ReplaceFile EQU <ReplaceFileA>
        SetComputerNameEx EQU <SetComputerNameExA>
        SetVolumeMountPoint EQU <SetVolumeMountPointA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINXP)
    ActivateActCtx PROTO :HANDLE, :XPTR
    AddLocalAlternateComputerNameA PROTO :LPCTSTR, :XWORD
    AddLocalAlternateComputerNameW PROTO :LPCWSTR, :XWORD
    AddRefActCtx PROTO :HANDLE
    AddVectoredExceptionHandler PROTO :XWORD, :XPTR
    AttachConsole PROTO :XWORD
    CancelWaitableTimer PROTO :HANDLE
    ConvertFiberToThread PROTO
    CreateActCtxA PROTO :XPTR
    CreateActCtxW PROTO :XPTR
    CreateFiberEx PROTO :SIZE_T, :SIZE_T, :XWORD, :XPTR, :LPVOID
    CreateJobSet PROTO :XWORD, :XPTR, :XWORD
    CreateMemoryResourceNotification PROTO :XWORD
    CreateProcessInternalA PROTO :HANDLE, :LPTSTR, :XPTR, :XPTR, :XWORD, :XWORD, :LPVOID, :LPCTSTR, :XPTR, :XPTR
    CreateProcessInternalW PROTO :HANDLE, :LPWSTR, :XPTR, :XPTR, :XWORD, :XWORD, :LPVOID, :LPCWSTR, :XPTR, :XPTR
    DeactivateActCtx PROTO :XWORD, :XPTR
    DebugActiveProcessStop PROTO :XWORD
    DebugBreakProcess PROTO :HANDLE
    DebugSetProcessKillOnExit PROTO :XWORD
    DeleteTimerQueueEx PROTO :HANDLE, :HANDLE
    DeleteTimerQueueTimer PROTO :HANDLE, :HANDLE, :HANDLE
    EnumerateLocalComputerNamesA PROTO :XWORD, :XWORD, :XWORD, :XWORD
    EnumerateLocalComputerNamesW PROTO :XWORD, :XWORD, :XWORD, :XWORD
    EnumSystemGeoID PROTO :XWORD, :XWORD, :XPTR
    FindActCtxSectionGuid PROTO :XWORD, :XPTR, :XWORD, :XPTR, :XPTR
    FindActCtxSectionStringA PROTO :XWORD, :XPTR, :XWORD, :LPCTSTR, :XPTR
    FindActCtxSectionStringW PROTO :XWORD, :XPTR, :XWORD, :LPCWSTR, :XPTR
    FlsAlloc PROTO :XPTR
    FlsFree PROTO :XWORD
    FlsGetValue PROTO :XWORD
    FlsSetValue PROTO :XWORD, :PVOID
    GetConsoleDisplayMode PROTO :LPDWORD
    GetConsoleFontInfo PROTO :HANDLE, :XWORD, :XPTR
    GetConsoleFontSize PROTO :HANDLE, :XWORD
    GetConsoleProcessList PROTO :LPDWORD, :XWORD
    GetConsoleSelectionInfo PROTO :XPTR
    GetCurrentActCtx PROTO :XPTR
    GetCurrentConsoleFont PROTO :HANDLE, :XWORD, :XPTR
    GetDllDirectoryA PROTO :XWORD, :LPTSTR
    GetDllDirectoryW PROTO :XWORD, :LPWSTR
    GetGeoInfoA PROTO :XWORD, :XWORD, :LPTSTR, :XWORD, :XWORD
    GetGeoInfoW PROTO :XWORD, :XWORD, :LPWSTR, :XWORD, :XWORD
    GetNativeSystemInfo PROTO :XPTR
    GetProcessId PROTO :HANDLE
    GetSystemWow64DirectoryA PROTO :LPTSTR, :XWORD
    GetSystemWow64DirectoryW PROTO :LPWSTR, :XWORD
    GetThreadId PROTO :HANDLE
    GetUserGeoID PROTO :XWORD
    GetVolumePathNamesForVolumeNameA PROTO :LPCTSTR, :LPTSTR, :XWORD, :XPTR
    GetVolumePathNamesForVolumeNameW PROTO :LPCWSTR, :LPWSTR, :XWORD, :XPTR
    GetWriteWatch PROTO :XWORD, :PVOID, :SIZE_T, :PVOID, :XPTR, :PULONG
    HeapQueryInformation PROTO :HANDLE, :XWORD, :PVOID, :SIZE_T, :XPTR
    HeapSetInformation PROTO :HANDLE, :XWORD, :PVOID, :SIZE_T
    InitializeCriticalSectionAndSpinCount PROTO :XPTR, :XWORD
    InitializeSListHead PROTO :XPTR
    InterlockedFlushSList PROTO :XPTR
    InterlockedPopEntrySList PROTO :XPTR
    InterlockedPushEntrySList PROTO :XPTR, :XPTR
    IsProcessInJob PROTO :HANDLE, :HANDLE, :XPTR
    Module32FirstW PROTO :HANDLE, :XPTR
    Module32NextW PROTO :HANDLE, :XPTR
    OpenEncryptedFileRawA PROTO :XPTR, :XWORD, :PVOID
    OpenEncryptedFileRawW PROTO :XPTR, :XWORD, :PVOID
    Process32FirstW PROTO :HANDLE, :XPTR
    Process32NextW PROTO :HANDLE, :XPTR
    IFDEF APP_UNICODE
        Module32First EQU <Module32FirstW>
        Module32Next EQU <Module32NextW>
        Process32First EQU <Process32FirstW>
        Process32Next EQU <Process32NextW>
    ELSE
        Module32First PROTO :HANDLE, :XPTR
        Module32Next PROTO :HANDLE, :XPTR
        Process32First PROTO :HANDLE, :XPTR
        Process32Next PROTO :HANDLE, :XPTR
    ENDIF
    QueryActCtxW PROTO :XWORD, :HANDLE, :XPTR, :XWORD, :PVOID, :SIZE_T, :SIZE_T
    QueryDepthSList PROTO :XPTR
    QueryMemoryResourceNotification PROTO :HANDLE, :XPTR
    QueueUserWorkItem PROTO :XPTR, :PVOID, :XWORD
    ReleaseActCtx PROTO :HANDLE
    RemoveVectoredExceptionHandler PROTO :PVOID
    IF (NTDDI_VERSION GE NTDDI_WIN8)
        ResolveDelayLoadedAPI PROTO :PVOID, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD
        ResolveDelayLoadsFromDll PROTO :PVOID, :LPCSTR, :XWORD
    ENDIF
    RtlCaptureContext PROTO :XPTR
    RtlCaptureStackBackTrace PROTO :XWORD, :XWORD, :PVOID, :PULONG
    RtlRaiseException PROTO :XPTR
    SetConsoleDisplayMode PROTO :HANDLE, :XWORD, :XPTR
    SetConsoleFont PROTO :HANDLE, :XWORD
    SetFileShortNameA PROTO :HANDLE, :LPCTSTR
    SetFileShortNameW PROTO :HANDLE, :LPCTSTR
    SetFileValidData PROTO :HANDLE, :XWORD
    SetLocalPrimaryComputerNameA PROTO :LPCSTR, :XWORD
    SetLocalPrimaryComputerNameW PROTO :LPWSTR, :XWORD
    SetThreadUILanguage PROTO :XWORD
    SetUserGeoID PROTO :XWORD
    TryEnterCriticalSection PROTO :XPTR
    TzSpecificLocalTimeToSystemTime PROTO :XPTR, :XPTR, :XPTR
    uaw_lstrcmpiW PROTO :XPTR, :XPTR
    uaw_lstrcmpW PROTO :XPTR, :XPTR
    uaw_lstrlenW PROTO :XPTR
    uaw_wcschr PROTO :XPTR, :XWORD
    uaw_wcscpy PROTO :XPTR, :XPTR
    uaw_wcsicmp PROTO :XPTR, :XPTR
    uaw_wcslen PROTO :XPTR
    uaw_wcsrchr PROTO :XPTR, :XWORD
    UnregisterWaitEx PROTO :HANDLE, :HANDLE
    ZombifyActCtx PROTO :HANDLE

    CaptureStackBackTrace EQU <RtlCaptureStackBackTrace>

    IF DEFINED(APP_WIN64) OR NTDDI_VERSION GE NTDDI_WINXPSP3 OR NTDDI_VERSION GE NTDDI_WS03SP1
        EnumSystemFirmwareTables PROTO :XWORD, :PVOID, :XWORD
        GetLogicalProcessorInformation PROTO :XPTR, :XPTR
        GetNumaHighestNodeNumber PROTO :PULONG
        GetSystemFileCacheSize PROTO :XPTR, :XPTR, :XPTR
        GetSystemFirmwareTable PROTO :XWORD, :XWORD, :PVOID, :XWORD
        RemoveVectoredContinueHandler PROTO :PVOID
        SetSystemFileCacheSize PROTO :SIZE_T, :SIZE_T, :XWORD
        SetThreadStackGuarantee PROTO :XPTR
        Wow64DisableWow64FsRedirection PROTO :PVOID
        Wow64RevertWow64FsRedirection PROTO :PVOID
    ENDIF

    IFDEF APP_WIN64
        RtlAddFunctionTable PROTO :XPTR, :XWORD, :XWORD, :XWORD
        RtlDeleteFunctionTable PROTO :XPTR
        RtlInstallFunctionTableCallback PROTO :XWORD, :XWORD, :XWORD, :XPTR, :PVOID, :XPTR
        RtlLookupFunctionEntry PROTO :XWORD, :XPTR, :XPTR
        RtlPcToFileHeader PROTO :PVOID, :PVOID
        RtlRestoreContext PROTO :XPTR, :XPTR
        RtlUnwindEx PROTO :XPTR, :PVOID, :XPTR, :PVOID, :XPTR, :XPTR
        RtlVirtualUnwind PROTO :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :PVOID, :XPTR, :XPTR
    ELSE
        RtlVirtualUnwind PROTO :XWORD, :XWORD, :XPTR, :XPTR, :PVOID, :XPTR, :XPTR
    ENDIF

    IFDEF APP_UNICODE
        AddLocalAlternateComputerName EQU <AddLocalAlternateComputerNameW>
        CreateActCtx EQU <CreateActCtxW>
        CreateProcessInternal EQU <CreateProcessInternalW>
        EnumerateLocalComputerNames EQU <EnumerateLocalComputerNamesW>
        GetDllDirectory EQU <GetDllDirectoryW>
        GetGeoInfo EQU <GetGeoInfoW>
        GetSystemWow64Directory EQU <GetSystemWow64DirectoryW>
        GetVolumePathNamesForVolumeName EQU <GetVolumePathNamesForVolumeNameW>
        OpenEncryptedFileRaw EQU <OpenEncryptedFileRawW>
        SetFileShortName EQU <SetFileShortNameW>
        SetLocalPrimaryComputerName EQU <SetLocalPrimaryComputerNameW>
    ELSE
        AddLocalAlternateComputerName EQU <AddLocalAlternateComputerNameA>
        CreateActCtx EQU <CreateActCtxA>
        CreateProcessInternal EQU <CreateProcessInternalA>
        EnumerateLocalComputerNames EQU <EnumerateLocalComputerNamesA>
        GetDllDirectory EQU <GetDllDirectoryA>
        GetGeoInfo EQU <GetGeoInfoA>
        GetSystemWow64Directory EQU <GetSystemWow64DirectoryA>
        GetVolumePathNamesForVolumeName EQU <GetVolumePathNamesForVolumeNameA>
        OpenEncryptedFileRaw EQU <OpenEncryptedFileRawA>
        SetFileShortName EQU <SetFileShortNameA>
        SetLocalPrimaryComputerName EQU <SetLocalPrimaryComputerNameA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINXPSP1)
    CheckNameLegalDOS8Dot3A PROTO :LPCTSTR, :LPSTR, :XWORD, :XPTR, :XPTR
    CheckNameLegalDOS8Dot3W PROTO :LPCWSTR, :LPWSTR, :XWORD, :XPTR, :XPTR
    CheckRemoteDebuggerPresent PROTO :HANDLE, :XPTR
    ConvertThreadToFiberEx PROTO :LPVOID, :XWORD
    GetFirmwareEnvironmentVariableA PROTO :LPCTSTR, :LPCTSTR, :PVOID, :XWORD
    GetFirmwareEnvironmentVariableW PROTO :LPCWSTR, :LPCWSTR, :PVOID, :XWORD
    GetProcessHandleCount PROTO :HANDLE, :XPTR
    GetSystemRegistryQuota PROTO :XPTR, :XPTR
    GetSystemTimes PROTO :XPTR, :XPTR, :XPTR
    GetThreadIOPendingFlag PROTO :HANDLE, :XPTR
    SetFirmwareEnvironmentVariableA PROTO :LPCTSTR, :LPCTSTR, :PVOID, :XWORD
    SetFirmwareEnvironmentVariableW PROTO :LPCWSTR, :LPCWSTR, :PVOID, :XWORD
    IFDEF APP_UNICODE
        CheckNameLegalDOS8Dot3 EQU <CheckNameLegalDOS8Dot3W>
        GetFirmwareEnvironmentVariable EQU <GetFirmwareEnvironmentVariableW>
        SetFirmwareEnvironmentVariable EQU <SetFirmwareEnvironmentVariableW>
    ELSE
        CheckNameLegalDOS8Dot3 EQU <CheckNameLegalDOS8Dot3A>
        GetFirmwareEnvironmentVariable EQU <GetFirmwareEnvironmentVariableA>
        SetFirmwareEnvironmentVariable EQU <SetFirmwareEnvironmentVariableA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINXPSP2)
    GetNumaAvailableMemoryNode PROTO :XWORD, :XPTR
    GetNumaNodeProcessorMask PROTO :XWORD, :XPTR
    GetNumaProcessorNode PROTO :XWORD, :XPTR
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINXPSP2 OR NTDDI_VERSION GE NTDDI_WS03SP1)
    DecodePointer PROTO :PVOID
    DecodeSystemPointer PROTO :PVOID
    EncodePointer PROTO :PVOID
    EncodeSystemPointer PROTO :PVOID
    IsWow64Process PROTO :HANDLE, :XPTR
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINXPSP3)
    GetSystemDEPPolicy PROTO
    GetProcessDEPPolicy PROTO :HANDLE, :LPDWORD, :XPTR
    SetProcessDEPPolicy PROTO :XWORD
ENDIF

IF (NTDDI_VERSION GE NTDDI_WS03)
    FindFirstStreamW PROTO :LPCWSTR, :XWORD, :LPVOID, :XWORD
    FindNextStreamW PROTO :HANDLE, :LPVOID
    GetLargePageMinimum PROTO
    GetProcessIdOfThread PROTO :HANDLE
    GetProcessWorkingSetSizeEx PROTO :HANDLE, :XPTR, :XPTR, :XPTR
    ReOpenFile PROTO :HANDLE, :XWORD, :XWORD, :XWORD
    SetDllDirectoryA PROTO :LPCTSTR
    SetDllDirectoryW PROTO :LPCWSTR
    SetEnvironmentStringsA PROTO :LPCTSTR
    SetEnvironmentStringsW PROTO :LPCWSTR
    SetProcessWorkingSetSizeEx PROTO :HANDLE, :SIZE_T, :SIZE_T, :XWORD
    Wow64EnableWow64FsRedirection PROTO :XWORD
    WTSGetActiveConsoleSessionId PROTO
    IFDEF APP_UNICODE
        SetDllDirectory EQU <SetDllDirectoryW>
        SetEnvironmentStrings EQU <SetEnvironmentStringsW>
    ELSE
        SetDllDirectory EQU <SetDllDirectoryA>
        SetEnvironmentStrings EQU <SetEnvironmentStringsA>
    ENDIF
ENDIF

IFNDEF APP_WIN64
    IF (NTDDI_VERSION LE NTDDI_VISTA)
        InterlockedCompareExchange PROTO :XPTR, :XWORD, :XWORD
        InterlockedCompareExchange64 PROTO :XPTR, :XWORD, :XWORD
        InterlockedExchangeAdd PROTO :XPTR, :XWORD
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_VISTA)
    AcquireSRWLockExclusive PROTO :XPTR
    AcquireSRWLockShared PROTO :XPTR
    AddDllDirectory PROTO :XPTR
    AddSIDToBoundaryDescriptor PROTO :HANDLE, :XPTR
    AddVectoredContinueHandler PROTO :XWORD, :XPTR
    AdjustCalendarDate PROTO :XPTR, :XWORD
    AllocateUserPhysicalPagesNuma PROTO :HANDLE, :XPTR, :XPTR, :XWORD
    ApplicationRecoveryFinished PROTO :XWORD
    ApplicationRecoveryInProgress PROTO :XPTR
    CallbackMayRunLong PROTO :XPTR
    CancelIoEx PROTO :HANDLE, :XPTR
    CancelSynchronousIo PROTO :HANDLE
    CancelThreadpoolIo PROTO :XPTR
    CheckElevationEnabled PROTO :LPBOOL
    ClosePrivateNamespace PROTO :HANDLE, :XWORD
    CloseThreadpool PROTO :XPTR
    CloseThreadpoolCleanupGroup PROTO :XPTR
    CloseThreadpoolCleanupGroupMembers PROTO :XPTR, :XWORD, :PVOID
    CloseThreadpoolIo PROTO :XPTR
    CloseThreadpoolTimer PROTO :XPTR
    CloseThreadpoolWait PROTO :XPTR
    CloseThreadpoolWork PROTO :XPTR
    CompareStringEx PROTO :LPCWSTR, :XWORD, :LPCWSTR, :XWORD, :LPCWSTR, :XWORD, :XPTR, :LPVOID, :LPARAM
    CompareStringOrdinal PROTO :LPCWSTR, :XWORD, :LPCWSTR, :XWORD, :XWORD
    ConvertCalDateTimeToSystemTime PROTO :XPTR, :XPTR
    ConvertSystemTimeToCalDateTime PROTO :XPTR, :XWORD, :XPTR
    CopyFileTransactedA PROTO :LPCTSTR, :LPCTSTR, :XPTR, :LPVOID, :LPBOOL, :XWORD, :HANDLE
    CopyFileTransactedW PROTO :LPCWSTR, :LPCWSTR, :XPTR, :LPVOID, :LPBOOL, :XWORD, :HANDLE
    CreateBoundaryDescriptorA PROTO :LPCTSTR, :XWORD
    CreateBoundaryDescriptorW PROTO :LPCWSTR, :XWORD
    CreateDirectoryTransactedA PROTO :LPCTSTR, :LPCTSTR, :XPTR, :HANDLE
    CreateDirectoryTransactedW PROTO :LPCWSTR, :LPCWSTR, :XPTR, :HANDLE
    CreateEventExA PROTO :XPTR, :LPCTSTR, :XWORD, :XWORD
    CreateEventExW PROTO :XPTR, :LPCWSTR, :XWORD, :XWORD
    CreateFileMappingNumaA PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :XWORD, :LPCTSTR, :XWORD
    CreateFileMappingNumaW PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :XWORD, :LPCWSTR, :XWORD
    CreateFileTransactedA PROTO :LPCTSTR, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD, :HANDLE, :HANDLE, :XPTR, :PVOID
    CreateFileTransactedW PROTO :LPCWSTR, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD, :HANDLE, :HANDLE, :XPTR, :PVOID
    CreateHardLinkTransactedA PROTO :LPCTSTR, :LPCTSTR, :XPTR, :HANDLE
    CreateHardLinkTransactedW PROTO :LPCWSTR, :LPCWSTR, :XPTR, :HANDLE
    CreateMutexExA PROTO :XPTR, :LPCTSTR, :XWORD, :XWORD
    CreateMutexExW PROTO :XPTR, :LPCWSTR, :XWORD, :XWORD
    CreatePrivateNamespaceA PROTO :XPTR, :LPVOID, :LPCTSTR
    CreatePrivateNamespaceW PROTO :XPTR, :LPVOID, :LPCWSTR
    CreateSemaphoreExA PROTO :XPTR, :XWORD, :XWORD, :LPCTSTR, :XWORD, :XWORD
    CreateSemaphoreExW PROTO :XPTR, :XWORD, :XWORD, :LPCWSTR, :XWORD, :XWORD
    CreateSymbolicLinkA PROTO :LPTSTR, :LPTSTR, :XWORD
    CreateSymbolicLinkTransactedA PROTO :LPTSTR, :LPTSTR, :XWORD, :HANDLE
    CreateSymbolicLinkTransactedW PROTO :LPWSTR, :LPWSTR, :XWORD, :HANDLE
    CreateSymbolicLinkW PROTO :LPWSTR, :LPWSTR, :XWORD
    CreateThreadpool PROTO :PVOID
    CreateThreadpoolCleanupGroup PROTO
    CreateThreadpoolIo PROTO :HANDLE, :XPTR, :PVOID, :XPTR
    CreateThreadpoolTimer PROTO :XPTR, :PVOID, :XPTR
    CreateThreadpoolWait PROTO :XPTR, :PVOID, :XPTR
    CreateThreadpoolWork PROTO :XPTR, :PVOID, :XPTR
    CreateWaitableTimerExA PROTO :XPTR, :LPCTSTR, :XWORD, :XWORD
    CreateWaitableTimerExW PROTO :XPTR, :LPCWSTR, :XWORD, :XWORD
    DeleteBoundaryDescriptor PROTO :HANDLE
    DeleteFileTransactedA PROTO :LPCTSTR, :HANDLE
    DeleteFileTransactedW PROTO :LPCWSTR, :HANDLE
    DeleteProcThreadAttributeList PROTO :XPTR
    DisassociateCurrentThreadFromCallback PROTO :XPTR
    EnumCalendarInfoExEx PROTO :XPTR, :LPCWSTR, :XWORD, :LPCWSTR, :XWORD, :LPARAM
    EnumDateFormatsExEx PROTO :XPTR, :LPCWSTR, :XWORD, :LPARAM
    EnumResourceLanguagesExA PROTO :HMODULE, :LPCTSTR, :LPCTSTR, :XPTR, :LONG_PTR, :XWORD, :XWORD
    EnumResourceLanguagesExW PROTO :HMODULE, :LPCWSTR, :LPCWSTR, :XPTR, :LONG_PTR, :XWORD, :XWORD
    EnumResourceNamesExA PROTO :HMODULE, :LPCTSTR, :XPTR, :LONG_PTR, :XWORD, :XWORD
    EnumResourceNamesExW PROTO :HMODULE, :LPCWSTR, :XPTR, :LONG_PTR, :XWORD, :XWORD
    EnumResourceTypesExA PROTO :HMODULE, :XPTR, :LONG_PTR, :XWORD, :XWORD
    EnumResourceTypesExW PROTO :HMODULE, :XPTR, :LONG_PTR, :XWORD, :XWORD
    EnumSystemLocalesEx PROTO :XPTR, :XWORD, :LPARAM, :LPVOID
    EnumTimeFormatsEx PROTO :XPTR, :LPCWSTR, :XWORD, :LPARAM
    FindFirstFileNameTransactedW PROTO :LPCWSTR, :XWORD, :LPDWORD, :XPTR, :HANDLE
    FindFirstFileNameW PROTO :LPCWSTR, :XWORD, :LPDWORD, :XPTR
    FindFirstFileTransactedA PROTO :LPCTSTR, :XWORD, :LPVOID, :XWORD, :LPVOID, :XWORD, :HANDLE
    FindFirstFileTransactedW PROTO :LPCWSTR, :XWORD, :LPVOID, :XWORD, :LPVOID, :XWORD, :HANDLE
    FindFirstStreamTransactedW PROTO :LPCWSTR, :XWORD, :LPVOID, :XWORD, :HANDLE
    FindNextFileNameW PROTO :HANDLE, :LPDWORD, :XPTR
    FindNLSString PROTO :XWORD, :XWORD, :LPCWSTR, :XWORD, :LPCWSTR, :XWORD, :XPTR
    FindNLSStringEx PROTO :LPCWSTR, :XWORD, :LPCWSTR, :XWORD, :LPCWSTR, :XWORD, :XPTR, :XPTR, :LPVOID, :LPARAM
    FlushProcessWriteBuffers PROTO
    FreeLibraryWhenCallbackReturns PROTO :XPTR, :HMODULE
    GetApplicationRecoveryCallback PROTO :HANDLE, :XPTR, :PVOID, :XPTR, :XPTR
    GetApplicationRestartSettings PROTO :HANDLE, :XPTR, :XPTR, :XPTR
    GetCalendarDateFormatEx PROTO :LPCWSTR, :XWORD, :XPTR, :LPCWSTR, :LPWSTR, :XWORD
    GetCalendarInfoEx PROTO :LPCWSTR, :XWORD, :LPCWSTR, :XWORD, :LPWSTR, :XWORD, :LPDWORD
    GetCalendarSupportedDateRange PROTO :XWORD, :XPTR, :XPTR
    GetComPlusPackageInstallStatus PROTO
    GetCompressedFileSizeTransactedA PROTO :LPCTSTR, :LPDWORD, :HANDLE
    GetCompressedFileSizeTransactedW PROTO :LPCWSTR, :LPDWORD, :HANDLE
    GetConsoleHistoryInfo PROTO :XPTR
    GetConsoleOriginalTitleA PROTO :LPTSTR, :XWORD
    GetConsoleOriginalTitleW PROTO :LPWSTR, :XWORD
    GetConsoleScreenBufferInfoEx PROTO :HANDLE, :XPTR
    GetCurrencyFormatEx PROTO :LPCWSTR, :XWORD, :LPCWSTR, :XPTR, :LPWSTR, :XWORD
    GetCurrentConsoleFontEx PROTO :HANDLE, :XWORD, :XPTR
    GetCurrentProcessorNumber PROTO
    GetDateFormatEx PROTO :LPCWSTR, :XWORD, :XPTR, :LPCWSTR, :LPWSTR, :XWORD, :LPCWSTR
    GetDurationFormat PROTO :XWORD, :XWORD, :XPTR, :XWORD, :LPCWSTR, :LPWSTR, :XWORD
    GetDurationFormatEx PROTO :LPCWSTR, :XWORD, :XPTR, :XWORD, :LPCWSTR, :LPWSTR, :XWORD
    GetDynamicTimeZoneInformation PROTO :XPTR
    GetFileAttributesTransactedA PROTO :LPCTSTR, :XWORD, :LPVOID, :HANDLE
    GetFileAttributesTransactedW PROTO :LPCWSTR, :XWORD, :LPVOID, :HANDLE
    GetFileBandwidthReservation PROTO :HANDLE, :LPDWORD, :LPDWORD, :LPBOOL, :LPDWORD, :LPDWORD
    GetFileInformationByHandleEx PROTO :HANDLE, :XWORD, :LPVOID, :XWORD
    GetFileMUIInfo PROTO :XWORD, :XPTR, :XPTR, :XPTR
    GetFileMUIPath PROTO :XWORD, :XPTR, :XPTR, :PULONG, :XPTR, :PULONG, :XPTR
    GetFinalPathNameByHandleA PROTO :HANDLE, :LPTSTR, :XWORD, :XWORD
    GetFinalPathNameByHandleW PROTO :HANDLE, :LPWSTR, :XWORD, :XWORD
    GetFullPathNameTransactedA PROTO :LPCTSTR, :XWORD, :LPTSTR, :LPTSTR, :HANDLE
    GetFullPathNameTransactedW PROTO :LPCWSTR, :XWORD, :LPWSTR, :LPWSTR, :HANDLE
    GetLocaleInfoEx PROTO :LPCWSTR, :XWORD, :LPWSTR, :XWORD
    GetLongPathNameTransactedA PROTO :LPCTSTR, :LPTSTR, :XWORD, :HANDLE
    GetLongPathNameTransactedW PROTO :LPCWSTR, :LPWSTR, :XWORD, :HANDLE
    GetNamedPipeAttribute PROTO :HANDLE, :XWORD, :XWORD, :PVOID, :XPTR
    GetNamedPipeClientComputerNameA PROTO :HANDLE, :LPTSTR, :XWORD
    GetNamedPipeClientComputerNameW PROTO :HANDLE, :LPWSTR, :XWORD
    GetNamedPipeClientProcessId PROTO :HANDLE, :XPTR
    GetNamedPipeClientSessionId PROTO :HANDLE, :XPTR
    GetNamedPipeServerProcessId PROTO :HANDLE, :XPTR
    GetNamedPipeServerSessionId PROTO :HANDLE, :XPTR
    GetNLSVersion PROTO :XWORD, :XWORD, :XPTR
    GetNLSVersionEx PROTO :XWORD, :LPCWSTR, :XPTR
    GetNumaProximityNode PROTO :XWORD, :XPTR
    GetNumberFormatEx PROTO :LPCWSTR, :XWORD, :LPCWSTR, :XPTR, :LPWSTR, :XWORD
    GetProductInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
    GetQueuedCompletionStatusEx PROTO :HANDLE, :XPTR, :XWORD, :XPTR, :XWORD, :XWORD
    GetStringScripts PROTO :XWORD, :LPCWSTR, :XWORD, :LPWSTR, :XWORD
    GetSystemDefaultLocaleName PROTO :LPWSTR, :XWORD
    GetSystemPreferredUILanguages PROTO :XWORD, :PULONG, :XPTR, :PULONG
    GetThreadPreferredUILanguages PROTO :XWORD, :PULONG, :XPTR, :PULONG
    GetThreadUILanguage PROTO
    GetTickCount64 PROTO
    GetTimeFormatEx PROTO :LPCWSTR, :XWORD, :XPTR, :LPCWSTR, :LPWSTR, :XWORD
    GetUILanguageInfo PROTO :XWORD, :XPTR, :XPTR, :XPTR, :XPTR
    GetUserDefaultLocaleName PROTO :LPWSTR, :XWORD
    GetUserPreferredUILanguages PROTO :XWORD, :PULONG, :XPTR, :PULONG
    GetVolumeInformationByHandleW PROTO :HANDLE, :LPWSTR, :XWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPWSTR, :XWORD
    IdnToAscii PROTO :XWORD, :LPCWSTR, :XWORD, :LPWSTR, :XWORD
    IdnToNameprepUnicode PROTO :XWORD, :LPCWSTR, :XWORD, :LPWSTR, :XWORD
    IdnToUnicode PROTO :XWORD, :LPCWSTR, :XWORD, :LPWSTR, :XWORD
    InitOnceBeginInitialize PROTO :XPTR, :XWORD, :XPTR, :LPVOID
    InitOnceComplete PROTO :XPTR, :XWORD, :LPVOID
    InitOnceExecuteOnce PROTO :XPTR, :XPTR, :XPTR, :LPVOID
    InitOnceInitialize PROTO :XPTR
    InitializeConditionVariable PROTO :XPTR
    InitializeCriticalSectionEx PROTO :XPTR, :XWORD, :XWORD
    InitializeProcThreadAttributeList PROTO :XPTR, :XWORD, :XWORD, :XPTR
    InitializeSRWLock PROTO :XPTR
    InterlockedPushListSList PROTO :XPTR, :XPTR, :XPTR, :XWORD
    IsCalendarLeapDay PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IsCalendarLeapMonth PROTO :XWORD, :XWORD, :XWORD, :XWORD
    IsCalendarLeapYear PROTO :XWORD, :XWORD, :XWORD
    IsNLSDefinedString PROTO :XWORD, :XWORD, :XPTR, :LPCWSTR, :XWORD
    IsNormalizedString PROTO :XWORD, :LPCWSTR, :XWORD
    IsThreadAFiber PROTO
    IsThreadpoolTimerSet PROTO :XPTR
    IF (NTDDI_VERSION NE NTDDI_WIN81)
        IsTimeZoneRedirectionEnabled PROTO
    ENDIF
    IsValidCalDateTime PROTO :XWORD, :XWORD
    IsValidLocaleName PROTO :LPCWSTR
    LCIDToLocaleName PROTO :XWORD, :LPWSTR, :XWORD, :XWORD
    LCMapStringEx PROTO :LPCWSTR, :XWORD, :LPCWSTR, :XWORD, :LPWSTR, :XWORD, :XPTR, :LPVOID, :LPARAM
    LeaveCriticalSectionWhenCallbackReturns PROTO :XPTR, :XPTR
    LoadStringBaseExW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    LoadStringBaseW PROTO :XWORD, :XWORD, :XWORD, :XWORD
    LocaleNameToLCID PROTO :LPCWSTR, :XWORD
    MapViewOfFileExNuma PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :SIZE_T, :LPVOID, :XWORD
    MoveFileTransactedA PROTO :LPCTSTR, :LPCTSTR, :XPTR, :LPVOID, :XWORD, :HANDLE
    MoveFileTransactedW PROTO :LPCWSTR, :LPCWSTR, :XPTR, :LPVOID, :XWORD, :HANDLE
    NeedCurrentDirectoryForExePathA PROTO :LPCTSTR
    NeedCurrentDirectoryForExePathW PROTO :LPCWSTR
    NormalizeString PROTO :XWORD, :LPCWSTR, :XWORD, :LPWSTR, :XWORD
    OpenFileById PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :XPTR, :XWORD
    OpenPrivateNamespaceA PROTO :LPVOID, :LPCTSTR
    OpenPrivateNamespaceW PROTO :LPVOID, :LPCWSTR
    QueryActCtxSettingsW PROTO :XWORD, :HANDLE, :XPTR, :XPTR, :XPTR, :SIZE_T, :XPTR
    QueryFullProcessImageNameA PROTO :HANDLE, :XWORD, :LPTSTR, :XPTR
    QueryFullProcessImageNameW PROTO :HANDLE, :XWORD, :LPWSTR, :XPTR
    QueryIdleProcessorCycleTime PROTO :XPTR, :XPTR
    QueryProcessCycleTime PROTO :HANDLE, :XPTR
    QueryThreadCycleTime PROTO :HANDLE, :XPTR
    RegisterApplicationRecoveryCallback PROTO :XPTR, :PVOID, :XWORD, :XWORD
    RegisterApplicationRestart PROTO :XPTR, :XWORD
    ReleaseMutexWhenCallbackReturns PROTO :XPTR, :HANDLE
    ReleaseSRWLockExclusive PROTO :XPTR
    ReleaseSRWLockShared PROTO :XPTR
    ReleaseSemaphoreWhenCallbackReturns PROTO :XPTR, :HANDLE, :XWORD
    RemoveDirectoryTransactedA PROTO :LPCTSTR, :HANDLE
    RemoveDirectoryTransactedW PROTO :LPCWSTR, :HANDLE
    RemoveDllDirectory PROTO :XPTR
    ReplacePartitionUnit PROTO :XPTR, :XPTR, :XWORD
    SetCurrentConsoleFontEx PROTO :HANDLE, :XWORD, :XPTR
    SetConsoleHistoryInfo PROTO :XPTR
    SetConsoleScreenBufferInfoEx PROTO :HANDLE, :XPTR
    SetCurrentConsoleFontEx PROTO :HANDLE, :XWORD, :XPTR
    SetDefaultDllDirectories PROTO :XWORD
    SetDynamicTimeZoneInformation PROTO :XPTR
    SetEventWhenCallbackReturns PROTO :XPTR, :HANDLE
    SetFileAttributesTransactedA PROTO :LPCTSTR, :XWORD, :HANDLE
    SetFileAttributesTransactedW PROTO :LPCWSTR, :XWORD, :HANDLE
    SetFileBandwidthReservation PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :LPDWORD, :LPDWORD
    SetFileCompletionNotificationModes PROTO :HANDLE, :XWORD
    SetFileInformationByHandle PROTO :HANDLE, :XWORD, :LPVOID, :XWORD
    SetFileIoOverlappedRange PROTO :HANDLE, :XPTR, :XWORD
    SetNamedPipeAttribute PROTO :HANDLE, :XWORD, :XPTR, :PVOID, :SIZE_T
    SetThreadpoolThreadMaximum PROTO :XPTR, :XWORD
    SetThreadpoolThreadMinimum PROTO :XPTR, :XWORD
    SetThreadpoolTimer PROTO :XPTR, :XPTR, :XWORD, :XWORD
    SetThreadpoolWait PROTO :XPTR, :HANDLE, :XPTR
    IF (NTDDI_VERSION GE NTDDI_WIN8)
        SetThreadpoolWaitEx PROTO :XPTR, :HANDLE, :PVOID
    ENDIF
    SetThreadPreferredUILanguages PROTO :XWORD, :XPTR, :PULONG
    SleepConditionVariableCS PROTO :XPTR, :XPTR, :XWORD
    SleepConditionVariableSRW PROTO :XPTR, :XPTR, :XWORD, :XWORD
    StartThreadpoolIo PROTO :XPTR
    SubmitThreadpoolWork PROTO :XPTR
    TrySubmitThreadpoolCallback PROTO :XPTR, :PVOID, :XPTR
    UnregisterApplicationRecoveryCallback PROTO
    UnregisterApplicationRestart PROTO
    UpdateCalendarDayOfWeek PROTO :XPTR
    UpdateProcThreadAttribute PROTO :XPTR, :XWORD, :XWORD, :PVOID, :SIZE_T, :PVOID, :XPTR
    VerifyScripts PROTO :XWORD, :LPCWSTR, :XWORD, :LPCWSTR, :XWORD
    VirtualAllocExNuma PROTO :HANDLE, :LPVOID, :SIZE_T, :XWORD, :XWORD, :XWORD
    WaitForThreadpoolIoCallbacks PROTO :XPTR, :XWORD
    WaitForThreadpoolTimerCallbacks PROTO :XPTR, :XWORD
    WaitForThreadpoolWaitCallbacks PROTO :XPTR, :XWORD
    WaitForThreadpoolWorkCallbacks PROTO :XPTR, :XWORD
    WakeAllConditionVariable PROTO :XPTR
    WakeConditionVariable PROTO :XPTR
    WerGetFlags PROTO :HANDLE, :XPTR
    WerRegisterFile PROTO :XPTR, :XWORD, :XWORD
    WerRegisterMemoryBlock PROTO :PVOID, :XWORD
    WerSetFlags PROTO :XWORD
    WerUnregisterFile PROTO :XPTR
    WerUnregisterMemoryBlock PROTO :PVOID
    Wow64GetThreadContext PROTO :HANDLE, :XPTR
    Wow64SetThreadContext PROTO :HANDLE, :XPTR
    Wow64SuspendThread PROTO :HANDLE
    IFDEF APP_UNICODE
        CopyFileTransacted EQU <CopyFileTransactedW>
        CreateBoundaryDescriptor EQU <CreateBoundaryDescriptorW>
        CreateDirectoryTransacted EQU <CreateDirectoryTransactedW>
        CreateEventEx EQU <CreateEventExW>
        CreateFileMappingNuma EQU <CreateFileMappingNumaW>
        CreateFileTransacted EQU <CreateFileTransactedW>
        CreateHardLinkTransacted EQU <CreateHardLinkTransactedW>
        CreateMutexEx EQU <CreateMutexExW>
        CreatePrivateNamespace EQU <CreatePrivateNamespaceW>
        CreateSemaphoreEx EQU <CreateSemaphoreExW>
        CreateSymbolicLink EQU <CreateSymbolicLinkW>
        CreateSymbolicLinkTransacted EQU <CreateSymbolicLinkTransactedW>
        CreateWaitableTimerEx EQU <CreateWaitableTimerExW>
        DeleteFileTransacted EQU <DeleteFileTransactedW>
        EnumResourceLanguagesEx EQU <EnumResourceLanguagesExW>
        EnumResourceNamesEx EQU <EnumResourceNamesExW>
        EnumResourceTypesEx EQU <EnumResourceTypesExW>
        FindFirstFileTransacted EQU <FindFirstFileTransactedW>
        GetCompressedFileSizeTransacted EQU <GetCompressedFileSizeTransactedW>
        GetConsoleOriginalTitle EQU <GetConsoleOriginalTitleW>
        GetFileAttributesTransacted EQU <GetFileAttributesTransactedW>
        GetFinalPathNameByHandle EQU <GetFinalPathNameByHandleW>
        GetFullPathNameTransacted EQU <GetFullPathNameTransactedW>
        GetLongPathNameTransacted EQU <GetLongPathNameTransactedW>
        GetNamedPipeClientComputerName EQU <GetNamedPipeClientComputerNameW>
        MoveFileTransacted EQU <MoveFileTransactedW>
        NeedCurrentDirectoryForExePath EQU <NeedCurrentDirectoryForExePathW>
        OpenPrivateNamespace EQU <OpenPrivateNamespaceW>
        QueryFullProcessImageName EQU <QueryFullProcessImageNameW>
        RemoveDirectoryTransacted EQU <RemoveDirectoryTransactedW>
        SetFileAttributesTransacted EQU <SetFileAttributesTransactedW>
    ELSE
        CopyFileTransacted EQU <CopyFileTransactedA>
        CreateBoundaryDescriptor EQU <CreateBoundaryDescriptorA>
        CreateDirectoryTransacted EQU <CreateDirectoryTransactedA>
        CreateEventEx EQU <CreateEventExA>
        CreateFileMappingNuma EQU <CreateFileMappingNumaA>
        CreateFileTransacted EQU <CreateFileTransactedA>
        CreateHardLinkTransacted EQU <CreateHardLinkTransactedA>
        CreateMutexEx EQU <CreateMutexExA>
        CreatePrivateNamespace EQU <CreatePrivateNamespaceA>
        CreateSemaphoreEx EQU <CreateSemaphoreExA>
        CreateSymbolicLink EQU <CreateSymbolicLinkA>
        CreateSymbolicLinkTransacted EQU <CreateSymbolicLinkTransactedA>
        CreateWaitableTimerEx EQU <CreateWaitableTimerExA>
        DeleteFileTransacted EQU <DeleteFileTransactedA>
        EnumResourceLanguagesEx EQU <EnumResourceLanguagesExA>
        EnumResourceNamesEx EQU <EnumResourceNamesExA>
        EnumResourceTypesEx EQU <EnumResourceTypesExA>
        FindFirstFileTransacted EQU <FindFirstFileTransactedA>
        GetCompressedFileSizeTransacted EQU <GetCompressedFileSizeTransactedA>
        GetConsoleOriginalTitle EQU <GetConsoleOriginalTitleA>
        GetFileAttributesTransacted EQU <GetFileAttributesTransactedA>
        GetFinalPathNameByHandle EQU <GetFinalPathNameByHandleA>
        GetFullPathNameTransacted EQU <GetFullPathNameTransactedA>
        GetLongPathNameTransacted EQU <GetLongPathNameTransactedA>
        GetNamedPipeClientComputerName EQU <GetNamedPipeClientComputerNameA>
        MoveFileTransacted EQU <MoveFileTransactedA>
        NeedCurrentDirectoryForExePath EQU <NeedCurrentDirectoryForExePathA>
        OpenPrivateNamespace EQU <OpenPrivateNamespaceA>
        QueryFullProcessImageName EQU <QueryFullProcessImageNameA>
        RemoveDirectoryTransacted EQU <RemoveDirectoryTransactedA>
        SetFileAttributesTransacted EQU <SetFileAttributesTransactedA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_VISTASP1)
    AddSecureMemoryCacheCallback PROTO :XPTR
    GetPhysicallyInstalledSystemMemory PROTO :PULONGLONG
    GetTimeZoneInformationForYear PROTO :XWORD, :XPTR, :XPTR
    QueryProcessAffinityUpdateMode PROTO :HANDLE, :XWORD
    RemoveSecureMemoryCacheCallback PROTO :XPTR
    SetProcessAffinityUpdateMode PROTO :HANDLE, :XWORD
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN7)
    AddIntegrityLabelToBoundaryDescriptor PROTO :HANDLE, :XPTR
    BaseFormatTimeOut PROTO :XPTR, :XWORD
    BaseGetNamedObjectDirectory PROTO :XPTR
    Basep8BitStringToDynamicUnicodeString PROTO :XPTR, :XPTR
    CreateRemoteThreadEx PROTO :HANDLE, :XPTR, :SIZE_T, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR
    DisableThreadProfiling PROTO :HANDLE
    EnableThreadProfiling PROTO :HANDLE, :XWORD, :XWORD, :HANDLE
    FindStringOrdinal PROTO :XWORD, :LPCWSTR, :XWORD, :LPCWSTR, :XWORD, :XWORD
    GetActiveProcessorCount PROTO :XWORD
    GetActiveProcessorGroupCount PROTO
    GetCurrentProcessorNumberEx PROTO :XPTR
    GetLogicalProcessorInformationEx PROTO :XWORD, :XPTR, :XPTR
    GetMaximumProcessorCount PROTO :XWORD
    GetMaximumProcessorGroupCount PROTO
    GetNumaAvailableMemoryNodeEx PROTO :XWORD, :XPTR
    GetNumaNodeNumberFromHandle PROTO :HANDLE, :XPTR
    GetNumaNodeProcessorMaskEx PROTO :XWORD, :XPTR
    GetNumaProcessorNodeEx PROTO :XPTR, :XPTR
    GetNumaProximityNodeEx PROTO :XWORD, :XPTR
    GetProcessGroupAffinity PROTO :HANDLE, :XPTR, :XPTR
    GetProcessorSystemCycleTime PROTO :XWORD, :XPTR, :XPTR
    GetProcessPreferredUILanguages PROTO :XWORD, :PULONG, :XPTR, :PULONG
    GetProcessUserModeExceptionPolicy PROTO :LPDWORD
    GetThreadErrorMode PROTO
    GetThreadGroupAffinity PROTO :HANDLE, :XPTR
    GetThreadIdealProcessorEx PROTO :HANDLE, :XPTR
    K32EmptyWorkingSet PROTO :HANDLE
    K32EnumDeviceDrivers PROTO :XWORD, :XWORD, :XWORD
    K32EnumPageFilesA PROTO :XPTR, :LPVOID
    K32EnumPageFilesW PROTO :XPTR, :LPVOID
    K32EnumProcessModules PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD
    K32EnumProcessModulesEx PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD, :XWORD
    K32EnumProcesses PROTO :XPTR, :XWORD, :XPTR
    K32GetDeviceDriverBaseNameA PROTO :LPVOID, :LPTSTR, :XWORD
    K32GetDeviceDriverBaseNameW PROTO :LPVOID, :LPWSTR, :XWORD
    K32GetDeviceDriverFileNameA PROTO :LPVOID, :LPTSTR, :XWORD
    K32GetDeviceDriverFileNameW PROTO :LPVOID, :LPWSTR, :XWORD
    K32GetMappedFileNameA PROTO :HANDLE, :LPVOID, :LPSTR, :XWORD
    K32GetMappedFileNameW PROTO :HANDLE, :LPVOID, :LPWSTR, :XWORD
    K32GetModuleBaseNameA PROTO :HANDLE, :HMODULE, :LPTSTR, :XWORD
    K32GetModuleBaseNameW PROTO :HANDLE, :HMODULE, :LPWSTR, :XWORD
    K32GetModuleFileNameExA PROTO :HANDLE, :HMODULE, :LPTSTR, :XWORD
    K32GetModuleFileNameExW PROTO :HANDLE, :HMODULE, :LPWSTR, :XWORD
    K32GetModuleInformation PROTO :HANDLE, :HMODULE, :XPTR, :XWORD
    K32GetPerformanceInfo PROTO :XPTR, :XWORD
    K32GetProcessImageFileNameA PROTO :HANDLE, :LPTSTR, :XWORD
    K32GetProcessImageFileNameW PROTO :HANDLE, :LPWSTR, :XWORD
    K32GetProcessMemoryInfo PROTO :HANDLE, :XPTR, :XWORD
    K32GetWsChanges PROTO :HANDLE, :XPTR, :XWORD
    K32GetWsChangesEx PROTO :HANDLE, :XPTR, :XPTR
    K32InitializeProcessForWsWatch PROTO :HANDLE
    K32QueryWorkingSet PROTO :HANDLE, :XPTR, :XWORD
    K32QueryWorkingSetEx PROTO :HANDLE, :PVOID, :XWORD
    LoadAppInitDlls PROTO
    NotifyUILanguageChange PROTO :XWORD, :XPTR, :XPTR, :XWORD, :XPTR
    OpenProcessToken PROTO :HANDLE, :XWORD, :XPTR
    OpenThreadToken PROTO :HANDLE, :XWORD, :XWORD, :XPTR
    PowerClearRequest PROTO :HANDLE, :XWORD
    PowerCreateRequest PROTO :XPTR
    PowerSetRequest PROTO :HANDLE, :XWORD
    QueryIdleProcessorCycleTimeEx PROTO :XWORD, :XPTR, :XPTR
    QueryThreadProfiling PROTO :HANDLE, :XPTR
    QueryThreadpoolStackInformation PROTO :XPTR, :XPTR
    QueryUnbiasedInterruptTime PROTO :XPTR
    RaiseFailFastException PROTO :XPTR, :XPTR, :XWORD
    ReadThreadProfilingData PROTO :HANDLE, :XWORD, :XPTR
    RegCloseKey PROTO :HKEY
    RegCreateKeyExA PROTO :HKEY, :LPCTSTR, :XWORD, :LPTSTR, :XWORD, :XWORD, :XPTR, :XPTR, :LPDWORD
    RegCreateKeyExW PROTO :HKEY, :LPCWSTR, :XWORD, :LPTSTR, :XWORD, :XWORD, :XPTR, :XPTR, :LPDWORD
    RegDeleteKeyExA PROTO :HKEY, :LPCTSTR, :XWORD, :XWORD
    RegDeleteKeyExW PROTO :HKEY, :LPCWSTR, :XWORD, :XWORD
    RegDeleteTreeA PROTO :HKEY, :LPCTSTR
    RegDeleteTreeW PROTO :HKEY, :LPCWSTR
    RegDeleteValueA PROTO :HKEY, :LPCTSTR
    RegDeleteValueW PROTO :HKEY, :LPCWSTR
    RegDisablePredefinedCacheEx PROTO
    RegEnumKeyExA PROTO :HKEY, :XWORD, :LPTSTR, :LPDWORD, :LPDWORD, :LPTSTR, :LPDWORD, :XPTR
    RegEnumKeyExW PROTO :HKEY, :XWORD, :LPWSTR, :LPDWORD, :LPDWORD, :LPWSTR, :LPDWORD, :XPTR
    RegEnumValueA PROTO :HKEY, :XWORD, :LPTSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPBYTE, :LPDWORD
    RegEnumValueW PROTO :HKEY, :XWORD, :LPWSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPWORD, :LPDWORD
    RegFlushKey PROTO :HKEY
    RegGetKeySecurity PROTO :HKEY, :XWORD, :XPTR, :LPDWORD
    RegGetValueA PROTO :HKEY, :LPCTSTR, :LPCTSTR, :XWORD, :LPDWORD, :PVOID, :LPDWORD
    RegGetValueW PROTO :HKEY, :LPCWSTR, :LPCWSTR, :XWORD, :LPDWORD, :PVOID, :LPDWORD
    RegLoadKeyA PROTO :HKEY, :LPCTSTR, :LPCTSTR
    RegLoadKeyW PROTO :HKEY, :LPCWSTR, :LPCWSTR
    RegLoadMUIStringA PROTO :HKEY, :LPCTSTR, :LPTSTR, :XWORD, :LPDWORD, :XWORD, :LPCTSTR
    RegLoadMUIStringW PROTO :HKEY, :LPCWSTR, :LPWSTR, :XWORD, :LPDWORD, :XWORD, :LPCWSTR
    RegNotifyChangeKeyValue PROTO :HKEY, :XWORD, :XWORD, :HANDLE, :XWORD
    RegOpenCurrentUser PROTO :XWORD, :XPTR
    RegOpenKeyExA PROTO :HKEY, :LPCTSTR, :XWORD, :XWORD, :XPTR
    RegOpenKeyExW PROTO :HKEY, :LPCWSTR, :XWORD, :XWORD, :XPTR
    RegOpenUserClassesRoot PROTO :HANDLE, :XWORD, :XWORD, :XPTR
    RegQueryInfoKeyA PROTO :HKEY, :LPTSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :XPTR
    RegQueryInfoKeyW PROTO :HKEY, :LPWSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :XPTR
    RegQueryValueExA PROTO :HKEY, :LPCTSTR, :LPDWORD, :LPDWORD, :LPBYTE, :LPDWORD
    RegQueryValueExW PROTO :HKEY, :LPCWSTR, :LPDWORD, :LPDWORD, :LPWORD, :LPDWORD
    RegRestoreKeyA PROTO :HKEY, :LPCTSTR, :XWORD
    RegRestoreKeyW PROTO :HKEY, :LPCWSTR, :XWORD
    RegSaveKeyExA PROTO :HKEY, :LPCTSTR, :XPTR, :XWORD
    RegSaveKeyExW PROTO :HKEY, :LPCWSTR, :XPTR, :XWORD
    RegSetKeySecurity PROTO :HKEY, :XWORD, :XPTR
    RegSetValueExA PROTO :HKEY, :LPCTSTR, :XWORD, :XWORD, :XPTR, :XWORD
    RegSetValueExW PROTO :HKEY, :LPCWSTR, :XWORD, :XWORD, :XPTR, :XWORD
    RegUnLoadKeyA PROTO :HKEY, :LPCTSTR
    RegUnLoadKeyW PROTO :HKEY, :LPCWSTR
    ResolveLocaleName PROTO :LPCWSTR, :LPWSTR, :XWORD
    RtlCompareMemory PROTO :XPTR, :XPTR, :SIZE_T
    RtlCopyMemory PROTO :XPTR, :XPTR, :SIZE_T
    SetProcessPreferredUILanguages PROTO :XWORD, :XPTR, :PULONG
    IF (NTDDI_VERSION LT NTDDI_WIN8)
        SetProcessUserModeExceptionPolicy PROTO :XWORD
    ENDIF
    SetSearchPathMode PROTO :XWORD
    SetStdHandleEx PROTO :XWORD, :HANDLE, :HANDLE
    SetThreadErrorMode PROTO :XWORD, :LPDWORD
    SetThreadGroupAffinity PROTO :HANDLE, :XPTR, :XPTR
    SetThreadIdealProcessorEx PROTO :HANDLE, :XPTR, :XPTR
    SetThreadpoolStackInformation PROTO :XPTR, :XPTR
    SetThreadToken PROTO :XPTR, :HANDLE
    SystemTimeToTzSpecificLocalTimeEx PROTO :XPTR, :XPTR, :XPTR
    TryAcquireSRWLockExclusive PROTO :XPTR
    TryAcquireSRWLockShared PROTO :XPTR
    TzSpecificLocalTimeToSystemTimeEx PROTO :XPTR, :XPTR, :XPTR
    WerRegisterRuntimeExceptionModule PROTO :XPTR,  :PVOID
    WerUnregisterRuntimeExceptionModule PROTO :XPTR,  :PVOID
    Wow64GetThreadSelectorEntry PROTO :HANDLE, :XWORD, :XPTR
    CopyMemory EQU <RtlCopyMemory>
    IFDEF APP_WIN64
        CreateUmsCompletionList PROTO :XPTR
        CreateUmsThreadContext PROTO :XPTR
        DeleteUmsCompletionList PROTO :XPTR
        DeleteUmsThreadContext PROTO :XPTR
        DequeueUmsCompletionListItems PROTO :XPTR, :XWORD, :XPTR
        EnterUmsSchedulingMode PROTO :XPTR
        ExecuteUmsThread PROTO :XPTR
        GetCurrentUmsThread PROTO
        GetNextUmsListItem PROTO :XPTR
        GetUmsCompletionListEvent PROTO :XPTR, :XPTR
        GetUmsSystemThreadInformation PROTO :HANDLE, :XPTR
        QueryUmsThreadInformation PROTO :XPTR, :XWORD, :PVOID, :XWORD, :PULONG
        SetUmsThreadInformation PROTO :XPTR, :XWORD, :PVOID, :XWORD
        UmsThreadYield PROTO :PVOID
    ENDIF

    IFDEF APP_UNICODE
        K32EnumPageFiles EQU <K32EnumPageFilesW>
        K32GetDeviceDriverBaseName EQU <K32GetDeviceDriverBaseNameW>
        K32GetDeviceDriverFileName EQU <K32GetDeviceDriverFileNameW>
        K32GetMappedFileName EQU <K32GetMappedFileNameW>
        K32GetModuleBaseName EQU <K32GetModuleBaseNameW>
        K32GetModuleFileNameEx EQU <K32GetModuleFileNameExW>
        K32GetProcessImageFileName EQU <K32GetProcessImageFileNameW>
        RegCreateKeyEx EQU <RegCreateKeyExW>
        RegDeleteKeyEx EQU <RegDeleteKeyExW>
        RegDeleteTree EQU <RegDeleteTreeW>
        RegDeleteValue EQU <RegDeleteValueW>
        RegEnumKeyEx EQU <RegEnumKeyExW>
        RegEnumValue EQU <RegEnumValueW>
        RegGetValue EQU <RegGetValueW>
        RegLoadKey EQU <RegLoadKeyW>
        RegLoadMUIString EQU <RegLoadMUIStringW>
        RegOpenKeyEx EQU <RegOpenKeyExW>
        RegQueryInfoKey EQU <RegQueryInfoKeyW>
        RegQueryValueEx EQU <RegQueryValueExW>
        RegRestoreKey EQU <RegRestoreKeyW>
        RegSaveKeyEx EQU <RegSaveKeyExW>
        RegSetValueEx EQU <RegSetValueExW>
        RegUnLoadKey EQU <RegUnLoadKeyW>
    ELSE
        K32EnumPageFiles EQU <K32EnumPageFilesA>
        K32GetDeviceDriverBaseName EQU <K32GetDeviceDriverBaseNameA>
        K32GetDeviceDriverFileName EQU <K32GetDeviceDriverFileNameA>
        K32GetMappedFileName EQU <K32GetMappedFileNameA>
        K32GetModuleBaseName EQU <K32GetModuleBaseNameA>
        K32GetModuleFileNameEx EQU <K32GetModuleFileNameExA>
        K32GetProcessImageFileName EQU <K32GetProcessImageFileNameA>
        RegCreateKeyEx EQU <RegCreateKeyExA>
        RegDeleteKeyEx EQU <RegDeleteKeyExA>
        RegDeleteTree EQU <RegDeleteTreeA>
        RegDeleteValue EQU <RegDeleteValueA>
        RegEnumKeyEx EQU <RegEnumKeyExA>
        RegEnumValue EQU <RegEnumValueA>
        RegGetValue EQU <RegGetValueA>
        RegLoadKey EQU <RegLoadKeyA>
        RegLoadMUIString EQU <RegLoadMUIStringA>
        RegOpenKeyEx EQU <RegOpenKeyExA>
        RegQueryInfoKey EQU <RegQueryInfoKeyA>
        RegQueryValueEx EQU <RegQueryValueExA>
        RegRestoreKey EQU <RegRestoreKeyA>
        RegSaveKeyEx EQU <RegSaveKeyExA>
        RegSetValueEx EQU <RegSetValueExA>
        RegUnLoadKey EQU <RegUnLoadKeyA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN7SP1)
    CopyContext PROTO :XPTR, :XWORD, :XPTR
    GetEnabledXStateFeatures PROTO
    GetXStateFeaturesMask PROTO :XPTR, :XPTR
    InitializeContext PROTO :PVOID, :XWORD, :XPTR, :XPTR
    LocateXStateFeature PROTO :XPTR, :XWORD, :XPTR
    SetXStateFeaturesMask PROTO :XPTR, :XWORD
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN8)
    IF (NTDDI_VERSION EQ NTDDI_WIN8)
        AcquireStateLock PROTO :XPTR
    ENDIF
    AddResourceAttributeAce PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR
    AddScopedPolicyIDAce PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XPTR
    IF (NTDDI_VERSION EQ NTDDI_WIN81)
        CalloutOnFiberStack PROTO :PVOID, :XPTR, :PVOID
        CopyExtendedContext PROTO :XPTR, :XWORD, :XPTR
    ENDIF
    CeipIsOptedIn PROTO
    CheckTokenCapability PROTO :HANDLE, :XPTR, :XPTR
    CheckTokenMembershipEx PROTO :HANDLE, :XPTR, :XWORD, :XPTR
    ClosePackageInfo PROTO :XPTR
    CopyFile2 PROTO :XPTR, :XPTR, :XPTR
    CreateFile2 PROTO :LPCWSTR, :XWORD, :XWORD, :XWORD, :XPTR
    CreateFileMappingFromApp PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :XPTR
    GetAppContainerNamedObjectPath PROTO :HANDLE, :XPTR, :XWORD, :LPWSTR, :XPTR
    GetApplicationUserModelId PROTO :HANDLE, :XPTR, :XPTR
    GetCachedSigningLevel PROTO :HANDLE, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    GetCurrentApplicationUserModelId PROTO :XWORD, :XPTR
    GetCurrentPackageFamilyName PROTO :XPTR, :XPTR
    GetCurrentPackageFullName PROTO :XPTR, :XPTR
    GetCurrentPackageId PROTO :XPTR, :XPTR
    GetCurrentPackageInfo PROTO :XWORD, :XPTR, :XPTR, :XPTR
    GetCurrentPackagePath PROTO :XPTR, :XPTR
    GetCurrentThreadStackLimits PROTO :PULONG, :PULONG
    GetFirmwareEnvironmentVariableExA PROTO :LPCSTR, :LPCSTR, :PVOID, :XWORD, :XPTR
    GetFirmwareEnvironmentVariableExW PROTO :LPWSTR, :LPWSTR, :PVOID, :XWORD, :XPTR
    GetFirmwareType PROTO :XPTR
    GetMemoryErrorHandlingCapabilities PROTO :PULONG
    GetOverlappedResultEx PROTO :HANDLE, :XPTR, :LPDWORD, :XWORD, :XWORD
    GetPackageFamilyName PROTO :HANDLE, :XPTR, :XPTR
    GetPackageFullName PROTO :HANDLE, :XPTR, :XPTR
    GetPackageId PROTO :HANDLE, :XPTR, :XPTR
    GetPackageInfo PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XPTR
    GetPackagePath PROTO :XPTR, :XWORD, :XPTR, :XPTR
    GetPackagesByPackageFamily PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    GetProcessInformation PROTO :HANDLE, :XWORD, :XPTR, :XWORD
    GetProcessMitigationPolicy PROTO :HANDLE, :XPTR, :PVOID, :SIZE_T
    GetSystemTimePreciseAsFileTime PROTO :XPTR
    GetThreadInformation PROTO :HANDLE, :XWORD, :XPTR, :XWORD
    GlobalAddAtomExA PROTO :LPCSTR, :XWORD
    GlobalAddAtomExW PROTO :LPCWSTR, :XWORD
    InterlockedPushListSListEx PROTO :XPTR, :XPTR, :XPTR, :XWORD
    IsNativeVhdBoot PROTO :XPTR
    IsValidNLSVersion PROTO :XWORD, :LPCWSTR, :XPTR
    LoadPackagedLibrary PROTO :LPCWSTR, :XWORD
    MapViewOfFileFromApp PROTO :HANDLE, :XWORD, :XWORD, :SIZE_T
    OpenPackageInfoByFullName PROTO :XPTR, :XWORD, :XPTR
    PackageFamilyNameFromFullName PROTO :XPTR, :XPTR, :XPTR
    PackageFamilyNameFromId PROTO :XPTR, :XPTR, :XPTR
    PackageFullNameFromId PROTO :XPTR, :XPTR, :XPTR
    PackageIdFromFullName PROTO :XPTR, :XWORD, :XPTR, :XPTR
    PackageNameAndPublisherIdFromFamilyName PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    PrefetchVirtualMemory PROTO :HANDLE, :ULONG_PTR, :XPTR, :XWORD
    RegCopyTreeW PROTO :HKEY, :LPCWSTR, :HKEY
    RegisterBadMemoryNotification PROTO :XPTR
    RestoreLastError PROTO :XWORD
    SetCachedSigningLevel PROTO :XPTR, :XWORD, :XWORD, :HANDLE
    SetFirmwareEnvironmentVariableExA PROTO :LPCTSTR, :LPCTSTR, :PVOID, :XWORD, :XWORD
    SetFirmwareEnvironmentVariableExW PROTO :LPCWSTR, :LPCWSTR, :PVOID, :XWORD, :XWORD
    SetProcessInformation PROTO :HANDLE, :XWORD, :XPTR, :XWORD
    SetProcessMitigationPolicy PROTO :XWORD, :PVOID, :SIZE_T
    SetThreadInformation PROTO :HANDLE, :XWORD, :XPTR, :XWORD
    UnregisterBadMemoryNotification PROTO :PVOID
    IFDEF APP_UNICODE
        GetFirmwareEnvironmentVariableEx EQU <GetFirmwareEnvironmentVariableExW>
        GlobalAddAtomEx EQU <GlobalAddAtomExW>
        SetFirmwareEnvironmentVariableEx EQU <SetFirmwareEnvironmentVariableExW>
    ELSE
        GetFirmwareEnvironmentVariableEx EQU <GetFirmwareEnvironmentVariableExA>
        GlobalAddAtomEx EQU <GlobalAddAtomExA>
        SetFirmwareEnvironmentVariableEx EQU <SetFirmwareEnvironmentVariableExA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN81)
    DeleteSynchronizationBarrier PROTO :XPTR
    EnterSynchronizationBarrier PROTO :XPTR, :XWORD
    FindPackagesByPackageFamily PROTO :XPTR, :XWORD, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD
    FormatApplicationUserModelId PROTO :XPTR, :XPTR, :XPTR, :XPTR
    GetPackageApplicationIds PROTO :XPTR, :XPTR, :XPTR, :XPTR
    GetPackagePathByFullName PROTO :XPTR, :XPTR, :XPTR
    GetStagedPackagePathByFullName PROTO :XPTR, :XPTR, :XPTR
    InitializeSynchronizationBarrier PROTO :XPTR, :XWORD, :XWORD
    InstallELAMCertificateInfo PROTO :HANDLE
    IsProcessCritical PROTO :HANDLE, :XPTR
    OOBEComplete PROTO :XPTR
    ParseApplicationUserModelId PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    PssCaptureSnapshot PROTO :HANDLE, :XWORD, :XWORD, :XPTR
    PssDuplicateSnapshot PROTO :HANDLE, :HANDLE, :HANDLE, :HANDLE, :XWORD
    PssFreeSnapshot PROTO :HANDLE, :HANDLE
    PssQuerySnapshot PROTO :HANDLE, :XWORD, :XPTR, :XWORD
    PssWalkMarkerCreate PROTO :XPTR, :HANDLE
    PssWalkMarkerFree PROTO :HANDLE
    PssWalkMarkerGetPosition PROTO :HANDLE, :XPTR
    PssWalkMarkerSeekToBeginning PROTO :HANDLE
    PssWalkMarkerSetPosition PROTO :HANDLE, :XPTR
    PssWalkSnapshot PROTO :HANDLE, :XWORD, :HANDLE, :XPTR, :XWORD
    RegisterWaitUntilOOBECompleted PROTO :XPTR, :XPTR, :XPTR
    UnregisterWaitUntilOOBECompleted PROTO :PVOID
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN10)
    CreateEnclave PROTO :HANDLE, :XPTR, :SIZE_T, :SIZE_T, :XWORD, :XPTR, :XWORD, :XPTR
    DiscardVirtualMemory PROTO :PVOID, :SIZE_T
    FreeMemoryJobObject PROTO :XPTR
    GetProcessDefaultCpuSets PROTO :HANDLE, :XPTR, :XWORD, :XPTR
    GetSystemCpuSetInformation PROTO :XPTR, :XWORD, :XPTR, :HANDLE, :XPTR
    GetThreadSelectedCpuSets PROTO :HANDLE, :XPTR, :XWORD, :XPTR
    InitializeEnclave PROTO :HANDLE, :LPVOID, :LPVOID, :XWORD, :LPDWORD
    IsEnclaveTypeSupported PROTO :XWORD
    LoadEnclaveData PROTO :HANDLE, :LPVOID, :LPCVOID, :SIZE_T, :XWORD, :LPCVOID, :XWORD, :XPTR, :LPDWORD
    OfferVirtualMemory PROTO :XPTR, :SIZE_T, :XWORD
    QueryIoRateControlInformationJobObject PROTO :HANDLE, :XPTR, :XPTR, :XPTR
    QueryProtectedPolicy PROTO :XPTR, :XPTR
    ReclaimVirtualMemory PROTO :XPTR, :SIZE_T
    SetIoRateControlInformationJobObject PROTO :HANDLE, :XPTR
    SetProcessDefaultCpuSets PROTO :HANDLE, :XWORD, :XWORD
    SetProtectedPolicy PROTO :XPTR, :XPTR, :XPTR
    SetThreadSelectedCpuSets PROTO :HANDLE, :XWORD, :XWORD
    WaitForDebugEventEx PROTO :XPTR, :XWORD
ENDIF

IFDEF APP_UNICODE
    AddAtom EQU <AddAtomW>
    BeginUpdateResource EQU <BeginUpdateResourceW>
    BuildCommDCB EQU <BuildCommDCBW>
    BuildCommDCBAndTimeouts EQU <BuildCommDCBAndTimeoutsW>
    CallNamedPipe EQU <CallNamedPipeW>
    CommConfigDialog EQU <CommConfigDialogW>
    CompareString EQU <CompareStringW>
    CopyFile EQU <CopyFileW>
    CreateDirectory EQU <CreateDirectoryW>
    CreateDirectoryEx EQU <CreateDirectoryExW>
    CreateEvent EQU <CreateEventW>
    CreateFile EQU <CreateFileW>
    CreateFileMapping EQU <CreateFileMappingW>
    CreateMailslot EQU <CreateMailslotW>
    CreateMutex EQU <CreateMutexW>
    CreateNamedPipe EQU <CreateNamedPipeW>
    CreateProcess EQU <CreateProcessW>
    CreateSemaphore EQU <CreateSemaphoreW>
    DefineDosDevice EQU <DefineDosDeviceW>
    DeleteFile EQU <DeleteFileW>
    EndUpdateResource EQU <EndUpdateResourceW>
    EnumCalendarInfo EQU <EnumCalendarInfoW>
    EnumDateFormats EQU <EnumDateFormatsW>
    EnumResourceLanguages EQU <EnumResourceLanguagesW>
    EnumResourceNames EQU <EnumResourceNamesW>
    EnumResourceTypes EQU <EnumResourceTypesW>
    EnumSystemCodePages EQU <EnumSystemCodePagesW>
    EnumSystemLocales EQU <EnumSystemLocalesW>
    EnumTimeFormats EQU <EnumTimeFormatsW>
    ExpandEnvironmentStrings EQU <ExpandEnvironmentStringsW>
    FatalAppExit EQU <FatalAppExitW>
    FillConsoleOutputCharacter EQU <FillConsoleOutputCharacterW>
    FindAtom EQU <FindAtomW>
    FindFirstChangeNotification EQU <FindFirstChangeNotificationW>
    FindFirstFile EQU <FindFirstFileW>
    FindNextFile EQU <FindNextFileW>
    FindResource EQU <FindResourceW>
    FindResourceEx EQU <FindResourceExW>
    FoldString EQU <FoldStringW>
    FormatMessage EQU <FormatMessageW>
    FreeEnvironmentStrings EQU <FreeEnvironmentStringsW>
    GetAtomName EQU <GetAtomNameW>
    GetBinaryType EQU <GetBinaryTypeW>
    GetCommandLine EQU <GetCommandLineW>
    GetCompressedFileSize EQU <GetCompressedFileSizeW>
    GetComputerName EQU <GetComputerNameW>
    GetConsoleTitle EQU <GetConsoleTitleW>
    GetCurrencyFormat EQU <GetCurrencyFormatW>
    GetCurrentDirectory EQU <GetCurrentDirectoryW>
    GetDateFormat EQU <GetDateFormatW>
    GetDefaultCommConfig EQU <GetDefaultCommConfigW>
    GetDiskFreeSpace EQU <GetDiskFreeSpaceW>
    GetDiskFreeSpaceEx EQU <GetDiskFreeSpaceExW>
    GetDriveType EQU <GetDriveTypeW>
    GetEnvironmentStrings EQU <GetEnvironmentStringsW>
    GetEnvironmentVariable EQU <GetEnvironmentVariableW>
    GetFileAttributes EQU <GetFileAttributesW>
    GetFullPathName EQU <GetFullPathNameW>
    GetLocaleInfo EQU <GetLocaleInfoW>
    GetLogicalDriveStrings EQU <GetLogicalDriveStringsW>
    GetModuleFileName EQU <GetModuleFileNameW>
    GetModuleHandle EQU <GetModuleHandleW>
    GetNamedPipeHandleState EQU <GetNamedPipeHandleStateW>
    GetNumberFormat EQU <GetNumberFormatW>
    GetPrivateProfileInt EQU <GetPrivateProfileIntW>
    GetPrivateProfileSection EQU <GetPrivateProfileSectionW>
    GetPrivateProfileSectionNames EQU <GetPrivateProfileSectionNamesW>
    GetPrivateProfileString EQU <GetPrivateProfileStringW>
    GetPrivateProfileStruct EQU <GetPrivateProfileStructW>
    GetProfileInt EQU <GetProfileIntW>
    GetProfileSection EQU <GetProfileSectionW>
    GetProfileString EQU <GetProfileStringW>
    GetShortPathName EQU <GetShortPathNameW>
    GetStartupInfo EQU <GetStartupInfoW>
    GetStringType EQU <GetStringTypeW>
    GetStringTypeEx EQU <GetStringTypeExW>
    GetSystemDirectory EQU <GetSystemDirectoryW>
    GetTempFileName EQU <GetTempFileNameW>
    GetTempPath EQU <GetTempPathW>
    GetTimeFormat EQU <GetTimeFormatW>
    GetUserName EQU <GetUserNameW>
    GetVersionEx EQU <GetVersionExW>
    GetVolumeInformation EQU <GetVolumeInformationW>
    GetWindowsDirectory EQU <GetWindowsDirectoryW>
    GlobalAddAtom EQU <GlobalAddAtomW>
    GlobalFindAtom EQU <GlobalFindAtomW>
    GlobalGetAtomName EQU <GlobalGetAtomNameW>
    IsBadStringPtr EQU <IsBadStringPtrW>
    LCMapString EQU <LCMapStringW>
    LoadLibrary EQU <LoadLibraryW>
    LoadLibraryEx EQU <LoadLibraryExW>
    lstrcat EQU <lstrcatW>
    lstrcmp EQU <lstrcmpW>
    lstrcmpi EQU <lstrcmpiW>
    lstrcpy EQU <lstrcpyW>
    lstrcpyn EQU <lstrcpynW>
    lstrlen EQU <lstrlenW>
    MoveFile EQU <MoveFileW>
    MoveFileEx EQU <MoveFileExW>
    OpenEvent EQU <OpenEventW>
    OpenFileMapping EQU <OpenFileMappingW>
    OpenMutex EQU <OpenMutexW>
    OpenSemaphore EQU <OpenSemaphoreW>
    OutputDebugString EQU <OutputDebugStringW>
    PeekConsoleInput EQU <PeekConsoleInputW>
    QueryDosDevice EQU <QueryDosDeviceW>
    ReadConsole EQU <ReadConsoleW>
    ReadConsoleInput EQU <ReadConsoleInputW>
    ReadConsoleOutput EQU <ReadConsoleOutputW>
    ReadConsoleOutputCharacter EQU <ReadConsoleOutputCharacterW>
    RemoveDirectory EQU <RemoveDirectoryW>
    ScrollConsoleScreenBuffer EQU <ScrollConsoleScreenBufferW>
    SearchPath EQU <SearchPathW>
    SetComputerName EQU <SetComputerNameW>
    SetConsoleTitle EQU <SetConsoleTitleW>
    SetCurrentDirectory EQU <SetCurrentDirectoryW>
    SetDefaultCommConfig EQU <SetDefaultCommConfigW>
    SetEnvironmentVariable EQU <SetEnvironmentVariableW>
    SetFileAttributes EQU <SetFileAttributesW>
    SetLocaleInfo EQU <SetLocaleInfoW>
    SetVolumeLabel EQU <SetVolumeLabelW>
    UpdateResource EQU <UpdateResourceW>
    VerLanguageName EQU <VerLanguageNameW>
    WaitNamedPipe EQU <WaitNamedPipeW>
    WriteConsole EQU <WriteConsoleW>
    WriteConsoleInput EQU <WriteConsoleInputW>
    WriteConsoleOutput EQU <WriteConsoleOutputW>
    WriteConsoleOutputCharacter EQU <WriteConsoleOutputCharacterW>
    WritePrivateProfileSection EQU <WritePrivateProfileSectionW>
    WritePrivateProfileString EQU <WritePrivateProfileStringW>
    WritePrivateProfileStruct EQU <WritePrivateProfileStructW>
    WriteProfileSection EQU <WriteProfileSectionW>
    WriteProfileString EQU <WriteProfileStringW>
ELSE
    AddAtom EQU <AddAtomA>
    BeginUpdateResource EQU <BeginUpdateResourceA>
    BuildCommDCB EQU <BuildCommDCBA>
    BuildCommDCBAndTimeouts EQU <BuildCommDCBAndTimeoutsA>
    CallNamedPipe EQU <CallNamedPipeA>
    CommConfigDialog EQU <CommConfigDialogA>
    CompareString EQU <CompareStringA>
    CopyFile EQU <CopyFileA>
    CreateDirectory EQU <CreateDirectoryA>
    CreateDirectoryEx EQU <CreateDirectoryExA>
    CreateEvent EQU <CreateEventA>
    CreateFile EQU <CreateFileA>
    CreateFileMapping EQU <CreateFileMappingA>
    CreateMailslot EQU <CreateMailslotA>
    CreateMutex EQU <CreateMutexA>
    CreateNamedPipe EQU <CreateNamedPipeA>
    CreateProcess EQU <CreateProcessA>
    CreateSemaphore EQU <CreateSemaphoreA>
    DefineDosDevice EQU <DefineDosDeviceA>
    DeleteFile EQU <DeleteFileA>
    EndUpdateResource EQU <EndUpdateResourceA>
    EnumCalendarInfo EQU <EnumCalendarInfoA>
    EnumDateFormats EQU <EnumDateFormatsA>
    EnumResourceLanguages EQU <EnumResourceLanguagesA>
    EnumResourceNames EQU <EnumResourceNamesA>
    EnumResourceTypes EQU <EnumResourceTypesA>
    EnumSystemCodePages EQU <EnumSystemCodePagesA>
    EnumSystemLocales EQU <EnumSystemLocalesA>
    EnumTimeFormats EQU <EnumTimeFormatsA>
    ExpandEnvironmentStrings EQU <ExpandEnvironmentStringsA>
    FatalAppExit EQU <FatalAppExitA>
    FillConsoleOutputCharacter EQU <FillConsoleOutputCharacterA>
    FindAtom EQU <FindAtomA>
    FindFirstChangeNotification EQU <FindFirstChangeNotificationA>
    FindFirstFile EQU <FindFirstFileA>
    FindNextFile EQU <FindNextFileA>
    FindResource EQU <FindResourceA>
    FindResourceEx EQU <FindResourceExA>
    FoldString EQU <FoldStringA>
    FormatMessage EQU <FormatMessageA>
    FreeEnvironmentStrings EQU <FreeEnvironmentStringsA>
    GetAtomName EQU <GetAtomNameA>
    GetBinaryType EQU <GetBinaryTypeA>
    GetCommandLine EQU <GetCommandLineA>
    GetCompressedFileSize EQU <GetCompressedFileSizeA>
    GetComputerName EQU <GetComputerNameA>
    GetConsoleTitle EQU <GetConsoleTitleA>
    GetCurrencyFormat EQU <GetCurrencyFormatA>
    GetCurrentDirectory EQU <GetCurrentDirectoryA>
    GetDateFormat EQU <GetDateFormatA>
    GetDefaultCommConfig EQU <GetDefaultCommConfigA>
    GetDiskFreeSpace EQU <GetDiskFreeSpaceA>
    GetDiskFreeSpaceEx EQU <GetDiskFreeSpaceExA>
    GetDriveType EQU <GetDriveTypeA>
    GetEnvironmentStrings EQU <GetEnvironmentStringsA>
    GetEnvironmentVariable EQU <GetEnvironmentVariableA>
    GetFileAttributes EQU <GetFileAttributesA>
    GetFullPathName EQU <GetFullPathNameA>
    GetLocaleInfo EQU <GetLocaleInfoA>
    GetLogicalDriveStrings EQU <GetLogicalDriveStringsA>
    GetModuleFileName EQU <GetModuleFileNameA>
    GetModuleHandle EQU <GetModuleHandleA>
    GetNamedPipeHandleState EQU <GetNamedPipeHandleStateA>
    GetNumberFormat EQU <GetNumberFormatA>
    GetPrivateProfileInt EQU <GetPrivateProfileIntA>
    GetPrivateProfileSection EQU <GetPrivateProfileSectionA>
    GetPrivateProfileSectionNames EQU <GetPrivateProfileSectionNamesA>
    GetPrivateProfileString EQU <GetPrivateProfileStringA>
    GetPrivateProfileStruct EQU <GetPrivateProfileStructA>
    GetProfileInt EQU <GetProfileIntA>
    GetProfileSection EQU <GetProfileSectionA>
    GetProfileString EQU <GetProfileStringA>
    GetShortPathName EQU <GetShortPathNameA>
    GetStartupInfo EQU <GetStartupInfoA>
    GetStringType EQU <GetStringTypeA>
    GetStringTypeEx EQU <GetStringTypeExA>
    GetSystemDirectory EQU <GetSystemDirectoryA>
    GetTempFileName EQU <GetTempFileNameA>
    GetTempPath EQU <GetTempPathA>
    GetTimeFormat EQU <GetTimeFormatA>
    GetUserName EQU <GetUserNameA>
    GetVersionEx EQU <GetVersionExA>
    GetVolumeInformation EQU <GetVolumeInformationA>
    GetWindowsDirectory EQU <GetWindowsDirectoryA>
    GlobalAddAtom EQU <GlobalAddAtomA>
    GlobalFindAtom EQU <GlobalFindAtomA>
    GlobalGetAtomName EQU <GlobalGetAtomNameA>
    IsBadStringPtr EQU <IsBadStringPtrA>
    LCMapString EQU <LCMapStringA>
    LoadLibrary EQU <LoadLibraryA>
    LoadLibraryEx EQU <LoadLibraryExA>
    lstrcat EQU <lstrcatA>
    lstrcmp EQU <lstrcmpA>
    lstrcmpi EQU <lstrcmpiA>
    lstrcpy EQU <lstrcpyA>
    lstrcpyn EQU <lstrcpynA>
    lstrlen EQU <lstrlenA>
    MoveFile EQU <MoveFileA>
    MoveFileEx EQU <MoveFileExA>
    OpenEvent EQU <OpenEventA>
    OpenFileMapping EQU <OpenFileMappingA>
    OpenMutex EQU <OpenMutexA>
    OpenSemaphore EQU <OpenSemaphoreA>
    OutputDebugString EQU <OutputDebugStringA>
    PeekConsoleInput EQU <PeekConsoleInputA>
    QueryDosDevice EQU <QueryDosDeviceA>
    ReadConsole EQU <ReadConsoleA>
    ReadConsoleInput EQU <ReadConsoleInputA>
    ReadConsoleOutput EQU <ReadConsoleOutputA>
    ReadConsoleOutputCharacter EQU <ReadConsoleOutputCharacterA>
    RemoveDirectory EQU <RemoveDirectoryA>
    ScrollConsoleScreenBuffer EQU <ScrollConsoleScreenBufferA>
    SearchPath EQU <SearchPathA>
    SetComputerName EQU <SetComputerNameA>
    SetConsoleTitle EQU <SetConsoleTitleA>
    SetCurrentDirectory EQU <SetCurrentDirectoryA>
    SetDefaultCommConfig EQU <SetDefaultCommConfigA>
    SetEnvironmentVariable EQU <SetEnvironmentVariableA>
    SetFileAttributes EQU <SetFileAttributesA>
    SetLocaleInfo EQU <SetLocaleInfoA>
    SetVolumeLabel EQU <SetVolumeLabelA>
    UpdateResource EQU <UpdateResourceA>
    VerLanguageName EQU <VerLanguageNameA>
    WaitNamedPipe EQU <WaitNamedPipeA>
    WriteConsole EQU <WriteConsoleA>
    WriteConsoleInput EQU <WriteConsoleInputA>
    WriteConsoleOutput EQU <WriteConsoleOutputA>
    WriteConsoleOutputCharacter EQU <WriteConsoleOutputCharacterA>
    WritePrivateProfileSection EQU <WritePrivateProfileSectionA>
    WritePrivateProfileString EQU <WritePrivateProfileStringA>
    WritePrivateProfileStruct EQU <WritePrivateProfileStructA>
    WriteProfileSection EQU <WriteProfileSectionA>
    WriteProfileString EQU <WriteProfileStringA>
ENDIF

;======================= Undocumented functions (unknown arguments) =======================;
;IFNDEF __misaligned_access
;    __misaligned_access PROTO
;ENDIF
;ActivateActCtxWorker PROTO
;AddRefActCtxWorker PROTO
;AppContainerDeriveSidFromMoniker PROTO
;AppContainerFreeMemory PROTO
;AppContainerLookupDisplayNameMrtReference PROTO
;AppContainerLookupMoniker PROTO
;AppContainerRegisterSid PROTO
;AppContainerUnregisterSid PROTO
;AppXFreeMemory PROTO
;AppXGetApplicationData PROTO
;AppXGetDevelopmentMode PROTO
;AppXGetOSMaxVersionTested PROTO
;AppXGetOSMinVersion PROTO
;AppXGetPackageCapabilities PROTO
;AppXGetPackageSid PROTO
;AppXGetPackageState PROTO
;AppXLookupDisplayName PROTO
;AppXLookupMoniker PROTO
;AppXSetPackageState PROTO
;BaseCheckAppcompatCache PROTO
;BaseCheckAppcompatCacheEx PROTO
;BaseCheckAppcompatCacheExWorker PROTO
;BaseCheckAppcompatCacheWorker PROTO
;BaseCheckElevation PROTO
;BaseCheckRunApp PROTO
;BaseCleanupAppcompatCacheSupport PROTO
;BaseCleanupAppcompatCacheSupportWorker PROTO
;BaseDestroyVDMEnvironment PROTO
;BaseDllReadWriteIniFile PROTO
;BaseDumpAppcompatCache PROTO
;BaseDumpAppcompatCacheWorker PROTO
;BaseElevationPostProcessing PROTO
;BaseFlushAppcompatCache PROTO
;BaseFlushAppcompatCacheWorker PROTO
;BaseFreeAppCompatDataForProcessWorker PROTO
;BaseFormatObjectAttributes PROTO
;BaseGenerateAppCompatData PROTO
;BaseInitAppcompatCacheSupport PROTO
;BaseInitAppcompatCacheSupportWorker PROTO
;BaseIsAppcompatInfrastructureDisabled PROTO
;BaseIsAppcompatInfrastructureDisabledWorker PROTO
;BaseIsDosApplication PROTO
;BaseProcessInitPostImport PROTO
;BaseProcessStart PROTO
;BaseQueryModuleData PROTO
;BaseReadAppCompatDataForProcessWorker PROTO
;BaseSetLastNTError PROTO
;BaseThreadInitThunk PROTO
;BaseUpdateAppcompatCache PROTO
;BaseUpdateAppcompatCacheWorker PROTO
;BaseUpdateVDMEntry PROTO
;BaseVerifyUnicodeString PROTO
;BaseWriteErrorElevationRequiredEvent PROTO
;BasepAllocateActivationContextActivationBlock PROTO
;BasepAnsiStringToDynamicUnicodeString PROTO
;BasepAppCompatHookDLL PROTO
;BasepAppContainerEnvironmentExtension PROTO
;BasepAppXExtension PROTO
;BasepCheckAppCompat PROTO
;BasepCheckBadapp PROTO
;BasepCheckWebBladeHashes PROTO
;BasepCheckWinSaferRestrictions PROTO
;BasepConstructSxsCreateProcessMessage PROTO
;BasepCopyEncryption PROTO
;BasepFreeActivationContextActivationBlock PROTO
;BasepFreeAppCompatData PROTO
;BasepGetAppCompatData PROTO
;BasepGetComputerNameFromNtPath PROTO
;BasepGetExeArchType PROTO
;BasepIsProcessAllowed PROTO
;BasepMapModuleHandle PROTO
;BasepNotifyLoadStringResource PROTO
;BasepPostSuccessAppXExtension PROTO
;BasepProcessInvalidImage PROTO
;BasepQueryAppCompat PROTO
;BasepReleaseAppXContext PROTO
;BasepReleaseSxsCreateProcessUtilityStruct PROTO
;BasepReportFault PROTO
;BasepSetFileEncryptionCompression PROTO
;CancelTimerQueueTimer PROTO
;CheckAllowDecryptedRemoteDestinationPolicy PROTO
;CheckElevation PROTO
;CheckForReadOnlyResource PROTO
;CheckForReadOnlyResourceFilter PROTO
;CloseConsoleHandle PROTO
;CloseState PROTO
;CloseStateAtom PROTO
;CloseStateChangeNotification PROTO
;CloseStateContainer PROTO
;CloseStateLock PROTO
;CmdBatNotification PROTO
;CommitStateAtom PROTO
;CompareCalendarDates PROTO
;ConsoleIMERoutine PROTO
;ConvertNLSDayOfWeekToWin32DayOfWeek PROTO
;CreateActCtxWWorker PROTO
;CreateNlsSecurityDescriptor PROTO
;CreateSocketHandle PROTO
;CreateStateAtom PROTO
;CreateStateChangeNotification PROTO
;CreateStateContainer PROTO
;CreateStateLock PROTO
;CreateStateSubcontainer PROTO
;CtrlRoutine PROTO
;DeactivateActCtxWorker PROTO
;DeleteStateAtomValue PROTO
;DeleteStateContainer PROTO
;DeleteStateContainerValue PROTO
;DnsHostnameToComputerNameExW PROTO
;DuplicateEncryptionInfoFileExt PROTO
;DuplicateStateContainerHandle PROTO
;EnumerateStateAtomValues PROTO
;EnumerateStateContainerItems PROTO
;FindActCtxSectionGuidWorker PROTO
;FindActCtxSectionStringWWorker PROTO
;GetAppContainerAce PROTO
;GetApplicationRecoveryCallbackWorker PROTO
;GetApplicationRestartSettingsWorker PROTO
;GetCalendarDateFormat PROTO
;GetCalendarDaysInMonth PROTO
;GetCalendarDifferenceInDays PROTO
;GetCalendarMonthsInYear PROTO
;GetCalendarWeekNumber PROTO
;GetConsoleCharType PROTO
;GetConsoleCommandHistoryA PROTO
;GetConsoleCommandHistoryW PROTO
;GetConsoleCommandHistoryLengthA PROTO
;GetConsoleCommandHistoryLengthW PROTO
;GetConsoleCursorMode PROTO
;GetConsoleHardwareState PROTO
;GetConsoleInputExeNameA PROTO
;GetConsoleInputExeNameW PROTO
;GetConsoleInputWaitHandle PROTO
;GetConsoleKeyboardLayoutNameA PROTO
;GetConsoleKeyboardLayoutNameW PROTO
;GetCPFileNameFromRegistry PROTO
;GetCurrentActCtxWorker PROTO
;GetDateFormatAWorker PROTO
;GetDateFormatWWorker PROTO
;GetDefaultSortkeySize PROTO
;GetEncryptedFileVersionExt PROTO
;GetEraNameCountedString PROTO
;GetHivePath PROTO
;GetLinguistLangSize PROTO
;GetNlsSectionName PROTO
;GetRoamingLastObservedChangeTime PROTO
;GetSerializedAtomBytes PROTO
;GetStateContainerDepth PROTO
;GetStateFolder PROTO
;GetStateRootFolder PROTO
;GetStateSettingsFolder PROTO
;GetStateVersion PROTO
;GetSystemAppDataFolder PROTO
;GetSystemAppDataKey PROTO
;GetTimeFormatAWorker PROTO
;GetTimeFormatWWorker PROTO
;HeapSummary PROTO
;HeapCreateTagsW PROTO
;HeapExtend PROTO
;HeapQueryTagW PROTO
;HeapUsage PROTO
;IsValidUILanguage PROTO
;NlsCheckPolicy PROTO
;NlsConvertIntegerToString PROTO
;NlsEventDataDescCreate PROTO
;NlsGetCacheUpdateCount PROTO
;NlsResetProcessLocale PROTO
;NlsUpdateLocale PROTO
;NlsUpdateSystemLocale PROTO
;NlsWriteEtwEvent PROTO
;NotifyMountMgr PROTO
;NtVdm64CreateProcessInternalW PROTO
;OpenConsoleWStub PROTO
;OpenState PROTO
;OpenStateAtom PROTO
;OpenStateExplicit PROTO
;OverrideRoamingDataModificationTimesInRange PROTO
;PssWalkMarkerRewind PROTO
;PssWalkMarkerSeek PROTO
;PssWalkMarkerTell PROTO
;PrivMoveFileIdentityW PROTO
;PublishStateChangeNotification PROTO
;QueryActCtxSettingsWWorker PROTO
;QueryActCtxWWorker PROTO
;QueryStateAtomValueInfo PROTO
;QueryStateContainerItemInfo PROTO
;QuirkGetData2Worker PROTO
;QuirkGetDataWorker PROTO
;QuirkIsEnabled2Worker PROTO
;QuirkIsEnabled3Worker PROTO
;QuirkIsEnabledForPackage2Worker PROTO
;QuirkIsEnabledForPackage3Worker PROTO
;QuirkIsEnabledForPackage4Worker PROTO
;QuirkIsEnabledForPackageWorker PROTO
;QuirkIsEnabledForProcessWorker PROTO
;QuirkIsEnabledWorker PROTO
;RaiseInvalid16BitExeError PROTO
;ReadStateAtomValue PROTO
;ReadStateContainerValue PROTO
;RegisterConsoleIME PROTO
;RegisterConsoleOS2 PROTO
;RegisterConsoleVDM PROTO
;RegisterStateChangeNotification PROTO
;RegisterStateLock PROTO
;RegisterWaitForInputIdle PROTO
;RegisterWaitForSingleObjectEx PROTO
;RegisterWowBaseHandlers PROTO
;RegisterWowExec PROTO
;RegKrnGetGlobalState PROTO
;RegKrnInitialize PROTO
;ReleaseActCtxWorker PROTO
;ReleaseStateLock PROTO
;RemoveLocalAlternateComputerNameA PROTO
;RemoveLocalAlternateComputerNameW PROTO
;ResetState PROTO
;SetClientDynamicTimeZoneInformation PROTO
;SetClientTimeZoneInformation PROTO
;SetComPlusPackageInstallStatus PROTO
;SetComputerNameEx2W PROTO
;SetConsoleCommandHistoryMode PROTO
;SetConsoleCursorMode PROTO
;SetConsoleInputExeNameA PROTO
;SetConsoleInputExeNameW PROTO
;SetConsoleKeyShortcuts PROTO
;SetConsoleLocalEUDC PROTO
;SetConsoleMenuClose PROTO
;SetCPGlobal PROTO
;SetRoamingLastObservedChangeTime PROTO
;SetStateVersion PROTO
;SetThreadpoolTimerEx PROTO
;SetVolumeMountPointWStub PROTO
;SetWaitableTimerEx PROTO
;SortCloseHandle PROTO
;SortGetHandle PROTO
;SubscribeStateChangeNotification PROTO
;TermsrvConvertSysRootToUserDir PROTO
;TermsrvAppInstallMode PROTO
;TermsrvCreateRegEntry PROTO
;TermsrvDeleteKey PROTO
;TermsrvDeleteValue PROTO
;TermsrvGetPreSetValue PROTO
;TermsrvGetWindowsDirectoryA PROTO
;TermsrvGetWindowsDirectoryW PROTO
;TermsrvOpenRegEntry PROTO
;TermsrvOpenUserClasses PROTO
;TermsrvRestoreKey PROTO
;TermsrvSetKeySecurity PROTO
;TermsrvSetValueKey PROTO
;TermsrvSyncUserIniFileExt PROTO
;UnmapViewOfFileEx PROTO
;UnregisterConsoleIME PROTO
;UTRegister PROTO
;UTUnRegister PROTO
;UnregisterStateChangeNotification PROTO
;UnregisterStateLock PROTO
;UnsubscribeStateChangeNotification PROTO
;ValidateLCType PROTO
;ValidateLocale PROTO
;VDMConsoleOperation PROTO
;VDMOperationStarted PROTO
;VerifyConsoleIoHandle PROTO
;WerGetFlagsWorker PROTO
;WerRegisterFileWorker PROTO
;WerRegisterMemoryBlockWorker PROTO
;WerRegisterRuntimeExceptionModuleWorker PROTO
;WerSetFlagsWorker PROTO
;WerUnregisterFileWorker PROTO
;WerUnregisterMemoryBlockWorker PROTO
;WerUnregisterRuntimeExceptionModuleWorker PROTO
;WerpCleanupMessageMapping PROTO
;WerpGetDebugger PROTO
;WerpInitiateRemoteRecovery PROTO
;WerpLaunchAeDebug PROTO
;WerpNotifyLoadStringResource PROTO
;WerpNotifyLoadStringResourceEx PROTO
;WerpNotifyLoadStringResourceWorker PROTO
;WerpNotifyUseStringResource PROTO
;WerpNotifyUseStringResourceWorker PROTO
;WerpStringLookup PROTO
;WriteConsoleInputVDMA PROTO
;WriteConsoleInputVDMW PROTO
;WriteStateAtomValue PROTO
;WriteStateContainerValue PROTO
;ZombifyActCtxWorker PROTO

;IFDEF APP_UNICODE
;    GetConsoleCommandHistory EQU <GetConsoleCommandHistoryW>
;    GetConsoleCommandHistoryLength EQU <GetConsoleCommandHistoryLengthW>
;    GetConsoleInputExeName EQU <GetConsoleInputExeNameW>
;    GetConsoleKeyboardLayoutName EQU <GetConsoleKeyboardLayoutNameW>
;    RemoveLocalAlternateComputerName EQU <RemoveLocalAlternateComputerNameW>
;    SetConsoleInputExeName EQU <SetConsoleInputExeNameW>
;    TermsrvGetWindowsDirectory EQU <TermsrvGetWindowsDirectoryW>
;    WriteConsoleInputVDM EQU <WriteConsoleInputVDMW>
;ELSE
;    GetConsoleCommandHistory EQU <GetConsoleCommandHistoryA>
;    GetConsoleCommandHistoryLength EQU <GetConsoleCommandHistoryLengthA>
;    GetConsoleInputExeName EQU <GetConsoleInputExeNameA>
;    GetConsoleKeyboardLayoutName EQU <GetConsoleKeyboardLayoutNameA>
;    RemoveLocalAlternateComputerName EQU <RemoveLocalAlternateComputerNameA>
;    SetConsoleInputExeName EQU <SetConsoleInputExeNameA>
;    TermsrvGetWindowsDirectory EQU <TermsrvGetWindowsDirectoryA>
;    WriteConsoleInputVDM EQU <WriteConsoleInputVDMA>
;ENDIF

ENDIF ;KERNEL32_INC
