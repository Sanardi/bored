; ======================================================;
;                                                       ;
;  netapi32.inc for Easy Code 2.0 64-bit Masm projects  ;
;                  (version 1.0.1)                      ;
;                                                       ;
;             Copyright © Ramon Sala - 2018             ;
;                                                       ;
; ======================================================;

IFNDEF NETAPI32_INC
NETAPI32_INC    EQU     1

USE_LOCAL_PARMNUM                               EQU     1
USE_REMOTE_PARMNUM                              EQU     2
USE_PASSWORD_PARMNUM                            EQU     3
USE_ASGTYPE_PARMNUM                             EQU     4
USE_USERNAME_PARMNUM                            EQU     5
USE_DOMAINNAME_PARMNUM                          EQU     6

USE_OK                                          EQU     0
USE_PAUSED                                      EQU     1
USE_SESSLOST                                    EQU     2
USE_DISCONN                                     EQU     2
USE_NETERR                                      EQU     3
USE_CONN                                        EQU     4
USE_RECONN                                      EQU     5

USE_WILDCARD                                    EQU     (-1)
USE_DISKDEV                                     EQU     0
USE_SPOOLDEV                                    EQU     1
USE_CHARDEV                                     EQU     2
USE_IPC                                         EQU     3

CREATE_NO_CONNECT                               EQU     1
CREATE_BYPASS_CSC                               EQU     2

USE_NOFORCE                                     EQU     0
USE_FORCE                                       EQU     1
USE_LOTS_OF_FORCE                               EQU     2

;=============================== lmcons constants ===============================
IFNDEF CNLEN
    CNLEN                                       EQU     15
    LM20_CNLEN                                  EQU     15
    DNLEN                                       EQU     CNLEN
    LM20_DNLEN                                  EQU     LM20_CNLEN
    UNCLEN                                      EQU     CNLEN + 2
    LM20_UNCLEN                                 EQU     LM20_CNLEN + 2
    NNLEN                                       EQU     80
    LM20_NNLEN                                  EQU     12
    RMLEN                                       EQU     UNCLEN + 1 + NNLEN
    LM20_RMLEN                                  EQU     LM20_UNCLEN + 1 + LM20_NNLEN
    SNLEN                                       EQU     80
    LM20_SNLEN                                  EQU     15
    STXTLEN                                     EQU     256
    LM20_STXTLEN                                EQU     63
    PATHLEN                                     EQU     256
    LM20_PATHLEN                                EQU     256
    DEVLEN                                      EQU     80
    LM20_DEVLEN                                 EQU     8
    EVLEN                                       EQU     16
    UNLEN                                       EQU     256
    LM20_UNLEN                                  EQU     20
    GNLEN                                       EQU     UNLEN
    LM20_GNLEN                                  EQU     LM20_UNLEN
    PWLEN                                       EQU     256
    LM20_PWLEN                                  EQU     14
    SHPWLEN                                     EQU     8
    CLTYPE_LEN                                  EQU     12
    MAXCOMMENTSZ                                EQU     256
    LM20_MAXCOMMENTSZ                           EQU     48
    QNLEN                                       EQU     NNLEN
    LM20_QNLEN                                  EQU     LM20_NNLEN
    ALERTSZ                                     EQU     128
    MAXDEVENTRIES                               EQU     32
    NETBIOS_NAME_LEN                            EQU     16
    MAX_PREFERRED_LENGTH                        EQU     (-1)
    CRYPT_KEY_LEN                               EQU     7
    CRYPT_TXT_LEN                               EQU     8
    ENCRYPTED_PWLEN                             EQU     16
    SESSION_PWLEN                               EQU     24
    SESSION_CRYPT_KLEN                          EQU     21
    IFNDEF PARMNUM_ALL
        PARMNUM_ALL                             EQU     0
    ENDIF
    PARM_ERROR_UNKNOWN                          EQU     (-1)
    PARM_ERROR_NONE                             EQU     0
    PARMNUM_BASE_INFOLEVEL                      EQU     1000
    MESSAGE_FILENAME                            TEXTEQU <NETMSG>
    OS2MSG_FILENAME                             TEXTEQU <BASE>
    HELP_MSG_FILENAME                           TEXTEQU <NETH>
    BACKUP_MSG_FILENAME                         TEXTEQU <BAK.MSG>
    PLATFORM_ID_DOS                             EQU     300
    PLATFORM_ID_OS2                             EQU     400
    PLATFORM_ID_NT                              EQU     500
    PLATFORM_ID_OSF                             EQU     600
    PLATFORM_ID_VMS                             EQU     700
    MIN_LANMAN_MESSAGE_ID                       EQU     NERR_BASE
    MAX_LANMAN_MESSAGE_ID                       EQU     5799
ENDIF


;======================================== Structures ======================================;
USE_INFO_0 STRUCT ALIGNMODE
    ui0_local  XPTR ?
    ui0_remote XPTR ?
USE_INFO_0 ENDS

USE_INFO_1 STRUCT ALIGNMODE
    ui1_local    XPTR ?
    ui1_remote   XPTR ?
    ui1_password XPTR ?
    ui1_status   DD   ?
    ui1_asg_type DD   ?
    ui1_refcount DD   ?
    ui1_usecount DD   ?
USE_INFO_1 ENDS

USE_INFO_2 STRUCT ALIGNMODE
    ui2_local      XPTR ?
    ui2_remote     XPTR ?
    ui2_password   XPTR ?
    ui2_status     DD   ?
    ui2_asg_type   DD   ?
    ui2_refcount   DD   ?
    ui2_usecount   DD   ?
    ui2_username   XPTR ?
    ui2_domainname XPTR ?
USE_INFO_2 ENDS

USE_INFO_3 STRUCT ALIGNMODE
    ui3_ui2   USE_INFO_2 <>
    ui3_flags DD ?
USE_INFO_3 ENDS


;======================================== Functions =======================================;
DsAddressToSiteNamesA PROTO :XWORD, :XWORD, :XWORD, :XWORD
DsAddressToSiteNamesExA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DsAddressToSiteNamesExW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DsAddressToSiteNamesW PROTO :XWORD, :XWORD, :XWORD, :XWORD
DsDeregisterDnsHostRecordsA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DsDeregisterDnsHostRecordsW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DsEnumerateDomainTrustsA PROTO :XWORD, :XWORD, :XWORD, :XWORD
DsEnumerateDomainTrustsW PROTO :XWORD, :XWORD, :XWORD, :XWORD
DsGetDcCloseW PROTO :XWORD
DsGetDcNameA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DsGetDcNameW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DsGetDcNameWithAccountA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DsGetDcNameWithAccountW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DsGetDcNextA PROTO :XWORD, :XWORD, :XWORD, :XWORD
DsGetDcNextW PROTO :XWORD, :XWORD, :XWORD, :XWORD
DsGetDcOpenA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DsGetDcOpenW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DsGetDcSiteCoverageA PROTO :XWORD, :XWORD, :XWORD
DsGetDcSiteCoverageW PROTO :XWORD, :XWORD, :XWORD
DsGetForestTrustInformationW PROTO :XWORD, :XWORD, :XWORD, :XWORD
DsGetSiteNameA PROTO :XWORD, :XWORD
DsGetSiteNameW PROTO :XWORD, :XWORD
DsMergeForestTrustInformationW PROTO :XWORD, :XWORD, :XWORD, :XWORD
DsRoleAbortDownlevelServerUpgrade PROTO :XWORD, :XWORD, :XWORD, :XWORD
DsRoleCancel PROTO :XWORD, :XWORD
DsRoleDcAsDc PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DsRoleDcAsReplica PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DsRoleDemoteDc PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DsRoleDnsNameToFlatName PROTO :XWORD, :XWORD, :XWORD, :XWORD
DsRoleFreeMemory PROTO :XWORD
DsRoleGetDatabaseFacts PROTO :XWORD, :XWORD, :XWORD, :XWORD
DsRoleGetDcOperationProgress PROTO :XWORD, :XWORD, :XWORD
DsRoleGetDcOperationResults PROTO :XWORD, :XWORD, :XWORD
DsRoleGetPrimaryDomainInformation PROTO :XWORD, :XWORD, :XWORD
DsRoleIfmHandleFree PROTO :XWORD, :XWORD
DsRoleServerSaveStateForUpgrade PROTO :XWORD
DsRoleUpgradeDownlevelServer PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DsValidateSubnetNameA PROTO :XWORD
DsValidateSubnetNameW PROTO :XWORD
I_BrowserDebugCall PROTO :XWORD, :XWORD, :XWORD
I_BrowserDebugTrace PROTO :XWORD, :XWORD
I_BrowserQueryEmulatedDomains PROTO :XWORD, :XWORD, :XWORD
I_BrowserQueryOtherDomains PROTO :XWORD, :XWORD, :XWORD, :XWORD
I_BrowserQueryStatistics PROTO :XWORD, :XWORD
I_BrowserResetNetlogonState PROTO :XWORD
I_BrowserResetStatistics PROTO :XWORD
I_BrowserServerEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_BrowserSetNetlogonState PROTO :XWORD, :XWORD, :XWORD, :XWORD
I_DsUpdateReadOnlyServerDnsRecords PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetAccountDeltas PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetAccountSync PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetChainSetClientAttributes PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetChainSetClientAttributes2 PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetDatabaseDeltas PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetDatabaseRedo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetDatabaseSync PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetDatabaseSync2 PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetDfsGetVersion PROTO :XWORD, :XWORD
I_NetDfsIsThisADomainName PROTO :XWORD
I_NetGetDCList PROTO :XWORD, :XWORD, :XWORD, :XWORD
I_NetGetForestTrustInformation PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetLogonControl PROTO :XWORD, :XWORD, :XWORD, :XWORD
I_NetLogonControl2 PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetLogonGetDomainInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetLogonSamLogoff PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetLogonSamLogon PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetLogonSamLogonEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetLogonSamLogonWithFlags PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetLogonSendToSam PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetLogonUasLogoff PROTO :XWORD, :XWORD, :XWORD
I_NetLogonUasLogon PROTO :XWORD, :XWORD, :XWORD
I_NetServerAuthenticate PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetServerAuthenticate2 PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetServerAuthenticate3 PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetServerGetTrustInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetServerPasswordGet PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetServerPasswordSet PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetServerPasswordSet2 PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetServerReqChallenge PROTO :XWORD, :XWORD, :XWORD, :XWORD
I_NetServerSetServiceBits PROTO :XWORD, :XWORD, :XWORD, :XWORD
I_NetServerSetServiceBitsEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetServerTrustPasswordsGet PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetlogonComputeClientDigest PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
I_NetlogonComputeServerDigestt PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetAddAlternateComputerName PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetAddServiceAccount PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetAlertRaise PROTO :XWORD, :XWORD, :XWORD
NetAlertRaiseEx PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetApiBufferAllocate PROTO :XWORD, :XWORD
NetApiBufferFree PROTO :XWORD
NetApiBufferReallocate PROTO :XWORD, :XWORD, :XWORD
NetApiBufferSize PROTO :XWORD, :XWORD
NetAuditClear PROTO :XWORD, :XWORD, :XWORD
NetAuditRead PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetAuditWrite PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetBrowserStatisticsGet PROTO :XWORD, :XWORD, :XWORD
NetConfigGet PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetConfigGetAll PROTO :XWORD, :XWORD, :XWORD
NetConfigSet PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetConnectionEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetDfsAdd PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetDfsAddFtRoot PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetDfsAddRootTarget PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetDfsAddStdRoot PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetDfsAddStdRootForced PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetDfsEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetDfsGetClientInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetDfsGetDcAddress PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetDfsGetFtContainerSecurity PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetDfsGetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetDfsGetSecurity PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetDfsGetStdContainerSecurity PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetDfsGetSupportedNamespaceVersion PROTO :XWORD, :XWORD, :XWORD
NetDfsManagerInitialize PROTO :XWORD, :XWORD
NetDfsManagerSendSiteInfo PROTO :XWORD, :XWORD, :XWORD
NetDfsMove PROTO :XWORD, :XWORD, :XWORD
NetDfsRemove PROTO :XWORD, :XWORD, :XWORD
NetDfsRemoveFtRoot PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetDfsRemoveFtRootForced PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetDfsRemoveRootTarget PROTO :XWORD, :XWORD, :XWORD
NetDfsRemoveStdRoot PROTO :XWORD, :XWORD, :XWORD
NetDfsRename PROTO :XWORD, :XWORD
NetDfsSetClientInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetDfsSetFtContainerSecurity PROTO :XWORD, :XWORD, :XWORD
NetDfsSetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetDfsSetSecurity PROTO :XWORD, :XWORD, :XWORD
NetDfsSetStdContainerSecurity PROTO :XWORD, :XWORD, :XWORD
NetEnumerateComputerNames PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetEnumerateServiceAccounts PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetEnumerateTrustedDomains PROTO :XWORD, :XWORD
NetErrorLogClear PROTO :XWORD, :XWORD, :XWORD
NetErrorLogRead PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetErrorLogWrite PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetFileClose PROTO :XWORD, :XWORD
NetFileEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetFileGetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetGetAnyDCName PROTO :XWORD, :XWORD, :XWORD
NetGetDCName PROTO :XWORD, :XWORD, :XWORD
NetGetDisplayInformationIndex PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetGetJoinInformation PROTO :XWORD, :XWORD, :XWORD
NetGetJoinableOUs PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetGroupAdd PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetGroupAddUser PROTO :XWORD, :XWORD, :XWORD
NetGroupDel PROTO :XWORD, :XWORD
NetGroupDelUser PROTO :XWORD, :XWORD, :XWORD
NetGroupEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetGroupGetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetGroupGetUsers PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetGroupSetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetGroupSetUsers PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetIsServiceAccount PROTO :XWORD, :XWORD, :XWORD
NetJoinDomain PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetLocalGroupAdd PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetLocalGroupAddMember PROTO :XWORD, :XWORD, :XWORD
NetLocalGroupAddMembers PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetLocalGroupDel PROTO :XWORD, :XWORD
NetLocalGroupDelMember PROTO :XWORD, :XWORD, :XWORD
NetLocalGroupDelMembers PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetLocalGroupEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetLocalGroupGetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetLocalGroupGetMembers PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetLocalGroupSetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetLocalGroupSetMembers PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetLogonGetTimeServiceParentDomain PROTO :XWORD, :XWORD, :XWORD
NetLogonSetServiceBits PROTO :XWORD, :XWORD, :XWORD
NetMessageBufferSend PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetMessageNameAdd PROTO :XWORD, :XWORD
NetMessageNameDel PROTO :XWORD, :XWORD
NetMessageNameEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetMessageNameGetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetProvisionComputerAccount PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetQueryDisplayInformation PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetQueryServiceAccount PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetRegisterDomainNameChangeNotification PROTO :XWORD
NetRemoteComputerSupports PROTO :XWORD, :XWORD, :XWORD
NetRemoteTOD PROTO :XWORD, :XWORD
NetRemoveAlternateComputerName PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetRemoveServiceAccount PROTO :XWORD, :XWORD, :XWORD
NetRenameMachineInDomain PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetReplExportDirAdd PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetReplExportDirDel PROTO :XWORD, :XWORD
NetReplExportDirEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetReplExportDirGetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetReplExportDirLock PROTO :XWORD, :XWORD
NetReplExportDirSetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetReplExportDirUnlock PROTO :XWORD, :XWORD, :XWORD
NetReplGetInfo PROTO :XWORD, :XWORD, :XWORD
NetReplImportDirAdd PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetReplImportDirDel PROTO :XWORD, :XWORD
NetReplImportDirEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetReplImportDirGetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetReplImportDirLock PROTO :XWORD, :XWORD
NetReplImportDirUnlock PROTO :XWORD, :XWORD, :XWORD
NetReplSetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetRequestOfflineDomainJoin PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetScheduleJobAdd PROTO :XWORD, :XWORD, :XWORD
NetScheduleJobDel PROTO :XWORD, :XWORD, :XWORD
NetScheduleJobEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetScheduleJobGetInfo PROTO :XWORD, :XWORD, :XWORD
NetServerAliasAdd PROTO :XWORD, :XWORD, :XWORD
NetServerAliasDel PROTO :XWORD, :XWORD, :XWORD
NetServerAliasEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetServerComputerNameAdd PROTO :XWORD, :XWORD, :XWORD
NetServerComputerNameDel PROTO :XWORD, :XWORD
NetServerDiskEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetServerEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetServerEnumEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetServerGetInfo PROTO :XWORD, :XWORD, :XWORD
NetServerSetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetServerTransportAdd PROTO :XWORD, :XWORD, :XWORD
NetServerTransportAddEx PROTO :XWORD, :XWORD, :XWORD
NetServerTransportDel PROTO :XWORD, :XWORD, :XWORD
NetServerTransportEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetServiceControl PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetServiceEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetServiceGetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetServiceInstall PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetSessionDel PROTO :XWORD, :XWORD, :XWORD
NetSessionEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetSessionGetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetSetPrimaryComputerName PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetShareAdd PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetShareCheck PROTO :XWORD, :XWORD, :XWORD
NetShareDel PROTO :XWORD, :XWORD, :XWORD
NetShareDelEx PROTO :XWORD, :XWORD, :XWORD
NetShareDelSticky PROTO :XWORD, :XWORD, :XWORD
NetShareEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetShareEnumSticky PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetShareGetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetShareSetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetStatisticsGet PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetUnjoinDomain PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetUnregisterDomainNameChangeNotification PROTO :XWORD
NetUseAdd PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetUseDel PROTO :XWORD, :XWORD, :XWORD
NetUseEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetUseGetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetUserAdd PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetUserChangePassword PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetUserDel PROTO :XWORD, :XWORD
NetUserEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetUserGetGroups PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetUserGetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetUserGetLocalGroups PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetUserModalsGet PROTO :XWORD, :XWORD, :XWORD
NetUserModalsSet PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetUserSetGroups PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetUserSetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetValidateName PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetValidatePasswordPolicy PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetValidatePasswordPolicyFree PROTO :XWORD
NetWkstaGetInfo PROTO :XWORD, :XWORD, :XWORD
NetWkstaSetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetWkstaTransportAdd PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetWkstaTransportDel PROTO :XWORD, :XWORD, :XWORD
NetWkstaTransportEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetWkstaUserEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetWkstaUserGetInfo PROTO :XWORD, :XWORD, :XWORD
NetWkstaUserSetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetapipBufferAllocate PROTO :XWORD, :XWORD
Netbios PROTO :XWORD
NetpAssertFailed PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetpCloseConfigData PROTO :XWORD
NetpDbgPrint PROTO :VARARG
NetpGetConfigBool PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetpGetConfigDword PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetpGetConfigTStrArray PROTO :XWORD, :XWORD, :XWORD
NetpGetConfigValue PROTO :XWORD, :XWORD, :XWORD
NetpGetFileSecurity PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetpHexDump PROTO :XWORD, :XWORD
NetpInitFtinfoContext PROTO :XWORD
NetpIsRemote PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetpIsUncComputerNameValid PROTO :XWORD
NetpMergeFtinfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetpNetBiosReset PROTO :XWORD
NetpNetBiosStatusToApiStatus PROTO :XWORD
NetpOpenConfigData PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetpSetFileSecurity PROTO :XWORD, :XWORD, :XWORD
NetpwNameCanonicalize PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetpwNameCompare PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetpwNameValidate PROTO :XWORD, :XWORD, :XWORD
NetpwPathCanonicalize PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NetpwPathCompare PROTO :XWORD, :XWORD, :XWORD, :XWORD
NetpwPathType PROTO :XWORD, :XWORD, :XWORD
NlBindingAddServerToCache PROTO :XWORD, :XWORD
NlBindingRemoveServerFromCache PROTO :XWORD, :XWORD
NlBindingSetAuthInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
RxNetAccessAdd PROTO :XWORD, :XWORD, :XWORD, :XWORD
RxNetAccessDel PROTO :XWORD, :XWORD
RxNetAccessEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
RxNetAccessGetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
RxNetAccessGetUserPerms PROTO :XWORD, :XWORD, :XWORD, :XWORD
RxNetAccessSetInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
RxNetServerEnum PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
RxNetUserPasswordSet PROTO :XWORD, :XWORD, :XWORD, :XWORD
RxRemoteApi PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD

DsGetDcClose EQU <DsGetDcCloseW>
DsGetForestTrustInformation EQU <DsGetForestTrustInformationW>
DsMergeForestTrustInformation EQU <DsMergeForestTrustInformationW>
IFDEF APP_UNICODE
    DsAddressToSiteNames EQU <DsAddressToSiteNamesW>
    DsAddressToSiteNamesEx EQU <DsAddressToSiteNamesExW>
    DsDeregisterDnsHostRecords EQU <DsDeregisterDnsHostRecordsW>
    DsEnumerateDomainTrusts EQU <DsEnumerateDomainTrustsW>
    DsGetDcName EQU <DsGetDcNameW>
    DsGetDcNameWithAccount EQU <DsGetDcNameWithAccountW>
    DsGetDcNext EQU <DsGetDcNextW>
    DsGetDcOpen EQU <DsGetDcOpenW>
    DsGetDcSiteCoverage EQU <DsGetDcSiteCoverageW>
    DsGetSiteName EQU <DsGetSiteNameW>
    DsValidateSubnetName EQU <DsValidateSubnetNameW>
ELSE
    DsAddressToSiteNames EQU <DsAddressToSiteNamesA>
    DsAddressToSiteNamesEx EQU <DsAddressToSiteNamesExA>
    DsDeregisterDnsHostRecords EQU <DsDeregisterDnsHostRecordsA>
    DsEnumerateDomainTrusts EQU <DsEnumerateDomainTrustsA>
    DsGetDcName EQU <DsGetDcNameA>
    DsGetDcNameWithAccount EQU <DsGetDcNameWithAccountA>
    DsGetDcNext EQU <DsGetDcNextA>
    DsGetDcOpen EQU <DsGetDcOpenA>
    DsGetDcSiteCoverage EQU <DsGetDcSiteCoverageA>
    DsGetSiteName EQU <DsGetSiteNameA>
    DsValidateSubnetName EQU <DsValidateSubnetNameA>
ENDIF

;======================= Undocumented functions (unknown arguments) =======================;
;NetDfsManagerGetConfigInfo PROTO
;NetpAddTlnFtinfoEntry PROTO
;NetpAllocFtinfoEntry PROTO
;NetpCleanFtinfoContext PROTO
;NetpCopyFtinfoContext PROTO


ENDIF ;NETAPI32_INC
