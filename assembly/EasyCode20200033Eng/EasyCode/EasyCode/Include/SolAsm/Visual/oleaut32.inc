; ====================================================;
;                                                     ;
;    oleaut32.inc for EC v2 SolAsm visual projects    ;
;                   (version 1.0.1)                   ;
;                                                     ;
;          Copyright © Ramon Sala - 2018-2019         ;
;                                                     ;
; ====================================================;

#ifndef OLEAUT32_INC
OLEAUT32_INC equ 1

LOAD_TLB_AS_32BIT                                       equ     020H
LOAD_TLB_AS_64BIT                                       equ     040H
MASK_TO_RESET_TLB_BITS                                  equ     <not (LOAD_TLB_AS_32BIT or LOAD_TLB_AS_64BIT)>

STDOLE_MAJORVERNUM                                      equ     01H
STDOLE_MINORVERNUM                                      equ     00H
STDOLE_LCID                                             equ     00H

STDOLE2_MAJORVERNUM                                     equ     02H
STDOLE2_MINORVERNUM                                     equ     00H
STDOLE2_LCID                                            equ     00H

VARIANT_NOVALUEPROP                                     equ     001H
VARIANT_ALPHABOOL                                       equ     002H
VARIANT_NOUSEROVERRIDE                                  equ     004H
VARIANT_CALENDAR_HIJRI                                  equ     008H
VARIANT_LOCALBOOL                                       equ     010H
VARIANT_CALENDAR_THAI                                   equ     020H
VARIANT_CALENDAR_GREGORIAN                              equ     040H
VARIANT_USE_NLS                                         equ     080H

VAR_CALENDAR_THAI                                       equ     000000080H
VAR_CALENDAR_GREGORIAN                                  equ     000000100H
VAR_CALENDAR_HIJRI                                      equ     000000008H

VAR_TIMEVALUEONLY                                       equ     000000001H
VAR_DATEVALUEONLY                                       equ     000000002H
VAR_VALIDDATE                                           equ     000000004H
VAR_LOCALBOOL                                           equ     000000010H
VAR_FORMAT_NOSUBSTITUTE                                 equ     000000020H
VAR_FOURDIGITYEARS                                      equ     000000040H

#ifndef LOCALE_USE_NLS
    LOCALE_USE_NLS                                      equ     010000000H
#endif

NUMPRS_LEADING_WHITE                                    equ     0001H
NUMPRS_TRAILING_WHITE                                   equ     0002H
NUMPRS_LEADING_PLUS                                     equ     0004H
NUMPRS_TRAILING_PLUS                                    equ     0008H
NUMPRS_LEADING_MINUS                                    equ     0010H
NUMPRS_TRAILING_MINUS                                   equ     0020H
NUMPRS_HEX_OCT                                          equ     0040H
NUMPRS_PARENS                                           equ     0080H
NUMPRS_DECIMAL                                          equ     0100H
NUMPRS_THOUSANDS                                        equ     0200H
NUMPRS_CURRENCY                                         equ     0400H
NUMPRS_EXPONENT                                         equ     0800H
NUMPRS_USE_ALL                                          equ     1000H
NUMPRS_STD                                              equ     1FFFH
NUMPRS_NEG                                              equ     10000H
NUMPRS_INEXACT                                          equ     20000H

VARCMP_LT                                               equ     0
VARCMP_EQ                                               equ     1
VARCMP_GT                                               equ     2
VARCMP_NULL                                             equ     3

VT_RESERVED                                             equ     08000H
VT_HARDTYPE                                             equ     VT_RESERVED

DISPID_UNKNOWN                                          equ     (-1)

MEMBERID_NIL                                            equ     DISPID_UNKNOWN
ID_DEFAULTINST                                          equ     (-2)

DISPATCH_METHOD                                         equ     01H
DISPATCH_PROPERTYGET                                    equ     02H
DISPATCH_PROPERTYPUT                                    equ     04H
DISPATCH_PROPERTYPUTREF                                 equ     08H

ACTIVEOBJECT_STRONG                                     equ     00H
ACTIVEOBJECT_WEAK                                       equ     01H

REGKIND_DEFAULT                                         equ     0
REGKIND_REGISTER                                        equ     1
REGKIND_NONE                                            equ     2

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib oleaut32.lib
#else
    from_dll oleaut32.dll
#endif

#ifdef APP_WIN64
    import BSTR_UserFree
    import BSTR_UserFree64
    import BSTR_UserMarshal
    import BSTR_UserMarshal64
    import BSTR_UserSize
    import BSTR_UserSize64
    import BSTR_UserUnmarshal
    import BSTR_UserUnmarshal64
    import BstrFromVector
    import ClearCustData
    import CreateDispTypeInfo
    import CreateErrorInfo
    import CreateStdDispatch
    import CreateTypeLib
    import CreateTypeLib2
    import DispCallFunc
    import DispGetIDsOfNames
    import DispGetParam
    import DispInvoke
    #ifndef DllCanUnloadNow
        import DllCanUnloadNow
    #endif
    #ifndef DllGetClassObject
        import DllGetClassObject
    #endif
    #ifndef DllRegisterServer
        import DllRegisterServer
    #endif
    #ifndef DllUnregisterServer
        import DllUnregisterServer
    #endif
    import DosDateTimeToVariantTime
    import GetActiveObject
    import GetAltMonthNames
    #ifndef GetErrorInfo
        import GetErrorInfo
    #endif
    import GetRecordInfoFromGuids
    import GetRecordInfoFromTypeInfo
    import GetVarConversionLocaleSetting
    #if NTDDI_VERSION >= NTDDI_WIN8
        import HWND_UserFree
        import HWND_UserFree64
        import HWND_UserMarshal
        import HWND_UserMarshal64
        import HWND_UserSize
        import HWND_UserSize64
        import HWND_UserUnmarshal
        import HWND_UserUnmarshal64
    #endif
    import LHashValOfNameSys
    import LHashValOfNameSysA
    import LoadRegTypeLib
    import LoadTypeLib
    import LoadTypeLibEx
    import LPSAFEARRAY_Marshal
    import LPSAFEARRAY_Size
    import LPSAFEARRAY_Unmarshal
    import LPSAFEARRAY_UserFree
    import LPSAFEARRAY_UserFree64
    import LPSAFEARRAY_UserMarshal
    import LPSAFEARRAY_UserMarshal64
    import LPSAFEARRAY_UserSize
    import LPSAFEARRAY_UserSize64
    import LPSAFEARRAY_UserUnmarshal
    import LPSAFEARRAY_UserUnmarshal64
    import OaBuildVersion
    import OACreateTypeLib2
    #if NTDDI_VERSION >= NTDDI_VISTA
        import OaEnablePerUserTLibRegistration
    #endif
    import OleCreateFontIndirect
    import OleCreatePictureIndirect
    import OleCreatePropertyFrame
    import OleCreatePropertyFrameIndirect
    import OleIconToCursor
    import OleLoadPicture
    import OleLoadPictureEx
    import OleLoadPictureFile
    import OleLoadPictureFileEx
    import OleLoadPicturePath
    import OleSavePictureFile
    import OleTranslateColor
    import QueryPathOfRegTypeLib
    import RegisterActiveObject
    import RegisterTypeLib
    import RegisterTypeLibForUser
    import RevokeActiveObject
    import SafeArrayAccessData
    import SafeArrayAllocData
    import SafeArrayAllocDescriptor
    import SafeArrayAllocDescriptorEx
    import SafeArrayCopy
    import SafeArrayCopyData
    import SafeArrayCreate
    import SafeArrayCreateEx
    import SafeArrayCreateVector
    import SafeArrayCreateVectorEx
    import SafeArrayDestroy
    import SafeArrayDestroyData
    import SafeArrayDestroyDescriptor
    import SafeArrayGetDim
    import SafeArrayGetElement
    import SafeArrayGetElemsize
    import SafeArrayGetIID
    import SafeArrayGetLBound
    import SafeArrayGetRecordInfo
    import SafeArrayGetUBound
    import SafeArrayGetVartype
    import SafeArrayLock
    import SafeArrayPtrOfIndex
    import SafeArrayPutElement
    import SafeArrayRedim
    import SafeArraySetIID
    import SafeArraySetRecordInfo
    import SafeArrayUnaccessData
    import SafeArrayUnlock
    #ifndef SetErrorInfo
        import SetErrorInfo
    #endif
    import SetOaNoCache
    import SetVarConversionLocaleSetting
    import SysAllocString
    import SysAllocStringByteLen
    import SysAllocStringLen
    import SysFreeString
    import SysReAllocString
    import SysReAllocStringLen
    import SysStringByteLen
    import SysStringLen
    import SystemTimeToVariantTime
    import UnRegisterTypeLib
    import UnRegisterTypeLibForUser
    import VarAbs
    import VarAdd
    import VarAnd
    import VarBoolFromCy
    import VarBoolFromDate
    import VarBoolFromDec
    import VarBoolFromDisp
    import VarBoolFromI1
    import VarBoolFromI2
    import VarBoolFromI4
    import VarBoolFromI8
    import VarBoolFromR4
    import VarBoolFromR8
    import VarBoolFromStr
    import VarBoolFromUI1
    import VarBoolFromUI2
    import VarBoolFromUI4
    import VarBoolFromUI8
    import VarBstrCat
    import VarBstrCmp
    import VarBstrFromBool
    import VarBstrFromCy
    import VarBstrFromDate
    import VarBstrFromDec
    import VarBstrFromDisp
    import VarBstrFromI1
    import VarBstrFromI2
    import VarBstrFromI4
    import VarBstrFromI8
    import VarBstrFromR4
    import VarBstrFromR8
    import VarBstrFromUI1
    import VarBstrFromUI2
    import VarBstrFromUI4
    import VarBstrFromUI8
    import VarCat
    import VarCmp
    import VarCyAbs
    import VarCyAdd
    import VarCyCmp
    import VarCyCmpR8
    import VarCyFix
    import VarCyFromBool
    import VarCyFromDate
    import VarCyFromDec
    import VarCyFromDisp
    import VarCyFromI1
    import VarCyFromI2
    import VarCyFromI4
    import VarCyFromI8
    import VarCyFromR4
    import VarCyFromR8
    import VarCyFromStr
    import VarCyFromUI1
    import VarCyFromUI2
    import VarCyFromUI4
    import VarCyFromUI8
    import VarCyInt
    import VarCyMul
    import VarCyMulI4
    import VarCyMulI8
    import VarCyNeg
    import VarCyRound
    import VarCySub
    import VarDateFromBool
    import VarDateFromCy
    import VarDateFromDec
    import VarDateFromDisp
    import VarDateFromI1
    import VarDateFromI2
    import VarDateFromI4
    import VarDateFromI8
    import VarDateFromR4
    import VarDateFromR8
    import VarDateFromStr
    import VarDateFromUI1
    import VarDateFromUI2
    import VarDateFromUI4
    import VarDateFromUI8
    import VarDateFromUdate
    import VarDateFromUdateEx
    import VarDecAbs
    import VarDecAdd
    import VarDecCmp
    import VarDecCmpR8
    import VarDecDiv
    import VarDecFix
    import VarDecFromBool
    import VarDecFromCy
    import VarDecFromDate
    import VarDecFromDisp
    import VarDecFromI1
    import VarDecFromI2
    import VarDecFromI4
    import VarDecFromI8
    import VarDecFromR4
    import VarDecFromR8
    import VarDecFromStr
    import VarDecFromUI1
    import VarDecFromUI2
    import VarDecFromUI4
    import VarDecFromUI8
    import VarDecInt
    import VarDecMul
    import VarDecNeg
    import VarDecRound
    import VarDecSub
    import VarDiv
    import VarEqv
    import VarFix
    import VarFormat
    import VarFormatCurrency
    import VarFormatDateTime
    import VarFormatFromTokens
    import VarFormatNumber
    import VarFormatPercent
    import VarI1FromBool
    import VarI1FromCy
    import VarI1FromDate
    import VarI1FromDec
    import VarI1FromDisp
    import VarI1FromI2
    import VarI1FromI4
    import VarI1FromI8
    import VarI1FromR4
    import VarI1FromR8
    import VarI1FromStr
    import VarI1FromUI1
    import VarI1FromUI2
    import VarI1FromUI4
    import VarI1FromUI8
    import VarI2FromBool
    import VarI2FromCy
    import VarI2FromDate
    import VarI2FromDec
    import VarI2FromDisp
    import VarI2FromI1
    import VarI2FromI4
    import VarI2FromI8
    import VarI2FromR4
    import VarI2FromR8
    import VarI2FromStr
    import VarI2FromUI1
    import VarI2FromUI2
    import VarI2FromUI4
    import VarI2FromUI8
    import VarI4FromBool
    import VarI4FromCy
    import VarI4FromDate
    import VarI4FromDec
    import VarI4FromDisp
    import VarI4FromI1
    import VarI4FromI2
    import VarI4FromI8
    import VarI4FromR4
    import VarI4FromR8
    import VarI4FromStr
    import VarI4FromUI1
    import VarI4FromUI2
    import VarI4FromUI4
    import VarI4FromUI8
    import VarI8FromBool
    import VarI8FromCy
    import VarI8FromDate
    import VarI8FromDec
    import VarI8FromDisp
    import VarI8FromI1
    import VarI8FromI2
    import VarI8FromR4
    import VarI8FromR8
    import VarI8FromStr
    import VarI8FromUI1
    import VarI8FromUI2
    import VarI8FromUI4
    import VarI8FromUI8
    import VARIANT_UserFree
    import VARIANT_UserFree64
    import VARIANT_UserMarshal
    import VARIANT_UserMarshal64
    import VARIANT_UserSize
    import VARIANT_UserSize64
    import VARIANT_UserUnmarshal
    import VARIANT_UserUnmarshal64
    import VariantChangeType
    import VariantChangeTypeEx
    import VariantClear
    import VariantCopy
    import VariantCopyInd
    import VariantInit
    import VariantTimeToDosDateTime
    import VariantTimeToSystemTime
    import VarIdiv
    import VarImp
    import VarInt
    import VarMod
    import VarMonthName
    import VarMul
    import VarNeg
    import VarNot
    import VarNumFromParseNum
    import VarOr
    import VarParseNumFromStr
    import VarPow
    import VarR4CmpR8
    import VarR4FromBool
    import VarR4FromCy
    import VarR4FromDate
    import VarR4FromDec
    import VarR4FromDisp
    import VarR4FromI1
    import VarR4FromI2
    import VarR4FromI4
    import VarR4FromI8
    import VarR4FromR8
    import VarR4FromStr
    import VarR4FromUI1
    import VarR4FromUI2
    import VarR4FromUI4
    import VarR4FromUI8
    import VarR8FromBool
    import VarR8FromCy
    import VarR8FromDate
    import VarR8FromDec
    import VarR8FromDisp
    import VarR8FromI1
    import VarR8FromI2
    import VarR8FromI4
    import VarR8FromI8
    import VarR8FromR4
    import VarR8FromStr
    import VarR8FromUI1
    import VarR8FromUI2
    import VarR8FromUI4
    import VarR8FromUI8
    import VarR8Pow
    import VarR8Round
    import VarRound
    import VarSub
    import VarTokenizeFormatString
    import VarUdateFromDate
    import VarUI1FromBool
    import VarUI1FromCy
    import VarUI1FromDate
    import VarUI1FromDec
    import VarUI1FromDisp
    import VarUI1FromI1
    import VarUI1FromI2
    import VarUI1FromI4
    import VarUI1FromI8
    import VarUI1FromR4
    import VarUI1FromR8
    import VarUI1FromStr
    import VarUI1FromUI2
    import VarUI1FromUI4
    import VarUI1FromUI8
    import VarUI2FromBool
    import VarUI2FromCy
    import VarUI2FromDate
    import VarUI2FromDec
    import VarUI2FromDisp
    import VarUI2FromI1
    import VarUI2FromI2
    import VarUI2FromI4
    import VarUI2FromI8
    import VarUI2FromR4
    import VarUI2FromR8
    import VarUI2FromStr
    import VarUI2FromUI1
    import VarUI2FromUI4
    import VarUI2FromUI8
    import VarUI4FromBool
    import VarUI4FromCy
    import VarUI4FromDate
    import VarUI4FromDec
    import VarUI4FromDisp
    import VarUI4FromI1
    import VarUI4FromI2
    import VarUI4FromI4
    import VarUI4FromI8
    import VarUI4FromR4
    import VarUI4FromR8
    import VarUI4FromStr
    import VarUI4FromUI1
    import VarUI4FromUI2
    import VarUI4FromUI8
    import VarUI8FromBool
    import VarUI8FromCy
    import VarUI8FromDate
    import VarUI8FromDec
    import VarUI8FromDisp
    import VarUI8FromI1
    import VarUI8FromI2
    import VarUI8FromI8
    import VarUI8FromR4
    import VarUI8FromR8
    import VarUI8FromStr
    import VarUI8FromUI1
    import VarUI8FromUI2
    import VarUI8FromUI4
    import VarWeekdayName
    import VarXor
    import VectorFromBstr
#else
    extern BSTR_UserFree alias _BSTR_UserFree@8
    ;extern BSTR_UserFree64 alias _BSTR_UserFree64@8
    extern BSTR_UserMarshal alias _BSTR_UserMarshal@12
    ;extern BSTR_UserMarshal64 alias _BSTR_UserMarshal64@12
    extern BSTR_UserSize alias _BSTR_UserSize@12
    ;extern BSTR_UserSize64 alias _BSTR_UserSize64@12
    extern BSTR_UserUnmarshal alias _BSTR_UserUnmarshal@12
    ;extern BSTR_UserUnmarshal64 alias _BSTR_UserUnmarshal64@12
    extern BstrFromVector alias _BstrFromVector@8
    extern ClearCustData alias _ClearCustData@4
    extern CreateDispTypeInfo alias _CreateDispTypeInfo@12
    extern CreateErrorInfo alias _CreateErrorInfo@4
    extern CreateStdDispatch alias _CreateStdDispatch@16
    extern CreateTypeLib alias _CreateTypeLib@12
    extern CreateTypeLib2 alias _CreateTypeLib2@12
    extern DispCallFunc alias _DispCallFunc@32
    extern DispGetIDsOfNames alias _DispGetIDsOfNames@16
    extern DispGetParam alias _DispGetParam@20
    extern DispInvoke alias _DispInvoke@32
    extern DosDateTimeToVariantTime alias _DosDateTimeToVariantTime@12
    extern GetActiveObject alias _GetActiveObject@12
    extern GetAltMonthNames alias _GetAltMonthNames@8
    extern GetErrorInfo alias _GetErrorInfo@8
    extern GetRecordInfoFromGuids alias _GetRecordInfoFromGuids@24
    extern GetRecordInfoFromTypeInfo alias _GetRecordInfoFromTypeInfo@8
    extern GetVarConversionLocaleSetting alias _GetVarConversionLocaleSetting@4
    #if NTDDI_VERSION >= NTDDI_WIN8
        extern HWND_UserFree alias _HWND_UserFree@8
        extern HWND_UserFree64 alias _HWND_UserFree64@8
        extern HWND_UserMarshal alias _HWND_UserMarshal@12
        extern HWND_UserMarshal64 alias _HWND_UserMarshal64@12
        extern HWND_UserSize alias _HWND_UserSize@12
        extern HWND_UserSize64 alias _HWND_UserSize64@12
        extern HWND_UserUnmarshal alias _HWND_UserUnmarshal@12
        extern HWND_UserUnmarshal64 alias _HWND_UserUnmarshal642 @12
    #endif
    ;extern LHashValOfNameSys alias _LHashValOfNameSys@12
    extern LHashValOfNameSysA alias _LHashValOfNameSysA@12
    extern LoadRegTypeLib alias _LoadRegTypeLib@20
    extern LoadTypeLib alias _LoadTypeLib@8
    extern LoadTypeLibEx alias _LoadTypeLibEx@12
    extern LPSAFEARRAY_Marshal alias _LPSAFEARRAY_Marshal@16
    extern LPSAFEARRAY_Size alias _LPSAFEARRAY_Size@16
    extern LPSAFEARRAY_Unmarshal alias _LPSAFEARRAY_Unmarshal@16
    extern LPSAFEARRAY_UserFree alias _LPSAFEARRAY_UserFree@8
    ;extern LPSAFEARRAY_UserFree64 alias _LPSAFEARRAY_UserFree64@8
    extern LPSAFEARRAY_UserMarshal alias _LPSAFEARRAY_UserMarshal@12
    ;extern LPSAFEARRAY_UserMarshal64 alias _LPSAFEARRAY_UserMarshal64@12
    extern LPSAFEARRAY_UserSize alias _LPSAFEARRAY_UserSize@12
    ;extern LPSAFEARRAY_UserSize64 alias _LPSAFEARRAY_UserSize64@12
    extern LPSAFEARRAY_UserUnmarshal alias _LPSAFEARRAY_UserUnmarshal@12
    ;extern LPSAFEARRAY_UserUnmarshal64 alias _LPSAFEARRAY_UserUnmarshal64@12
    extern OaBuildVersion alias _OaBuildVersion@0
    extern OACreateTypeLib2 alias _OACreateTypeLib2@12
    #if NTDDI_VERSION >= NTDDI_VISTA
        extern OaEnablePerUserTLibRegistration alias _OaEnablePerUserTLibRegistration@0
    #endif
    extern OleCreateFontIndirect alias _OleCreateFontIndirect@12
    extern OleCreatePictureIndirect alias _OleCreatePictureIndirect@16
    extern OleCreatePropertyFrame alias _OleCreatePropertyFrame@44
    extern OleCreatePropertyFrameIndirect alias _OleCreatePropertyFrameIndirect@4
    extern OleIconToCursor alias _OleIconToCursor@8
    extern OleLoadPicture alias _OleLoadPicture@20
    extern OleLoadPictureEx alias _OleLoadPictureEx@32
    extern OleLoadPictureFile alias _OleLoadPictureFile@20
    extern OleLoadPictureFileEx alias _OleLoadPictureFileEx@32
    extern OleLoadPicturePath alias _OleLoadPicturePath@24
    extern OleSavePictureFile alias _OleSavePictureFile@8
    extern OleTranslateColor alias _OleTranslateColor@12
    extern QueryPathOfRegTypeLib alias _QueryPathOfRegTypeLib@20
    extern RegisterActiveObject alias _RegisterActiveObject@16
    extern RegisterTypeLib alias _RegisterTypeLib@12
    extern RegisterTypeLibForUser alias _RegisterTypeLibForUser@12
    extern RevokeActiveObject alias _RevokeActiveObject@8
    extern SafeArrayAccessData alias _SafeArrayAccessData@8
    extern SafeArrayAllocData alias _SafeArrayAllocData@4
    extern SafeArrayAllocDescriptor alias _SafeArrayAllocDescriptor@8
    extern SafeArrayAllocDescriptorEx alias _SafeArrayAllocDescriptorEx@12
    extern SafeArrayCopy alias _SafeArrayCopy@8
    extern SafeArrayCopyData alias _SafeArrayCopyData@8
    extern SafeArrayCreate alias _SafeArrayCreate@12
    extern SafeArrayCreateEx alias _SafeArrayCreateEx@16
    extern SafeArrayCreateVector alias _SafeArrayCreateVector@12
    extern SafeArrayCreateVectorEx alias _SafeArrayCreateVectorEx@16
    extern SafeArrayDestroy alias _SafeArrayDestroy@4
    extern SafeArrayDestroyData alias _SafeArrayDestroyData@4
    extern SafeArrayDestroyDescriptor alias _SafeArrayDestroyDescriptor@4
    extern SafeArrayGetDim alias _SafeArrayGetDim@4
    extern SafeArrayGetElement alias _SafeArrayGetElement@12
    extern SafeArrayGetElemsize alias _SafeArrayGetElemsize@4
    extern SafeArrayGetIID alias _SafeArrayGetIID@8
    extern SafeArrayGetLBound alias _SafeArrayGetLBound@12
    extern SafeArrayGetRecordInfo alias _SafeArrayGetRecordInfo@8
    extern SafeArrayGetUBound alias _SafeArrayGetUBound@12
    extern SafeArrayGetVartype alias _SafeArrayGetVartype@8
    extern SafeArrayLock alias _SafeArrayLock@4
    extern SafeArrayPtrOfIndex alias _SafeArrayPtrOfIndex@12
    extern SafeArrayPutElement alias _SafeArrayPutElement@12
    extern SafeArrayRedim alias _SafeArrayRedim@8
    extern SafeArraySetIID alias _SafeArraySetIID@8
    extern SafeArraySetRecordInfo alias _SafeArraySetRecordInfo@8
    extern SafeArrayUnaccessData alias _SafeArrayUnaccessData@4
    extern SafeArrayUnlock alias _SafeArrayUnlock@4
    extern SetErrorInfo alias _SetErrorInfo@8
    ;extern SetOaNoCache alias _SetOaNoCache@4
    extern SetVarConversionLocaleSetting alias _SetVarConversionLocaleSetting@4
    extern SysAllocString alias _SysAllocString@4
    extern SysAllocStringByteLen alias _SysAllocStringByteLen@8
    extern SysAllocStringLen alias _SysAllocStringLen@8
    extern SysFreeString alias _SysFreeString@4
    extern SysReAllocString alias _SysReAllocString@8
    extern SysReAllocStringLen alias _SysReAllocStringLen@12
    extern SysStringByteLen alias _SysStringByteLen@4
    extern SysStringLen alias _SysStringLen@4
    extern SystemTimeToVariantTime alias _SystemTimeToVariantTime@8
    extern UnRegisterTypeLib alias _UnRegisterTypeLib@20
    extern UnRegisterTypeLibForUser alias _UnRegisterTypeLibForUser@20
    extern VarAbs alias _VarAbs@8
    extern VarAdd alias _VarAdd@12
    extern VarAnd alias _VarAnd@12
    extern VarBoolFromCy alias _VarBoolFromCy@12
    extern VarBoolFromDate alias _VarBoolFromDate@12
    extern VarBoolFromDec alias _VarBoolFromDec@8
    extern VarBoolFromDisp alias _VarBoolFromDisp@12
    extern VarBoolFromI1 alias _VarBoolFromI1@8
    extern VarBoolFromI2 alias _VarBoolFromI2@8
    extern VarBoolFromI4 alias _VarBoolFromI4@8
    extern VarBoolFromI8 alias _VarBoolFromI8@12
    extern VarBoolFromR4 alias _VarBoolFromR4@8
    extern VarBoolFromR8 alias _VarBoolFromR8@12
    extern VarBoolFromStr alias _VarBoolFromStr@16
    extern VarBoolFromUI1 alias _VarBoolFromUI1@8
    extern VarBoolFromUI2 alias _VarBoolFromUI2@8
    extern VarBoolFromUI4 alias _VarBoolFromUI4@8
    extern VarBoolFromUI8 alias _VarBoolFromUI8@12
    extern VarBstrCat alias _VarBstrCat@12
    extern VarBstrCmp alias _VarBstrCmp@16
    extern VarBstrFromBool alias _VarBstrFromBool@16
    extern VarBstrFromCy alias _VarBstrFromCy@20
    extern VarBstrFromDate alias _VarBstrFromDate@20
    extern VarBstrFromDec alias _VarBstrFromDec@16
    extern VarBstrFromDisp alias _VarBstrFromDisp@16
    extern VarBstrFromI1 alias _VarBstrFromI1@16
    extern VarBstrFromI2 alias _VarBstrFromI2@16
    extern VarBstrFromI4 alias _VarBstrFromI4@16
    extern VarBstrFromI8 alias _VarBstrFromI8@20
    extern VarBstrFromR4 alias _VarBstrFromR4@16
    extern VarBstrFromR8 alias _VarBstrFromR8@20
    extern VarBstrFromUI1 alias _VarBstrFromUI1@16
    extern VarBstrFromUI2 alias _VarBstrFromUI2@16
    extern VarBstrFromUI4 alias _VarBstrFromUI4@16
    extern VarBstrFromUI8 alias _VarBstrFromUI8@20
    extern VarCat alias _VarCat@12
    extern VarCmp alias _VarCmp@16
    extern VarCyAbs alias _VarCyAbs@12
    extern VarCyAdd alias _VarCyAdd@20
    extern VarCyCmp alias _VarCyCmp@16
    extern VarCyCmpR8 alias _VarCyCmpR8@16
    extern VarCyFix alias _VarCyFix@12
    extern VarCyFromBool alias _VarCyFromBool@8
    extern VarCyFromDate alias _VarCyFromDate@12
    extern VarCyFromDec alias _VarCyFromDec@8
    extern VarCyFromDisp alias _VarCyFromDisp@12
    extern VarCyFromI1 alias _VarCyFromI1@8
    extern VarCyFromI2 alias _VarCyFromI2@8
    extern VarCyFromI4 alias _VarCyFromI4@8
    extern VarCyFromI8 alias _VarCyFromI8@12
    extern VarCyFromR4 alias _VarCyFromR4@8
    extern VarCyFromR8 alias _VarCyFromR8@12
    extern VarCyFromStr alias _VarCyFromStr@16
    extern VarCyFromUI1 alias _VarCyFromUI1@8
    extern VarCyFromUI2 alias _VarCyFromUI2@8
    extern VarCyFromUI4 alias _VarCyFromUI4@8
    extern VarCyFromUI8 alias _VarCyFromUI8@12
    extern VarCyInt alias _VarCyInt@12
    extern VarCyMul alias _VarCyMul@20
    extern VarCyMulI4 alias _VarCyMulI4@16
    extern VarCyMulI8 alias _VarCyMulI8@20
    extern VarCyNeg alias _VarCyNeg@12
    extern VarCyRound alias _VarCyRound@16
    extern VarCySub alias _VarCySub@20
    extern VarDateFromBool alias _VarDateFromBool@8
    extern VarDateFromCy alias _VarDateFromCy@12
    extern VarDateFromDec alias _VarDateFromDec@8
    extern VarDateFromDisp alias _VarDateFromDisp@12
    extern VarDateFromI1 alias _VarDateFromI1@8
    extern VarDateFromI2 alias _VarDateFromI2@8
    extern VarDateFromI4 alias _VarDateFromI4@8
    extern VarDateFromI8 alias _VarDateFromI8@12
    extern VarDateFromR4 alias _VarDateFromR4@8
    extern VarDateFromR8 alias _VarDateFromR8@12
    extern VarDateFromStr alias _VarDateFromStr@16
    extern VarDateFromUI1 alias _VarDateFromUI1@8
    extern VarDateFromUI2 alias _VarDateFromUI2@8
    extern VarDateFromUI4 alias _VarDateFromUI4@8
    extern VarDateFromUI8 alias _VarDateFromUI8@12
    extern VarDateFromUdate alias _VarDateFromUdate@12
    extern VarDateFromUdateEx alias _VarDateFromUdateEx@16
    extern VarDecAbs alias _VarDecAbs@8
    extern VarDecAdd alias _VarDecAdd@12
    extern VarDecCmp alias _VarDecCmp@8
    extern VarDecCmpR8 alias _VarDecCmpR8@12
    extern VarDecDiv alias _VarDecDiv@12
    extern VarDecFix alias _VarDecFix@8
    extern VarDecFromBool alias _VarDecFromBool@8
    extern VarDecFromCy alias _VarDecFromCy@12
    extern VarDecFromDate alias _VarDecFromDate@12
    extern VarDecFromDisp alias _VarDecFromDisp@12
    extern VarDecFromI1 alias _VarDecFromI1@8
    extern VarDecFromI2 alias _VarDecFromI2@8
    extern VarDecFromI4 alias _VarDecFromI4@8
    extern VarDecFromI8 alias _VarDecFromI8@12
    extern VarDecFromR4 alias _VarDecFromR4@8
    extern VarDecFromR8 alias _VarDecFromR8@12
    extern VarDecFromStr alias _VarDecFromStr@16
    extern VarDecFromUI1 alias _VarDecFromUI1@8
    extern VarDecFromUI2 alias _VarDecFromUI2@8
    extern VarDecFromUI4 alias _VarDecFromUI4@8
    extern VarDecFromUI8 alias _VarDecFromUI8@12
    extern VarDecInt alias _VarDecInt@8
    extern VarDecMul alias _VarDecMul@12
    extern VarDecNeg alias _VarDecNeg@8
    extern VarDecRound alias _VarDecRound@12
    extern VarDecSub alias _VarDecSub@12
    extern VarDiv alias _VarDiv@12
    extern VarEqv alias _VarEqv@12
    extern VarFix alias _VarFix@8
    extern VarFormat alias _VarFormat@24
    extern VarFormatCurrency alias _VarFormatCurrency@28
    extern VarFormatDateTime alias _VarFormatDateTime@16
    extern VarFormatFromTokens alias _VarFormatFromTokens@24
    extern VarFormatNumber alias _VarFormatNumber@28
    extern VarFormatPercent alias _VarFormatPercent@28
    extern VarI1FromBool alias _VarI1FromBool@8
    extern VarI1FromCy alias _VarI1FromCy@12
    extern VarI1FromDate alias _VarI1FromDate@12
    extern VarI1FromDec alias _VarI1FromDec@8
    extern VarI1FromDisp alias _VarI1FromDisp@12
    extern VarI1FromI2 alias _VarI1FromI2@8
    extern VarI1FromI4 alias _VarI1FromI4@8
    extern VarI1FromI8 alias _VarI1FromI8@12
    extern VarI1FromR4 alias _VarI1FromR4@8
    extern VarI1FromR8 alias _VarI1FromR8@12
    extern VarI1FromStr alias _VarI1FromStr@16
    extern VarI1FromUI1 alias _VarI1FromUI1@8
    extern VarI1FromUI2 alias _VarI1FromUI2@8
    extern VarI1FromUI4 alias _VarI1FromUI4@8
    extern VarI1FromUI8 alias _VarI1FromUI8@12
    extern VarI2FromBool alias _VarI2FromBool@8
    extern VarI2FromCy alias _VarI2FromCy@12
    extern VarI2FromDate alias _VarI2FromDate@12
    extern VarI2FromDec alias _VarI2FromDec@8
    extern VarI2FromDisp alias _VarI2FromDisp@12
    extern VarI2FromI1 alias _VarI2FromI1@8
    extern VarI2FromI4 alias _VarI2FromI4@8
    extern VarI2FromI8 alias _VarI2FromI8@12
    extern VarI2FromR4 alias _VarI2FromR4@8
    extern VarI2FromR8 alias _VarI2FromR8@12
    extern VarI2FromStr alias _VarI2FromStr@16
    extern VarI2FromUI1 alias _VarI2FromUI1@8
    extern VarI2FromUI2 alias _VarI2FromUI2@8
    extern VarI2FromUI4 alias _VarI2FromUI4@8
    extern VarI2FromUI8 alias _VarI2FromUI8@12
    extern VarI4FromBool alias _VarI4FromBool@8
    extern VarI4FromCy alias _VarI4FromCy@12
    extern VarI4FromDate alias _VarI4FromDate@12
    extern VarI4FromDec alias _VarI4FromDec@8
    extern VarI4FromDisp alias _VarI4FromDisp@12
    extern VarI4FromI1 alias _VarI4FromI1@8
    extern VarI4FromI2 alias _VarI4FromI2@8
    extern VarI4FromI8 alias _VarI4FromI8@12
    extern VarI4FromR4 alias _VarI4FromR4@8
    extern VarI4FromR8 alias _VarI4FromR8@12
    extern VarI4FromStr alias _VarI4FromStr@16
    extern VarI4FromUI1 alias _VarI4FromUI1@8
    extern VarI4FromUI2 alias _VarI4FromUI2@8
    extern VarI4FromUI4 alias _VarI4FromUI4@8
    extern VarI4FromUI8 alias _VarI4FromUI8@12
    extern VarI8FromBool alias _VarI8FromBool@8
    extern VarI8FromCy alias _VarI8FromCy@12
    extern VarI8FromDate alias _VarI8FromDate@12
    extern VarI8FromDec alias _VarI8FromDec@8
    extern VarI8FromDisp alias _VarI8FromDisp@12
    extern VarI8FromI1 alias _VarI8FromI1@8
    extern VarI8FromI2 alias _VarI8FromI2@8
    extern VarI8FromR4 alias _VarI8FromR4@8
    extern VarI8FromR8 alias _VarI8FromR8@12
    extern VarI8FromStr alias _VarI8FromStr@16
    extern VarI8FromUI1 alias _VarI8FromUI1@8
    extern VarI8FromUI2 alias _VarI8FromUI2@8
    extern VarI8FromUI4 alias _VarI8FromUI4@8
    extern VarI8FromUI8 alias _VarI8FromUI8@12
    extern VARIANT_UserFree alias _VARIANT_UserFree@8
    ;extern VARIANT_UserFree64 alias _VARIANT_UserFree64@8
    extern VARIANT_UserMarshal alias _VARIANT_UserMarshal@12
    ;extern VARIANT_UserMarshal64 alias _VARIANT_UserMarshal64@12
    extern VARIANT_UserSize alias _VARIANT_UserSize@12
    ;extern VARIANT_UserSize64 alias _VARIANT_UserSize64@12
    extern VARIANT_UserUnmarshal alias _VARIANT_UserUnmarshal@12
    ;extern VARIANT_UserUnmarshal64 alias _VARIANT_UserUnmarshal64@12
    extern VariantChangeType alias _VariantChangeType@16
    extern VariantChangeTypeEx alias _VariantChangeTypeEx@20
    extern VariantClear alias _VariantClear@4
    extern VariantCopy alias _VariantCopy@8
    extern VariantCopyInd alias _VariantCopyInd@8
    extern VariantInit alias _VariantInit@4
    extern VariantTimeToDosDateTime alias _VariantTimeToDosDateTime@16
    ;extern VariantTimeToSystemTime alias _VariantTimeToSystemTime@8
    extern VarIdiv alias _VarIdiv@12
    extern VarImp alias _VarImp@12
    extern VarInt alias _VarInt@8
    extern VarMod alias _VarMod@12
    extern VarMonthName alias _VarMonthName@16
    extern VarMul alias _VarMul@12
    extern VarNeg alias _VarNeg@8
    extern VarNot alias _VarNot@8
    extern VarNumFromParseNum alias _VarNumFromParseNum@16
    extern VarOr alias _VarOr@12
    extern VarParseNumFromStr alias _VarParseNumFromStr@20
    extern VarPow alias _VarPow@12
    extern VarR4CmpR8 alias _VarR4CmpR8@12
    extern VarR4FromBool alias _VarR4FromBool@8
    extern VarR4FromCy alias _VarR4FromCy@12
    extern VarR4FromDate alias _VarR4FromDate@12
    extern VarR4FromDec alias _VarR4FromDec@8
    extern VarR4FromDisp alias _VarR4FromDisp@12
    extern VarR4FromI1 alias _VarR4FromI1@8
    extern VarR4FromI2 alias _VarR4FromI2@8
    extern VarR4FromI4 alias _VarR4FromI4@8
    extern VarR4FromI8 alias _VarR4FromI8@12
    extern VarR4FromR8 alias _VarR4FromR8@12
    extern VarR4FromStr alias _VarR4FromStr@16
    extern VarR4FromUI1 alias _VarR4FromUI1@8
    extern VarR4FromUI2 alias _VarR4FromUI2@8
    extern VarR4FromUI4 alias _VarR4FromUI4@8
    extern VarR4FromUI8 alias _VarR4FromUI8@12
    extern VarR8FromBool alias _VarR8FromBool@8
    extern VarR8FromCy alias _VarR8FromCy@12
    extern VarR8FromDate alias _VarR8FromDate@12
    extern VarR8FromDec alias _VarR8FromDec@8
    extern VarR8FromDisp alias _VarR8FromDisp@12
    extern VarR8FromI1 alias _VarR8FromI1@8
    extern VarR8FromI2 alias _VarR8FromI2@8
    extern VarR8FromI4 alias _VarR8FromI4@8
    extern VarR8FromI8 alias _VarR8FromI8@12
    extern VarR8FromR4 alias _VarR8FromR4@8
    extern VarR8FromStr alias _VarR8FromStr@16
    extern VarR8FromUI1 alias _VarR8FromUI1@8
    extern VarR8FromUI2 alias _VarR8FromUI2@8
    extern VarR8FromUI4 alias _VarR8FromUI4@8
    extern VarR8FromUI8 alias _VarR8FromUI8@12
    extern VarR8Pow alias _VarR8Pow@20
    extern VarR8Round alias _VarR8Round@16
    extern VarRound alias _VarRound@12
    extern VarSub alias _VarSub@12
    extern VarTokenizeFormatString alias _VarTokenizeFormatString@28
    extern VarUdateFromDate alias _VarUdateFromDate@16
    extern VarUI1FromBool alias _VarUI1FromBool@8
    extern VarUI1FromCy alias _VarUI1FromCy@12
    extern VarUI1FromDate alias _VarUI1FromDate@12
    extern VarUI1FromDec alias _VarUI1FromDec@8
    extern VarUI1FromDisp alias _VarUI1FromDisp@12
    extern VarUI1FromI1 alias _VarUI1FromI1@8
    extern VarUI1FromI2 alias _VarUI1FromI2@8
    extern VarUI1FromI4 alias _VarUI1FromI4@8
    extern VarUI1FromI8 alias _VarUI1FromI8@12
    extern VarUI1FromR4 alias _VarUI1FromR4@8
    extern VarUI1FromR8 alias _VarUI1FromR8@12
    extern VarUI1FromStr alias _VarUI1FromStr@16
    extern VarUI1FromUI2 alias _VarUI1FromUI2@8
    extern VarUI1FromUI4 alias _VarUI1FromUI4@8
    extern VarUI1FromUI8 alias _VarUI1FromUI8@12
    extern VarUI2FromBool alias _VarUI2FromBool@8
    extern VarUI2FromCy alias _VarUI2FromCy@12
    extern VarUI2FromDate alias _VarUI2FromDate@12
    extern VarUI2FromDec alias _VarUI2FromDec@8
    extern VarUI2FromDisp alias _VarUI2FromDisp@12
    extern VarUI2FromI1 alias _VarUI2FromI1@8
    extern VarUI2FromI2 alias _VarUI2FromI2@8
    extern VarUI2FromI4 alias _VarUI2FromI4@8
    extern VarUI2FromI8 alias _VarUI2FromI8@12
    extern VarUI2FromR4 alias _VarUI2FromR4@8
    extern VarUI2FromR8 alias _VarUI2FromR8@12
    extern VarUI2FromStr alias _VarUI2FromStr@16
    extern VarUI2FromUI1 alias _VarUI2FromUI1@8
    extern VarUI2FromUI4 alias _VarUI2FromUI4@8
    extern VarUI2FromUI8 alias _VarUI2FromUI8@12
    extern VarUI4FromBool alias _VarUI4FromBool@8
    extern VarUI4FromCy alias _VarUI4FromCy@12
    extern VarUI4FromDate alias _VarUI4FromDate@12
    extern VarUI4FromDec alias _VarUI4FromDec@8
    extern VarUI4FromDisp alias _VarUI4FromDisp@12
    extern VarUI4FromI1 alias _VarUI4FromI1@8
    extern VarUI4FromI2 alias _VarUI4FromI2@8
    extern VarUI4FromI4 alias _VarUI4FromI4@8
    extern VarUI4FromI8 alias _VarUI4FromI8@12
    extern VarUI4FromR4 alias _VarUI4FromR4@8
    extern VarUI4FromR8 alias _VarUI4FromR8@12
    extern VarUI4FromStr alias _VarUI4FromStr@16
    extern VarUI4FromUI1 alias _VarUI4FromUI1@8
    extern VarUI4FromUI2 alias _VarUI4FromUI2@8
    extern VarUI4FromUI8 alias _VarUI4FromUI8@12
    extern VarUI8FromBool alias _VarUI8FromBool@8
    extern VarUI8FromCy alias _VarUI8FromCy@12
    extern VarUI8FromDate alias _VarUI8FromDate@12
    extern VarUI8FromDec alias _VarUI8FromDec@8
    extern VarUI8FromDisp alias _VarUI8FromDisp@12
    extern VarUI8FromI1 alias _VarUI8FromI1@8
    extern VarUI8FromI2 alias _VarUI8FromI2@8
    extern VarUI8FromI8 alias _VarUI8FromI8@12
    extern VarUI8FromR4 alias _VarUI8FromR4@8
    extern VarUI8FromR8 alias _VarUI8FromR8@12
    extern VarUI8FromStr alias _VarUI8FromStr@16
    extern VarUI8FromUI1 alias _VarUI8FromUI1@8
    extern VarUI8FromUI2 alias _VarUI8FromUI2@8
    extern VarUI8FromUI4 alias _VarUI8FromUI4@8
    extern VarWeekdayName alias _VarWeekdayName@20
    extern VarXor alias _VarXor@12
    extern VectorFromBstr alias _VectorFromBstr@8
#endif

define VarUI1FromInt VarUI1FromI4
define VarUI1FromUint VarUI1FromUI4
define VarI2FromInt VarI2FromI4
define VarI2FromUint VarI2FromUI4
define VarI4FromInt VarI4FromI4
define VarI4FromUint VarI4FromUI4
define VarI8FromUint VarI8FromUI4
define VarR4FromInt VarR4FromI4
define VarR4FromUint VarR4FromUI4
define VarR8FromInt VarR8FromI4
define VarR8FromUint VarR8FromUI4
define VarDateFromInt VarDateFromI4
define VarDateFromUint VarDateFromUI4
define VarCyFromInt VarCyFromI4
define VarCyFromUint VarCyFromUI4
define VarBstrFromInt VarBstrFromI4
define VarBstrFromUint VarBstrFromUI4
define VarBoolFromInt VarBoolFromI4
define VarBoolFromUint VarBoolFromUI4
define VarI1FromInt VarI1FromI4
define VarI1FromUint VarI1FromUI4
define VarUI2FromInt VarUI2FromI4
define VarUI2FromUint VarUI2FromUI4
define VarUI4FromInt VarUI4FromI4
define VarUI4FromUint VarUI4FromUI4
define VarDecFromInt VarDecFromI4
define VarDecFromUint VarDecFromUI4
define VarIntFromUI1 VarI4FromUI1
define VarIntFromI2 VarI4FromI2
define VarIntFromI4 VarI4FromI4
define VarIntFromI8 VarI4FromI8
define VarIntFromR4 VarI4FromR4
define VarIntFromR8 VarI4FromR8
define VarIntFromDate VarI4FromDate
define VarIntFromCy VarI4FromCy
define VarIntFromStr VarI4FromStr
define VarIntFromDisp VarI4FromDisp
define VarIntFromBool VarI4FromBool
define VarIntFromI1 VarI4FromI1
define VarIntFromUI2 VarI4FromUI2
define VarIntFromUI4 VarI4FromUI4
define VarIntFromUI8 VarI4FromUI8
define VarIntFromDec VarI4FromDec
define VarIntFromUint VarI4FromUI4
define VarUintFromUI1 VarUI4FromUI1
define VarUintFromI2 VarUI4FromI2
define VarUintFromI4 VarUI4FromI4
define VarUintFromI8 VarUI4FromI8
define VarUintFromR4 VarUI4FromR4
define VarUintFromR8 VarUI4FromR8
define VarUintFromDate VarUI4FromDate
define VarUintFromCy VarUI4FromCy
define VarUintFromStr VarUI4FromStr
define VarUintFromDisp VarUI4FromDisp
define VarUintFromBool VarUI4FromBool
define VarUintFromI1 VarUI4FromI1
define VarUintFromUI2 VarUI4FromUI2
define VarUintFromUI4 VarUI4FromUI4
define VarUintFromUI8 VarUI4FromUI8
define VarUintFromDec VarUI4FromDec
define VarUintFromInt VarUI4FromI4

#endif ;OLEAUT32_INC
