; ====================================================;
;                                                     ;
;    oleaut32.inc for EC v2 SolAsm classic projects   ;
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
