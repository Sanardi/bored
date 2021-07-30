; ====================================================;
;                                                     ;
;     oleaut32.inc for EC v2 Fasm visual projects     ;
;                   (version 1.0.2)                   ;
;                                                     ;
;          Copyright © Ramon Sala - 2018-2020         ;
;                                                     ;
; ====================================================;

if ~defined OLEAUT32_INC
define OLEAUT32_INC 1

LOAD_TLB_AS_32BIT                                       equ     020H
LOAD_TLB_AS_64BIT                                       equ     040H
MASK_TO_RESET_TLB_BITS                                  equ     not (LOAD_TLB_AS_32BIT or LOAD_TLB_AS_64BIT)

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

if ~defined LOCALE_USE_NLS
    LOCALE_USE_NLS                                      equ     010000000H
end if

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

;======================================== Structures ======================================;
struct NUMPARSE
    cDig       dd ?
    dwInFlags  dd ?
    dwOutFlags dd ?
    cchUsed    dd ?
    nBaseShift dd ?
    nPwr10     dd ?
ends

struct UDATE
    _st SYSTEMTIME <>
    wDayOfYear dw ?
ends

struct PARAMDATA
    szName     xptr    ?
    vt         VARTYPE ?
ends

struct METHODDATA
    szName     xptr ?
    ppdata     xptr ?
    dispid     dd   ?
    iMeth      dd   ?
    cc         dd   ?
    cArgs      dd   ?
    wFlags     dw   ?
    vtReturn   dw   ?
ends

struct INTERFACEDATA
    pmethdata  xptr ?
    cMembers   dd   ?
ends

;======================================== Functions =======================================;
if defined APP_WIN64
    extrn '__imp_BSTR_UserFree' as BSTR_UserFree:qword
    extrn '__imp_BSTR_UserFree64' as BSTR_UserFree64:qword
    extrn '__imp_BSTR_UserMarshal' as BSTR_UserMarshal:qword
    extrn '__imp_BSTR_UserMarshal64' as BSTR_UserMarshal64:qword
    extrn '__imp_BSTR_UserSize' as BSTR_UserSize:qword
    extrn '__imp_BSTR_UserSize64' as BSTR_UserSize64:qword
    extrn '__imp_BSTR_UserUnmarshal' as BSTR_UserUnmarshal:qword
    extrn '__imp_BSTR_UserUnmarshal64' as BSTR_UserUnmarshal64:qword
    extrn '__imp_BstrFromVector' as BstrFromVector:qword
    extrn '__imp_ClearCustData' as ClearCustData:qword
    extrn '__imp_CreateDispTypeInfo' as CreateDispTypeInfo:qword
    extrn '__imp_CreateErrorInfo' as CreateErrorInfo:qword
    extrn '__imp_CreateStdDispatch' as CreateStdDispatch:qword
    extrn '__imp_CreateTypeLib' as CreateTypeLib:qword
    extrn '__imp_CreateTypeLib2' as CreateTypeLib2:qword
    extrn '__imp_DispCallFunc' as DispCallFunc:qword
    extrn '__imp_DispGetIDsOfNames' as DispGetIDsOfNames:qword
    extrn '__imp_DispGetParam' as DispGetParam:qword
    extrn '__imp_DispInvoke' as DispInvoke:qword
    if ~defined __imp_DllCanUnloadNow
        extrn '__imp_DllCanUnloadNow' as DllCanUnloadNow:qword
    end if
    if ~defined __imp_DllRegisterServer
        extrn '__imp_DllRegisterServer' as DllRegisterServer:qword
    end if
    if ~defined __imp_DllUnregisterServer
        extrn '__imp_DllUnregisterServer' as DllUnregisterServer:qword
    end if
    extrn '__imp_DosDateTimeToVariantTime' as DosDateTimeToVariantTime:qword
    extrn '__imp_GetActiveObject' as GetActiveObject:qword
    extrn '__imp_GetAltMonthNames' as GetAltMonthNames:qword
    extrn '__imp_GetErrorInfo' as GetErrorInfo:qword
    extrn '__imp_GetRecordInfoFromGuids' as GetRecordInfoFromGuids:qword
    extrn '__imp_GetRecordInfoFromTypeInfo' as GetRecordInfoFromTypeInfo:qword
    extrn '__imp_GetVarConversionLocaleSetting' as GetVarConversionLocaleSetting:qword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_HWND_UserFree' as HWND_UserFree:qword
        extrn '__imp_HWND_UserFree64' as HWND_UserFree64:qword
        extrn '__imp_HWND_UserMarshal' as HWND_UserMarshal:qword
        extrn '__imp_HWND_UserMarshal64' as HWND_UserMarshal64:qword
        extrn '__imp_HWND_UserSize' as HWND_UserSize:qword
        extrn '__imp_HWND_UserSize64' as HWND_UserSize64:qword
        extrn '__imp_HWND_UserUnmarshal' as HWND_UserUnmarshal:qword
        extrn '__imp_HWND_UserUnmarshal64' as HWND_UserUnmarshal64:qword
    end if
    extrn '__imp_LHashValOfNameSys' as LHashValOfNameSys:qword
    extrn '__imp_LHashValOfNameSysA' as LHashValOfNameSysA:qword
    extrn '__imp_LoadRegTypeLib' as LoadRegTypeLib:qword
    extrn '__imp_LoadTypeLib' as LoadTypeLib:qword
    extrn '__imp_LoadTypeLibEx' as LoadTypeLibEx:qword
    extrn '__imp_LPSAFEARRAY_Marshal' as LPSAFEARRAY_Marshal:qword
    extrn '__imp_LPSAFEARRAY_Size' as LPSAFEARRAY_Size:qword
    extrn '__imp_LPSAFEARRAY_Unmarshal' as LPSAFEARRAY_Unmarshal:qword
    extrn '__imp_LPSAFEARRAY_UserFree' as LPSAFEARRAY_UserFree:qword
    extrn '__imp_LPSAFEARRAY_UserFree64' as LPSAFEARRAY_UserFree64:qword
    extrn '__imp_LPSAFEARRAY_UserMarshal' as LPSAFEARRAY_UserMarshal:qword
    extrn '__imp_LPSAFEARRAY_UserMarshal64' as LPSAFEARRAY_UserMarshal64:qword
    extrn '__imp_LPSAFEARRAY_UserSize' as LPSAFEARRAY_UserSize:qword
    extrn '__imp_LPSAFEARRAY_UserSize64' as LPSAFEARRAY_UserSize64:qword
    extrn '__imp_LPSAFEARRAY_UserUnmarshal' as LPSAFEARRAY_UserUnmarshal:qword
    extrn '__imp_LPSAFEARRAY_UserUnmarshal64' as LPSAFEARRAY_UserUnmarshal64:qword
    extrn '__imp_OaBuildVersion' as OaBuildVersion:qword
    extrn '__imp_OACreateTypeLib2' as OACreateTypeLib2:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_OaEnablePerUserTLibRegistration' as OaEnablePerUserTLibRegistration:qword
    end if
    extrn '__imp_OleCreateFontIndirect' as OleCreateFontIndirect:qword
    extrn '__imp_OleCreatePictureIndirect' as OleCreatePictureIndirect:qword
    extrn '__imp_OleCreatePropertyFrame' as OleCreatePropertyFrame:qword
    extrn '__imp_OleCreatePropertyFrameIndirect' as OleCreatePropertyFrameIndirect:qword
    extrn '__imp_OleIconToCursor' as OleIconToCursor:qword
    extrn '__imp_OleLoadPicture' as OleLoadPicture:qword
    extrn '__imp_OleLoadPictureEx' as OleLoadPictureEx:qword
    extrn '__imp_OleLoadPictureFile' as OleLoadPictureFile:qword
    extrn '__imp_OleLoadPictureFileEx' as OleLoadPictureFileEx:qword
    extrn '__imp_OleLoadPicturePath' as OleLoadPicturePath:qword
    extrn '__imp_OleSavePictureFile' as OleSavePictureFile:qword
    extrn '__imp_OleTranslateColor' as OleTranslateColor:qword
    extrn '__imp_QueryPathOfRegTypeLib' as QueryPathOfRegTypeLib:qword
    extrn '__imp_RegisterActiveObject' as RegisterActiveObject:qword
    extrn '__imp_RegisterTypeLib' as RegisterTypeLib:qword
    extrn '__imp_RegisterTypeLibForUser' as RegisterTypeLibForUser:qword
    extrn '__imp_RevokeActiveObject' as RevokeActiveObject:qword
    extrn '__imp_SafeArrayAccessData' as SafeArrayAccessData:qword
    extrn '__imp_SafeArrayAllocData' as SafeArrayAllocData:qword
    extrn '__imp_SafeArrayAllocDescriptor' as SafeArrayAllocDescriptor:qword
    extrn '__imp_SafeArrayAllocDescriptorEx' as SafeArrayAllocDescriptorEx:qword
    extrn '__imp_SafeArrayCopy' as SafeArrayCopy:qword
    extrn '__imp_SafeArrayCopyData' as SafeArrayCopyData:qword
    extrn '__imp_SafeArrayCreate' as SafeArrayCreate:qword
    extrn '__imp_SafeArrayCreateEx' as SafeArrayCreateEx:qword
    extrn '__imp_SafeArrayCreateVector' as SafeArrayCreateVector:qword
    extrn '__imp_SafeArrayCreateVectorEx' as SafeArrayCreateVectorEx:qword
    extrn '__imp_SafeArrayDestroy' as SafeArrayDestroy:qword
    extrn '__imp_SafeArrayDestroyData' as SafeArrayDestroyData:qword
    extrn '__imp_SafeArrayDestroyDescriptor' as SafeArrayDestroyDescriptor:qword
    extrn '__imp_SafeArrayGetDim' as SafeArrayGetDim:qword
    extrn '__imp_SafeArrayGetElement' as SafeArrayGetElement:qword
    extrn '__imp_SafeArrayGetElemsize' as SafeArrayGetElemsize:qword
    extrn '__imp_SafeArrayGetIID' as SafeArrayGetIID:qword
    extrn '__imp_SafeArrayGetLBound' as SafeArrayGetLBound:qword
    extrn '__imp_SafeArrayGetRecordInfo' as SafeArrayGetRecordInfo:qword
    extrn '__imp_SafeArrayGetUBound' as SafeArrayGetUBound:qword
    extrn '__imp_SafeArrayGetVartype' as SafeArrayGetVartype:qword
    extrn '__imp_SafeArrayLock' as SafeArrayLock:qword
    extrn '__imp_SafeArrayPtrOfIndex' as SafeArrayPtrOfIndex:qword
    extrn '__imp_SafeArrayPutElement' as SafeArrayPutElement:qword
    extrn '__imp_SafeArrayRedim' as SafeArrayRedim:qword
    extrn '__imp_SafeArraySetIID' as SafeArraySetIID:qword
    extrn '__imp_SafeArraySetRecordInfo' as SafeArraySetRecordInfo:qword
    extrn '__imp_SafeArrayUnaccessData' as SafeArrayUnaccessData:qword
    extrn '__imp_SafeArrayUnlock' as SafeArrayUnlock:qword
    extrn '__imp_SetErrorInfo' as SetErrorInfo:qword
    extrn '__imp_SetOaNoCache' as SetOaNoCache:qword
    extrn '__imp_SetVarConversionLocaleSetting' as SetVarConversionLocaleSetting:qword
    extrn '__imp_SysAllocString' as SysAllocString:qword
    extrn '__imp_SysAllocStringByteLen' as SysAllocStringByteLen:qword
    extrn '__imp_SysAllocStringLen' as SysAllocStringLen:qword
    extrn '__imp_SysFreeString' as SysFreeString:qword
    extrn '__imp_SysReAllocString' as SysReAllocString:qword
    extrn '__imp_SysReAllocStringLen' as SysReAllocStringLen:qword
    extrn '__imp_SysStringByteLen' as SysStringByteLen:qword
    extrn '__imp_SysStringLen' as SysStringLen:qword
    extrn '__imp_SystemTimeToVariantTime' as SystemTimeToVariantTime:qword
    extrn '__imp_UnRegisterTypeLib' as UnRegisterTypeLib:qword
    extrn '__imp_UnRegisterTypeLibForUser' as UnRegisterTypeLibForUser:qword
    extrn '__imp_VarAbs' as VarAbs:qword
    extrn '__imp_VarAdd' as VarAdd:qword
    extrn '__imp_VarAnd' as VarAnd:qword
    extrn '__imp_VarBoolFromCy' as VarBoolFromCy:qword
    extrn '__imp_VarBoolFromDate' as VarBoolFromDate:qword
    extrn '__imp_VarBoolFromDec' as VarBoolFromDec:qword
    extrn '__imp_VarBoolFromDisp' as VarBoolFromDisp:qword
    extrn '__imp_VarBoolFromI1' as VarBoolFromI1:qword
    extrn '__imp_VarBoolFromI2' as VarBoolFromI2:qword
    extrn '__imp_VarBoolFromI4' as VarBoolFromI4:qword
    extrn '__imp_VarBoolFromI8' as VarBoolFromI8:qword
    extrn '__imp_VarBoolFromR4' as VarBoolFromR4:qword
    extrn '__imp_VarBoolFromR8' as VarBoolFromR8:qword
    extrn '__imp_VarBoolFromStr' as VarBoolFromStr:qword
    extrn '__imp_VarBoolFromUI1' as VarBoolFromUI1:qword
    extrn '__imp_VarBoolFromUI2' as VarBoolFromUI2:qword
    extrn '__imp_VarBoolFromUI4' as VarBoolFromUI4:qword
    extrn '__imp_VarBoolFromUI8' as VarBoolFromUI8:qword
    extrn '__imp_VarBstrCat' as VarBstrCat:qword
    extrn '__imp_VarBstrCmp' as VarBstrCmp:qword
    extrn '__imp_VarBstrFromBool' as VarBstrFromBool:qword
    extrn '__imp_VarBstrFromCy' as VarBstrFromCy:qword
    extrn '__imp_VarBstrFromDate' as VarBstrFromDate:qword
    extrn '__imp_VarBstrFromDec' as VarBstrFromDec:qword
    extrn '__imp_VarBstrFromDisp' as VarBstrFromDisp:qword
    extrn '__imp_VarBstrFromI1' as VarBstrFromI1:qword
    extrn '__imp_VarBstrFromI2' as VarBstrFromI2:qword
    extrn '__imp_VarBstrFromI4' as VarBstrFromI4:qword
    extrn '__imp_VarBstrFromI8' as VarBstrFromI8:qword
    extrn '__imp_VarBstrFromR4' as VarBstrFromR4:qword
    extrn '__imp_VarBstrFromR8' as VarBstrFromR8:qword
    extrn '__imp_VarBstrFromUI1' as VarBstrFromUI1:qword
    extrn '__imp_VarBstrFromUI2' as VarBstrFromUI2:qword
    extrn '__imp_VarBstrFromUI4' as VarBstrFromUI4:qword
    extrn '__imp_VarBstrFromUI8' as VarBstrFromUI8:qword
    extrn '__imp_VarCat' as VarCat:qword
    extrn '__imp_VarCmp' as VarCmp:qword
    extrn '__imp_VarCyAbs' as VarCyAbs:qword
    extrn '__imp_VarCyAdd' as VarCyAdd:qword
    extrn '__imp_VarCyCmp' as VarCyCmp:qword
    extrn '__imp_VarCyCmpR8' as VarCyCmpR8:qword
    extrn '__imp_VarCyFix' as VarCyFix:qword
    extrn '__imp_VarCyFromBool' as VarCyFromBool:qword
    extrn '__imp_VarCyFromDate' as VarCyFromDate:qword
    extrn '__imp_VarCyFromDec' as VarCyFromDec:qword
    extrn '__imp_VarCyFromDisp' as VarCyFromDisp:qword
    extrn '__imp_VarCyFromI1' as VarCyFromI1:qword
    extrn '__imp_VarCyFromI2' as VarCyFromI2:qword
    extrn '__imp_VarCyFromI4' as VarCyFromI4:qword
    extrn '__imp_VarCyFromI8' as VarCyFromI8:qword
    extrn '__imp_VarCyFromR4' as VarCyFromR4:qword
    extrn '__imp_VarCyFromR8' as VarCyFromR8:qword
    extrn '__imp_VarCyFromStr' as VarCyFromStr:qword
    extrn '__imp_VarCyFromUI1' as VarCyFromUI1:qword
    extrn '__imp_VarCyFromUI2' as VarCyFromUI2:qword
    extrn '__imp_VarCyFromUI4' as VarCyFromUI4:qword
    extrn '__imp_VarCyFromUI8' as VarCyFromUI8:qword
    extrn '__imp_VarCyInt' as VarCyInt:qword
    extrn '__imp_VarCyMul' as VarCyMul:qword
    extrn '__imp_VarCyMulI4' as VarCyMulI4:qword
    extrn '__imp_VarCyMulI8' as VarCyMulI8:qword
    extrn '__imp_VarCyNeg' as VarCyNeg:qword
    extrn '__imp_VarCyRound' as VarCyRound:qword
    extrn '__imp_VarCySub' as VarCySub:qword
    extrn '__imp_VarDateFromBool' as VarDateFromBool:qword
    extrn '__imp_VarDateFromCy' as VarDateFromCy:qword
    extrn '__imp_VarDateFromDec' as VarDateFromDec:qword
    extrn '__imp_VarDateFromDisp' as VarDateFromDisp:qword
    extrn '__imp_VarDateFromI1' as VarDateFromI1:qword
    extrn '__imp_VarDateFromI2' as VarDateFromI2:qword
    extrn '__imp_VarDateFromI4' as VarDateFromI4:qword
    extrn '__imp_VarDateFromI8' as VarDateFromI8:qword
    extrn '__imp_VarDateFromR4' as VarDateFromR4:qword
    extrn '__imp_VarDateFromR8' as VarDateFromR8:qword
    extrn '__imp_VarDateFromStr' as VarDateFromStr:qword
    extrn '__imp_VarDateFromUI1' as VarDateFromUI1:qword
    extrn '__imp_VarDateFromUI2' as VarDateFromUI2:qword
    extrn '__imp_VarDateFromUI4' as VarDateFromUI4:qword
    extrn '__imp_VarDateFromUI8' as VarDateFromUI8:qword
    extrn '__imp_VarDateFromUdate' as VarDateFromUdate:qword
    extrn '__imp_VarDateFromUdateEx' as VarDateFromUdateEx:qword
    extrn '__imp_VarDecAbs' as VarDecAbs:qword
    extrn '__imp_VarDecAdd' as VarDecAdd:qword
    extrn '__imp_VarDecCmp' as VarDecCmp:qword
    extrn '__imp_VarDecCmpR8' as VarDecCmpR8:qword
    extrn '__imp_VarDecDiv' as VarDecDiv:qword
    extrn '__imp_VarDecFix' as VarDecFix:qword
    extrn '__imp_VarDecFromBool' as VarDecFromBool:qword
    extrn '__imp_VarDecFromCy' as VarDecFromCy:qword
    extrn '__imp_VarDecFromDate' as VarDecFromDate:qword
    extrn '__imp_VarDecFromDisp' as VarDecFromDisp:qword
    extrn '__imp_VarDecFromI1' as VarDecFromI1:qword
    extrn '__imp_VarDecFromI2' as VarDecFromI2:qword
    extrn '__imp_VarDecFromI4' as VarDecFromI4:qword
    extrn '__imp_VarDecFromI8' as VarDecFromI8:qword
    extrn '__imp_VarDecFromR4' as VarDecFromR4:qword
    extrn '__imp_VarDecFromR8' as VarDecFromR8:qword
    extrn '__imp_VarDecFromStr' as VarDecFromStr:qword
    extrn '__imp_VarDecFromUI1' as VarDecFromUI1:qword
    extrn '__imp_VarDecFromUI2' as VarDecFromUI2:qword
    extrn '__imp_VarDecFromUI4' as VarDecFromUI4:qword
    extrn '__imp_VarDecFromUI8' as VarDecFromUI8:qword
    extrn '__imp_VarDecInt' as VarDecInt:qword
    extrn '__imp_VarDecMul' as VarDecMul:qword
    extrn '__imp_VarDecNeg' as VarDecNeg:qword
    extrn '__imp_VarDecRound' as VarDecRound:qword
    extrn '__imp_VarDecSub' as VarDecSub:qword
    extrn '__imp_VarDiv' as VarDiv:qword
    extrn '__imp_VarEqv' as VarEqv:qword
    extrn '__imp_VarFix' as VarFix:qword
    extrn '__imp_VarFormat' as VarFormat:qword
    extrn '__imp_VarFormatCurrency' as VarFormatCurrency:qword
    extrn '__imp_VarFormatDateTime' as VarFormatDateTime:qword
    extrn '__imp_VarFormatFromTokens' as VarFormatFromTokens:qword
    extrn '__imp_VarFormatNumber' as VarFormatNumber:qword
    extrn '__imp_VarFormatPercent' as VarFormatPercent:qword
    extrn '__imp_VarI1FromBool' as VarI1FromBool:qword
    extrn '__imp_VarI1FromCy' as VarI1FromCy:qword
    extrn '__imp_VarI1FromDate' as VarI1FromDate:qword
    extrn '__imp_VarI1FromDec' as VarI1FromDec:qword
    extrn '__imp_VarI1FromDisp' as VarI1FromDisp:qword
    extrn '__imp_VarI1FromI2' as VarI1FromI2:qword
    extrn '__imp_VarI1FromI4' as VarI1FromI4:qword
    extrn '__imp_VarI1FromI8' as VarI1FromI8:qword
    extrn '__imp_VarI1FromR4' as VarI1FromR4:qword
    extrn '__imp_VarI1FromR8' as VarI1FromR8:qword
    extrn '__imp_VarI1FromStr' as VarI1FromStr:qword
    extrn '__imp_VarI1FromUI1' as VarI1FromUI1:qword
    extrn '__imp_VarI1FromUI2' as VarI1FromUI2:qword
    extrn '__imp_VarI1FromUI4' as VarI1FromUI4:qword
    extrn '__imp_VarI1FromUI8' as VarI1FromUI8:qword
    extrn '__imp_VarI2FromBool' as VarI2FromBool:qword
    extrn '__imp_VarI2FromCy' as VarI2FromCy:qword
    extrn '__imp_VarI2FromDate' as VarI2FromDate:qword
    extrn '__imp_VarI2FromDec' as VarI2FromDec:qword
    extrn '__imp_VarI2FromDisp' as VarI2FromDisp:qword
    extrn '__imp_VarI2FromI1' as VarI2FromI1:qword
    extrn '__imp_VarI2FromI4' as VarI2FromI4:qword
    extrn '__imp_VarI2FromI8' as VarI2FromI8:qword
    extrn '__imp_VarI2FromR4' as VarI2FromR4:qword
    extrn '__imp_VarI2FromR8' as VarI2FromR8:qword
    extrn '__imp_VarI2FromStr' as VarI2FromStr:qword
    extrn '__imp_VarI2FromUI1' as VarI2FromUI1:qword
    extrn '__imp_VarI2FromUI2' as VarI2FromUI2:qword
    extrn '__imp_VarI2FromUI4' as VarI2FromUI4:qword
    extrn '__imp_VarI2FromUI8' as VarI2FromUI8:qword
    extrn '__imp_VarI4FromBool' as VarI4FromBool:qword
    extrn '__imp_VarI4FromCy' as VarI4FromCy:qword
    extrn '__imp_VarI4FromDate' as VarI4FromDate:qword
    extrn '__imp_VarI4FromDec' as VarI4FromDec:qword
    extrn '__imp_VarI4FromDisp' as VarI4FromDisp:qword
    extrn '__imp_VarI4FromI1' as VarI4FromI1:qword
    extrn '__imp_VarI4FromI2' as VarI4FromI2:qword
    extrn '__imp_VarI4FromI8' as VarI4FromI8:qword
    extrn '__imp_VarI4FromR4' as VarI4FromR4:qword
    extrn '__imp_VarI4FromR8' as VarI4FromR8:qword
    extrn '__imp_VarI4FromStr' as VarI4FromStr:qword
    extrn '__imp_VarI4FromUI1' as VarI4FromUI1:qword
    extrn '__imp_VarI4FromUI2' as VarI4FromUI2:qword
    extrn '__imp_VarI4FromUI4' as VarI4FromUI4:qword
    extrn '__imp_VarI4FromUI8' as VarI4FromUI8:qword
    extrn '__imp_VarI8FromBool' as VarI8FromBool:qword
    extrn '__imp_VarI8FromCy' as VarI8FromCy:qword
    extrn '__imp_VarI8FromDate' as VarI8FromDate:qword
    extrn '__imp_VarI8FromDec' as VarI8FromDec:qword
    extrn '__imp_VarI8FromDisp' as VarI8FromDisp:qword
    extrn '__imp_VarI8FromI1' as VarI8FromI1:qword
    extrn '__imp_VarI8FromI2' as VarI8FromI2:qword
    extrn '__imp_VarI8FromR4' as VarI8FromR4:qword
    extrn '__imp_VarI8FromR8' as VarI8FromR8:qword
    extrn '__imp_VarI8FromStr' as VarI8FromStr:qword
    extrn '__imp_VarI8FromUI1' as VarI8FromUI1:qword
    extrn '__imp_VarI8FromUI2' as VarI8FromUI2:qword
    extrn '__imp_VarI8FromUI4' as VarI8FromUI4:qword
    extrn '__imp_VarI8FromUI8' as VarI8FromUI8:qword
    extrn '__imp_VARIANT_UserFree' as VARIANT_UserFree:qword
    extrn '__imp_VARIANT_UserFree64' as VARIANT_UserFree64:qword
    extrn '__imp_VARIANT_UserMarshal' as VARIANT_UserMarshal:qword
    extrn '__imp_VARIANT_UserMarshal64' as VARIANT_UserMarshal64:qword
    extrn '__imp_VARIANT_UserSize' as VARIANT_UserSize:qword
    extrn '__imp_VARIANT_UserSize64' as VARIANT_UserSize64:qword
    extrn '__imp_VARIANT_UserUnmarshal' as VARIANT_UserUnmarshal:qword
    extrn '__imp_VARIANT_UserUnmarshal64' as VARIANT_UserUnmarshal64:qword
    extrn '__imp_VariantChangeType' as VariantChangeType:qword
    extrn '__imp_VariantChangeTypeEx' as VariantChangeTypeEx:qword
    extrn '__imp_VariantClear' as VariantClear:qword
    extrn '__imp_VariantCopy' as VariantCopy:qword
    extrn '__imp_VariantCopyInd' as VariantCopyInd:qword
    extrn '__imp_VariantInit' as VariantInit:qword
    extrn '__imp_VariantTimeToDosDateTime' as VariantTimeToDosDateTime:qword
    extrn '__imp_VariantTimeToSystemTime' as VariantTimeToSystemTime:qword
    extrn '__imp_VarIdiv' as VarIdiv:qword
    extrn '__imp_VarImp' as VarImp:qword
    extrn '__imp_VarInt' as VarInt:qword
    extrn '__imp_VarMod' as VarMod:qword
    extrn '__imp_VarMonthName' as VarMonthName:qword
    extrn '__imp_VarMul' as VarMul:qword
    extrn '__imp_VarNeg' as VarNeg:qword
    extrn '__imp_VarNot' as VarNot:qword
    extrn '__imp_VarNumFromParseNum' as VarNumFromParseNum:qword
    extrn '__imp_VarOr' as VarOr:qword
    extrn '__imp_VarParseNumFromStr' as VarParseNumFromStr:qword
    extrn '__imp_VarPow' as VarPow:qword
    extrn '__imp_VarR4CmpR8' as VarR4CmpR8:qword
    extrn '__imp_VarR4FromBool' as VarR4FromBool:qword
    extrn '__imp_VarR4FromCy' as VarR4FromCy:qword
    extrn '__imp_VarR4FromDate' as VarR4FromDate:qword
    extrn '__imp_VarR4FromDec' as VarR4FromDec:qword
    extrn '__imp_VarR4FromDisp' as VarR4FromDisp:qword
    extrn '__imp_VarR4FromI1' as VarR4FromI1:qword
    extrn '__imp_VarR4FromI2' as VarR4FromI2:qword
    extrn '__imp_VarR4FromI4' as VarR4FromI4:qword
    extrn '__imp_VarR4FromI8' as VarR4FromI8:qword
    extrn '__imp_VarR4FromR8' as VarR4FromR8:qword
    extrn '__imp_VarR4FromStr' as VarR4FromStr:qword
    extrn '__imp_VarR4FromUI1' as VarR4FromUI1:qword
    extrn '__imp_VarR4FromUI2' as VarR4FromUI2:qword
    extrn '__imp_VarR4FromUI4' as VarR4FromUI4:qword
    extrn '__imp_VarR4FromUI8' as VarR4FromUI8:qword
    extrn '__imp_VarR8FromBool' as VarR8FromBool:qword
    extrn '__imp_VarR8FromCy' as VarR8FromCy:qword
    extrn '__imp_VarR8FromDate' as VarR8FromDate:qword
    extrn '__imp_VarR8FromDec' as VarR8FromDec:qword
    extrn '__imp_VarR8FromDisp' as VarR8FromDisp:qword
    extrn '__imp_VarR8FromI1' as VarR8FromI1:qword
    extrn '__imp_VarR8FromI2' as VarR8FromI2:qword
    extrn '__imp_VarR8FromI4' as VarR8FromI4:qword
    extrn '__imp_VarR8FromI8' as VarR8FromI8:qword
    extrn '__imp_VarR8FromR4' as VarR8FromR4:qword
    extrn '__imp_VarR8FromStr' as VarR8FromStr:qword
    extrn '__imp_VarR8FromUI1' as VarR8FromUI1:qword
    extrn '__imp_VarR8FromUI2' as VarR8FromUI2:qword
    extrn '__imp_VarR8FromUI4' as VarR8FromUI4:qword
    extrn '__imp_VarR8FromUI8' as VarR8FromUI8:qword
    extrn '__imp_VarR8Pow' as VarR8Pow:qword
    extrn '__imp_VarR8Round' as VarR8Round:qword
    extrn '__imp_VarRound' as VarRound:qword
    extrn '__imp_VarSub' as VarSub:qword
    extrn '__imp_VarTokenizeFormatString' as VarTokenizeFormatString:qword
    extrn '__imp_VarUdateFromDate' as VarUdateFromDate:qword
    extrn '__imp_VarUI1FromBool' as VarUI1FromBool:qword
    extrn '__imp_VarUI1FromCy' as VarUI1FromCy:qword
    extrn '__imp_VarUI1FromDate' as VarUI1FromDate:qword
    extrn '__imp_VarUI1FromDec' as VarUI1FromDec:qword
    extrn '__imp_VarUI1FromDisp' as VarUI1FromDisp:qword
    extrn '__imp_VarUI1FromI1' as VarUI1FromI1:qword
    extrn '__imp_VarUI1FromI2' as VarUI1FromI2:qword
    extrn '__imp_VarUI1FromI4' as VarUI1FromI4:qword
    extrn '__imp_VarUI1FromI8' as VarUI1FromI8:qword
    extrn '__imp_VarUI1FromR4' as VarUI1FromR4:qword
    extrn '__imp_VarUI1FromR8' as VarUI1FromR8:qword
    extrn '__imp_VarUI1FromStr' as VarUI1FromStr:qword
    extrn '__imp_VarUI1FromUI2' as VarUI1FromUI2:qword
    extrn '__imp_VarUI1FromUI4' as VarUI1FromUI4:qword
    extrn '__imp_VarUI1FromUI8' as VarUI1FromUI8:qword
    extrn '__imp_VarUI2FromBool' as VarUI2FromBool:qword
    extrn '__imp_VarUI2FromCy' as VarUI2FromCy:qword
    extrn '__imp_VarUI2FromDate' as VarUI2FromDate:qword
    extrn '__imp_VarUI2FromDec' as VarUI2FromDec:qword
    extrn '__imp_VarUI2FromDisp' as VarUI2FromDisp:qword
    extrn '__imp_VarUI2FromI1' as VarUI2FromI1:qword
    extrn '__imp_VarUI2FromI2' as VarUI2FromI2:qword
    extrn '__imp_VarUI2FromI4' as VarUI2FromI4:qword
    extrn '__imp_VarUI2FromI8' as VarUI2FromI8:qword
    extrn '__imp_VarUI2FromR4' as VarUI2FromR4:qword
    extrn '__imp_VarUI2FromR8' as VarUI2FromR8:qword
    extrn '__imp_VarUI2FromStr' as VarUI2FromStr:qword
    extrn '__imp_VarUI2FromUI1' as VarUI2FromUI1:qword
    extrn '__imp_VarUI2FromUI4' as VarUI2FromUI4:qword
    extrn '__imp_VarUI2FromUI8' as VarUI2FromUI8:qword
    extrn '__imp_VarUI4FromBool' as VarUI4FromBool:qword
    extrn '__imp_VarUI4FromCy' as VarUI4FromCy:qword
    extrn '__imp_VarUI4FromDate' as VarUI4FromDate:qword
    extrn '__imp_VarUI4FromDec' as VarUI4FromDec:qword
    extrn '__imp_VarUI4FromDisp' as VarUI4FromDisp:qword
    extrn '__imp_VarUI4FromI1' as VarUI4FromI1:qword
    extrn '__imp_VarUI4FromI2' as VarUI4FromI2:qword
    extrn '__imp_VarUI4FromI4' as VarUI4FromI4:qword
    extrn '__imp_VarUI4FromI8' as VarUI4FromI8:qword
    extrn '__imp_VarUI4FromR4' as VarUI4FromR4:qword
    extrn '__imp_VarUI4FromR8' as VarUI4FromR8:qword
    extrn '__imp_VarUI4FromStr' as VarUI4FromStr:qword
    extrn '__imp_VarUI4FromUI1' as VarUI4FromUI1:qword
    extrn '__imp_VarUI4FromUI2' as VarUI4FromUI2:qword
    extrn '__imp_VarUI4FromUI8' as VarUI4FromUI8:qword
    extrn '__imp_VarUI8FromBool' as VarUI8FromBool:qword
    extrn '__imp_VarUI8FromCy' as VarUI8FromCy:qword
    extrn '__imp_VarUI8FromDate' as VarUI8FromDate:qword
    extrn '__imp_VarUI8FromDec' as VarUI8FromDec:qword
    extrn '__imp_VarUI8FromDisp' as VarUI8FromDisp:qword
    extrn '__imp_VarUI8FromI1' as VarUI8FromI1:qword
    extrn '__imp_VarUI8FromI2' as VarUI8FromI2:qword
    extrn '__imp_VarUI8FromI8' as VarUI8FromI8:qword
    extrn '__imp_VarUI8FromR4' as VarUI8FromR4:qword
    extrn '__imp_VarUI8FromR8' as VarUI8FromR8:qword
    extrn '__imp_VarUI8FromStr' as VarUI8FromStr:qword
    extrn '__imp_VarUI8FromUI1' as VarUI8FromUI1:qword
    extrn '__imp_VarUI8FromUI2' as VarUI8FromUI2:qword
    extrn '__imp_VarUI8FromUI4' as VarUI8FromUI4:qword
    extrn '__imp_VarWeekdayName' as VarWeekdayName:qword
    extrn '__imp_VarXor' as VarXor:qword
    extrn '__imp_VectorFromBstr' as VectorFromBstr:qword
else
    extrn '__imp__BSTR_UserFree@8' as BSTR_UserFree:dword
    ;extrn '__imp__BSTR_UserFree64@8' as BSTR_UserFree64:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__BSTR_UserMarshal@12' as BSTR_UserMarshal:dword
    ;extrn '__imp__BSTR_UserMarshal64@12' as BSTR_UserMarshal64:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__BSTR_UserSize@12' as BSTR_UserSize:dword
    ;extrn '__imp__BSTR_UserSize64@12' as BSTR_UserSize64:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__BSTR_UserUnmarshal@12' as BSTR_UserUnmarshal:dword
    ;extrn '__imp__BSTR_UserUnmarshal64@12' as BSTR_UserUnmarshal64:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__BstrFromVector@8' as BstrFromVector:dword
    extrn '__imp__ClearCustData@4' as ClearCustData:dword
    extrn '__imp__CreateDispTypeInfo@12' as CreateDispTypeInfo:dword
    extrn '__imp__CreateErrorInfo@4' as CreateErrorInfo:dword
    extrn '__imp__CreateStdDispatch@16' as CreateStdDispatch:dword
    extrn '__imp__CreateTypeLib@12' as CreateTypeLib:dword
    extrn '__imp__CreateTypeLib2@12' as CreateTypeLib2:dword
    extrn '__imp__DispCallFunc@32' as DispCallFunc:dword
    extrn '__imp__DispGetIDsOfNames@16' as DispGetIDsOfNames:dword
    extrn '__imp__DispGetParam@20' as DispGetParam:dword
    extrn '__imp__DispInvoke@32' as DispInvoke:dword
;    if ~defined __imp__DllCanUnloadNow
;        extrn '__imp__DllCanUnloadNow@0' as DllCanUnloadNow:dword ;Not present in MASM32 ol32.lib
;    end if
;    if ~defined __imp__DllRegisterServer
;        extrn '__imp__DllRegisterServer@0' as DllRegisterServer:dword ;Not present in MASM32 ol32.lib
;    end if
;    if ~defined __imp__DllUnregisterServer
;        extrn '__imp__DllUnregisterServer@0' as DllUnregisterServer:dword ;Not present in MASM32 ol32.lib
;    end if
    extrn '__imp__DosDateTimeToVariantTime@12' as DosDateTimeToVariantTime:dword
    extrn '__imp__GetActiveObject@12' as GetActiveObject:dword
    extrn '__imp__GetAltMonthNames@8' as GetAltMonthNames:dword
    extrn '__imp__GetErrorInfo@8' as GetErrorInfo:dword
    extrn '__imp__GetRecordInfoFromGuids@24' as GetRecordInfoFromGuids:dword
    extrn '__imp__GetRecordInfoFromTypeInfo@8' as GetRecordInfoFromTypeInfo:dword
    extrn '__imp__GetVarConversionLocaleSetting@4' as GetVarConversionLocaleSetting:dword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__HWND_UserFree@8' as HWND_UserFree:dword
        extrn '__imp__HWND_UserFree64@8' as HWND_UserFree64:dword
        extrn '__imp__HWND_UserMarshal@12' as HWND_UserMarshal:dword
        extrn '__imp__HWND_UserMarshal64@12' as HWND_UserMarshal64:dword
        extrn '__imp__HWND_UserSize@12' as HWND_UserSize:dword
        extrn '__imp__HWND_UserSize64@12' as HWND_UserSize64:dword
        extrn '__imp__HWND_UserUnmarshal@12' as HWND_UserUnmarshal:dword
        extrn '__imp__HWND_UserUnmarshal64@12' as HWND_UserUnmarshal64:dword
    end if
    ;extrn '__imp__LHashValOfNameSys@12' as LHashValOfNameSys:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__LHashValOfNameSysA@12' as LHashValOfNameSysA:dword
    extrn '__imp__LoadRegTypeLib@20' as LoadRegTypeLib:dword
    extrn '__imp__LoadTypeLib@8' as LoadTypeLib:dword
    extrn '__imp__LoadTypeLibEx@12' as LoadTypeLibEx:dword
    extrn '__imp__LPSAFEARRAY_Marshal@16' as LPSAFEARRAY_Marshal:dword
    extrn '__imp__LPSAFEARRAY_Size@16' as LPSAFEARRAY_Size:dword
    extrn '__imp__LPSAFEARRAY_Unmarshal@16' as LPSAFEARRAY_Unmarshal:dword
    extrn '__imp__LPSAFEARRAY_UserFree@8' as LPSAFEARRAY_UserFree:dword
    ;extrn '__imp__LPSAFEARRAY_UserFree64@8' as LPSAFEARRAY_UserFree64:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__LPSAFEARRAY_UserMarshal@12' as LPSAFEARRAY_UserMarshal:dword
    ;extrn '__imp__LPSAFEARRAY_UserMarshal64@12' as LPSAFEARRAY_UserMarshal64:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__LPSAFEARRAY_UserSize@12' as LPSAFEARRAY_UserSize:dword
    ;extrn '__imp__LPSAFEARRAY_UserSize64@12' as LPSAFEARRAY_UserSize64:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__LPSAFEARRAY_UserUnmarshal@12' as LPSAFEARRAY_UserUnmarshal:dword
    ;extrn '__imp__LPSAFEARRAY_UserUnmarshal64@12' as LPSAFEARRAY_UserUnmarshal64:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__OaBuildVersion@0' as OaBuildVersion:dword
    extrn '__imp__OACreateTypeLib2@12' as OACreateTypeLib2:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__OaEnablePerUserTLibRegistration@0' as OaEnablePerUserTLibRegistration:dword
    end if
    extrn '__imp__OleCreateFontIndirect@12' as OleCreateFontIndirect:dword
    extrn '__imp__OleCreatePictureIndirect@16' as OleCreatePictureIndirect:dword
    extrn '__imp__OleCreatePropertyFrame@44' as OleCreatePropertyFrame:dword
    extrn '__imp__OleCreatePropertyFrameIndirect@4' as OleCreatePropertyFrameIndirect:dword
    extrn '__imp__OleIconToCursor@8' as OleIconToCursor:dword
    extrn '__imp__OleLoadPicture@20' as OleLoadPicture:dword
    extrn '__imp__OleLoadPictureEx@32' as OleLoadPictureEx:dword
    extrn '__imp__OleLoadPictureFile@20' as OleLoadPictureFile:dword
    extrn '__imp__OleLoadPictureFileEx@32' as OleLoadPictureFileEx:dword
    extrn '__imp__OleLoadPicturePath@24' as OleLoadPicturePath:dword
    extrn '__imp__OleSavePictureFile@8' as OleSavePictureFile:dword
    extrn '__imp__OleTranslateColor@12' as OleTranslateColor:dword
    extrn '__imp__QueryPathOfRegTypeLib@20' as QueryPathOfRegTypeLib:dword
    extrn '__imp__RegisterActiveObject@16' as RegisterActiveObject:dword
    extrn '__imp__RegisterTypeLib@12' as RegisterTypeLib:dword
    extrn '__imp__RegisterTypeLibForUser@12' as RegisterTypeLibForUser:dword
    extrn '__imp__RevokeActiveObject@8' as RevokeActiveObject:dword
    extrn '__imp__SafeArrayAccessData@8' as SafeArrayAccessData:dword
    extrn '__imp__SafeArrayAllocData@4' as SafeArrayAllocData:dword
    extrn '__imp__SafeArrayAllocDescriptor@8' as SafeArrayAllocDescriptor:dword
    extrn '__imp__SafeArrayAllocDescriptorEx@12' as SafeArrayAllocDescriptorEx:dword
    extrn '__imp__SafeArrayCopy@8' as SafeArrayCopy:dword
    extrn '__imp__SafeArrayCopyData@8' as SafeArrayCopyData:dword
    extrn '__imp__SafeArrayCreate@12' as SafeArrayCreate:dword
    extrn '__imp__SafeArrayCreateEx@16' as SafeArrayCreateEx:dword
    extrn '__imp__SafeArrayCreateVector@12' as SafeArrayCreateVector:dword
    extrn '__imp__SafeArrayCreateVectorEx@16' as SafeArrayCreateVectorEx:dword
    extrn '__imp__SafeArrayDestroy@4' as SafeArrayDestroy:dword
    extrn '__imp__SafeArrayDestroyData@4' as SafeArrayDestroyData:dword
    extrn '__imp__SafeArrayDestroyDescriptor@4' as SafeArrayDestroyDescriptor:dword
    extrn '__imp__SafeArrayGetDim@4' as SafeArrayGetDim:dword
    extrn '__imp__SafeArrayGetElement@12' as SafeArrayGetElement:dword
    extrn '__imp__SafeArrayGetElemsize@4' as SafeArrayGetElemsize:dword
    extrn '__imp__SafeArrayGetIID@8' as SafeArrayGetIID:dword
    extrn '__imp__SafeArrayGetLBound@12' as SafeArrayGetLBound:dword
    extrn '__imp__SafeArrayGetRecordInfo@8' as SafeArrayGetRecordInfo:dword
    extrn '__imp__SafeArrayGetUBound@12' as SafeArrayGetUBound:dword
    extrn '__imp__SafeArrayGetVartype@8' as SafeArrayGetVartype:dword
    extrn '__imp__SafeArrayLock@4' as SafeArrayLock:dword
    extrn '__imp__SafeArrayPtrOfIndex@12' as SafeArrayPtrOfIndex:dword
    extrn '__imp__SafeArrayPutElement@12' as SafeArrayPutElement:dword
    extrn '__imp__SafeArrayRedim@8' as SafeArrayRedim:dword
    extrn '__imp__SafeArraySetIID@8' as SafeArraySetIID:dword
    extrn '__imp__SafeArraySetRecordInfo@8' as SafeArraySetRecordInfo:dword
    extrn '__imp__SafeArrayUnaccessData@4' as SafeArrayUnaccessData:dword
    extrn '__imp__SafeArrayUnlock@4' as SafeArrayUnlock:dword
    extrn '__imp__SetErrorInfo@8' as SetErrorInfo:dword
    ;extrn '__imp__SetOaNoCache@4' as SetOaNoCache:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__SetVarConversionLocaleSetting@4' as SetVarConversionLocaleSetting:dword
    extrn '__imp__SysAllocString@4' as SysAllocString:dword
    extrn '__imp__SysAllocStringByteLen@8' as SysAllocStringByteLen:dword
    extrn '__imp__SysAllocStringLen@8' as SysAllocStringLen:dword
    extrn '__imp__SysFreeString@4' as SysFreeString:dword
    extrn '__imp__SysReAllocString@8' as SysReAllocString:dword
    extrn '__imp__SysReAllocStringLen@12' as SysReAllocStringLen:dword
    extrn '__imp__SysStringByteLen@4' as SysStringByteLen:dword
    extrn '__imp__SysStringLen@4' as SysStringLen:dword
    extrn '__imp__SystemTimeToVariantTime@8' as SystemTimeToVariantTime:dword
    extrn '__imp__UnRegisterTypeLib@20' as UnRegisterTypeLib:dword
    extrn '__imp__UnRegisterTypeLibForUser@20' as UnRegisterTypeLibForUser:dword
    extrn '__imp__VarAbs@8' as VarAbs:dword
    extrn '__imp__VarAdd@12' as VarAdd:dword
    extrn '__imp__VarAnd@12' as VarAnd:dword
    extrn '__imp__VarBoolFromCy@12' as VarBoolFromCy:dword
    extrn '__imp__VarBoolFromDate@12' as VarBoolFromDate:dword
    extrn '__imp__VarBoolFromDec@8' as VarBoolFromDec:dword
    extrn '__imp__VarBoolFromDisp@12' as VarBoolFromDisp:dword
    extrn '__imp__VarBoolFromI1@8' as VarBoolFromI1:dword
    extrn '__imp__VarBoolFromI2@8' as VarBoolFromI2:dword
    extrn '__imp__VarBoolFromI4@8' as VarBoolFromI4:dword
    extrn '__imp__VarBoolFromI8@12' as VarBoolFromI8:dword
    extrn '__imp__VarBoolFromR4@8' as VarBoolFromR4:dword
    extrn '__imp__VarBoolFromR8@12' as VarBoolFromR8:dword
    extrn '__imp__VarBoolFromStr@16' as VarBoolFromStr:dword
    extrn '__imp__VarBoolFromUI1@8' as VarBoolFromUI1:dword
    extrn '__imp__VarBoolFromUI2@8' as VarBoolFromUI2:dword
    extrn '__imp__VarBoolFromUI4@8' as VarBoolFromUI4:dword
    extrn '__imp__VarBoolFromUI8@12' as VarBoolFromUI8:dword
    extrn '__imp__VarBstrCat@12' as VarBstrCat:dword
    extrn '__imp__VarBstrCmp@16' as VarBstrCmp:dword
    extrn '__imp__VarBstrFromBool@16' as VarBstrFromBool:dword
    extrn '__imp__VarBstrFromCy@20' as VarBstrFromCy:dword
    extrn '__imp__VarBstrFromDate@20' as VarBstrFromDate:dword
    extrn '__imp__VarBstrFromDec@16' as VarBstrFromDec:dword
    extrn '__imp__VarBstrFromDisp@16' as VarBstrFromDisp:dword
    extrn '__imp__VarBstrFromI1@16' as VarBstrFromI1:dword
    extrn '__imp__VarBstrFromI2@16' as VarBstrFromI2:dword
    extrn '__imp__VarBstrFromI4@16' as VarBstrFromI4:dword
    extrn '__imp__VarBstrFromI8@20' as VarBstrFromI8:dword
    extrn '__imp__VarBstrFromR4@16' as VarBstrFromR4:dword
    extrn '__imp__VarBstrFromR8@20' as VarBstrFromR8:dword
    extrn '__imp__VarBstrFromUI1@16' as VarBstrFromUI1:dword
    extrn '__imp__VarBstrFromUI2@16' as VarBstrFromUI2:dword
    extrn '__imp__VarBstrFromUI4@16' as VarBstrFromUI4:dword
    extrn '__imp__VarBstrFromUI8@20' as VarBstrFromUI8:dword
    extrn '__imp__VarCat@12' as VarCat:dword
    extrn '__imp__VarCmp@16' as VarCmp:dword
    extrn '__imp__VarCyAbs@12' as VarCyAbs:dword
    extrn '__imp__VarCyAdd@20' as VarCyAdd:dword
    extrn '__imp__VarCyCmp@16' as VarCyCmp:dword
    extrn '__imp__VarCyCmpR8@16' as VarCyCmpR8:dword
    extrn '__imp__VarCyFix@12' as VarCyFix:dword
    extrn '__imp__VarCyFromBool@8' as VarCyFromBool:dword
    extrn '__imp__VarCyFromDate@12' as VarCyFromDate:dword
    extrn '__imp__VarCyFromDec@8' as VarCyFromDec:dword
    extrn '__imp__VarCyFromDisp@12' as VarCyFromDisp:dword
    extrn '__imp__VarCyFromI1@8' as VarCyFromI1:dword
    extrn '__imp__VarCyFromI2@8' as VarCyFromI2:dword
    extrn '__imp__VarCyFromI4@8' as VarCyFromI4:dword
    extrn '__imp__VarCyFromI8@12' as VarCyFromI8:dword
    extrn '__imp__VarCyFromR4@8' as VarCyFromR4:dword
    extrn '__imp__VarCyFromR8@12' as VarCyFromR8:dword
    extrn '__imp__VarCyFromStr@16' as VarCyFromStr:dword
    extrn '__imp__VarCyFromUI1@8' as VarCyFromUI1:dword
    extrn '__imp__VarCyFromUI2@8' as VarCyFromUI2:dword
    extrn '__imp__VarCyFromUI4@8' as VarCyFromUI4:dword
    extrn '__imp__VarCyFromUI8@12' as VarCyFromUI8:dword
    extrn '__imp__VarCyInt@12' as VarCyInt:dword
    extrn '__imp__VarCyMul@20' as VarCyMul:dword
    extrn '__imp__VarCyMulI4@16' as VarCyMulI4:dword
    extrn '__imp__VarCyMulI8@20' as VarCyMulI8:dword
    extrn '__imp__VarCyNeg@12' as VarCyNeg:dword
    extrn '__imp__VarCyRound@16' as VarCyRound:dword
    extrn '__imp__VarCySub@20' as VarCySub:dword
    extrn '__imp__VarDateFromBool@8' as VarDateFromBool:dword
    extrn '__imp__VarDateFromCy@12' as VarDateFromCy:dword
    extrn '__imp__VarDateFromDec@8' as VarDateFromDec:dword
    extrn '__imp__VarDateFromDisp@12' as VarDateFromDisp:dword
    extrn '__imp__VarDateFromI1@8' as VarDateFromI1:dword
    extrn '__imp__VarDateFromI2@8' as VarDateFromI2:dword
    extrn '__imp__VarDateFromI4@8' as VarDateFromI4:dword
    extrn '__imp__VarDateFromI8@12' as VarDateFromI8:dword
    extrn '__imp__VarDateFromR4@8' as VarDateFromR4:dword
    extrn '__imp__VarDateFromR8@12' as VarDateFromR8:dword
    extrn '__imp__VarDateFromStr@16' as VarDateFromStr:dword
    extrn '__imp__VarDateFromUI1@8' as VarDateFromUI1:dword
    extrn '__imp__VarDateFromUI2@8' as VarDateFromUI2:dword
    extrn '__imp__VarDateFromUI4@8' as VarDateFromUI4:dword
    extrn '__imp__VarDateFromUI8@12' as VarDateFromUI8:dword
    extrn '__imp__VarDateFromUdate@12' as VarDateFromUdate:dword
    extrn '__imp__VarDateFromUdateEx@16' as VarDateFromUdateEx:dword
    extrn '__imp__VarDecAbs@8' as VarDecAbs:dword
    extrn '__imp__VarDecAdd@12' as VarDecAdd:dword
    extrn '__imp__VarDecCmp@8' as VarDecCmp:dword
    extrn '__imp__VarDecCmpR8@12' as VarDecCmpR8:dword
    extrn '__imp__VarDecDiv@12' as VarDecDiv:dword
    extrn '__imp__VarDecFix@8' as VarDecFix:dword
    extrn '__imp__VarDecFromBool@8' as VarDecFromBool:dword
    extrn '__imp__VarDecFromCy@12' as VarDecFromCy:dword
    extrn '__imp__VarDecFromDate@12' as VarDecFromDate:dword
    extrn '__imp__VarDecFromDisp@12' as VarDecFromDisp:dword
    extrn '__imp__VarDecFromI1@8' as VarDecFromI1:dword
    extrn '__imp__VarDecFromI2@8' as VarDecFromI2:dword
    extrn '__imp__VarDecFromI4@8' as VarDecFromI4:dword
    extrn '__imp__VarDecFromI8@12' as VarDecFromI8:dword
    extrn '__imp__VarDecFromR4@8' as VarDecFromR4:dword
    extrn '__imp__VarDecFromR8@12' as VarDecFromR8:dword
    extrn '__imp__VarDecFromStr@16' as VarDecFromStr:dword
    extrn '__imp__VarDecFromUI1@8' as VarDecFromUI1:dword
    extrn '__imp__VarDecFromUI2@8' as VarDecFromUI2:dword
    extrn '__imp__VarDecFromUI4@8' as VarDecFromUI4:dword
    extrn '__imp__VarDecFromUI8@12' as VarDecFromUI8:dword
    extrn '__imp__VarDecInt@8' as VarDecInt:dword
    extrn '__imp__VarDecMul@12' as VarDecMul:dword
    extrn '__imp__VarDecNeg@8' as VarDecNeg:dword
    extrn '__imp__VarDecRound@12' as VarDecRound:dword
    extrn '__imp__VarDecSub@12' as VarDecSub:dword
    extrn '__imp__VarDiv@12' as VarDiv:dword
    extrn '__imp__VarEqv@12' as VarEqv:dword
    extrn '__imp__VarFix@8' as VarFix:dword
    extrn '__imp__VarFormat@24' as VarFormat:dword
    extrn '__imp__VarFormatCurrency@28' as VarFormatCurrency:dword
    extrn '__imp__VarFormatDateTime@16' as VarFormatDateTime:dword
    extrn '__imp__VarFormatFromTokens@24' as VarFormatFromTokens:dword
    extrn '__imp__VarFormatNumber@28' as VarFormatNumber:dword
    extrn '__imp__VarFormatPercent@28' as VarFormatPercent:dword
    extrn '__imp__VarI1FromBool@8' as VarI1FromBool:dword
    extrn '__imp__VarI1FromCy@12' as VarI1FromCy:dword
    extrn '__imp__VarI1FromDate@12' as VarI1FromDate:dword
    extrn '__imp__VarI1FromDec@8' as VarI1FromDec:dword
    extrn '__imp__VarI1FromDisp@12' as VarI1FromDisp:dword
    extrn '__imp__VarI1FromI2@8' as VarI1FromI2:dword
    extrn '__imp__VarI1FromI4@8' as VarI1FromI4:dword
    extrn '__imp__VarI1FromI8@12' as VarI1FromI8:dword
    extrn '__imp__VarI1FromR4@8' as VarI1FromR4:dword
    extrn '__imp__VarI1FromR8@12' as VarI1FromR8:dword
    extrn '__imp__VarI1FromStr@16' as VarI1FromStr:dword
    extrn '__imp__VarI1FromUI1@8' as VarI1FromUI1:dword
    extrn '__imp__VarI1FromUI2@8' as VarI1FromUI2:dword
    extrn '__imp__VarI1FromUI4@8' as VarI1FromUI4:dword
    extrn '__imp__VarI1FromUI8@12' as VarI1FromUI8:dword
    extrn '__imp__VarI2FromBool@8' as VarI2FromBool:dword
    extrn '__imp__VarI2FromCy@12' as VarI2FromCy:dword
    extrn '__imp__VarI2FromDate@12' as VarI2FromDate:dword
    extrn '__imp__VarI2FromDec@8' as VarI2FromDec:dword
    extrn '__imp__VarI2FromDisp@12' as VarI2FromDisp:dword
    extrn '__imp__VarI2FromI1@8' as VarI2FromI1:dword
    extrn '__imp__VarI2FromI4@8' as VarI2FromI4:dword
    extrn '__imp__VarI2FromI8@12' as VarI2FromI8:dword
    extrn '__imp__VarI2FromR4@8' as VarI2FromR4:dword
    extrn '__imp__VarI2FromR8@12' as VarI2FromR8:dword
    extrn '__imp__VarI2FromStr@16' as VarI2FromStr:dword
    extrn '__imp__VarI2FromUI1@8' as VarI2FromUI1:dword
    extrn '__imp__VarI2FromUI2@8' as VarI2FromUI2:dword
    extrn '__imp__VarI2FromUI4@8' as VarI2FromUI4:dword
    extrn '__imp__VarI2FromUI8@12' as VarI2FromUI8:dword
    extrn '__imp__VarI4FromBool@8' as VarI4FromBool:dword
    extrn '__imp__VarI4FromCy@12' as VarI4FromCy:dword
    extrn '__imp__VarI4FromDate@12' as VarI4FromDate:dword
    extrn '__imp__VarI4FromDec@8' as VarI4FromDec:dword
    extrn '__imp__VarI4FromDisp@12' as VarI4FromDisp:dword
    extrn '__imp__VarI4FromI1@8' as VarI4FromI1:dword
    extrn '__imp__VarI4FromI2@8' as VarI4FromI2:dword
    extrn '__imp__VarI4FromI8@12' as VarI4FromI8:dword
    extrn '__imp__VarI4FromR4@8' as VarI4FromR4:dword
    extrn '__imp__VarI4FromR8@12' as VarI4FromR8:dword
    extrn '__imp__VarI4FromStr@16' as VarI4FromStr:dword
    extrn '__imp__VarI4FromUI1@8' as VarI4FromUI1:dword
    extrn '__imp__VarI4FromUI2@8' as VarI4FromUI2:dword
    extrn '__imp__VarI4FromUI4@8' as VarI4FromUI4:dword
    extrn '__imp__VarI4FromUI8@12' as VarI4FromUI8:dword
    extrn '__imp__VarI8FromBool@8' as VarI8FromBool:dword
    extrn '__imp__VarI8FromCy@12' as VarI8FromCy:dword
    extrn '__imp__VarI8FromDate@12' as VarI8FromDate:dword
    extrn '__imp__VarI8FromDec@8' as VarI8FromDec:dword
    extrn '__imp__VarI8FromDisp@12' as VarI8FromDisp:dword
    extrn '__imp__VarI8FromI1@8' as VarI8FromI1:dword
    extrn '__imp__VarI8FromI2@8' as VarI8FromI2:dword
    extrn '__imp__VarI8FromR4@8' as VarI8FromR4:dword
    extrn '__imp__VarI8FromR8@12' as VarI8FromR8:dword
    extrn '__imp__VarI8FromStr@16' as VarI8FromStr:dword
    extrn '__imp__VarI8FromUI1@8' as VarI8FromUI1:dword
    extrn '__imp__VarI8FromUI2@8' as VarI8FromUI2:dword
    extrn '__imp__VarI8FromUI4@8' as VarI8FromUI4:dword
    extrn '__imp__VarI8FromUI8@12' as VarI8FromUI8:dword
    extrn '__imp__VARIANT_UserFree@8' as VARIANT_UserFree:dword
    ;extrn '__imp__VARIANT_UserFree64@8' as VARIANT_UserFree64:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__VARIANT_UserMarshal@12' as VARIANT_UserMarshal:dword
    ;extrn '__imp__VARIANT_UserMarshal64@12' as VARIANT_UserMarshal64:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__VARIANT_UserSize@12' as VARIANT_UserSize:dword
    ;extrn '__imp__VARIANT_UserSize64@12' as VARIANT_UserSize64:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__VARIANT_UserUnmarshal@12' as VARIANT_UserUnmarshal:dword
    ;extrn '__imp__VARIANT_UserUnmarshal64@12' as VARIANT_UserUnmarshal64:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__VariantChangeType@16' as VariantChangeType:dword
    extrn '__imp__VariantChangeTypeEx@20' as VariantChangeTypeEx:dword
    extrn '__imp__VariantClear@4' as VariantClear:dword
    extrn '__imp__VariantCopy@8' as VariantCopy:dword
    extrn '__imp__VariantCopyInd@8' as VariantCopyInd:dword
    extrn '__imp__VariantInit@4' as VariantInit:dword
    extrn '__imp__VariantTimeToDosDateTime@16' as VariantTimeToDosDateTime:dword
    ;extrn '__imp__VariantTimeToSystemTime@8' as VariantTimeToSystemTime:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__VarIdiv@12' as VarIdiv:dword
    extrn '__imp__VarImp@12' as VarImp:dword
    extrn '__imp__VarInt@8' as VarInt:dword
    extrn '__imp__VarMod@12' as VarMod:dword
    extrn '__imp__VarMonthName@16' as VarMonthName:dword
    extrn '__imp__VarMul@12' as VarMul:dword
    extrn '__imp__VarNeg@8' as VarNeg:dword
    extrn '__imp__VarNot@8' as VarNot:dword
    extrn '__imp__VarNumFromParseNum@16' as VarNumFromParseNum:dword
    extrn '__imp__VarOr@12' as VarOr:dword
    extrn '__imp__VarParseNumFromStr@20' as VarParseNumFromStr:dword
    extrn '__imp__VarPow@12' as VarPow:dword
    extrn '__imp__VarR4CmpR8@12' as VarR4CmpR8:dword
    extrn '__imp__VarR4FromBool@8' as VarR4FromBool:dword
    extrn '__imp__VarR4FromCy@12' as VarR4FromCy:dword
    extrn '__imp__VarR4FromDate@12' as VarR4FromDate:dword
    extrn '__imp__VarR4FromDec@8' as VarR4FromDec:dword
    extrn '__imp__VarR4FromDisp@12' as VarR4FromDisp:dword
    extrn '__imp__VarR4FromI1@8' as VarR4FromI1:dword
    extrn '__imp__VarR4FromI2@8' as VarR4FromI2:dword
    extrn '__imp__VarR4FromI4@8' as VarR4FromI4:dword
    extrn '__imp__VarR4FromI8@12' as VarR4FromI8:dword
    extrn '__imp__VarR4FromR8@12' as VarR4FromR8:dword
    extrn '__imp__VarR4FromStr@16' as VarR4FromStr:dword
    extrn '__imp__VarR4FromUI1@8' as VarR4FromUI1:dword
    extrn '__imp__VarR4FromUI2@8' as VarR4FromUI2:dword
    extrn '__imp__VarR4FromUI4@8' as VarR4FromUI4:dword
    extrn '__imp__VarR4FromUI8@12' as VarR4FromUI8:dword
    extrn '__imp__VarR8FromBool@8' as VarR8FromBool:dword
    extrn '__imp__VarR8FromCy@12' as VarR8FromCy:dword
    extrn '__imp__VarR8FromDate@12' as VarR8FromDate:dword
    extrn '__imp__VarR8FromDec@8' as VarR8FromDec:dword
    extrn '__imp__VarR8FromDisp@12' as VarR8FromDisp:dword
    extrn '__imp__VarR8FromI1@8' as VarR8FromI1:dword
    extrn '__imp__VarR8FromI2@8' as VarR8FromI2:dword
    extrn '__imp__VarR8FromI4@8' as VarR8FromI4:dword
    extrn '__imp__VarR8FromI8@12' as VarR8FromI8:dword
    extrn '__imp__VarR8FromR4@8' as VarR8FromR4:dword
    extrn '__imp__VarR8FromStr@16' as VarR8FromStr:dword
    extrn '__imp__VarR8FromUI1@8' as VarR8FromUI1:dword
    extrn '__imp__VarR8FromUI2@8' as VarR8FromUI2:dword
    extrn '__imp__VarR8FromUI4@8' as VarR8FromUI4:dword
    extrn '__imp__VarR8FromUI8@12' as VarR8FromUI8:dword
    extrn '__imp__VarR8Pow@20' as VarR8Pow:dword
    extrn '__imp__VarR8Round@16' as VarR8Round:dword
    extrn '__imp__VarRound@12' as VarRound:dword
    extrn '__imp__VarSub@12' as VarSub:dword
    extrn '__imp__VarTokenizeFormatString@28' as VarTokenizeFormatString:dword
    extrn '__imp__VarUdateFromDate@16' as VarUdateFromDate:dword
    extrn '__imp__VarUI1FromBool@8' as VarUI1FromBool:dword
    extrn '__imp__VarUI1FromCy@12' as VarUI1FromCy:dword
    extrn '__imp__VarUI1FromDate@12' as VarUI1FromDate:dword
    extrn '__imp__VarUI1FromDec@8' as VarUI1FromDec:dword
    extrn '__imp__VarUI1FromDisp@12' as VarUI1FromDisp:dword
    extrn '__imp__VarUI1FromI1@8' as VarUI1FromI1:dword
    extrn '__imp__VarUI1FromI2@8' as VarUI1FromI2:dword
    extrn '__imp__VarUI1FromI4@8' as VarUI1FromI4:dword
    extrn '__imp__VarUI1FromI8@12' as VarUI1FromI8:dword
    extrn '__imp__VarUI1FromR4@8' as VarUI1FromR4:dword
    extrn '__imp__VarUI1FromR8@12' as VarUI1FromR8:dword
    extrn '__imp__VarUI1FromStr@16' as VarUI1FromStr:dword
    extrn '__imp__VarUI1FromUI2@8' as VarUI1FromUI2:dword
    extrn '__imp__VarUI1FromUI4@8' as VarUI1FromUI4:dword
    extrn '__imp__VarUI1FromUI8@12' as VarUI1FromUI8:dword
    extrn '__imp__VarUI2FromBool@8' as VarUI2FromBool:dword
    extrn '__imp__VarUI2FromCy@12' as VarUI2FromCy:dword
    extrn '__imp__VarUI2FromDate@12' as VarUI2FromDate:dword
    extrn '__imp__VarUI2FromDec@8' as VarUI2FromDec:dword
    extrn '__imp__VarUI2FromDisp@12' as VarUI2FromDisp:dword
    extrn '__imp__VarUI2FromI1@8' as VarUI2FromI1:dword
    extrn '__imp__VarUI2FromI2@8' as VarUI2FromI2:dword
    extrn '__imp__VarUI2FromI4@8' as VarUI2FromI4:dword
    extrn '__imp__VarUI2FromI8@12' as VarUI2FromI8:dword
    extrn '__imp__VarUI2FromR4@8' as VarUI2FromR4:dword
    extrn '__imp__VarUI2FromR8@12' as VarUI2FromR8:dword
    extrn '__imp__VarUI2FromStr@16' as VarUI2FromStr:dword
    extrn '__imp__VarUI2FromUI1@8' as VarUI2FromUI1:dword
    extrn '__imp__VarUI2FromUI4@8' as VarUI2FromUI4:dword
    extrn '__imp__VarUI2FromUI8@12' as VarUI2FromUI8:dword
    extrn '__imp__VarUI4FromBool@8' as VarUI4FromBool:dword
    extrn '__imp__VarUI4FromCy@12' as VarUI4FromCy:dword
    extrn '__imp__VarUI4FromDate@12' as VarUI4FromDate:dword
    extrn '__imp__VarUI4FromDec@8' as VarUI4FromDec:dword
    extrn '__imp__VarUI4FromDisp@12' as VarUI4FromDisp:dword
    extrn '__imp__VarUI4FromI1@8' as VarUI4FromI1:dword
    extrn '__imp__VarUI4FromI2@8' as VarUI4FromI2:dword
    extrn '__imp__VarUI4FromI4@8' as VarUI4FromI4:dword
    extrn '__imp__VarUI4FromI8@12' as VarUI4FromI8:dword
    extrn '__imp__VarUI4FromR4@8' as VarUI4FromR4:dword
    extrn '__imp__VarUI4FromR8@12' as VarUI4FromR8:dword
    extrn '__imp__VarUI4FromStr@16' as VarUI4FromStr:dword
    extrn '__imp__VarUI4FromUI1@8' as VarUI4FromUI1:dword
    extrn '__imp__VarUI4FromUI2@8' as VarUI4FromUI2:dword
    extrn '__imp__VarUI4FromUI8@12' as VarUI4FromUI8:dword
    extrn '__imp__VarUI8FromBool@8' as VarUI8FromBool:dword
    extrn '__imp__VarUI8FromCy@12' as VarUI8FromCy:dword
    extrn '__imp__VarUI8FromDate@12' as VarUI8FromDate:dword
    extrn '__imp__VarUI8FromDec@8' as VarUI8FromDec:dword
    extrn '__imp__VarUI8FromDisp@12' as VarUI8FromDisp:dword
    extrn '__imp__VarUI8FromI1@8' as VarUI8FromI1:dword
    extrn '__imp__VarUI8FromI2@8' as VarUI8FromI2:dword
    extrn '__imp__VarUI8FromI8@12' as VarUI8FromI8:dword
    extrn '__imp__VarUI8FromR4@8' as VarUI8FromR4:dword
    extrn '__imp__VarUI8FromR8@12' as VarUI8FromR8:dword
    extrn '__imp__VarUI8FromStr@16' as VarUI8FromStr:dword
    extrn '__imp__VarUI8FromUI1@8' as VarUI8FromUI1:dword
    extrn '__imp__VarUI8FromUI2@8' as VarUI8FromUI2:dword
    extrn '__imp__VarUI8FromUI4@8' as VarUI8FromUI4:dword
    extrn '__imp__VarWeekdayName@20' as VarWeekdayName:dword
    extrn '__imp__VarXor@12' as VarXor:dword
    extrn '__imp__VectorFromBstr@8' as VectorFromBstr:dword
end if


;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
;    extrn '__imp_OACleanup' as OACleanup:qword
;else
;    extrn '__imp__OACleanup@??' as OACleanup:dword
;end if

end if ;OLEAUT32_INC
