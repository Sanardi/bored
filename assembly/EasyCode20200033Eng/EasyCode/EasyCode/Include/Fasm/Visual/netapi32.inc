; ====================================================;
;                                                     ;
;     netapi32.inc for EC v2 Fasm visual projects     ;
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
if defined APP_WIN64
    extrn '__imp_DsAddressToSiteNamesA' as DsAddressToSiteNamesA:qword
    extrn '__imp_DsAddressToSiteNamesExA' as DsAddressToSiteNamesExA:qword
    extrn '__imp_DsAddressToSiteNamesExW' as DsAddressToSiteNamesExW:qword
    extrn '__imp_DsAddressToSiteNamesW' as DsAddressToSiteNamesW:qword
    extrn '__imp_DsDeregisterDnsHostRecordsA' as DsDeregisterDnsHostRecordsA:qword
    extrn '__imp_DsDeregisterDnsHostRecordsW' as DsDeregisterDnsHostRecordsW:qword
    extrn '__imp_DsEnumerateDomainTrustsA' as DsEnumerateDomainTrustsA:qword
    extrn '__imp_DsEnumerateDomainTrustsW' as DsEnumerateDomainTrustsW:qword
    extrn '__imp_DsGetDcCloseW' as DsGetDcCloseW:qword
    extrn '__imp_DsGetDcNameA' as DsGetDcNameA:qword
    extrn '__imp_DsGetDcNameW' as DsGetDcNameW:qword
    extrn '__imp_DsGetDcNameWithAccountA' as DsGetDcNameWithAccountA:qword
    extrn '__imp_DsGetDcNameWithAccountW' as DsGetDcNameWithAccountW:qword
    extrn '__imp_DsGetDcNextA' as DsGetDcNextA:qword
    extrn '__imp_DsGetDcNextW' as DsGetDcNextW:qword
    extrn '__imp_DsGetDcOpenA' as DsGetDcOpenA:qword
    extrn '__imp_DsGetDcOpenW' as DsGetDcOpenW:qword
    extrn '__imp_DsGetDcSiteCoverageA' as DsGetDcSiteCoverageA:qword
    extrn '__imp_DsGetDcSiteCoverageW' as DsGetDcSiteCoverageW:qword
    extrn '__imp_DsGetForestTrustInformationW' as DsGetForestTrustInformationW:qword
    extrn '__imp_DsGetSiteNameA' as DsGetSiteNameA:qword
    extrn '__imp_DsGetSiteNameW' as DsGetSiteNameW:qword
    extrn '__imp_DsMergeForestTrustInformationW' as DsMergeForestTrustInformationW:qword
    extrn '__imp_DsRoleAbortDownlevelServerUpgrade' as DsRoleAbortDownlevelServerUpgrade:qword
    extrn '__imp_DsRoleCancel' as DsRoleCancel:qword
    extrn '__imp_DsRoleDcAsDc' as DsRoleDcAsDc:qword
    extrn '__imp_DsRoleDcAsReplica' as DsRoleDcAsReplica:qword
    extrn '__imp_DsRoleDemoteDc' as DsRoleDemoteDc:qword
    extrn '__imp_DsRoleDnsNameToFlatName' as DsRoleDnsNameToFlatName:qword
    extrn '__imp_DsRoleFreeMemory' as DsRoleFreeMemory:qword
    extrn '__imp_DsRoleGetDatabaseFacts' as DsRoleGetDatabaseFacts:qword
    extrn '__imp_DsRoleGetDcOperationProgress' as DsRoleGetDcOperationProgress:qword
    extrn '__imp_DsRoleGetDcOperationResults' as DsRoleGetDcOperationResults:qword
    extrn '__imp_DsRoleGetPrimaryDomainInformation' as DsRoleGetPrimaryDomainInformation:qword
    extrn '__imp_DsRoleIfmHandleFree' as DsRoleIfmHandleFree:qword
    extrn '__imp_DsRoleServerSaveStateForUpgrade' as DsRoleServerSaveStateForUpgrade:qword
    extrn '__imp_DsRoleUpgradeDownlevelServer' as DsRoleUpgradeDownlevelServer:qword
    extrn '__imp_DsValidateSubnetNameA' as DsValidateSubnetNameA:qword
    extrn '__imp_DsValidateSubnetNameW' as DsValidateSubnetNameW:qword
    extrn '__imp_I_BrowserDebugCall' as I_BrowserDebugCall:qword
    extrn '__imp_I_BrowserDebugTrace' as I_BrowserDebugTrace:qword
    extrn '__imp_I_BrowserQueryEmulatedDomains' as I_BrowserQueryEmulatedDomains:qword
    extrn '__imp_I_BrowserQueryOtherDomains' as I_BrowserQueryOtherDomains:qword
    extrn '__imp_I_BrowserQueryStatistics' as I_BrowserQueryStatistics:qword
    extrn '__imp_I_BrowserResetNetlogonState' as I_BrowserResetNetlogonState:qword
    extrn '__imp_I_BrowserResetStatistics' as I_BrowserResetStatistics:qword
    extrn '__imp_I_BrowserServerEnum' as I_BrowserServerEnum:qword
    extrn '__imp_I_BrowserSetNetlogonState' as I_BrowserSetNetlogonState:qword
    extrn '__imp_I_DsUpdateReadOnlyServerDnsRecords' as I_DsUpdateReadOnlyServerDnsRecords:qword
    extrn '__imp_I_NetAccountDeltas' as I_NetAccountDeltas:qword
    extrn '__imp_I_NetAccountSync' as I_NetAccountSync:qword
    extrn '__imp_I_NetChainSetClientAttributes' as I_NetChainSetClientAttributes:qword
    extrn '__imp_I_NetChainSetClientAttributes2' as I_NetChainSetClientAttributes2:qword
    extrn '__imp_I_NetDatabaseDeltas' as I_NetDatabaseDeltas:qword
    extrn '__imp_I_NetDatabaseRedo' as I_NetDatabaseRedo:qword
    extrn '__imp_I_NetDatabaseSync' as I_NetDatabaseSync:qword
    extrn '__imp_I_NetDatabaseSync2' as I_NetDatabaseSync2:qword
    extrn '__imp_I_NetDfsGetVersion' as I_NetDfsGetVersion:qword
    extrn '__imp_I_NetDfsIsThisADomainName' as I_NetDfsIsThisADomainName:qword
    extrn '__imp_I_NetGetDCList' as I_NetGetDCList:qword
    extrn '__imp_I_NetGetForestTrustInformation' as I_NetGetForestTrustInformation:qword
    extrn '__imp_I_NetLogonControl' as I_NetLogonControl:qword
    extrn '__imp_I_NetLogonControl2' as I_NetLogonControl2:qword
    extrn '__imp_I_NetLogonGetDomainInfo' as I_NetLogonGetDomainInfo:qword
    extrn '__imp_I_NetLogonSamLogoff' as I_NetLogonSamLogoff:qword
    extrn '__imp_I_NetLogonSamLogon' as I_NetLogonSamLogon:qword
    extrn '__imp_I_NetLogonSamLogonEx' as I_NetLogonSamLogonEx:qword
    extrn '__imp_I_NetLogonSamLogonWithFlags' as I_NetLogonSamLogonWithFlags:qword
    extrn '__imp_I_NetLogonSendToSam' as I_NetLogonSendToSam:qword
    extrn '__imp_I_NetLogonUasLogoff' as I_NetLogonUasLogoff:qword
    extrn '__imp_I_NetLogonUasLogon' as I_NetLogonUasLogon:qword
    extrn '__imp_I_NetServerAuthenticate' as I_NetServerAuthenticate:qword
    extrn '__imp_I_NetServerAuthenticate2' as I_NetServerAuthenticate2:qword
    extrn '__imp_I_NetServerAuthenticate3' as I_NetServerAuthenticate3:qword
    extrn '__imp_I_NetServerGetTrustInfo' as I_NetServerGetTrustInfo:qword
    extrn '__imp_I_NetServerPasswordGet' as I_NetServerPasswordGet:qword
    extrn '__imp_I_NetServerPasswordSet' as I_NetServerPasswordSet:qword
    extrn '__imp_I_NetServerPasswordSet2' as I_NetServerPasswordSet2:qword
    extrn '__imp_I_NetServerReqChallenge' as I_NetServerReqChallenge:qword
    extrn '__imp_I_NetServerSetServiceBits' as I_NetServerSetServiceBits:qword
    extrn '__imp_I_NetServerSetServiceBitsEx' as I_NetServerSetServiceBitsEx:qword
    extrn '__imp_I_NetServerTrustPasswordsGet' as I_NetServerTrustPasswordsGet:qword
    extrn '__imp_I_NetlogonComputeClientDigest' as I_NetlogonComputeClientDigest:qword
    extrn '__imp_NetAddAlternateComputerName' as NetAddAlternateComputerName:qword
    extrn '__imp_NetAddServiceAccount' as NetAddServiceAccount:qword
    extrn '__imp_NetAlertRaise' as NetAlertRaise:qword
    extrn '__imp_NetAlertRaiseEx' as NetAlertRaiseEx:qword
    extrn '__imp_NetApiBufferAllocate' as NetApiBufferAllocate:qword
    extrn '__imp_NetApiBufferFree' as NetApiBufferFree:qword
    extrn '__imp_NetApiBufferReallocate' as NetApiBufferReallocate:qword
    extrn '__imp_NetApiBufferSize' as NetApiBufferSize:qword
    extrn '__imp_NetAuditClear' as NetAuditClear:qword
    extrn '__imp_NetAuditRead' as NetAuditRead:qword
    extrn '__imp_NetAuditWrite' as NetAuditWrite:qword
    extrn '__imp_NetBrowserStatisticsGet' as NetBrowserStatisticsGet:qword
    extrn '__imp_NetConfigGet' as NetConfigGet:qword
    extrn '__imp_NetConfigGetAll' as NetConfigGetAll:qword
    extrn '__imp_NetConfigSet' as NetConfigSet:qword
    extrn '__imp_NetConnectionEnum' as NetConnectionEnum:qword
    extrn '__imp_NetDfsAdd' as NetDfsAdd:qword
    extrn '__imp_NetDfsAddFtRoot' as NetDfsAddFtRoot:qword
    extrn '__imp_NetDfsAddRootTarget' as NetDfsAddRootTarget:qword
    extrn '__imp_NetDfsAddStdRoot' as NetDfsAddStdRoot:qword
    extrn '__imp_NetDfsAddStdRootForced' as NetDfsAddStdRootForced:qword
    extrn '__imp_NetDfsEnum' as NetDfsEnum:qword
    extrn '__imp_NetDfsGetClientInfo' as NetDfsGetClientInfo:qword
    extrn '__imp_NetDfsGetDcAddress' as NetDfsGetDcAddress:qword
    extrn '__imp_NetDfsGetFtContainerSecurity' as NetDfsGetFtContainerSecurity:qword
    extrn '__imp_NetDfsGetInfo' as NetDfsGetInfo:qword
    extrn '__imp_NetDfsGetSecurity' as NetDfsGetSecurity:qword
    extrn '__imp_NetDfsGetStdContainerSecurity' as NetDfsGetStdContainerSecurity:qword
    extrn '__imp_NetDfsGetSupportedNamespaceVersion' as NetDfsGetSupportedNamespaceVersion:qword
    extrn '__imp_NetDfsManagerInitialize' as NetDfsManagerInitialize:qword
    extrn '__imp_NetDfsManagerSendSiteInfo' as NetDfsManagerSendSiteInfo:qword
    extrn '__imp_NetDfsMove' as NetDfsMove:qword
    extrn '__imp_NetDfsRemove' as NetDfsRemove:qword
    extrn '__imp_NetDfsRemoveFtRoot' as NetDfsRemoveFtRoot:qword
    extrn '__imp_NetDfsRemoveFtRootForced' as NetDfsRemoveFtRootForced:qword
    extrn '__imp_NetDfsRemoveRootTarget' as NetDfsRemoveRootTarget:qword
    extrn '__imp_NetDfsRemoveStdRoot' as NetDfsRemoveStdRoot:qword
    extrn '__imp_NetDfsRename' as NetDfsRename:qword
    extrn '__imp_NetDfsSetClientInfo' as NetDfsSetClientInfo:qword
    extrn '__imp_NetDfsSetFtContainerSecurity' as NetDfsSetFtContainerSecurity:qword
    extrn '__imp_NetDfsSetInfo' as NetDfsSetInfo:qword
    extrn '__imp_NetDfsSetSecurity' as NetDfsSetSecurity:qword
    extrn '__imp_NetDfsSetStdContainerSecurity' as NetDfsSetStdContainerSecurity:qword
    extrn '__imp_NetEnumerateComputerNames' as NetEnumerateComputerNames:qword
    extrn '__imp_NetEnumerateServiceAccounts' as NetEnumerateServiceAccounts:qword
    extrn '__imp_NetEnumerateTrustedDomains' as NetEnumerateTrustedDomains:qword
    extrn '__imp_NetErrorLogClear' as NetErrorLogClear:qword
    extrn '__imp_NetErrorLogRead' as NetErrorLogRead:qword
    extrn '__imp_NetErrorLogWrite' as NetErrorLogWrite:qword
    extrn '__imp_NetFileClose' as NetFileClose:qword
    extrn '__imp_NetFileEnum' as NetFileEnum:qword
    extrn '__imp_NetFileGetInfo' as NetFileGetInfo:qword
    extrn '__imp_NetGetAnyDCName' as NetGetAnyDCName:qword
    extrn '__imp_NetGetDCName' as NetGetDCName:qword
    extrn '__imp_NetGetDisplayInformationIndex' as NetGetDisplayInformationIndex:qword
    extrn '__imp_NetGetJoinInformation' as NetGetJoinInformation:qword
    extrn '__imp_NetGetJoinableOUs' as NetGetJoinableOUs:qword
    extrn '__imp_NetGroupAdd' as NetGroupAdd:qword
    extrn '__imp_NetGroupAddUser' as NetGroupAddUser:qword
    extrn '__imp_NetGroupDel' as NetGroupDel:qword
    extrn '__imp_NetGroupDelUser' as NetGroupDelUser:qword
    extrn '__imp_NetGroupEnum' as NetGroupEnum:qword
    extrn '__imp_NetGroupGetInfo' as NetGroupGetInfo:qword
    extrn '__imp_NetGroupGetUsers' as NetGroupGetUsers:qword
    extrn '__imp_NetGroupSetInfo' as NetGroupSetInfo:qword
    extrn '__imp_NetGroupSetUsers' as NetGroupSetUsers:qword
    extrn '__imp_NetIsServiceAccount' as NetIsServiceAccount:qword
    extrn '__imp_NetJoinDomain' as NetJoinDomain:qword
    extrn '__imp_NetLocalGroupAdd' as NetLocalGroupAdd:qword
    extrn '__imp_NetLocalGroupAddMember' as NetLocalGroupAddMember:qword
    extrn '__imp_NetLocalGroupAddMembers' as NetLocalGroupAddMembers:qword
    extrn '__imp_NetLocalGroupDel' as NetLocalGroupDel:qword
    extrn '__imp_NetLocalGroupDelMember' as NetLocalGroupDelMember:qword
    extrn '__imp_NetLocalGroupDelMembers' as NetLocalGroupDelMembers:qword
    extrn '__imp_NetLocalGroupEnum' as NetLocalGroupEnum:qword
    extrn '__imp_NetLocalGroupGetInfo' as NetLocalGroupGetInfo:qword
    extrn '__imp_NetLocalGroupGetMembers' as NetLocalGroupGetMembers:qword
    extrn '__imp_NetLocalGroupSetInfo' as NetLocalGroupSetInfo:qword
    extrn '__imp_NetLocalGroupSetMembers' as NetLocalGroupSetMembers:qword
    extrn '__imp_NetLogonGetTimeServiceParentDomain' as NetLogonGetTimeServiceParentDomain:qword
    extrn '__imp_NetLogonSetServiceBits' as NetLogonSetServiceBits:qword
    extrn '__imp_NetMessageBufferSend' as NetMessageBufferSend:qword
    extrn '__imp_NetMessageNameAdd' as NetMessageNameAdd:qword
    extrn '__imp_NetMessageNameDel' as NetMessageNameDel:qword
    extrn '__imp_NetMessageNameEnum' as NetMessageNameEnum:qword
    extrn '__imp_NetMessageNameGetInfo' as NetMessageNameGetInfo:qword
    extrn '__imp_NetProvisionComputerAccount' as NetProvisionComputerAccount:qword
    extrn '__imp_NetQueryDisplayInformation' as NetQueryDisplayInformation:qword
    extrn '__imp_NetQueryServiceAccount' as NetQueryServiceAccount:qword
    extrn '__imp_NetRegisterDomainNameChangeNotification' as NetRegisterDomainNameChangeNotification:qword
    extrn '__imp_NetRemoteComputerSupports' as NetRemoteComputerSupports:qword
    extrn '__imp_NetRemoteTOD' as NetRemoteTOD:qword
    extrn '__imp_NetRemoveAlternateComputerName' as NetRemoveAlternateComputerName:qword
    extrn '__imp_NetRemoveServiceAccount' as NetRemoveServiceAccount:qword
    extrn '__imp_NetRenameMachineInDomain' as NetRenameMachineInDomain:qword
    extrn '__imp_NetReplExportDirAdd' as NetReplExportDirAdd:qword
    extrn '__imp_NetReplExportDirDel' as NetReplExportDirDel:qword
    extrn '__imp_NetReplExportDirEnum' as NetReplExportDirEnum:qword
    extrn '__imp_NetReplExportDirGetInfo' as NetReplExportDirGetInfo:qword
    extrn '__imp_NetReplExportDirLock' as NetReplExportDirLock:qword
    extrn '__imp_NetReplExportDirSetInfo' as NetReplExportDirSetInfo:qword
    extrn '__imp_NetReplExportDirUnlock' as NetReplExportDirUnlock:qword
    extrn '__imp_NetReplGetInfo' as NetReplGetInfo:qword
    extrn '__imp_NetReplImportDirAdd' as NetReplImportDirAdd:qword
    extrn '__imp_NetReplImportDirDel' as NetReplImportDirDel:qword
    extrn '__imp_NetReplImportDirEnum' as NetReplImportDirEnum:qword
    extrn '__imp_NetReplImportDirGetInfo' as NetReplImportDirGetInfo:qword
    extrn '__imp_NetReplImportDirLock' as NetReplImportDirLock:qword
    extrn '__imp_NetReplImportDirUnlock' as NetReplImportDirUnlock:qword
    extrn '__imp_NetReplSetInfo' as NetReplSetInfo:qword
    extrn '__imp_NetRequestOfflineDomainJoin' as NetRequestOfflineDomainJoin:qword
    extrn '__imp_NetScheduleJobAdd' as NetScheduleJobAdd:qword
    extrn '__imp_NetScheduleJobDel' as NetScheduleJobDel:qword
    extrn '__imp_NetScheduleJobEnum' as NetScheduleJobEnum:qword
    extrn '__imp_NetScheduleJobGetInfo' as NetScheduleJobGetInfo:qword
    extrn '__imp_NetServerAliasAdd' as NetServerAliasAdd:qword
    extrn '__imp_NetServerAliasDel' as NetServerAliasDel:qword
    extrn '__imp_NetServerAliasEnum' as NetServerAliasEnum:qword
    extrn '__imp_NetServerComputerNameAdd' as NetServerComputerNameAdd:qword
    extrn '__imp_NetServerComputerNameDel' as NetServerComputerNameDel:qword
    extrn '__imp_NetServerDiskEnum' as NetServerDiskEnum:qword
    extrn '__imp_NetServerEnum' as NetServerEnum:qword
    extrn '__imp_NetServerEnumEx' as NetServerEnumEx:qword
    extrn '__imp_NetServerGetInfo' as NetServerGetInfo:qword
    extrn '__imp_NetServerSetInfo' as NetServerSetInfo:qword
    extrn '__imp_NetServerTransportAdd' as NetServerTransportAdd:qword
    extrn '__imp_NetServerTransportAddEx' as NetServerTransportAddEx:qword
    extrn '__imp_NetServerTransportDel' as NetServerTransportDel:qword
    extrn '__imp_NetServerTransportEnum' as NetServerTransportEnum:qword
    extrn '__imp_NetServiceControl' as NetServiceControl:qword
    extrn '__imp_NetServiceEnum' as NetServiceEnum:qword
    extrn '__imp_NetServiceGetInfo' as NetServiceGetInfo:qword
    extrn '__imp_NetServiceInstall' as NetServiceInstall:qword
    extrn '__imp_NetSessionDel' as NetSessionDel:qword
    extrn '__imp_NetSessionEnum' as NetSessionEnum:qword
    extrn '__imp_NetSessionGetInfo' as NetSessionGetInfo:qword
    extrn '__imp_NetSetPrimaryComputerName' as NetSetPrimaryComputerName:qword
    extrn '__imp_NetShareAdd' as NetShareAdd:qword
    extrn '__imp_NetShareCheck' as NetShareCheck:qword
    extrn '__imp_NetShareDel' as NetShareDel:qword
    extrn '__imp_NetShareDelEx' as NetShareDelEx:qword
    extrn '__imp_NetShareDelSticky' as NetShareDelSticky:qword
    extrn '__imp_NetShareEnum' as NetShareEnum:qword
    extrn '__imp_NetShareEnumSticky' as NetShareEnumSticky:qword
    extrn '__imp_NetShareGetInfo' as NetShareGetInfo:qword
    extrn '__imp_NetShareSetInfo' as NetShareSetInfo:qword
    extrn '__imp_NetStatisticsGet' as NetStatisticsGet:qword
    extrn '__imp_NetUnjoinDomain' as NetUnjoinDomain:qword
    extrn '__imp_NetUnregisterDomainNameChangeNotification' as NetUnregisterDomainNameChangeNotification:qword
    extrn '__imp_NetUseAdd' as NetUseAdd:qword
    extrn '__imp_NetUseDel' as NetUseDel:qword
    extrn '__imp_NetUseEnum' as NetUseEnum:qword
    extrn '__imp_NetUseGetInfo' as NetUseGetInfo:qword
    extrn '__imp_NetUserAdd' as NetUserAdd:qword
    extrn '__imp_NetUserChangePassword' as NetUserChangePassword:qword
    extrn '__imp_NetUserDel' as NetUserDel:qword
    extrn '__imp_NetUserEnum' as NetUserEnum:qword
    extrn '__imp_NetUserGetGroups' as NetUserGetGroups:qword
    extrn '__imp_NetUserGetInfo' as NetUserGetInfo:qword
    extrn '__imp_NetUserGetLocalGroups' as NetUserGetLocalGroups:qword
    extrn '__imp_NetUserModalsGet' as NetUserModalsGet:qword
    extrn '__imp_NetUserModalsSet' as NetUserModalsSet:qword
    extrn '__imp_NetUserSetGroups' as NetUserSetGroups:qword
    extrn '__imp_NetUserSetInfo' as NetUserSetInfo:qword
    extrn '__imp_NetValidateName' as NetValidateName:qword
    extrn '__imp_NetValidatePasswordPolicy' as NetValidatePasswordPolicy:qword
    extrn '__imp_NetValidatePasswordPolicyFree' as NetValidatePasswordPolicyFree:qword
    extrn '__imp_NetWkstaGetInfo' as NetWkstaGetInfo:qword
    extrn '__imp_NetWkstaSetInfo' as NetWkstaSetInfo:qword
    extrn '__imp_NetWkstaTransportAdd' as NetWkstaTransportAdd:qword
    extrn '__imp_NetWkstaTransportDel' as NetWkstaTransportDel:qword
    extrn '__imp_NetWkstaTransportEnum' as NetWkstaTransportEnum:qword
    extrn '__imp_NetWkstaUserEnum' as NetWkstaUserEnum:qword
    extrn '__imp_NetWkstaUserGetInfo' as NetWkstaUserGetInfo:qword
    extrn '__imp_NetWkstaUserSetInfo' as NetWkstaUserSetInfo:qword
    extrn '__imp_NetapipBufferAllocate' as NetapipBufferAllocate:qword
    extrn '__imp_Netbios' as Netbios:qword
    extrn '__imp_NetpAssertFailed' as NetpAssertFailed:qword
    extrn '__imp_NetpCloseConfigData' as NetpCloseConfigData:qword
    extrn '__imp_NetpDbgPrint' as NetpDbgPrint:qword
    extrn '__imp_NetpGetConfigBool' as NetpGetConfigBool:qword
    extrn '__imp_NetpGetConfigDword' as NetpGetConfigDword:qword
    extrn '__imp_NetpGetConfigTStrArray' as NetpGetConfigTStrArray:qword
    extrn '__imp_NetpGetConfigValue' as NetpGetConfigValue:qword
    extrn '__imp_NetpGetFileSecurity' as NetpGetFileSecurity:qword
    extrn '__imp_NetpHexDump' as NetpHexDump:qword
    extrn '__imp_NetpInitFtinfoContext' as NetpInitFtinfoContext:qword
    extrn '__imp_NetpIsRemote' as NetpIsRemote:qword
    extrn '__imp_NetpIsUncComputerNameValid' as NetpIsUncComputerNameValid:qword
    extrn '__imp_NetpMergeFtinfo' as NetpMergeFtinfo:qword
    extrn '__imp_NetpNetBiosReset' as NetpNetBiosReset:qword
    extrn '__imp_NetpNetBiosStatusToApiStatus' as NetpNetBiosStatusToApiStatus:qword
    extrn '__imp_NetpOpenConfigData' as NetpOpenConfigData:qword
    extrn '__imp_NetpSetFileSecurity' as NetpSetFileSecurity:qword
    extrn '__imp_NetpwNameCanonicalize' as NetpwNameCanonicalize:qword
    extrn '__imp_NetpwNameCompare' as NetpwNameCompare:qword
    extrn '__imp_NetpwNameValidate' as NetpwNameValidate:qword
    extrn '__imp_NetpwPathCanonicalize' as NetpwPathCanonicalize:qword
    extrn '__imp_NetpwPathCompare' as NetpwPathCompare:qword
    extrn '__imp_NetpwPathType' as NetpwPathType:qword
    extrn '__imp_NlBindingAddServerToCache' as NlBindingAddServerToCache:qword
    extrn '__imp_NlBindingRemoveServerFromCache' as NlBindingRemoveServerFromCache:qword
    extrn '__imp_NlBindingSetAuthInfo' as NlBindingSetAuthInfo:qword
    extrn '__imp_RxNetAccessAdd' as RxNetAccessAdd:qword
    extrn '__imp_RxNetAccessDel' as RxNetAccessDel:qword
    extrn '__imp_RxNetAccessEnum' as RxNetAccessEnum:qword
    extrn '__imp_RxNetAccessGetInfo' as RxNetAccessGetInfo:qword
    extrn '__imp_RxNetAccessGetUserPerms' as RxNetAccessGetUserPerms:qword
    extrn '__imp_RxNetAccessSetInfo' as RxNetAccessSetInfo:qword
    extrn '__imp_RxNetServerEnum' as RxNetServerEnum:qword
    extrn '__imp_RxNetUserPasswordSet' as RxNetUserPasswordSet:qword
    extrn '__imp_RxRemoteApi' as RxRemoteApi:qword
else
    extrn '__imp__DsAddressToSiteNamesA@16' as DsAddressToSiteNamesA:dword
    extrn '__imp__DsAddressToSiteNamesExA@20' as DsAddressToSiteNamesExA:dword
    extrn '__imp__DsAddressToSiteNamesExW@20' as DsAddressToSiteNamesExW:dword
    extrn '__imp__DsAddressToSiteNamesW@16' as DsAddressToSiteNamesW:dword
    extrn '__imp__DsDeregisterDnsHostRecordsA@20' as DsDeregisterDnsHostRecordsA:dword
    extrn '__imp__DsDeregisterDnsHostRecordsW@20' as DsDeregisterDnsHostRecordsW:dword
    extrn '__imp__DsEnumerateDomainTrustsA@16' as DsEnumerateDomainTrustsA:dword
    extrn '__imp__DsEnumerateDomainTrustsW@16' as DsEnumerateDomainTrustsW:dword
    extrn '__imp__DsGetDcCloseW@4' as DsGetDcCloseW:dword
    extrn '__imp__DsGetDcNameA@24' as DsGetDcNameA:dword
    extrn '__imp__DsGetDcNameW@24' as DsGetDcNameW:dword
    extrn '__imp__DsGetDcNameWithAccountA@32' as DsGetDcNameWithAccountA:dword
    extrn '__imp__DsGetDcNameWithAccountW@32' as DsGetDcNameWithAccountW:dword
    extrn '__imp__DsGetDcNextA@16' as DsGetDcNextA:dword
    extrn '__imp__DsGetDcNextW@16' as DsGetDcNextW:dword
    extrn '__imp__DsGetDcOpenA@28' as DsGetDcOpenA:dword
    extrn '__imp__DsGetDcOpenW@28' as DsGetDcOpenW:dword
    extrn '__imp__DsGetDcSiteCoverageA@12' as DsGetDcSiteCoverageA:dword
    extrn '__imp__DsGetDcSiteCoverageW@12' as DsGetDcSiteCoverageW:dword
    extrn '__imp__DsGetForestTrustInformationW@16' as DsGetForestTrustInformationW:dword
    extrn '__imp__DsGetSiteNameA@8' as DsGetSiteNameA:dword
    extrn '__imp__DsGetSiteNameW@8' as DsGetSiteNameW:dword
    extrn '__imp__DsMergeForestTrustInformationW@16' as DsMergeForestTrustInformationW:dword
    extrn '__imp__DsRoleAbortDownlevelServerUpgrade@16' as DsRoleAbortDownlevelServerUpgrade:dword
    extrn '__imp__DsRoleCancel@8' as DsRoleCancel:dword
    extrn '__imp__DsRoleDcAsDc@60' as DsRoleDcAsDc:dword
    extrn '__imp__DsRoleDcAsReplica@56' as DsRoleDcAsReplica:dword
    extrn '__imp__DsRoleDemoteDc@36' as DsRoleDemoteDc:dword
    extrn '__imp__DsRoleDnsNameToFlatName@16' as DsRoleDnsNameToFlatName:dword
    extrn '__imp__DsRoleFreeMemory@4' as DsRoleFreeMemory:dword
    extrn '__imp__DsRoleGetDatabaseFacts@16' as DsRoleGetDatabaseFacts:dword
    extrn '__imp__DsRoleGetDcOperationProgress@12' as DsRoleGetDcOperationProgress:dword
    extrn '__imp__DsRoleGetDcOperationResults@12' as DsRoleGetDcOperationResults:dword
    extrn '__imp__DsRoleGetPrimaryDomainInformation@12' as DsRoleGetPrimaryDomainInformation:dword
    ;extrn '__imp__DsRoleIfmHandleFree@8' as DsRoleIfmHandleFree:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__DsRoleServerSaveStateForUpgrade@4' as DsRoleServerSaveStateForUpgrade:dword
    extrn '__imp__DsRoleUpgradeDownlevelServer@48' as DsRoleUpgradeDownlevelServer:dword
    extrn '__imp__DsValidateSubnetNameA@4' as DsValidateSubnetNameA:dword
    extrn '__imp__DsValidateSubnetNameW@4' as DsValidateSubnetNameW:dword
    ;extrn '__imp__I_BrowserDebugCall@12' as I_BrowserDebugCall:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__I_BrowserDebugTrace@8' as I_BrowserDebugTrace:dword
    ;extrn '__imp__I_BrowserQueryEmulatedDomains@12' as I_BrowserQueryEmulatedDomains:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__I_BrowserQueryOtherDomains@16' as I_BrowserQueryOtherDomains:dword
    extrn '__imp__I_BrowserQueryStatistics@8' as I_BrowserQueryStatistics:dword
    extrn '__imp__I_BrowserResetNetlogonState@4' as I_BrowserResetNetlogonState:dword
    extrn '__imp__I_BrowserResetStatistics@4' as I_BrowserResetStatistics:dword
    extrn '__imp__I_BrowserServerEnum@44' as I_BrowserServerEnum:dword
    ;extrn '__imp__I_BrowserSetNetlogonState@16' as I_BrowserSetNetlogonState:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_DsUpdateReadOnlyServerDnsRecords@28' as I_DsUpdateReadOnlyServerDnsRecords:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetAccountDeltas@48' as I_NetAccountDeltas:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetAccountSync@48' as I_NetAccountSync:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetChainSetClientAttributes@36' as I_NetChainSetClientAttributes:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetChainSetClientAttributes2@36' as I_NetChainSetClientAttributes2:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetDatabaseDeltas@32' as I_NetDatabaseDeltas:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetDatabaseRedo@28' as I_NetDatabaseRedo:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetDatabaseSync@32' as I_NetDatabaseSync:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetDatabaseSync2@36' as I_NetDatabaseSync2:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetDfsGetVersion@8' as I_NetDfsGetVersion:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetDfsIsThisADomainName@4' as I_NetDfsIsThisADomainName:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetGetDCList@16' as I_NetGetDCList:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetGetForestTrustInformation@24' as I_NetGetForestTrustInformation:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__I_NetLogonControl@16' as I_NetLogonControl:dword
    extrn '__imp__I_NetLogonControl2@20' as I_NetLogonControl2:dword
    ;extrn '__imp__I_NetLogonGetDomainInfo@28' as I_NetLogonGetDomainInfo:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetLogonSamLogoff@24' as I_NetLogonSamLogoff:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetLogonSamLogon@36' as I_NetLogonSamLogon:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetLogonSamLogonEx@40' as I_NetLogonSamLogonEx:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetLogonSamLogonWithFlags@40' as I_NetLogonSamLogonWithFlags:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetLogonSendToSam@24' as I_NetLogonSendToSam:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetLogonUasLogoff@12' as I_NetLogonUasLogoff:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetLogonUasLogon@12' as I_NetLogonUasLogon:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetServerAuthenticate@24' as I_NetServerAuthenticate:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetServerAuthenticate2@28' as I_NetServerAuthenticate2:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetServerAuthenticate3@32' as I_NetServerAuthenticate3:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetServerGetTrustInfo@32' as I_NetServerGetTrustInfo:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__I_NetServerPasswordGet@28' as I_NetServerPasswordGet:dword
    ;extrn '__imp__I_NetServerPasswordSet@28' as I_NetServerPasswordSet:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__I_NetServerPasswordSet2@28' as I_NetServerPasswordSet2:dword
    ;extrn '__imp__I_NetServerReqChallenge@16' as I_NetServerReqChallenge:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetServerSetServiceBits@16' as I_NetServerSetServiceBits:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetServerSetServiceBitsEx@24' as I_NetServerSetServiceBitsEx:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetServerTrustPasswordsGet@32' as I_NetServerTrustPasswordsGet:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetlogonComputeClientDigest@24' as I_NetlogonComputeClientDigest:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__I_NetlogonComputeServerDigestt@24' as I_NetlogonComputeServerDigestt:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetAddAlternateComputerName@20' as NetAddAlternateComputerName:dword
    ;extrn '__imp__NetAddServiceAccount@16' as NetAddServiceAccount:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetAlertRaise@12' as NetAlertRaise:dword
    extrn '__imp__NetAlertRaiseEx@16' as NetAlertRaiseEx:dword
    extrn '__imp__NetApiBufferAllocate@8' as NetApiBufferAllocate:dword
    extrn '__imp__NetApiBufferFree@4' as NetApiBufferFree:dword
    extrn '__imp__NetApiBufferReallocate@12' as NetApiBufferReallocate:dword
    extrn '__imp__NetApiBufferSize@8' as NetApiBufferSize:dword
    extrn '__imp__NetAuditClear@12' as NetAuditClear:dword
    extrn '__imp__NetAuditRead@44' as NetAuditRead:dword
    extrn '__imp__NetAuditWrite@20' as NetAuditWrite:dword
    ;extrn '__imp__NetBrowserStatisticsGet@12' as NetBrowserStatisticsGet:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetConfigGet@16' as NetConfigGet:dword
    extrn '__imp__NetConfigGetAll@12' as NetConfigGetAll:dword
    extrn '__imp__NetConfigSet@28' as NetConfigSet:dword
    extrn '__imp__NetConnectionEnum@32' as NetConnectionEnum:dword
    extrn '__imp__NetDfsAdd@20' as NetDfsAdd:dword
    extrn '__imp__NetDfsAddFtRoot@20' as NetDfsAddFtRoot:dword
    ;extrn '__imp__NetDfsAddRootTarget@20' as NetDfsAddRootTarget:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetDfsAddStdRoot@16' as NetDfsAddStdRoot:dword
    extrn '__imp__NetDfsAddStdRootForced@16' as NetDfsAddStdRootForced:dword
    extrn '__imp__NetDfsEnum@24' as NetDfsEnum:dword
    extrn '__imp__NetDfsGetClientInfo@20' as NetDfsGetClientInfo:dword
    extrn '__imp__NetDfsGetDcAddress@16' as NetDfsGetDcAddress:dword
    ;extrn '__imp__NetDfsGetFtContainerSecurity@16' as NetDfsGetFtContainerSecurity:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetDfsGetInfo@20' as NetDfsGetInfo:dword
    ;extrn '__imp__NetDfsGetSecurity@16' as NetDfsGetSecurity:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetDfsGetStdContainerSecurity@16' as NetDfsGetStdContainerSecurity:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetDfsGetSupportedNamespaceVersion@12' as NetDfsGetSupportedNamespaceVersion:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetDfsManagerInitialize@8' as NetDfsManagerInitialize:dword
    extrn '__imp__NetDfsManagerSendSiteInfo@12' as NetDfsManagerSendSiteInfo:dword
    ;extrn '__imp__NetDfsMove@12' as NetDfsMove:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetDfsRemove@12' as NetDfsRemove:dword
    extrn '__imp__NetDfsRemoveFtRoot@16' as NetDfsRemoveFtRoot:dword
    extrn '__imp__NetDfsRemoveFtRootForced@20' as NetDfsRemoveFtRootForced:dword
    ;extrn '__imp__NetDfsRemoveRootTarget@12' as NetDfsRemoveRootTarget:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetDfsRemoveStdRoot@12' as NetDfsRemoveStdRoot:dword
    ;extrn '__imp__NetDfsRename@8' as NetDfsRename:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetDfsSetClientInfo@20' as NetDfsSetClientInfo:dword
    ;extrn '__imp__NetDfsSetFtContainerSecurity@12' as NetDfsSetFtContainerSecurity:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetDfsSetInfo@20' as NetDfsSetInfo:dword
    ;extrn '__imp__NetDfsSetSecurity@12' as NetDfsSetSecurity:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetDfsSetStdContainerSecurity@12' as NetDfsSetStdContainerSecurity:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetEnumerateComputerNames@20' as NetEnumerateComputerNames:dword
    ;extrn '__imp__NetEnumerateServiceAccounts@16' as NetEnumerateServiceAccounts:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetEnumerateTrustedDomains@8' as NetEnumerateTrustedDomains:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetErrorLogClear@12' as NetErrorLogClear:dword
    extrn '__imp__NetErrorLogRead@44' as NetErrorLogRead:dword
    extrn '__imp__NetErrorLogWrite@32' as NetErrorLogWrite:dword
    extrn '__imp__NetFileClose@8' as NetFileClose:dword
    extrn '__imp__NetFileEnum@36' as NetFileEnum:dword
    extrn '__imp__NetFileGetInfo@16' as NetFileGetInfo:dword
    extrn '__imp__NetGetAnyDCName@12' as NetGetAnyDCName:dword
    extrn '__imp__NetGetDCName@12' as NetGetDCName:dword
    extrn '__imp__NetGetDisplayInformationIndex@16' as NetGetDisplayInformationIndex:dword
    extrn '__imp__NetGetJoinInformation@12' as NetGetJoinInformation:dword
    extrn '__imp__NetGetJoinableOUs@24' as NetGetJoinableOUs:dword
    extrn '__imp__NetGroupAdd@16' as NetGroupAdd:dword
    extrn '__imp__NetGroupAddUser@12' as NetGroupAddUser:dword
    extrn '__imp__NetGroupDel@8' as NetGroupDel:dword
    extrn '__imp__NetGroupDelUser@12' as NetGroupDelUser:dword
    extrn '__imp__NetGroupEnum@28' as NetGroupEnum:dword
    extrn '__imp__NetGroupGetInfo@16' as NetGroupGetInfo:dword
    extrn '__imp__NetGroupGetUsers@32' as NetGroupGetUsers:dword
    extrn '__imp__NetGroupSetInfo@20' as NetGroupSetInfo:dword
    extrn '__imp__NetGroupSetUsers@20' as NetGroupSetUsers:dword
    ;extrn '__imp__NetIsServiceAccount@12' as NetIsServiceAccount:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetJoinDomain@24' as NetJoinDomain:dword
    extrn '__imp__NetLocalGroupAdd@16' as NetLocalGroupAdd:dword
    extrn '__imp__NetLocalGroupAddMember@12' as NetLocalGroupAddMember:dword
    extrn '__imp__NetLocalGroupAddMembers@20' as NetLocalGroupAddMembers:dword
    extrn '__imp__NetLocalGroupDel@8' as NetLocalGroupDel:dword
    extrn '__imp__NetLocalGroupDelMember@12' as NetLocalGroupDelMember:dword
    extrn '__imp__NetLocalGroupDelMembers@20' as NetLocalGroupDelMembers:dword
    extrn '__imp__NetLocalGroupEnum@28' as NetLocalGroupEnum:dword
    extrn '__imp__NetLocalGroupGetInfo@16' as NetLocalGroupGetInfo:dword
    extrn '__imp__NetLocalGroupGetMembers@32' as NetLocalGroupGetMembers:dword
    extrn '__imp__NetLocalGroupSetInfo@20' as NetLocalGroupSetInfo:dword
    extrn '__imp__NetLocalGroupSetMembers@20' as NetLocalGroupSetMembers:dword
    extrn '__imp__NetLogonGetTimeServiceParentDomain@12' as NetLogonGetTimeServiceParentDomain:dword
    ;extrn '__imp__NetLogonSetServiceBits@12' as NetLogonSetServiceBits:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetMessageBufferSend@20' as NetMessageBufferSend:dword
    extrn '__imp__NetMessageNameAdd@8' as NetMessageNameAdd:dword
    extrn '__imp__NetMessageNameDel@8' as NetMessageNameDel:dword
    extrn '__imp__NetMessageNameEnum@28' as NetMessageNameEnum:dword
    extrn '__imp__NetMessageNameGetInfo@16' as NetMessageNameGetInfo:dword
    ;extrn '__imp__NetProvisionComputerAccount@32' as NetProvisionComputerAccount:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetQueryDisplayInformation@28' as NetQueryDisplayInformation:dword
    ;extrn '__imp__NetQueryServiceAccount@16' as NetQueryServiceAccount:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetRegisterDomainNameChangeNotification@4' as NetRegisterDomainNameChangeNotification:dword
    extrn '__imp__NetRemoteComputerSupports@12' as NetRemoteComputerSupports:dword
    extrn '__imp__NetRemoteTOD@8' as NetRemoteTOD:dword
    extrn '__imp__NetRemoveAlternateComputerName@20' as NetRemoveAlternateComputerName:dword
    ;extrn '__imp__NetRemoveServiceAccount@12' as NetRemoveServiceAccount:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetRenameMachineInDomain@20' as NetRenameMachineInDomain:dword
    extrn '__imp__NetReplExportDirAdd@16' as NetReplExportDirAdd:dword
    extrn '__imp__NetReplExportDirDel@8' as NetReplExportDirDel:dword
    extrn '__imp__NetReplExportDirEnum@28' as NetReplExportDirEnum:dword
    extrn '__imp__NetReplExportDirGetInfo@16' as NetReplExportDirGetInfo:dword
    extrn '__imp__NetReplExportDirLock@8' as NetReplExportDirLock:dword
    extrn '__imp__NetReplExportDirSetInfo@20' as NetReplExportDirSetInfo:dword
    extrn '__imp__NetReplExportDirUnlock@12' as NetReplExportDirUnlock:dword
    extrn '__imp__NetReplGetInfo@12' as NetReplGetInfo:dword
    extrn '__imp__NetReplImportDirAdd@16' as NetReplImportDirAdd:dword
    extrn '__imp__NetReplImportDirDel@8' as NetReplImportDirDel:dword
    extrn '__imp__NetReplImportDirEnum@28' as NetReplImportDirEnum:dword
    extrn '__imp__NetReplImportDirGetInfo@16' as NetReplImportDirGetInfo:dword
    extrn '__imp__NetReplImportDirLock@8' as NetReplImportDirLock:dword
    extrn '__imp__NetReplImportDirUnlock@12' as NetReplImportDirUnlock:dword
    extrn '__imp__NetReplSetInfo@16' as NetReplSetInfo:dword
    ;extrn '__imp__NetRequestOfflineDomainJoin@16' as NetRequestOfflineDomainJoin:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetScheduleJobAdd@12' as NetScheduleJobAdd:dword
    extrn '__imp__NetScheduleJobDel@12' as NetScheduleJobDel:dword
    extrn '__imp__NetScheduleJobEnum@24' as NetScheduleJobEnum:dword
    extrn '__imp__NetScheduleJobGetInfo@12' as NetScheduleJobGetInfo:dword
    ;extrn '__imp__NetServerAliasAdd@12' as NetServerAliasAdd:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetServerAliasDel@12' as NetServerAliasDel:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetServerAliasEnum@28' as NetServerAliasEnum:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetServerComputerNameAdd@12' as NetServerComputerNameAdd:dword
    extrn '__imp__NetServerComputerNameDel@8' as NetServerComputerNameDel:dword
    extrn '__imp__NetServerDiskEnum@28' as NetServerDiskEnum:dword
    extrn '__imp__NetServerEnum@36' as NetServerEnum:dword
    ;extrn '__imp__NetServerEnumEx@36' as NetServerEnumEx:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetServerGetInfo@12' as NetServerGetInfo:dword
    extrn '__imp__NetServerSetInfo@16' as NetServerSetInfo:dword
    extrn '__imp__NetServerTransportAdd@12' as NetServerTransportAdd:dword
    extrn '__imp__NetServerTransportAddEx@12' as NetServerTransportAddEx:dword
    extrn '__imp__NetServerTransportDel@12' as NetServerTransportDel:dword
    extrn '__imp__NetServerTransportEnum@28' as NetServerTransportEnum:dword
    extrn '__imp__NetServiceControl@20' as NetServiceControl:dword
    extrn '__imp__NetServiceEnum@28' as NetServiceEnum:dword
    extrn '__imp__NetServiceGetInfo@16' as NetServiceGetInfo:dword
    extrn '__imp__NetServiceInstall@20' as NetServiceInstall:dword
    extrn '__imp__NetSessionDel@12' as NetSessionDel:dword
    extrn '__imp__NetSessionEnum@36' as NetSessionEnum:dword
    extrn '__imp__NetSessionGetInfo@20' as NetSessionGetInfo:dword
    extrn '__imp__NetSetPrimaryComputerName@20' as NetSetPrimaryComputerName:dword
    extrn '__imp__NetShareAdd@16' as NetShareAdd:dword
    extrn '__imp__NetShareCheck@12' as NetShareCheck:dword
    extrn '__imp__NetShareDel@12' as NetShareDel:dword
    ;extrn '__imp__NetShareDelEx@12' as NetShareDelEx:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetShareDelSticky@12' as NetShareDelSticky:dword
    extrn '__imp__NetShareEnum@28' as NetShareEnum:dword
    extrn '__imp__NetShareEnumSticky@28' as NetShareEnumSticky:dword
    extrn '__imp__NetShareGetInfo@16' as NetShareGetInfo:dword
    extrn '__imp__NetShareSetInfo@20' as NetShareSetInfo:dword
    extrn '__imp__NetStatisticsGet@20' as NetStatisticsGet:dword
    extrn '__imp__NetUnjoinDomain@16' as NetUnjoinDomain:dword
    extrn '__imp__NetUnregisterDomainNameChangeNotification@4' as NetUnregisterDomainNameChangeNotification:dword
    extrn '__imp__NetUseAdd@16' as NetUseAdd:dword
    extrn '__imp__NetUseDel@12' as NetUseDel:dword
    extrn '__imp__NetUseEnum@28' as NetUseEnum:dword
    extrn '__imp__NetUseGetInfo@16' as NetUseGetInfo:dword
    extrn '__imp__NetUserAdd@16' as NetUserAdd:dword
    extrn '__imp__NetUserChangePassword@16' as NetUserChangePassword:dword
    extrn '__imp__NetUserDel@8' as NetUserDel:dword
    extrn '__imp__NetUserEnum@32' as NetUserEnum:dword
    extrn '__imp__NetUserGetGroups@28' as NetUserGetGroups:dword
    extrn '__imp__NetUserGetInfo@16' as NetUserGetInfo:dword
    extrn '__imp__NetUserGetLocalGroups@32' as NetUserGetLocalGroups:dword
    extrn '__imp__NetUserModalsGet@12' as NetUserModalsGet:dword
    extrn '__imp__NetUserModalsSet@16' as NetUserModalsSet:dword
    extrn '__imp__NetUserSetGroups@20' as NetUserSetGroups:dword
    extrn '__imp__NetUserSetInfo@20' as NetUserSetInfo:dword
    extrn '__imp__NetValidateName@20' as NetValidateName:dword
    ;extrn '__imp__NetValidatePasswordPolicy@20' as NetValidatePasswordPolicy:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetValidatePasswordPolicyFree@4' as NetValidatePasswordPolicyFree:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NetWkstaGetInfo@12' as NetWkstaGetInfo:dword
    extrn '__imp__NetWkstaSetInfo@16' as NetWkstaSetInfo:dword
    extrn '__imp__NetWkstaTransportAdd@16' as NetWkstaTransportAdd:dword
    extrn '__imp__NetWkstaTransportDel@12' as NetWkstaTransportDel:dword
    extrn '__imp__NetWkstaTransportEnum@28' as NetWkstaTransportEnum:dword
    extrn '__imp__NetWkstaUserEnum@28' as NetWkstaUserEnum:dword
    extrn '__imp__NetWkstaUserGetInfo@12' as NetWkstaUserGetInfo:dword
    extrn '__imp__NetWkstaUserSetInfo@16' as NetWkstaUserSetInfo:dword
    ;extrn '__imp__NetapipBufferAllocate@8' as NetapipBufferAllocate:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__Netbios@4' as Netbios:dword
    ;extrn '__imp__NetpAssertFailed@16' as NetpAssertFailed:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpCloseConfigData@4' as NetpCloseConfigData:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpDbgPrint@4' as NetpDbgPrint:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpGetConfigBool@16' as NetpGetConfigBool:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpGetConfigDword@16' as NetpGetConfigDword:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpGetConfigTStrArray@12' as NetpGetConfigTStrArray:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpGetConfigValue@12' as NetpGetConfigValue:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpGetFileSecurity@16' as NetpGetFileSecurity:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpHexDump@8' as NetpHexDump:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpInitFtinfoContext@4' as NetpInitFtinfoContext:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpIsRemote@16' as NetpIsRemote:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpIsUncComputerNameValid@4' as NetpIsUncComputerNameValid:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpMergeFtinfo@16' as NetpMergeFtinfo:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpNetBiosReset@4' as NetpNetBiosReset:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpNetBiosStatusToApiStatus@4' as NetpNetBiosStatusToApiStatus:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpOpenConfigData@16' as NetpOpenConfigData:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpSetFileSecurity@12' as NetpSetFileSecurity:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpwNameCanonicalize@16' as NetpwNameCanonicalize:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpwNameCompare@16' as NetpwNameCompare:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpwNameValidate@12' as NetpwNameValidate:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpwPathCanonicalize@24' as NetpwPathCanonicalize:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpwPathCompare@16' as NetpwPathCompare:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NetpwPathType@12' as NetpwPathType:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NlBindingAddServerToCache@8' as NlBindingAddServerToCache:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__NlBindingRemoveServerFromCache@8' as NlBindingRemoveServerFromCache:dword ;Not present in MASM32 netapi32.lib
    extrn '__imp__NlBindingSetAuthInfo@20' as NlBindingSetAuthInfo:dword
    extrn '__imp__RxNetAccessAdd@16' as RxNetAccessAdd:dword
    extrn '__imp__RxNetAccessDel@8' as RxNetAccessDel:dword
    extrn '__imp__RxNetAccessEnum@36' as RxNetAccessEnum:dword
    extrn '__imp__RxNetAccessGetInfo@16' as RxNetAccessGetInfo:dword
    extrn '__imp__RxNetAccessGetUserPerms@16' as RxNetAccessGetUserPerms:dword
    extrn '__imp__RxNetAccessSetInfo@20' as RxNetAccessSetInfo:dword
    ;extrn '__imp__RxNetServerEnum@40' as RxNetServerEnum:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__RxNetUserPasswordSet@16' as RxNetUserPasswordSet:dword ;Not present in MASM32 netapi32.lib
    ;extrn '__imp__RxRemoteApi@44' as RxRemoteApi:dword ;Not present in MASM32 netapi32.lib
end if

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
