; ====================================================;
;                                                     ;
;    oleaut32.inc for EC v2 Fasm classic projects     ;
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
    import oleaut32,\
    BSTR_UserFree,'BSTR_UserFree',\
    BSTR_UserFree64,'BSTR_UserFree64',\
    BSTR_UserMarshal,'BSTR_UserMarshal',\
    BSTR_UserMarshal64,'BSTR_UserMarshal64',\
    BSTR_UserSize,'BSTR_UserSize',\
    BSTR_UserSize64,'BSTR_UserSize64',\
    BSTR_UserUnmarshal,'BSTR_UserUnmarshal',\
    BSTR_UserUnmarshal64,'BSTR_UserUnmarshal64',\
    BstrFromVector,'BstrFromVector',\
    ClearCustData,'ClearCustData',\
    CreateDispTypeInfo,'CreateDispTypeInfo',\
    CreateErrorInfo,'CreateErrorInfo',\
    CreateStdDispatch,'CreateStdDispatch',\
    CreateTypeLib,'CreateTypeLib',\
    CreateTypeLib2,'CreateTypeLib2',\
    DispCallFunc,'DispCallFunc',\
    DispGetIDsOfNames,'DispGetIDsOfNames',\
    DispGetParam,'DispGetParam',\
    DispInvoke,'DispInvoke',\
    DllCanUnloadNow,'DllCanUnloadNow',\
    DllRegisterServer,'DllRegisterServer',\
    DllUnregisterServer,'DllUnregisterServer',\
    DosDateTimeToVariantTime,'DosDateTimeToVariantTime',\
    GetActiveObject,'GetActiveObject',\
    GetAltMonthNames,'GetAltMonthNames',\
    GetErrorInfo,'GetErrorInfo',\
    GetRecordInfoFromGuids,'GetRecordInfoFromGuids',\
    GetRecordInfoFromTypeInfo,'GetRecordInfoFromTypeInfo',\
    GetVarConversionLocaleSetting,'GetVarConversionLocaleSetting',\
    HWND_UserFree,'HWND_UserFree',\
    HWND_UserFree64,'HWND_UserFree64',\
    HWND_UserMarshal,'HWND_UserMarshal',\
    HWND_UserMarshal64,'HWND_UserMarshal64',\
    HWND_UserSize,'HWND_UserSize',\
    HWND_UserSize64,'HWND_UserSize64',\
    HWND_UserUnmarshal,'HWND_UserUnmarshal',\
    HWND_UserUnmarshal64,'HWND_UserUnmarshal64',\
    LHashValOfNameSys,'LHashValOfNameSys',\
    LHashValOfNameSysA,'LHashValOfNameSysA',\
    LoadRegTypeLib,'LoadRegTypeLib',\
    LoadTypeLib,'LoadTypeLib',\
    LoadTypeLibEx,'LoadTypeLibEx',\
    LPSAFEARRAY_Marshal,'LPSAFEARRAY_Marshal',\
    LPSAFEARRAY_Size,'LPSAFEARRAY_Size',\
    LPSAFEARRAY_Unmarshal,'LPSAFEARRAY_Unmarshal',\
    LPSAFEARRAY_UserFree,'LPSAFEARRAY_UserFree',\
    LPSAFEARRAY_UserFree64,'LPSAFEARRAY_UserFree64',\
    LPSAFEARRAY_UserMarshal,'LPSAFEARRAY_UserMarshal',\
    LPSAFEARRAY_UserMarshal64,'LPSAFEARRAY_UserMarshal64',\
    LPSAFEARRAY_UserSize,'LPSAFEARRAY_UserSize',\
    LPSAFEARRAY_UserSize64,'LPSAFEARRAY_UserSize64',\
    LPSAFEARRAY_UserUnmarshal,'LPSAFEARRAY_UserUnmarshal',\
    LPSAFEARRAY_UserUnmarshal64,'LPSAFEARRAY_UserUnmarshal64',\
    OaBuildVersion,'OaBuildVersion',\
    OACleanup,'OACleanup',\
    OACreateTypeLib2,'OACreateTypeLib2',\
    OaEnablePerUserTLibRegistration,'OaEnablePerUserTLibRegistration',\
    OleCreateFontIndirect,'OleCreateFontIndirect',\
    OleCreatePictureIndirect,'OleCreatePictureIndirect',\
    OleCreatePropertyFrame,'OleCreatePropertyFrame',\
    OleCreatePropertyFrameIndirect,'OleCreatePropertyFrameIndirect',\
    OleIconToCursor,'OleIconToCursor',\
    OleLoadPicture,'OleLoadPicture',\
    OleLoadPictureEx,'OleLoadPictureEx',\
    OleLoadPictureFile,'OleLoadPictureFile',\
    OleLoadPictureFileEx,'OleLoadPictureFileEx',\
    OleLoadPicturePath,'OleLoadPicturePath',\
    OleSavePictureFile,'OleSavePictureFile',\
    OleTranslateColor,'OleTranslateColor',\
    QueryPathOfRegTypeLib,'QueryPathOfRegTypeLib',\
    RegisterActiveObject,'RegisterActiveObject',\
    RegisterTypeLib,'RegisterTypeLib',\
    RegisterTypeLibForUser,'RegisterTypeLibForUser',\
    RevokeActiveObject,'RevokeActiveObject',\
    SafeArrayAccessData,'SafeArrayAccessData',\
    SafeArrayAllocData,'SafeArrayAllocData',\
    SafeArrayAllocDescriptor,'SafeArrayAllocDescriptor',\
    SafeArrayAllocDescriptorEx,'SafeArrayAllocDescriptorEx',\
    SafeArrayCopy,'SafeArrayCopy',\
    SafeArrayCopyData,'SafeArrayCopyData',\
    SafeArrayCreate,'SafeArrayCreate',\
    SafeArrayCreateEx,'SafeArrayCreateEx',\
    SafeArrayCreateVector,'SafeArrayCreateVector',\
    SafeArrayCreateVectorEx,'SafeArrayCreateVectorEx',\
    SafeArrayDestroy,'SafeArrayDestroy',\
    SafeArrayDestroyData,'SafeArrayDestroyData',\
    SafeArrayDestroyDescriptor,'SafeArrayDestroyDescriptor',\
    SafeArrayGetDim,'SafeArrayGetDim',\
    SafeArrayGetElement,'SafeArrayGetElement',\
    SafeArrayGetElemsize,'SafeArrayGetElemsize',\
    SafeArrayGetIID,'SafeArrayGetIID',\
    SafeArrayGetLBound,'SafeArrayGetLBound',\
    SafeArrayGetRecordInfo,'SafeArrayGetRecordInfo',\
    SafeArrayGetUBound,'SafeArrayGetUBound',\
    SafeArrayGetVartype,'SafeArrayGetVartype',\
    SafeArrayLock,'SafeArrayLock',\
    SafeArrayPtrOfIndex,'SafeArrayPtrOfIndex',\
    SafeArrayPutElement,'SafeArrayPutElement',\
    SafeArrayRedim,'SafeArrayRedim',\
    SafeArraySetIID,'SafeArraySetIID',\
    SafeArraySetRecordInfo,'SafeArraySetRecordInfo',\
    SafeArrayUnaccessData,'SafeArrayUnaccessData',\
    SafeArrayUnlock,'SafeArrayUnlock',\
    SetErrorInfo,'SetErrorInfo',\
    SetOaNoCache,'SetOaNoCache',\
    SetVarConversionLocaleSetting,'SetVarConversionLocaleSetting',\
    SysAllocString,'SysAllocString',\
    SysAllocStringByteLen,'SysAllocStringByteLen',\
    SysAllocStringLen,'SysAllocStringLen',\
    SysFreeString,'SysFreeString',\
    SysReAllocString,'SysReAllocString',\
    SysReAllocStringLen,'SysReAllocStringLen',\
    SysStringByteLen,'SysStringByteLen',\
    SysStringLen,'SysStringLen',\
    SystemTimeToVariantTime,'SystemTimeToVariantTime',\
    UnRegisterTypeLib,'UnRegisterTypeLib',\
    UnRegisterTypeLibForUser,'UnRegisterTypeLibForUser',\
    VarAbs,'VarAbs',\
    VarAdd,'VarAdd',\
    VarAnd,'VarAnd',\
    VarBoolFromCy,'VarBoolFromCy',\
    VarBoolFromDate,'VarBoolFromDate',\
    VarBoolFromDec,'VarBoolFromDec',\
    VarBoolFromDisp,'VarBoolFromDisp',\
    VarBoolFromI1,'VarBoolFromI1',\
    VarBoolFromI2,'VarBoolFromI2',\
    VarBoolFromI4,'VarBoolFromI4',\
    VarBoolFromI8,'VarBoolFromI8',\
    VarBoolFromR4,'VarBoolFromR4',\
    VarBoolFromR8,'VarBoolFromR8',\
    VarBoolFromStr,'VarBoolFromStr',\
    VarBoolFromUI1,'VarBoolFromUI1',\
    VarBoolFromUI2,'VarBoolFromUI2',\
    VarBoolFromUI4,'VarBoolFromUI4',\
    VarBoolFromUI8,'VarBoolFromUI8',\
    VarBstrCat,'VarBstrCat',\
    VarBstrCmp,'VarBstrCmp',\
    VarBstrFromBool,'VarBstrFromBool',\
    VarBstrFromCy,'VarBstrFromCy',\
    VarBstrFromDate,'VarBstrFromDate',\
    VarBstrFromDec,'VarBstrFromDec',\
    VarBstrFromDisp,'VarBstrFromDisp',\
    VarBstrFromI1,'VarBstrFromI1',\
    VarBstrFromI2,'VarBstrFromI2',\
    VarBstrFromI4,'VarBstrFromI4',\
    VarBstrFromI8,'VarBstrFromI8',\
    VarBstrFromR4,'VarBstrFromR4',\
    VarBstrFromR8,'VarBstrFromR8',\
    VarBstrFromUI1,'VarBstrFromUI1',\
    VarBstrFromUI2,'VarBstrFromUI2',\
    VarBstrFromUI4,'VarBstrFromUI4',\
    VarBstrFromUI8,'VarBstrFromUI8',\
    VarCat,'VarCat',\
    VarCmp,'VarCmp',\
    VarCyAbs,'VarCyAbs',\
    VarCyAdd,'VarCyAdd',\
    VarCyCmp,'VarCyCmp',\
    VarCyCmpR8,'VarCyCmpR8',\
    VarCyFix,'VarCyFix',\
    VarCyFromBool,'VarCyFromBool',\
    VarCyFromDate,'VarCyFromDate',\
    VarCyFromDec,'VarCyFromDec',\
    VarCyFromDisp,'VarCyFromDisp',\
    VarCyFromI1,'VarCyFromI1',\
    VarCyFromI2,'VarCyFromI2',\
    VarCyFromI4,'VarCyFromI4',\
    VarCyFromI8,'VarCyFromI8',\
    VarCyFromR4,'VarCyFromR4',\
    VarCyFromR8,'VarCyFromR8',\
    VarCyFromStr,'VarCyFromStr',\
    VarCyFromUI1,'VarCyFromUI1',\
    VarCyFromUI2,'VarCyFromUI2',\
    VarCyFromUI4,'VarCyFromUI4',\
    VarCyFromUI8,'VarCyFromUI8',\
    VarCyInt,'VarCyInt',\
    VarCyMul,'VarCyMul',\
    VarCyMulI4,'VarCyMulI4',\
    VarCyMulI8,'VarCyMulI8',\
    VarCyNeg,'VarCyNeg',\
    VarCyRound,'VarCyRound',\
    VarCySub,'VarCySub',\
    VarDateFromBool,'VarDateFromBool',\
    VarDateFromCy,'VarDateFromCy',\
    VarDateFromDec,'VarDateFromDec',\
    VarDateFromDisp,'VarDateFromDisp',\
    VarDateFromI1,'VarDateFromI1',\
    VarDateFromI2,'VarDateFromI2',\
    VarDateFromI4,'VarDateFromI4',\
    VarDateFromI8,'VarDateFromI8',\
    VarDateFromR4,'VarDateFromR4',\
    VarDateFromR8,'VarDateFromR8',\
    VarDateFromStr,'VarDateFromStr',\
    VarDateFromUdate,'VarDateFromUdate',\
    VarDateFromUdateEx,'VarDateFromUdateEx',\
    VarDateFromUI1,'VarDateFromUI1',\
    VarDateFromUI2,'VarDateFromUI2',\
    VarDateFromUI4,'VarDateFromUI4',\
    VarDateFromUI8,'VarDateFromUI8',\
    VarDecAbs,'VarDecAbs',\
    VarDecAdd,'VarDecAdd',\
    VarDecCmp,'VarDecCmp',\
    VarDecCmpR8,'VarDecCmpR8',\
    VarDecDiv,'VarDecDiv',\
    VarDecFix,'VarDecFix',\
    VarDecFromBool,'VarDecFromBool',\
    VarDecFromCy,'VarDecFromCy',\
    VarDecFromDate,'VarDecFromDate',\
    VarDecFromDisp,'VarDecFromDisp',\
    VarDecFromI1,'VarDecFromI1',\
    VarDecFromI2,'VarDecFromI2',\
    VarDecFromI4,'VarDecFromI4',\
    VarDecFromI8,'VarDecFromI8',\
    VarDecFromR4,'VarDecFromR4',\
    VarDecFromR8,'VarDecFromR8',\
    VarDecFromStr,'VarDecFromStr',\
    VarDecFromUI1,'VarDecFromUI1',\
    VarDecFromUI2,'VarDecFromUI2',\
    VarDecFromUI4,'VarDecFromUI4',\
    VarDecFromUI8,'VarDecFromUI8',\
    VarDecInt,'VarDecInt',\
    VarDecMul,'VarDecMul',\
    VarDecNeg,'VarDecNeg',\
    VarDecRound,'VarDecRound',\
    VarDecSub,'VarDecSub',\
    VarDiv,'VarDiv',\
    VarEqv,'VarEqv',\
    VarFix,'VarFix',\
    VarFormat,'VarFormat',\
    VarFormatCurrency,'VarFormatCurrency',\
    VarFormatDateTime,'VarFormatDateTime',\
    VarFormatFromTokens,'VarFormatFromTokens',\
    VarFormatNumber,'VarFormatNumber',\
    VarFormatPercent,'VarFormatPercent',\
    VarI1FromBool,'VarI1FromBool',\
    VarI1FromCy,'VarI1FromCy',\
    VarI1FromDate,'VarI1FromDate',\
    VarI1FromDec,'VarI1FromDec',\
    VarI1FromDisp,'VarI1FromDisp',\
    VarI1FromI2,'VarI1FromI2',\
    VarI1FromI4,'VarI1FromI4',\
    VarI1FromI8,'VarI1FromI8',\
    VarI1FromR4,'VarI1FromR4',\
    VarI1FromR8,'VarI1FromR8',\
    VarI1FromStr,'VarI1FromStr',\
    VarI1FromUI1,'VarI1FromUI1',\
    VarI1FromUI2,'VarI1FromUI2',\
    VarI1FromUI4,'VarI1FromUI4',\
    VarI1FromUI8,'VarI1FromUI8',\
    VarI2FromBool,'VarI2FromBool',\
    VarI2FromCy,'VarI2FromCy',\
    VarI2FromDate,'VarI2FromDate',\
    VarI2FromDec,'VarI2FromDec',\
    VarI2FromDisp,'VarI2FromDisp',\
    VarI2FromI1,'VarI2FromI1',\
    VarI2FromI4,'VarI2FromI4',\
    VarI2FromI8,'VarI2FromI8',\
    VarI2FromR4,'VarI2FromR4',\
    VarI2FromR8,'VarI2FromR8',\
    VarI2FromStr,'VarI2FromStr',\
    VarI2FromUI1,'VarI2FromUI1',\
    VarI2FromUI2,'VarI2FromUI2',\
    VarI2FromUI4,'VarI2FromUI4',\
    VarI2FromUI8,'VarI2FromUI8',\
    VarI4FromBool,'VarI4FromBool',\
    VarI4FromCy,'VarI4FromCy',\
    VarI4FromDate,'VarI4FromDate',\
    VarI4FromDec,'VarI4FromDec',\
    VarI4FromDisp,'VarI4FromDisp',\
    VarI4FromI1,'VarI4FromI1',\
    VarI4FromI2,'VarI4FromI2',\
    VarI4FromI8,'VarI4FromI8',\
    VarI4FromR4,'VarI4FromR4',\
    VarI4FromR8,'VarI4FromR8',\
    VarI4FromStr,'VarI4FromStr',\
    VarI4FromUI1,'VarI4FromUI1',\
    VarI4FromUI2,'VarI4FromUI2',\
    VarI4FromUI4,'VarI4FromUI4',\
    VarI4FromUI8,'VarI4FromUI8',\
    VarI8FromBool,'VarI8FromBool',\
    VarI8FromCy,'VarI8FromCy',\
    VarI8FromDate,'VarI8FromDate',\
    VarI8FromDec,'VarI8FromDec',\
    VarI8FromDisp,'VarI8FromDisp',\
    VarI8FromI1,'VarI8FromI1',\
    VarI8FromI2,'VarI8FromI2',\
    VarI8FromR4,'VarI8FromR4',\
    VarI8FromR8,'VarI8FromR8',\
    VarI8FromStr,'VarI8FromStr',\
    VarI8FromUI1,'VarI8FromUI1',\
    VarI8FromUI2,'VarI8FromUI2',\
    VarI8FromUI4,'VarI8FromUI4',\
    VarI8FromUI8,'VarI8FromUI8',\
    VARIANT_UserFree,'VARIANT_UserFree',\
    VARIANT_UserFree64,'VARIANT_UserFree64',\
    VARIANT_UserMarshal,'VARIANT_UserMarshal',\
    VARIANT_UserMarshal64,'VARIANT_UserMarshal64',\
    VARIANT_UserSize,'VARIANT_UserSize',\
    VARIANT_UserSize64,'VARIANT_UserSize64',\
    VARIANT_UserUnmarshal,'VARIANT_UserUnmarshal',\
    VARIANT_UserUnmarshal64,'VARIANT_UserUnmarshal64',\
    VariantChangeType,'VariantChangeType',\
    VariantChangeTypeEx,'VariantChangeTypeEx',\
    VariantClear,'VariantClear',\
    VariantCopy,'VariantCopy',\
    VariantCopyInd,'VariantCopyInd',\
    VariantInit,'VariantInit',\
    VariantTimeToDosDateTime,'VariantTimeToDosDateTime',\
    VariantTimeToSystemTime,'VariantTimeToSystemTime',\
    VarIdiv,'VarIdiv',\
    VarImp,'VarImp',\
    VarInt,'VarInt',\
    VarMod,'VarMod',\
    VarMonthName,'VarMonthName',\
    VarMul,'VarMul',\
    VarNeg,'VarNeg',\
    VarNot,'VarNot',\
    VarNumFromParseNum,'VarNumFromParseNum',\
    VarOr,'VarOr',\
    VarParseNumFromStr,'VarParseNumFromStr',\
    VarPow,'VarPow',\
    VarR4CmpR8,'VarR4CmpR8',\
    VarR4FromBool,'VarR4FromBool',\
    VarR4FromCy,'VarR4FromCy',\
    VarR4FromDate,'VarR4FromDate',\
    VarR4FromDec,'VarR4FromDec',\
    VarR4FromDisp,'VarR4FromDisp',\
    VarR4FromI1,'VarR4FromI1',\
    VarR4FromI2,'VarR4FromI2',\
    VarR4FromI4,'VarR4FromI4',\
    VarR4FromI8,'VarR4FromI8',\
    VarR4FromR8,'VarR4FromR8',\
    VarR4FromStr,'VarR4FromStr',\
    VarR4FromUI1,'VarR4FromUI1',\
    VarR4FromUI2,'VarR4FromUI2',\
    VarR4FromUI4,'VarR4FromUI4',\
    VarR4FromUI8,'VarR4FromUI8',\
    VarR8FromBool,'VarR8FromBool',\
    VarR8FromCy,'VarR8FromCy',\
    VarR8FromDate,'VarR8FromDate',\
    VarR8FromDec,'VarR8FromDec',\
    VarR8FromDisp,'VarR8FromDisp',\
    VarR8FromI1,'VarR8FromI1',\
    VarR8FromI2,'VarR8FromI2',\
    VarR8FromI4,'VarR8FromI4',\
    VarR8FromI8,'VarR8FromI8',\
    VarR8FromR4,'VarR8FromR4',\
    VarR8FromStr,'VarR8FromStr',\
    VarR8FromUI1,'VarR8FromUI1',\
    VarR8FromUI2,'VarR8FromUI2',\
    VarR8FromUI4,'VarR8FromUI4',\
    VarR8FromUI8,'VarR8FromUI8',\
    VarR8Pow,'VarR8Pow',\
    VarR8Round,'VarR8Round',\
    VarRound,'VarRound',\
    VarSub,'VarSub',\
    VarTokenizeFormatString,'VarTokenizeFormatString',\
    VarUdateFromDate,'VarUdateFromDate',\
    VarUI1FromBool,'VarUI1FromBool',\
    VarUI1FromCy,'VarUI1FromCy',\
    VarUI1FromDate,'VarUI1FromDate',\
    VarUI1FromDec,'VarUI1FromDec',\
    VarUI1FromDisp,'VarUI1FromDisp',\
    VarUI1FromI1,'VarUI1FromI1',\
    VarUI1FromI2,'VarUI1FromI2',\
    VarUI1FromI4,'VarUI1FromI4',\
    VarUI1FromI8,'VarUI1FromI8',\
    VarUI1FromR4,'VarUI1FromR4',\
    VarUI1FromR8,'VarUI1FromR8',\
    VarUI1FromStr,'VarUI1FromStr',\
    VarUI1FromUI2,'VarUI1FromUI2',\
    VarUI1FromUI4,'VarUI1FromUI4',\
    VarUI1FromUI8,'VarUI1FromUI8',\
    VarUI2FromBool,'VarUI2FromBool',\
    VarUI2FromCy,'VarUI2FromCy',\
    VarUI2FromDate,'VarUI2FromDate',\
    VarUI2FromDec,'VarUI2FromDec',\
    VarUI2FromDisp,'VarUI2FromDisp',\
    VarUI2FromI1,'VarUI2FromI1',\
    VarUI2FromI2,'VarUI2FromI2',\
    VarUI2FromI4,'VarUI2FromI4',\
    VarUI2FromI8,'VarUI2FromI8',\
    VarUI2FromR4,'VarUI2FromR4',\
    VarUI2FromR8,'VarUI2FromR8',\
    VarUI2FromStr,'VarUI2FromStr',\
    VarUI2FromUI1,'VarUI2FromUI1',\
    VarUI2FromUI4,'VarUI2FromUI4',\
    VarUI2FromUI8,'VarUI2FromUI8',\
    VarUI4FromBool,'VarUI4FromBool',\
    VarUI4FromCy,'VarUI4FromCy',\
    VarUI4FromDate,'VarUI4FromDate',\
    VarUI4FromDec,'VarUI4FromDec',\
    VarUI4FromDisp,'VarUI4FromDisp',\
    VarUI4FromI1,'VarUI4FromI1',\
    VarUI4FromI2,'VarUI4FromI2',\
    VarUI4FromI4,'VarUI4FromI4',\
    VarUI4FromI8,'VarUI4FromI8',\
    VarUI4FromR4,'VarUI4FromR4',\
    VarUI4FromR8,'VarUI4FromR8',\
    VarUI4FromStr,'VarUI4FromStr',\
    VarUI4FromUI1,'VarUI4FromUI1',\
    VarUI4FromUI2,'VarUI4FromUI2',\
    VarUI4FromUI8,'VarUI4FromUI8',\
    VarUI8FromBool,'VarUI8FromBool',\
    VarUI8FromCy,'VarUI8FromCy',\
    VarUI8FromDate,'VarUI8FromDate',\
    VarUI8FromDec,'VarUI8FromDec',\
    VarUI8FromDisp,'VarUI8FromDisp',\
    VarUI8FromI1,'VarUI8FromI1',\
    VarUI8FromI2,'VarUI8FromI2',\
    VarUI8FromI8,'VarUI8FromI8',\
    VarUI8FromR4,'VarUI8FromR4',\
    VarUI8FromR8,'VarUI8FromR8',\
    VarUI8FromStr,'VarUI8FromStr',\
    VarUI8FromUI1,'VarUI8FromUI1',\
    VarUI8FromUI2,'VarUI8FromUI2',\
    VarUI8FromUI4,'VarUI8FromUI4',\
    VarWeekdayName,'VarWeekdayName',\
    VarXor,'VarXor',\
    VectorFromBstr,'VectorFromBstr'
else
    import oleaut32,\
    BSTR_UserFree,'BSTR_UserFree',\
    BSTR_UserFree64,'BSTR_UserFree64',\
    BSTR_UserMarshal,'BSTR_UserMarshal',\
    BSTR_UserMarshal64,'BSTR_UserMarshal64',\
    BSTR_UserSize,'BSTR_UserSize',\
    BSTR_UserSize64,'BSTR_UserSize64',\
    BSTR_UserUnmarshal,'BSTR_UserUnmarshal',\
    BSTR_UserUnmarshal64,'BSTR_UserUnmarshal64',\
    BstrFromVector,'BstrFromVector',\
    ClearCustData,'ClearCustData',\
    CreateDispTypeInfo,'CreateDispTypeInfo',\
    CreateErrorInfo,'CreateErrorInfo',\
    CreateStdDispatch,'CreateStdDispatch',\
    CreateTypeLib,'CreateTypeLib',\
    CreateTypeLib2,'CreateTypeLib2',\
    DispCallFunc,'DispCallFunc',\
    DispGetIDsOfNames,'DispGetIDsOfNames',\
    DispGetParam,'DispGetParam',\
    DispInvoke,'DispInvoke',\
    DllCanUnloadNow,'DllCanUnloadNow',\
    DllRegisterServer,'DllRegisterServer',\
    DllUnregisterServer,'DllUnregisterServer',\
    DosDateTimeToVariantTime,'DosDateTimeToVariantTime',\
    GetActiveObject,'GetActiveObject',\
    GetAltMonthNames,'GetAltMonthNames',\
    GetErrorInfo,'GetErrorInfo',\
    GetRecordInfoFromGuids,'GetRecordInfoFromGuids',\
    GetRecordInfoFromTypeInfo,'GetRecordInfoFromTypeInfo',\
    GetVarConversionLocaleSetting,'GetVarConversionLocaleSetting',\
    HWND_UserFree,'HWND_UserFree',\
    HWND_UserFree64,'HWND_UserFree64',\
    HWND_UserMarshal,'HWND_UserMarshal',\
    HWND_UserMarshal64,'HWND_UserMarshal64',\
    HWND_UserSize,'HWND_UserSize',\
    HWND_UserSize64,'HWND_UserSize64',\
    HWND_UserUnmarshal,'HWND_UserUnmarshal',\
    HWND_UserUnmarshal64,'HWND_UserUnmarshal64',\
    LHashValOfNameSys,'LHashValOfNameSys',\
    LHashValOfNameSysA,'LHashValOfNameSysA',\
    LoadRegTypeLib,'LoadRegTypeLib',\
    LoadTypeLib,'LoadTypeLib',\
    LoadTypeLibEx,'LoadTypeLibEx',\
    LPSAFEARRAY_Marshal,'LPSAFEARRAY_Marshal',\
    LPSAFEARRAY_Size,'LPSAFEARRAY_Size',\
    LPSAFEARRAY_Unmarshal,'LPSAFEARRAY_Unmarshal',\
    LPSAFEARRAY_UserFree,'LPSAFEARRAY_UserFree',\
    LPSAFEARRAY_UserFree64,'LPSAFEARRAY_UserFree64',\
    LPSAFEARRAY_UserMarshal,'LPSAFEARRAY_UserMarshal',\
    LPSAFEARRAY_UserMarshal64,'LPSAFEARRAY_UserMarshal64',\
    LPSAFEARRAY_UserSize,'LPSAFEARRAY_UserSize',\
    LPSAFEARRAY_UserSize64,'LPSAFEARRAY_UserSize64',\
    LPSAFEARRAY_UserUnmarshal,'LPSAFEARRAY_UserUnmarshal',\
    LPSAFEARRAY_UserUnmarshal64,'LPSAFEARRAY_UserUnmarshal64',\
    OaBuildVersion,'OaBuildVersion',\
    OACleanup,'OACleanup',\
    OACreateTypeLib2,'OACreateTypeLib2',\
    OaEnablePerUserTLibRegistration,'OaEnablePerUserTLibRegistration',\
    OleCreateFontIndirect,'OleCreateFontIndirect',\
    OleCreatePictureIndirect,'OleCreatePictureIndirect',\
    OleCreatePropertyFrame,'OleCreatePropertyFrame',\
    OleCreatePropertyFrameIndirect,'OleCreatePropertyFrameIndirect',\
    OleIconToCursor,'OleIconToCursor',\
    OleLoadPicture,'OleLoadPicture',\
    OleLoadPictureEx,'OleLoadPictureEx',\
    OleLoadPictureFile,'OleLoadPictureFile',\
    OleLoadPictureFileEx,'OleLoadPictureFileEx',\
    OleLoadPicturePath,'OleLoadPicturePath',\
    OleSavePictureFile,'OleSavePictureFile',\
    OleTranslateColor,'OleTranslateColor',\
    QueryPathOfRegTypeLib,'QueryPathOfRegTypeLib',\
    RegisterActiveObject,'RegisterActiveObject',\
    RegisterTypeLib,'RegisterTypeLib',\
    RegisterTypeLibForUser,'RegisterTypeLibForUser',\
    RevokeActiveObject,'RevokeActiveObject',\
    SafeArrayAccessData,'SafeArrayAccessData',\
    SafeArrayAllocData,'SafeArrayAllocData',\
    SafeArrayAllocDescriptor,'SafeArrayAllocDescriptor',\
    SafeArrayAllocDescriptorEx,'SafeArrayAllocDescriptorEx',\
    SafeArrayCopy,'SafeArrayCopy',\
    SafeArrayCopyData,'SafeArrayCopyData',\
    SafeArrayCreate,'SafeArrayCreate',\
    SafeArrayCreateEx,'SafeArrayCreateEx',\
    SafeArrayCreateVector,'SafeArrayCreateVector',\
    SafeArrayCreateVectorEx,'SafeArrayCreateVectorEx',\
    SafeArrayDestroy,'SafeArrayDestroy',\
    SafeArrayDestroyData,'SafeArrayDestroyData',\
    SafeArrayDestroyDescriptor,'SafeArrayDestroyDescriptor',\
    SafeArrayGetDim,'SafeArrayGetDim',\
    SafeArrayGetElement,'SafeArrayGetElement',\
    SafeArrayGetElemsize,'SafeArrayGetElemsize',\
    SafeArrayGetIID,'SafeArrayGetIID',\
    SafeArrayGetLBound,'SafeArrayGetLBound',\
    SafeArrayGetRecordInfo,'SafeArrayGetRecordInfo',\
    SafeArrayGetUBound,'SafeArrayGetUBound',\
    SafeArrayGetVartype,'SafeArrayGetVartype',\
    SafeArrayLock,'SafeArrayLock',\
    SafeArrayPtrOfIndex,'SafeArrayPtrOfIndex',\
    SafeArrayPutElement,'SafeArrayPutElement',\
    SafeArrayRedim,'SafeArrayRedim',\
    SafeArraySetIID,'SafeArraySetIID',\
    SafeArraySetRecordInfo,'SafeArraySetRecordInfo',\
    SafeArrayUnaccessData,'SafeArrayUnaccessData',\
    SafeArrayUnlock,'SafeArrayUnlock',\
    SetErrorInfo,'SetErrorInfo',\
    SetOaNoCache,'SetOaNoCache',\
    SetVarConversionLocaleSetting,'SetVarConversionLocaleSetting',\
    SysAllocString,'SysAllocString',\
    SysAllocStringByteLen,'SysAllocStringByteLen',\
    SysAllocStringLen,'SysAllocStringLen',\
    SysFreeString,'SysFreeString',\
    SysReAllocString,'SysReAllocString',\
    SysReAllocStringLen,'SysReAllocStringLen',\
    SysStringByteLen,'SysStringByteLen',\
    SysStringLen,'SysStringLen',\
    SystemTimeToVariantTime,'SystemTimeToVariantTime',\
    UnRegisterTypeLib,'UnRegisterTypeLib',\
    UnRegisterTypeLibForUser,'UnRegisterTypeLibForUser',\
    VarAbs,'VarAbs',\
    VarAdd,'VarAdd',\
    VarAnd,'VarAnd',\
    VarBoolFromCy,'VarBoolFromCy',\
    VarBoolFromDate,'VarBoolFromDate',\
    VarBoolFromDec,'VarBoolFromDec',\
    VarBoolFromDisp,'VarBoolFromDisp',\
    VarBoolFromI1,'VarBoolFromI1',\
    VarBoolFromI2,'VarBoolFromI2',\
    VarBoolFromI4,'VarBoolFromI4',\
    VarBoolFromI8,'VarBoolFromI8',\
    VarBoolFromR4,'VarBoolFromR4',\
    VarBoolFromR8,'VarBoolFromR8',\
    VarBoolFromStr,'VarBoolFromStr',\
    VarBoolFromUI1,'VarBoolFromUI1',\
    VarBoolFromUI2,'VarBoolFromUI2',\
    VarBoolFromUI4,'VarBoolFromUI4',\
    VarBoolFromUI8,'VarBoolFromUI8',\
    VarBstrCat,'VarBstrCat',\
    VarBstrCmp,'VarBstrCmp',\
    VarBstrFromBool,'VarBstrFromBool',\
    VarBstrFromCy,'VarBstrFromCy',\
    VarBstrFromDate,'VarBstrFromDate',\
    VarBstrFromDec,'VarBstrFromDec',\
    VarBstrFromDisp,'VarBstrFromDisp',\
    VarBstrFromI1,'VarBstrFromI1',\
    VarBstrFromI2,'VarBstrFromI2',\
    VarBstrFromI4,'VarBstrFromI4',\
    VarBstrFromI8,'VarBstrFromI8',\
    VarBstrFromR4,'VarBstrFromR4',\
    VarBstrFromR8,'VarBstrFromR8',\
    VarBstrFromUI1,'VarBstrFromUI1',\
    VarBstrFromUI2,'VarBstrFromUI2',\
    VarBstrFromUI4,'VarBstrFromUI4',\
    VarBstrFromUI8,'VarBstrFromUI8',\
    VarCat,'VarCat',\
    VarCmp,'VarCmp',\
    VarCyAbs,'VarCyAbs',\
    VarCyAdd,'VarCyAdd',\
    VarCyCmp,'VarCyCmp',\
    VarCyCmpR8,'VarCyCmpR8',\
    VarCyFix,'VarCyFix',\
    VarCyFromBool,'VarCyFromBool',\
    VarCyFromDate,'VarCyFromDate',\
    VarCyFromDec,'VarCyFromDec',\
    VarCyFromDisp,'VarCyFromDisp',\
    VarCyFromI1,'VarCyFromI1',\
    VarCyFromI2,'VarCyFromI2',\
    VarCyFromI4,'VarCyFromI4',\
    VarCyFromI8,'VarCyFromI8',\
    VarCyFromR4,'VarCyFromR4',\
    VarCyFromR8,'VarCyFromR8',\
    VarCyFromStr,'VarCyFromStr',\
    VarCyFromUI1,'VarCyFromUI1',\
    VarCyFromUI2,'VarCyFromUI2',\
    VarCyFromUI4,'VarCyFromUI4',\
    VarCyFromUI8,'VarCyFromUI8',\
    VarCyInt,'VarCyInt',\
    VarCyMul,'VarCyMul',\
    VarCyMulI4,'VarCyMulI4',\
    VarCyMulI8,'VarCyMulI8',\
    VarCyNeg,'VarCyNeg',\
    VarCyRound,'VarCyRound',\
    VarCySub,'VarCySub',\
    VarDateFromBool,'VarDateFromBool',\
    VarDateFromCy,'VarDateFromCy',\
    VarDateFromDec,'VarDateFromDec',\
    VarDateFromDisp,'VarDateFromDisp',\
    VarDateFromI1,'VarDateFromI1',\
    VarDateFromI2,'VarDateFromI2',\
    VarDateFromI4,'VarDateFromI4',\
    VarDateFromI8,'VarDateFromI8',\
    VarDateFromR4,'VarDateFromR4',\
    VarDateFromR8,'VarDateFromR8',\
    VarDateFromStr,'VarDateFromStr',\
    VarDateFromUdate,'VarDateFromUdate',\
    VarDateFromUdateEx,'VarDateFromUdateEx',\
    VarDateFromUI1,'VarDateFromUI1',\
    VarDateFromUI2,'VarDateFromUI2',\
    VarDateFromUI4,'VarDateFromUI4',\
    VarDateFromUI8,'VarDateFromUI8',\
    VarDecAbs,'VarDecAbs',\
    VarDecAdd,'VarDecAdd',\
    VarDecCmp,'VarDecCmp',\
    VarDecCmpR8,'VarDecCmpR8',\
    VarDecDiv,'VarDecDiv',\
    VarDecFix,'VarDecFix',\
    VarDecFromBool,'VarDecFromBool',\
    VarDecFromCy,'VarDecFromCy',\
    VarDecFromDate,'VarDecFromDate',\
    VarDecFromDisp,'VarDecFromDisp',\
    VarDecFromI1,'VarDecFromI1',\
    VarDecFromI2,'VarDecFromI2',\
    VarDecFromI4,'VarDecFromI4',\
    VarDecFromI8,'VarDecFromI8',\
    VarDecFromR4,'VarDecFromR4',\
    VarDecFromR8,'VarDecFromR8',\
    VarDecFromStr,'VarDecFromStr',\
    VarDecFromUI1,'VarDecFromUI1',\
    VarDecFromUI2,'VarDecFromUI2',\
    VarDecFromUI4,'VarDecFromUI4',\
    VarDecFromUI8,'VarDecFromUI8',\
    VarDecInt,'VarDecInt',\
    VarDecMul,'VarDecMul',\
    VarDecNeg,'VarDecNeg',\
    VarDecRound,'VarDecRound',\
    VarDecSub,'VarDecSub',\
    VarDiv,'VarDiv',\
    VarEqv,'VarEqv',\
    VarFix,'VarFix',\
    VarFormat,'VarFormat',\
    VarFormatCurrency,'VarFormatCurrency',\
    VarFormatDateTime,'VarFormatDateTime',\
    VarFormatFromTokens,'VarFormatFromTokens',\
    VarFormatNumber,'VarFormatNumber',\
    VarFormatPercent,'VarFormatPercent',\
    VarI1FromBool,'VarI1FromBool',\
    VarI1FromCy,'VarI1FromCy',\
    VarI1FromDate,'VarI1FromDate',\
    VarI1FromDec,'VarI1FromDec',\
    VarI1FromDisp,'VarI1FromDisp',\
    VarI1FromI2,'VarI1FromI2',\
    VarI1FromI4,'VarI1FromI4',\
    VarI1FromI8,'VarI1FromI8',\
    VarI1FromR4,'VarI1FromR4',\
    VarI1FromR8,'VarI1FromR8',\
    VarI1FromStr,'VarI1FromStr',\
    VarI1FromUI1,'VarI1FromUI1',\
    VarI1FromUI2,'VarI1FromUI2',\
    VarI1FromUI4,'VarI1FromUI4',\
    VarI1FromUI8,'VarI1FromUI8',\
    VarI2FromBool,'VarI2FromBool',\
    VarI2FromCy,'VarI2FromCy',\
    VarI2FromDate,'VarI2FromDate',\
    VarI2FromDec,'VarI2FromDec',\
    VarI2FromDisp,'VarI2FromDisp',\
    VarI2FromI1,'VarI2FromI1',\
    VarI2FromI4,'VarI2FromI4',\
    VarI2FromI8,'VarI2FromI8',\
    VarI2FromR4,'VarI2FromR4',\
    VarI2FromR8,'VarI2FromR8',\
    VarI2FromStr,'VarI2FromStr',\
    VarI2FromUI1,'VarI2FromUI1',\
    VarI2FromUI2,'VarI2FromUI2',\
    VarI2FromUI4,'VarI2FromUI4',\
    VarI2FromUI8,'VarI2FromUI8',\
    VarI4FromBool,'VarI4FromBool',\
    VarI4FromCy,'VarI4FromCy',\
    VarI4FromDate,'VarI4FromDate',\
    VarI4FromDec,'VarI4FromDec',\
    VarI4FromDisp,'VarI4FromDisp',\
    VarI4FromI1,'VarI4FromI1',\
    VarI4FromI2,'VarI4FromI2',\
    VarI4FromI8,'VarI4FromI8',\
    VarI4FromR4,'VarI4FromR4',\
    VarI4FromR8,'VarI4FromR8',\
    VarI4FromStr,'VarI4FromStr',\
    VarI4FromUI1,'VarI4FromUI1',\
    VarI4FromUI2,'VarI4FromUI2',\
    VarI4FromUI4,'VarI4FromUI4',\
    VarI4FromUI8,'VarI4FromUI8',\
    VarI8FromBool,'VarI8FromBool',\
    VarI8FromCy,'VarI8FromCy',\
    VarI8FromDate,'VarI8FromDate',\
    VarI8FromDec,'VarI8FromDec',\
    VarI8FromDisp,'VarI8FromDisp',\
    VarI8FromI1,'VarI8FromI1',\
    VarI8FromI2,'VarI8FromI2',\
    VarI8FromR4,'VarI8FromR4',\
    VarI8FromR8,'VarI8FromR8',\
    VarI8FromStr,'VarI8FromStr',\
    VarI8FromUI1,'VarI8FromUI1',\
    VarI8FromUI2,'VarI8FromUI2',\
    VarI8FromUI4,'VarI8FromUI4',\
    VarI8FromUI8,'VarI8FromUI8',\
    VARIANT_UserFree,'VARIANT_UserFree',\
    VARIANT_UserFree64,'VARIANT_UserFree64',\
    VARIANT_UserMarshal,'VARIANT_UserMarshal',\
    VARIANT_UserMarshal64,'VARIANT_UserMarshal64',\
    VARIANT_UserSize,'VARIANT_UserSize',\
    VARIANT_UserSize64,'VARIANT_UserSize64',\
    VARIANT_UserUnmarshal,'VARIANT_UserUnmarshal',\
    VARIANT_UserUnmarshal64,'VARIANT_UserUnmarshal64',\
    VariantChangeType,'VariantChangeType',\
    VariantChangeTypeEx,'VariantChangeTypeEx',\
    VariantClear,'VariantClear',\
    VariantCopy,'VariantCopy',\
    VariantCopyInd,'VariantCopyInd',\
    VariantInit,'VariantInit',\
    VariantTimeToDosDateTime,'VariantTimeToDosDateTime',\
    VariantTimeToSystemTime,'VariantTimeToSystemTime',\
    VarIdiv,'VarIdiv',\
    VarImp,'VarImp',\
    VarInt,'VarInt',\
    VarMod,'VarMod',\
    VarMonthName,'VarMonthName',\
    VarMul,'VarMul',\
    VarNeg,'VarNeg',\
    VarNot,'VarNot',\
    VarNumFromParseNum,'VarNumFromParseNum',\
    VarOr,'VarOr',\
    VarParseNumFromStr,'VarParseNumFromStr',\
    VarPow,'VarPow',\
    VarR4CmpR8,'VarR4CmpR8',\
    VarR4FromBool,'VarR4FromBool',\
    VarR4FromCy,'VarR4FromCy',\
    VarR4FromDate,'VarR4FromDate',\
    VarR4FromDec,'VarR4FromDec',\
    VarR4FromDisp,'VarR4FromDisp',\
    VarR4FromI1,'VarR4FromI1',\
    VarR4FromI2,'VarR4FromI2',\
    VarR4FromI4,'VarR4FromI4',\
    VarR4FromI8,'VarR4FromI8',\
    VarR4FromR8,'VarR4FromR8',\
    VarR4FromStr,'VarR4FromStr',\
    VarR4FromUI1,'VarR4FromUI1',\
    VarR4FromUI2,'VarR4FromUI2',\
    VarR4FromUI4,'VarR4FromUI4',\
    VarR4FromUI8,'VarR4FromUI8',\
    VarR8FromBool,'VarR8FromBool',\
    VarR8FromCy,'VarR8FromCy',\
    VarR8FromDate,'VarR8FromDate',\
    VarR8FromDec,'VarR8FromDec',\
    VarR8FromDisp,'VarR8FromDisp',\
    VarR8FromI1,'VarR8FromI1',\
    VarR8FromI2,'VarR8FromI2',\
    VarR8FromI4,'VarR8FromI4',\
    VarR8FromI8,'VarR8FromI8',\
    VarR8FromR4,'VarR8FromR4',\
    VarR8FromStr,'VarR8FromStr',\
    VarR8FromUI1,'VarR8FromUI1',\
    VarR8FromUI2,'VarR8FromUI2',\
    VarR8FromUI4,'VarR8FromUI4',\
    VarR8FromUI8,'VarR8FromUI8',\
    VarR8Pow,'VarR8Pow',\
    VarR8Round,'VarR8Round',\
    VarRound,'VarRound',\
    VarSub,'VarSub',\
    VarTokenizeFormatString,'VarTokenizeFormatString',\
    VarUdateFromDate,'VarUdateFromDate',\
    VarUI1FromBool,'VarUI1FromBool',\
    VarUI1FromCy,'VarUI1FromCy',\
    VarUI1FromDate,'VarUI1FromDate',\
    VarUI1FromDec,'VarUI1FromDec',\
    VarUI1FromDisp,'VarUI1FromDisp',\
    VarUI1FromI1,'VarUI1FromI1',\
    VarUI1FromI2,'VarUI1FromI2',\
    VarUI1FromI4,'VarUI1FromI4',\
    VarUI1FromI8,'VarUI1FromI8',\
    VarUI1FromR4,'VarUI1FromR4',\
    VarUI1FromR8,'VarUI1FromR8',\
    VarUI1FromStr,'VarUI1FromStr',\
    VarUI1FromUI2,'VarUI1FromUI2',\
    VarUI1FromUI4,'VarUI1FromUI4',\
    VarUI1FromUI8,'VarUI1FromUI8',\
    VarUI2FromBool,'VarUI2FromBool',\
    VarUI2FromCy,'VarUI2FromCy',\
    VarUI2FromDate,'VarUI2FromDate',\
    VarUI2FromDec,'VarUI2FromDec',\
    VarUI2FromDisp,'VarUI2FromDisp',\
    VarUI2FromI1,'VarUI2FromI1',\
    VarUI2FromI2,'VarUI2FromI2',\
    VarUI2FromI4,'VarUI2FromI4',\
    VarUI2FromI8,'VarUI2FromI8',\
    VarUI2FromR4,'VarUI2FromR4',\
    VarUI2FromR8,'VarUI2FromR8',\
    VarUI2FromStr,'VarUI2FromStr',\
    VarUI2FromUI1,'VarUI2FromUI1',\
    VarUI2FromUI4,'VarUI2FromUI4',\
    VarUI2FromUI8,'VarUI2FromUI8',\
    VarUI4FromBool,'VarUI4FromBool',\
    VarUI4FromCy,'VarUI4FromCy',\
    VarUI4FromDate,'VarUI4FromDate',\
    VarUI4FromDec,'VarUI4FromDec',\
    VarUI4FromDisp,'VarUI4FromDisp',\
    VarUI4FromI1,'VarUI4FromI1',\
    VarUI4FromI2,'VarUI4FromI2',\
    VarUI4FromI4,'VarUI4FromI4',\
    VarUI4FromI8,'VarUI4FromI8',\
    VarUI4FromR4,'VarUI4FromR4',\
    VarUI4FromR8,'VarUI4FromR8',\
    VarUI4FromStr,'VarUI4FromStr',\
    VarUI4FromUI1,'VarUI4FromUI1',\
    VarUI4FromUI2,'VarUI4FromUI2',\
    VarUI4FromUI8,'VarUI4FromUI8',\
    VarUI8FromBool,'VarUI8FromBool',\
    VarUI8FromCy,'VarUI8FromCy',\
    VarUI8FromDate,'VarUI8FromDate',\
    VarUI8FromDec,'VarUI8FromDec',\
    VarUI8FromDisp,'VarUI8FromDisp',\
    VarUI8FromI1,'VarUI8FromI1',\
    VarUI8FromI2,'VarUI8FromI2',\
    VarUI8FromI8,'VarUI8FromI8',\
    VarUI8FromR4,'VarUI8FromR4',\
    VarUI8FromR8,'VarUI8FromR8',\
    VarUI8FromStr,'VarUI8FromStr',\
    VarUI8FromUI1,'VarUI8FromUI1',\
    VarUI8FromUI2,'VarUI8FromUI2',\
    VarUI8FromUI4,'VarUI8FromUI4',\
    VarWeekdayName,'VarWeekdayName',\
    VarXor,'VarXor',\
    VectorFromBstr,'VectorFromBstr'
end if

end if ;OLEAUT32_INC
