; ====================================================;
;                                                     ;
;    wintrust.inc for EC v2 SolAsm visual projects    ;
;                   (version 1.0.0)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2020            ;
;                                                     ;
; ====================================================;

#ifndef WINTRUST_INC
WINTRUST_INC equ 1

#if COFF_FORMAT == 1
    from_lib wintrust.lib
#else
    from_dll wintrust.dll
#endif

#ifdef APP_WIN64
    import AddPersonalTrustDBPages
    import CatalogCompactHashDatabase
    import CryptCATAdminAcquireContext
    import CryptCATAdminAcquireContext2
    import CryptCATAdminAddCatalog
    import CryptCATAdminCalcHashFromFileHandle
    import CryptCATAdminCalcHashFromFileHandle2
    import CryptCATAdminEnumCatalogFromHash
    import CryptCATAdminPauseServiceForBackup
    import CryptCATAdminReleaseCatalogContext
    import CryptCATAdminReleaseContext
    import CryptCATAdminRemoveCatalog
    import CryptCATAdminResolveCatalogPath
    import CryptCATAllocSortedMemberInfo
    import CryptCATCDFClose
    import CryptCATCDFEnumAttributes
    import CryptCATCDFEnumAttributesWithCDFTag
    import CryptCATCDFEnumCatAttributes
    import CryptCATCDFEnumMembers
    import CryptCATCDFEnumMembersByCDFTag
    import CryptCATCDFEnumMembersByCDFTagEx
    import CryptCATCDFOpen
    import CryptCATCatalogInfoFromContext
    import CryptCATClose
    import CryptCATEnumerateAttr
    import CryptCATEnumerateCatAttr
    import CryptCATEnumerateMember
    import CryptCATFreeSortedMemberInfo
    import CryptCATGetAttrInfo
    import CryptCATGetCatAttrInfo
    import CryptCATGetMemberInfo
    import CryptCATHandleFromStore
    import CryptCATOpen
    import CryptCATPersistStore
    import CryptCATPutAttrInfo
    import CryptCATPutCatAttrInfo
    import CryptCATPutMemberInfo
    import CryptCATStoreFromHandle
    import CryptSIPCreateIndirectData
    import CryptSIPGetCaps
    import CryptSIPGetSignedDataMsg
    import CryptSIPPutSignedDataMsg
    import CryptSIPRemoveSignedDataMsg
    import CryptSIPVerifyIndirectData
    import DriverCleanupPolicy
    import DriverFinalPolicy
    import DriverInitializePolicy
    import FindCertsByIssuer
    import GenericChainCertificateTrust
    import GenericChainFinalProv
    import HTTPSCertificateTrust
    import HTTPSFinalProv
    import IsCatalogFile
    import MsCatConstructHashTag
    import MsCatFreeHashTag
    import OfficeCleanupPolicy
    import OfficeInitializePolicy
    import OpenPersonalTrustDBDialog
    import OpenPersonalTrustDBDialogEx
    import SoftpubAuthenticode
    import SoftpubCheckCert
    import SoftpubCleanup
    import SoftpubDefCertInit
    import SoftpubDllRegisterServer
    import SoftpubDllUnregisterServer
    import SoftpubDumpStructure
    import SoftpubFreeDefUsageCallData
    import SoftpubInitialize
    import SoftpubLoadDefUsageCallData
    import SoftpubLoadMessage
    import SoftpubLoadSignature
    import TrustDecode
    import TrustFindIssuerCertificate
    import TrustFreeDecode
    import TrustIsCertificateSelfSigned
    import TrustOpenStores
    import WTHelperCertCheckValidSignature
    import WTHelperCertFindIssuerCertificate
    import WTHelperCertIsSelfSigned
    import WTHelperCheckCertUsage
    import WTHelperGetAgencyInfo
    import WTHelperGetFileHandle
    import WTHelperGetFileHash
    import WTHelperGetFileName
    import WTHelperGetKnownUsages
    import WTHelperGetProvCertFromChain
    import WTHelperGetProvPrivateDataFromChain
    import WTHelperGetProvSignerFromChain
    import WTHelperIsInRootStore
    import WTHelperOpenKnownStores
    import WTHelperProvDataFromStateData
    import WVTAsn1CatMemberInfoDecode
    import WVTAsn1CatMemberInfoEncode
    import WVTAsn1CatNameValueDecode
    import WVTAsn1CatNameValueEncode
    import WVTAsn1SpcFinancialCriteriaInfoDecode
    import WVTAsn1SpcFinancialCriteriaInfoEncode
    import WVTAsn1SpcIndirectDataContentDecode
    import WVTAsn1SpcIndirectDataContentEncode
    import WVTAsn1SpcLinkDecode
    import WVTAsn1SpcLinkEncode
    import WVTAsn1SpcMinimalCriteriaInfoDecode
    import WVTAsn1SpcMinimalCriteriaInfoEncode
    import WVTAsn1SpcPeImageDataDecode
    import WVTAsn1SpcPeImageDataEncode
    import WVTAsn1SpcSigInfoDecode
    import WVTAsn1SpcSigInfoEncode
    import WVTAsn1SpcSpAgencyInfoDecode
    import WVTAsn1SpcSpAgencyInfoEncode
    import WVTAsn1SpcSpOpusInfoDecode
    import WVTAsn1SpcSpOpusInfoEncode
    import WVTAsn1SpcStatementTypeDecode
    import WVTAsn1SpcStatementTypeEncode
    import WinVerifyTrust
    import WinVerifyTrustEx
    import WintrustAddActionID
    import WintrustAddDefaultForUsage
    import WintrustCertificateTrust
    import WintrustGetDefaultForUsage
    import WintrustGetRegPolicyFlags
    import WintrustLoadFunctionPointers
    import WintrustRemoveActionID
    import WintrustSetDefaultIncludePEPageHashes
    import WintrustSetRegPolicyFlags
    import mscat32DllRegisterServer
    import mscat32DllUnregisterServer
    import mssip32DllRegisterServer
    import mssip32DllUnregisterServer
#else
    extern AddPersonalTrustDBPages alias _AddPersonalTrustDBPages@12
    extern CatalogCompactHashDatabase alias _CatalogCompactHashDatabase@16
    extern CryptCATAdminAcquireContext alias _CryptCATAdminAcquireContext@12
    extern CryptCATAdminAcquireContext2 alias _CryptCATAdminAcquireContext2@20
    extern CryptCATAdminAddCatalog alias _CryptCATAdminAddCatalog@16
    extern CryptCATAdminCalcHashFromFileHandle alias _CryptCATAdminCalcHashFromFileHandle@16
    extern CryptCATAdminCalcHashFromFileHandle2 alias _CryptCATAdminCalcHashFromFileHandle2@20
    extern CryptCATAdminEnumCatalogFromHash alias _CryptCATAdminEnumCatalogFromHash@20
    extern CryptCATAdminPauseServiceForBackup alias _CryptCATAdminPauseServiceForBackup@8
    extern CryptCATAdminReleaseCatalogContext alias _CryptCATAdminReleaseCatalogContext@12
    extern CryptCATAdminReleaseContext alias _CryptCATAdminReleaseContext@8
    extern CryptCATAdminRemoveCatalog alias _CryptCATAdminRemoveCatalog@12
    extern CryptCATAdminResolveCatalogPath alias _CryptCATAdminResolveCatalogPath@16
    extern CryptCATAllocSortedMemberInfo alias _CryptCATAllocSortedMemberInfo@8
    extern CryptCATCDFClose alias _CryptCATCDFClose@4
    extern CryptCATCDFEnumAttributes alias _CryptCATCDFEnumAttributes@16
    extern CryptCATCDFEnumAttributesWithCDFTag alias _CryptCATCDFEnumAttributesWithCDFTag@20
    extern CryptCATCDFEnumCatAttributes alias _CryptCATCDFEnumCatAttributes@12
    extern CryptCATCDFEnumMembers alias _CryptCATCDFEnumMembers@12
    extern CryptCATCDFEnumMembersByCDFTag alias _CryptCATCDFEnumMembersByCDFTag@16
    extern CryptCATCDFEnumMembersByCDFTagEx alias _CryptCATCDFEnumMembersByCDFTagEx@24
    extern CryptCATCDFOpen alias _CryptCATCDFOpen@8
    extern CryptCATCatalogInfoFromContext alias _CryptCATCatalogInfoFromContext@12
    extern CryptCATClose alias _CryptCATClose@4
    extern CryptCATEnumerateAttr alias _CryptCATEnumerateAttr@12
    extern CryptCATEnumerateCatAttr alias _CryptCATEnumerateCatAttr@8
    extern CryptCATEnumerateMember alias _CryptCATEnumerateMember@8
    extern CryptCATFreeSortedMemberInfo alias _CryptCATFreeSortedMemberInfo@4
    extern CryptCATGetAttrInfo alias _CryptCATGetAttrInfo@12
    extern CryptCATGetCatAttrInfo alias _CryptCATGetCatAttrInfo@8
    extern CryptCATGetMemberInfo alias _CryptCATGetMemberInfo@8
    extern CryptCATHandleFromStore alias _CryptCATHandleFromStore@4
    extern CryptCATOpen alias _CryptCATOpen@20
    extern CryptCATPersistStore alias _CryptCATPersistStore@4
    extern CryptCATPutAttrInfo alias _CryptCATPutAttrInfo@24
    extern CryptCATPutCatAttrInfo alias _CryptCATPutCatAttrInfo@20
    extern CryptCATPutMemberInfo alias _CryptCATPutMemberInfo@28
    extern CryptCATStoreFromHandle alias _CryptCATStoreFromHandle@4
    extern CryptSIPCreateIndirectData alias _CryptSIPCreateIndirectData@12
    extern CryptSIPGetCaps alias _CryptSIPGetCaps@8
    extern CryptSIPGetSignedDataMsg alias _CryptSIPGetSignedDataMsg@20
    extern CryptSIPPutSignedDataMsg alias _CryptSIPPutSignedDataMsg@20
    extern CryptSIPRemoveSignedDataMsg alias _CryptSIPRemoveSignedDataMsg@8
    extern CryptSIPVerifyIndirectData alias _CryptSIPVerifyIndirectData@8
    extern DriverCleanupPolicy alias _DriverCleanupPolicy@4
    extern DriverFinalPolicy alias _DriverFinalPolicy@4
    extern DriverInitializePolicy alias _DriverInitializePolicy@4
    extern FindCertsByIssuer alias _FindCertsByIssuer@28
    extern GenericChainCertificateTrust alias _GenericChainCertificateTrust@4
    extern GenericChainFinalProv alias _GenericChainFinalProv@4
    extern HTTPSCertificateTrust alias _HTTPSCertificateTrust@4
    extern HTTPSFinalProv alias _HTTPSFinalProv@4
    extern IsCatalogFile alias _IsCatalogFile@8
    extern MsCatConstructHashTag alias _MsCatConstructHashTag@12
    extern MsCatFreeHashTag alias _MsCatFreeHashTag@4
    extern OfficeCleanupPolicy alias _OfficeCleanupPolicy@4
    extern OfficeInitializePolicy alias _OfficeInitializePolicy@4
    extern OpenPersonalTrustDBDialog alias _OpenPersonalTrustDBDialog@4
    extern OpenPersonalTrustDBDialogEx alias _OpenPersonalTrustDBDialogEx@12
    extern SoftpubAuthenticode alias _SoftpubAuthenticode@4
    extern SoftpubCheckCert alias _SoftpubCheckCert@16
    extern SoftpubCleanup alias _SoftpubCleanup@4
    extern SoftpubDefCertInit alias _SoftpubDefCertInit@4
    extern SoftpubDllRegisterServer alias _SoftpubDllRegisterServer@0
    extern SoftpubDllUnregisterServer alias _SoftpubDllUnregisterServer@0
    extern SoftpubDumpStructure alias _SoftpubDumpStructure@4
    extern SoftpubFreeDefUsageCallData alias _SoftpubFreeDefUsageCallData@4
    extern SoftpubInitialize alias _SoftpubInitialize@4
    extern SoftpubLoadDefUsageCallData alias _SoftpubLoadDefUsageCallData@8
    extern SoftpubLoadMessage alias _SoftpubLoadMessage@4
    extern SoftpubLoadSignature alias _SoftpubLoadSignature@4
    extern TrustDecode alias _TrustDecode@36
    extern TrustFindIssuerCertificate alias _TrustFindIssuerCertificate@32
    extern TrustFreeDecode alias _TrustFreeDecode@8
    extern TrustIsCertificateSelfSigned alias _TrustIsCertificateSelfSigned@12
    extern TrustOpenStores alias _TrustOpenStores@16
    extern WTHelperCertCheckValidSignature alias _WTHelperCertCheckValidSignature@4
    extern WTHelperCertFindIssuerCertificate alias _WTHelperCertFindIssuerCertificate@20
    extern WTHelperCertIsSelfSigned alias _WTHelperCertIsSelfSigned@8
    extern WTHelperCheckCertUsage alias _WTHelperCheckCertUsage@8
    extern WTHelperGetAgencyInfo alias _WTHelperGetAgencyInfo@12
    extern WTHelperGetFileHandle alias _WTHelperGetFileHandle@4
    extern WTHelperGetFileHash alias _WTHelperGetFileHash@24
    extern WTHelperGetFileName alias _WTHelperGetFileName@4
    extern WTHelperGetKnownUsages alias _WTHelperGetKnownUsages@8
    extern WTHelperGetProvCertFromChain alias _WTHelperGetProvCertFromChain@8
    extern WTHelperGetProvPrivateDataFromChain alias _WTHelperGetProvPrivateDataFromChain@8
    extern WTHelperGetProvSignerFromChain alias _WTHelperGetProvSignerFromChain@16
    extern WTHelperIsInRootStore alias _WTHelperIsInRootStore@8
    extern WTHelperOpenKnownStores alias _WTHelperOpenKnownStores@4
    extern WTHelperProvDataFromStateData alias _WTHelperProvDataFromStateData@4
    extern WVTAsn1CatMemberInfoDecode alias _WVTAsn1CatMemberInfoDecode@28
    extern WVTAsn1CatMemberInfoEncode alias _WVTAsn1CatMemberInfoEncode@20
    extern WVTAsn1CatNameValueDecode alias _WVTAsn1CatNameValueDecode@28
    extern WVTAsn1CatNameValueEncode alias _WVTAsn1CatNameValueEncode@20
    extern WVTAsn1SpcFinancialCriteriaInfoDecode alias _WVTAsn1SpcFinancialCriteriaInfoDecode@28
    extern WVTAsn1SpcFinancialCriteriaInfoEncode alias _WVTAsn1SpcFinancialCriteriaInfoEncode@20
    extern WVTAsn1SpcIndirectDataContentDecode alias _WVTAsn1SpcIndirectDataContentDecode@28
    extern WVTAsn1SpcIndirectDataContentEncode alias _WVTAsn1SpcIndirectDataContentEncode@20
    extern WVTAsn1SpcLinkDecode alias _WVTAsn1SpcLinkDecode@28
    extern WVTAsn1SpcLinkEncode alias _WVTAsn1SpcLinkEncode@20
    extern WVTAsn1SpcMinimalCriteriaInfoDecode alias _WVTAsn1SpcMinimalCriteriaInfoDecode@28
    extern WVTAsn1SpcMinimalCriteriaInfoEncode alias _WVTAsn1SpcMinimalCriteriaInfoEncode@20
    extern WVTAsn1SpcPeImageDataDecode alias _WVTAsn1SpcPeImageDataDecode@28
    extern WVTAsn1SpcPeImageDataEncode alias _WVTAsn1SpcPeImageDataEncode@20
    extern WVTAsn1SpcSigInfoDecode alias _WVTAsn1SpcSigInfoDecode@28
    extern WVTAsn1SpcSigInfoEncode alias _WVTAsn1SpcSigInfoEncode@20
    extern WVTAsn1SpcSpAgencyInfoDecode alias _WVTAsn1SpcSpAgencyInfoDecode@28
    extern WVTAsn1SpcSpAgencyInfoEncode alias _WVTAsn1SpcSpAgencyInfoEncode@20
    extern WVTAsn1SpcSpOpusInfoDecode alias _WVTAsn1SpcSpOpusInfoDecode@28
    extern WVTAsn1SpcSpOpusInfoEncode alias _WVTAsn1SpcSpOpusInfoEncode@20
    extern WVTAsn1SpcStatementTypeDecode alias _WVTAsn1SpcStatementTypeDecode@28
    extern WVTAsn1SpcStatementTypeEncode alias _WVTAsn1SpcStatementTypeEncode@20
    extern WinVerifyTrust alias _WinVerifyTrust@12
    extern WinVerifyTrustEx alias _WinVerifyTrustEx@12
    extern WintrustAddActionID alias _WintrustAddActionID@12
    extern WintrustAddDefaultForUsage alias _WintrustAddDefaultForUsage@8
    extern WintrustCertificateTrust alias _WintrustCertificateTrust@4
    extern WintrustGetDefaultForUsage alias _WintrustGetDefaultForUsage@12
    extern WintrustGetRegPolicyFlags alias _WintrustGetRegPolicyFlags@4
    extern WintrustLoadFunctionPointers alias _WintrustLoadFunctionPointers@8
    extern WintrustRemoveActionID alias _WintrustRemoveActionID@4
    extern WintrustSetDefaultIncludePEPageHashes alias _WintrustSetDefaultIncludePEPageHashes@4
    extern WintrustSetRegPolicyFlags alias _WintrustSetRegPolicyFlags@4
    extern mscat32DllRegisterServer alias _mscat32DllRegisterServer@0
    extern mscat32DllUnregisterServer alias _mscat32DllUnregisterServer@0
    extern mssip32DllRegisterServer alias _mssip32DllRegisterServer@0
    extern mssip32DllUnregisterServer alias _mssip32DllUnregisterServer@0
#endif

#endif ;WINTRUST_INC
