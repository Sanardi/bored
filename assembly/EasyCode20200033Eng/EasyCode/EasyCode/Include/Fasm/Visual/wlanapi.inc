; ====================================================;
;                                                     ;
;     wlanapi.inc for EC v2 Fasm visual projects      ;
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

if defined APP_WIN64
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_WlanAllocateMemory' as WlanAllocateMemory:qword
        extrn '__imp_WlanCloseHandle' as WlanCloseHandle:qword
        extrn '__imp_WlanConnect' as WlanConnect:qword
        extrn '__imp_WlanDeleteProfile' as WlanDeleteProfile:qword
        extrn '__imp_WlanDisconnect' as WlanDisconnect:qword
        extrn '__imp_WlanEnumInterfaces' as WlanEnumInterfaces:qword
        extrn '__imp_WlanExtractPsdIEDataList' as WlanExtractPsdIEDataList:qword
        extrn '__imp_WlanFreeMemory' as WlanFreeMemory:qword
        extrn '__imp_WlanGetAvailableNetworkList' as WlanGetAvailableNetworkList:qword
        extrn '__imp_WlanGetFilterList' as WlanGetFilterList:qword
        extrn '__imp_WlanGetInterfaceCapability' as WlanGetInterfaceCapability:qword
        extrn '__imp_WlanGetNetworkBssList' as WlanGetNetworkBssList:qword
        extrn '__imp_WlanGetProfile' as WlanGetProfile:qword
        extrn '__imp_WlanGetProfileCustomUserData' as WlanGetProfileCustomUserData:qword
        extrn '__imp_WlanGetProfileList' as WlanGetProfileList:qword
        extrn '__imp_WlanGetSecuritySettings' as WlanGetSecuritySettings:qword
        extrn '__imp_WlanIhvControl' as WlanIhvControl:qword
        extrn '__imp_WlanQueryAutoConfigParameter' as WlanQueryAutoConfigParameter:qword
        extrn '__imp_WlanOpenHandle' as WlanOpenHandle:qword
        extrn '__imp_WlanQueryInterface' as WlanQueryInterface:qword
        extrn '__imp_WlanReasonCodeToString' as WlanReasonCodeToString:qword
        extrn '__imp_WlanRegisterNotification' as WlanRegisterNotification:qword
        extrn '__imp_WlanRenameProfile' as WlanRenameProfile:qword
        extrn '__imp_WlanSaveTemporaryProfile' as WlanSaveTemporaryProfile:qword
        extrn '__imp_WlanScan' as WlanScan:qword
        extrn '__imp_WlanSetAutoConfigParameter' as WlanSetAutoConfigParameter:qword
        extrn '__imp_WlanSetFilterList' as WlanSetFilterList:qword
        extrn '__imp_WlanSetInterface' as WlanSetInterface:qword
        extrn '__imp_WlanSetProfile' as WlanSetProfile:qword
        extrn '__imp_WlanSetProfileCustomUserData' as WlanSetProfileCustomUserData:qword
        extrn '__imp_WlanSetProfileEapUserData' as WlanSetProfileEapUserData:qword
        extrn '__imp_WlanSetProfileEapXmlUserData' as WlanSetProfileEapXmlUserData:qword
        extrn '__imp_WlanSetProfileList' as WlanSetProfileList:qword
        extrn '__imp_WlanSetProfilePosition' as WlanSetProfilePosition:qword
        extrn '__imp_WlanSetPsdIEDataList' as WlanSetPsdIEDataList:qword
        extrn '__imp_WlanSetSecuritySettings' as WlanSetSecuritySettings:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_WlanHostedNetworkForceStart' as WlanHostedNetworkForceStart:qword
        extrn '__imp_WlanHostedNetworkForceStop' as WlanHostedNetworkForceStop:qword
        extrn '__imp_WlanHostedNetworkInitSettings' as WlanHostedNetworkInitSettings:qword
        extrn '__imp_WlanHostedNetworkQueryProperty' as WlanHostedNetworkQueryProperty:qword
        extrn '__imp_WlanHostedNetworkQuerySecondaryKey' as WlanHostedNetworkQuerySecondaryKey:qword
        extrn '__imp_WlanHostedNetworkQueryStatus' as WlanHostedNetworkQueryStatus:qword
        extrn '__imp_WlanHostedNetworkRefreshSecuritySettings' as WlanHostedNetworkRefreshSecuritySettings:qword
        extrn '__imp_WlanHostedNetworkSetProperty' as WlanHostedNetworkSetProperty:qword
        extrn '__imp_WlanHostedNetworkSetSecondaryKey' as WlanHostedNetworkSetSecondaryKey:qword
        extrn '__imp_WlanHostedNetworkStartUsing' as WlanHostedNetworkStartUsing:qword
        extrn '__imp_WlanHostedNetworkStopUsing' as WlanHostedNetworkStopUsing:qword
        extrn '__imp_WlanRegisterVirtualStationNotification' as WlanRegisterVirtualStationNotification:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_WFDCancelOpenSession' as WFDCancelOpenSession:qword
        extrn '__imp_WFDCloseHandle' as WFDCloseHandle:qword
        extrn '__imp_WFDCloseSession' as WFDCloseSession:qword
        extrn '__imp_WFDOpenHandle' as WFDOpenHandle:qword
        extrn '__imp_WFDOpenLegacySession' as WFDOpenLegacySession:qword
        extrn '__imp_WFDStartOpenSession' as WFDStartOpenSession:qword
        extrn '__imp_WFDUpdateDeviceVisibility' as WFDUpdateDeviceVisibility:qword
    end if
else
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__WlanAllocateMemory@4' as WlanAllocateMemory:dword
        extrn '__imp__WlanCloseHandle@8' as WlanCloseHandle:dword
        extrn '__imp__WlanConnect@16' as WlanConnect:dword
        extrn '__imp__WlanDeleteProfile@16' as WlanDeleteProfile:dword
        extrn '__imp__WlanDisconnect@12' as WlanDisconnect:dword
        extrn '__imp__WlanEnumInterfaces@12' as WlanEnumInterfaces:dword
        extrn '__imp__WlanExtractPsdIEDataList@24' as WlanExtractPsdIEDataList:dword
        extrn '__imp__WlanFreeMemory@4' as WlanFreeMemory:dword
        extrn '__imp__WlanGetAvailableNetworkList@20' as WlanGetAvailableNetworkList:dword
        extrn '__imp__WlanGetFilterList@16' as WlanGetFilterList:dword
        extrn '__imp__WlanGetInterfaceCapability@16' as WlanGetInterfaceCapability:dword
        extrn '__imp__WlanGetNetworkBssList@28' as WlanGetNetworkBssList:dword
        extrn '__imp__WlanGetProfile@28' as WlanGetProfile:dword
        extrn '__imp__WlanGetProfileCustomUserData@24' as WlanGetProfileCustomUserData:dword
        extrn '__imp__WlanGetProfileList@16' as WlanGetProfileList:dword
        extrn '__imp__WlanGetSecuritySettings@20' as WlanGetSecuritySettings:dword
        extrn '__imp__WlanIhvControl@32' as WlanIhvControl:dword
        extrn '__imp__WlanOpenHandle@16' as WlanOpenHandle:dword
        extrn '__imp__WlanQueryAutoConfigParameter@24' as WlanQueryAutoConfigParameter:dword
        extrn '__imp__WlanQueryInterface@28' as WlanQueryInterface:dword
        extrn '__imp__WlanReasonCodeToString@16' as WlanReasonCodeToString:dword
        extrn '__imp__WlanRegisterNotification@28' as WlanRegisterNotification:dword
        extrn '__imp__WlanRenameProfile@20' as WlanRenameProfile:dword
        extrn '__imp__WlanSaveTemporaryProfile@28' as WlanSaveTemporaryProfile:dword
        extrn '__imp__WlanScan@20' as WlanScan:dword
        extrn '__imp__WlanSetAutoConfigParameter@20' as WlanSetAutoConfigParameter:dword
        extrn '__imp__WlanSetFilterList@16' as WlanSetFilterList:dword
        extrn '__imp__WlanSetInterface@24' as WlanSetInterface:dword
        extrn '__imp__WlanSetProfile@32' as WlanSetProfile:dword
        extrn '__imp__WlanSetProfileCustomUserData@24' as WlanSetProfileCustomUserData:dword
        extrn '__imp__WlanSetProfileEapUserData@32' as WlanSetProfileEapUserData:dword
        extrn '__imp__WlanSetProfileEapXmlUserData@24' as WlanSetProfileEapXmlUserData:dword
        extrn '__imp__WlanSetProfileList@20' as WlanSetProfileList:dword
        extrn '__imp__WlanSetProfilePosition@20' as WlanSetProfilePosition:dword
        extrn '__imp__WlanSetPsdIEDataList@16' as WlanSetPsdIEDataList:dword
        extrn '__imp__WlanSetSecuritySettings@12' as WlanSetSecuritySettings:dword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp__WlanHostedNetworkForceStart@12' as WlanHostedNetworkForceStart:dword
        extrn '__imp__WlanHostedNetworkForceStop@12' as WlanHostedNetworkForceStop:dword
        extrn '__imp__WlanHostedNetworkInitSettings@12' as WlanHostedNetworkInitSettings:dword
        extrn '__imp__WlanHostedNetworkQueryProperty@24' as WlanHostedNetworkQueryProperty:dword
        extrn '__imp__WlanHostedNetworkQuerySecondaryKey@28' as WlanHostedNetworkQuerySecondaryKey:dword
        extrn '__imp__WlanHostedNetworkQueryStatus@12' as WlanHostedNetworkQueryStatus:dword
        extrn '__imp__WlanHostedNetworkRefreshSecuritySettings@12' as WlanHostedNetworkRefreshSecuritySettings:dword
        extrn '__imp__WlanHostedNetworkSetProperty@24' as WlanHostedNetworkSetProperty:dword
        extrn '__imp__WlanHostedNetworkSetSecondaryKey@28' as WlanHostedNetworkSetSecondaryKey:dword
        extrn '__imp__WlanHostedNetworkStartUsing@12' as WlanHostedNetworkStartUsing:dword
        extrn '__imp__WlanHostedNetworkStopUsing@12' as WlanHostedNetworkStopUsing:dword
        extrn '__imp__WlanRegisterVirtualStationNotification@12' as WlanRegisterVirtualStationNotification:dword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__WFDCancelOpenSession@4' as WFDCancelOpenSession:dword
        extrn '__imp__WFDCloseHandle@4' as WFDCloseHandle:dword
        extrn '__imp__WFDCloseSession@4' as WFDCloseSession:dword
        extrn '__imp__WFDOpenHandle@12' as WFDOpenHandle:dword
        extrn '__imp__WFDOpenLegacySession@16' as WFDOpenLegacySession:dword
        extrn '__imp__WFDStartOpenSession@20' as WFDStartOpenSession:dword
        extrn '__imp__WFDUpdateDeviceVisibility@4' as WFDUpdateDeviceVisibility:dword
    end if
end if

;======================= Undocumented functions (unknown arguments) =======================;
if defined APP_WIN64
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_QueryNetconStatus' as QueryNetconStatus:qword
        extrn '__imp_QueryNetconVirtualCharacteristic' as QueryNetconVirtualCharacteristic:qword
        extrn '__imp_WFDAcceptConnectRequestAndOpenSessionInt' as WFDAcceptConnectRequestAndOpenSessionInt:qword
        extrn '__imp_WFDAcceptGroupRequestAndOpenSessionInt' as WFDAcceptGroupRequestAndOpenSessionInt:qword
        extrn '__imp_WFDCancelConnectorPairWithOOB' as WFDCancelConnectorPairWithOOB:qword
        extrn '__imp_WFDCancelListenerPairWithOOB' as WFDCancelListenerPairWithOOB:qword
        extrn '__imp_WFDCancelOpenSessionInt' as WFDCancelOpenSessionInt:qword
        extrn '__imp_WFDCloseHandleInt' as WFDCloseHandleInt:qword
        extrn '__imp_WFDCloseLegacySessionInt' as WFDCloseLegacySessionInt:qword
        extrn '__imp_WFDCloseOOBPairingSession' as WFDCloseOOBPairingSession:qword
        extrn '__imp_WFDCloseSessionInt' as WFDCloseSessionInt:qword
        extrn '__imp_WFDDeclineConnectRequestInt' as WFDDeclineConnectRequestInt:qword
        extrn '__imp_WFDDeclineGroupRequestInt' as WFDDeclineGroupRequestInt:qword
        extrn '__imp_WFDDiscoverDevicesInt' as WFDDiscoverDevicesInt:qword
        extrn '__imp_WFDFlushVisibleDeviceListInt' as WFDFlushVisibleDeviceListInt:qword
        extrn '__imp_WFDForceDisconnectInt' as WFDForceDisconnectInt:qword
        extrn '__imp_WFDFreeMemoryInt' as WFDFreeMemoryInt:qword
        extrn '__imp_WFDGetDefaultGroupProfileInt' as WFDGetDefaultGroupProfileInt:qword
        extrn '__imp_WFDGetOOBBlob' as WFDGetOOBBlob:qword
        extrn '__imp_WFDGetProfileKeyInfoInt' as WFDGetProfileKeyInfoInt:qword
        extrn '__imp_WFDGetVisibleDevicesInt' as WFDGetVisibleDevicesInt:qword
        extrn '__imp_WFDIsInterfaceWiFiDirect' as WFDIsInterfaceWiFiDirect:qword
        extrn '__imp_WFDIsWiFiDirectRunningOnWiFiAdapter' as WFDIsWiFiDirectRunningOnWiFiAdapter:qword
        extrn '__imp_WFDOpenHandleInt' as WFDOpenHandleInt:qword
        extrn '__imp_WFDOpenLegacySessionInt' as WFDOpenLegacySessionInt:qword
        extrn '__imp_WFDPairCancelByDeviceAddressInt' as WFDPairCancelByDeviceAddressInt:qword
        extrn '__imp_WFDPairCancelInt' as WFDPairCancelInt:qword
        extrn '__imp_WFDPairEnumerateCeremoniesInt' as WFDPairEnumerateCeremoniesInt:qword
        extrn '__imp_WFDPairSelectCeremonyInt' as WFDPairSelectCeremonyInt:qword
        extrn '__imp_WFDPairWithDeviceAndOpenSessionInt' as WFDPairWithDeviceAndOpenSessionInt:qword
        extrn '__imp_WFDParseOOBBlob' as WFDParseOOBBlob:qword
        extrn '__imp_WFDParseProfileXmlInt' as WFDParseProfileXmlInt:qword
        extrn '__imp_WFDQueryPropertyInt' as WFDQueryPropertyInt:qword
        extrn '__imp_WFDRegisterNotificationInt' as WFDRegisterNotificationInt:qword
        extrn '__imp_WFDSetAdditionalIEsInt' as WFDSetAdditionalIEsInt:qword
        extrn '__imp_WFDSetPropertyInt' as WFDSetPropertyInt:qword
        extrn '__imp_WFDSetSecondaryDeviceTypeListInt' as WFDSetSecondaryDeviceTypeListInt:qword
        extrn '__imp_WFDStartConnectorPairWithOOB' as WFDStartConnectorPairWithOOB:qword
        extrn '__imp_WFDStartListenerPairWithOOB' as WFDStartListenerPairWithOOB:qword
        extrn '__imp_WFDStartOpenSessionInt' as WFDStartOpenSessionInt:qword
        extrn '__imp_WFDStartUsingGroupInt' as WFDStartUsingGroupInt:qword
        extrn '__imp_WFDStopUsingGroupInt' as WFDStopUsingGroupInt:qword
        extrn '__imp_WlanCancelPlap' as WlanCancelPlap:qword
        extrn '__imp_WlanConnectEx' as WlanConnectEx:qword
        extrn '__imp_WlanConnectWithInput' as WlanConnectWithInput:qword
        extrn '__imp_WlanDeinitPlapParams' as WlanDeinitPlapParams:qword
        extrn '__imp_WlanDoesBssMatchSecurity' as WlanDoesBssMatchSecurity:qword
        extrn '__imp_WlanDoPlap' as WlanDoPlap:qword
        extrn '__imp_WlanEnumAllInterfaces' as WlanEnumAllInterfaces:qword
        extrn '__imp_WlanGenerateProfileXmlBasicSettings' as WlanGenerateProfileXmlBasicSettings:qword
        extrn '__imp_WlanGetMFPNegotiated' as WlanGetMFPNegotiated:qword
        extrn '__imp_WlanGetProfileEapUserDataInfo' as WlanGetProfileEapUserDataInfo:qword
        extrn '__imp_WlanGetProfileIndex' as WlanGetProfileIndex:qword
        extrn '__imp_WlanGetProfileKeyInfo' as WlanGetProfileKeyInfo:qword
        extrn '__imp_WlanGetStoredRadioState' as WlanGetStoredRadioState:qword
        extrn '__imp_WlanHostedNetworkFreeWCNSettings' as WlanHostedNetworkFreeWCNSettings:qword
        extrn '__imp_WlanHostedNetworkHlpQueryEverUsed' as WlanHostedNetworkHlpQueryEverUsed:qword
        extrn '__imp_WlanHostedNetworkQueryWCNSettings' as WlanHostedNetworkQueryWCNSettings:qword
        extrn '__imp_WlanHostedNetworkSetWCNSettings' as WlanHostedNetworkSetWCNSettings:qword
        extrn '__imp_WlanInitPlapParams' as WlanInitPlapParams:qword
        extrn '__imp_WlanInternalScan' as WlanInternalScan:qword
        extrn '__imp_WlanIsActiveConsoleUser' as WlanIsActiveConsoleUser:qword
        extrn '__imp_WlanIsNetworkSuppressed' as WlanIsNetworkSuppressed:qword
        extrn '__imp_WlanIsUIRequestPending' as WlanIsUIRequestPending:qword
        extrn '__imp_WlanLowPrivCloseHandle' as WlanLowPrivCloseHandle:qword
        extrn '__imp_WlanLowPrivEnumInterfaces' as WlanLowPrivEnumInterfaces:qword
        extrn '__imp_WlanLowPrivFreeMemory' as WlanLowPrivFreeMemory:qword
        extrn '__imp_WlanLowPrivOpenHandle' as WlanLowPrivOpenHandle:qword
        extrn '__imp_WlanLowPrivQueryInterface' as WlanLowPrivQueryInterface:qword
        extrn '__imp_WlanLowPrivSetInterface' as WlanLowPrivSetInterface:qword
        extrn '__imp_WlanParseProfileXmlBasicSettings' as WlanParseProfileXmlBasicSettings:qword
        extrn '__imp_WlanPrivateGetAvailableNetworkList' as WlanPrivateGetAvailableNetworkList:qword
        extrn '__imp_WlanQueryCreateAllUserProfileRestricted' as WlanQueryCreateAllUserProfileRestricted:qword
        extrn '__imp_WlanQueryPlapCredentials' as WlanQueryPlapCredentials:qword
        extrn '__imp_WlanQueryPreConnectInput' as WlanQueryPreConnectInput:qword
        extrn '__imp_WlanQueryVirtualInterfaceType' as WlanQueryVirtualInterfaceType:qword
        extrn '__imp_WlanRefreshConnections' as WlanRefreshConnections:qword
        extrn '__imp_WlanRemoveUIForwardingNetworkList' as WlanRemoveUIForwardingNetworkList:qword
        extrn '__imp_WlanSendUIResponse' as WlanSendUIResponse:qword
        extrn '__imp_WlanSetAllUserProfileRestricted' as WlanSetAllUserProfileRestricted:qword
        extrn '__imp_WlanSetProfileMetadata' as WlanSetProfileMetadata:qword
        extrn '__imp_WlanSignalValueToBar' as WlanSignalValueToBar:qword
        extrn '__imp_WlanSsidToDisplayName' as WlanSsidToDisplayName:qword
        extrn '__imp_WlanStartAP' as WlanStartAP:qword
        extrn '__imp_WlanStopAP' as WlanStopAP:qword
        extrn '__imp_WlanStoreRadioStateOnEnteringAirPlaneMode' as WlanStoreRadioStateOnEnteringAirPlaneMode:qword
        extrn '__imp_WlanStringToSsid' as WlanStringToSsid:qword
        extrn '__imp_WlanWcmGetInterface' as WlanWcmGetInterface:qword
        extrn '__imp_WlanWcmGetProfileList' as WlanWcmGetProfileList:qword
        extrn '__imp_WlanWcmSetInterface' as WlanWcmSetInterface:qword
        extrn '__imp_WlanWfdGetPeerInfo' as WlanWfdGetPeerInfo:qword
        extrn '__imp_WlanWfdGOSetWCNSettings' as WlanWfdGOSetWCNSettings:qword
        extrn '__imp_WlanWfdStartGO' as WlanWfdStartGO:qword
        extrn '__imp_WlanWfdStopGO' as WlanWfdStopGO:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN81)
        extrn '__imp_WFDConfigureFirewallForSessionInt' as WFDConfigureFirewallForSessionInt:qword
        extrn '__imp_WFDForceDisconnectLegacyPeerInt' as WFDForceDisconnectLegacyPeerInt:qword
        extrn '__imp_WFDGetSessionEndpointPairsInt' as WFDGetSessionEndpointPairsInt:qword
        extrn '__imp_WFDLowPrivCancelOpenSessionInt' as WFDLowPrivCancelOpenSessionInt:qword
        extrn '__imp_WFDLowPrivCloseHandleInt' as WFDLowPrivCloseHandleInt:qword
        extrn '__imp_WFDLowPrivCloseSessionInt' as WFDLowPrivCloseSessionInt:qword
        extrn '__imp_WFDLowPrivConfigureFirewallForSessionInt' as WFDLowPrivConfigureFirewallForSessionInt:qword
        extrn '__imp_WFDLowPrivGetSessionEndpointPairsInt' as WFDLowPrivGetSessionEndpointPairsInt:qword
        extrn '__imp_WFDLowPrivIsWfdSupportedInt' as WFDLowPrivIsWfdSupportedInt:qword
        extrn '__imp_WFDLowPrivOpenHandleInt' as WFDLowPrivOpenHandleInt:qword
        extrn '__imp_WFDLowPrivRegisterNotificationInt' as WFDLowPrivRegisterNotificationInt:qword
        extrn '__imp_WFDLowPrivStartOpenSessionByInterfaceIdInt' as WFDLowPrivStartOpenSessionByInterfaceIdInt:qword
        extrn '__imp_WFDPairWithDeviceAndOpenSessionExInt' as WFDPairWithDeviceAndOpenSessionExInt:qword
        extrn '__imp_WFDStopDiscoverDevicesInt' as WFDStopDiscoverDevicesInt:qword
        extrn '__imp_WlanNotifyVsIeProviderInt' as WlanNotifyVsIeProviderInt:qword
        extrn '__imp_WlanTryUpgradeCurrentConnectionAuthCipher' as WlanTryUpgradeCurrentConnectionAuthCipher:qword
        extrn '__imp_WlanUpdateProfileWithAuthCipher' as WlanUpdateProfileWithAuthCipher:qword
        extrn '__imp_WlanUtf8SsidToDisplayName' as WlanUtf8SsidToDisplayName:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp_WFDAbortSessionInt' as WFDAbortSessionInt:qword
        extrn '__imp_WFDCreateDHPrivatePublicKeyPairInt' as WFDCreateDHPrivatePublicKeyPairInt:qword
        extrn '__imp_WFDGetDeviceDescriptorForPendingRequestInt' as WFDGetDeviceDescriptorForPendingRequestInt:qword
        extrn '__imp_WFDGetNFCCarrierConfigBlobInt' as WFDGetNFCCarrierConfigBlobInt:qword
        extrn '__imp_WFDLowPrivCloseLegacySessionInt' as WFDLowPrivCloseLegacySessionInt:qword
        extrn '__imp_WFDLowPrivDeclineDeviceApiConnectionRequestInt' as WFDLowPrivDeclineDeviceApiConnectionRequestInt:qword
        extrn '__imp_WFDLowPrivGetPendingGroupRequestDetailsInt' as WFDLowPrivGetPendingGroupRequestDetailsInt:qword
        extrn '__imp_WFDLowPrivOpenLegacySessionInt' as WFDLowPrivOpenLegacySessionInt:qword
        extrn '__imp_WFDLowPrivOpenSessionByDafObjectIdInt' as WFDLowPrivOpenSessionByDafObjectIdInt:qword
        extrn '__imp_WFDLowPrivQueryPropertyInt' as WFDLowPrivQueryPropertyInt:qword
        extrn '__imp_WFDLowPrivRegisterVMgrCallerInt' as WFDLowPrivRegisterVMgrCallerInt:qword
        extrn '__imp_WFDLowPrivSetPropertyInt' as WFDLowPrivSetPropertyInt:qword
        extrn '__imp_WFDLowPrivStartDeviceApiConnectionRequestListenerInt' as WFDLowPrivStartDeviceApiConnectionRequestListenerInt:qword
        extrn '__imp_WFDLowPrivStartUsingGroupInt' as WFDLowPrivStartUsingGroupInt:qword
        extrn '__imp_WFDLowPrivStopDeviceApiConnectionRequestListenerInt' as WFDLowPrivStopDeviceApiConnectionRequestListenerInt:qword
        extrn '__imp_WFDLowPrivStopUsingGroupInt' as WFDLowPrivStopUsingGroupInt:qword
        extrn '__imp_WFDLowPrivUnregisterVMgrCallerInt' as WFDLowPrivUnregisterVMgrCallerInt:qword
        extrn '__imp_WFDPairContinuePairWithDeviceInt' as WFDPairContinuePairWithDeviceInt:qword
        extrn '__imp_WFDParseOOBBlobTypeAndGetPayloadInt' as WFDParseOOBBlobTypeAndGetPayloadInt:qword
        extrn '__imp_WFDParseWfaNfcCarrierConfigBlobInt' as WFDParseWfaNfcCarrierConfigBlobInt:qword
        extrn '__imp_WFDRegisterVMgrCallerInt' as WFDRegisterVMgrCallerInt:qword
        extrn '__imp_WFDStartBackgroundDiscoveryInt' as WFDStartBackgroundDiscoveryInt:qword
        extrn '__imp_WFDStartOffloadedDiscoveryInt' as WFDStartOffloadedDiscoveryInt:qword
        extrn '__imp_WFDStartUsingGroupExInt' as WFDStartUsingGroupExInt:qword
        extrn '__imp_WFDStopBackgroundDiscoveryInt' as WFDStopBackgroundDiscoveryInt:qword
        extrn '__imp_WFDStopOffloadedDiscoveryInt' as WFDStopOffloadedDiscoveryInt:qword
        extrn '__imp_WFDSvcLowPrivAcceptSessionInt' as WFDSvcLowPrivAcceptSessionInt:qword
        extrn '__imp_WFDSvcLowPrivCancelSessionInt' as WFDSvcLowPrivCancelSessionInt:qword
        extrn '__imp_WFDSvcLowPrivCloseSessionInt' as WFDSvcLowPrivCloseSessionInt:qword
        extrn '__imp_WFDSvcLowPrivConfigureSessionInt' as WFDSvcLowPrivConfigureSessionInt:qword
        extrn '__imp_WFDSvcLowPrivConnectSessionInt' as WFDSvcLowPrivConnectSessionInt:qword
        extrn '__imp_WFDSvcLowPrivGetProvisioningInfoInt' as WFDSvcLowPrivGetProvisioningInfoInt:qword
        extrn '__imp_WFDSvcLowPrivGetSessionEndpointPairsInt' as WFDSvcLowPrivGetSessionEndpointPairsInt:qword
        extrn '__imp_WFDSvcLowPrivOpenAdvertiserSessionInt' as WFDSvcLowPrivOpenAdvertiserSessionInt:qword
        extrn '__imp_WFDSvcLowPrivOpenSeekerSessionInt' as WFDSvcLowPrivOpenSeekerSessionInt:qword
        extrn '__imp_WFDSvcLowPrivPublishServiceInt' as WFDSvcLowPrivPublishServiceInt:qword
        extrn '__imp_WFDSvcLowPrivUnpublishServiceInt' as WFDSvcLowPrivUnpublishServiceInt:qword
        extrn '__imp_WFDUnregisterVMgrCallerInt' as WFDUnregisterVMgrCallerInt:qword
        extrn '__imp_WlanGetAvailableNetworkList2' as WlanGetAvailableNetworkList2:qword
        extrn '__imp_WlanLowPrivNotifyVsIeProviderInt' as WlanLowPrivNotifyVsIeProviderInt:qword
        extrn '__imp_WlanNotifyVsIeProviderExInt' as WlanNotifyVsIeProviderExInt:qword
        extrn '__imp_WlanPrivateClearAnqpCache' as WlanPrivateClearAnqpCache:qword
        extrn '__imp_WlanPrivateGetAnqpCacheResponse' as WlanPrivateGetAnqpCacheResponse:qword
        extrn '__imp_WlanPrivateParseAnqpRawData' as WlanPrivateParseAnqpRawData:qword
        extrn '__imp_WlanPrivateQueryInterface' as WlanPrivateQueryInterface:qword
        extrn '__imp_WlanPrivateRefreshAnqpCache' as WlanPrivateRefreshAnqpCache:qword
        extrn '__imp_WlanPrivateSetInterface' as WlanPrivateSetInterface:qword
        extrn '__imp_WlanSetProfileListForOffload' as WlanSetProfileListForOffload:qword
        extrn '__imp_WlanStringToUtf8Ssid' as WlanStringToUtf8Ssid:qword
        extrn '__imp_WlanUpdateBasicProfileSecurity' as WlanUpdateBasicProfileSecurity:qword
        extrn '__imp_WlanVMgrQueryCurrentScenariosInt' as WlanVMgrQueryCurrentScenariosInt:qword
        extrn '__imp_WlanWcmDisconnect' as WlanWcmDisconnect:qword
        extrn '__imp_WlanWcmSetProfile' as WlanWcmSetProfile:qword
    end if
;else
;    if (NTDDI_VERSION >= NTDDI_WIN8)
;        extrn '__imp__QueryNetconStatus@??' as QueryNetconStatus:dword
;        extrn '__imp__QueryNetconVirtualCharacteristic@??' as QueryNetconVirtualCharacteristic:dword
;        extrn '__imp__WFDAcceptConnectRequestAndOpenSessionInt@??' as WFDAcceptConnectRequestAndOpenSessionInt:dword
;        extrn '__imp__WFDAcceptGroupRequestAndOpenSessionInt@??' as WFDAcceptGroupRequestAndOpenSessionInt:dword
;        extrn '__imp__WFDCancelConnectorPairWithOOB@??' as WFDCancelConnectorPairWithOOB:dword
;        extrn '__imp__WFDCancelListenerPairWithOOB@??' as WFDCancelListenerPairWithOOB:dword
;        extrn '__imp__WFDCancelOpenSessionInt@??' as WFDCancelOpenSessionInt:dword
;        extrn '__imp__WFDCloseHandleInt@??' as WFDCloseHandleInt:dword
;        extrn '__imp__WFDCloseLegacySessionInt@??' as WFDCloseLegacySessionInt:dword
;        extrn '__imp__WFDCloseOOBPairingSession@??' as WFDCloseOOBPairingSession:dword
;        extrn '__imp__WFDCloseSessionInt@??' as WFDCloseSessionInt:dword
;        extrn '__imp__WFDDeclineConnectRequestInt@??' as WFDDeclineConnectRequestInt:dword
;        extrn '__imp__WFDDeclineGroupRequestInt@??' as WFDDeclineGroupRequestInt:dword
;        extrn '__imp__WFDDiscoverDevicesInt@??' as WFDDiscoverDevicesInt:dword
;        extrn '__imp__WFDFlushVisibleDeviceListInt@??' as WFDFlushVisibleDeviceListInt:dword
;        extrn '__imp__WFDForceDisconnectInt@??' as WFDForceDisconnectInt:dword
;        extrn '__imp__WFDFreeMemoryInt@??' as WFDFreeMemoryInt:dword
;        extrn '__imp__WFDGetDefaultGroupProfileInt@??' as WFDGetDefaultGroupProfileInt:dword
;        extrn '__imp__WFDGetOOBBlob@??' as WFDGetOOBBlob:dword
;        extrn '__imp__WFDGetProfileKeyInfoInt@??' as WFDGetProfileKeyInfoInt:dword
;        extrn '__imp__WFDGetVisibleDevicesInt@??' as WFDGetVisibleDevicesInt:dword
;        extrn '__imp__WFDIsInterfaceWiFiDirect@??' as WFDIsInterfaceWiFiDirect:dword
;        extrn '__imp__WFDIsWiFiDirectRunningOnWiFiAdapter@??' as WFDIsWiFiDirectRunningOnWiFiAdapter:dword
;        extrn '__imp__WFDOpenHandleInt@??' as WFDOpenHandleInt:dword
;        extrn '__imp__WFDOpenLegacySessionInt@??' as WFDOpenLegacySessionInt:dword
;        extrn '__imp__WFDPairCancelByDeviceAddressInt@??' as WFDPairCancelByDeviceAddressInt:dword
;        extrn '__imp__WFDPairCancelInt@??' as WFDPairCancelInt:dword
;        extrn '__imp__WFDPairEnumerateCeremoniesInt@??' as WFDPairEnumerateCeremoniesInt:dword
;        extrn '__imp__WFDPairSelectCeremonyInt@??' as WFDPairSelectCeremonyInt:dword
;        extrn '__imp__WFDPairWithDeviceAndOpenSessionInt@??' as WFDPairWithDeviceAndOpenSessionInt:dword
;        extrn '__imp__WFDParseOOBBlob@??' as WFDParseOOBBlob:dword
;        extrn '__imp__WFDParseProfileXmlInt@??' as WFDParseProfileXmlInt:dword
;        extrn '__imp__WFDQueryPropertyInt@??' as WFDQueryPropertyInt:dword
;        extrn '__imp__WFDRegisterNotificationInt@??' as WFDRegisterNotificationInt:dword
;        extrn '__imp__WFDSetAdditionalIEsInt@??' as WFDSetAdditionalIEsInt:dword
;        extrn '__imp__WFDSetPropertyInt@??' as WFDSetPropertyInt:dword
;        extrn '__imp__WFDSetSecondaryDeviceTypeListInt@??' as WFDSetSecondaryDeviceTypeListInt:dword
;        extrn '__imp__WFDStartConnectorPairWithOOB@??' as WFDStartConnectorPairWithOOB:dword
;        extrn '__imp__WFDStartListenerPairWithOOB@??' as WFDStartListenerPairWithOOB:dword
;        extrn '__imp__WFDStartOpenSessionInt@??' as WFDStartOpenSessionInt:dword
;        extrn '__imp__WFDStartUsingGroupInt@??' as WFDStartUsingGroupInt:dword
;        extrn '__imp__WFDStopUsingGroupInt@??' as WFDStopUsingGroupInt:dword
;        extrn '__imp__WlanCancelPlap@??' as WlanCancelPlap:dword
;        extrn '__imp__WlanConnectEx@??' as WlanConnectEx:dword
;        extrn '__imp__WlanConnectWithInput@??' as WlanConnectWithInput:dword
;        extrn '__imp__WlanDeinitPlapParams@??' as WlanDeinitPlapParams:dword
;        extrn '__imp__WlanDoesBssMatchSecurity@??' as WlanDoesBssMatchSecurity:dword
;        extrn '__imp__WlanDoPlap@??' as WlanDoPlap:dword
;        extrn '__imp__WlanEnumAllInterfaces@??' as WlanEnumAllInterfaces:dword
;        extrn '__imp__WlanGenerateProfileXmlBasicSettings@??' as WlanGenerateProfileXmlBasicSettings:dword
;        extrn '__imp__WlanGetMFPNegotiated@??' as WlanGetMFPNegotiated:dword
;        extrn '__imp__WlanGetProfileEapUserDataInfo@??' as WlanGetProfileEapUserDataInfo:dword
;        extrn '__imp__WlanGetProfileIndex@??' as WlanGetProfileIndex:dword
;        extrn '__imp__WlanGetProfileKeyInfo@??' as WlanGetProfileKeyInfo:dword
;        extrn '__imp__WlanGetStoredRadioState@??' as WlanGetStoredRadioState:dword
;        extrn '__imp__WlanHostedNetworkFreeWCNSettings@??' as WlanHostedNetworkFreeWCNSettings:dword
;        extrn '__imp__WlanHostedNetworkHlpQueryEverUsed@??' as WlanHostedNetworkHlpQueryEverUsed:dword
;        extrn '__imp__WlanHostedNetworkQueryWCNSettings@??' as WlanHostedNetworkQueryWCNSettings:dword
;        extrn '__imp__WlanHostedNetworkSetWCNSettings@??' as WlanHostedNetworkSetWCNSettings:dword
;        extrn '__imp__WlanInitPlapParams@??' as WlanInitPlapParams:dword
;        extrn '__imp__WlanInternalScan@??' as WlanInternalScan:dword
;        extrn '__imp__WlanIsActiveConsoleUser@??' as WlanIsActiveConsoleUser:dword
;        extrn '__imp__WlanIsNetworkSuppressed@??' as WlanIsNetworkSuppressed:dword
;        extrn '__imp__WlanIsUIRequestPending@??' as WlanIsUIRequestPending:dword
;        extrn '__imp__WlanLowPrivCloseHandle@??' as WlanLowPrivCloseHandle:dword
;        extrn '__imp__WlanLowPrivEnumInterfaces@??' as WlanLowPrivEnumInterfaces:dword
;        extrn '__imp__WlanLowPrivFreeMemory@??' as WlanLowPrivFreeMemory:dword
;        extrn '__imp__WlanLowPrivOpenHandle@??' as WlanLowPrivOpenHandle:dword
;        extrn '__imp__WlanLowPrivQueryInterface@??' as WlanLowPrivQueryInterface:dword
;        extrn '__imp__WlanLowPrivSetInterface@??' as WlanLowPrivSetInterface:dword
;        extrn '__imp__WlanParseProfileXmlBasicSettings@??' as WlanParseProfileXmlBasicSettings:dword
;        extrn '__imp__WlanPrivateGetAvailableNetworkList@??' as WlanPrivateGetAvailableNetworkList:dword
;        extrn '__imp__WlanQueryCreateAllUserProfileRestricted@??' as WlanQueryCreateAllUserProfileRestricted:dword
;        extrn '__imp__WlanQueryPlapCredentials@??' as WlanQueryPlapCredentials:dword
;        extrn '__imp__WlanQueryPreConnectInput@??' as WlanQueryPreConnectInput:dword
;        extrn '__imp__WlanQueryVirtualInterfaceType@??' as WlanQueryVirtualInterfaceType:dword
;        extrn '__imp__WlanRefreshConnections@??' as WlanRefreshConnections:dword
;        extrn '__imp__WlanRemoveUIForwardingNetworkList@??' as WlanRemoveUIForwardingNetworkList:dword
;        extrn '__imp__WlanSendUIResponse@??' as WlanSendUIResponse:dword
;        extrn '__imp__WlanSetAllUserProfileRestricted@??' as WlanSetAllUserProfileRestricted:dword
;        extrn '__imp__WlanSetProfileMetadata@??' as WlanSetProfileMetadata:dword
;        extrn '__imp__WlanSignalValueToBar@??' as WlanSignalValueToBar:dword
;        extrn '__imp__WlanSsidToDisplayName@??' as WlanSsidToDisplayName:dword
;        extrn '__imp__WlanStartAP@??' as WlanStartAP:dword
;        extrn '__imp__WlanStopAP@??' as WlanStopAP:dword
;        extrn '__imp__WlanStoreRadioStateOnEnteringAirPlaneMode@??' as WlanStoreRadioStateOnEnteringAirPlaneMode:dword
;        extrn '__imp__WlanStringToSsid@??' as WlanStringToSsid:dword
;        extrn '__imp__WlanWcmGetInterface@??' as WlanWcmGetInterface:dword
;        extrn '__imp__WlanWcmGetProfileList@??' as WlanWcmGetProfileList:dword
;        extrn '__imp__WlanWcmSetInterface@??' as WlanWcmSetInterface:dword
;        extrn '__imp__WlanWfdGetPeerInfo@??' as WlanWfdGetPeerInfo:dword
;        extrn '__imp__WlanWfdGOSetWCNSettings@??' as WlanWfdGOSetWCNSettings:dword
;        extrn '__imp__WlanWfdStartGO@??' as WlanWfdStartGO:dword
;        extrn '__imp__WlanWfdStopGO@??' as WlanWfdStopGO:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_WIN81)
;        extrn '__imp__WFDConfigureFirewallForSessionInt@??' as WFDConfigureFirewallForSessionInt:dword
;        extrn '__imp__WFDForceDisconnectLegacyPeerInt@??' as WFDForceDisconnectLegacyPeerInt:dword
;        extrn '__imp__WFDGetSessionEndpointPairsInt@??' as WFDGetSessionEndpointPairsInt:dword
;        extrn '__imp__WFDLowPrivCancelOpenSessionInt@??' as WFDLowPrivCancelOpenSessionInt:dword
;        extrn '__imp__WFDLowPrivCloseHandleInt@??' as WFDLowPrivCloseHandleInt:dword
;        extrn '__imp__WFDLowPrivCloseSessionInt@??' as WFDLowPrivCloseSessionInt:dword
;        extrn '__imp__WFDLowPrivConfigureFirewallForSessionInt@??' as WFDLowPrivConfigureFirewallForSessionInt:dword
;        extrn '__imp__WFDLowPrivGetSessionEndpointPairsInt@??' as WFDLowPrivGetSessionEndpointPairsInt:dword
;        extrn '__imp__WFDLowPrivIsWfdSupportedInt@??' as WFDLowPrivIsWfdSupportedInt:dword
;        extrn '__imp__WFDLowPrivOpenHandleInt@??' as WFDLowPrivOpenHandleInt:dword
;        extrn '__imp__WFDLowPrivRegisterNotificationInt@??' as WFDLowPrivRegisterNotificationInt:dword
;        extrn '__imp__WFDLowPrivStartOpenSessionByInterfaceIdInt@??' as WFDLowPrivStartOpenSessionByInterfaceIdInt:dword
;        extrn '__imp__WFDPairWithDeviceAndOpenSessionExInt@??' as WFDPairWithDeviceAndOpenSessionExInt:dword
;        extrn '__imp__WFDStopDiscoverDevicesInt@??' as WFDStopDiscoverDevicesInt:dword
;        extrn '__imp__WlanNotifyVsIeProviderInt@??' as WlanNotifyVsIeProviderInt:dword
;        extrn '__imp__WlanTryUpgradeCurrentConnectionAuthCipher@??' as WlanTryUpgradeCurrentConnectionAuthCipher:dword
;        extrn '__imp__WlanUpdateProfileWithAuthCipher@??' as WlanUpdateProfileWithAuthCipher:dword
;        extrn '__imp__WlanUtf8SsidToDisplayName@??' as WlanUtf8SsidToDisplayName:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_WIN10)
;        extrn '__imp__WFDAbortSessionInt@??' as WFDAbortSessionInt:dword
;        extrn '__imp__WFDCreateDHPrivatePublicKeyPairInt@??' as WFDCreateDHPrivatePublicKeyPairInt:dword
;        extrn '__imp__WFDGetDeviceDescriptorForPendingRequestInt@??' as WFDGetDeviceDescriptorForPendingRequestInt:dword
;        extrn '__imp__WFDGetNFCCarrierConfigBlobInt@??' as WFDGetNFCCarrierConfigBlobInt:dword
;        extrn '__imp__WFDLowPrivCloseLegacySessionInt@??' as WFDLowPrivCloseLegacySessionInt:dword
;        extrn '__imp__WFDLowPrivDeclineDeviceApiConnectionRequestInt@??' as WFDLowPrivDeclineDeviceApiConnectionRequestInt:dword
;        extrn '__imp__WFDLowPrivGetPendingGroupRequestDetailsInt@??' as WFDLowPrivGetPendingGroupRequestDetailsInt:dword
;        extrn '__imp__WFDLowPrivOpenLegacySessionInt@??' as WFDLowPrivOpenLegacySessionInt:dword
;        extrn '__imp__WFDLowPrivOpenSessionByDafObjectIdInt@??' as WFDLowPrivOpenSessionByDafObjectIdInt:dword
;        extrn '__imp__WFDLowPrivQueryPropertyInt@??' as WFDLowPrivQueryPropertyInt:dword
;        extrn '__imp__WFDLowPrivRegisterVMgrCallerInt@??' as WFDLowPrivRegisterVMgrCallerInt:dword
;        extrn '__imp__WFDLowPrivSetPropertyInt@??' as WFDLowPrivSetPropertyInt:dword
;        extrn '__imp__WFDLowPrivStartDeviceApiConnectionRequestListenerInt@??' as WFDLowPrivStartDeviceApiConnectionRequestListenerInt:dword
;        extrn '__imp__WFDLowPrivStartUsingGroupInt@??' as WFDLowPrivStartUsingGroupInt:dword
;        extrn '__imp__WFDLowPrivStopDeviceApiConnectionRequestListenerInt@??' as WFDLowPrivStopDeviceApiConnectionRequestListenerInt:dword
;        extrn '__imp__WFDLowPrivStopUsingGroupInt@??' as WFDLowPrivStopUsingGroupInt:dword
;        extrn '__imp__WFDLowPrivUnregisterVMgrCallerInt@??' as WFDLowPrivUnregisterVMgrCallerInt:dword
;        extrn '__imp__WFDPairContinuePairWithDeviceInt@??' as WFDPairContinuePairWithDeviceInt:dword
;        extrn '__imp__WFDParseOOBBlobTypeAndGetPayloadInt@??' as WFDParseOOBBlobTypeAndGetPayloadInt:dword
;        extrn '__imp__WFDParseWfaNfcCarrierConfigBlobInt@??' as WFDParseWfaNfcCarrierConfigBlobInt:dword
;        extrn '__imp__WFDRegisterVMgrCallerInt@??' as WFDRegisterVMgrCallerInt:dword
;        extrn '__imp__WFDStartBackgroundDiscoveryInt@??' as WFDStartBackgroundDiscoveryInt:dword
;        extrn '__imp__WFDStartOffloadedDiscoveryInt@??' as WFDStartOffloadedDiscoveryInt:dword
;        extrn '__imp__WFDStartUsingGroupExInt@??' as WFDStartUsingGroupExInt:dword
;        extrn '__imp__WFDStopBackgroundDiscoveryInt@??' as WFDStopBackgroundDiscoveryInt:dword
;        extrn '__imp__WFDStopOffloadedDiscoveryInt@??' as WFDStopOffloadedDiscoveryInt:dword
;        extrn '__imp__WFDSvcLowPrivAcceptSessionInt@??' as WFDSvcLowPrivAcceptSessionInt:dword
;        extrn '__imp__WFDSvcLowPrivCancelSessionInt@??' as WFDSvcLowPrivCancelSessionInt:dword
;        extrn '__imp__WFDSvcLowPrivCloseSessionInt@??' as WFDSvcLowPrivCloseSessionInt:dword
;        extrn '__imp__WFDSvcLowPrivConfigureSessionInt@??' as WFDSvcLowPrivConfigureSessionInt:dword
;        extrn '__imp__WFDSvcLowPrivConnectSessionInt@??' as WFDSvcLowPrivConnectSessionInt:dword
;        extrn '__imp__WFDSvcLowPrivGetProvisioningInfoInt@??' as WFDSvcLowPrivGetProvisioningInfoInt:dword
;        extrn '__imp__WFDSvcLowPrivGetSessionEndpointPairsInt@??' as WFDSvcLowPrivGetSessionEndpointPairsInt:dword
;        extrn '__imp__WFDSvcLowPrivOpenAdvertiserSessionInt@??' as WFDSvcLowPrivOpenAdvertiserSessionInt:dword
;        extrn '__imp__WFDSvcLowPrivOpenSeekerSessionInt@??' as WFDSvcLowPrivOpenSeekerSessionInt:dword
;        extrn '__imp__WFDSvcLowPrivPublishServiceInt@??' as WFDSvcLowPrivPublishServiceInt:dword
;        extrn '__imp__WFDSvcLowPrivUnpublishServiceInt@??' as WFDSvcLowPrivUnpublishServiceInt:dword
;        extrn '__imp__WFDUnregisterVMgrCallerInt@??' as WFDUnregisterVMgrCallerInt:dword
;        extrn '__imp__WlanGetAvailableNetworkList2@??' as WlanGetAvailableNetworkList2:dword
;        extrn '__imp__WlanLowPrivNotifyVsIeProviderInt@??' as WlanLowPrivNotifyVsIeProviderInt:dword
;        extrn '__imp__WlanNotifyVsIeProviderExInt@??' as WlanNotifyVsIeProviderExInt:dword
;        extrn '__imp__WlanPrivateClearAnqpCache@??' as WlanPrivateClearAnqpCache:dword
;        extrn '__imp__WlanPrivateGetAnqpCacheResponse@??' as WlanPrivateGetAnqpCacheResponse:dword
;        extrn '__imp__WlanPrivateParseAnqpRawData@??' as WlanPrivateParseAnqpRawData:dword
;        extrn '__imp__WlanPrivateQueryInterface@??' as WlanPrivateQueryInterface:dword
;        extrn '__imp__WlanPrivateRefreshAnqpCache@??' as WlanPrivateRefreshAnqpCache:dword
;        extrn '__imp__WlanPrivateSetInterface@??' as WlanPrivateSetInterface:dword
;        extrn '__imp__WlanSetProfileListForOffload@??' as WlanSetProfileListForOffload:dword
;        extrn '__imp__WlanStringToUtf8Ssid@??' as WlanStringToUtf8Ssid:dword
;        extrn '__imp__WlanUpdateBasicProfileSecurity@??' as WlanUpdateBasicProfileSecurity:dword
;        extrn '__imp__WlanVMgrQueryCurrentScenariosInt@??' as WlanVMgrQueryCurrentScenariosInt:dword
;        extrn '__imp__WlanWcmDisconnect@??' as WlanWcmDisconnect:dword
;        extrn '__imp__WlanWcmSetProfile@??' as WlanWcmSetProfile:dword
;    end if
end if

end if ;WLANAPI_INC
