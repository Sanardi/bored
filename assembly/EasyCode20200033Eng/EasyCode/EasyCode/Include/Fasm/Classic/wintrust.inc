; ====================================================;
;                                                     ;
;    wintrust.inc for EC v2 Fasm classic projects     ;
;                   (version 1.0.0)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2020            ;
;                                                     ;
; ====================================================;

if ~defined WINTRUST_INC
define WINTRUST_INC 1

import wintrust,\
AddPersonalTrustDBPages,'AddPersonalTrustDBPages',\
CatalogCompactHashDatabase,'CatalogCompactHashDatabase',\
CryptCATAdminAcquireContext,'CryptCATAdminAcquireContext',\
CryptCATAdminAcquireContext2,'CryptCATAdminAcquireContext2',\
CryptCATAdminAddCatalog,'CryptCATAdminAddCatalog',\
CryptCATAdminCalcHashFromFileHandle,'CryptCATAdminCalcHashFromFileHandle',\
CryptCATAdminCalcHashFromFileHandle2,'CryptCATAdminCalcHashFromFileHandle2',\
CryptCATAdminEnumCatalogFromHash,'CryptCATAdminEnumCatalogFromHash',\
CryptCATAdminPauseServiceForBackup,'CryptCATAdminPauseServiceForBackup',\
CryptCATAdminReleaseCatalogContext,'CryptCATAdminReleaseCatalogContext',\
CryptCATAdminReleaseContext,'CryptCATAdminReleaseContext',\
CryptCATAdminRemoveCatalog,'CryptCATAdminRemoveCatalog',\
CryptCATAdminResolveCatalogPath,'CryptCATAdminResolveCatalogPath',\
CryptCATAllocSortedMemberInfo,'CryptCATAllocSortedMemberInfo',\
CryptCATCDFClose,'CryptCATCDFClose',\
CryptCATCDFEnumAttributes,'CryptCATCDFEnumAttributes',\
CryptCATCDFEnumAttributesWithCDFTag,'CryptCATCDFEnumAttributesWithCDFTag',\
CryptCATCDFEnumCatAttributes,'CryptCATCDFEnumCatAttributes',\
CryptCATCDFEnumMembers,'CryptCATCDFEnumMembers',\
CryptCATCDFEnumMembersByCDFTag,'CryptCATCDFEnumMembersByCDFTag',\
CryptCATCDFEnumMembersByCDFTagEx,'CryptCATCDFEnumMembersByCDFTagEx',\
CryptCATCDFOpen,'CryptCATCDFOpen',\
CryptCATCatalogInfoFromContext,'CryptCATCatalogInfoFromContext',\
CryptCATClose,'CryptCATClose',\
CryptCATEnumerateAttr,'CryptCATEnumerateAttr',\
CryptCATEnumerateCatAttr,'CryptCATEnumerateCatAttr',\
CryptCATEnumerateMember,'CryptCATEnumerateMember',\
CryptCATFreeSortedMemberInfo,'CryptCATFreeSortedMemberInfo',\
CryptCATGetAttrInfo,'CryptCATGetAttrInfo',\
CryptCATGetCatAttrInfo,'CryptCATGetCatAttrInfo',\
CryptCATGetMemberInfo,'CryptCATGetMemberInfo',\
CryptCATHandleFromStore,'CryptCATHandleFromStore',\
CryptCATOpen,'CryptCATOpen',\
CryptCATPersistStore,'CryptCATPersistStore',\
CryptCATPutAttrInfo,'CryptCATPutAttrInfo',\
CryptCATPutCatAttrInfo,'CryptCATPutCatAttrInfo',\
CryptCATPutMemberInfo,'CryptCATPutMemberInfo',\
CryptCATStoreFromHandle,'CryptCATStoreFromHandle',\
CryptSIPCreateIndirectData,'CryptSIPCreateIndirectData',\
CryptSIPGetCaps,'CryptSIPGetCaps',\
CryptSIPGetSignedDataMsg,'CryptSIPGetSignedDataMsg',\
CryptSIPPutSignedDataMsg,'CryptSIPPutSignedDataMsg',\
CryptSIPRemoveSignedDataMsg,'CryptSIPRemoveSignedDataMsg',\
CryptSIPVerifyIndirectData,'CryptSIPVerifyIndirectData',\
DriverCleanupPolicy,'DriverCleanupPolicy',\
DriverFinalPolicy,'DriverFinalPolicy',\
DriverInitializePolicy,'DriverInitializePolicy',\
FindCertsByIssuer,'FindCertsByIssuer',\
GenericChainCertificateTrust,'GenericChainCertificateTrust',\
GenericChainFinalProv,'GenericChainFinalProv',\
HTTPSCertificateTrust,'HTTPSCertificateTrust',\
HTTPSFinalProv,'HTTPSFinalProv',\
IsCatalogFile,'IsCatalogFile',\
MsCatConstructHashTag,'MsCatConstructHashTag',\
MsCatFreeHashTag,'MsCatFreeHashTag',\
OfficeCleanupPolicy,'OfficeCleanupPolicy',\
OfficeInitializePolicy,'OfficeInitializePolicy',\
OpenPersonalTrustDBDialog,'OpenPersonalTrustDBDialog',\
OpenPersonalTrustDBDialogEx,'OpenPersonalTrustDBDialogEx',\
SoftpubAuthenticode,'SoftpubAuthenticode',\
SoftpubCheckCert,'SoftpubCheckCert',\
SoftpubCleanup,'SoftpubCleanup',\
SoftpubDefCertInit,'SoftpubDefCertInit',\
SoftpubDllRegisterServer,'SoftpubDllRegisterServer',\
SoftpubDllUnregisterServer,'SoftpubDllUnregisterServer',\
SoftpubDumpStructure,'SoftpubDumpStructure',\
SoftpubFreeDefUsageCallData,'SoftpubFreeDefUsageCallData',\
SoftpubInitialize,'SoftpubInitialize',\
SoftpubLoadDefUsageCallData,'SoftpubLoadDefUsageCallData',\
SoftpubLoadMessage,'SoftpubLoadMessage',\
SoftpubLoadSignature,'SoftpubLoadSignature',\
TrustDecode,'TrustDecode',\
TrustFindIssuerCertificate,'TrustFindIssuerCertificate',\
TrustFreeDecode,'TrustFreeDecode',\
TrustIsCertificateSelfSigned,'TrustIsCertificateSelfSigned',\
TrustOpenStores,'TrustOpenStores',\
WTHelperCertCheckValidSignature,'WTHelperCertCheckValidSignature',\
WTHelperCertFindIssuerCertificate,'WTHelperCertFindIssuerCertificate',\
WTHelperCertIsSelfSigned,'WTHelperCertIsSelfSigned',\
WTHelperCheckCertUsage,'WTHelperCheckCertUsage',\
WTHelperGetAgencyInfo,'WTHelperGetAgencyInfo',\
WTHelperGetFileHandle,'WTHelperGetFileHandle',\
WTHelperGetFileHash,'WTHelperGetFileHash',\
WTHelperGetFileName,'WTHelperGetFileName',\
WTHelperGetKnownUsages,'WTHelperGetKnownUsages',\
WTHelperGetProvCertFromChain,'WTHelperGetProvCertFromChain',\
WTHelperGetProvPrivateDataFromChain,'WTHelperGetProvPrivateDataFromChain',\
WTHelperGetProvSignerFromChain,'WTHelperGetProvSignerFromChain',\
WTHelperIsInRootStore,'WTHelperIsInRootStore',\
WTHelperOpenKnownStores,'WTHelperOpenKnownStores',\
WTHelperProvDataFromStateData,'WTHelperProvDataFromStateData',\
WVTAsn1CatMemberInfoDecode,'WVTAsn1CatMemberInfoDecode',\
WVTAsn1CatMemberInfoEncode,'WVTAsn1CatMemberInfoEncode',\
WVTAsn1CatNameValueDecode,'WVTAsn1CatNameValueDecode',\
WVTAsn1CatNameValueEncode,'WVTAsn1CatNameValueEncode',\
WVTAsn1SpcFinancialCriteriaInfoDecode,'WVTAsn1SpcFinancialCriteriaInfoDecode',\
WVTAsn1SpcFinancialCriteriaInfoEncode,'WVTAsn1SpcFinancialCriteriaInfoEncode',\
WVTAsn1SpcIndirectDataContentDecode,'WVTAsn1SpcIndirectDataContentDecode',\
WVTAsn1SpcIndirectDataContentEncode,'WVTAsn1SpcIndirectDataContentEncode',\
WVTAsn1SpcLinkDecode,'WVTAsn1SpcLinkDecode',\
WVTAsn1SpcLinkEncode,'WVTAsn1SpcLinkEncode',\
WVTAsn1SpcMinimalCriteriaInfoDecode,'WVTAsn1SpcMinimalCriteriaInfoDecode',\
WVTAsn1SpcMinimalCriteriaInfoEncode,'WVTAsn1SpcMinimalCriteriaInfoEncode',\
WVTAsn1SpcPeImageDataDecode,'WVTAsn1SpcPeImageDataDecode',\
WVTAsn1SpcPeImageDataEncode,'WVTAsn1SpcPeImageDataEncode',\
WVTAsn1SpcSigInfoDecode,'WVTAsn1SpcSigInfoDecode',\
WVTAsn1SpcSigInfoEncode,'WVTAsn1SpcSigInfoEncode',\
WVTAsn1SpcSpAgencyInfoDecode,'WVTAsn1SpcSpAgencyInfoDecode',\
WVTAsn1SpcSpAgencyInfoEncode,'WVTAsn1SpcSpAgencyInfoEncode',\
WVTAsn1SpcSpOpusInfoDecode,'WVTAsn1SpcSpOpusInfoDecode',\
WVTAsn1SpcSpOpusInfoEncode,'WVTAsn1SpcSpOpusInfoEncode',\
WVTAsn1SpcStatementTypeDecode,'WVTAsn1SpcStatementTypeDecode',\
WVTAsn1SpcStatementTypeEncode,'WVTAsn1SpcStatementTypeEncode',\
WinVerifyTrust,'WinVerifyTrust',\
WinVerifyTrustEx,'WinVerifyTrustEx',\
WintrustAddActionID,'WintrustAddActionID',\
WintrustAddDefaultForUsage,'WintrustAddDefaultForUsage',\
WintrustCertificateTrust,'WintrustCertificateTrust',\
WintrustGetDefaultForUsage,'WintrustGetDefaultForUsage',\
WintrustGetRegPolicyFlags,'WintrustGetRegPolicyFlags',\
WintrustLoadFunctionPointers,'WintrustLoadFunctionPointers',\
WintrustRemoveActionID,'WintrustRemoveActionID',\
WintrustSetDefaultIncludePEPageHashes,'WintrustSetDefaultIncludePEPageHashes',\
WintrustSetRegPolicyFlags,'WintrustSetRegPolicyFlags',\
mscat32DllRegisterServer,'mscat32DllRegisterServer',\
mscat32DllUnregisterServer,'mscat32DllUnregisterServer',\
mssip32DllRegisterServer,'mssip32DllRegisterServer',\
mssip32DllUnregisterServer,'mssip32DllUnregisterServer'

;======================= Undocumented functions (unknown arguments) =======================;
;CryptCATVerifyMember,'CryptCATVerifyMember',\
;CryptSIPGetInfo,'CryptSIPGetInfo',\
;CryptSIPGetRegWorkingFlags,'CryptSIPGetRegWorkingFlags',\
;WVTAsn1CatMemberInfo2Decode,'WVTAsn1CatMemberInfo2Decode',\
;WVTAsn1CatMemberInfo2Encode,'WVTAsn1CatMemberInfo2Encode'

end if ;WINTRUST_INC
