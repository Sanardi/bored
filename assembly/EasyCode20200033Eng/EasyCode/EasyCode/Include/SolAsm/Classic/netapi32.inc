; ====================================================;
;                                                     ;
;   netapi32.inc for EC v2 SolAsm classic projects    ;
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
;import NetDfsManagerGetConfigInfo
;import NetpAddTlnFtinfoEntry
;import NetpAllocFtinfoEntry
;import NetpCleanFtinfoContext
;import NetpCopyFtinfoContext

#endif ;NETAPI32_INC
