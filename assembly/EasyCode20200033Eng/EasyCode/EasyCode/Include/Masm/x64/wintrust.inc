; ======================================================;
;                                                       ;
;  wintrust.inc for Easy Code 2.0 64-bit Masm projects  ;
;                    (version 1.0.0)                    ;
;                                                       ;
;             Copyright © Ramon Sala - 2020             ;
;                                                       ;
; ======================================================;

IFNDEF WINTRUST_INC
WINTRUST_INC     EQU     1

AddPersonalTrustDBPages PROTO :XWORD,:XWORD,:XWORD
CatalogCompactHashDatabase PROTO :XWORD,:XWORD,:XWORD,:XWORD
CryptCATAdminAcquireContext PROTO :XWORD,:XWORD,:XWORD
CryptCATAdminAcquireContext2 PROTO :XPTR,:XPTR,:XPTR,:XPTR,:XWORD
CryptCATAdminAddCatalog PROTO :XWORD,:XWORD,:XWORD,:XWORD
CryptCATAdminCalcHashFromFileHandle PROTO :XWORD,:XWORD,:XWORD,:XWORD
CryptCATAdminCalcHashFromFileHandle2 PROTO :XWORD,:XWORD,:XPTR,:XPTR,:XWORD
CryptCATAdminEnumCatalogFromHash PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
CryptCATAdminPauseServiceForBackup PROTO :XWORD,:XWORD
CryptCATAdminReleaseCatalogContext PROTO :XWORD,:XWORD,:XWORD
CryptCATAdminReleaseContext PROTO :XWORD,:XWORD
CryptCATAdminRemoveCatalog PROTO :XWORD,:XWORD,:XWORD
CryptCATAdminResolveCatalogPath PROTO :XWORD,:XWORD,:XWORD,:XWORD
CryptCATAllocSortedMemberInfo PROTO :XWORD,:XPTR
CryptCATCDFClose PROTO :XWORD
CryptCATCDFEnumAttributes PROTO :XWORD,:XWORD,:XWORD,:XWORD
CryptCATCDFEnumAttributesWithCDFTag PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
CryptCATCDFEnumCatAttributes PROTO :XWORD,:XWORD,:XWORD
CryptCATCDFEnumMembers PROTO :XWORD,:XWORD,:XWORD
CryptCATCDFEnumMembersByCDFTag PROTO :XWORD,:XWORD,:XWORD,:XWORD
CryptCATCDFEnumMembersByCDFTagEx PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
CryptCATCDFOpen PROTO :XWORD,:XWORD
CryptCATCatalogInfoFromContext PROTO :XWORD,:XWORD,:XWORD
CryptCATClose PROTO :XWORD
CryptCATEnumerateAttr PROTO :XWORD,:XWORD,:XWORD
CryptCATEnumerateCatAttr PROTO :XWORD,:XWORD
CryptCATEnumerateMember PROTO :XWORD,:XWORD
CryptCATFreeSortedMemberInfo PROTO :XWORD
CryptCATGetAttrInfo PROTO :XWORD,:XWORD,:XWORD
CryptCATGetCatAttrInfo PROTO :XWORD,:XWORD
CryptCATGetMemberInfo PROTO :XWORD,:XWORD
CryptCATHandleFromStore PROTO :XWORD
CryptCATOpen PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
CryptCATPersistStore PROTO :XWORD
CryptCATPutAttrInfo PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
CryptCATPutCatAttrInfo PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
CryptCATPutMemberInfo PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
CryptCATStoreFromHandle PROTO :XWORD
CryptSIPCreateIndirectData PROTO :XWORD,:XWORD,:XWORD
CryptSIPGetCaps PROTO :XPTR,:XPTR
CryptSIPGetSignedDataMsg PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
CryptSIPPutSignedDataMsg PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
CryptSIPRemoveSignedDataMsg PROTO :XWORD,:XWORD
CryptSIPVerifyIndirectData PROTO :XWORD,:XWORD
DriverCleanupPolicy PROTO :XWORD
DriverFinalPolicy PROTO :XWORD
DriverInitializePolicy PROTO :XWORD
FindCertsByIssuer PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GenericChainCertificateTrust PROTO :XPTR
GenericChainFinalProv PROTO :XPTR
HTTPSCertificateTrust PROTO :XPTR
HTTPSFinalProv PROTO :XWORD
IsCatalogFile PROTO :XWORD,:XWORD
MsCatConstructHashTag PROTO :XWORD,:XWORD,:XWORD
MsCatFreeHashTag PROTO :XWORD
OfficeCleanupPolicy PROTO :XWORD
OfficeInitializePolicy PROTO :XWORD
OpenPersonalTrustDBDialog PROTO :XWORD
OpenPersonalTrustDBDialogEx PROTO :XWORD,:XWORD,:XWORD
SoftpubAuthenticode PROTO :XWORD
SoftpubCheckCert PROTO :XWORD,:XWORD,:XWORD,:XWORD
SoftpubCleanup PROTO :XWORD
SoftpubDefCertInit PROTO :XPTR
SoftpubDllRegisterServer PROTO
SoftpubDllUnregisterServer PROTO
SoftpubDumpStructure PROTO :XWORD
SoftpubFreeDefUsageCallData PROTO :XPTR
SoftpubInitialize PROTO :XWORD
SoftpubLoadDefUsageCallData PROTO :XPTR,:XPTR
SoftpubLoadMessage PROTO :XWORD
SoftpubLoadSignature PROTO :XWORD
TrustDecode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
TrustFindIssuerCertificate PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
TrustFreeDecode PROTO :XWORD,:XWORD
TrustIsCertificateSelfSigned PROTO :XWORD,:XWORD,:XWORD
TrustOpenStores PROTO :XWORD,:XWORD,:XWORD,:XWORD
WTHelperCertCheckValidSignature PROTO :XWORD
WTHelperCertFindIssuerCertificate PROTO :XPTR,:XPTR,:XPTR,:XPTR,:XPTR
WTHelperCertIsSelfSigned PROTO :XWORD,:XWORD
WTHelperCheckCertUsage PROTO :XWORD,:XWORD
WTHelperGetAgencyInfo PROTO :XWORD,:XWORD,:XWORD
WTHelperGetFileHandle PROTO :XWORD
WTHelperGetFileHash PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WTHelperGetFileName PROTO :XWORD
WTHelperGetKnownUsages PROTO :XWORD,:XWORD
WTHelperGetProvCertFromChain PROTO :XWORD,:XWORD
WTHelperGetProvPrivateDataFromChain PROTO :XWORD,:XWORD
WTHelperGetProvSignerFromChain PROTO :XWORD,:XWORD,:XWORD,:XWORD
WTHelperIsInRootStore PROTO :XWORD,:XWORD
WTHelperOpenKnownStores PROTO :XWORD
WTHelperProvDataFromStateData PROTO :XWORD
WVTAsn1CatMemberInfoDecode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1CatMemberInfoEncode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1CatNameValueDecode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1CatNameValueEncode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcFinancialCriteriaInfoDecode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcFinancialCriteriaInfoEncode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcIndirectDataContentDecode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcIndirectDataContentEncode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcLinkDecode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcLinkEncode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcMinimalCriteriaInfoDecode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcMinimalCriteriaInfoEncode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcPeImageDataDecode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcPeImageDataEncode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcSigInfoDecode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcSigInfoEncode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcSpAgencyInfoDecode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcSpAgencyInfoEncode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcSpOpusInfoDecode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcSpOpusInfoEncode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcStatementTypeDecode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WVTAsn1SpcStatementTypeEncode PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WinVerifyTrust PROTO :XWORD,:XWORD,:XWORD
WinVerifyTrustEx PROTO :XWORD,:XWORD,:XWORD
WintrustAddActionID PROTO :XWORD,:XWORD,:XWORD
WintrustAddDefaultForUsage PROTO :XWORD,:XWORD
WintrustCertificateTrust PROTO :XWORD
WintrustGetDefaultForUsage PROTO :XWORD,:XWORD,:XWORD
WintrustGetRegPolicyFlags PROTO :XWORD
WintrustLoadFunctionPointers PROTO :XWORD,:XWORD
WintrustRemoveActionID PROTO :XWORD
WintrustSetDefaultIncludePEPageHashes PROTO :XWORD
WintrustSetRegPolicyFlags PROTO :XWORD
mscat32DllRegisterServer PROTO
mscat32DllUnregisterServer PROTO
mssip32DllRegisterServer PROTO
mssip32DllUnregisterServer PROTO


;======================= Undocumented functions (unknown arguments) =======================;
;CryptCATVerifyMember PROTO
;CryptSIPGetInfo PROTO
;CryptSIPGetRegWorkingFlags PROTO
;WVTAsn1CatMemberInfo2Decode PROTO
;WVTAsn1CatMemberInfo2Encode PROTO

ENDIF ;WINTRUST_INC
