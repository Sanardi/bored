; =========================================================;
;                                                          ;
;      rasapi32.inc for EC v2 SolAsm visual projects       ;
;                     (version 1.0.4)                      ;
;                                                          ;
;           Copyright � Ramon Sala - 2018-2019             ;
;                                                          ;
; =========================================================;

#ifndef RASAPI32_INC
RASAPI32_INC    equ 1

RASCS_PAUSED                                    equ     01000H
RASCS_DONE                                      equ     02000H

;RASCONNSTATE enumeration
RASCS_OpenPort                                  equ     0
RASCS_PortOpened                                equ     1
RASCS_ConnectDevice                             equ     2
RASCS_DeviceConnected                           equ     3
RASCS_AllDevicesConnected                       equ     4
RASCS_Authenticate                              equ     5
RASCS_AuthNotify                                equ     6
RASCS_AuthRetry                                 equ     7
RASCS_AuthCallback                              equ     8
RASCS_AuthChangePassword                        equ     9
RASCS_AuthProject                               equ     10
RASCS_AuthLinkSpeed                             equ     11
RASCS_AuthAck                                   equ     12
RASCS_ReAuthenticate                            equ     13
RASCS_Authenticated                             equ     14
RASCS_PrepareForCallback                        equ     15
RASCS_WaitForModemReset                         equ     16
RASCS_WaitForCallback                           equ     17
RASCS_Projected                                 equ     18
RASCS_StartAuthentication                       equ     19
RASCS_CallbackComplete                          equ     20
RASCS_LogonNetwork                              equ     21
RASCS_SubEntryConnected                         equ     22
RASCS_SubEntryDisconnected                      equ     23
RASCS_Interactive                               equ     <RASCS_PAUSED+1>
RASCS_RetryAuthentication                       equ     <RASCS_PAUSED+2>
RASCS_CallbackSetByCaller                       equ     <RASCS_PAUSED+3>
RASCS_PasswordExpired                           equ     <RASCS_PAUSED+4>
RASCS_Connected                                 equ     RASCS_DONE
RASCS_Disconnected                              equ     <RASCS_DONE+1>

RDEOPT_UsePrefixSuffix                          equ     00000001H
RDEOPT_PausedStates                             equ     00000002H
RDEOPT_IgnoreModemSpeaker                       equ     00000004H
RDEOPT_SetModemSpeaker                          equ     00000008H
RDEOPT_IgnoreSoftwareCompression                equ     00000010H
RDEOPT_SetSoftwareCompression                   equ     00000020H
RDEOPT_DisableConnectedUI                       equ     00000040H
RDEOPT_DisableReconnectUI                       equ     00000080H
RDEOPT_DisableReconnect                         equ     00000100H
RDEOPT_NoUser                                   equ     00000200H
RDEOPT_PauseOnScript                            equ     00000400H

;RASDIALEVENT                                    db     'RasDialEvent',0
WM_RASDIALEVENT                                 equ     0CCCDH

RASEO_UseCountryAndAreaCodes                    equ     00000001H
RASEO_SpecificIpAddr                            equ     00000002H
RASEO_SpecificNameServers                       equ     00000004H
RASEO_IpHeaderCompression                       equ     00000008H
RASEO_RemoteDefaultGateway                      equ     00000010H
RASEO_DisableLcpExtensions                      equ     00000020H
RASEO_TerminalBeforeDial                        equ     00000040H
RASEO_TerminalAfterDial                         equ     00000080H
RASEO_ModemLights                               equ     00000100H
RASEO_SwCompression                             equ     00000200H
RASEO_RequireEncryptedPw                        equ     00000400H
RASEO_RequireMsEncryptedPw                      equ     00000800H
RASEO_RequireDataEncryption                     equ     00001000H
RASEO_NetworkLogon                              equ     00002000H
RASEO_UseLogonCredentials                       equ     00004000H
RASEO_PromoteAlternates                         equ     00008000H
RASEO_SecureLocalFiles                          equ     00010000H

RASNP_NetBEUI                                   equ     00000001H
RASNP_Ipx                                       equ     00000002H
RASNP_Ip                                        equ     00000004H

RASFP_Ppp                                       equ     00000001H
RASFP_Slip                                      equ     00000002H
RASFP_Ras                                       equ     00000004H

;RASDT_Modem                                     db      'modem',0
;RASDT_Isdn                                      db      'isdn',0
;RASDT_X25                                       db      'x25',0

RASCN_Connection                                equ     00000001H
RASCN_Disconnection                             equ     00000002H
RASCN_BandwidthAdded                            equ     00000004H
RASCN_BandwidthRemoved                          equ     00000008H

RASEDM_DialAll                                  equ     1
RASEDM_DialAsNeeded                             equ     2

RASIDS_Disabled                                 equ     0FFFFFFFFH
RASIDS_UseGlobalValue                           equ     0

RASADFLG_PositionDlg                            equ     00000001H

RASCM_UserName                                  equ     00000001H
RASCM_Password                                  equ     00000002H
RASCM_Domain                                    equ     00000004H

RASADP_DisableConnectionQuery                   equ     0
RASADP_LoginSessionDisable                      equ     1
RASADP_SavedAddressesLimit                      equ     2
RASADP_FailedConnectionTimeout                  equ     3
RASADP_ConnectionQueryTimeout                   equ     4

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib rasapi32.lib
#else
    from_dll rasapi32.dll
#endif

#ifdef APP_WIN64
    import DDMGetPhonebookInfo
    import DwCloneEntry
    import DwDeleteSubEntry
    import DwEnumEntriesForAllUsers
    import DwEnumEntryDetails
    import DwRasRefreshKerbScCreds
    import DwRasUninitialize
    import RasAutoDialSharedConnection
    import RasAutodialAddressToNetwork
    import RasAutodialEntryToNetwork
    import RasClearConnectionStatistics
    import RasClearLinkStatistics
    import RasConnectionNotificationA
    import RasConnectionNotificationW
    import RasCreatePhonebookEntryA
    import RasCreatePhonebookEntryW
    import RasDeleteEntryA
    import RasDeleteEntryW
    import RasDeleteSubEntryA
    import RasDeleteSubEntryW
    import RasDialA
    import RasDialW
    import RasDialWow
    import RasEditPhonebookEntryA
    import RasEditPhonebookEntryW
    import RasEnumAutodialAddressesA
    import RasEnumAutodialAddressesW
    import RasEnumConnectionsA
    import RasEnumConnectionsW
    import RasEnumConnectionsWow
    import RasEnumDevicesA
    import RasEnumDevicesW
    import RasEnumEntriesA
    import RasEnumEntriesW
    import RasEnumEntriesWow
    import RasFreeEapUserIdentityA
    import RasFreeEapUserIdentityW
    import RasGetAutodialAddressA
    import RasGetAutodialAddressW
    import RasGetAutodialEnableA
    import RasGetAutodialEnableW
    import RasGetAutodialParamA
    import RasGetAutodialParamW
    import RasGetConnectResponse
    import RasGetConnectStatusA
    import RasGetConnectStatusW
    import RasGetConnectStatusWow
    import RasGetConnectionStatistics
    import RasGetCountryInfoA
    import RasGetCountryInfoW
    import RasGetCredentialsA
    import RasGetCredentialsW
    import RasGetCustomAuthDataA
    import RasGetCustomAuthDataW
    import RasGetEapUserDataA
    import RasGetEapUserDataW
    import RasGetEapUserIdentityA
    import RasGetEapUserIdentityW
    import RasGetEntryDialParamsA
    import RasGetEntryDialParamsW
    import RasGetEntryHrasconnA
    import RasGetEntryHrasconnW
    import RasGetEntryPropertiesA
    import RasGetEntryPropertiesW
    import RasGetErrorStringA
    import RasGetErrorStringW
    import RasGetErrorStringWow
    import RasGetHport
    import RasGetLinkStatistics
    import RasGetProjectionInfoA
    import RasGetProjectionInfoW
    import RasGetSubEntryHandleA
    import RasGetSubEntryHandleW
    import RasGetSubEntryPropertiesA
    import RasGetSubEntryPropertiesW
    import RasHangUpA
    import RasHangUpW
    import RasHangUpWow
    import RasInvokeEapUI
    import RasIsRouterConnection
    import RasIsSharedConnection
    import RasQueryRedialOnLinkFailure
    import RasQuerySharedAutoDial
    import RasQuerySharedConnection
    import RasRenameEntryA
    import RasRenameEntryW
    import RasScriptExecute
    import RasScriptGetEventCode
    import RasScriptGetIpAddress
    #if NTDDI_VERSION < NTDDI_WIN10
        import RasScriptInit
        import RasScriptReceive
        import RasScriptSend
        import RasScriptTerm
    #endif
    import RasSetAutodialAddressA
    import RasSetAutodialAddressW
    import RasSetAutodialEnableA
    import RasSetAutodialEnableW
    import RasSetAutodialParamA
    import RasSetAutodialParamW
    import RasSetCredentialsA
    import RasSetCredentialsW
    import RasSetCustomAuthDataA
    import RasSetCustomAuthDataW
    import RasSetEapUserDataA
    import RasSetEapUserDataW
    import RasSetEntryDialParamsA
    import RasSetEntryDialParamsW
    import RasSetEntryPropertiesA
    import RasSetEntryPropertiesW
    import RasSetOldPassword
    import RasSetSharedAutoDial
    import RasSetSubEntryPropertiesA
    import RasSetSubEntryPropertiesW
    import RasValidateEntryNameA
    import RasValidateEntryNameW
    import RasfileClose
    import RasfileDeleteLine
    import RasfileFindFirstLine
    import RasfileFindLastLine
    import RasfileFindMarkedLine
    import RasfileFindNextKeyLine
    import RasfileFindNextLine
    import RasfileFindPrevLine
    import RasfileFindSectionLine
    import RasfileGetKeyValueFields
    import RasfileGetLine
    import RasfileGetLineMark
    import RasfileGetLineText
    import RasfileGetLineType
    import RasfileGetSectionName
    import RasfileInsertLine
    import RasfileLoad
    import RasfileLoadInfo
    import RasfilePutKeyValueFields
    import RasfilePutLineMark
    import RasfilePutLineText
    import RasfilePutSectionName
    import RasfileWrite
    import SharedAccessResponseListToString
    import SharedAccessResponseStringToList
    import UnInitializeRAS
#else
    extern DDMGetPhonebookInfo alias _DDMGetPhonebookInfo@32
    extern DwCloneEntry alias _DwCloneEntry@12
    extern DwEnumEntryDetails alias _DwEnumEntryDetails@16
    extern DwRasUninitialize alias _DwRasUninitialize@0
    extern RasAutoDialSharedConnection alias _RasAutoDialSharedConnection@0
    extern RasAutodialAddressToNetwork alias _RasAutodialAddressToNetwork@12
    extern RasAutodialEntryToNetwork alias _RasAutodialEntryToNetwork@12
    extern RasClearConnectionStatistics alias _RasClearConnectionStatistics@4
    extern RasClearLinkStatistics alias _RasClearLinkStatistics@8
    extern RasConnectionNotificationA alias _RasConnectionNotificationA@12
    extern RasConnectionNotificationW alias _RasConnectionNotificationW@12
    extern RasCreatePhonebookEntryA alias _RasCreatePhonebookEntryA@8
    extern RasCreatePhonebookEntryW alias _RasCreatePhonebookEntryW@8
    extern RasDeleteEntryA alias _RasDeleteEntryA@8
    extern RasDeleteEntryW alias _RasDeleteEntryW@8
    extern RasDeleteSubEntryA alias _RasDeleteSubEntryA@12
    extern RasDeleteSubEntryW alias _RasDeleteSubEntryW@12
    extern RasDialA alias _RasDialA@24
    extern RasDialW alias _RasDialW@24
    extern RasEditPhonebookEntryA alias _RasEditPhonebookEntryA@12
    extern RasEditPhonebookEntryW alias _RasEditPhonebookEntryW@12
    extern RasEnumAutodialAddressesA alias _RasEnumAutodialAddressesA@12
    extern RasEnumAutodialAddressesW alias _RasEnumAutodialAddressesW@12
    extern RasEnumConnectionsA alias _RasEnumConnectionsA@12
    extern RasEnumConnectionsW alias _RasEnumConnectionsW@12
    extern RasEnumDevicesA alias _RasEnumDevicesA@12
    extern RasEnumDevicesW alias _RasEnumDevicesW@12
    extern RasEnumEntriesA alias _RasEnumEntriesA@20
    extern RasEnumEntriesW alias _RasEnumEntriesW@20
    extern RasFreeEapUserIdentityA alias _RasFreeEapUserIdentityA@4
    extern RasFreeEapUserIdentityW alias _RasFreeEapUserIdentityW@4
    extern RasGetAutodialAddressA alias _RasGetAutodialAddressA@20
    extern RasGetAutodialAddressW alias _RasGetAutodialAddressW@20
    extern RasGetAutodialEnableA alias _RasGetAutodialEnableA@8
    extern RasGetAutodialEnableW alias _RasGetAutodialEnableW@8
    extern RasGetAutodialParamA alias _RasGetAutodialParamA@12
    extern RasGetAutodialParamW alias _RasGetAutodialParamW@12
    extern RasGetConnectStatusA alias _RasGetConnectStatusA@8
    extern RasGetConnectStatusW alias _RasGetConnectStatusW@8
    extern RasGetConnectionStatistics alias _RasGetConnectionStatistics@8
    extern RasGetCountryInfoA alias _RasGetCountryInfoA@8
    extern RasGetCountryInfoW alias _RasGetCountryInfoW@8
    extern RasGetCredentialsA alias _RasGetCredentialsA@12
    extern RasGetCredentialsW alias _RasGetCredentialsW@12
    extern RasGetCustomAuthDataA alias _RasGetCustomAuthDataA@16
    extern RasGetCustomAuthDataW alias _RasGetCustomAuthDataW@16
    extern RasGetEapUserDataA alias _RasGetEapUserDataA@20
    extern RasGetEapUserDataW alias _RasGetEapUserDataW@20
    extern RasGetEapUserIdentityA alias _RasGetEapUserIdentityA@20
    extern RasGetEapUserIdentityW alias _RasGetEapUserIdentityW@20
    extern RasGetEntryDialParamsA alias _RasGetEntryDialParamsA@12
    extern RasGetEntryDialParamsW alias _RasGetEntryDialParamsW@12
    extern RasGetEntryHrasconnW alias _RasGetEntryHrasconnW@12
    extern RasGetEntryPropertiesA alias _RasGetEntryPropertiesA@24
    extern RasGetEntryPropertiesW alias _RasGetEntryPropertiesW@24
    extern RasGetErrorStringA alias _RasGetErrorStringA@12
    extern RasGetErrorStringW alias _RasGetErrorStringW@12
    extern RasGetHport alias _RasGetHport@4
    extern RasGetLinkStatistics alias _RasGetLinkStatistics@12
    extern RasGetProjectionInfoA alias _RasGetProjectionInfoA@16
    extern RasGetProjectionInfoW alias _RasGetProjectionInfoW@16
    extern RasGetSubEntryHandleA alias _RasGetSubEntryHandleA@12
    extern RasGetSubEntryHandleW alias _RasGetSubEntryHandleW@12
    extern RasGetSubEntryPropertiesA alias _RasGetSubEntryPropertiesA@28
    extern RasGetSubEntryPropertiesW alias _RasGetSubEntryPropertiesW@28
    extern RasHangUpA alias _RasHangUpA@4
    extern RasHangUpW alias _RasHangUpW@4
    extern RasInvokeEapUI alias _RasInvokeEapUI@16
    extern RasIsSharedConnection alias _RasIsSharedConnection@8
    extern RasQueryRedialOnLinkFailure alias _RasQueryRedialOnLinkFailure@12
    extern RasQuerySharedAutoDial alias _RasQuerySharedAutoDial@4
    extern RasQuerySharedConnection alias _RasQuerySharedConnection@4
    extern RasRenameEntryA alias _RasRenameEntryA@12
    extern RasRenameEntryW alias _RasRenameEntryW@12
    extern RasSetAutodialAddressA alias _RasSetAutodialAddressA@20
    extern RasSetAutodialAddressW alias _RasSetAutodialAddressW@20
    extern RasSetAutodialEnableA alias _RasSetAutodialEnableA@8
    extern RasSetAutodialEnableW alias _RasSetAutodialEnableW@8
    extern RasSetAutodialParamA alias _RasSetAutodialParamA@12
    extern RasSetAutodialParamW alias _RasSetAutodialParamW@12
    extern RasSetCredentialsA alias _RasSetCredentialsA@16
    extern RasSetCredentialsW alias _RasSetCredentialsW@16
    extern RasSetCustomAuthDataA alias _RasSetCustomAuthDataA@16
    extern RasSetCustomAuthDataW alias _RasSetCustomAuthDataW@16
    extern RasSetEapUserDataA alias _RasSetEapUserDataA@20
    extern RasSetEapUserDataW alias _RasSetEapUserDataW@20
    extern RasSetEntryDialParamsA alias _RasSetEntryDialParamsA@12
    extern RasSetEntryDialParamsW alias _RasSetEntryDialParamsW@12
    extern RasSetEntryPropertiesA alias _RasSetEntryPropertiesA@24
    extern RasSetEntryPropertiesW alias _RasSetEntryPropertiesW@24
    extern RasSetOldPassword alias _RasSetOldPassword@8
    extern RasSetSharedAutoDial alias _RasSetSharedAutoDial@4
    extern RasSetSubEntryPropertiesA alias _RasSetSubEntryPropertiesA@28
    extern RasSetSubEntryPropertiesW alias _RasSetSubEntryPropertiesW@28
    extern RasValidateEntryNameA alias _RasValidateEntryNameA@8
    extern RasValidateEntryNameW alias _RasValidateEntryNameW@8
    extern UnInitializeRAS alias _UnInitializeRAS@0
#endif

#ifdef APP_UNICODE
    define RasConnectionNotification RasConnectionNotificationW
    define RasCreatePhonebookEntry RasCreatePhonebookEntryW
    define RasDeleteEntry RasDeleteEntryW
    define RasDeleteSubEntry RasDeleteSubEntryW
    define RasDial RasDialW
    define RasEditPhonebookEntry RasEditPhonebookEntryW
    define RasEnumAutodialAddresses RasEnumAutodialAddressesW
    define RasEnumConnections RasEnumConnectionsW
    define RasEnumDevices RasEnumDevicesW
    define RasEnumEntries RasEnumEntriesW
    define RasFreeEapUserIdentity RasFreeEapUserIdentityW
    define RasGetAutodialAddress RasGetAutodialAddressW
    define RasGetAutodialEnable RasGetAutodialEnableW
    define RasGetAutodialParam RasGetAutodialParamW
    define RasGetConnectStatus RasGetConnectStatusW
    define RasGetCountryInfo RasGetCountryInfoW
    define RasGetCredentials RasGetCredentialsW
    define RasGetCustomAuthData RasGetCustomAuthDataW
    define RasGetEapUserData RasGetEapUserDataW
    define RasGetEapUserIdentity RasGetEapUserIdentityW
    define RasGetEntryDialParams RasGetEntryDialParamsW
    define RasGetEntryHrasconn RasGetEntryHrasconnW
    define RasGetEntryProperties RasGetEntryPropertiesW
    define RasGetErrorString RasGetErrorStringW
    define RasGetProjectionInfo RasGetProjectionInfoW
    define RasGetSubEntryHandle RasGetSubEntryHandleW
    define RasGetSubEntryProperties RasGetSubEntryPropertiesW
    define RasHangUp RasHangUpW
    define RasRenameEntry RasRenameEntryW
    define RasSetAutodialAddress RasSetAutodialAddressW
    define RasSetAutodialEnable RasSetAutodialEnableW
    define RasSetAutodialParam RasSetAutodialParamW
    define RasSetCredentials RasSetCredentialsW
    define RasSetCustomAuthData RasSetCustomAuthDataW
    define RasSetEapUserData RasSetEapUserDataW
    define RasSetEntryDialParams RasSetEntryDialParamsW
    define RasSetEntryProperties RasSetEntryPropertiesW
    define RasSetSubEntryProperties RasSetSubEntryPropertiesW
    define RasValidateEntryName RasValidateEntryNameW
#else
    define RasConnectionNotification RasConnectionNotificationA
    define RasCreatePhonebookEntry RasCreatePhonebookEntryA
    define RasDeleteEntry RasDeleteEntryA
    define RasDeleteSubEntry RasDeleteSubEntryA
    define RasDial RasDialA
    define RasEditPhonebookEntry RasEditPhonebookEntryA
    define RasEnumAutodialAddresses RasEnumAutodialAddressesA
    define RasEnumConnections RasEnumConnectionsA
    define RasEnumDevices RasEnumDevicesA
    define RasEnumEntries RasEnumEntriesA
    define RasFreeEapUserIdentity RasFreeEapUserIdentityA
    define RasGetAutodialAddress RasGetAutodialAddressA
    define RasGetAutodialEnable RasGetAutodialEnableA
    define RasGetAutodialParam RasGetAutodialParamA
    define RasGetConnectStatus RasGetConnectStatusA
    define RasGetCountryInfo RasGetCountryInfoA
    define RasGetCredentials RasGetCredentialsA
    define RasGetCustomAuthData RasGetCustomAuthDataA
    define RasGetEapUserData RasGetEapUserDataA
    define RasGetEapUserIdentity RasGetEapUserIdentityA
    define RasGetEntryDialParams RasGetEntryDialParamsA
    define RasGetEntryHrasconn RasGetEntryHrasconnA
    define RasGetEntryProperties RasGetEntryPropertiesA
    define RasGetErrorString RasGetErrorStringA
    define RasGetProjectionInfo RasGetProjectionInfoA
    define RasGetSubEntryHandle RasGetSubEntryHandleA
    define RasGetSubEntryProperties RasGetSubEntryPropertiesA
    define RasHangUp RasHangUpA
    define RasRenameEntry RasRenameEntryA
    define RasSetAutodialAddress RasSetAutodialAddressA
    define RasSetAutodialEnable RasSetAutodialEnableA
    define RasSetAutodialParam RasSetAutodialParamA
    define RasSetCredentials RasSetCredentialsA
    define RasSetCustomAuthData RasSetCustomAuthDataA
    define RasSetEapUserData RasSetEapUserDataA
    define RasSetEntryDialParams RasSetEntryDialParamsA
    define RasSetEntryProperties RasSetEntryPropertiesA
    define RasSetSubEntryProperties RasSetSubEntryPropertiesA
    define RasValidateEntryName RasValidateEntryNameA
#endif


;======================= Undocumented functions (unknown arguments) =======================;
;import DDMComputeLuid
;import DDMFreeDialingParam
;import DDMFreeRemoteEndpoint
;import DDMFreeRemoteEndpointV2
;import DDMGetAddressesFromPhonebook
;import DDMGetAddressesFromPhonebookV2
;import DDMGetEapInfo
;import DDMGetEapUserIdentityW
;import DDMGetPhoneBookContext
;import DDMGetPhonebookInfoV2
;import DDMGetProtocolStartParams
;import DDMGetRasDialParams
;import DDMGetRasDialingParams
;import DDMGetTunnelEndpoints
;import DDMRasPbkEntryCleanup
;import DDMUpdateProtocolConfigInfoFromEntry
;import DwEnumEntryDetailsEx
;import GetAutoTriggerProfileInfo
;import IsActiveAutoTriggerConnection
;import LaunchVanUIW
;import RasCompleteDialMachineCleanup
;import RasConfigUserProxySettingsW
;import RasFreeEntryAdvancedProperties
;import RasGetAutoTriggerConnectStatus
;import RasGetConnectionErrorStringW
;import RasGetEntryAdvancedProperties
;import RasGetPbkPath
;import RasHandleTriggerConnDisconnect
;import RasRegisterEntryChangeNotification
;import RasSetAutoTriggerProfile
;import RasSetEapUserDataAEx
;import RasSetEapUserDataWEx
;import RasSetEntryAdvancedProperties
;import RasSetPerConnectionProxy
;import RasTriggerConnection
;import RasTriggerConnectionEx
;import RasTriggerDisconnection
;import RasTriggerDisconnectionEx
;import RasUnregisterEntryChangeNotification

;#ifdef APP_UNICODE
;    define RasSetEapUserDataEx RasSetEapUserDataWEx
;#else
;    define RasSetEapUserDataEx RasSetEapUserDataAEx
;#endif

#endif ;RASAPI32_INC
