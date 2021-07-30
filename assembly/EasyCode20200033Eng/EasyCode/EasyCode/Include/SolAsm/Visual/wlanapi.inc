; ====================================================;
;                                                     ;
;    wlanapi.inc for EC v2 SolAsm visual projects     ;
;                   (version 1.0.1)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2020            ;
;                                                     ;
; ====================================================;

#ifndef WLANAPI_INC
WLANAPI_INC  equ 1

WLAN_API_VERSION_1_0                            equ     00000001H
WLAN_API_VERSION_2_0                            equ     00000002H

#if NTDDI_VERSION >= NTDDI_VISTA
    WLAN_API_VERSION                            equ     WLAN_API_VERSION_2_0
#else
    #if NTDDI_VERSION >= NTDDI_WINXP
        WLAN_API_VERSION                        equ     WLAN_API_VERSION_1_0
    #endif
#endif

L2_PROFILE_MAX_NAME_LENGTH                      equ     256

WLAN_PROFILE_GROUP_POLICY                       equ     00000001H
WLAN_PROFILE_USER                               equ     00000002H
WLAN_PROFILE_GET_PLAINTEXT_KEY                  equ     00000004H
WLAN_PROFILE_CONNECTION_MODE_SET_BY_CLIENT      equ     00010000H
WLAN_PROFILE_CONNECTION_MODE_AUTO               equ     00020000H

dot11_BSS_type_infrastructure                   equ     1
dot11_BSS_type_independent                      equ     2
dot11_BSS_type_any                              equ     3

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
L2_REASON_CODE_DOT11_AC_BASE                    equ     L2_REASON_CODE_GEN_BASE+L2_REASON_CODE_GROUP_SIZE
L2_REASON_CODE_DOT11_MSM_BASE                   equ     L2_REASON_CODE_DOT11_AC_BASE+L2_REASON_CODE_GROUP_SIZE
L2_REASON_CODE_DOT11_SECURITY_BASE              equ     L2_REASON_CODE_DOT11_MSM_BASE+L2_REASON_CODE_GROUP_SIZE
L2_REASON_CODE_ONEX_BASE                        equ     L2_REASON_CODE_DOT11_SECURITY_BASE+L2_REASON_CODE_GROUP_SIZE
L2_REASON_CODE_DOT3_AC_BASE                     equ     L2_REASON_CODE_ONEX_BASE+L2_REASON_CODE_GROUP_SIZE
L2_REASON_CODE_DOT3_MSM_BASE                    equ     L2_REASON_CODE_DOT3_AC_BASE+L2_REASON_CODE_GROUP_SIZE
L2_REASON_CODE_PROFILE_BASE                     equ     L2_REASON_CODE_DOT3_MSM_BASE+L2_REASON_CODE_GROUP_SIZE
L2_REASON_CODE_IHV_BASE                         equ     L2_REASON_CODE_PROFILE_BASE+L2_REASON_CODE_GROUP_SIZE
L2_REASON_CODE_WIMAX_BASE                       equ     L2_REASON_CODE_IHV_BASE+L2_REASON_CODE_GROUP_SIZE

WLAN_REASON_CODE_SUCCESS                        equ     0
WLAN_REASON_CODE_UNKNOWN                        equ     L2_REASON_CODE_UNKNOWN

WLAN_REASON_CODE_RANGE_SIZE                     equ     L2_REASON_CODE_GROUP_SIZE
WLAN_REASON_CODE_BASE                           equ     L2_REASON_CODE_DOT11_AC_BASE

WLAN_REASON_CODE_AC_BASE                        equ     L2_REASON_CODE_DOT11_AC_BASE
WLAN_REASON_CODE_AC_CONNECT_BASE                equ     WLAN_REASON_CODE_AC_BASE+WLAN_REASON_CODE_RANGE_SIZE/2
WLAN_REASON_CODE_AC_END                         equ     WLAN_REASON_CODE_AC_BASE+WLAN_REASON_CODE_RANGE_SIZE-1

WLAN_REASON_CODE_PROFILE_BASE                   equ     L2_REASON_CODE_PROFILE_BASE
WLAN_REASON_CODE_PROFILE_CONNECT_BASE           equ     WLAN_REASON_CODE_PROFILE_BASE+WLAN_REASON_CODE_RANGE_SIZE/2
WLAN_REASON_CODE_PROFILE_END                    equ     WLAN_REASON_CODE_PROFILE_BASE+WLAN_REASON_CODE_RANGE_SIZE-1

WLAN_REASON_CODE_MSM_BASE                       equ     L2_REASON_CODE_DOT11_MSM_BASE
WLAN_REASON_CODE_MSM_CONNECT_BASE               equ     WLAN_REASON_CODE_MSM_BASE+WLAN_REASON_CODE_RANGE_SIZE/2
WLAN_REASON_CODE_MSM_END                        equ     WLAN_REASON_CODE_MSM_BASE+WLAN_REASON_CODE_RANGE_SIZE-1

WLAN_REASON_CODE_MSMSEC_BASE                    equ     L2_REASON_CODE_DOT11_SECURITY_BASE
WLAN_REASON_CODE_MSMSEC_CONNECT_BASE            equ     WLAN_REASON_CODE_MSMSEC_BASE+WLAN_REASON_CODE_RANGE_SIZE/2
WLAN_REASON_CODE_MSMSEC_END                     equ     WLAN_REASON_CODE_MSMSEC_BASE+WLAN_REASON_CODE_RANGE_SIZE-1

WLAN_REASON_CODE_NETWORK_NOT_COMPATIBLE         equ     WLAN_REASON_CODE_AC_BASE+1
WLAN_REASON_CODE_PROFILE_NOT_COMPATIBLE         equ     WLAN_REASON_CODE_AC_BASE+2

WLAN_REASON_CODE_NO_AUTO_CONNECTION             equ     WLAN_REASON_CODE_AC_CONNECT_BASE+1
WLAN_REASON_CODE_NOT_VISIBLE                    equ     WLAN_REASON_CODE_AC_CONNECT_BASE+2
WLAN_REASON_CODE_GP_DENIED                      equ     WLAN_REASON_CODE_AC_CONNECT_BASE+3
WLAN_REASON_CODE_USER_DENIED                    equ     WLAN_REASON_CODE_AC_CONNECT_BASE+4
WLAN_REASON_CODE_BSS_TYPE_NOT_ALLOWED           equ     WLAN_REASON_CODE_AC_CONNECT_BASE+5
WLAN_REASON_CODE_IN_FAILED_LIST                 equ     WLAN_REASON_CODE_AC_CONNECT_BASE+6
WLAN_REASON_CODE_IN_BLOCKED_LIST                equ     WLAN_REASON_CODE_AC_CONNECT_BASE+7
WLAN_REASON_CODE_SSID_LIST_TOO_LONG             equ     WLAN_REASON_CODE_AC_CONNECT_BASE+8
WLAN_REASON_CODE_CONNECT_CALL_FAIL              equ     WLAN_REASON_CODE_AC_CONNECT_BASE+9
WLAN_REASON_CODE_SCAN_CALL_FAIL                 equ     WLAN_REASON_CODE_AC_CONNECT_BASE+10
WLAN_REASON_CODE_NETWORK_NOT_AVAILABLE          equ     WLAN_REASON_CODE_AC_CONNECT_BASE+11
WLAN_REASON_CODE_PROFILE_CHANGED_OR_DELETED     equ     WLAN_REASON_CODE_AC_CONNECT_BASE+12
WLAN_REASON_CODE_KEY_MISMATCH                   equ     WLAN_REASON_CODE_AC_CONNECT_BASE+13
WLAN_REASON_CODE_USER_NOT_RESPOND               equ     WLAN_REASON_CODE_AC_CONNECT_BASE+14
WLAN_REASON_CODE_AP_PROFILE_NOT_ALLOWED_FOR_CLIENT equ  WLAN_REASON_CODE_AC_CONNECT_BASE+15
WLAN_REASON_CODE_AP_PROFILE_NOT_ALLOWED         equ     WLAN_REASON_CODE_AC_CONNECT_BASE+16
WLAN_REASON_CODE_HOTSPOT2_PROFILE_DENIED        equ     WLAN_REASON_CODE_AC_CONNECT_BASE+17

WLAN_REASON_CODE_INVALID_PROFILE_SCHEMA         equ     WLAN_REASON_CODE_PROFILE_BASE+1
WLAN_REASON_CODE_PROFILE_MISSING                equ     WLAN_REASON_CODE_PROFILE_BASE+2
WLAN_REASON_CODE_INVALID_PROFILE_NAME           equ     WLAN_REASON_CODE_PROFILE_BASE+3
WLAN_REASON_CODE_INVALID_PROFILE_TYPE           equ     WLAN_REASON_CODE_PROFILE_BASE+4
WLAN_REASON_CODE_INVALID_PHY_TYPE               equ     WLAN_REASON_CODE_PROFILE_BASE+5
WLAN_REASON_CODE_MSM_SECURITY_MISSING           equ     WLAN_REASON_CODE_PROFILE_BASE+6
WLAN_REASON_CODE_IHV_SECURITY_NOT_SUPPORTED     equ     WLAN_REASON_CODE_PROFILE_BASE+7
WLAN_REASON_CODE_IHV_OUI_MISMATCH               equ     WLAN_REASON_CODE_PROFILE_BASE+8
WLAN_REASON_CODE_IHV_OUI_MISSING                equ     WLAN_REASON_CODE_PROFILE_BASE+9
WLAN_REASON_CODE_IHV_SETTINGS_MISSING           equ     WLAN_REASON_CODE_PROFILE_BASE+10
WLAN_REASON_CODE_CONFLICT_SECURITY              equ     WLAN_REASON_CODE_PROFILE_BASE+11
WLAN_REASON_CODE_SECURITY_MISSING               equ     WLAN_REASON_CODE_PROFILE_BASE+12
WLAN_REASON_CODE_INVALID_BSS_TYPE               equ     WLAN_REASON_CODE_PROFILE_BASE+13
WLAN_REASON_CODE_INVALID_ADHOC_CONNECTION_MODE  equ     WLAN_REASON_CODE_PROFILE_BASE+14
WLAN_REASON_CODE_NON_BROADCAST_SET_FOR_ADHOC    equ     WLAN_REASON_CODE_PROFILE_BASE+15
WLAN_REASON_CODE_AUTO_SWITCH_SET_FOR_ADHOC      equ     WLAN_REASON_CODE_PROFILE_BASE+16
WLAN_REASON_CODE_AUTO_SWITCH_SET_FOR_MANUAL_CONNECTION equ WLAN_REASON_CODE_PROFILE_BASE+17
WLAN_REASON_CODE_IHV_SECURITY_ONEX_MISSING      equ     WLAN_REASON_CODE_PROFILE_BASE+18
WLAN_REASON_CODE_PROFILE_SSID_INVALID           equ     WLAN_REASON_CODE_PROFILE_BASE+19
WLAN_REASON_CODE_TOO_MANY_SSID                  equ     WLAN_REASON_CODE_PROFILE_BASE+20
WLAN_REASON_CODE_IHV_CONNECTIVITY_NOT_SUPPORTED equ     WLAN_REASON_CODE_PROFILE_BASE+21
WLAN_REASON_CODE_BAD_MAX_NUMBER_OF_CLIENTS_FOR_AP equ   WLAN_REASON_CODE_PROFILE_BASE+22
WLAN_REASON_CODE_INVALID_CHANNEL                equ     WLAN_REASON_CODE_PROFILE_BASE+23
WLAN_REASON_CODE_OPERATION_MODE_NOT_SUPPORTED   equ     WLAN_REASON_CODE_PROFILE_BASE+24
WLAN_REASON_CODE_AUTO_AP_PROFILE_NOT_ALLOWED    equ     WLAN_REASON_CODE_PROFILE_BASE+25
WLAN_REASON_CODE_AUTO_CONNECTION_NOT_ALLOWED    equ     WLAN_REASON_CODE_PROFILE_BASE+26
WLAN_REASON_CODE_HOTSPOT2_PROFILE_NOT_ALLOWED   equ     WLAN_REASON_CODE_PROFILE_BASE+27

WLAN_REASON_CODE_UNSUPPORTED_SECURITY_SET_BY_OS equ     WLAN_REASON_CODE_MSM_BASE+1
WLAN_REASON_CODE_UNSUPPORTED_SECURITY_SET       equ     WLAN_REASON_CODE_MSM_BASE+2
WLAN_REASON_CODE_BSS_TYPE_UNMATCH               equ     WLAN_REASON_CODE_MSM_BASE+3
WLAN_REASON_CODE_PHY_TYPE_UNMATCH               equ     WLAN_REASON_CODE_MSM_BASE+4
WLAN_REASON_CODE_DATARATE_UNMATCH               equ     WLAN_REASON_CODE_MSM_BASE+5

WLAN_REASON_CODE_USER_CANCELLED                 equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+1
WLAN_REASON_CODE_ASSOCIATION_FAILURE            equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+2
WLAN_REASON_CODE_ASSOCIATION_TIMEOUT            equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+3
WLAN_REASON_CODE_PRE_SECURITY_FAILURE           equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+4
WLAN_REASON_CODE_START_SECURITY_FAILURE         equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+5
WLAN_REASON_CODE_SECURITY_FAILURE               equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+6
WLAN_REASON_CODE_SECURITY_TIMEOUT               equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+7
WLAN_REASON_CODE_ROAMING_FAILURE                equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+8
WLAN_REASON_CODE_ROAMING_SECURITY_FAILURE       equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+9
WLAN_REASON_CODE_ADHOC_SECURITY_FAILURE         equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+10
WLAN_REASON_CODE_DRIVER_DISCONNECTED            equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+11
WLAN_REASON_CODE_DRIVER_OPERATION_FAILURE       equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+12
WLAN_REASON_CODE_IHV_NOT_AVAILABLE              equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+13
WLAN_REASON_CODE_IHV_NOT_RESPONDING             equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+14
WLAN_REASON_CODE_DISCONNECT_TIMEOUT             equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+15
WLAN_REASON_CODE_INTERNAL_FAILURE               equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+16
WLAN_REASON_CODE_UI_REQUEST_TIMEOUT             equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+17
WLAN_REASON_CODE_TOO_MANY_SECURITY_ATTEMPTS     equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+18
WLAN_REASON_CODE_AP_STARTING_FAILURE            equ     WLAN_REASON_CODE_MSM_CONNECT_BASE+19

WLAN_REASON_CODE_MSMSEC_MIN                     equ     WLAN_REASON_CODE_MSMSEC_BASE

WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_KEY_INDEX equ   WLAN_REASON_CODE_MSMSEC_BASE+1
WLAN_REASON_CODE_MSMSEC_PROFILE_PSK_PRESENT     equ     WLAN_REASON_CODE_MSMSEC_BASE+2
WLAN_REASON_CODE_MSMSEC_PROFILE_KEY_LENGTH      equ     WLAN_REASON_CODE_MSMSEC_BASE+3
WLAN_REASON_CODE_MSMSEC_PROFILE_PSK_LENGTH      equ     WLAN_REASON_CODE_MSMSEC_BASE+4
WLAN_REASON_CODE_MSMSEC_PROFILE_NO_AUTH_CIPHER_SPECIFIED equ WLAN_REASON_CODE_MSMSEC_BASE+5
WLAN_REASON_CODE_MSMSEC_PROFILE_TOO_MANY_AUTH_CIPHER_SPECIFIED equ WLAN_REASON_CODE_MSMSEC_BASE+6
WLAN_REASON_CODE_MSMSEC_PROFILE_DUPLICATE_AUTH_CIPHER equ WLAN_REASON_CODE_MSMSEC_BASE+7
WLAN_REASON_CODE_MSMSEC_PROFILE_RAWDATA_INVALID equ     WLAN_REASON_CODE_MSMSEC_BASE+8
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_AUTH_CIPHER equ WLAN_REASON_CODE_MSMSEC_BASE+9
WLAN_REASON_CODE_MSMSEC_PROFILE_ONEX_DISABLED   equ     WLAN_REASON_CODE_MSMSEC_BASE+10
WLAN_REASON_CODE_MSMSEC_PROFILE_ONEX_ENABLED    equ     WLAN_REASON_CODE_MSMSEC_BASE+11
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PMKCACHE_MODE equ WLAN_REASON_CODE_MSMSEC_BASE+12
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PMKCACHE_SIZE equ WLAN_REASON_CODE_MSMSEC_BASE+13
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PMKCACHE_TTL equ WLAN_REASON_CODE_MSMSEC_BASE+14
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PREAUTH_MODE equ WLAN_REASON_CODE_MSMSEC_BASE+15
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PREAUTH_THROTTLE equ WLAN_REASON_CODE_MSMSEC_BASE+16
WLAN_REASON_CODE_MSMSEC_PROFILE_PREAUTH_ONLY_ENABLED equ WLAN_REASON_CODE_MSMSEC_BASE+17
WLAN_REASON_CODE_MSMSEC_CAPABILITY_NETWORK      equ     WLAN_REASON_CODE_MSMSEC_BASE+18
WLAN_REASON_CODE_MSMSEC_CAPABILITY_NIC          equ     WLAN_REASON_CODE_MSMSEC_BASE+19
WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE      equ     WLAN_REASON_CODE_MSMSEC_BASE+20
WLAN_REASON_CODE_MSMSEC_CAPABILITY_DISCOVERY    equ     WLAN_REASON_CODE_MSMSEC_BASE+21
WLAN_REASON_CODE_MSMSEC_PROFILE_PASSPHRASE_CHAR equ     WLAN_REASON_CODE_MSMSEC_BASE+22
WLAN_REASON_CODE_MSMSEC_PROFILE_KEYMATERIAL_CHAR      equ WLAN_REASON_CODE_MSMSEC_BASE+23
WLAN_REASON_CODE_MSMSEC_PROFILE_WRONG_KEYTYPE   equ     WLAN_REASON_CODE_MSMSEC_BASE+24
WLAN_REASON_CODE_MSMSEC_MIXED_CELL              equ     WLAN_REASON_CODE_MSMSEC_BASE+25
WLAN_REASON_CODE_MSMSEC_PROFILE_AUTH_TIMERS_INVALID equ WLAN_REASON_CODE_MSMSEC_BASE+26
WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_GKEY_INTV equ WLAN_REASON_CODE_MSMSEC_BASE+27
WLAN_REASON_CODE_MSMSEC_TRANSITION_NETWORK      equ     WLAN_REASON_CODE_MSMSEC_BASE+28
WLAN_REASON_CODE_MSMSEC_PROFILE_KEY_UNMAPPED_CHAR equ WLAN_REASON_CODE_MSMSEC_BASE+29
WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_AUTH equ     WLAN_REASON_CODE_MSMSEC_BASE+30
WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_CIPHER equ WLAN_REASON_CODE_MSMSEC_BASE+31
WLAN_REASON_CODE_MSMSEC_PROFILE_SAFE_MODE       equ     WLAN_REASON_CODE_MSMSEC_BASE+32
WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_SAFE_MODE_NIC equ WLAN_REASON_CODE_MSMSEC_BASE+33
WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_SAFE_MODE_NW equ WLAN_REASON_CODE_MSMSEC_BASE+34
WLAN_REASON_CODE_MSMSEC_PROFILE_UNSUPPORTED_AUTH equ    WLAN_REASON_CODE_MSMSEC_BASE+35
WLAN_REASON_CODE_MSMSEC_PROFILE_UNSUPPORTED_CIPHER equ WLAN_REASON_CODE_MSMSEC_BASE+36
WLAN_REASON_CODE_MSMSEC_CAPABILITY_MFP_NW_NIC   equ     WLAN_REASON_CODE_MSMSEC_BASE+37

WLAN_REASON_CODE_MSMSEC_UI_REQUEST_FAILURE      equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+1
WLAN_REASON_CODE_MSMSEC_AUTH_START_TIMEOUT      equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+2
WLAN_REASON_CODE_MSMSEC_AUTH_SUCCESS_TIMEOUT    equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+3
WLAN_REASON_CODE_MSMSEC_KEY_START_TIMEOUT       equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+4
WLAN_REASON_CODE_MSMSEC_KEY_SUCCESS_TIMEOUT     equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+5
WLAN_REASON_CODE_MSMSEC_M3_MISSING_KEY_DATA     equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+6
WLAN_REASON_CODE_MSMSEC_M3_MISSING_IE           equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+7
WLAN_REASON_CODE_MSMSEC_M3_MISSING_GRP_KEY      equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+8
WLAN_REASON_CODE_MSMSEC_PR_IE_MATCHING          equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+9
WLAN_REASON_CODE_MSMSEC_SEC_IE_MATCHING         equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+10
WLAN_REASON_CODE_MSMSEC_NO_PAIRWISE_KEY         equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+11
WLAN_REASON_CODE_MSMSEC_G1_MISSING_KEY_DATA     equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+12
WLAN_REASON_CODE_MSMSEC_G1_MISSING_GRP_KEY      equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+13
WLAN_REASON_CODE_MSMSEC_PEER_INDICATED_INSECURE equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+14
WLAN_REASON_CODE_MSMSEC_NO_AUTHENTICATOR        equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+15
WLAN_REASON_CODE_MSMSEC_NIC_FAILURE             equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+16
WLAN_REASON_CODE_MSMSEC_CANCELLED               equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+17
WLAN_REASON_CODE_MSMSEC_KEY_FORMAT              equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+18
WLAN_REASON_CODE_MSMSEC_DOWNGRADE_DETECTED      equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+19
WLAN_REASON_CODE_MSMSEC_PSK_MISMATCH_SUSPECTED  equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+20
WLAN_REASON_CODE_MSMSEC_FORCED_FAILURE          equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+21
WLAN_REASON_CODE_MSMSEC_M3_TOO_MANY_RSNIE       equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+22
WLAN_REASON_CODE_MSMSEC_M2_MISSING_KEY_DATA     equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+23
WLAN_REASON_CODE_MSMSEC_M2_MISSING_IE           equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+24
WLAN_REASON_CODE_MSMSEC_AUTH_WCN_COMPLETED      equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+25
WLAN_REASON_CODE_MSMSEC_M3_MISSING_MGMT_GRP_KEY equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+26
WLAN_REASON_CODE_MSMSEC_G1_MISSING_MGMT_GRP_KEY equ     WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+27

WLAN_REASON_CODE_MSMSEC_MAX                     equ     WLAN_REASON_CODE_MSMSEC_END

WLAN_CONNECTION_NOTIFICATION_ADHOC_NETWORK_FORMED equ  00000001H
WLAN_CONNECTION_NOTIFICATION_CONSOLE_USER_PROFILE equ  00000004H

wlan_notification_acm_start                      equ     0
wlan_notification_acm_autoconf_enabled           equ     1
wlan_notification_acm_autoconf_disabled          equ     2
wlan_notification_acm_background_scan_enabled    equ     3
wlan_notification_acm_background_scan_disabled   equ     4
wlan_notification_acm_bss_type_change            equ     5
wlan_notification_acm_power_setting_change       equ     6
wlan_notification_acm_scan_complete              equ     7
wlan_notification_acm_scan_fail                  equ     8
wlan_notification_acm_connection_start           equ     9
wlan_notification_acm_connection_complete        equ     10
wlan_notification_acm_connection_attempt_fail    equ     11
wlan_notification_acm_filter_list_change         equ     12
wlan_notification_acm_interface_arrival          equ     13
wlan_notification_acm_interface_removal          equ     14
wlan_notification_acm_profile_change             equ     15
wlan_notification_acm_profile_name_change        equ     16
wlan_notification_acm_profiles_exhausted         equ     17
wlan_notification_acm_network_not_available      equ     18
wlan_notification_acm_network_available          equ     19
wlan_notification_acm_disconnecting              equ     20
wlan_notification_acm_disconnected               equ     21
wlan_notification_acm_adhoc_network_state_change equ     22
wlan_notification_acm_profile_unblocked          equ     23
wlan_notification_acm_screen_power_change        equ     24
wlan_notification_acm_profile_blocked            equ     25
wlan_notification_acm_scan_list_refresh          equ     26
wlan_notification_acm_end                        equ     27

WLAN_NOTIFICATION_SOURCE_NONE                    equ     00000000H
WLAN_NOTIFICATION_SOURCE_ONEX                    equ     00000004H
WLAN_NOTIFICATION_SOURCE_ACM                     equ     00000008H
WLAN_NOTIFICATION_SOURCE_MSM                     equ     00000010H
WLAN_NOTIFICATION_SOURCE_SECURITY                equ     00000020H
WLAN_NOTIFICATION_SOURCE_IHV                     equ     00000040H
WLAN_NOTIFICATION_SOURCE_HNWK                    equ     00000080H
WLAN_NOTIFICATION_SOURCE_ALL                     equ     0000FFFFH

;======================================== Structures ======================================;
struc WLAN_NOTIFICATION_DATA
    NotificationSource      dd    ?
    NotificationCode        dd    ?
    InterfaceGuid           GUID  <?>
    dwDataSize              dd    ?
    pData                   xword ?
ends

struc DATALIST
    dwDataOffset            dd ?
    dwDataSize              dd ?
ends

struc WLAN_RAW_DATA_LIST
    dwTotalSize             dd ?
    dwNumberOfItems         dd ?
    __unnamed_struct_17d8_1 DATALIST <?>
ends

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib wlanapi.lib
#else
    from_dll wlanapi.dll
#endif

#ifdef APP_WIN64
    import QueryNetconStatus
    import QueryNetconVirtualCharacteristic
    import WFDAbortSessionInt
    import WFDAcceptConnectRequestAndOpenSessionInt
    import WFDAcceptGroupRequestAndOpenSessionInt
    import WFDCancelConnectorPairWithOOB
    import WFDCancelListenerPairWithOOB
    import WFDCancelOpenSession
    import WFDCancelOpenSessionInt
    import WFDCloseHandle
    import WFDCloseHandleInt
    import WFDCloseLegacySessionInt
    import WFDCloseOOBPairingSession
    import WFDCloseSession
    import WFDCloseSessionInt
    import WFDConfigureFirewallForSessionInt
    import WFDCreateDHPrivatePublicKeyPairInt
    import WFDDeclineConnectRequestInt
    import WFDDeclineGroupRequestInt
    import WFDDiscoverDevicesInt
    import WFDFlushVisibleDeviceListInt
    import WFDForceDisconnectInt
    import WFDForceDisconnectLegacyPeerInt
    import WFDFreeMemoryInt
    import WFDGetDefaultGroupProfileInt
    import WFDGetDeviceDescriptorForPendingRequestInt
    import WFDGetNFCCarrierConfigBlobInt
    import WFDGetOOBBlob
    import WFDGetProfileKeyInfoInt
    import WFDGetSessionEndpointPairsInt
    import WFDGetVisibleDevicesInt
    import WFDIsInterfaceWiFiDirect
    import WFDIsWiFiDirectRunningOnWiFiAdapter
    import WFDLowPrivCancelOpenSessionInt
    import WFDLowPrivCloseHandleInt
    import WFDLowPrivCloseLegacySessionInt
    import WFDLowPrivCloseSessionInt
    import WFDLowPrivConfigureFirewallForSessionInt
    import WFDLowPrivDeclineDeviceApiConnectionRequestInt
    import WFDLowPrivGetPendingGroupRequestDetailsInt
    import WFDLowPrivGetSessionEndpointPairsInt
    import WFDLowPrivIsWfdSupportedInt
    import WFDLowPrivOpenHandleInt
    import WFDLowPrivOpenLegacySessionInt
    import WFDLowPrivOpenSessionByDafObjectIdInt
    import WFDLowPrivQueryPropertyInt
    import WFDLowPrivRegisterNotificationInt
    import WFDLowPrivRegisterVMgrCallerInt
    import WFDLowPrivSetPropertyInt
    import WFDLowPrivStartDeviceApiConnectionRequestListenerInt
    import WFDLowPrivStartOpenSessionByInterfaceIdInt
    import WFDLowPrivStartUsingGroupInt
    import WFDLowPrivStopDeviceApiConnectionRequestListenerInt
    import WFDLowPrivStopUsingGroupInt
    import WFDLowPrivUnregisterVMgrCallerInt
    import WFDOpenHandle
    import WFDOpenHandleInt
    import WFDOpenLegacySession
    import WFDOpenLegacySessionInt
    import WFDPairCancelByDeviceAddressInt
    import WFDPairCancelInt
    import WFDPairContinuePairWithDeviceInt
    import WFDPairEnumerateCeremoniesInt
    import WFDPairSelectCeremonyInt
    import WFDPairWithDeviceAndOpenSessionExInt
    import WFDPairWithDeviceAndOpenSessionInt
    import WFDParseOOBBlob
    import WFDParseOOBBlobTypeAndGetPayloadInt
    import WFDParseProfileXmlInt
    import WFDParseWfaNfcCarrierConfigBlobInt
    import WFDQueryPropertyInt
    import WFDRegisterNotificationInt
    import WFDRegisterVMgrCallerInt
    import WFDSetAdditionalIEsInt
    import WFDSetPropertyInt
    import WFDSetSecondaryDeviceTypeListInt
    import WFDStartBackgroundDiscoveryInt
    import WFDStartConnectorPairWithOOB
    import WFDStartListenerPairWithOOB
    import WFDStartOffloadedDiscoveryInt
    import WFDStartOpenSession
    import WFDStartOpenSessionInt
    import WFDStartUsingGroupExInt
    import WFDStartUsingGroupInt
    import WFDStopBackgroundDiscoveryInt
    import WFDStopDiscoverDevicesInt
    import WFDStopOffloadedDiscoveryInt
    import WFDStopUsingGroupInt
    import WFDSvcLowPrivAcceptSessionInt
    import WFDSvcLowPrivCancelSessionInt
    import WFDSvcLowPrivCloseSessionInt
    import WFDSvcLowPrivConfigureSessionInt
    import WFDSvcLowPrivConnectSessionInt
    import WFDSvcLowPrivGetProvisioningInfoInt
    import WFDSvcLowPrivGetSessionEndpointPairsInt
    import WFDSvcLowPrivOpenAdvertiserSessionInt
    import WFDSvcLowPrivOpenSeekerSessionInt
    import WFDSvcLowPrivPublishServiceInt
    import WFDSvcLowPrivUnpublishServiceInt
    import WFDUnregisterVMgrCallerInt
    import WFDUpdateDeviceVisibility
    import WlanAllocateMemory
    import WlanCancelPlap
    import WlanCloseHandle
    import WlanConnect
    import WlanConnectEx
    import WlanConnectWithInput
    import WlanDeinitPlapParams
    import WlanDeleteProfile
    import WlanDisconnect
    import WlanDoesBssMatchSecurity
    import WlanDoPlap
    import WlanEnumAllInterfaces
    import WlanEnumInterfaces
    import WlanExtractPsdIEDataList
    import WlanFreeMemory
    import WlanGenerateProfileXmlBasicSettings
    import WlanGetAvailableNetworkList
    import WlanGetAvailableNetworkList2
    import WlanGetFilterList
    import WlanGetInterfaceCapability
    import WlanGetMFPNegotiated
    import WlanGetNetworkBssList
    import WlanGetProfile
    import WlanGetProfileCustomUserData
    import WlanGetProfileEapUserDataInfo
    import WlanGetProfileIndex
    import WlanGetProfileKeyInfo
    import WlanGetProfileList
    import WlanGetSecuritySettings
    import WlanGetStoredRadioState
    import WlanHostedNetworkForceStart
    import WlanHostedNetworkForceStop
    import WlanHostedNetworkFreeWCNSettings
    import WlanHostedNetworkHlpQueryEverUsed
    import WlanHostedNetworkInitSettings
    import WlanHostedNetworkQueryProperty
    import WlanHostedNetworkQuerySecondaryKey
    import WlanHostedNetworkQueryStatus
    import WlanHostedNetworkQueryWCNSettings
    import WlanHostedNetworkRefreshSecuritySettings
    import WlanHostedNetworkSetProperty
    import WlanHostedNetworkSetSecondaryKey
    import WlanHostedNetworkSetWCNSettings
    import WlanHostedNetworkStartUsing
    import WlanHostedNetworkStopUsing
    import WlanIhvControl
    import WlanInitPlapParams
    import WlanInternalScan
    import WlanIsActiveConsoleUser
    import WlanIsNetworkSuppressed
    import WlanIsUIRequestPending
    import WlanLowPrivCloseHandle
    import WlanLowPrivEnumInterfaces
    import WlanLowPrivFreeMemory
    import WlanLowPrivNotifyVsIeProviderInt
    import WlanLowPrivOpenHandle
    import WlanLowPrivQueryInterface
    import WlanLowPrivSetInterface
    import WlanNotifyVsIeProviderExInt
    import WlanNotifyVsIeProviderInt
    import WlanOpenHandle
    import WlanParseProfileXmlBasicSettings
    import WlanPrivateClearAnqpCache
    import WlanPrivateGetAnqpCacheResponse
    import WlanPrivateGetAvailableNetworkList
    import WlanPrivateParseAnqpRawData
    import WlanPrivateQueryInterface
    import WlanPrivateRefreshAnqpCache
    import WlanPrivateSetInterface
    import WlanQueryAutoConfigParameter
    import WlanQueryCreateAllUserProfileRestricted
    import WlanQueryInterface
    import WlanQueryPlapCredentials
    import WlanQueryPreConnectInput
    import WlanQueryVirtualInterfaceType
    import WlanReasonCodeToString
    import WlanRefreshConnections
    import WlanRegisterNotification
    import WlanRegisterVirtualStationNotification
    import WlanRemoveUIForwardingNetworkList
    import WlanRenameProfile
    import WlanSaveTemporaryProfile
    import WlanScan
    import WlanSendUIResponse
    import WlanSetAllUserProfileRestricted
    import WlanSetAutoConfigParameter
    import WlanSetFilterList
    import WlanSetInterface
    import WlanSetProfile
    import WlanSetProfileCustomUserData
    import WlanSetProfileEapUserData
    import WlanSetProfileEapXmlUserData
    import WlanSetProfileList
    import WlanSetProfileListForOffload
    import WlanSetProfileMetadata
    import WlanSetProfilePosition
    import WlanSetPsdIEDataList
    import WlanSetSecuritySettings
    import WlanSetUIForwardingNetworkList
    import WlanSignalValueToBar
    import WlanSsidToDisplayName
    import WlanStartAP
    import WlanStopAP
    import WlanStoreRadioStateOnEnteringAirPlaneMode
    import WlanStringToSsid
    import WlanStringToUtf8Ssid
    import WlanTryUpgradeCurrentConnectionAuthCipher
    import WlanUpdateBasicProfileSecurity
    import WlanUpdateProfileWithAuthCipher
    import WlanUtf8SsidToDisplayName
    import WlanVMgrQueryCurrentScenariosInt
    import WlanWcmDisconnect
    import WlanWcmGetInterface
    import WlanWcmGetProfileList
    import WlanWcmSetInterface
    import WlanWcmSetProfile
    import WlanWfdGetPeerInfo
    import WlanWfdGOSetWCNSettings
    import WlanWfdStartGO
    import WlanWfdStopGO
#else
    #if NTDDI_VERSION >= NTDDI_VISTA
        extern WlanAllocateMemory alias _WlanAllocateMemory@4
        extern WlanCloseHandle alias _WlanCloseHandle@8
        extern WlanConnect alias _WlanConnect@16
        extern WlanDeleteProfile alias _WlanDeleteProfile@16
        extern WlanDisconnect alias _WlanDisconnect@12
        extern WlanEnumInterfaces alias _WlanEnumInterfaces@12
        extern WlanExtractPsdIEDataList alias _WlanExtractPsdIEDataList@24
        extern WlanFreeMemory alias _WlanFreeMemory@4
        extern WlanGetAvailableNetworkList alias _WlanGetAvailableNetworkList@20
        extern WlanGetFilterList alias _WlanGetFilterList@16
        extern WlanGetInterfaceCapability alias _WlanGetInterfaceCapability@16
        extern WlanGetNetworkBssList alias _WlanGetNetworkBssList@28
        extern WlanGetProfile alias _WlanGetProfile@28
        extern WlanGetProfileCustomUserData alias _WlanGetProfileCustomUserData@24
        extern WlanGetProfileList alias _WlanGetProfileList@16
        extern WlanGetSecuritySettings alias _WlanGetSecuritySettings@20
        extern WlanIhvControl alias _WlanIhvControl@32
        extern WlanOpenHandle alias _WlanOpenHandle@16
        extern WlanQueryAutoConfigParameter alias _WlanQueryAutoConfigParameter@24
        extern WlanQueryInterface alias _WlanQueryInterface@28
        extern WlanReasonCodeToString alias _WlanReasonCodeToString@16
        extern WlanRegisterNotification alias _WlanRegisterNotification@28
        extern WlanRenameProfile alias _WlanRenameProfile@20
        extern WlanSaveTemporaryProfile alias _WlanSaveTemporaryProfile@28
        extern WlanScan alias _WlanScan@20
        extern WlanSetAutoConfigParameter alias _WlanSetAutoConfigParameter@20
        extern WlanSetFilterList alias _WlanSetFilterList@16
        extern WlanSetInterface alias _WlanSetInterface@24
        extern WlanSetProfile alias _WlanSetProfile@32
        extern WlanSetProfileCustomUserData alias _WlanSetProfileCustomUserData@24
        extern WlanSetProfileEapUserData alias _WlanSetProfileEapUserData@32
        extern WlanSetProfileEapXmlUserData alias _WlanSetProfileEapXmlUserData@24
        extern WlanSetProfileList alias _WlanSetProfileList@20
        extern WlanSetProfilePosition alias _WlanSetProfilePosition@20
        extern WlanSetPsdIEDataList alias _WlanSetPsdIEDataList@16
        extern WlanSetSecuritySettings alias _WlanSetSecuritySettings@12
    #endif
    #if NTDDI_VERSION >= NTDDI_WIN7
        extern WlanHostedNetworkForceStart alias _WlanHostedNetworkForceStart@12
        extern WlanHostedNetworkForceStop alias _WlanHostedNetworkForceStop@12
        extern WlanHostedNetworkInitSettings alias _WlanHostedNetworkInitSettings@12
        extern WlanHostedNetworkQueryProperty alias _WlanHostedNetworkQueryProperty@24
        extern WlanHostedNetworkQuerySecondaryKey alias _WlanHostedNetworkQuerySecondaryKey@28
        extern WlanHostedNetworkQueryStatus alias _WlanHostedNetworkQueryStatus@12
        extern WlanHostedNetworkRefreshSecuritySettings alias _WlanHostedNetworkRefreshSecuritySettings@12
        extern WlanHostedNetworkSetProperty alias _WlanHostedNetworkSetProperty@24
        extern WlanHostedNetworkSetSecondaryKey alias _WlanHostedNetworkSetSecondaryKey@28
        extern WlanHostedNetworkStartUsing alias _WlanHostedNetworkStartUsing@12
        extern WlanHostedNetworkStopUsing alias _WlanHostedNetworkStopUsing@12
        extern WlanRegisterVirtualStationNotification alias _WlanRegisterVirtualStationNotification@12
    #endif
    #if NTDDI_VERSION >= NTDDI_WIN8
        extern WFDCancelOpenSession alias _WFDCancelOpenSession@4
        extern WFDCloseHandle alias _WFDCloseHandle@4
        extern WFDCloseSession alias _WFDCloseSession@4
        extern WFDOpenHandle alias _WFDOpenHandle@12
        extern WFDOpenLegacySession alias _WFDOpenLegacySession@16
        extern WFDStartOpenSession alias _WFDStartOpenSession@20
        extern WFDUpdateDeviceVisibility alias _WFDUpdateDeviceVisibility@4
    #endif
#endif


;======================= Undocumented functions (unknown arguments) =======================;
#ifdef APP_WIN64
    #if NTDDI_VERSION >= NTDDI_WIN8
        import QueryNetconStatus
        import QueryNetconVirtualCharacteristic
        import WFDAcceptConnectRequestAndOpenSessionInt
        import WFDAcceptGroupRequestAndOpenSessionInt
        import WFDCancelConnectorPairWithOOB
        import WFDCancelListenerPairWithOOB
        import WFDCancelOpenSessionInt
        import WFDCloseHandleInt
        import WFDCloseLegacySessionInt
        import WFDCloseOOBPairingSession
        import WFDCloseSessionInt
        import WFDDeclineConnectRequestInt
        import WFDDeclineGroupRequestInt
        import WFDDiscoverDevicesInt
        import WFDFlushVisibleDeviceListInt
        import WFDForceDisconnectInt
        import WFDFreeMemoryInt
        import WFDGetDefaultGroupProfileInt
        import WFDGetOOBBlob
        import WFDGetProfileKeyInfoInt
        import WFDGetVisibleDevicesInt
        import WFDIsInterfaceWiFiDirect
        import WFDIsWiFiDirectRunningOnWiFiAdapter
        import WFDOpenHandleInt
        import WFDOpenLegacySessionInt
        import WFDPairCancelByDeviceAddressInt
        import WFDPairCancelInt
        import WFDPairEnumerateCeremoniesInt
        import WFDPairSelectCeremonyInt
        import WFDPairWithDeviceAndOpenSessionInt
        import WFDParseOOBBlob
        import WFDParseProfileXmlInt
        import WFDQueryPropertyInt
        import WFDRegisterNotificationInt
        import WFDSetAdditionalIEsInt
        import WFDSetPropertyInt
        import WFDSetSecondaryDeviceTypeListInt
        import WFDStartConnectorPairWithOOB
        import WFDStartListenerPairWithOOB
        import WFDStartOpenSessionInt
        import WFDStartUsingGroupInt
        import WFDStopUsingGroupInt
        import WlanCancelPlap
        import WlanConnectEx
        import WlanConnectWithInput
        import WlanDeinitPlapParams
        import WlanDoesBssMatchSecurity
        import WlanDoPlap
        import WlanEnumAllInterfaces
        import WlanGenerateProfileXmlBasicSettings
        import WlanGetMFPNegotiated
        import WlanGetProfileEapUserDataInfo
        import WlanGetProfileIndex
        import WlanGetProfileKeyInfo
        import WlanGetStoredRadioState
        import WlanHostedNetworkFreeWCNSettings
        import WlanHostedNetworkHlpQueryEverUsed
        import WlanHostedNetworkQueryWCNSettings
        import WlanHostedNetworkSetWCNSettings
        import WlanInitPlapParams
        import WlanInternalScan
        import WlanIsActiveConsoleUser
        import WlanIsNetworkSuppressed
        import WlanIsUIRequestPending
        import WlanLowPrivCloseHandle
        import WlanLowPrivEnumInterfaces
        import WlanLowPrivFreeMemory
        import WlanLowPrivOpenHandle
        import WlanLowPrivQueryInterface
        import WlanLowPrivSetInterface
        import WlanParseProfileXmlBasicSettings
        import WlanPrivateGetAvailableNetworkList
        import WlanQueryCreateAllUserProfileRestricted
        import WlanQueryPlapCredentials
        import WlanQueryPreConnectInput
        import WlanQueryVirtualInterfaceType
        import WlanRefreshConnections
        import WlanRemoveUIForwardingNetworkList
        import WlanSendUIResponse
        import WlanSetAllUserProfileRestricted
        import WlanSetProfileMetadata
        import WlanSignalValueToBar
        import WlanSsidToDisplayName
        import WlanStartAP
        import WlanStopAP
        import WlanStoreRadioStateOnEnteringAirPlaneMode
        import WlanStringToSsid
        import WlanWcmGetInterface
        import WlanWcmGetProfileList
        import WlanWcmSetInterface
        import WlanWfdGetPeerInfo
        import WlanWfdGOSetWCNSettings
        import WlanWfdStartGO
        import WlanWfdStopGO
    #endif
    #if NTDDI_VERSION >= NTDDI_WIN81
        import WFDConfigureFirewallForSessionInt
        import WFDForceDisconnectLegacyPeerInt
        import WFDGetSessionEndpointPairsInt
        import WFDLowPrivCancelOpenSessionInt
        import WFDLowPrivCloseHandleInt
        import WFDLowPrivCloseSessionInt
        import WFDLowPrivConfigureFirewallForSessionInt
        import WFDLowPrivGetSessionEndpointPairsInt
        import WFDLowPrivIsWfdSupportedInt
        import WFDLowPrivOpenHandleInt
        import WFDLowPrivRegisterNotificationInt
        import WFDLowPrivStartOpenSessionByInterfaceIdInt
        import WFDPairWithDeviceAndOpenSessionExInt
        import WFDStopDiscoverDevicesInt
        import WlanNotifyVsIeProviderInt
        import WlanTryUpgradeCurrentConnectionAuthCipher
        import WlanUpdateProfileWithAuthCipher
        import WlanUtf8SsidToDisplayName
    #endif
    #if NTDDI_VERSION >= NTDDI_WIN10
        import WFDAbortSessionInt
        import WFDCreateDHPrivatePublicKeyPairInt
        import WFDGetDeviceDescriptorForPendingRequestInt
        import WFDGetNFCCarrierConfigBlobInt
        import WFDLowPrivCloseLegacySessionInt
        import WFDLowPrivDeclineDeviceApiConnectionRequestInt
        import WFDLowPrivGetPendingGroupRequestDetailsInt
        import WFDLowPrivOpenLegacySessionInt
        import WFDLowPrivOpenSessionByDafObjectIdInt
        import WFDLowPrivQueryPropertyInt
        import WFDLowPrivRegisterVMgrCallerInt
        import WFDLowPrivSetPropertyInt
        import WFDLowPrivStartDeviceApiConnectionRequestListenerInt
        import WFDLowPrivStartUsingGroupInt
        import WFDLowPrivStopDeviceApiConnectionRequestListenerInt
        import WFDLowPrivStopUsingGroupInt
        import WFDLowPrivUnregisterVMgrCallerInt
        import WFDPairContinuePairWithDeviceInt
        import WFDParseOOBBlobTypeAndGetPayloadInt
        import WFDParseWfaNfcCarrierConfigBlobInt
        import WFDRegisterVMgrCallerInt
        import WFDStartBackgroundDiscoveryInt
        import WFDStartOffloadedDiscoveryInt
        import WFDStartUsingGroupExInt
        import WFDStopBackgroundDiscoveryInt
        import WFDStopOffloadedDiscoveryInt
        import WFDSvcLowPrivAcceptSessionInt
        import WFDSvcLowPrivCancelSessionInt
        import WFDSvcLowPrivCloseSessionInt
        import WFDSvcLowPrivConfigureSessionInt
        import WFDSvcLowPrivConnectSessionInt
        import WFDSvcLowPrivGetProvisioningInfoInt
        import WFDSvcLowPrivGetSessionEndpointPairsInt
        import WFDSvcLowPrivOpenAdvertiserSessionInt
        import WFDSvcLowPrivOpenSeekerSessionInt
        import WFDSvcLowPrivPublishServiceInt
        import WFDSvcLowPrivUnpublishServiceInt
        import WFDUnregisterVMgrCallerInt
        import WlanGetAvailableNetworkList2
        import WlanLowPrivNotifyVsIeProviderInt
        import WlanNotifyVsIeProviderExInt
        import WlanPrivateClearAnqpCache
        import WlanPrivateGetAnqpCacheResponse
        import WlanPrivateParseAnqpRawData
        import WlanPrivateQueryInterface
        import WlanPrivateRefreshAnqpCache
        import WlanPrivateSetInterface
        import WlanSetProfileListForOffload
        import WlanStringToUtf8Ssid
        import WlanUpdateBasicProfileSecurity
        import WlanVMgrQueryCurrentScenariosInt
        import WlanWcmDisconnect
        import WlanWcmSetProfile
    #endif
;else
;    #if NTDDI_VERSION >= NTDDI_WIN8
;        extern QueryNetconStatus alias _QueryNetconStatus@??
;        extern QueryNetconVirtualCharacteristic alias _QueryNetconVirtualCharacteristic@??
;        extern WFDAcceptConnectRequestAndOpenSessionInt alias _WFDAcceptConnectRequestAndOpenSessionInt@??
;        extern WFDAcceptGroupRequestAndOpenSessionInt alias _WFDAcceptGroupRequestAndOpenSessionInt@??
;        extern WFDCancelConnectorPairWithOOB alias _WFDCancelConnectorPairWithOOB@??
;        extern WFDCancelListenerPairWithOOB alias _WFDCancelListenerPairWithOOB@??
;        extern WFDCancelOpenSessionInt alias _WFDCancelOpenSessionInt@??
;        extern WFDCloseHandleInt alias _WFDCloseHandleInt@??
;        extern WFDCloseLegacySessionInt alias _WFDCloseLegacySessionInt@??
;        extern WFDCloseOOBPairingSession alias _WFDCloseOOBPairingSession@??
;        extern WFDCloseSessionInt alias _WFDCloseSessionInt@??
;        extern WFDDeclineConnectRequestInt alias _WFDDeclineConnectRequestInt@??
;        extern WFDDeclineGroupRequestInt alias _WFDDeclineGroupRequestInt@??
;        extern WFDDiscoverDevicesInt alias _WFDDiscoverDevicesInt@??
;        extern WFDFlushVisibleDeviceListInt alias _WFDFlushVisibleDeviceListInt@??
;        extern WFDForceDisconnectInt alias _WFDForceDisconnectInt@??
;        extern WFDFreeMemoryInt alias _WFDFreeMemoryInt@??
;        extern WFDGetDefaultGroupProfileInt alias _WFDGetDefaultGroupProfileInt@??
;        extern WFDGetOOBBlob alias _WFDGetOOBBlob@??
;        extern WFDGetProfileKeyInfoInt alias _WFDGetProfileKeyInfoInt@??
;        extern WFDGetVisibleDevicesInt alias _WFDGetVisibleDevicesInt@??
;        extern WFDIsInterfaceWiFiDirect alias _WFDIsInterfaceWiFiDirect@??
;        extern WFDIsWiFiDirectRunningOnWiFiAdapter alias _WFDIsWiFiDirectRunningOnWiFiAdapter@??
;        extern WFDOpenHandleInt alias _WFDOpenHandleInt@??
;        extern WFDOpenLegacySessionInt alias _WFDOpenLegacySessionInt@??
;        extern WFDPairCancelByDeviceAddressInt alias _WFDPairCancelByDeviceAddressInt@??
;        extern WFDPairCancelInt alias _WFDPairCancelInt@??
;        extern WFDPairEnumerateCeremoniesInt alias _WFDPairEnumerateCeremoniesInt@??
;        extern WFDPairSelectCeremonyInt alias _WFDPairSelectCeremonyInt@??
;        extern WFDPairWithDeviceAndOpenSessionInt alias _WFDPairWithDeviceAndOpenSessionInt@??
;        extern WFDParseOOBBlob alias _WFDParseOOBBlob@??
;        extern WFDParseProfileXmlInt alias _WFDParseProfileXmlInt@??
;        extern WFDQueryPropertyInt alias _WFDQueryPropertyInt@??
;        extern WFDRegisterNotificationInt alias _WFDRegisterNotificationInt@??
;        extern WFDSetAdditionalIEsInt alias _WFDSetAdditionalIEsInt@??
;        extern WFDSetPropertyInt alias _WFDSetPropertyInt@??
;        extern WFDSetSecondaryDeviceTypeListInt alias _WFDSetSecondaryDeviceTypeListInt@??
;        extern WFDStartConnectorPairWithOOB alias _WFDStartConnectorPairWithOOB@??
;        extern WFDStartListenerPairWithOOB alias _WFDStartListenerPairWithOOB@??
;        extern WFDStartOpenSessionInt alias _WFDStartOpenSessionInt@??
;        extern WFDStartUsingGroupInt alias _WFDStartUsingGroupInt@??
;        extern WFDStopUsingGroupInt alias _WFDStopUsingGroupInt@??
;        extern WlanCancelPlap alias _WlanCancelPlap@??
;        extern WlanConnectEx alias _WlanConnectEx@??
;        extern WlanConnectWithInput alias _WlanConnectWithInput@??
;        extern WlanDeinitPlapParams alias _WlanDeinitPlapParams@??
;        extern WlanDoesBssMatchSecurity alias _WlanDoesBssMatchSecurity@??
;        extern WlanDoPlap alias _WlanDoPlap@??
;        extern WlanEnumAllInterfaces alias _WlanEnumAllInterfaces@??
;        extern WlanGenerateProfileXmlBasicSettings alias _WlanGenerateProfileXmlBasicSettings@??
;        extern WlanGetMFPNegotiated alias _WlanGetMFPNegotiated@??
;        extern WlanGetProfileEapUserDataInfo alias _WlanGetProfileEapUserDataInfo@??
;        extern WlanGetProfileIndex alias _WlanGetProfileIndex@??
;        extern WlanGetProfileKeyInfo alias _WlanGetProfileKeyInfo@??
;        extern WlanGetStoredRadioState alias _WlanGetStoredRadioState@??
;        extern WlanHostedNetworkFreeWCNSettings alias _WlanHostedNetworkFreeWCNSettings@??
;        extern WlanHostedNetworkHlpQueryEverUsed alias _WlanHostedNetworkHlpQueryEverUsed@??
;        extern WlanHostedNetworkQueryWCNSettings alias _WlanHostedNetworkQueryWCNSettings@??
;        extern WlanHostedNetworkSetWCNSettings alias _WlanHostedNetworkSetWCNSettings@??
;        extern WlanInitPlapParams alias _WlanInitPlapParams@??
;        extern WlanInternalScan alias _WlanInternalScan@??
;        extern WlanIsActiveConsoleUser alias _WlanIsActiveConsoleUser@??
;        extern WlanIsNetworkSuppressed alias _WlanIsNetworkSuppressed@??
;        extern WlanIsUIRequestPending alias _WlanIsUIRequestPending@??
;        extern WlanLowPrivCloseHandle alias _WlanLowPrivCloseHandle@??
;        extern WlanLowPrivEnumInterfaces alias _WlanLowPrivEnumInterfaces@??
;        extern WlanLowPrivFreeMemory alias _WlanLowPrivFreeMemory@??
;        extern WlanLowPrivOpenHandle alias _WlanLowPrivOpenHandle@??
;        extern WlanLowPrivQueryInterface alias _WlanLowPrivQueryInterface@??
;        extern WlanLowPrivSetInterface alias _WlanLowPrivSetInterface@??
;        extern WlanParseProfileXmlBasicSettings alias _WlanParseProfileXmlBasicSettings@??
;        extern WlanPrivateGetAvailableNetworkList alias _WlanPrivateGetAvailableNetworkList@??
;        extern WlanQueryCreateAllUserProfileRestricted alias _WlanQueryCreateAllUserProfileRestricted@??
;        extern WlanQueryPlapCredentials alias _WlanQueryPlapCredentials@??
;        extern WlanQueryPreConnectInput alias _WlanQueryPreConnectInput@??
;        extern WlanQueryVirtualInterfaceType alias _WlanQueryVirtualInterfaceType@??
;        extern WlanRefreshConnections alias _WlanRefreshConnections@??
;        extern WlanRemoveUIForwardingNetworkList alias _WlanRemoveUIForwardingNetworkList@??
;        extern WlanSendUIResponse alias _WlanSendUIResponse@??
;        extern WlanSetAllUserProfileRestricted alias _WlanSetAllUserProfileRestricted@??
;        extern WlanSetProfileMetadata alias _WlanSetProfileMetadata@??
;        extern WlanSignalValueToBar alias _WlanSignalValueToBar@??
;        extern WlanSsidToDisplayName alias _WlanSsidToDisplayName@??
;        extern WlanStartAP alias _WlanStartAP@??
;        extern WlanStopAP alias _WlanStopAP@??
;        extern WlanStoreRadioStateOnEnteringAirPlaneMode alias _WlanStoreRadioStateOnEnteringAirPlaneMode@??
;        extern WlanStringToSsid alias _WlanStringToSsid@??
;        extern WlanWcmGetInterface alias _WlanWcmGetInterface@??
;        extern WlanWcmGetProfileList alias _WlanWcmGetProfileList@??
;        extern WlanWcmSetInterface alias _WlanWcmSetInterface@??
;        extern WlanWfdGetPeerInfo alias _WlanWfdGetPeerInfo@??
;        extern WlanWfdGOSetWCNSettings alias _WlanWfdGOSetWCNSettings@??
;        extern WlanWfdStartGO alias _WlanWfdStartGO@??
;        extern WlanWfdStopGO alias _WlanWfdStopGO@??
;    #endif
;    #if NTDDI_VERSION >= NTDDI_WIN81
;        extern WFDConfigureFirewallForSessionInt alias _WFDConfigureFirewallForSessionInt@??
;        extern WFDForceDisconnectLegacyPeerInt alias _WFDForceDisconnectLegacyPeerInt@??
;        extern WFDGetSessionEndpointPairsInt alias _WFDGetSessionEndpointPairsInt@??
;        extern WFDLowPrivCancelOpenSessionInt alias _WFDLowPrivCancelOpenSessionInt@??
;        extern WFDLowPrivCloseHandleInt alias _WFDLowPrivCloseHandleInt@??
;        extern WFDLowPrivCloseSessionInt alias _WFDLowPrivCloseSessionInt@??
;        extern WFDLowPrivConfigureFirewallForSessionInt alias _WFDLowPrivConfigureFirewallForSessionInt@??
;        extern WFDLowPrivGetSessionEndpointPairsInt alias _WFDLowPrivGetSessionEndpointPairsInt@??
;        extern WFDLowPrivIsWfdSupportedInt alias _WFDLowPrivIsWfdSupportedInt@??
;        extern WFDLowPrivOpenHandleInt alias _WFDLowPrivOpenHandleInt@??
;        extern WFDLowPrivRegisterNotificationInt alias _WFDLowPrivRegisterNotificationInt@??
;        extern WFDLowPrivStartOpenSessionByInterfaceIdInt alias _WFDLowPrivStartOpenSessionByInterfaceIdInt@??
;        extern WFDPairWithDeviceAndOpenSessionExInt alias _WFDPairWithDeviceAndOpenSessionExInt@??
;        extern WFDStopDiscoverDevicesInt alias _WFDStopDiscoverDevicesInt@??
;        extern WlanNotifyVsIeProviderInt alias _WlanNotifyVsIeProviderInt@??
;        extern WlanTryUpgradeCurrentConnectionAuthCipher alias _WlanTryUpgradeCurrentConnectionAuthCipher@??
;        extern WlanUpdateProfileWithAuthCipher alias _WlanUpdateProfileWithAuthCipher@??
;        extern WlanUtf8SsidToDisplayName alias _WlanUtf8SsidToDisplayName@??
;    #endif
;    #if NTDDI_VERSION >= NTDDI_WIN10
;        extern WFDAbortSessionInt alias _WFDAbortSessionInt@??
;        extern WFDCreateDHPrivatePublicKeyPairInt alias _WFDCreateDHPrivatePublicKeyPairInt@??
;        extern WFDGetDeviceDescriptorForPendingRequestInt alias _WFDGetDeviceDescriptorForPendingRequestInt@??
;        extern WFDGetNFCCarrierConfigBlobInt alias _WFDGetNFCCarrierConfigBlobInt@??
;        extern WFDLowPrivCloseLegacySessionInt alias _WFDLowPrivCloseLegacySessionInt@??
;        extern WFDLowPrivDeclineDeviceApiConnectionRequestInt alias _WFDLowPrivDeclineDeviceApiConnectionRequestInt@??
;        extern WFDLowPrivGetPendingGroupRequestDetailsInt alias _WFDLowPrivGetPendingGroupRequestDetailsInt@??
;        extern WFDLowPrivOpenLegacySessionInt alias _WFDLowPrivOpenLegacySessionInt@??
;        extern WFDLowPrivOpenSessionByDafObjectIdInt alias _WFDLowPrivOpenSessionByDafObjectIdInt@??
;        extern WFDLowPrivQueryPropertyInt alias _WFDLowPrivQueryPropertyInt@??
;        extern WFDLowPrivRegisterVMgrCallerInt alias _WFDLowPrivRegisterVMgrCallerInt@??
;        extern WFDLowPrivSetPropertyInt alias _WFDLowPrivSetPropertyInt@??
;        extern WFDLowPrivStartDeviceApiConnectionRequestListenerInt alias _WFDLowPrivStartDeviceApiConnectionRequestListenerInt@??
;        extern WFDLowPrivStartUsingGroupInt alias _WFDLowPrivStartUsingGroupInt@??
;        extern WFDLowPrivStopDeviceApiConnectionRequestListenerInt alias _WFDLowPrivStopDeviceApiConnectionRequestListenerInt@??
;        extern WFDLowPrivStopUsingGroupInt alias _WFDLowPrivStopUsingGroupInt@??
;        extern WFDLowPrivUnregisterVMgrCallerInt alias _WFDLowPrivUnregisterVMgrCallerInt@??
;        extern WFDPairContinuePairWithDeviceInt alias _WFDPairContinuePairWithDeviceInt@??
;        extern WFDParseOOBBlobTypeAndGetPayloadInt alias _WFDParseOOBBlobTypeAndGetPayloadInt@??
;        extern WFDParseWfaNfcCarrierConfigBlobInt alias _WFDParseWfaNfcCarrierConfigBlobInt@??
;        extern WFDRegisterVMgrCallerInt alias _WFDRegisterVMgrCallerInt@??
;        extern WFDStartBackgroundDiscoveryInt alias _WFDStartBackgroundDiscoveryInt@??
;        extern WFDStartOffloadedDiscoveryInt alias _WFDStartOffloadedDiscoveryInt@??
;        extern WFDStartUsingGroupExInt alias _WFDStartUsingGroupExInt@??
;        extern WFDStopBackgroundDiscoveryInt alias _WFDStopBackgroundDiscoveryInt@??
;        extern WFDStopOffloadedDiscoveryInt alias _WFDStopOffloadedDiscoveryInt@??
;        extern WFDSvcLowPrivAcceptSessionInt alias _WFDSvcLowPrivAcceptSessionInt@??
;        extern WFDSvcLowPrivCancelSessionInt alias _WFDSvcLowPrivCancelSessionInt@??
;        extern WFDSvcLowPrivCloseSessionInt alias _WFDSvcLowPrivCloseSessionInt@??
;        extern WFDSvcLowPrivConfigureSessionInt alias _WFDSvcLowPrivConfigureSessionInt@??
;        extern WFDSvcLowPrivConnectSessionInt alias _WFDSvcLowPrivConnectSessionInt@??
;        extern WFDSvcLowPrivGetProvisioningInfoInt alias _WFDSvcLowPrivGetProvisioningInfoInt@??
;        extern WFDSvcLowPrivGetSessionEndpointPairsInt alias _WFDSvcLowPrivGetSessionEndpointPairsInt@??
;        extern WFDSvcLowPrivOpenAdvertiserSessionInt alias _WFDSvcLowPrivOpenAdvertiserSessionInt@??
;        extern WFDSvcLowPrivOpenSeekerSessionInt alias _WFDSvcLowPrivOpenSeekerSessionInt@??
;        extern WFDSvcLowPrivPublishServiceInt alias _WFDSvcLowPrivPublishServiceInt@??
;        extern WFDSvcLowPrivUnpublishServiceInt alias _WFDSvcLowPrivUnpublishServiceInt@??
;        extern WFDUnregisterVMgrCallerInt alias _WFDUnregisterVMgrCallerInt@??
;        extern WlanGetAvailableNetworkList2 alias _WlanGetAvailableNetworkList2@??
;        extern WlanLowPrivNotifyVsIeProviderInt alias _WlanLowPrivNotifyVsIeProviderInt@??
;        extern WlanNotifyVsIeProviderExInt alias _WlanNotifyVsIeProviderExInt@??
;        extern WlanPrivateClearAnqpCache alias _WlanPrivateClearAnqpCache@??
;        extern WlanPrivateGetAnqpCacheResponse alias _WlanPrivateGetAnqpCacheResponse@??
;        extern WlanPrivateParseAnqpRawData alias _WlanPrivateParseAnqpRawData@??
;        extern WlanPrivateQueryInterface alias _WlanPrivateQueryInterface@??
;        extern WlanPrivateRefreshAnqpCache alias _WlanPrivateRefreshAnqpCache@??
;        extern WlanPrivateSetInterface alias _WlanPrivateSetInterface@??
;        extern WlanSetProfileListForOffload alias _WlanSetProfileListForOffload@??
;        extern WlanStringToUtf8Ssid alias _WlanStringToUtf8Ssid@??
;        extern WlanUpdateBasicProfileSecurity alias _WlanUpdateBasicProfileSecurity@??
;        extern WlanVMgrQueryCurrentScenariosInt alias _WlanVMgrQueryCurrentScenariosInt@??
;        extern WlanWcmDisconnect alias _WlanWcmDisconnect@??
;        extern WlanWcmSetProfile alias _WlanWcmSetProfile@??
;    #endif
#endif

#endif ;WLANAPI_INC
