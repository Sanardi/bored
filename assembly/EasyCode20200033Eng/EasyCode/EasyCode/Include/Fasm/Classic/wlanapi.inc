; ====================================================;
;                                                     ;
;     wlanapi.inc for EC v2 Fasm classic projects     ;
;                   (version 1.0.3)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

if ~defined WLANAPI_INC
define WLANAPI_INC  1

WLAN_API_VERSION_1_0                            equ     00000001H
WLAN_API_VERSION_2_0                            equ     00000002H

if (NTDDI_VERSION >= NTDDI_VISTA)
    WLAN_API_VERSION                            equ     WLAN_API_VERSION_2_0
else
    if (NTDDI_VERSION >= NTDDI_WINXP)
        WLAN_API_VERSION                        equ     WLAN_API_VERSION_1_0
    end if
end if

L2_PROFILE_MAX_NAME_LENGTH                      equ     256

WLAN_MAX_NAME_LENGTH                            equ     L2_PROFILE_MAX_NAME_LENGTH

WLAN_PROFILE_GROUP_POLICY                       equ     00000001H
WLAN_PROFILE_USER                               equ     00000002H
WLAN_PROFILE_GET_PLAINTEXT_KEY                  equ     00000004H
WLAN_PROFILE_CONNECTION_MODE_SET_BY_CLIENT      equ     00010000H
WLAN_PROFILE_CONNECTION_MODE_AUTO               equ     00020000H

ADAPTER_NAME_LENGTH                             equ     256
ADAPTER_DESCRIPTION_LENGTH                      equ     256

AP_NAME_LENGTH                                  equ     256

dot11_BSS_type_infrastructure                   equ     1
dot11_BSS_type_independent                      equ     2
dot11_BSS_type_any                              equ     3

DOT11_SSID_MAX_LENGTH                           equ     32
DOT11_RATE_SET_MAX_LENGTH                       equ     126

WLAN_MAX_PHY_TYPE_NUMBER                        equ     8

wlan_interface_state_not_ready                  equ     0
wlan_interface_state_connected                  equ     1
wlan_interface_state_ad_hoc_network_formed      equ     2
wlan_interface_state_disconnecting              equ     3
wlan_interface_state_disconnected               equ     4
wlan_interface_state_associating                equ     5
wlan_interface_state_discovering                equ     6
wlan_interface_state_authenticating             equ     7

dot11_phy_type_unknown                          equ     0
dot11_phy_type_any                              equ     0
dot11_phy_type_fhss                             equ     1
dot11_phy_type_dsss                             equ     2
dot11_phy_type_irbaseband                       equ     3
dot11_phy_type_ofdm                             equ     4
dot11_phy_type_hrdsss                           equ     5
dot11_phy_type_erp                              equ     6
dot11_phy_type_ht                               equ     7
dot11_phy_type_vht                              equ     8
dot11_phy_type_IHV_start                        equ     80000000H
dot11_phy_type_IHV_end                          equ     0FFFFFFFFH

DOT11_AUTH_ALGO_80211_OPEN                      equ     1
DOT11_AUTH_ALGO_80211_SHARED_KEY                equ     2
DOT11_AUTH_ALGO_WPA                             equ     3
DOT11_AUTH_ALGO_WPA_PSK                         equ     4
DOT11_AUTH_ALGO_WPA_NONE                        equ     5
DOT11_AUTH_ALGO_RSNA                            equ     6
DOT11_AUTH_ALGO_RSNA_PSK                        equ     7
DOT11_AUTH_ALGO_IHV_START                       equ     80000000H
DOT11_AUTH_ALGO_IHV_END                         equ     0FFFFFFFFH

DOT11_AUTH_ALGORITHM_OPEN_SYSTEM                equ     DOT11_AUTH_ALGO_80211_OPEN
DOT11_AUTH_ALGORITHM_SHARED_KEY                 equ     DOT11_AUTH_ALGO_80211_SHARED_KEY
DOT11_AUTH_ALGORITHM_WPA                        equ     DOT11_AUTH_ALGO_WPA
DOT11_AUTH_ALGORITHM_WPA_PSK                    equ     DOT11_AUTH_ALGO_WPA_PSK
DOT11_AUTH_ALGORITHM_WPA_NONE                   equ     DOT11_AUTH_ALGO_WPA_NONE
DOT11_AUTH_ALGORITHM_RSNA                       equ     DOT11_AUTH_ALGO_RSNA
DOT11_AUTH_ALGORITHM_RSNA_PSK                   equ     DOT11_AUTH_ALGO_RSNA_PSK

DOT11_CIPHER_ALGO_NONE                          equ     0H
DOT11_CIPHER_ALGO_WEP40                         equ     1H
DOT11_CIPHER_ALGO_TKIP                          equ     2H
DOT11_CIPHER_ALGO_CCMP                          equ     4H
DOT11_CIPHER_ALGO_WEP104                        equ     5H
DOT11_CIPHER_ALGO_WPA_USE_GROUP                 equ     100H
DOT11_CIPHER_ALGO_RSN_USE_GROUP                 equ     100H
DOT11_CIPHER_ALGO_WEP                           equ     101H
DOT11_CIPHER_ALGO_IHV_START                     equ     080000000H
DOT11_CIPHER_ALGO_IHV_END                       equ     0FFFFFFFFH

DOT11_OI_MAX_LENGTH                             equ     5
DOT11_OI_MIN_LENGTH                             equ     3

DOT11_PSD_IE_MAX_DATA_SIZE                      equ     240
DOT11_PSD_IE_MAX_ENTRY_NUMBER                   equ     5

WLAN_AVAILABLE_NETWORK_CONNECTED                equ     00000001H
WLAN_AVAILABLE_NETWORK_HAS_PROFILE              equ     00000002H
WLAN_AVAILABLE_NETWORK_CONSOLE_USER_PROFILE     equ     00000004H
WLAN_AVAILABLE_NETWORK_INTERWORKING_SUPPORTED   equ     00000008H
WLAN_AVAILABLE_NETWORK_HOTSPOT2_ENABLED         equ     00000010H
WLAN_AVAILABLE_NETWORK_ANQP_SUPPORTED           equ     00000020H
WLAN_AVAILABLE_NETWORK_HOTSPOT2_DOMAIN          equ     00000040H
WLAN_AVAILABLE_NETWORK_HOTSPOT2_ROAMING         equ     00000080H
WLAN_AVAILABLE_NETWORK_AUTO_CONNECT_FAILED      equ     00000100H

WLAN_AVAILABLE_NETWORK_INCLUDE_ALL_ADHOC_PROFILES equ   00000001H
WLAN_AVAILABLE_NETWORK_INCLUDE_ALL_MANUAL_HIDDEN_PROFILES equ 00000002H

L2_REASON_CODE_GROUP_SIZE                       equ     010000H
L2_REASON_CODE_GEN_BASE                         equ     010000H
L2_REASON_CODE_DOT11_AC_BASE                    equ     (L2_REASON_CODE_GEN_BASE+L2_REASON_CODE_GROUP_SIZE)
L2_REASON_CODE_DOT11_MSM_BASE                   equ     (L2_REASON_CODE_DOT11_AC_BASE+L2_REASON_CODE_GROUP_SIZE)
L2_REASON_CODE_DOT11_SECURITY_BASE              equ     (L2_REASON_CODE_DOT11_MSM_BASE+L2_REASON_CODE_GROUP_SIZE)
L2_REASON_CODE_ONEX_BASE                        equ     (L2_REASON_CODE_DOT11_SECURITY_BASE+L2_REASON_CODE_GROUP_SIZE)
L2_REASON_CODE_DOT3_AC_BASE                     equ     (L2_REASON_CODE_ONEX_BASE+L2_REASON_CODE_GROUP_SIZE)
L2_REASON_CODE_DOT3_MSM_BASE                    equ     (L2_REASON_CODE_DOT3_AC_BASE+L2_REASON_CODE_GROUP_SIZE)
L2_REASON_CODE_PROFILE_BASE                     equ     (L2_REASON_CODE_DOT3_MSM_BASE+L2_REASON_CODE_GROUP_SIZE)
L2_REASON_CODE_IHV_BASE                         equ     (L2_REASON_CODE_PROFILE_BASE+L2_REASON_CODE_GROUP_SIZE)
L2_REASON_CODE_WIMAX_BASE                       equ     (L2_REASON_CODE_IHV_BASE+L2_REASON_CODE_GROUP_SIZE)

WLAN_REASON_CODE_SUCCESS                        equ     0
WLAN_REASON_CODE_UNKNOWN                        equ     L2_REASON_CODE_UNKNOWN

WLAN_REASON_CODE_RANGE_SIZE                     equ     L2_REASON_CODE_GROUP_SIZE
WLAN_REASON_CODE_BASE                           equ     L2_REASON_CODE_DOT11_AC_BASE

WLAN_REASON_CODE_AC_BASE                        equ     L2_REASON_CODE_DOT11_AC_BASE
WLAN_REASON_CODE_AC_CONNECT_BASE                equ     (WLAN_REASON_CODE_AC_BASE + WLAN_REASON_CODE_RANGE_SIZE / 2)
WLAN_REASON_CODE_AC_END                         equ     (WLAN_REASON_CODE_AC_BASE + WLAN_REASON_CODE_RANGE_SIZE - 1)

WLAN_REASON_CODE_PROFILE_BASE                   equ     L2_REASON_CODE_PROFILE_BASE
WLAN_REASON_CODE_PROFILE_CONNECT_BASE           equ     (WLAN_REASON_CODE_PROFILE_BASE + WLAN_REASON_CODE_RANGE_SIZE / 2)
WLAN_REASON_CODE_PROFILE_END                    equ     (WLAN_REASON_CODE_PROFILE_BASE + WLAN_REASON_CODE_RANGE_SIZE - 1)

WLAN_REASON_CODE_MSM_BASE                       equ     L2_REASON_CODE_DOT11_MSM_BASE
WLAN_REASON_CODE_MSM_CONNECT_BASE               equ     (WLAN_REASON_CODE_MSM_BASE + WLAN_REASON_CODE_RANGE_SIZE / 2)
WLAN_REASON_CODE_MSM_END                        equ     (WLAN_REASON_CODE_MSM_BASE + WLAN_REASON_CODE_RANGE_SIZE - 1)

WLAN_REASON_CODE_MSMSEC_BASE                    equ     L2_REASON_CODE_DOT11_SECURITY_BASE
WLAN_REASON_CODE_MSMSEC_CONNECT_BASE            equ     (WLAN_REASON_CODE_MSMSEC_BASE + WLAN_REASON_CODE_RANGE_SIZE / 2)
WLAN_REASON_CODE_MSMSEC_END                     equ     (WLAN_REASON_CODE_MSMSEC_BASE + WLAN_REASON_CODE_RANGE_SIZE - 1)

WLAN_REASON_CODE_NETWORK_NOT_COMPATIBLE         equ     (WLAN_REASON_CODE_AC_BASE +1)
WLAN_REASON_CODE_PROFILE_NOT_COMPATIBLE         equ     (WLAN_REASON_CODE_AC_BASE +2)

WLAN_REASON_CODE_NO_AUTO_CONNECTION             equ     (WLAN_REASON_CODE_AC_CONNECT_BASE +1)
WLAN_REASON_CODE_NOT_VISIBLE                    equ     (WLAN_REASON_CODE_AC_CONNECT_BASE +2)
WLAN_REASON_CODE_GP_DENIED                      equ     (WLAN_REASON_CODE_AC_CONNECT_BASE +3)
WLAN_REASON_CODE_USER_DENIED                    equ     (WLAN_REASON_CODE_AC_CONNECT_BASE +4)
WLAN_REASON_CODE_BSS_TYPE_NOT_ALLOWED           equ     (WLAN_REASON_CODE_AC_CONNECT_BASE +5)
WLAN_REASON_CODE_IN_FAILED_LIST                 equ     (WLAN_REASON_CODE_AC_CONNECT_BASE +6)
WLAN_REASON_CODE_IN_BLOCKED_LIST                equ     (WLAN_REASON_CODE_AC_CONNECT_BASE +7)
WLAN_REASON_CODE_SSID_LIST_TOO_LONG             equ     (WLAN_REASON_CODE_AC_CONNECT_BASE +8)
WLAN_REASON_CODE_CONNECT_CALL_FAIL              equ     (WLAN_REASON_CODE_AC_CONNECT_BASE +9)
WLAN_REASON_CODE_SCAN_CALL_FAIL                 equ     (WLAN_REASON_CODE_AC_CONNECT_BASE +10)
WLAN_REASON_CODE_NETWORK_NOT_AVAILABLE          equ     (WLAN_REASON_CODE_AC_CONNECT_BASE +11)
WLAN_REASON_CODE_PROFILE_CHANGED_OR_DELETED     equ     (WLAN_REASON_CODE_AC_CONNECT_BASE +12)
WLAN_REASON_CODE_KEY_MISMATCH                   equ     (WLAN_REASON_CODE_AC_CONNECT_BASE + 13)
WLAN_REASON_CODE_USER_NOT_RESPOND               equ     (WLAN_REASON_CODE_AC_CONNECT_BASE + 14)
WLAN_REASON_CODE_AP_PROFILE_NOT_ALLOWED_FOR_CLIENT equ  (WLAN_REASON_CODE_AC_CONNECT_BASE + 15)
WLAN_REASON_CODE_AP_PROFILE_NOT_ALLOWED         equ     (WLAN_REASON_CODE_AC_CONNECT_BASE + 16)
WLAN_REASON_CODE_HOTSPOT2_PROFILE_DENIED        equ     (WLAN_REASON_CODE_AC_CONNECT_BASE + 17)

WLAN_REASON_CODE_INVALID_PROFILE_SCHEMA         equ     (WLAN_REASON_CODE_PROFILE_BASE +1)
WLAN_REASON_CODE_PROFILE_MISSING                equ     (WLAN_REASON_CODE_PROFILE_BASE +2)
WLAN_REASON_CODE_INVALID_PROFILE_NAME           equ     (WLAN_REASON_CODE_PROFILE_BASE +3)
WLAN_REASON_CODE_INVALID_PROFILE_TYPE           equ     (WLAN_REASON_CODE_PROFILE_BASE +4)
WLAN_REASON_CODE_INVALID_PHY_TYPE               equ     (WLAN_REASON_CODE_PROFILE_BASE +5)
WLAN_REASON_CODE_MSM_SECURITY_MISSING           equ     (WLAN_REASON_CODE_PROFILE_BASE +6)
WLAN_REASON_CODE_IHV_SECURITY_NOT_SUPPORTED     equ     (WLAN_REASON_CODE_PROFILE_BASE +7)
WLAN_REASON_CODE_IHV_OUI_MISMATCH               equ     (WLAN_REASON_CODE_PROFILE_BASE +8)
WLAN_REASON_CODE_IHV_OUI_MISSING                equ     (WLAN_REASON_CODE_PROFILE_BASE +9)
WLAN_REASON_CODE_IHV_SETTINGS_MISSING           equ     (WLAN_REASON_CODE_PROFILE_BASE +10)
WLAN_REASON_CODE_CONFLICT_SECURITY              equ     (WLAN_REASON_CODE_PROFILE_BASE +11)
WLAN_REASON_CODE_SECURITY_MISSING               equ     (WLAN_REASON_CODE_PROFILE_BASE +12)
WLAN_REASON_CODE_INVALID_BSS_TYPE               equ     (WLAN_REASON_CODE_PROFILE_BASE +13)
WLAN_REASON_CODE_INVALID_ADHOC_CONNECTION_MODE  equ     (WLAN_REASON_CODE_PROFILE_BASE +14)
WLAN_REASON_CODE_NON_BROADCAST_SET_FOR_ADHOC    equ     (WLAN_REASON_CODE_PROFILE_BASE +15)
WLAN_REASON_CODE_AUTO_SWITCH_SET_FOR_ADHOC      equ     (WLAN_REASON_CODE_PROFILE_BASE +16)
WLAN_REASON_CODE_AUTO_SWITCH_SET_FOR_MANUAL_CONNECTION equ (WLAN_REASON_CODE_PROFILE_BASE +17)
WLAN_REASON_CODE_IHV_SECURITY_ONEX_MISSING      equ     (WLAN_REASON_CODE_PROFILE_BASE +18)
WLAN_REASON_CODE_PROFILE_SSID_INVALID           equ     (WLAN_REASON_CODE_PROFILE_BASE +19)
WLAN_REASON_CODE_TOO_MANY_SSID                  equ     (WLAN_REASON_CODE_PROFILE_BASE +20)
WLAN_REASON_CODE_IHV_CONNECTIVITY_NOT_SUPPORTED equ     (WLAN_REASON_CODE_PROFILE_BASE +21)
WLAN_REASON_CODE_BAD_MAX_NUMBER_OF_CLIENTS_FOR_AP equ   (WLAN_REASON_CODE_PROFILE_BASE +22)
WLAN_REASON_CODE_INVALID_CHANNEL                equ     (WLAN_REASON_CODE_PROFILE_BASE +23)
WLAN_REASON_CODE_OPERATION_MODE_NOT_SUPPORTED   equ     (WLAN_REASON_CODE_PROFILE_BASE +24)
WLAN_REASON_CODE_AUTO_AP_PROFILE_NOT_ALLOWED    equ     (WLAN_REASON_CODE_PROFILE_BASE +25)
WLAN_REASON_CODE_AUTO_CONNECTION_NOT_ALLOWED    equ     (WLAN_REASON_CODE_PROFILE_BASE +26)
WLAN_REASON_CODE_HOTSPOT2_PROFILE_NOT_ALLOWED   equ     (WLAN_REASON_CODE_PROFILE_BASE +27)

WLAN_REASON_CODE_UNSUPPORTED_SECURITY_SET_BY_OS equ     (WLAN_REASON_CODE_MSM_BASE +1)
WLAN_REASON_CODE_UNSUPPORTED_SECURITY_SET       equ     (WLAN_REASON_CODE_MSM_BASE +2)
WLAN_REASON_CODE_BSS_TYPE_UNMATCH               equ     (WLAN_REASON_CODE_MSM_BASE +3)
WLAN_REASON_CODE_PHY_TYPE_UNMATCH               equ     (WLAN_REASON_CODE_MSM_BASE +4)
WLAN_REASON_CODE_DATARATE_UNMATCH               equ     (WLAN_REASON_CODE_MSM_BASE +5)

WLAN_REASON_CODE_USER_CANCELLED                 equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+1)
WLAN_REASON_CODE_ASSOCIATION_FAILURE            equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+2)
WLAN_REASON_CODE_ASSOCIATION_TIMEOUT            equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+3)
WLAN_REASON_CODE_PRE_SECURITY_FAILURE           equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+4)
WLAN_REASON_CODE_START_SECURITY_FAILURE         equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+5)
WLAN_REASON_CODE_SECURITY_FAILURE               equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+6)
WLAN_REASON_CODE_SECURITY_TIMEOUT               equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+7)
WLAN_REASON_CODE_ROAMING_FAILURE                equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+8)
WLAN_REASON_CODE_ROAMING_SECURITY_FAILURE       equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+9)
WLAN_REASON_CODE_ADHOC_SECURITY_FAILURE         equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+10)
WLAN_REASON_CODE_DRIVER_DISCONNECTED            equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+11)
WLAN_REASON_CODE_DRIVER_OPERATION_FAILURE       equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+12)
WLAN_REASON_CODE_IHV_NOT_AVAILABLE              equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+13)
WLAN_REASON_CODE_IHV_NOT_RESPONDING             equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+14)
WLAN_REASON_CODE_DISCONNECT_TIMEOUT             equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+15)
WLAN_REASON_CODE_INTERNAL_FAILURE               equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+16)
WLAN_REASON_CODE_UI_REQUEST_TIMEOUT             equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+17)
WLAN_REASON_CODE_TOO_MANY_SECURITY_ATTEMPTS     equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+18)
WLAN_REASON_CODE_AP_STARTING_FAILURE            equ     (WLAN_REASON_CODE_MSM_CONNECT_BASE+19)

WLAN_REASON_CODE_MSMSEC_MIN                     equ     WLAN_REASON_CODE_MSMSEC_BASE

WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_KEY_INDEX equ   (WLAN_REASON_CODE_MSMSEC_BASE+1)
WLAN_REASON_CODE_MSMSEC_PROFILE_PSK_PRESENT     equ     (WLAN_REASON_CODE_MSMSEC_BASE+2)
WLAN_REASON_CODE_MSMSEC_PROFILE_KEY_LENGTH      equ     (WLAN_REASON_CODE_MSMSEC_BASE+3)
WLAN_REASON_CODE_MSMSEC_PROFILE_PSK_LENGTH      equ     (WLAN_REASON_CODE_MSMSEC_BASE+4)
WLAN_REASON_CODE_MSMSEC_PROFILE_NO_AUTH_CIPHER_SPECIFIED equ (WLAN_REASON_CODE_MSMSEC_BASE+5)
WLAN_REASON_CODE_MSMSEC_PROFILE_TOO_MANY_AUTH_CIPHER_SPECIFIED equ (WLAN_REASON_CODE_MSMSEC_BASE+6)
WLAN_REASON_CODE_MSMSEC_PROFILE_DUPLICATE_AUTH_CIPHER equ (WLAN_REASON_CODE_MSMSEC_BASE+7)
WLAN_REASON_CODE_MSMSEC_PROFILE_RAWDATA_INVALID equ     (WLAN_REASON_CODE_MSMSEC_BASE+8)
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_AUTH_CIPHER equ (WLAN_REASON_CODE_MSMSEC_BASE+9)
WLAN_REASON_CODE_MSMSEC_PROFILE_ONEX_DISABLED   equ     (WLAN_REASON_CODE_MSMSEC_BASE+10)
WLAN_REASON_CODE_MSMSEC_PROFILE_ONEX_ENABLED    equ     (WLAN_REASON_CODE_MSMSEC_BASE+11)
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PMKCACHE_MODE equ (WLAN_REASON_CODE_MSMSEC_BASE+12)
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PMKCACHE_SIZE equ (WLAN_REASON_CODE_MSMSEC_BASE+13)
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PMKCACHE_TTL equ (WLAN_REASON_CODE_MSMSEC_BASE+14)
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PREAUTH_MODE equ (WLAN_REASON_CODE_MSMSEC_BASE+15)
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PREAUTH_THROTTLE equ (WLAN_REASON_CODE_MSMSEC_BASE+16)
WLAN_REASON_CODE_MSMSEC_PROFILE_PREAUTH_ONLY_ENABLED equ (WLAN_REASON_CODE_MSMSEC_BASE+17)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_NETWORK      equ     (WLAN_REASON_CODE_MSMSEC_BASE+18)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_NIC          equ     (WLAN_REASON_CODE_MSMSEC_BASE+19)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE      equ     (WLAN_REASON_CODE_MSMSEC_BASE+20)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_DISCOVERY    equ     (WLAN_REASON_CODE_MSMSEC_BASE+21)
WLAN_REASON_CODE_MSMSEC_PROFILE_PASSPHRASE_CHAR equ     (WLAN_REASON_CODE_MSMSEC_BASE+22)
WLAN_REASON_CODE_MSMSEC_PROFILE_KEYMATERIAL_CHAR      equ (WLAN_REASON_CODE_MSMSEC_BASE+23)
WLAN_REASON_CODE_MSMSEC_PROFILE_WRONG_KEYTYPE   equ     (WLAN_REASON_CODE_MSMSEC_BASE+24)
WLAN_REASON_CODE_MSMSEC_MIXED_CELL              equ     (WLAN_REASON_CODE_MSMSEC_BASE+25)
WLAN_REASON_CODE_MSMSEC_PROFILE_AUTH_TIMERS_INVALID equ (WLAN_REASON_CODE_MSMSEC_BASE+26)
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_GKEY_INTV equ (WLAN_REASON_CODE_MSMSEC_BASE+27)
WLAN_REASON_CODE_MSMSEC_TRANSITION_NETWORK      equ     (WLAN_REASON_CODE_MSMSEC_BASE+28)
WLAN_REASON_CODE_MSMSEC_PROFILE_KEY_UNMAPPED_CHAR equ (WLAN_REASON_CODE_MSMSEC_BASE+29)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_AUTH equ     (WLAN_REASON_CODE_MSMSEC_BASE+30)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_CIPHER equ (WLAN_REASON_CODE_MSMSEC_BASE+31)
WLAN_REASON_CODE_MSMSEC_PROFILE_SAFE_MODE       equ     (WLAN_REASON_CODE_MSMSEC_BASE+32)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_SAFE_MODE_NIC equ (WLAN_REASON_CODE_MSMSEC_BASE+33)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_SAFE_MODE_NW equ (WLAN_REASON_CODE_MSMSEC_BASE+34)
WLAN_REASON_CODE_MSMSEC_PROFILE_UNSUPPORTED_AUTH equ    (WLAN_REASON_CODE_MSMSEC_BASE+35)
WLAN_REASON_CODE_MSMSEC_PROFILE_UNSUPPORTED_CIPHER equ (WLAN_REASON_CODE_MSMSEC_BASE+36)
WLAN_REASON_CODE_MSMSEC_CAPABILITY_MFP_NW_NIC   equ     (WLAN_REASON_CODE_MSMSEC_BASE+37)

WLAN_REASON_CODE_MSMSEC_UI_REQUEST_FAILURE      equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+1)
WLAN_REASON_CODE_MSMSEC_AUTH_START_TIMEOUT      equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+2)
WLAN_REASON_CODE_MSMSEC_AUTH_SUCCESS_TIMEOUT    equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+3)
WLAN_REASON_CODE_MSMSEC_KEY_START_TIMEOUT       equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+4)
WLAN_REASON_CODE_MSMSEC_KEY_SUCCESS_TIMEOUT     equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+5)
WLAN_REASON_CODE_MSMSEC_M3_MISSING_KEY_DATA     equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+6)
WLAN_REASON_CODE_MSMSEC_M3_MISSING_IE           equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+7)
WLAN_REASON_CODE_MSMSEC_M3_MISSING_GRP_KEY      equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+8)
WLAN_REASON_CODE_MSMSEC_PR_IE_MATCHING          equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+9)
WLAN_REASON_CODE_MSMSEC_SEC_IE_MATCHING         equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+10)
WLAN_REASON_CODE_MSMSEC_NO_PAIRWISE_KEY         equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+11)
WLAN_REASON_CODE_MSMSEC_G1_MISSING_KEY_DATA     equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+12)
WLAN_REASON_CODE_MSMSEC_G1_MISSING_GRP_KEY      equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+13)
WLAN_REASON_CODE_MSMSEC_PEER_INDICATED_INSECURE equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+14)
WLAN_REASON_CODE_MSMSEC_NO_AUTHENTICATOR        equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+15)
WLAN_REASON_CODE_MSMSEC_NIC_FAILURE             equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+16)
WLAN_REASON_CODE_MSMSEC_CANCELLED               equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+17)
WLAN_REASON_CODE_MSMSEC_KEY_FORMAT              equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+18)
WLAN_REASON_CODE_MSMSEC_DOWNGRADE_DETECTED      equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+19)
WLAN_REASON_CODE_MSMSEC_PSK_MISMATCH_SUSPECTED  equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+20)
WLAN_REASON_CODE_MSMSEC_FORCED_FAILURE          equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+21)
WLAN_REASON_CODE_MSMSEC_M3_TOO_MANY_RSNIE       equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+22)
WLAN_REASON_CODE_MSMSEC_M2_MISSING_KEY_DATA     equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+23)
WLAN_REASON_CODE_MSMSEC_M2_MISSING_IE           equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+24)
WLAN_REASON_CODE_MSMSEC_AUTH_WCN_COMPLETED      equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+25)
WLAN_REASON_CODE_MSMSEC_M3_MISSING_MGMT_GRP_KEY equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+26)
WLAN_REASON_CODE_MSMSEC_G1_MISSING_MGMT_GRP_KEY equ     (WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+27)

WLAN_REASON_CODE_MSMSEC_MAX                     equ     WLAN_REASON_CODE_MSMSEC_END

WLAN_MAX_PHY_INDEX                              equ    64

WLAN_CONNECTION_NOTIFICATION_ADHOC_NETWORK_FORMED equ  00000001H
WLAN_CONNECTION_NOTIFICATION_CONSOLE_USER_PROFILE equ  00000004H

wlan_notification_acm_start                             equ     0
wlan_notification_acm_autoconf_enabled                  equ     1
wlan_notification_acm_autoconf_disabled                 equ     2
wlan_notification_acm_background_scan_enabled           equ     3
wlan_notification_acm_background_scan_disabled          equ     4
wlan_notification_acm_bss_type_change                   equ     5
wlan_notification_acm_power_setting_change              equ     6
wlan_notification_acm_scan_complete                     equ     7
wlan_notification_acm_scan_fail                         equ     8
wlan_notification_acm_connection_start                  equ     9
wlan_notification_acm_connection_complete               equ     10
wlan_notification_acm_connection_attempt_fail           equ     11
wlan_notification_acm_filter_list_change                equ     12
wlan_notification_acm_interface_arrival                 equ     13
wlan_notification_acm_interface_removal                 equ     14
wlan_notification_acm_profile_change                    equ     15
wlan_notification_acm_profile_name_change               equ     16
wlan_notification_acm_profiles_exhausted                equ     17
wlan_notification_acm_network_not_available             equ     18
wlan_notification_acm_network_available                 equ     19
wlan_notification_acm_disconnecting                     equ     20
wlan_notification_acm_disconnected                      equ     21
wlan_notification_acm_adhoc_network_state_change        equ     22
wlan_notification_acm_profile_unblocked                 equ     23
wlan_notification_acm_screen_power_change               equ     24
wlan_notification_acm_profile_blocked                   equ     25
wlan_notification_acm_scan_list_refresh                 equ     26
wlan_notification_acm_end                               equ     27

WLAN_NOTIFICATION_SOURCE_NONE                           equ     00000000H
WLAN_NOTIFICATION_SOURCE_ONEX                           equ     00000004H
WLAN_NOTIFICATION_SOURCE_ACM                            equ     00000008H
WLAN_NOTIFICATION_SOURCE_MSM                            equ     00000010H
WLAN_NOTIFICATION_SOURCE_SECURITY                       equ     00000020H
WLAN_NOTIFICATION_SOURCE_IHV                            equ     00000040H
WLAN_NOTIFICATION_SOURCE_HNWK                           equ     00000080H
WLAN_NOTIFICATION_SOURCE_ALL                            equ     0000FFFFH

;======================================== Structures ======================================;
struct ADAPTER_INFO
    name                        dw ADAPTER_NAME_LENGTH dup(?)
    description                 dw ADAPTER_DESCRIPTION_LENGTH dup(?)
ends

struct MAC_ADDRESS
    u                           db      6 dup(?)
                                db      2 dup(?)    ;Padding for WIN64
ends

struct AP_INFO
    _name                       db      AP_NAME_LENGTH dup(?)
    rssi                        dd      ?
    mac_address                 MAC_ADDRESS
ends

struct DOT11_OI
    OILength    dw ?
    OI          db DOT11_OI_MAX_LENGTH dup(?)
ends

struct DOT11_AUTH_CIPHER_PAIR
    AuthAlgoId      dd   ?
    CipherAlgoId    dd   ?
ends

struct DOT11_SSID
   uSSIDLength                  dd ?
   ucSSID                       db DOT11_SSID_MAX_LENGTH dup(?)
ends

struct DOT11_MAC_ADDRESS
    ucDot11MacAddress           db      6 dup(?)
                                db      2 dup(?)    ;Padding for WIN64
ends

struct DOT11_NETWORK
    dot11Ssid       DOT11_SSID
    dot11BssType    xptr ?
ends

struct DOT11_ACCESSNETWORKOPTIONS
    AccessNetworkType   db ?
    Internet            db ?
    ASRA                db ?
    ESR                 db ?
    UESA                db ?
                        db 3 dup(?)    ;Padding for WIN64
ends

struct DOT11_VENUEINFO
    VenueGroup  db ?
    VenueType   db ?
                db 2 dup(?)    ;Padding for WIN64
ends

struct WLAN_PROFILE_INFO
    strProfileName  dw WLAN_MAX_NAME_LENGTH dup(?)
    dwFlags         dd ?
ends

struct WLAN_INTERFACE_INFO
    InterfaceGuid               GUID  
    strInterfaceDescription     dw     256 dup(?)
    isState                     xptr   ?
                                db 2 dup(?)    ;Padding for WIN64
ends

struct WLAN_INTERFACE_INFO_LIST
    dwNumberOfItems             dd   ?
    dwIndex                     dd   ?
    InterfaceInfo               WLAN_INTERFACE_INFO
ends

struct WLAN_ASSOCIATION_ATTRIBUTES
    dot11Ssid           DOT11_SSID
    dot11BssType        dd   ?
    dot11Bssid          DOT11_MAC_ADDRESS
    dot11PhyType        dd   ?
    uDot11PhyIndex      dd   ?
    wlanSignalQuality   xptr ?
    ulRxRate            dd   ?
    ulTxRate            dd   ?
ends

struct WLAN_SECURITY_ATTRIBUTES
    bSecurityEnabled        dd ?
    bOneXEnabled            dd ?
    dot11AuthAlgorithm      dd ?
    dot11CipherAlgorithm    dd ?
ends

struct WLAN_AVAILABLE_NETWORK
    strProfileName              dw WLAN_MAX_NAME_LENGTH dup(?)
    dot11Ssid                   DOT11_SSID
    dot11BssType                dd ?
    uNumberOfBssids             dd ?
    bNetworkConnectable         dd ?
    wlanNotConnectableReason    dd ?
    uNumberOfPhyTypes           dd ?
    dot11PhyTypes               dd WLAN_MAX_PHY_TYPE_NUMBER dup(?)
    bMorePhyTypes               dd ?
    wlanSignalQuality           dd ?
    bSecurityEnabled            dd ?
    dot11DefaultAuthAlgorithm   dd ?
    dot11DefaultCipherAlgorithm dd ?
    dwFlags                     dd ?
    dwReserved                  dd ?
ends

struct WLAN_AVAILABLE_NETWORK_V2
    strProfileName              dw WLAN_MAX_NAME_LENGTH dup(?)
    dot11Ssid                   DOT11_SSID
    dot11BssType                dd ?
    uNumberOfBssids             dd ?
    bNetworkConnectable         dd ?
    wlanNotConnectableReason    dd ?
    uNumberOfPhyTypes           dd ?
    dot11PhyTypes               dd WLAN_MAX_PHY_TYPE_NUMBER dup(?)
    bMorePhyTypes               dd ?
    wlanSignalQuality           dd ?
    bSecurityEnabled            dd ?
    dot11DefaultAuthAlgorithm   dd ?
    dot11DefaultCipherAlgorithm dd ?
    dwFlags                     dd ?
    AccessNetworkOptions        DOT11_ACCESSNETWORKOPTIONS
    dot11HESSID                 xptr ?
    VenueInfo                   DOT11_VENUEINFO
    dwReserved                  dd ?
ends

struct WLAN_AVAILABLE_NETWORK_LIST
    dwNumberOfItems dd   ?
    dwIndex         dd   ?
    Network         WLAN_AVAILABLE_NETWORK 1 dup(?)
ends

struct WLAN_RAW_DATA
    dwDataSize  dd ?
    DataBlob    db 1 dup(?)
                db 3 dup(?)    ;Padding for WIN64
ends

struct WLAN_RATE_SET
    uRateSetLength  dd ?
    usRateSet       dw DOT11_RATE_SET_MAX_LENGTH dup(?)
ends
    
struct WLAN_BSS_ENTRY
    dot11Ssid                   DOT11_SSID 
    uPhyId                      dd ?
    dot11Bssid                  DOT11_MAC_ADDRESS
    dot11BssType                dd ?
    dot11BssPhyType             dd ?
    lRssi                       dd ?
    uLinkQuality                dd ?
    bInRegDomain                dw ?
    usBeaconPeriod              dw ?
                                db 4 dup(?)    ;Padding for WIN64
    ullTimestamp                dq ?
    ullHostTimestamp            dq ?
    usCapabilityInformation     dw ?
                                dw ?           ;Padding for WIN64
    ulChCenterFrequency         dd ?
    wlanRateSet                 WLAN_RATE_SET
    ulIeOffset                  dd ?
    ulIeSize                    dd ?
ends

struct WLAN_BSS_LIST
     dwTotalSize                dd   ?
     dwNumberOfItems            dd   ?
     wlanBssEntries             WLAN_BSS_ENTRY 1 dup(?)
ends

struct WLAN_CONNECTION_ATTRIBUTES
    isState                     dd ?
    wlanConnectionMode          dd ?
    strProfileName              dw WLAN_MAX_NAME_LENGTH dup(?)
    wlanAssociationAttributes   WLAN_ASSOCIATION_ATTRIBUTES
    wlanSecurityAttributes      WLAN_SECURITY_ATTRIBUTES
ends

struct WLAN_PHY_RADIO_STATE
    dwPhyIndex              dd ?
    dot11SoftwareRadioState dd ?
    dot11HardwareRadioState dd ?
                            dd ?    ;Padding for WIN64
ends

struct WLAN_RADIO_STATE
    dwNumberOfPhys  dd ?
    PhyRadioState   WLAN_PHY_RADIO_STATE 1 dup(?)
    repeat (WLAN_MAX_PHY_INDEX-1)
        WLAN_PHY_RADIO_STATE
    end repeat
ends

struct WLAN_MSM_NOTIFICATION_DATA
    wlanConnectionMode  dd ?
    strProfileName      dw WLAN_MAX_NAME_LENGTH dup(?)
    dot11Ssid           DOT11_SSID
    dot11BssType        dd ?
    dot11MacAddr        DOT11_MAC_ADDRESS
    bSecurityEnabled    dd ?
    bFirstPeer          dd ?
    bLastPeer           dd ?
    wlanReasonCode      dd ?
ends

struct WLAN_CONNECTION_NOTIFICATION_DATA
    wlanConnectionMode      dd ?
    strProfileName          dw WLAN_MAX_NAME_LENGTH dup(?)
    dot11Ssid               DOT11_SSID
    dot11BssType            dd ?
    bSecurityEnabled        dd ?
    wlanReasonCode          dd ?
    dwFlags                 dd ?
    strProfileXml           dw 1 dup(?)
                            db 2 dup(?)    ;Padding for WIN64
ends

struct WLAN_NOTIFICATION_DATA
    NotificationSource     dd   ?
    NotificationCode       dd   ?
    InterfaceGuid          GUID
    dwDataSize             dd   ?
    pData                  xptr ?
ends

struct DATALIST
    dwDataOffset           dd ?
    dwDataSize             dd ?
ends

struct WLAN_RAW_DATA_LIST
    dwTotalSize             dd ?
    dwNumberOfItems         dd ?
    __unnamed_struct_17d8_1 DATALIST
ends

;======================================== Functions =======================================;

import wlanapi,\
    QueryNetconStatus,'QueryNetconStatus',\
    QueryNetconVirtualCharacteristic,'QueryNetconVirtualCharacteristic',\
    WFDAbortSessionInt,'WFDAbortSessionInt',\
    WFDAcceptConnectRequestAndOpenSessionInt,'WFDAcceptConnectRequestAndOpenSessionInt',\
    WFDAcceptGroupRequestAndOpenSessionInt,'WFDAcceptGroupRequestAndOpenSessionInt',\
    WFDCancelConnectorPairWithOOB,'WFDCancelConnectorPairWithOOB',\
    WFDCancelListenerPairWithOOB,'WFDCancelListenerPairWithOOB',\
    WFDCancelOpenSession,'WFDCancelOpenSession',\
    WFDCancelOpenSessionInt,'WFDCancelOpenSessionInt',\
    WFDCloseHandle,'WFDCloseHandle',\
    WFDCloseHandleInt,'WFDCloseHandleInt',\
    WFDCloseLegacySessionInt,'WFDCloseLegacySessionInt',\
    WFDCloseOOBPairingSession,'WFDCloseOOBPairingSession',\
    WFDCloseSession,'WFDCloseSession',\
    WFDCloseSessionInt,'WFDCloseSessionInt',\
    WFDConfigureFirewallForSessionInt,'WFDConfigureFirewallForSessionInt',\
    WFDCreateDHPrivatePublicKeyPairInt,'WFDCreateDHPrivatePublicKeyPairInt',\
    WFDDeclineConnectRequestInt,'WFDDeclineConnectRequestInt',\
    WFDDeclineGroupRequestInt,'WFDDeclineGroupRequestInt',\
    WFDDiscoverDevicesInt,'WFDDiscoverDevicesInt',\
    WFDFlushVisibleDeviceListInt,'WFDFlushVisibleDeviceListInt',\
    WFDForceDisconnectInt,'WFDForceDisconnectInt',\
    WFDForceDisconnectLegacyPeerInt,'WFDForceDisconnectLegacyPeerInt',\
    WFDFreeMemoryInt,'WFDFreeMemoryInt',\
    WFDGetDefaultGroupProfileInt,'WFDGetDefaultGroupProfileInt',\
    WFDGetDeviceDescriptorForPendingRequestInt,'WFDGetDeviceDescriptorForPendingRequestInt',\
    WFDGetNFCCarrierConfigBlobInt,'WFDGetNFCCarrierConfigBlobInt',\
    WFDGetOOBBlob,'WFDGetOOBBlob',\
    WFDGetProfileKeyInfoInt,'WFDGetProfileKeyInfoInt',\
    WFDGetSessionEndpointPairsInt,'WFDGetSessionEndpointPairsInt',\
    WFDGetVisibleDevicesInt,'WFDGetVisibleDevicesInt',\
    WFDIsInterfaceWiFiDirect,'WFDIsInterfaceWiFiDirect',\
    WFDIsWiFiDirectRunningOnWiFiAdapter,'WFDIsWiFiDirectRunningOnWiFiAdapter',\
    WFDLowPrivCancelOpenSessionInt,'WFDLowPrivCancelOpenSessionInt',\
    WFDLowPrivCloseHandleInt,'WFDLowPrivCloseHandleInt',\
    WFDLowPrivCloseLegacySessionInt,'WFDLowPrivCloseLegacySessionInt',\
    WFDLowPrivCloseSessionInt,'WFDLowPrivCloseSessionInt',\
    WFDLowPrivConfigureFirewallForSessionInt,'WFDLowPrivConfigureFirewallForSessionInt',\
    WFDLowPrivDeclineDeviceApiConnectionRequestInt,'WFDLowPrivDeclineDeviceApiConnectionRequestInt',\
    WFDLowPrivGetPendingGroupRequestDetailsInt,'WFDLowPrivGetPendingGroupRequestDetailsInt',\
    WFDLowPrivGetSessionEndpointPairsInt,'WFDLowPrivGetSessionEndpointPairsInt',\
    WFDLowPrivIsWfdSupportedInt,'WFDLowPrivIsWfdSupportedInt',\
    WFDLowPrivOpenHandleInt,'WFDLowPrivOpenHandleInt',\
    WFDLowPrivOpenLegacySessionInt,'WFDLowPrivOpenLegacySessionInt',\
    WFDLowPrivOpenSessionByDafObjectIdInt,'WFDLowPrivOpenSessionByDafObjectIdInt',\
    WFDLowPrivQueryPropertyInt,'WFDLowPrivQueryPropertyInt',\
    WFDLowPrivRegisterNotificationInt,'WFDLowPrivRegisterNotificationInt',\
    WFDLowPrivRegisterVMgrCallerInt,'WFDLowPrivRegisterVMgrCallerInt',\
    WFDLowPrivSetPropertyInt,'WFDLowPrivSetPropertyInt',\
    WFDLowPrivStartDeviceApiConnectionRequestListenerInt,'WFDLowPrivStartDeviceApiConnectionRequestListenerInt',\
    WFDLowPrivStartOpenSessionByInterfaceIdInt,'WFDLowPrivStartOpenSessionByInterfaceIdInt',\
    WFDLowPrivStartUsingGroupInt,'WFDLowPrivStartUsingGroupInt',\
    WFDLowPrivStopDeviceApiConnectionRequestListenerInt,'WFDLowPrivStopDeviceApiConnectionRequestListenerInt',\
    WFDLowPrivStopUsingGroupInt,'WFDLowPrivStopUsingGroupInt',\
    WFDLowPrivUnregisterVMgrCallerInt,'WFDLowPrivUnregisterVMgrCallerInt',\
    WFDOpenHandle,'WFDOpenHandle',\
    WFDOpenHandleInt,'WFDOpenHandleInt',\
    WFDOpenLegacySession,'WFDOpenLegacySession',\
    WFDOpenLegacySessionInt,'WFDOpenLegacySessionInt',\
    WFDPairCancelByDeviceAddressInt,'WFDPairCancelByDeviceAddressInt',\
    WFDPairCancelInt,'WFDPairCancelInt',\
    WFDPairContinuePairWithDeviceInt,'WFDPairContinuePairWithDeviceInt',\
    WFDPairEnumerateCeremoniesInt,'WFDPairEnumerateCeremoniesInt',\
    WFDPairSelectCeremonyInt,'WFDPairSelectCeremonyInt',\
    WFDPairWithDeviceAndOpenSessionExInt,'WFDPairWithDeviceAndOpenSessionExInt',\
    WFDPairWithDeviceAndOpenSessionInt,'WFDPairWithDeviceAndOpenSessionInt',\
    WFDParseOOBBlob,'WFDParseOOBBlob',\
    WFDParseOOBBlobTypeAndGetPayloadInt,'WFDParseOOBBlobTypeAndGetPayloadInt',\
    WFDParseProfileXmlInt,'WFDParseProfileXmlInt',\
    WFDParseWfaNfcCarrierConfigBlobInt,'WFDParseWfaNfcCarrierConfigBlobInt',\
    WFDQueryPropertyInt,'WFDQueryPropertyInt',\
    WFDRegisterNotificationInt,'WFDRegisterNotificationInt',\
    WFDRegisterVMgrCallerInt,'WFDRegisterVMgrCallerInt',\
    WFDSetAdditionalIEsInt,'WFDSetAdditionalIEsInt',\
    WFDSetPropertyInt,'WFDSetPropertyInt',\
    WFDSetSecondaryDeviceTypeListInt,'WFDSetSecondaryDeviceTypeListInt',\
    WFDStartBackgroundDiscoveryInt,'WFDStartBackgroundDiscoveryInt',\
    WFDStartConnectorPairWithOOB,'WFDStartConnectorPairWithOOB',\
    WFDStartListenerPairWithOOB,'WFDStartListenerPairWithOOB',\
    WFDStartOffloadedDiscoveryInt,'WFDStartOffloadedDiscoveryInt',\
    WFDStartOpenSession,'WFDStartOpenSession',\
    WFDStartOpenSessionInt,'WFDStartOpenSessionInt',\
    WFDStartUsingGroupExInt,'WFDStartUsingGroupExInt',\
    WFDStartUsingGroupInt,'WFDStartUsingGroupInt',\
    WFDStopBackgroundDiscoveryInt,'WFDStopBackgroundDiscoveryInt',\
    WFDStopDiscoverDevicesInt,'WFDStopDiscoverDevicesInt',\
    WFDStopOffloadedDiscoveryInt,'WFDStopOffloadedDiscoveryInt',\
    WFDStopUsingGroupInt,'WFDStopUsingGroupInt',\
    WFDSvcLowPrivAcceptSessionInt,'WFDSvcLowPrivAcceptSessionInt',\
    WFDSvcLowPrivCancelSessionInt,'WFDSvcLowPrivCancelSessionInt',\
    WFDSvcLowPrivCloseSessionInt,'WFDSvcLowPrivCloseSessionInt',\
    WFDSvcLowPrivConfigureSessionInt,'WFDSvcLowPrivConfigureSessionInt',\
    WFDSvcLowPrivConnectSessionInt,'WFDSvcLowPrivConnectSessionInt',\
    WFDSvcLowPrivGetProvisioningInfoInt,'WFDSvcLowPrivGetProvisioningInfoInt',\
    WFDSvcLowPrivGetSessionEndpointPairsInt,'WFDSvcLowPrivGetSessionEndpointPairsInt',\
    WFDSvcLowPrivOpenAdvertiserSessionInt,'WFDSvcLowPrivOpenAdvertiserSessionInt',\
    WFDSvcLowPrivOpenSeekerSessionInt,'WFDSvcLowPrivOpenSeekerSessionInt',\
    WFDSvcLowPrivPublishServiceInt,'WFDSvcLowPrivPublishServiceInt',\
    WFDSvcLowPrivUnpublishServiceInt,'WFDSvcLowPrivUnpublishServiceInt',\
    WFDUnregisterVMgrCallerInt,'WFDUnregisterVMgrCallerInt',\
    WFDUpdateDeviceVisibility,'WFDUpdateDeviceVisibility',\
    WlanAllocateMemory,'WlanAllocateMemory',\
    WlanCancelPlap,'WlanCancelPlap',\
    WlanCloseHandle,'WlanCloseHandle',\
    WlanConnect,'WlanConnect',\
    WlanConnectEx,'WlanConnectEx',\
    WlanConnectWithInput,'WlanConnectWithInput',\
    WlanDeinitPlapParams,'WlanDeinitPlapParams',\
    WlanDeleteProfile,'WlanDeleteProfile',\
    WlanDisconnect,'WlanDisconnect',\
    WlanDoesBssMatchSecurity,'WlanDoesBssMatchSecurity',\
    WlanDoPlap,'WlanDoPlap',\
    WlanEnumAllInterfaces,'WlanEnumAllInterfaces',\
    WlanEnumInterfaces,'WlanEnumInterfaces',\
    WlanExtractPsdIEDataList,'WlanExtractPsdIEDataList',\
    WlanFreeMemory,'WlanFreeMemory',\
    WlanGenerateProfileXmlBasicSettings,'WlanGenerateProfileXmlBasicSettings',\
    WlanGetAvailableNetworkList,'WlanGetAvailableNetworkList',\
    WlanGetAvailableNetworkList2,'WlanGetAvailableNetworkList2',\
    WlanGetFilterList,'WlanGetFilterList',\
    WlanGetInterfaceCapability,'WlanGetInterfaceCapability',\
    WlanGetMFPNegotiated,'WlanGetMFPNegotiated',\
    WlanGetNetworkBssList,'WlanGetNetworkBssList',\
    WlanGetProfile,'WlanGetProfile',\
    WlanGetProfileCustomUserData,'WlanGetProfileCustomUserData',\
    WlanGetProfileEapUserDataInfo,'WlanGetProfileEapUserDataInfo',\
    WlanGetProfileIndex,'WlanGetProfileIndex',\
    WlanGetProfileKeyInfo,'WlanGetProfileKeyInfo',\
    WlanGetProfileList,'WlanGetProfileList',\
    WlanGetSecuritySettings,'WlanGetSecuritySettings',\
    WlanGetStoredRadioState,'WlanGetStoredRadioState',\
    WlanHostedNetworkForceStart,'WlanHostedNetworkForceStart',\
    WlanHostedNetworkForceStop,'WlanHostedNetworkForceStop',\
    WlanHostedNetworkFreeWCNSettings,'WlanHostedNetworkFreeWCNSettings',\
    WlanHostedNetworkHlpQueryEverUsed,'WlanHostedNetworkHlpQueryEverUsed',\
    WlanHostedNetworkInitSettings,'WlanHostedNetworkInitSettings',\
    WlanHostedNetworkQueryProperty,'WlanHostedNetworkQueryProperty',\
    WlanHostedNetworkQuerySecondaryKey,'WlanHostedNetworkQuerySecondaryKey',\
    WlanHostedNetworkQueryStatus,'WlanHostedNetworkQueryStatus',\
    WlanHostedNetworkQueryWCNSettings,'WlanHostedNetworkQueryWCNSettings',\
    WlanHostedNetworkRefreshSecuritySettings,'WlanHostedNetworkRefreshSecuritySettings',\
    WlanHostedNetworkSetProperty,'WlanHostedNetworkSetProperty',\
    WlanHostedNetworkSetSecondaryKey,'WlanHostedNetworkSetSecondaryKey',\
    WlanHostedNetworkSetWCNSettings,'WlanHostedNetworkSetWCNSettings',\
    WlanHostedNetworkStartUsing,'WlanHostedNetworkStartUsing',\
    WlanHostedNetworkStopUsing,'WlanHostedNetworkStopUsing',\
    WlanIhvControl,'WlanIhvControl',\
    WlanInitPlapParams,'WlanInitPlapParams',\
    WlanInternalScan,'WlanInternalScan',\
    WlanIsActiveConsoleUser,'WlanIsActiveConsoleUser',\
    WlanIsNetworkSuppressed,'WlanIsNetworkSuppressed',\
    WlanIsUIRequestPending,'WlanIsUIRequestPending',\
    WlanLowPrivCloseHandle,'WlanLowPrivCloseHandle',\
    WlanLowPrivEnumInterfaces,'WlanLowPrivEnumInterfaces',\
    WlanLowPrivFreeMemory,'WlanLowPrivFreeMemory',\
    WlanLowPrivNotifyVsIeProviderInt,'WlanLowPrivNotifyVsIeProviderInt',\
    WlanLowPrivOpenHandle,'WlanLowPrivOpenHandle',\
    WlanLowPrivQueryInterface,'WlanLowPrivQueryInterface',\
    WlanLowPrivSetInterface,'WlanLowPrivSetInterface',\
    WlanNotifyVsIeProviderExInt,'WlanNotifyVsIeProviderExInt',\
    WlanNotifyVsIeProviderInt,'WlanNotifyVsIeProviderInt',\
    WlanOpenHandle,'WlanOpenHandle',\
    WlanParseProfileXmlBasicSettings,'WlanParseProfileXmlBasicSettings',\
    WlanPrivateClearAnqpCache,'WlanPrivateClearAnqpCache',\
    WlanPrivateGetAnqpCacheResponse,'WlanPrivateGetAnqpCacheResponse',\
    WlanPrivateGetAvailableNetworkList,'WlanPrivateGetAvailableNetworkList',\
    WlanPrivateParseAnqpRawData,'WlanPrivateParseAnqpRawData',\
    WlanPrivateQueryInterface,'WlanPrivateQueryInterface',\
    WlanPrivateRefreshAnqpCache,'WlanPrivateRefreshAnqpCache',\
    WlanPrivateSetInterface,'WlanPrivateSetInterface',\
    WlanQueryAutoConfigParameter,'WlanQueryAutoConfigParameter',\
    WlanQueryCreateAllUserProfileRestricted,'WlanQueryCreateAllUserProfileRestricted',\
    WlanQueryInterface,'WlanQueryInterface',\
    WlanQueryPlapCredentials,'WlanQueryPlapCredentials',\
    WlanQueryPreConnectInput,'WlanQueryPreConnectInput',\
    WlanQueryVirtualInterfaceType,'WlanQueryVirtualInterfaceType',\
    WlanReasonCodeToString,'WlanReasonCodeToString',\
    WlanRefreshConnections,'WlanRefreshConnections',\
    WlanRegisterNotification,'WlanRegisterNotification',\
    WlanRegisterVirtualStationNotification,'WlanRegisterVirtualStationNotification',\
    WlanRemoveUIForwardingNetworkList,'WlanRemoveUIForwardingNetworkList',\
    WlanRenameProfile,'WlanRenameProfile',\
    WlanSaveTemporaryProfile,'WlanSaveTemporaryProfile',\
    WlanScan,'WlanScan',\
    WlanSendUIResponse,'WlanSendUIResponse',\
    WlanSetAllUserProfileRestricted,'WlanSetAllUserProfileRestricted',\
    WlanSetAutoConfigParameter,'WlanSetAutoConfigParameter',\
    WlanSetFilterList,'WlanSetFilterList',\
    WlanSetInterface,'WlanSetInterface',\
    WlanSetProfile,'WlanSetProfile',\
    WlanSetProfileCustomUserData,'WlanSetProfileCustomUserData',\
    WlanSetProfileEapUserData,'WlanSetProfileEapUserData',\
    WlanSetProfileEapXmlUserData,'WlanSetProfileEapXmlUserData',\
    WlanSetProfileList,'WlanSetProfileList',\
    WlanSetProfileListForOffload,'WlanSetProfileListForOffload',\
    WlanSetProfileMetadata,'WlanSetProfileMetadata',\
    WlanSetProfilePosition,'WlanSetProfilePosition',\
    WlanSetPsdIEDataList,'WlanSetPsdIEDataList',\
    WlanSetSecuritySettings,'WlanSetSecuritySettings',\
    WlanSetUIForwardingNetworkList,'WlanSetUIForwardingNetworkList',\
    WlanSignalValueToBar,'WlanSignalValueToBar',\
    WlanSsidToDisplayName,'WlanSsidToDisplayName',\
    WlanStartAP,'WlanStartAP',\
    WlanStopAP,'WlanStopAP',\
    WlanStoreRadioStateOnEnteringAirPlaneMode,'WlanStoreRadioStateOnEnteringAirPlaneMode',\
    WlanStringToSsid,'WlanStringToSsid',\
    WlanStringToUtf8Ssid,'WlanStringToUtf8Ssid',\
    WlanTryUpgradeCurrentConnectionAuthCipher,'WlanTryUpgradeCurrentConnectionAuthCipher',\
    WlanUpdateBasicProfileSecurity,'WlanUpdateBasicProfileSecurity',\
    WlanUpdateProfileWithAuthCipher,'WlanUpdateProfileWithAuthCipher',\
    WlanUtf8SsidToDisplayName,'WlanUtf8SsidToDisplayName',\
    WlanVMgrQueryCurrentScenariosInt,'WlanVMgrQueryCurrentScenariosInt',\
    WlanWcmDisconnect,'WlanWcmDisconnect',\
    WlanWcmGetInterface,'WlanWcmGetInterface',\
    WlanWcmGetProfileList,'WlanWcmGetProfileList',\
    WlanWcmSetInterface,'WlanWcmSetInterface',\
    WlanWcmSetProfile,'WlanWcmSetProfile',\
    WlanWfdGetPeerInfo,'WlanWfdGetPeerInfo',\
    WlanWfdGOSetWCNSettings,'WlanWfdGOSetWCNSettings',\
    WlanWfdStartGO,'WlanWfdStartGO',\
    WlanWfdStopGO,'WlanWfdStopGO'

end if ;WLANAPI_INC
