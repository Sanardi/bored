; =========================================================;
;                                                          ;
;    wlanapi.inc for Easy Code 2.0 64-bit Masm projects    ;
;                   (version 1.0.4)                        ;
;                                                          ;
; Copyright © Ramon Sala / Héctor A. Medina - 2015-2020    ;
;                                                          ;
; =========================================================;

IFNDEF WLANAPI_INC
WLANAPI_INC     EQU     1

WLAN_API_VERSION_1_0                                    EQU     00000001H
WLAN_API_VERSION_2_0                                    EQU     00000002H

IF (NTDDI_VERSION GE NTDDI_VISTA)
    WLAN_API_VERSION                                    EQU     WLAN_API_VERSION_2_0
ELSE
    IF (NTDDI_VERSION GE NTDDI_WINXP)
        WLAN_API_VERSION                                EQU     WLAN_API_VERSION_1_0
    ENDIF
ENDIF

L2_PROFILE_MAX_NAME_LENGTH                              EQU     256

WLAN_MAX_NAME_LENGTH                                    EQU     L2_PROFILE_MAX_NAME_LENGTH

WLAN_PROFILE_GROUP_POLICY                               EQU     00000001H
WLAN_PROFILE_USER                                       EQU     00000002H
WLAN_PROFILE_GET_PLAINTEXT_KEY                          EQU     00000004H
WLAN_PROFILE_CONNECTION_MODE_SET_BY_CLIENT              EQU     00010000H
WLAN_PROFILE_CONNECTION_MODE_AUTO                       EQU     00020000H

ADAPTER_NAME_LENGTH                                     EQU     256
ADAPTER_DESCRIPTION_LENGTH                              EQU     256

AP_NAME_LENGTH                                          EQU     256

dot11_BSS_type_infrastructure                           EQU     1
dot11_BSS_type_independent                              EQU     2
dot11_BSS_type_any                                      EQU     3

DOT11_SSID_MAX_LENGTH                                   EQU     32
DOT11_RATE_SET_MAX_LENGTH                               EQU     126

WLAN_MAX_PHY_TYPE_NUMBER                                EQU     8

wlan_interface_state_not_ready                          EQU     0
wlan_interface_state_connected                          EQU     1
wlan_interface_state_ad_hoc_network_formed              EQU     2
wlan_interface_state_disconnecting                      EQU     3
wlan_interface_state_disconnected                       EQU     4
wlan_interface_state_associating                        EQU     5
wlan_interface_state_discovering                        EQU     6
wlan_interface_state_authenticating                     EQU     7

dot11_BSS_type_infrastructure                           EQU     1
dot11_BSS_type_independent                              EQU     2
dot11_BSS_type_any                                      EQU     3

dot11_phy_type_unknown                                  EQU     0
dot11_phy_type_any                                      EQU     0
dot11_phy_type_fhss                                     EQU     1
dot11_phy_type_dsss                                     EQU     2
dot11_phy_type_irbaseband                               EQU     3
dot11_phy_type_ofdm                                     EQU     4
dot11_phy_type_hrdsss                                   EQU     5
dot11_phy_type_erp                                      EQU     6
dot11_phy_type_ht                                       EQU     7
dot11_phy_type_vht                                      EQU     8
dot11_phy_type_IHV_start                                EQU     80000000H
dot11_phy_type_IHV_end                                  EQU     0FFFFFFFFH

DOT11_AUTH_ALGO_80211_OPEN                              EQU     1
DOT11_AUTH_ALGO_80211_SHARED_KEY                        EQU     2
DOT11_AUTH_ALGO_WPA                                     EQU     3
DOT11_AUTH_ALGO_WPA_PSK                                 EQU     4
DOT11_AUTH_ALGO_WPA_NONE                                EQU     5
DOT11_AUTH_ALGO_RSNA                                    EQU     6
DOT11_AUTH_ALGO_RSNA_PSK                                EQU     7
DOT11_AUTH_ALGO_IHV_START                               EQU     80000000H
DOT11_AUTH_ALGO_IHV_END                                 EQU     0FFFFFFFFH

DOT11_AUTH_ALGORITHM_OPEN_SYSTEM                        EQU     DOT11_AUTH_ALGO_80211_OPEN
DOT11_AUTH_ALGORITHM_SHARED_KEY                         EQU     DOT11_AUTH_ALGO_80211_SHARED_KEY
DOT11_AUTH_ALGORITHM_WPA                                EQU     DOT11_AUTH_ALGO_WPA
DOT11_AUTH_ALGORITHM_WPA_PSK                            EQU     DOT11_AUTH_ALGO_WPA_PSK
DOT11_AUTH_ALGORITHM_WPA_NONE                           EQU     DOT11_AUTH_ALGO_WPA_NONE
DOT11_AUTH_ALGORITHM_RSNA                               EQU     DOT11_AUTH_ALGO_RSNA
DOT11_AUTH_ALGORITHM_RSNA_PSK                           EQU     DOT11_AUTH_ALGO_RSNA_PSK

DOT11_CIPHER_ALGO_NONE                                  EQU     0H
DOT11_CIPHER_ALGO_WEP40                                 EQU     1H
DOT11_CIPHER_ALGO_TKIP                                  EQU     2H
DOT11_CIPHER_ALGO_CCMP                                  EQU     4H
DOT11_CIPHER_ALGO_WEP104                                EQU     5H
DOT11_CIPHER_ALGO_WPA_USE_GROUP                         EQU     100H
DOT11_CIPHER_ALGO_RSN_USE_GROUP                         EQU     100H
DOT11_CIPHER_ALGO_WEP                                   EQU     101H
DOT11_CIPHER_ALGO_IHV_START                             EQU     080000000H
DOT11_CIPHER_ALGO_IHV_END                               EQU     0FFFFFFFFH

DOT11_OI_MAX_LENGTH                                     EQU     5
DOT11_OI_MIN_LENGTH                                     EQU     3

DOT11_PSD_IE_MAX_DATA_SIZE                              EQU     240
DOT11_PSD_IE_MAX_ENTRY_NUMBER                           EQU     5

WLAN_AVAILABLE_NETWORK_CONNECTED                        EQU     00000001H
WLAN_AVAILABLE_NETWORK_HAS_PROFILE                      EQU     00000002H
WLAN_AVAILABLE_NETWORK_CONSOLE_USER_PROFILE             EQU     00000004H
WLAN_AVAILABLE_NETWORK_INTERWORKING_SUPPORTED           EQU     00000008H
WLAN_AVAILABLE_NETWORK_HOTSPOT2_ENABLED                 EQU     00000010H
WLAN_AVAILABLE_NETWORK_ANQP_SUPPORTED                   EQU     00000020H
WLAN_AVAILABLE_NETWORK_HOTSPOT2_DOMAIN                  EQU     00000040H
WLAN_AVAILABLE_NETWORK_HOTSPOT2_ROAMING                 EQU     00000080H
WLAN_AVAILABLE_NETWORK_AUTO_CONNECT_FAILED              EQU     00000100H

WLAN_AVAILABLE_NETWORK_INCLUDE_ALL_ADHOC_PROFILES       EQU   00000001H
WLAN_AVAILABLE_NETWORK_INCLUDE_ALL_MANUAL_HIDDEN_PROFILES EQU 00000002H

L2_REASON_CODE_GROUP_SIZE                               EQU     010000H
L2_REASON_CODE_GEN_BASE                                 EQU     010000H
L2_REASON_CODE_DOT11_AC_BASE                            EQU     (L2_REASON_CODE_GEN_BASE+L2_REASON_CODE_GROUP_SIZE)
L2_REASON_CODE_DOT11_MSM_BASE                           EQU     (L2_REASON_CODE_DOT11_AC_BASE+L2_REASON_CODE_GROUP_SIZE)
L2_REASON_CODE_DOT11_SECURITY_BASE                      EQU     (L2_REASON_CODE_DOT11_MSM_BASE+L2_REASON_CODE_GROUP_SIZE)
L2_REASON_CODE_ONEX_BASE                                EQU     (L2_REASON_CODE_DOT11_SECURITY_BASE+L2_REASON_CODE_GROUP_SIZE)
L2_REASON_CODE_DOT3_AC_BASE                             EQU     (L2_REASON_CODE_ONEX_BASE+L2_REASON_CODE_GROUP_SIZE)
L2_REASON_CODE_DOT3_MSM_BASE                            EQU     (L2_REASON_CODE_DOT3_AC_BASE+L2_REASON_CODE_GROUP_SIZE)
L2_REASON_CODE_PROFILE_BASE                             EQU     (L2_REASON_CODE_DOT3_MSM_BASE+L2_REASON_CODE_GROUP_SIZE)
L2_REASON_CODE_IHV_BASE                                 EQU     (L2_REASON_CODE_PROFILE_BASE+L2_REASON_CODE_GROUP_SIZE)
L2_REASON_CODE_WIMAX_BASE                               EQU     (L2_REASON_CODE_IHV_BASE+L2_REASON_CODE_GROUP_SIZE)

WLAN_REASON_CODE_SUCCESS                                EQU     0
WLAN_REASON_CODE_UNKNOWN                                EQU     L2_REASON_CODE_UNKNOWN

WLAN_REASON_CODE_RANGE_SIZE                             EQU     L2_REASON_CODE_GROUP_SIZE
WLAN_REASON_CODE_BASE                                   EQU     L2_REASON_CODE_DOT11_AC_BASE

WLAN_REASON_CODE_AC_BASE                                EQU     L2_REASON_CODE_DOT11_AC_BASE
WLAN_REASON_CODE_AC_CONNECT_BASE                        EQU     (WLAN_REASON_CODE_AC_BASE + WLAN_REASON_CODE_RANGE_SIZE / 2)
WLAN_REASON_CODE_AC_END                                 EQU     (WLAN_REASON_CODE_AC_BASE + WLAN_REASON_CODE_RANGE_SIZE - 1)

WLAN_REASON_CODE_PROFILE_BASE                           EQU     L2_REASON_CODE_PROFILE_BASE
WLAN_REASON_CODE_PROFILE_CONNECT_BASE                   EQU     (WLAN_REASON_CODE_PROFILE_BASE + WLAN_REASON_CODE_RANGE_SIZE / 2)
WLAN_REASON_CODE_PROFILE_END                            EQU     (WLAN_REASON_CODE_PROFILE_BASE + WLAN_REASON_CODE_RANGE_SIZE - 1)

WLAN_REASON_CODE_MSM_BASE                               EQU     L2_REASON_CODE_DOT11_MSM_BASE
WLAN_REASON_CODE_MSM_CONNECT_BASE                       EQU     (WLAN_REASON_CODE_MSM_BASE + WLAN_REASON_CODE_RANGE_SIZE / 2)
WLAN_REASON_CODE_MSM_END                                EQU     (WLAN_REASON_CODE_MSM_BASE + WLAN_REASON_CODE_RANGE_SIZE - 1)

WLAN_REASON_CODE_MSMSEC_BASE                            EQU     L2_REASON_CODE_DOT11_SECURITY_BASE
WLAN_REASON_CODE_MSMSEC_CONNECT_BASE                    EQU     (WLAN_REASON_CODE_MSMSEC_BASE + WLAN_REASON_CODE_RANGE_SIZE / 2)
WLAN_REASON_CODE_MSMSEC_END                             EQU     (WLAN_REASON_CODE_MSMSEC_BASE + WLAN_REASON_CODE_RANGE_SIZE - 1)

WLAN_REASON_CODE_NETWORK_NOT_COMPATIBLE                 EQU     (WLAN_REASON_CODE_AC_BASE +1)
WLAN_REASON_CODE_PROFILE_NOT_COMPATIBLE                 EQU     (WLAN_REASON_CODE_AC_BASE +2)

WLAN_REASON_CODE_NO_AUTO_CONNECTION                     EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE +1)
WLAN_REASON_CODE_NOT_VISIBLE                            EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE +2)
WLAN_REASON_CODE_GP_DENIED                              EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE +3)
WLAN_REASON_CODE_USER_DENIED                            EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE +4)
WLAN_REASON_CODE_BSS_TYPE_NOT_ALLOWED                   EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE +5)
WLAN_REASON_CODE_IN_FAILED_LIST                         EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE +6)
WLAN_REASON_CODE_IN_BLOCKED_LIST                        EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE +7)
WLAN_REASON_CODE_SSID_LIST_TOO_LONG                     EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE +8)
WLAN_REASON_CODE_CONNECT_CALL_FAIL                      EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE +9)
WLAN_REASON_CODE_SCAN_CALL_FAIL                         EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE +10)
WLAN_REASON_CODE_NETWORK_NOT_AVAILABLE                  EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE +11)
WLAN_REASON_CODE_PROFILE_CHANGED_OR_DELETED             EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE +12)
WLAN_REASON_CODE_KEY_MISMATCH                           EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE + 13)
WLAN_REASON_CODE_USER_NOT_RESPOND                       EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE + 14)
WLAN_REASON_CODE_AP_PROFILE_NOT_ALLOWED_FOR_CLIENT      EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE + 15)
WLAN_REASON_CODE_AP_PROFILE_NOT_ALLOWED                 EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE + 16)
WLAN_REASON_CODE_HOTSPOT2_PROFILE_DENIED                EQU     (WLAN_REASON_CODE_AC_CONNECT_BASE + 17)

WLAN_REASON_CODE_INVALID_PROFILE_SCHEMA                 EQU     (WLAN_REASON_CODE_PROFILE_BASE +1)
WLAN_REASON_CODE_PROFILE_MISSING                        EQU     (WLAN_REASON_CODE_PROFILE_BASE +2)
WLAN_REASON_CODE_INVALID_PROFILE_NAME                   EQU     (WLAN_REASON_CODE_PROFILE_BASE +3)
WLAN_REASON_CODE_INVALID_PROFILE_TYPE                   EQU     (WLAN_REASON_CODE_PROFILE_BASE +4)
WLAN_REASON_CODE_INVALID_PHY_TYPE                       EQU     (WLAN_REASON_CODE_PROFILE_BASE +5)
WLAN_REASON_CODE_MSM_SECURITY_MISSING                   EQU     (WLAN_REASON_CODE_PROFILE_BASE +6)
WLAN_REASON_CODE_IHV_SECURITY_NOT_SUPPORTED             EQU     (WLAN_REASON_CODE_PROFILE_BASE +7)
WLAN_REASON_CODE_IHV_OUI_MISMATCH                       EQU     (WLAN_REASON_CODE_PROFILE_BASE +8)
WLAN_REASON_CODE_IHV_OUI_MISSING                        EQU     (WLAN_REASON_CODE_PROFILE_BASE +9)
WLAN_REASON_CODE_IHV_SETTINGS_MISSING                   EQU     (WLAN_REASON_CODE_PROFILE_BASE +10)
WLAN_REASON_CODE_CONFLICT_SECURITY                      EQU     (WLAN_REASON_CODE_PROFILE_BASE +11)
WLAN_REASON_CODE_SECURITY_MISSING                       EQU     (WLAN_REASON_CODE_PROFILE_BASE +12)
WLAN_REASON_CODE_INVALID_BSS_TYPE                       EQU     (WLAN_REASON_CODE_PROFILE_BASE +13)
WLAN_REASON_CODE_INVALID_ADHOC_CONNECTION_MODE          EQU     (WLAN_REASON_CODE_PROFILE_BASE +14)
WLAN_REASON_CODE_NON_BROADCAST_SET_FOR_ADHOC            EQU     (WLAN_REASON_CODE_PROFILE_BASE +15)
WLAN_REASON_CODE_AUTO_SWITCH_SET_FOR_ADHOC              EQU     (WLAN_REASON_CODE_PROFILE_BASE +16)
WLAN_REASON_CODE_AUTO_SWITCH_SET_FOR_MANUAL_CONNECTION  EQU     (WLAN_REASON_CODE_PROFILE_BASE +17)
WLAN_REASON_CODE_IHV_SECURITY_ONEX_MISSING              EQU     (WLAN_REASON_CODE_PROFILE_BASE +18)
WLAN_REASON_CODE_PROFILE_SSID_INVALID                   EQU     (WLAN_REASON_CODE_PROFILE_BASE +19)
WLAN_REASON_CODE_TOO_MANY_SSID                          EQU     (WLAN_REASON_CODE_PROFILE_BASE +20)
WLAN_REASON_CODE_IHV_CONNECTIVITY_NOT_SUPPORTED         EQU     (WLAN_REASON_CODE_PROFILE_BASE +21)
WLAN_REASON_CODE_BAD_MAX_NUMBER_OF_CLIENTS_FOR_AP       EQU     (WLAN_REASON_CODE_PROFILE_BASE +22)
WLAN_REASON_CODE_INVALID_CHANNEL                        EQU     (WLAN_REASON_CODE_PROFILE_BASE +23)
WLAN_REASON_CODE_OPERATION_MODE_NOT_SUPPORTED           EQU     (WLAN_REASON_CODE_PROFILE_BASE +24)
WLAN_REASON_CODE_AUTO_AP_PROFILE_NOT_ALLOWED            EQU     (WLAN_REASON_CODE_PROFILE_BASE +25)
WLAN_REASON_CODE_AUTO_CONNECTION_NOT_ALLOWED            EQU     (WLAN_REASON_CODE_PROFILE_BASE +26)
WLAN_REASON_CODE_HOTSPOT2_PROFILE_NOT_ALLOWED           EQU     (WLAN_REASON_CODE_PROFILE_BASE +27)

WLAN_REASON_CODE_UNSUPPORTED_SECURITY_SET_BY_OS         EQU     (WLAN_REASON_CODE_MSM_BASE +1)
WLAN_REASON_CODE_UNSUPPORTED_SECURITY_SET               EQU     (WLAN_REASON_CODE_MSM_BASE +2)
WLAN_REASON_CODE_BSS_TYPE_UNMATCH                       EQU     (WLAN_REASON_CODE_MSM_BASE +3)
WLAN_REASON_CODE_PHY_TYPE_UNMATCH                       EQU     (WLAN_REASON_CODE_MSM_BASE +4)
WLAN_REASON_CODE_DATARATE_UNMATCH                       EQU     (WLAN_REASON_CODE_MSM_BASE +5)

WLAN_REASON_CODE_USER_CANCELLED                         EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+1)
WLAN_REASON_CODE_ASSOCIATION_FAILURE                    EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+2)
WLAN_REASON_CODE_ASSOCIATION_TIMEOUT                    EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+3)
WLAN_REASON_CODE_PRE_SECURITY_FAILURE                   EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+4)
WLAN_REASON_CODE_START_SECURITY_FAILURE                 EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+5)
WLAN_REASON_CODE_SECURITY_FAILURE                       EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+6)
WLAN_REASON_CODE_SECURITY_TIMEOUT                       EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+7)
WLAN_REASON_CODE_ROAMING_FAILURE                        EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+8)
WLAN_REASON_CODE_ROAMING_SECURITY_FAILURE               EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+9)
WLAN_REASON_CODE_ADHOC_SECURITY_FAILURE                 EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+10)
WLAN_REASON_CODE_DRIVER_DISCONNECTED                    EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+11)
WLAN_REASON_CODE_DRIVER_OPERATION_FAILURE               EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+12)
WLAN_REASON_CODE_IHV_NOT_AVAILABLE                      EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+13)
WLAN_REASON_CODE_IHV_NOT_RESPONDING                     EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+14)
WLAN_REASON_CODE_DISCONNECT_TIMEOUT                     EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+15)
WLAN_REASON_CODE_INTERNAL_FAILURE                       EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+16)
WLAN_REASON_CODE_UI_REQUEST_TIMEOUT                     EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+17)
WLAN_REASON_CODE_TOO_MANY_SECURITY_ATTEMPTS             EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+18)
WLAN_REASON_CODE_AP_STARTING_FAILURE                    EQU     (WLAN_REASON_CODE_MSM_CONNECT_BASE+19)

WLAN_REASON_CODE_MSMSEC_MIN                             EQU     WLAN_REASON_CODE_MSMSEC_BASE

WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_KEY_INDEX       EQU     (WLAN_REASON_CODE_MSMSEC_BASE+1)
WLAN_REASON_CODE_MSMSEC_PROFILE_PSK_PRESENT             EQU     (WLAN_REASON_CODE_MSMSEC_BASE+2)
WLAN_REASON_CODE_MSMSEC_PROFILE_KEY_LENGTH              EQU     (WLAN_REASON_CODE_MSMSEC_BASE+3)
WLAN_REASON_CODE_MSMSEC_PROFILE_PSK_LENGTH              EQU     (WLAN_REASON_CODE_MSMSEC_BASE+4)
WLAN_REASON_CODE_MSMSEC_PROFILE_NO_AUTH_CIPHER_SPECIFIED EQU    (WLAN_REASON_CODE_MSMSEC_BASE+5)
WLAN_REASON_CODE_MSMSEC_PROFILE_TOO_MANY_AUTH_CIPHER_SPECIFIED EQU (WLAN_REASON_CODE_MSMSEC_BASE+6)
WLAN_REASON_CODE_MSMSEC_PROFILE_DUPLICATE_AUTH_CIPHER   EQU     (WLAN_REASON_CODE_MSMSEC_BASE+7)
WLAN_REASON_CODE_MSMSEC_PROFILE_RAWDATA_INVALID         EQU     (WLAN_REASON_CODE_MSMSEC_BASE+8)
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_AUTH_CIPHER     EQU     (WLAN_REASON_CODE_MSMSEC_BASE+9)
WLAN_REASON_CODE_MSMSEC_PROFILE_ONEX_DISABLED           EQU     (WLAN_REASON_CODE_MSMSEC_BASE+10)
WLAN_REASON_CODE_MSMSEC_PROFILE_ONEX_ENABLED            EQU     (WLAN_REASON_CODE_MSMSEC_BASE+11)
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PMKCACHE_MODE   EQU     (WLAN_REASON_CODE_MSMSEC_BASE+12)
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PMKCACHE_SIZE   EQU     (WLAN_REASON_CODE_MSMSEC_BASE+13)
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PMKCACHE_TTL    EQU     (WLAN_REASON_CODE_MSMSEC_BASE+14)
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PREAUTH_MODE    EQU     (WLAN_REASON_CODE_MSMSEC_BASE+15)
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PREAUTH_THROTTLE EQU    (WLAN_REASON_CODE_MSMSEC_BASE+16)
WLAN_REASON_CODE_MSMSEC_PROFILE_PREAUTH_ONLY_ENABLED    EQU     (WLAN_REASON_CODE_MSMSEC_BASE+17)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_NETWORK              EQU     (WLAN_REASON_CODE_MSMSEC_BASE+18)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_NIC                  EQU     (WLAN_REASON_CODE_MSMSEC_BASE+19)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE              EQU     (WLAN_REASON_CODE_MSMSEC_BASE+20)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_DISCOVERY            EQU     (WLAN_REASON_CODE_MSMSEC_BASE+21)
WLAN_REASON_CODE_MSMSEC_PROFILE_PASSPHRASE_CHAR         EQU     (WLAN_REASON_CODE_MSMSEC_BASE+22)
WLAN_REASON_CODE_MSMSEC_PROFILE_KEYMATERIAL_CHAR        EQU     (WLAN_REASON_CODE_MSMSEC_BASE+23)
WLAN_REASON_CODE_MSMSEC_PROFILE_WRONG_KEYTYPE           EQU     (WLAN_REASON_CODE_MSMSEC_BASE+24)
WLAN_REASON_CODE_MSMSEC_MIXED_CELL                      EQU     (WLAN_REASON_CODE_MSMSEC_BASE+25)
WLAN_REASON_CODE_MSMSEC_PROFILE_AUTH_TIMERS_INVALID     EQU     (WLAN_REASON_CODE_MSMSEC_BASE+26)
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_GKEY_INTV       EQU     (WLAN_REASON_CODE_MSMSEC_BASE+27)
WLAN_REASON_CODE_MSMSEC_TRANSITION_NETWORK              EQU     (WLAN_REASON_CODE_MSMSEC_BASE+28)
WLAN_REASON_CODE_MSMSEC_PROFILE_KEY_UNMAPPED_CHAR       EQU     (WLAN_REASON_CODE_MSMSEC_BASE+29)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_AUTH         EQU     (WLAN_REASON_CODE_MSMSEC_BASE+30)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_CIPHER       EQU     (WLAN_REASON_CODE_MSMSEC_BASE+31)
WLAN_REASON_CODE_MSMSEC_PROFILE_SAFE_MODE               EQU     (WLAN_REASON_CODE_MSMSEC_BASE+32)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_SAFE_MODE_NIC EQU    (WLAN_REASON_CODE_MSMSEC_BASE+33)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_SAFE_MODE_NW EQU     (WLAN_REASON_CODE_MSMSEC_BASE+34)
WLAN_REASON_CODE_MSMSEC_PROFILE_UNSUPPORTED_AUTH        EQU     (WLAN_REASON_CODE_MSMSEC_BASE+35)
WLAN_REASON_CODE_MSMSEC_PROFILE_UNSUPPORTED_CIPHER      EQU     (WLAN_REASON_CODE_MSMSEC_BASE+36)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_MFP_NW_NIC           EQU     (WLAN_REASON_CODE_MSMSEC_BASE+37)

WLAN_REASON_CODE_MSMSEC_UI_REQUEST_FAILURE              EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+1)
WLAN_REASON_CODE_MSMSEC_AUTH_START_TIMEOUT              EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+2)
WLAN_REASON_CODE_MSMSEC_AUTH_SUCCESS_TIMEOUT            EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+3)
WLAN_REASON_CODE_MSMSEC_KEY_START_TIMEOUT               EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+4)
WLAN_REASON_CODE_MSMSEC_KEY_SUCCESS_TIMEOUT             EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+5)
WLAN_REASON_CODE_MSMSEC_M3_MISSING_KEY_DATA             EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+6)
WLAN_REASON_CODE_MSMSEC_M3_MISSING_IE                   EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+7)
WLAN_REASON_CODE_MSMSEC_M3_MISSING_GRP_KEY              EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+8)
WLAN_REASON_CODE_MSMSEC_PR_IE_MATCHING                  EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+9)
WLAN_REASON_CODE_MSMSEC_SEC_IE_MATCHING                 EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+10)
WLAN_REASON_CODE_MSMSEC_NO_PAIRWISE_KEY                 EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+11)
WLAN_REASON_CODE_MSMSEC_G1_MISSING_KEY_DATA             EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+12)
WLAN_REASON_CODE_MSMSEC_G1_MISSING_GRP_KEY              EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+13)
WLAN_REASON_CODE_MSMSEC_PEER_INDICATED_INSECURE         EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+14)
WLAN_REASON_CODE_MSMSEC_NO_AUTHENTICATOR                EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+15)
WLAN_REASON_CODE_MSMSEC_NIC_FAILURE                     EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+16)
WLAN_REASON_CODE_MSMSEC_CANCELLED                       EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+17)
WLAN_REASON_CODE_MSMSEC_KEY_FORMAT                      EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+18)
WLAN_REASON_CODE_MSMSEC_DOWNGRADE_DETECTED              EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+19)
WLAN_REASON_CODE_MSMSEC_PSK_MISMATCH_SUSPECTED          EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+20)
WLAN_REASON_CODE_MSMSEC_FORCED_FAILURE                  EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+21)
WLAN_REASON_CODE_MSMSEC_M3_TOO_MANY_RSNIE               EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+22)
WLAN_REASON_CODE_MSMSEC_M2_MISSING_KEY_DATA             EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+23)
WLAN_REASON_CODE_MSMSEC_M2_MISSING_IE                   EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+24)
WLAN_REASON_CODE_MSMSEC_AUTH_WCN_COMPLETED              EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+25)
WLAN_REASON_CODE_MSMSEC_M3_MISSING_MGMT_GRP_KEY         EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+26)
WLAN_REASON_CODE_MSMSEC_G1_MISSING_MGMT_GRP_KEY         EQU     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+27)

WLAN_REASON_CODE_MSMSEC_MAX                             EQU     WLAN_REASON_CODE_MSMSEC_END

WLAN_MAX_PHY_INDEX                                      EQU     64

WLAN_CONNECTION_NOTIFICATION_ADHOC_NETWORK_FORMED       EQU     00000001H
WLAN_CONNECTION_NOTIFICATION_CONSOLE_USER_PROFILE       EQU     00000004H


wlan_notification_acm_start                             EQU     0
wlan_notification_acm_autoconf_enabled                  EQU     1
wlan_notification_acm_autoconf_disabled                 EQU     2
wlan_notification_acm_background_scan_enabled           EQU     3
wlan_notification_acm_background_scan_disabled          EQU     4
wlan_notification_acm_bss_type_change                   EQU     5
wlan_notification_acm_power_setting_change              EQU     6
wlan_notification_acm_scan_complete                     EQU     7
wlan_notification_acm_scan_fail                         EQU     8
wlan_notification_acm_connection_start                  EQU     9
wlan_notification_acm_connection_complete               EQU     10
wlan_notification_acm_connection_attempt_fail           EQU     11
wlan_notification_acm_filter_list_change                EQU     12
wlan_notification_acm_interface_arrival                 EQU     13
wlan_notification_acm_interface_removal                 EQU     14
wlan_notification_acm_profile_change                    EQU     15
wlan_notification_acm_profile_name_change               EQU     16
wlan_notification_acm_profiles_exhausted                EQU     17
wlan_notification_acm_network_not_available             EQU     18
wlan_notification_acm_network_available                 EQU     19
wlan_notification_acm_disconnecting                     EQU     20
wlan_notification_acm_disconnected                      EQU     21
wlan_notification_acm_adhoc_network_state_change        EQU     22
wlan_notification_acm_profile_unblocked                 EQU     23
wlan_notification_acm_screen_power_change               EQU     24
wlan_notification_acm_profile_blocked                   EQU     25
wlan_notification_acm_scan_list_refresh                 EQU     26
wlan_notification_acm_end                               EQU     27

WLAN_NOTIFICATION_SOURCE_NONE                           EQU     00000000H
WLAN_NOTIFICATION_SOURCE_ONEX                           EQU     00000004H
WLAN_NOTIFICATION_SOURCE_ACM                            EQU     00000008H
WLAN_NOTIFICATION_SOURCE_MSM                            EQU     00000010H
WLAN_NOTIFICATION_SOURCE_SECURITY                       EQU     00000020H
WLAN_NOTIFICATION_SOURCE_IHV                            EQU     00000040H
WLAN_NOTIFICATION_SOURCE_HNWK                           EQU     00000080H
WLAN_NOTIFICATION_SOURCE_ALL                            EQU     0000FFFFH

;======================================== Structures ======================================;

ADAPTER_INFO STRUCT ALIGNMODE
    _name                       WCHAR ADAPTER_NAME_LENGTH DUP(?)
    description                 WCHAR ADAPTER_DESCRIPTION_LENGTH DUP(?)
ADAPTER_INFO ENDS

MAC_ADDRESS STRUCT ALIGNMODE
    u                           UCHAR   6 DUP(?)
    IFDEF APP_WIN64
                                UCHAR   2 DUP(?)    ;Padding
    ENDIF
MAC_ADDRESS ENDS

AP_INFO STRUCT ALIGNMODE
    _name                       CHAR    AP_NAME_LENGTH DUP(?)
    rssi                        DWORD   ?
    mac_address                 MAC_ADDRESS <>
AP_INFO ENDS

DOT11_OI STRUCT ALIGNMODE
    OILength    USHORT ?
    OI          UCHAR DOT11_OI_MAX_LENGTH DUP(?)
DOT11_OI ENDS

DOT11_AUTH_CIPHER_PAIR STRUCT ALIGNMODE
    AuthAlgoId      DWORD   ?
    CipherAlgoId    DWORD   ?
DOT11_AUTH_CIPHER_PAIR ENDS

DOT11_SSID STRUCT
   uSSIDLength      ULONG ?
   ucSSID           UCHAR DOT11_SSID_MAX_LENGTH DUP(?)
DOT11_SSID ENDS

DOT11_MAC_ADDRESS STRUCT
    ucDot11MacAddress   DB  6 DUP(?)
    IFDEF APP_WIN64
                        DB  2 DUP(?)    ;Padding
    ENDIF
DOT11_MAC_ADDRESS ENDS

DOT11_NETWORK STRUCT ALIGNMODE
    dot11Ssid       DOT11_SSID <>
    dot11BssType    XWORD ?
DOT11_NETWORK ENDS

DOT11_ACCESSNETWORKOPTIONS STRUCT ALIGNMODE
    AccessNetworkType   UINT8 ?
    Internet            UINT8 ?
    ASRA                UINT8 ?
    ESR                 UINT8 ?
    UESA                UINT8 ?
DOT11_ACCESSNETWORKOPTIONS ENDS

DOT11_VENUEINFO STRUCT ALIGNMODE
    VenueGroup  UINT8 ?
    VenueType   UINT8 ?
DOT11_VENUEINFO ENDS

WLAN_PROFILE_INFO STRUCT ALIGNMODE
    strProfileName  WCHAR WLAN_MAX_NAME_LENGTH DUP(?)
    dwFlags         DWORD ?
WLAN_PROFILE_INFO ENDS

WLAN_INTERFACE_INFO STRUCT
    InterfaceGuid           GUID    <>
    strInterfaceDescription WCHAR   256 DUP(?)
    isState                 XWORD   ?
WLAN_INTERFACE_INFO ENDS

WLAN_INTERFACE_INFO_LIST STRUCT
    dwNumberOfItems         DWORD   ?
    dwIndex                 DWORD   ?
    InterfaceInfo           WLAN_INTERFACE_INFO <>
WLAN_INTERFACE_INFO_LIST ENDS

WLAN_ASSOCIATION_ATTRIBUTES STRUCT ALIGNMODE
    dot11Ssid           DOT11_SSID <>
    dot11BssType        DWORD ?
    dot11Bssid          DOT11_MAC_ADDRESS <>
    dot11PhyType        DWORD ?
    uDot11PhyIndex      ULONG ?
    wlanSignalQuality   XWORD ?
    ulRxRate            ULONG ?
    ulTxRate            ULONG ?
WLAN_ASSOCIATION_ATTRIBUTES ENDS

WLAN_SECURITY_ATTRIBUTES STRUCT ALIGNMODE
    bSecurityEnabled        BOOL  ?
    bOneXEnabled            BOOL  ?
    dot11AuthAlgorithm      DWORD ?
    dot11CipherAlgorithm    DWORD ?
WLAN_SECURITY_ATTRIBUTES ENDS

WLAN_AVAILABLE_NETWORK STRUCT
    strProfileName              WCHAR   WLAN_MAX_NAME_LENGTH DUP(?)
    dot11Ssid                   DOT11_SSID <>
    dot11BssType                DWORD   ?
    uNumberOfBssids             DWORD   ?
    bNetworkConnectable         BOOL    ?
    wlanNotConnectableReason    DWORD   ?
    uNumberOfPhyTypes           DWORD   ?
    dot11PhyTypes               DWORD   WLAN_MAX_PHY_TYPE_NUMBER DUP(?)
    bMorePhyTypes               DWORD   ?
    wlanSignalQuality           DWORD   ?
    bSecurityEnabled            BOOL    ?
    dot11DefaultAuthAlgorithm   DWORD   ?
    DOT11_CIPHER_ALGORITHM      DWORD   ?
    dwFlags                     DWORD   ?
    dwReserved                  DWORD   ?
WLAN_AVAILABLE_NETWORK ENDS

WLAN_AVAILABLE_NETWORK_V2 STRUCT ALIGNMODE
    strProfileName              WCHAR   WLAN_MAX_NAME_LENGTH DUP(?)
    dot11Ssid                   DOT11_SSID <>
    dot11BssType                DWORD   ?
    uNumberOfBssids             ULONG   ?
    bNetworkConnectable         BOOL    ?
    wlanNotConnectableReason    DWORD   ?
    uNumberOfPhyTypes           ULONG   ?
    dot11PhyTypes               DWORD   WLAN_MAX_PHY_TYPE_NUMBER DUP(?)
    bMorePhyTypes               BOOL    ?
    wlanSignalQuality           DWORD   ?
    bSecurityEnabled            BOOL    ?
    dot11DefaultAuthAlgorithm   DWORD   ?
    dot11DefaultCipherAlgorithm DWORD   ?
    dwFlags                     DWORD   ?
    AccessNetworkOptions        DOT11_ACCESSNETWORKOPTIONS <>
    dot11HESSID                 XWORD   ?
    VenueInfo                   DOT11_VENUEINFO <>
    dwReserved                  DWORD   ?
WLAN_AVAILABLE_NETWORK_V2 ENDS

WLAN_AVAILABLE_NETWORK_LIST STRUCT
    dwNumberOfItems DWORD   ?
    dwIndex         DWORD   ?
    Network         WLAN_AVAILABLE_NETWORK 1 DUP(<>)
WLAN_AVAILABLE_NETWORK_LIST ENDS

WLAN_RAW_DATA STRUCT ALIGNMODE
    dwDataSize  DWORD ?
    DataBlob    BYTE 1 DUP(?)
WLAN_RAW_DATA ENDS

WLAN_RATE_SET STRUCT ALIGNMODE
    uRateSetLength  ULONG   ?
    usRateSet       USHORT  DOT11_RATE_SET_MAX_LENGTH DUP(?)
WLAN_RATE_SET ENDS

WLAN_BSS_ENTRY STRUCT
    dot11Ssid               DOT11_SSID  <>
    uPhyId                  ULONG       ?
    dot11Bssid              DOT11_MAC_ADDRESS <>
    dot11BssType            DWORD       ?
    dot11BssPhyType         DWORD       ?
    lRssi                   LONG        ?
    uLinkQuality            ULONG       ?
    bInRegDomain            USHORT      ?
    usBeaconPeriod          USHORT      ?
    IFDEF APP_WIN64
                            DB          4 DUP(?)    ;Padding
    ENDIF
    ullTimestamp            ULONGLONG   ?
    ullHostTimestamp        ULONGLONG   ?
    IFDEF APP_WIN64
        usCapabilityInformation ULONG   ?
    ELSE
        usCapabilityInformation USHORT  ?
    ENDIF
    ulChCenterFrequency     ULONG       ?
    wlanRateSet             WLAN_RATE_SET <>
    ulIeOffset              ULONG       ?
    ulIeSize                ULONG       ?
WLAN_BSS_ENTRY ENDS
    
WLAN_BSS_LIST STRUCT
     dwTotalSize                DWORD   ?
     dwNumberOfItems            DWORD   ?
     wlanBssEntries             WLAN_BSS_ENTRY 1 DUP(<>)
WLAN_BSS_LIST ENDS

WLAN_CONNECTION_ATTRIBUTES STRUCT ALIGNMODE
    isState                     DWORD ?
    wlanConnectionMode          DWORD ?
    strProfileName              WCHAR WLAN_MAX_NAME_LENGTH DUP(?)
    wlanAssociationAttributes   WLAN_ASSOCIATION_ATTRIBUTES <>
    wlanSecurityAttributes      WLAN_SECURITY_ATTRIBUTES <>
WLAN_CONNECTION_ATTRIBUTES ENDS

WLAN_PHY_RADIO_STATE STRUCT ALIGNMODE
    dwPhyIndex              DWORD ?
    dot11SoftwareRadioState DWORD ?
    dot11HardwareRadioState DWORD ?
WLAN_PHY_RADIO_STATE ENDS

WLAN_RADIO_STATE STRUCT ALIGNMODE
    dwNumberOfPhys  DWORD ?
    PhyRadioState   WLAN_PHY_RADIO_STATE WLAN_MAX_PHY_INDEX DUP(<>)
WLAN_RADIO_STATE ENDS

WLAN_MSM_NOTIFICATION_DATA STRUCT ALIGNMODE
    wlanConnectionMode  DWORD ?
    strProfileName      WCHAR WLAN_MAX_NAME_LENGTH DUP(?)
    dot11Ssid           DOT11_SSID <>
    dot11BssType        DWORD ?
    dot11MacAddr        DOT11_MAC_ADDRESS <>
    bSecurityEnabled    BOOL  ?
    bFirstPeer          BOOL  ?
    bLastPeer           BOOL  ?
    wlanReasonCode      DWORD ?
WLAN_MSM_NOTIFICATION_DATA ENDS

WLAN_CONNECTION_NOTIFICATION_DATA STRUCT ALIGNMODE
    wlanConnectionMode      DWORD ?
    strProfileName          WCHAR WLAN_MAX_NAME_LENGTH DUP(?)
    dot11Ssid               DOT11_SSID <>
    dot11BssType            DWORD ?
    bSecurityEnabled        BOOL  ?
    wlanReasonCode          DWORD ?
    dwFlags                 DWORD ?
    strProfileXml           WCHAR 1 DUP(?)
WLAN_CONNECTION_NOTIFICATION_DATA ENDS

WLAN_NOTIFICATION_DATA STRUCT
    NotificationSource      DWORD ?
    NotificationCode        DWORD ?
    InterfaceGuid           GUID  <?>
    dwDataSize              DWORD ?
    pData                   PVOID ?
WLAN_NOTIFICATION_DATA ENDS

DATALIST Struct
    dwDataOffset            DWORD ?
    dwDataSize              DWORD ?
DATALIST ENDS

WLAN_RAW_DATA_LIST STRUCT
    dwTotalSize             DWORD ?
    dwNumberOfItems         DWORD ?
    __unnamed_struct_17d8_1 DATALIST <?>
WLAN_RAW_DATA_LIST ENDS


;======================================== Functions =======================================;

IF (NTDDI_VERSION GE NTDDI_VISTA)
    WlanAllocateMemory PROTO :XWORD
    WlanCloseHandle PROTO :XWORD, :XWORD
    WlanConnect PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WlanDeleteProfile PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WlanDisconnect PROTO :XWORD, :XWORD, :XWORD
    WlanEnumInterfaces PROTO :XWORD, :XWORD, :XWORD
    WlanExtractPsdIEDataList PROTO :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR
    WlanFreeMemory PROTO :XWORD
    WlanGetAvailableNetworkList PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanGetFilterList PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WlanGetInterfaceCapability PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WlanGetNetworkBssList PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanGetProfile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanGetProfileCustomUserData PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanGetProfileList PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WlanGetSecuritySettings PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanIhvControl PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanOpenHandle PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WlanQueryAutoConfigParameter PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanQueryInterface PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanReasonCodeToString PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WlanRegisterNotification PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanRenameProfile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanSaveTemporaryProfile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanScan PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanSetAutoConfigParameter PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanSetFilterList PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WlanSetInterface PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanSetProfile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanSetProfileCustomUserData PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanSetProfileEapUserData PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanSetProfileEapXmlUserData PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanSetProfileList PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanSetProfilePosition PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanSetPsdIEDataList PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WlanSetSecuritySettings PROTO :XWORD, :XWORD, :XWORD
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN7)
    WlanHostedNetworkForceStart PROTO :XWORD, :XWORD, :XWORD
    WlanHostedNetworkForceStop PROTO :XWORD, :XWORD, :XWORD
    WlanHostedNetworkInitSettings PROTO :XWORD, :XWORD, :XWORD
    WlanHostedNetworkQueryProperty PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanHostedNetworkQuerySecondaryKey PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanHostedNetworkQueryStatus PROTO :XWORD, :XWORD, :XWORD
    WlanHostedNetworkRefreshSecuritySettings PROTO :XWORD, :XWORD, :XWORD
    WlanHostedNetworkSetProperty PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanHostedNetworkSetSecondaryKey PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WlanHostedNetworkStartUsing PROTO :XWORD, :XWORD, :XWORD
    WlanHostedNetworkStopUsing PROTO :XWORD, :XWORD, :XWORD
    WlanRegisterVirtualStationNotification PROTO :XWORD, :XWORD, :XWORD
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN8)
    WFDCancelOpenSession PROTO :XWORD
    WFDCloseHandle PROTO :XWORD
    WFDCloseSession PROTO :XWORD
    WFDOpenHandle PROTO :XWORD, :XWORD, :XWORD
    WFDOpenLegacySession PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WFDStartOpenSession PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WFDUpdateDeviceVisibility PROTO :XWORD
ENDIF


;======================= Undocumented functions (unknown arguments) =======================;
IF (NTDDI_VERSION GE NTDDI_WIN8)
    QueryNetconStatus PROTO :VARARG
    QueryNetconVirtualCharacteristic PROTO :VARARG
    WFDAcceptConnectRequestAndOpenSessionInt PROTO :VARARG
    WFDAcceptGroupRequestAndOpenSessionInt PROTO :VARARG
    WFDCancelConnectorPairWithOOB PROTO :VARARG
    WFDCancelListenerPairWithOOB PROTO :VARARG
    WFDCancelOpenSessionInt PROTO :VARARG
    WFDCloseHandleInt PROTO :VARARG
    WFDCloseLegacySessionInt PROTO :VARARG
    WFDCloseOOBPairingSession PROTO :VARARG
    WFDCloseSessionInt PROTO :VARARG
    WFDDeclineConnectRequestInt PROTO :VARARG
    WFDDeclineGroupRequestInt PROTO :VARARG
    WFDDiscoverDevicesInt PROTO :VARARG
    WFDFlushVisibleDeviceListInt PROTO :VARARG
    WFDForceDisconnectInt PROTO :VARARG
    WFDFreeMemoryInt PROTO :VARARG
    WFDGetDefaultGroupProfileInt PROTO :VARARG
    WFDGetOOBBlob PROTO :VARARG
    WFDGetProfileKeyInfoInt PROTO :VARARG
    WFDGetVisibleDevicesInt PROTO :VARARG
    WFDIsInterfaceWiFiDirect PROTO :VARARG
    WFDIsWiFiDirectRunningOnWiFiAdapter PROTO :VARARG
    WFDOpenHandleInt PROTO :VARARG
    WFDOpenLegacySessionInt PROTO :VARARG
    WFDPairCancelByDeviceAddressInt PROTO :VARARG
    WFDPairCancelInt PROTO :VARARG
    WFDPairEnumerateCeremoniesInt PROTO :VARARG
    WFDPairSelectCeremonyInt PROTO :VARARG
    WFDPairWithDeviceAndOpenSessionInt PROTO :VARARG
    WFDParseOOBBlob PROTO :VARARG
    WFDParseProfileXmlInt PROTO :VARARG
    WFDQueryPropertyInt PROTO :VARARG
    WFDRegisterNotificationInt PROTO :VARARG
    WFDSetAdditionalIEsInt PROTO :VARARG
    WFDSetPropertyInt PROTO :VARARG
    WFDSetSecondaryDeviceTypeListInt PROTO :VARARG
    WFDStartConnectorPairWithOOB PROTO :VARARG
    WFDStartListenerPairWithOOB PROTO :VARARG
    WFDStartOpenSessionInt PROTO :VARARG
    WFDStartUsingGroupInt PROTO :VARARG
    WFDStopUsingGroupInt PROTO :VARARG
    WlanCancelPlap PROTO :VARARG
    WlanConnectEx PROTO :VARARG
    WlanConnectWithInput PROTO :VARARG
    WlanDeinitPlapParams PROTO :VARARG
    WlanDoesBssMatchSecurity PROTO :VARARG
    WlanDoPlap PROTO :VARARG
    WlanEnumAllInterfaces PROTO :VARARG
    WlanGenerateProfileXmlBasicSettings PROTO :VARARG
    WlanGetMFPNegotiated PROTO :VARARG
    WlanGetProfileEapUserDataInfo PROTO :VARARG
    WlanGetProfileIndex PROTO :VARARG
    WlanGetProfileKeyInfo PROTO :VARARG
    WlanGetStoredRadioState PROTO :VARARG
    WlanHostedNetworkFreeWCNSettings PROTO :VARARG
    WlanHostedNetworkHlpQueryEverUsed PROTO :VARARG
    WlanHostedNetworkQueryWCNSettings PROTO :VARARG
    WlanHostedNetworkSetWCNSettings PROTO :VARARG
    WlanInitPlapParams PROTO :VARARG
    WlanInternalScan PROTO :VARARG
    WlanIsActiveConsoleUser PROTO :VARARG
    WlanIsNetworkSuppressed PROTO :VARARG
    WlanIsUIRequestPending PROTO :VARARG
    WlanLowPrivCloseHandle PROTO :VARARG
    WlanLowPrivEnumInterfaces PROTO :VARARG
    WlanLowPrivFreeMemory PROTO :VARARG
    WlanLowPrivOpenHandle PROTO :VARARG
    WlanLowPrivQueryInterface PROTO :VARARG
    WlanLowPrivSetInterface PROTO :VARARG
    WlanParseProfileXmlBasicSettings PROTO :VARARG
    WlanPrivateGetAvailableNetworkList PROTO :VARARG
    WlanQueryCreateAllUserProfileRestricted PROTO :VARARG
    WlanQueryPlapCredentials PROTO :VARARG
    WlanQueryPreConnectInput PROTO :VARARG
    WlanQueryVirtualInterfaceType PROTO :VARARG
    WlanRefreshConnections PROTO :VARARG
    WlanRemoveUIForwardingNetworkList PROTO :VARARG
    WlanSendUIResponse PROTO :VARARG
    WlanSetAllUserProfileRestricted PROTO :VARARG
    WlanSetProfileMetadata PROTO :VARARG
    WlanSignalValueToBar PROTO :VARARG
    WlanSsidToDisplayName PROTO :VARARG
    WlanStartAP PROTO :VARARG
    WlanStopAP PROTO :VARARG
    WlanStoreRadioStateOnEnteringAirPlaneMode PROTO :VARARG
    WlanStringToSsid PROTO :VARARG
    WlanWcmGetInterface PROTO :VARARG
    WlanWcmGetProfileList PROTO :VARARG
    WlanWcmSetInterface PROTO :VARARG
    WlanWfdGetPeerInfo PROTO :VARARG
    WlanWfdGOSetWCNSettings PROTO :VARARG
    WlanWfdStartGO PROTO :VARARG
    WlanWfdStopGO PROTO :VARARG
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN81)
    WFDConfigureFirewallForSessionInt PROTO :VARARG
    WFDForceDisconnectLegacyPeerInt PROTO :VARARG
    WFDGetSessionEndpointPairsInt PROTO :VARARG
    WFDLowPrivCancelOpenSessionInt PROTO :VARARG
    WFDLowPrivCloseHandleInt PROTO :VARARG
    WFDLowPrivCloseSessionInt PROTO :VARARG
    WFDLowPrivConfigureFirewallForSessionInt PROTO :VARARG
    WFDLowPrivGetSessionEndpointPairsInt PROTO :VARARG
    WFDLowPrivIsWfdSupportedInt PROTO :VARARG
    WFDLowPrivOpenHandleInt PROTO :VARARG
    WFDLowPrivRegisterNotificationInt PROTO :VARARG
    WFDLowPrivStartOpenSessionByInterfaceIdInt PROTO :VARARG
    WFDPairWithDeviceAndOpenSessionExInt PROTO :VARARG
    WFDStopDiscoverDevicesInt PROTO :VARARG
    WlanNotifyVsIeProviderInt PROTO :VARARG
    WlanTryUpgradeCurrentConnectionAuthCipher PROTO :VARARG
    WlanUpdateProfileWithAuthCipher PROTO :VARARG
    WlanUtf8SsidToDisplayName PROTO :VARARG
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN10)
    WFDAbortSessionInt PROTO :VARARG
    WFDCreateDHPrivatePublicKeyPairInt PROTO :VARARG
    WFDGetDeviceDescriptorForPendingRequestInt PROTO :VARARG
    WFDGetNFCCarrierConfigBlobInt PROTO :VARARG
    WFDLowPrivCloseLegacySessionInt PROTO :VARARG
    WFDLowPrivDeclineDeviceApiConnectionRequestInt PROTO :VARARG
    WFDLowPrivGetPendingGroupRequestDetailsInt PROTO :VARARG
    WFDLowPrivOpenLegacySessionInt PROTO :VARARG
    WFDLowPrivOpenSessionByDafObjectIdInt PROTO :VARARG
    WFDLowPrivQueryPropertyInt PROTO :VARARG
    WFDLowPrivRegisterVMgrCallerInt PROTO :VARARG
    WFDLowPrivSetPropertyInt PROTO :VARARG
    WFDLowPrivStartDeviceApiConnectionRequestListenerInt PROTO :VARARG
    WFDLowPrivStartUsingGroupInt PROTO :VARARG
    WFDLowPrivStopDeviceApiConnectionRequestListenerInt PROTO :VARARG
    WFDLowPrivStopUsingGroupInt PROTO :VARARG
    WFDLowPrivUnregisterVMgrCallerInt PROTO :VARARG
    WFDPairContinuePairWithDeviceInt PROTO :VARARG
    WFDParseOOBBlobTypeAndGetPayloadInt PROTO :VARARG
    WFDParseWfaNfcCarrierConfigBlobInt PROTO :VARARG
    WFDRegisterVMgrCallerInt PROTO :VARARG
    WFDStartBackgroundDiscoveryInt PROTO :VARARG
    WFDStartOffloadedDiscoveryInt PROTO :VARARG
    WFDStartUsingGroupExInt PROTO :VARARG
    WFDStopBackgroundDiscoveryInt PROTO :VARARG
    WFDStopOffloadedDiscoveryInt PROTO :VARARG
    WFDSvcLowPrivAcceptSessionInt PROTO :VARARG
    WFDSvcLowPrivCancelSessionInt PROTO :VARARG
    WFDSvcLowPrivCloseSessionInt PROTO :VARARG
    WFDSvcLowPrivConfigureSessionInt PROTO :VARARG
    WFDSvcLowPrivConnectSessionInt PROTO :VARARG
    WFDSvcLowPrivGetProvisioningInfoInt PROTO :VARARG
    WFDSvcLowPrivGetSessionEndpointPairsInt PROTO :VARARG
    WFDSvcLowPrivOpenAdvertiserSessionInt PROTO :VARARG
    WFDSvcLowPrivOpenSeekerSessionInt PROTO :VARARG
    WFDSvcLowPrivPublishServiceInt PROTO :VARARG
    WFDSvcLowPrivUnpublishServiceInt PROTO :VARARG
    WFDUnregisterVMgrCallerInt PROTO :VARARG
    WlanGetAvailableNetworkList2 PROTO :VARARG
    WlanLowPrivNotifyVsIeProviderInt PROTO :VARARG
    WlanNotifyVsIeProviderExInt PROTO :VARARG
    WlanPrivateClearAnqpCache PROTO :VARARG
    WlanPrivateGetAnqpCacheResponse PROTO :VARARG
    WlanPrivateParseAnqpRawData PROTO :VARARG
    WlanPrivateQueryInterface PROTO :VARARG
    WlanPrivateRefreshAnqpCache PROTO :VARARG
    WlanPrivateSetInterface PROTO :VARARG
    WlanSetProfileListForOffload PROTO :VARARG
    WlanStringToUtf8Ssid PROTO :VARARG
    WlanUpdateBasicProfileSecurity PROTO :VARARG
    WlanVMgrQueryCurrentScenariosInt PROTO :VARARG
    WlanWcmDisconnect PROTO :VARARG
    WlanWcmSetProfile PROTO :VARARG
ENDIF

ENDIF ;WLANAPI_INC
