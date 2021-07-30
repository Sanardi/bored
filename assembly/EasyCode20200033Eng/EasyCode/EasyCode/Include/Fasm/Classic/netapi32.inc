; ====================================================;
;                                                     ;
;    netapi32.inc for EC v2 Fasm classic projects     ;
;                   (version 1.0.2)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

if ~defined NETAPI32_INC
define NETAPI32_INC    1

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


;=============================== lmcons constants ===============================
if ~defined CNLEN
    CNLEN                                       equ     15
    LM20_CNLEN                                  equ     15
    DNLEN                                       equ     CNLEN
    LM20_DNLEN                                  equ     LM20_CNLEN
    UNCLEN                                      equ     CNLEN + 2
    LM20_UNCLEN                                 equ     LM20_CNLEN + 2
    NNLEN                                       equ     80
    LM20_NNLEN                                  equ     12
    RMLEN                                       equ     UNCLEN + 1 + NNLEN
    LM20_RMLEN                                  equ     LM20_UNCLEN + 1 + LM20_NNLEN
    SNLEN                                       equ     80
    LM20_SNLEN                                  equ     15
    STXTLEN                                     equ     256
    LM20_STXTLEN                                equ     63
    PATHLEN                                     equ     256
    LM20_PATHLEN                                equ     256
    DEVLEN                                      equ     80
    LM20_DEVLEN                                 equ     8
    EVLEN                                       equ     16
    UNLEN                                       equ     256
    LM20_UNLEN                                  equ     20
    GNLEN                                       equ     UNLEN
    LM20_GNLEN                                  equ     LM20_UNLEN
    PWLEN                                       equ     256
    LM20_PWLEN                                  equ     14
    SHPWLEN                                     equ     8
    CLTYPE_LEN                                  equ     12
    MAXCOMMENTSZ                                equ     256
    LM20_MAXCOMMENTSZ                           equ     48
    QNLEN                                       equ     NNLEN
    LM20_QNLEN                                  equ     LM20_NNLEN
    ALERTSZ                                     equ     128
    MAXDEVENTRIES                               equ     32
    NETBIOS_NAME_LEN                            equ     16
    MAX_PREFERRED_LENGTH                        equ     (-1)
    CRYPT_KEY_LEN                               equ     7
    CRYPT_TXT_LEN                               equ     8
    ENCRYPTED_PWLEN                             equ     16
    SESSION_PWLEN                               equ     24
    SESSION_CRYPT_KLEN                          equ     21
    if ~defined PARMNUM_ALL
        PARMNUM_ALL                             equ     0
    end if
    PARM_ERROR_UNKNOWN                          equ     (-1)
    PARM_ERROR_NONE                             equ     0
    PARMNUM_BASE_INFOLEVEL                      equ     1000
    MESSAGE_FILENAME                            equ     "NETMSG"
    OS2MSG_FILENAME                             equ     "BASE"
    HELP_MSG_FILENAME                           equ     "NETH"
    BACKUP_MSG_FILENAME                         equ     "BAK.MSG"
    PLATFORM_ID_DOS                             equ     300
    PLATFORM_ID_OS2                             equ     400
    PLATFORM_ID_NT                              equ     500
    PLATFORM_ID_OSF                             equ     600
    PLATFORM_ID_VMS                             equ     700
    MIN_LANMAN_MESSAGE_ID                       equ     NERR_BASE
    MAX_LANMAN_MESSAGE_ID                       equ     5799
end if


;======================================== Structures ======================================;
struct USE_INFO_0
    ui0_local  xptr ?
    ui0_remote xptr ?
ends

struct USE_INFO_1
    ui1_local    xptr ?
    ui1_remote   xptr ?
    ui1_password xptr ?
    ui1_status   dd   ?
    ui1_asg_type dd   ?
    ui1_refcount dd   ?
    ui1_usecount dd   ?
ends

struct USE_INFO_2
    ui2_local      xptr ?
    ui2_remote     xptr ?
    ui2_password   xptr ?
    ui2_status     dd   ?
    ui2_asg_type   dd   ?
    ui2_refcount   dd   ?
    ui2_usecount   dd   ?
    ui2_username   xptr ?
    ui2_domainname xptr ?
ends

struct USE_INFO_3
    ui3_ui2   USE_INFO_2
    ui3_flags dd ?
ends


;======================================== Functions =======================================;
import netapi32,\
DsAddressToSiteNamesA,'DsAddressToSiteNamesA',\
DsAddressToSiteNamesExA,'DsAddressToSiteNamesExA',\
DsAddressToSiteNamesExW,'DsAddressToSiteNamesExW',\
DsAddressToSiteNamesW,'DsAddressToSiteNamesW',\
DsDeregisterDnsHostRecordsA,'DsDeregisterDnsHostRecordsA',\
DsDeregisterDnsHostRecordsW,'DsDeregisterDnsHostRecordsW',\
DsEnumerateDomainTrustsA,'DsEnumerateDomainTrustsA',\
DsEnumerateDomainTrustsW,'DsEnumerateDomainTrustsW',\
DsGetDcCloseW,'DsGetDcCloseW',\
DsGetDcNameA,'DsGetDcNameA',\
DsGetDcNameW,'DsGetDcNameW',\
DsGetDcNameWithAccountA,'DsGetDcNameWithAccountA',\
DsGetDcNameWithAccountW,'DsGetDcNameWithAccountW',\
DsGetDcNextA,'DsGetDcNextA',\
DsGetDcNextW,'DsGetDcNextW',\
DsGetDcOpenA,'DsGetDcOpenA',\
DsGetDcOpenW,'DsGetDcOpenW',\
DsGetDcSiteCoverageA,'DsGetDcSiteCoverageA',\
DsGetDcSiteCoverageW,'DsGetDcSiteCoverageW',\
DsGetForestTrustInformationW,'DsGetForestTrustInformationW',\
DsGetSiteNameA,'DsGetSiteNameA',\
DsGetSiteNameW,'DsGetSiteNameW',\
DsMergeForestTrustInformationW,'DsMergeForestTrustInformationW',\
DsRoleAbortDownlevelServerUpgrade,'DsRoleAbortDownlevelServerUpgrade',\
DsRoleCancel,'DsRoleCancel',\
DsRoleDcAsDc,'DsRoleDcAsDc',\
DsRoleDcAsReplica,'DsRoleDcAsReplica',\
DsRoleDemoteDc,'DsRoleDemoteDc',\
DsRoleDnsNameToFlatName,'DsRoleDnsNameToFlatName',\
DsRoleFreeMemory,'DsRoleFreeMemory',\
DsRoleGetDatabaseFacts,'DsRoleGetDatabaseFacts',\
DsRoleGetDcOperationProgress,'DsRoleGetDcOperationProgress',\
DsRoleGetDcOperationResults,'DsRoleGetDcOperationResults',\
DsRoleGetPrimaryDomainInformation,'DsRoleGetPrimaryDomainInformation',\
DsRoleIfmHandleFree,'DsRoleIfmHandleFree',\
DsRoleServerSaveStateForUpgrade,'DsRoleServerSaveStateForUpgrade',\
DsRoleUpgradeDownlevelServer,'DsRoleUpgradeDownlevelServer',\
DsValidateSubnetNameA,'DsValidateSubnetNameA',\
DsValidateSubnetNameW,'DsValidateSubnetNameW',\
I_BrowserDebugCall,'I_BrowserDebugCall',\
I_BrowserDebugTrace,'I_BrowserDebugTrace',\
I_BrowserQueryEmulatedDomains,'I_BrowserQueryEmulatedDomains',\
I_BrowserQueryOtherDomains,'I_BrowserQueryOtherDomains',\
I_BrowserQueryStatistics,'I_BrowserQueryStatistics',\
I_BrowserResetNetlogonState,'I_BrowserResetNetlogonState',\
I_BrowserResetStatistics,'I_BrowserResetStatistics',\
I_BrowserServerEnum,'I_BrowserServerEnum',\
I_BrowserSetNetlogonState,'I_BrowserSetNetlogonState',\
I_DsUpdateReadOnlyServerDnsRecords,'I_DsUpdateReadOnlyServerDnsRecords',\
I_NetAccountDeltas,'I_NetAccountDeltas',\
I_NetAccountSync,'I_NetAccountSync',\
I_NetChainSetClientAttributes,'I_NetChainSetClientAttributes',\
I_NetChainSetClientAttributes2,'I_NetChainSetClientAttributes2',\
I_NetDatabaseDeltas,'I_NetDatabaseDeltas',\
I_NetDatabaseRedo,'I_NetDatabaseRedo',\
I_NetDatabaseSync,'I_NetDatabaseSync',\
I_NetDatabaseSync2,'I_NetDatabaseSync2',\
I_NetDfsGetVersion,'I_NetDfsGetVersion',\
I_NetDfsIsThisADomainName,'I_NetDfsIsThisADomainName',\
I_NetGetDCList,'I_NetGetDCList',\
I_NetGetForestTrustInformation,'I_NetGetForestTrustInformation',\
I_NetLogonControl,'I_NetLogonControl',\
I_NetLogonControl2,'I_NetLogonControl2',\
I_NetLogonGetDomainInfo,'I_NetLogonGetDomainInfo',\
I_NetLogonSamLogoff,'I_NetLogonSamLogoff',\
I_NetLogonSamLogon,'I_NetLogonSamLogon',\
I_NetLogonSamLogonEx,'I_NetLogonSamLogonEx',\
I_NetLogonSamLogonWithFlags,'I_NetLogonSamLogonWithFlags',\
I_NetLogonSendToSam,'I_NetLogonSendToSam',\
I_NetLogonUasLogoff,'I_NetLogonUasLogoff',\
I_NetLogonUasLogon,'I_NetLogonUasLogon',\
I_NetServerAuthenticate,'I_NetServerAuthenticate',\
I_NetServerAuthenticate2,'I_NetServerAuthenticate2',\
I_NetServerAuthenticate3,'I_NetServerAuthenticate3',\
I_NetServerGetTrustInfo,'I_NetServerGetTrustInfo',\
I_NetServerPasswordGet,'I_NetServerPasswordGet',\
I_NetServerPasswordSet,'I_NetServerPasswordSet',\
I_NetServerPasswordSet2,'I_NetServerPasswordSet2',\
I_NetServerReqChallenge,'I_NetServerReqChallenge',\
I_NetServerSetServiceBits,'I_NetServerSetServiceBits',\
I_NetServerSetServiceBitsEx,'I_NetServerSetServiceBitsEx',\
I_NetServerTrustPasswordsGet,'I_NetServerTrustPasswordsGet',\
I_NetlogonComputeClientDigest,'I_NetlogonComputeClientDigest',\
I_NetlogonComputeServerDigestt,'I_NetlogonComputeServerDigestt',\
NetAddAlternateComputerName,'NetAddAlternateComputerName',\
NetAddServiceAccount,'NetAddServiceAccount',\
NetAlertRaise,'NetAlertRaise',\
NetAlertRaiseEx,'NetAlertRaiseEx',\
NetApiBufferAllocate,'NetApiBufferAllocate',\
NetApiBufferFree,'NetApiBufferFree',\
NetApiBufferReallocate,'NetApiBufferReallocate',\
NetApiBufferSize,'NetApiBufferSize',\
NetAuditClear,'NetAuditClear',\
NetAuditRead,'NetAuditRead',\
NetAuditWrite,'NetAuditWrite',\
NetBrowserStatisticsGet,'NetBrowserStatisticsGet',\
NetConfigGet,'NetConfigGet',\
NetConfigGetAll,'NetConfigGetAll',\
NetConfigSet,'NetConfigSet',\
NetConnectionEnum,'NetConnectionEnum',\
NetDfsAdd,'NetDfsAdd',\
NetDfsAddFtRoot,'NetDfsAddFtRoot',\
NetDfsAddRootTarget,'NetDfsAddRootTarget',\
NetDfsAddStdRoot,'NetDfsAddStdRoot',\
NetDfsAddStdRootForced,'NetDfsAddStdRootForced',\
NetDfsEnum,'NetDfsEnum',\
NetDfsGetClientInfo,'NetDfsGetClientInfo',\
NetDfsGetDcAddress,'NetDfsGetDcAddress',\
NetDfsGetFtContainerSecurity,'NetDfsGetFtContainerSecurity',\
NetDfsGetInfo,'NetDfsGetInfo',\
NetDfsGetSecurity,'NetDfsGetSecurity',\
NetDfsGetStdContainerSecurity,'NetDfsGetStdContainerSecurity',\
NetDfsGetSupportedNamespaceVersion,'NetDfsGetSupportedNamespaceVersion',\
NetDfsManagerInitialize,'NetDfsManagerInitialize',\
NetDfsManagerSendSiteInfo,'NetDfsManagerSendSiteInfo',\
NetDfsMove,'NetDfsMove',\
NetDfsRemove,'NetDfsRemove',\
NetDfsRemoveFtRoot,'NetDfsRemoveFtRoot',\
NetDfsRemoveFtRootForced,'NetDfsRemoveFtRootForced',\
NetDfsRemoveRootTarget,'NetDfsRemoveRootTarget',\
NetDfsRemoveStdRoot,'NetDfsRemoveStdRoot',\
NetDfsRename,'NetDfsRename',\
NetDfsSetClientInfo,'NetDfsSetClientInfo',\
NetDfsSetFtContainerSecurity,'NetDfsSetFtContainerSecurity',\
NetDfsSetInfo,'NetDfsSetInfo',\
NetDfsSetSecurity,'NetDfsSetSecurity',\
NetDfsSetStdContainerSecurity,'NetDfsSetStdContainerSecurity',\
NetEnumerateComputerNames,'NetEnumerateComputerNames',\
NetEnumerateServiceAccounts,'NetEnumerateServiceAccounts',\
NetEnumerateTrustedDomains,'NetEnumerateTrustedDomains',\
NetErrorLogClear,'NetErrorLogClear',\
NetErrorLogRead,'NetErrorLogRead',\
NetErrorLogWrite,'NetErrorLogWrite',\
NetFileClose,'NetFileClose',\
NetFileEnum,'NetFileEnum',\
NetFileGetInfo,'NetFileGetInfo',\
NetGetAnyDCName,'NetGetAnyDCName',\
NetGetDCName,'NetGetDCName',\
NetGetDisplayInformationIndex,'NetGetDisplayInformationIndex',\
NetGetJoinInformation,'NetGetJoinInformation',\
NetGetJoinableOUs,'NetGetJoinableOUs',\
NetGroupAdd,'NetGroupAdd',\
NetGroupAddUser,'NetGroupAddUser',\
NetGroupDel,'NetGroupDel',\
NetGroupDelUser,'NetGroupDelUser',\
NetGroupEnum,'NetGroupEnum',\
NetGroupGetInfo,'NetGroupGetInfo',\
NetGroupGetUsers,'NetGroupGetUsers',\
NetGroupSetInfo,'NetGroupSetInfo',\
NetGroupSetUsers,'NetGroupSetUsers',\
NetIsServiceAccount,'NetIsServiceAccount',\
NetJoinDomain,'NetJoinDomain',\
NetLocalGroupAdd,'NetLocalGroupAdd',\
NetLocalGroupAddMember,'NetLocalGroupAddMember',\
NetLocalGroupAddMembers,'NetLocalGroupAddMembers',\
NetLocalGroupDel,'NetLocalGroupDel',\
NetLocalGroupDelMember,'NetLocalGroupDelMember',\
NetLocalGroupDelMembers,'NetLocalGroupDelMembers',\
NetLocalGroupEnum,'NetLocalGroupEnum',\
NetLocalGroupGetInfo,'NetLocalGroupGetInfo',\
NetLocalGroupGetMembers,'NetLocalGroupGetMembers',\
NetLocalGroupSetInfo,'NetLocalGroupSetInfo',\
NetLocalGroupSetMembers,'NetLocalGroupSetMembers',\
NetLogonGetTimeServiceParentDomain,'NetLogonGetTimeServiceParentDomain',\
NetLogonSetServiceBits,'NetLogonSetServiceBits',\
NetMessageBufferSend,'NetMessageBufferSend',\
NetMessageNameAdd,'NetMessageNameAdd',\
NetMessageNameDel,'NetMessageNameDel',\
NetMessageNameEnum,'NetMessageNameEnum',\
NetMessageNameGetInfo,'NetMessageNameGetInfo',\
NetProvisionComputerAccount,'NetProvisionComputerAccount',\
NetQueryDisplayInformation,'NetQueryDisplayInformation',\
NetQueryServiceAccount,'NetQueryServiceAccount',\
NetRegisterDomainNameChangeNotification,'NetRegisterDomainNameChangeNotification',\
NetRemoteComputerSupports,'NetRemoteComputerSupports',\
NetRemoteTOD,'NetRemoteTOD',\
NetRemoveAlternateComputerName,'NetRemoveAlternateComputerName',\
NetRemoveServiceAccount,'NetRemoveServiceAccount',\
NetRenameMachineInDomain,'NetRenameMachineInDomain',\
NetReplExportDirAdd,'NetReplExportDirAdd',\
NetReplExportDirDel,'NetReplExportDirDel',\
NetReplExportDirEnum,'NetReplExportDirEnum',\
NetReplExportDirGetInfo,'NetReplExportDirGetInfo',\
NetReplExportDirLock,'NetReplExportDirLock',\
NetReplExportDirSetInfo,'NetReplExportDirSetInfo',\
NetReplExportDirUnlock,'NetReplExportDirUnlock',\
NetReplGetInfo,'NetReplGetInfo',\
NetReplImportDirAdd,'NetReplImportDirAdd',\
NetReplImportDirDel,'NetReplImportDirDel',\
NetReplImportDirEnum,'NetReplImportDirEnum',\
NetReplImportDirGetInfo,'NetReplImportDirGetInfo',\
NetReplImportDirLock,'NetReplImportDirLock',\
NetReplImportDirUnlock,'NetReplImportDirUnlock',\
NetReplSetInfo,'NetReplSetInfo',\
NetRequestOfflineDomainJoin,'NetRequestOfflineDomainJoin',\
NetScheduleJobAdd,'NetScheduleJobAdd',\
NetScheduleJobDel,'NetScheduleJobDel',\
NetScheduleJobEnum,'NetScheduleJobEnum',\
NetScheduleJobGetInfo,'NetScheduleJobGetInfo',\
NetServerAliasAdd,'NetServerAliasAdd',\
NetServerAliasDel,'NetServerAliasDel',\
NetServerAliasEnum,'NetServerAliasEnum',\
NetServerComputerNameAdd,'NetServerComputerNameAdd',\
NetServerComputerNameDel,'NetServerComputerNameDel',\
NetServerDiskEnum,'NetServerDiskEnum',\
NetServerEnum,'NetServerEnum',\
NetServerEnumEx,'NetServerEnumEx',\
NetServerGetInfo,'NetServerGetInfo',\
NetServerSetInfo,'NetServerSetInfo',\
NetServerTransportAdd,'NetServerTransportAdd',\
NetServerTransportAddEx,'NetServerTransportAddEx',\
NetServerTransportDel,'NetServerTransportDel',\
NetServerTransportEnum,'NetServerTransportEnum',\
NetServiceControl,'NetServiceControl',\
NetServiceEnum,'NetServiceEnum',\
NetServiceGetInfo,'NetServiceGetInfo',\
NetServiceInstall,'NetServiceInstall',\
NetSessionDel,'NetSessionDel',\
NetSessionEnum,'NetSessionEnum',\
NetSessionGetInfo,'NetSessionGetInfo',\
NetSetPrimaryComputerName,'NetSetPrimaryComputerName',\
NetShareAdd,'NetShareAdd',\
NetShareCheck,'NetShareCheck',\
NetShareDel,'NetShareDel',\
NetShareDelEx,'NetShareDelEx',\
NetShareDelSticky,'NetShareDelSticky',\
NetShareEnum,'NetShareEnum',\
NetShareEnumSticky,'NetShareEnumSticky',\
NetShareGetInfo,'NetShareGetInfo',\
NetShareSetInfo,'NetShareSetInfo',\
NetStatisticsGet,'NetStatisticsGet',\
NetUnjoinDomain,'NetUnjoinDomain',\
NetUnregisterDomainNameChangeNotification,'NetUnregisterDomainNameChangeNotification',\
NetUseAdd,'NetUseAdd',\
NetUseDel,'NetUseDel',\
NetUseEnum,'NetUseEnum',\
NetUseGetInfo,'NetUseGetInfo',\
NetUserAdd,'NetUserAdd',\
NetUserChangePassword,'NetUserChangePassword',\
NetUserDel,'NetUserDel',\
NetUserEnum,'NetUserEnum',\
NetUserGetGroups,'NetUserGetGroups',\
NetUserGetInfo,'NetUserGetInfo',\
NetUserGetLocalGroups,'NetUserGetLocalGroups',\
NetUserModalsGet,'NetUserModalsGet',\
NetUserModalsSet,'NetUserModalsSet',\
NetUserSetGroups,'NetUserSetGroups',\
NetUserSetInfo,'NetUserSetInfo',\
NetValidateName,'NetValidateName',\
NetValidatePasswordPolicy,'NetValidatePasswordPolicy',\
NetValidatePasswordPolicyFree,'NetValidatePasswordPolicyFree',\
NetWkstaGetInfo,'NetWkstaGetInfo',\
NetWkstaSetInfo,'NetWkstaSetInfo',\
NetWkstaTransportAdd,'NetWkstaTransportAdd',\
NetWkstaTransportDel,'NetWkstaTransportDel',\
NetWkstaTransportEnum,'NetWkstaTransportEnum',\
NetWkstaUserEnum,'NetWkstaUserEnum',\
NetWkstaUserGetInfo,'NetWkstaUserGetInfo',\
NetWkstaUserSetInfo,'NetWkstaUserSetInfo',\
NetapipBufferAllocate,'NetapipBufferAllocate',\
Netbios,'Netbios',\
NetpAssertFailed,'NetpAssertFailed',\
NetpCloseConfigData,'NetpCloseConfigData',\
NetpDbgPrint,'NetpDbgPrint',\
NetpGetConfigBool,'NetpGetConfigBool',\
NetpGetConfigDword,'NetpGetConfigDword',\
NetpGetConfigTStrArray,'NetpGetConfigTStrArray',\
NetpGetConfigValue,'NetpGetConfigValue',\
NetpGetFileSecurity,'NetpGetFileSecurity',\
NetpHexDump,'NetpHexDump',\
NetpInitFtinfoContext,'NetpInitFtinfoContext',\
NetpIsRemote,'NetpIsRemote',\
NetpIsUncComputerNameValid,'NetpIsUncComputerNameValid',\
NetpMergeFtinfo,'NetpMergeFtinfo',\
NetpNetBiosReset,'NetpNetBiosReset',\
NetpNetBiosStatusToApiStatus,'NetpNetBiosStatusToApiStatus',\
NetpOpenConfigData,'NetpOpenConfigData',\
NetpSetFileSecurity,'NetpSetFileSecurity',\
NetpwNameCanonicalize,'NetpwNameCanonicalize',\
NetpwNameCompare,'NetpwNameCompare',\
NetpwNameValidate,'NetpwNameValidate',\
NetpwPathCanonicalize,'NetpwPathCanonicalize',\
NetpwPathCompare,'NetpwPathCompare',\
NetpwPathType,'NetpwPathType',\
NlBindingAddServerToCache,'NlBindingAddServerToCache',\
NlBindingRemoveServerFromCache,'NlBindingRemoveServerFromCache',\
NlBindingSetAuthInfo,'NlBindingSetAuthInfo',\
RxNetAccessAdd,'RxNetAccessAdd',\
RxNetAccessDel,'RxNetAccessDel',\
RxNetAccessEnum,'RxNetAccessEnum',\
RxNetAccessGetInfo,'RxNetAccessGetInfo',\
RxNetAccessGetUserPerms,'RxNetAccessGetUserPerms',\
RxNetAccessSetInfo,'RxNetAccessSetInfo',\
RxNetServerEnum,'RxNetServerEnum',\
RxNetUserPasswordSet,'RxNetUserPasswordSet',\
RxRemoteApi,'RxRemoteApi'

DsGetDcClose equ DsGetDcCloseW
DsGetForestTrustInformation equ DsGetForestTrustInformationW
DsMergeForestTrustInformation equ DsMergeForestTrustInformationW
api DsAddressToSiteNames,\
    DsAddressToSiteNamesEx,\
    DsDeregisterDnsHostRecords,\
    DsEnumerateDomainTrusts,\
    DsGetDcName,\
    DsGetDcNameWithAccount,\
    DsGetDcNext,\
    DsGetDcOpen,\
    DsGetDcSiteCoverage,\
    DsGetSiteName,\
    DsValidateSubnetName

;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
    ;extrn '__imp__NetDfsManagerGetConfigInfo' as NetDfsManagerGetConfigInfo:qword
    ;extrn '__imp__NetpAddTlnFtinfoEntry' as NetpAddTlnFtinfoEntry:qword
    ;extrn '__imp__NetpAllocFtinfoEntry' as NetpAllocFtinfoEntry:qword
    ;extrn '__imp__NetpCleanFtinfoContext' as NetpCleanFtinfoContext:qword
    ;extrn '__imp__NetpCopyFtinfoContext' as NetpCopyFtinfoContext:qword
;else
    ;extrn '__imp__NetDfsManagerGetConfigInfo@??' as NetDfsManagerGetConfigInfo:dword
    ;extrn '__imp__NetpAddTlnFtinfoEntry@??' as NetpAddTlnFtinfoEntry:dword
    ;extrn '__imp__NetpAllocFtinfoEntry@??' as NetpAllocFtinfoEntry:dword
    ;extrn '__imp__NetpCleanFtinfoContext@??' as NetpCleanFtinfoContext:dword
    ;extrn '__imp__NetpCopyFtinfoContext@??' as NetpCopyFtinfoContext:dword
;end if


end if ;NETAPI32_INC
