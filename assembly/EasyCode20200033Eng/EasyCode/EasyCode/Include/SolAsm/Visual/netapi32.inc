; ====================================================;
;                                                     ;
;    netapi32.inc for EC v2 SolAsm visual projects    ;
;                   (version 1.0.0)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2019            ;
;                                                     ;
; ====================================================;

#ifndef NETAPI32_INC
NETAPI32_INC equ 1

USE_LOCAL_PARMNUM                               equ     1
USE_REMOTE_PARMNUM                              equ     2
USE_PASSWORD_PARMNUM                            equ     3
USE_ASGTYPE_PARMNUM                             equ     4
USE_USERNAME_PARMNUM                            equ     5
USE_DOMAINNAME_PARMNUM                          equ     6

USE_OK                                          equ     0
USE_PAUSED                                      equ     1
USE_SESSLOST                                    equ     2
USE_DISCONN                                     equ     2
USE_NETERR                                      equ     3
USE_CONN                                        equ     4
USE_RECONN                                      equ     5

USE_WILDCARD                                    equ     (-1)
USE_DISKDEV                                     equ     0
USE_SPOOLDEV                                    equ     1
USE_CHARDEV                                     equ     2
USE_IPC                                         equ     3

CREATE_NO_CONNECT                               equ     1
CREATE_BYPASS_CSC                               equ     2

USE_NOFORCE                                     equ     0
USE_FORCE                                       equ     1
USE_LOTS_OF_FORCE                               equ     2

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib netapi32.lib
#else
    from_dll netapi32.dll
#endif

#ifdef APP_WIN64
    import DsAddressToSiteNamesA
    import DsAddressToSiteNamesExA
    import DsAddressToSiteNamesExW
    import DsAddressToSiteNamesW
    import DsDeregisterDnsHostRecordsA
    import DsDeregisterDnsHostRecordsW
    import DsEnumerateDomainTrustsA
    import DsEnumerateDomainTrustsW
    import DsGetDcCloseW
    import DsGetDcNameA
    import DsGetDcNameW
    import DsGetDcNameWithAccountA
    import DsGetDcNameWithAccountW
    import DsGetDcNextA
    import DsGetDcNextW
    import DsGetDcOpenA
    import DsGetDcOpenW
    import DsGetDcSiteCoverageA
    import DsGetDcSiteCoverageW
    import DsGetForestTrustInformationW
    import DsGetSiteNameA
    import DsGetSiteNameW
    import DsMergeForestTrustInformationW
    import DsRoleAbortDownlevelServerUpgrade
    import DsRoleCancel
    import DsRoleDcAsDc
    import DsRoleDcAsReplica
    import DsRoleDemoteDc
    import DsRoleDnsNameToFlatName
    import DsRoleFreeMemory
    import DsRoleGetDatabaseFacts
    import DsRoleGetDcOperationProgress
    import DsRoleGetDcOperationResults
    import DsRoleGetPrimaryDomainInformation
    import DsRoleIfmHandleFree
    import DsRoleServerSaveStateForUpgrade
    import DsRoleUpgradeDownlevelServer
    import DsValidateSubnetNameA
    import DsValidateSubnetNameW
    import I_BrowserDebugCall
    import I_BrowserDebugTrace
    import I_BrowserQueryEmulatedDomains
    import I_BrowserQueryOtherDomains
    import I_BrowserQueryStatistics
    import I_BrowserResetNetlogonState
    import I_BrowserResetStatistics
    import I_BrowserServerEnum
    import I_BrowserSetNetlogonState
    import I_DsUpdateReadOnlyServerDnsRecords
    import I_NetAccountDeltas
    import I_NetAccountSync
    import I_NetChainSetClientAttributes
    import I_NetChainSetClientAttributes2
    import I_NetDatabaseDeltas
    import I_NetDatabaseRedo
    import I_NetDatabaseSync
    import I_NetDatabaseSync2
    import I_NetDfsGetVersion
    import I_NetDfsIsThisADomainName
    import I_NetGetDCList
    import I_NetGetForestTrustInformation
    import I_NetLogonControl
    import I_NetLogonControl2
    import I_NetLogonGetDomainInfo
    import I_NetLogonSamLogoff
    import I_NetLogonSamLogon
    import I_NetLogonSamLogonEx
    import I_NetLogonSamLogonWithFlags
    import I_NetLogonSendToSam
    import I_NetLogonUasLogoff
    import I_NetLogonUasLogon
    import I_NetServerAuthenticate
    import I_NetServerAuthenticate2
    import I_NetServerAuthenticate3
    import I_NetServerGetTrustInfo
    import I_NetServerPasswordGet
    import I_NetServerPasswordSet
    import I_NetServerPasswordSet2
    import I_NetServerReqChallenge
    import I_NetServerSetServiceBits
    import I_NetServerSetServiceBitsEx
    import I_NetServerTrustPasswordsGet
    import I_NetlogonComputeClientDigest
    import I_NetlogonComputeServerDigestt
    import NetAddAlternateComputerName
    import NetAddServiceAccount
    import NetAlertRaise
    import NetAlertRaiseEx
    import NetApiBufferAllocate
    import NetApiBufferFree
    import NetApiBufferReallocate
    import NetApiBufferSize
    import NetAuditClear
    import NetAuditRead
    import NetAuditWrite
    import NetBrowserStatisticsGet
    import NetConfigGet
    import NetConfigGetAll
    import NetConfigSet
    import NetConnectionEnum
    import NetDfsAdd
    import NetDfsAddFtRoot
    import NetDfsAddRootTarget
    import NetDfsAddStdRoot
    import NetDfsAddStdRootForced
    import NetDfsEnum
    import NetDfsGetClientInfo
    import NetDfsGetDcAddress
    import NetDfsGetFtContainerSecurity
    import NetDfsGetInfo
    import NetDfsGetSecurity
    import NetDfsGetStdContainerSecurity
    import NetDfsGetSupportedNamespaceVersion
    import NetDfsManagerInitialize
    import NetDfsManagerSendSiteInfo
    import NetDfsMove
    import NetDfsRemove
    import NetDfsRemoveFtRoot
    import NetDfsRemoveFtRootForced
    import NetDfsRemoveRootTarget
    import NetDfsRemoveStdRoot
    import NetDfsRename
    import NetDfsSetClientInfo
    import NetDfsSetFtContainerSecurity
    import NetDfsSetInfo
    import NetDfsSetSecurity
    import NetDfsSetStdContainerSecurity
    import NetEnumerateComputerNames
    import NetEnumerateServiceAccounts
    import NetEnumerateTrustedDomains
    import NetErrorLogClear
    import NetErrorLogRead
    import NetErrorLogWrite
    import NetFileClose
    import NetFileEnum
    import NetFileGetInfo
    import NetGetAnyDCName
    import NetGetDCName
    import NetGetDisplayInformationIndex
    import NetGetJoinInformation
    import NetGetJoinableOUs
    import NetGroupAdd
    import NetGroupAddUser
    import NetGroupDel
    import NetGroupDelUser
    import NetGroupEnum
    import NetGroupGetInfo
    import NetGroupGetUsers
    import NetGroupSetInfo
    import NetGroupSetUsers
    import NetIsServiceAccount
    import NetJoinDomain
    import NetLocalGroupAdd
    import NetLocalGroupAddMember
    import NetLocalGroupAddMembers
    import NetLocalGroupDel
    import NetLocalGroupDelMember
    import NetLocalGroupDelMembers
    import NetLocalGroupEnum
    import NetLocalGroupGetInfo
    import NetLocalGroupGetMembers
    import NetLocalGroupSetInfo
    import NetLocalGroupSetMembers
    import NetLogonGetTimeServiceParentDomain
    import NetLogonSetServiceBits
    import NetMessageBufferSend
    import NetMessageNameAdd
    import NetMessageNameDel
    import NetMessageNameEnum
    import NetMessageNameGetInfo
    import NetProvisionComputerAccount
    import NetQueryDisplayInformation
    import NetQueryServiceAccount
    import NetRegisterDomainNameChangeNotification
    import NetRemoteComputerSupports
    import NetRemoteTOD
    import NetRemoveAlternateComputerName
    import NetRemoveServiceAccount
    import NetRenameMachineInDomain
    import NetReplExportDirAdd
    import NetReplExportDirDel
    import NetReplExportDirEnum
    import NetReplExportDirGetInfo
    import NetReplExportDirLock
    import NetReplExportDirSetInfo
    import NetReplExportDirUnlock
    import NetReplGetInfo
    import NetReplImportDirAdd
    import NetReplImportDirDel
    import NetReplImportDirEnum
    import NetReplImportDirGetInfo
    import NetReplImportDirLock
    import NetReplImportDirUnlock
    import NetReplSetInfo
    import NetRequestOfflineDomainJoin
    import NetScheduleJobAdd
    import NetScheduleJobDel
    import NetScheduleJobEnum
    import NetScheduleJobGetInfo
    import NetServerAliasAdd
    import NetServerAliasDel
    import NetServerAliasEnum
    import NetServerComputerNameAdd
    import NetServerComputerNameDel
    import NetServerDiskEnum
    import NetServerEnum
    import NetServerEnumEx
    import NetServerGetInfo
    import NetServerSetInfo
    import NetServerTransportAdd
    import NetServerTransportAddEx
    import NetServerTransportDel
    import NetServerTransportEnum
    import NetServiceControl
    import NetServiceEnum
    import NetServiceGetInfo
    import NetServiceInstall
    import NetSessionDel
    import NetSessionEnum
    import NetSessionGetInfo
    import NetSetPrimaryComputerName
    import NetShareAdd
    import NetShareCheck
    import NetShareDel
    import NetShareDelEx
    import NetShareDelSticky
    import NetShareEnum
    import NetShareEnumSticky
    import NetShareGetInfo
    import NetShareSetInfo
    import NetStatisticsGet
    import NetUnjoinDomain
    import NetUnregisterDomainNameChangeNotification
    import NetUseAdd
    import NetUseDel
    import NetUseEnum
    import NetUseGetInfo
    import NetUserAdd
    import NetUserChangePassword
    import NetUserDel
    import NetUserEnum
    import NetUserGetGroups
    import NetUserGetInfo
    import NetUserGetLocalGroups
    import NetUserModalsGet
    import NetUserModalsSet
    import NetUserSetGroups
    import NetUserSetInfo
    import NetValidateName
    import NetValidatePasswordPolicy
    import NetValidatePasswordPolicyFree
    import NetWkstaGetInfo
    import NetWkstaSetInfo
    import NetWkstaTransportAdd
    import NetWkstaTransportDel
    import NetWkstaTransportEnum
    import NetWkstaUserEnum
    import NetWkstaUserGetInfo
    import NetWkstaUserSetInfo
    import NetapipBufferAllocate
    import Netbios
    import NetpAssertFailed
    import NetpCloseConfigData
    import NetpDbgPrint
    import NetpGetConfigBool
    import NetpGetConfigDword
    import NetpGetConfigTStrArray
    import NetpGetConfigValue
    import NetpGetFileSecurity
    import NetpHexDump
    import NetpInitFtinfoContext
    import NetpIsRemote
    import NetpIsUncComputerNameValid
    import NetpMergeFtinfo
    import NetpNetBiosReset
    import NetpNetBiosStatusToApiStatus
    import NetpOpenConfigData
    import NetpSetFileSecurity
    import NetpwNameCanonicalize
    import NetpwNameCompare
    import NetpwNameValidate
    import NetpwPathCanonicalize
    import NetpwPathCompare
    import NetpwPathType
    import NlBindingAddServerToCache
    import NlBindingRemoveServerFromCache
    import NlBindingSetAuthInfo
    import RxNetAccessAdd
    import RxNetAccessDel
    import RxNetAccessEnum
    import RxNetAccessGetInfo
    import RxNetAccessGetUserPerms
    import RxNetAccessSetInfo
    import RxNetServerEnum
    import RxNetUserPasswordSet
    import RxRemoteApi
#else
    extern DsAddressToSiteNamesA alias _DsAddressToSiteNamesA@16
    extern DsAddressToSiteNamesExA alias _DsAddressToSiteNamesExA@20
    extern DsAddressToSiteNamesExW alias _DsAddressToSiteNamesExW@20
    extern DsAddressToSiteNamesW alias _DsAddressToSiteNamesW@16
    extern DsDeregisterDnsHostRecordsA alias _DsDeregisterDnsHostRecordsA@20
    extern DsDeregisterDnsHostRecordsW alias _DsDeregisterDnsHostRecordsW@20
    extern DsEnumerateDomainTrustsA alias _DsEnumerateDomainTrustsA@16
    extern DsEnumerateDomainTrustsW alias _DsEnumerateDomainTrustsW@16
    extern DsGetDcCloseW alias _DsGetDcCloseW@4
    extern DsGetDcNameA alias _DsGetDcNameA@24
    extern DsGetDcNameW alias _DsGetDcNameW@24
    extern DsGetDcNameWithAccountA alias _DsGetDcNameWithAccountA@32
    extern DsGetDcNameWithAccountW alias _DsGetDcNameWithAccountW@32
    extern DsGetDcNextA alias _DsGetDcNextA@16
    extern DsGetDcNextW alias _DsGetDcNextW@16
    extern DsGetDcOpenA alias _DsGetDcOpenA@28
    extern DsGetDcOpenW alias _DsGetDcOpenW@28
    extern DsGetDcSiteCoverageA alias _DsGetDcSiteCoverageA@12
    extern DsGetDcSiteCoverageW alias _DsGetDcSiteCoverageW@12
    extern DsGetForestTrustInformationW alias _DsGetForestTrustInformationW@16
    extern DsGetSiteNameA alias _DsGetSiteNameA@8
    extern DsGetSiteNameW alias _DsGetSiteNameW@8
    extern DsMergeForestTrustInformationW alias _DsMergeForestTrustInformationW@16
    extern DsRoleAbortDownlevelServerUpgrade alias _DsRoleAbortDownlevelServerUpgrade@16
    extern DsRoleCancel alias _DsRoleCancel@8
    extern DsRoleDcAsDc alias _DsRoleDcAsDc@60
    extern DsRoleDcAsReplica alias _DsRoleDcAsReplica@56
    extern DsRoleDemoteDc alias _DsRoleDemoteDc@36
    extern DsRoleDnsNameToFlatName alias _DsRoleDnsNameToFlatName@16
    extern DsRoleFreeMemory alias _DsRoleFreeMemory@4
    extern DsRoleGetDatabaseFacts alias _DsRoleGetDatabaseFacts@16
    extern DsRoleGetDcOperationProgress alias _DsRoleGetDcOperationProgress@12
    extern DsRoleGetDcOperationResults alias _DsRoleGetDcOperationResults@12
    extern DsRoleGetPrimaryDomainInformation alias _DsRoleGetPrimaryDomainInformation@12
    extern DsRoleIfmHandleFree alias _DsRoleIfmHandleFree@8
    extern DsRoleServerSaveStateForUpgrade alias _DsRoleServerSaveStateForUpgrade@4
    extern DsRoleUpgradeDownlevelServer alias _DsRoleUpgradeDownlevelServer@48
    extern DsValidateSubnetNameA alias _DsValidateSubnetNameA@4
    extern DsValidateSubnetNameW alias _DsValidateSubnetNameW@4
    extern I_BrowserDebugCall alias _I_BrowserDebugCall@12
    extern I_BrowserDebugTrace alias _I_BrowserDebugTrace@8
    extern I_BrowserQueryEmulatedDomains alias _I_BrowserQueryEmulatedDomains@12
    extern I_BrowserQueryOtherDomains alias _I_BrowserQueryOtherDomains@16
    extern I_BrowserQueryStatistics alias _I_BrowserQueryStatistics@8
    extern I_BrowserResetNetlogonState alias _I_BrowserResetNetlogonState@4
    extern I_BrowserResetStatistics alias _I_BrowserResetStatistics@4
    extern I_BrowserServerEnum alias _I_BrowserServerEnum@44
    extern I_BrowserSetNetlogonState alias _I_BrowserSetNetlogonState@16
    extern I_DsUpdateReadOnlyServerDnsRecords alias _I_DsUpdateReadOnlyServerDnsRecords@28
    extern I_NetAccountDeltas alias _I_NetAccountDeltas@48
    extern I_NetAccountSync alias _I_NetAccountSync@48
    extern I_NetChainSetClientAttributes alias _I_NetChainSetClientAttributes@36
    extern I_NetChainSetClientAttributes2 alias _I_NetChainSetClientAttributes2@36
    extern I_NetDatabaseDeltas alias _I_NetDatabaseDeltas@32
    extern I_NetDatabaseRedo alias _I_NetDatabaseRedo@28
    extern I_NetDatabaseSync alias _I_NetDatabaseSync@32
    extern I_NetDatabaseSync2 alias _I_NetDatabaseSync2@36
    extern I_NetDfsGetVersion alias _I_NetDfsGetVersion@8
    extern I_NetDfsIsThisADomainName alias _I_NetDfsIsThisADomainName@4
    extern I_NetGetDCList alias _I_NetGetDCList@16
    extern I_NetGetForestTrustInformation alias _I_NetGetForestTrustInformation@24
    extern I_NetLogonControl alias _I_NetLogonControl@16
    extern I_NetLogonControl2 alias _I_NetLogonControl2@20
    extern I_NetLogonGetDomainInfo alias _I_NetLogonGetDomainInfo@28
    extern I_NetLogonSamLogoff alias _I_NetLogonSamLogoff@24
    extern I_NetLogonSamLogon alias _I_NetLogonSamLogon@36
    extern I_NetLogonSamLogonEx alias _I_NetLogonSamLogonEx@40
    extern I_NetLogonSamLogonWithFlags alias _I_NetLogonSamLogonWithFlags@40
    extern I_NetLogonSendToSam alias _I_NetLogonSendToSam@24
    extern I_NetLogonUasLogoff alias _I_NetLogonUasLogoff@12
    extern I_NetLogonUasLogon alias _I_NetLogonUasLogon@12
    extern I_NetServerAuthenticate alias _I_NetServerAuthenticate@24
    extern I_NetServerAuthenticate2 alias _I_NetServerAuthenticate2@28
    extern I_NetServerAuthenticate3 alias _I_NetServerAuthenticate3@32
    extern I_NetServerGetTrustInfo alias _I_NetServerGetTrustInfo@32
    extern I_NetServerPasswordGet alias _I_NetServerPasswordGet@28
    extern I_NetServerPasswordSet alias _I_NetServerPasswordSet@28
    extern I_NetServerPasswordSet2 alias _I_NetServerPasswordSet2@28
    extern I_NetServerReqChallenge alias _I_NetServerReqChallenge@16
    extern I_NetServerSetServiceBits alias _I_NetServerSetServiceBits@16
    extern I_NetServerSetServiceBitsEx alias _I_NetServerSetServiceBitsEx@24
    extern I_NetServerTrustPasswordsGet alias _I_NetServerTrustPasswordsGet@32
    extern I_NetlogonComputeClientDigest alias _I_NetlogonComputeClientDigest@24
    extern I_NetlogonComputeServerDigestt alias _I_NetlogonComputeServerDigestt@24
    extern NetAddAlternateComputerName alias _NetAddAlternateComputerName@20
    extern NetAddServiceAccount alias _NetAddServiceAccount@16
    extern NetAlertRaise alias _NetAlertRaise@12
    extern NetAlertRaiseEx alias _NetAlertRaiseEx@16
    extern NetApiBufferAllocate alias _NetApiBufferAllocate@8
    extern NetApiBufferFree alias _NetApiBufferFree@4
    extern NetApiBufferReallocate alias _NetApiBufferReallocate@12
    extern NetApiBufferSize alias _NetApiBufferSize@8
    extern NetAuditClear alias _NetAuditClear@12
    extern NetAuditRead alias _NetAuditRead@44
    extern NetAuditWrite alias _NetAuditWrite@20
    extern NetBrowserStatisticsGet alias _NetBrowserStatisticsGet@12
    extern NetConfigGet alias _NetConfigGet@16
    extern NetConfigGetAll alias _NetConfigGetAll@12
    extern NetConfigSet alias _NetConfigSet@28
    extern NetConnectionEnum alias _NetConnectionEnum@32
    extern NetDfsAdd alias _NetDfsAdd@20
    extern NetDfsAddFtRoot alias _NetDfsAddFtRoot@20
    extern NetDfsAddRootTarget alias _NetDfsAddRootTarget@20
    extern NetDfsAddStdRoot alias _NetDfsAddStdRoot@16
    extern NetDfsAddStdRootForced alias _NetDfsAddStdRootForced@16
    extern NetDfsEnum alias _NetDfsEnum@24
    extern NetDfsGetClientInfo alias _NetDfsGetClientInfo@20
    extern NetDfsGetDcAddress alias _NetDfsGetDcAddress@16
    extern NetDfsGetFtContainerSecurity alias _NetDfsGetFtContainerSecurity@16
    extern NetDfsGetInfo alias _NetDfsGetInfo@20
    extern NetDfsGetSecurity alias _NetDfsGetSecurity@16
    extern NetDfsGetStdContainerSecurity alias _NetDfsGetStdContainerSecurity@16
    extern NetDfsGetSupportedNamespaceVersion alias _NetDfsGetSupportedNamespaceVersion@12
    extern NetDfsManagerInitialize alias _NetDfsManagerInitialize@8
    extern NetDfsManagerSendSiteInfo alias _NetDfsManagerSendSiteInfo@12
    extern NetDfsMove alias _NetDfsMove@12
    extern NetDfsRemove alias _NetDfsRemove@12
    extern NetDfsRemoveFtRoot alias _NetDfsRemoveFtRoot@16
    extern NetDfsRemoveFtRootForced alias _NetDfsRemoveFtRootForced@20
    extern NetDfsRemoveRootTarget alias _NetDfsRemoveRootTarget@12
    extern NetDfsRemoveStdRoot alias _NetDfsRemoveStdRoot@12
    extern NetDfsRename alias _NetDfsRename@8
    extern NetDfsSetClientInfo alias _NetDfsSetClientInfo@20
    extern NetDfsSetFtContainerSecurity alias _NetDfsSetFtContainerSecurity@12
    extern NetDfsSetInfo alias _NetDfsSetInfo@20
    extern NetDfsSetSecurity alias _NetDfsSetSecurity@12
    extern NetDfsSetStdContainerSecurity alias _NetDfsSetStdContainerSecurity@12
    extern NetEnumerateComputerNames alias _NetEnumerateComputerNames@20
    extern NetEnumerateServiceAccounts alias _NetEnumerateServiceAccounts@16
    extern NetEnumerateTrustedDomains alias _NetEnumerateTrustedDomains@8
    extern NetErrorLogClear alias _NetErrorLogClear@12
    extern NetErrorLogRead alias _NetErrorLogRead@44
    extern NetErrorLogWrite alias _NetErrorLogWrite@32
    extern NetFileClose alias _NetFileClose@8
    extern NetFileEnum alias _NetFileEnum@36
    extern NetFileGetInfo alias _NetFileGetInfo@16
    extern NetGetAnyDCName alias _NetGetAnyDCName@12
    extern NetGetDCName alias _NetGetDCName@12
    extern NetGetDisplayInformationIndex alias _NetGetDisplayInformationIndex@16
    extern NetGetJoinInformation alias _NetGetJoinInformation@12
    extern NetGetJoinableOUs alias _NetGetJoinableOUs@24
    extern NetGroupAdd alias _NetGroupAdd@16
    extern NetGroupAddUser alias _NetGroupAddUser@12
    extern NetGroupDel alias _NetGroupDel@8
    extern NetGroupDelUser alias _NetGroupDelUser@12
    extern NetGroupEnum alias _NetGroupEnum@28
    extern NetGroupGetInfo alias _NetGroupGetInfo@16
    extern NetGroupGetUsers alias _NetGroupGetUsers@32
    extern NetGroupSetInfo alias _NetGroupSetInfo@20
    extern NetGroupSetUsers alias _NetGroupSetUsers@20
    extern NetIsServiceAccount alias _NetIsServiceAccount@12
    extern NetJoinDomain alias _NetJoinDomain@24
    extern NetLocalGroupAdd alias _NetLocalGroupAdd@16
    extern NetLocalGroupAddMember alias _NetLocalGroupAddMember@12
    extern NetLocalGroupAddMembers alias _NetLocalGroupAddMembers@20
    extern NetLocalGroupDel alias _NetLocalGroupDel@8
    extern NetLocalGroupDelMember alias _NetLocalGroupDelMember@12
    extern NetLocalGroupDelMembers alias _NetLocalGroupDelMembers@20
    extern NetLocalGroupEnum alias _NetLocalGroupEnum@28
    extern NetLocalGroupGetInfo alias _NetLocalGroupGetInfo@16
    extern NetLocalGroupGetMembers alias _NetLocalGroupGetMembers@32
    extern NetLocalGroupSetInfo alias _NetLocalGroupSetInfo@20
    extern NetLocalGroupSetMembers alias _NetLocalGroupSetMembers@20
    extern NetLogonGetTimeServiceParentDomain alias _NetLogonGetTimeServiceParentDomain@12
    extern NetLogonSetServiceBits alias _NetLogonSetServiceBits@12
    extern NetMessageBufferSend alias _NetMessageBufferSend@20
    extern NetMessageNameAdd alias _NetMessageNameAdd@8
    extern NetMessageNameDel alias _NetMessageNameDel@8
    extern NetMessageNameEnum alias _NetMessageNameEnum@28
    extern NetMessageNameGetInfo alias _NetMessageNameGetInfo@16
    extern NetProvisionComputerAccount alias _NetProvisionComputerAccount@32
    extern NetQueryDisplayInformation alias _NetQueryDisplayInformation@28
    extern NetQueryServiceAccount alias _NetQueryServiceAccount@16
    extern NetRegisterDomainNameChangeNotification alias _NetRegisterDomainNameChangeNotification@4
    extern NetRemoteComputerSupports alias _NetRemoteComputerSupports@12
    extern NetRemoteTOD alias _NetRemoteTOD@8
    extern NetRemoveAlternateComputerName alias _NetRemoveAlternateComputerName@20
    extern NetRemoveServiceAccount alias _NetRemoveServiceAccount@12
    extern NetRenameMachineInDomain alias _NetRenameMachineInDomain@20
    extern NetReplExportDirAdd alias _NetReplExportDirAdd@16
    extern NetReplExportDirDel alias _NetReplExportDirDel@8
    extern NetReplExportDirEnum alias _NetReplExportDirEnum@28
    extern NetReplExportDirGetInfo alias _NetReplExportDirGetInfo@16
    extern NetReplExportDirLock alias _NetReplExportDirLock@8
    extern NetReplExportDirSetInfo alias _NetReplExportDirSetInfo@20
    extern NetReplExportDirUnlock alias _NetReplExportDirUnlock@12
    extern NetReplGetInfo alias _NetReplGetInfo@12
    extern NetReplImportDirAdd alias _NetReplImportDirAdd@16
    extern NetReplImportDirDel alias _NetReplImportDirDel@8
    extern NetReplImportDirEnum alias _NetReplImportDirEnum@28
    extern NetReplImportDirGetInfo alias _NetReplImportDirGetInfo@16
    extern NetReplImportDirLock alias _NetReplImportDirLock@8
    extern NetReplImportDirUnlock alias _NetReplImportDirUnlock@12
    extern NetReplSetInfo alias _NetReplSetInfo@16
    extern NetRequestOfflineDomainJoin alias _NetRequestOfflineDomainJoin@16
    extern NetScheduleJobAdd alias _NetScheduleJobAdd@12
    extern NetScheduleJobDel alias _NetScheduleJobDel@12
    extern NetScheduleJobEnum alias _NetScheduleJobEnum@24
    extern NetScheduleJobGetInfo alias _NetScheduleJobGetInfo@12
    extern NetServerAliasAdd alias _NetServerAliasAdd@12
    extern NetServerAliasDel alias _NetServerAliasDel@12
    extern NetServerAliasEnum alias _NetServerAliasEnum@28
    extern NetServerComputerNameAdd alias _NetServerComputerNameAdd@12
    extern NetServerComputerNameDel alias _NetServerComputerNameDel@8
    extern NetServerDiskEnum alias _NetServerDiskEnum@28
    extern NetServerEnum alias _NetServerEnum@36
    extern NetServerEnumEx alias _NetServerEnumEx@36
    extern NetServerGetInfo alias _NetServerGetInfo@12
    extern NetServerSetInfo alias _NetServerSetInfo@16
    extern NetServerTransportAdd alias _NetServerTransportAdd@12
    extern NetServerTransportAddEx alias _NetServerTransportAddEx@12
    extern NetServerTransportDel alias _NetServerTransportDel@12
    extern NetServerTransportEnum alias _NetServerTransportEnum@28
    extern NetServiceControl alias _NetServiceControl@20
    extern NetServiceEnum alias _NetServiceEnum@28
    extern NetServiceGetInfo alias _NetServiceGetInfo@16
    extern NetServiceInstall alias _NetServiceInstall@20
    extern NetSessionDel alias _NetSessionDel@12
    extern NetSessionEnum alias _NetSessionEnum@36
    extern NetSessionGetInfo alias _NetSessionGetInfo@20
    extern NetSetPrimaryComputerName alias _NetSetPrimaryComputerName@20
    extern NetShareAdd alias _NetShareAdd@16
    extern NetShareCheck alias _NetShareCheck@12
    extern NetShareDel alias _NetShareDel@12
    extern NetShareDelEx alias _NetShareDelEx@12
    extern NetShareDelSticky alias _NetShareDelSticky@12
    extern NetShareEnum alias _NetShareEnum@28
    extern NetShareEnumSticky alias _NetShareEnumSticky@28
    extern NetShareGetInfo alias _NetShareGetInfo@16
    extern NetShareSetInfo alias _NetShareSetInfo@20
    extern NetStatisticsGet alias _NetStatisticsGet@20
    extern NetUnjoinDomain alias _NetUnjoinDomain@16
    extern NetUnregisterDomainNameChangeNotification alias _NetUnregisterDomainNameChangeNotification@4
    extern NetUseAdd alias _NetUseAdd@16
    extern NetUseDel alias _NetUseDel@12
    extern NetUseEnum alias _NetUseEnum@28
    extern NetUseGetInfo alias _NetUseGetInfo@16
    extern NetUserAdd alias _NetUserAdd@16
    extern NetUserChangePassword alias _NetUserChangePassword@16
    extern NetUserDel alias _NetUserDel@8
    extern NetUserEnum alias _NetUserEnum@32
    extern NetUserGetGroups alias _NetUserGetGroups@28
    extern NetUserGetInfo alias _NetUserGetInfo@16
    extern NetUserGetLocalGroups alias _NetUserGetLocalGroups@32
    extern NetUserModalsGet alias _NetUserModalsGet@12
    extern NetUserModalsSet alias _NetUserModalsSet@16
    extern NetUserSetGroups alias _NetUserSetGroups@20
    extern NetUserSetInfo alias _NetUserSetInfo@20
    extern NetValidateName alias _NetValidateName@20
    extern NetValidatePasswordPolicy alias _NetValidatePasswordPolicy@20
    extern NetValidatePasswordPolicyFree alias _NetValidatePasswordPolicyFree@4
    extern NetWkstaGetInfo alias _NetWkstaGetInfo@12
    extern NetWkstaSetInfo alias _NetWkstaSetInfo@16
    extern NetWkstaTransportAdd alias _NetWkstaTransportAdd@16
    extern NetWkstaTransportDel alias _NetWkstaTransportDel@12
    extern NetWkstaTransportEnum alias _NetWkstaTransportEnum@28
    extern NetWkstaUserEnum alias _NetWkstaUserEnum@28
    extern NetWkstaUserGetInfo alias _NetWkstaUserGetInfo@12
    extern NetWkstaUserSetInfo alias _NetWkstaUserSetInfo@16
    extern NetapipBufferAllocate alias _NetapipBufferAllocate@8
    extern Netbios alias _Netbios@4
    extern NetpAssertFailed alias _NetpAssertFailed@16
    extern NetpCloseConfigData alias _NetpCloseConfigData@4
    extern NetpDbgPrint alias _NetpDbgPrint@4
    extern NetpGetConfigBool alias _NetpGetConfigBool@16
    extern NetpGetConfigDword alias _NetpGetConfigDword@16
    extern NetpGetConfigTStrArray alias _NetpGetConfigTStrArray@12
    extern NetpGetConfigValue alias _NetpGetConfigValue@12
    extern NetpGetFileSecurity alias _NetpGetFileSecurity@16
    extern NetpHexDump alias _NetpHexDump@8
    extern NetpInitFtinfoContext alias _NetpInitFtinfoContext@4
    extern NetpIsRemote alias _NetpIsRemote@16
    extern NetpIsUncComputerNameValid alias _NetpIsUncComputerNameValid@4
    extern NetpMergeFtinfo alias _NetpMergeFtinfo@16
    extern NetpNetBiosReset alias _NetpNetBiosReset@4
    extern NetpNetBiosStatusToApiStatus alias _NetpNetBiosStatusToApiStatus@4
    extern NetpOpenConfigData alias _NetpOpenConfigData@16
    extern NetpSetFileSecurity alias _NetpSetFileSecurity@12
    extern NetpwNameCanonicalize alias _NetpwNameCanonicalize@16
    extern NetpwNameCompare alias _NetpwNameCompare@16
    extern NetpwNameValidate alias _NetpwNameValidate@12
    extern NetpwPathCanonicalize alias _NetpwPathCanonicalize@24
    extern NetpwPathCompare alias _NetpwPathCompare@16
    extern NetpwPathType alias _NetpwPathType@12
    extern NlBindingAddServerToCache alias _NlBindingAddServerToCache@8
    extern NlBindingRemoveServerFromCache alias _NlBindingRemoveServerFromCache@8
    extern NlBindingSetAuthInfo alias _NlBindingSetAuthInfo@20
    extern RxNetAccessAdd alias _RxNetAccessAdd@16
    extern RxNetAccessDel alias _RxNetAccessDel@8
    extern RxNetAccessEnum alias _RxNetAccessEnum@36
    extern RxNetAccessGetInfo alias _RxNetAccessGetInfo@16
    extern RxNetAccessGetUserPerms alias _RxNetAccessGetUserPerms@16
    extern RxNetAccessSetInfo alias _RxNetAccessSetInfo@20
    extern RxNetServerEnum alias _RxNetServerEnum@40
    extern RxNetUserPasswordSet alias _RxNetUserPasswordSet@16
    extern RxRemoteApi alias _RxRemoteApi@44
#endif

define DsGetDcClose DsGetDcCloseW
define DsGetForestTrustInformation DsGetForestTrustInformationW
define DsMergeForestTrustInformation DsMergeForestTrustInformationW

#ifdef APP_UNICODE
    define DsAddressToSiteNames DsAddressToSiteNamesW
    define DsAddressToSiteNamesEx DsAddressToSiteNamesExW
    define DsDeregisterDnsHostRecords DsDeregisterDnsHostRecordsW
    define DsEnumerateDomainTrusts DsEnumerateDomainTrustsW
    define DsGetDcName DsGetDcNameW
    define DsGetDcNameWithAccount DsGetDcNameWithAccountW
    define DsGetDcNext DsGetDcNextW
    define DsGetDcOpen DsGetDcOpenW
    define DsGetDcSiteCoverage DsGetDcSiteCoverageW
    define DsGetSiteName DsGetSiteNameW
    define DsValidateSubnetName DsValidateSubnetNameW
#else
    define DsAddressToSiteNames DsAddressToSiteNamesA
    define DsAddressToSiteNamesEx DsAddressToSiteNamesExA
    define DsDeregisterDnsHostRecords DsDeregisterDnsHostRecordsA
    define DsEnumerateDomainTrusts DsEnumerateDomainTrustsA
    define DsGetDcName DsGetDcNameA
    define DsGetDcNameWithAccount DsGetDcNameWithAccountA
    define DsGetDcNext DsGetDcNextA
    define DsGetDcOpen DsGetDcOpenA
    define DsGetDcSiteCoverage DsGetDcSiteCoverageA
    define DsGetSiteName DsGetSiteNameA
    define DsValidateSubnetName DsValidateSubnetNameA
#endif

;======================= Undocumented functions (unknown arguments) =======================;
;#ifdef APP_WIN64
    ;import NetDfsManagerGetConfigInfo
    ;import NetpAddTlnFtinfoEntry
    ;import NetpAllocFtinfoEntry
    ;import NetpCleanFtinfoContext
    ;import NetpCopyFtinfoContext
;#else
    ;extern NetDfsManagerGetConfigInfo alias _NetDfsManagerGetConfigInfo@??
    ;extern NetpAddTlnFtinfoEntry alias _NetpAddTlnFtinfoEntry@??
    ;extern NetpAllocFtinfoEntry alias _NetpAllocFtinfoEntry@??
    ;extern NetpCleanFtinfoContext alias _NetpCleanFtinfoContext@??
    ;extern NetpCopyFtinfoContext alias _NetpCopyFtinfoContext@??
;#endif

#endif ;NETAPI32_INC
