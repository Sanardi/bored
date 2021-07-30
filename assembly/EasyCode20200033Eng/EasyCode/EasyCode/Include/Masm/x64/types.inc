; =====================================================;
;                                                      ;
;   types.inc for Easy Code 2.0 64-bit Masm projects   ;
;                  (version 1.0.6)                     ;
;                                                      ;
;         Copyright © Ramon Sala - 2015-2020           ;
;                                                      ;
; =====================================================;

IFNDEF TYPES_INC
TYPES_INC   EQU     1

IFDEF APP_WIN64
    IFNDEF ALIGNMODE
        IFDEF POASM_COMPILER
            ALIGNMODE                           TEXTEQU <>
        ELSE
            ALIGNMODE                           TEXTEQU <16>
        ENDIF
    ENDIF
    XPTR                                        TYPEDEF QWORD
    XWORD                                       TYPEDEF QWORD
    ENUM                                        TYPEDEF QWORD
ELSE
    IFNDEF ALIGNMODE
        ALIGNMODE                               TEXTEQU <4>
    ENDIF
    XPTR                                        TYPEDEF DWORD
    XWORD                                       TYPEDEF DWORD
    ENUM                                        TYPEDEF DWORD
ENDIF

IFDEF APP_UNICODE
    BCHAR                                       TYPEDEF WORD
    SCHAR                                       TYPEDEF WORD
    TCHAR                                       TYPEDEF WORD
ELSE
    BCHAR                                       TYPEDEF BYTE
    SCHAR                                       TYPEDEF BYTE
    TCHAR                                       TYPEDEF BYTE
ENDIF

ACCESS_MASK                                     TYPEDEF DWORD
ATOM                                            TYPEDEF WORD
BOOL                                            TYPEDEF DWORD
BOOLEAN                                         TYPEDEF BYTE
CALID                                           TYPEDEF DWORD
CALTYPE                                         TYPEDEF DWORD
CHAR                                            TYPEDEF BYTE
COLORREF                                        TYPEDEF DWORD
DATE                                            TYPEDEF QWORD
DOUBLE                                          TYPEDEF REAL8
DWORD32                                         TYPEDEF DWORD
DWORD64                                         TYPEDEF QWORD
DWORDLONG                                       TYPEDEF QWORD
FILEOP_FLAGS                                    TYPEDEF WORD
FLOAT                                           TYPEDEF REAL4
HFILE                                           TYPEDEF DWORD
INT16                                           TYPEDEF WORD
INT32                                           TYPEDEF DWORD
INT64                                           TYPEDEF QWORD
LANGID                                          TYPEDEF WORD
LCID                                            TYPEDEF DWORD
LCTYPE                                          TYPEDEF DWORD
LGRPID                                          TYPEDEF DWORD
LONG                                            TYPEDEF DWORD
LONG32                                          TYPEDEF DWORD
LONG64                                          TYPEDEF QWORD
LONGLONG                                        TYPEDEF QWORD
MCIDEVICEID                                     TYPEDEF DWORD
SCODE                                           TYPEDEF DWORD
UBYTE                                           TYPEDEF BYTE
UCHAR                                           TYPEDEF BYTE
UINT                                            TYPEDEF DWORD
UINT8                                           TYPEDEF BYTE
UINT16                                          TYPEDEF WORD
UINT32                                          TYPEDEF DWORD
UINT64                                          TYPEDEF QWORD
ULONG                                           TYPEDEF DWORD
ULONG32                                         TYPEDEF DWORD
ULONG64                                         TYPEDEF QWORD
ULONGLONG                                       TYPEDEF QWORD
USHORT                                          TYPEDEF WORD
USN                                             TYPEDEF QWORD
WCHAR                                           TYPEDEF WORD
VARIANT_BOOL                                    TYPEDEF WORD
VARTYPE                                         TYPEDEF WORD

DWORD_PTR                                       TYPEDEF XPTR
HACCEL                                          TYPEDEF XPTR
HANDLE                                          TYPEDEF XPTR
HGLRC                                           TYPEDEF XPTR
HTASK                                           TYPEDEF XPTR
HWINEVENTHOOK                                   TYPEDEF XPTR
INT_PTR                                         TYPEDEF XPTR
LONG_PTR                                        TYPEDEF XPTR
LPARAM                                          TYPEDEF XPTR
LPBOOL                                          TYPEDEF XPTR
LPBYTE                                          TYPEDEF XPTR
LPCOLORREF                                      TYPEDEF XPTR
LPCSTR                                          TYPEDEF XPTR
LPCTSTR                                         TYPEDEF XPTR
LPCVOID                                         TYPEDEF XPTR
LPCWSTR                                         TYPEDEF XPTR
LPDWORD                                         TYPEDEF XPTR
LPHANDLE                                        TYPEDEF XPTR
LPLONG                                          TYPEDEF XPTR
LPSTR                                           TYPEDEF XPTR
LPTSTR                                          TYPEDEF XPTR
LPVOID                                          TYPEDEF XPTR
LPWORD                                          TYPEDEF XPTR
LPWSTR                                          TYPEDEF XPTR
LRESULT                                         TYPEDEF XPTR
PBOOLEAN                                        TYPEDEF XPTR
PDWORD32                                        TYPEDEF XPTR
PHALF_PTR                                       TYPEDEF XPTR
PINT16                                          TYPEDEF XPTR
PINT32                                          TYPEDEF XPTR
PINT64                                          TYPEDEF XPTR
PINT8                                           TYPEDEF XPTR
PINT_PTR                                        TYPEDEF XPTR
PLONG_PTR                                       TYPEDEF XPTR
PUINT32                                         TYPEDEF XPTR
PUINT64                                         TYPEDEF XPTR
PUINT_PTR                                       TYPEDEF XPTR
PULONG                                          TYPEDEF XPTR
PULONGLONG                                      TYPEDEF XPTR
PSCODE                                          TYPEDEF XPTR
PLONG32                                         TYPEDEF XPTR
PULONG32                                        TYPEDEF XPTR
PVOID                                           TYPEDEF XPTR
PWSTR                                           TYPEDEF XPTR
SOCKET                                          TYPEDEF XPTR
UINT_PTR                                        TYPEDEF XPTR
ULONG_PTR                                       TYPEDEF XPTR
WNDPROC                                         TYPEDEF XPTR

HBITMAP                                         TYPEDEF HANDLE
HBRUSH                                          TYPEDEF HANDLE
HCOLORSPACE                                     TYPEDEF HANDLE
HCONV                                           TYPEDEF HANDLE
HCONVLIST                                       TYPEDEF HANDLE
HCURSOR                                         TYPEDEF HANDLE
HDC                                             TYPEDEF HANDLE
HDDEDATA                                        TYPEDEF HANDLE
HDESK                                           TYPEDEF HANDLE
HDROP                                           TYPEDEF HANDLE
HDWP                                            TYPEDEF HANDLE
HENHMETAFILE                                    TYPEDEF HANDLE
HFONT                                           TYPEDEF HANDLE
HGDIOBJ                                         TYPEDEF HANDLE
HGLOBAL                                         TYPEDEF HANDLE
HHOOK                                           TYPEDEF HANDLE
HICON                                           TYPEDEF HANDLE
HINSTANCE                                       TYPEDEF HANDLE
HKEY                                            TYPEDEF HANDLE
HKL                                             TYPEDEF HANDLE
HLOCAL                                          TYPEDEF HANDLE
HMENU                                           TYPEDEF HANDLE
HMETAFILE                                       TYPEDEF HANDLE
HMODULE                                         TYPEDEF HINSTANCE
HMONITOR                                        TYPEDEF HANDLE
HPALETTE                                        TYPEDEF HANDLE
HPEN                                            TYPEDEF HANDLE
HRESULT                                         TYPEDEF LONG
HRGN                                            TYPEDEF HANDLE
HRSRC                                           TYPEDEF HANDLE
HSZ                                             TYPEDEF HANDLE
HWINSTA                                         TYPEDEF HANDLE
HWND                                            TYPEDEF HANDLE
SIZE_T                                          TYPEDEF ULONG_PTR
size_t                                          TYPEDEF SIZE_T
WPARAM                                          TYPEDEF UINT_PTR

CLSCTX_ACTIVATE_32_BIT_SERVER                   EQU     00040000H
CLSCTX_ACTIVATE_64_BIT_SERVER                   EQU     00080000H
CLSCTX_ACTIVATE_AAA_AS_IU                       EQU     00800000H
CLSCTX_ALL                                      EQU     00000007H
CLSCTX_APPCONTAINER                             EQU     00400000H
CLSCTX_DISABLE_AAA                              EQU     00008000H
CLSCTX_ENABLE_AAA                               EQU     00010000H
CLSCTX_ENABLE_CLOAKING                          EQU     00100000H
CLSCTX_ENABLE_CODE_DOWNLOAD                     EQU     00002000H
CLSCTX_ESERVER_HANDLER                          EQU     00000100H
CLSCTX_FROM_DEFAULT_CONTEXT                     EQU     00020000H
CLSCTX_INPROC                                   EQU     00000003H
CLSCTX_INPROC_HANDLER                           EQU     00000002H
CLSCTX_INPROC_HANDLER16                         EQU     00000020H
CLSCTX_INPROC_HANDLERX86                        EQU     00000080H
CLSCTX_INPROC_SERVER                            EQU     00000001H
CLSCTX_INPROC_SERVER16                          EQU     00000008H
CLSCTX_INPROC_SERVERX86                         EQU     00000040H
CLSCTX_LOCAL_SERVER                             EQU     00000004H
CLSCTX_NO_CODE_DOWNLOAD                         EQU     00000400H
CLSCTX_NO_CUSTOM_MARSHAL                        EQU     00001000H
CLSCTX_NO_FAILURE_LOG                           EQU     00004000H
CLSCTX_PS_DLL                                   EQU     80000000H
CLSCTX_REMOTE_SERVER                            EQU     00000010H
CLSCTX_RESERVED1                                EQU     00000040H
CLSCTX_RESERVED2                                EQU     00000080H
CLSCTX_RESERVED3                                EQU     00000100H
CLSCTX_RESERVED4                                EQU     00000200H
CLSCTX_RESERVED5                                EQU     00000800H
CLSCTX_SERVER                                   EQU     00000005H

;VARENUM enum
VT_EMPTY                                        EQU     0000H
VT_NULL                                         EQU     0001H
VT_I2                                           EQU     0002H
VT_I4                                           EQU     0003H
VT_R4                                           EQU     0004H
VT_R8                                           EQU     0005H
VT_CY                                           EQU     0006H
VT_DATE                                         EQU     0007H
VT_BSTR                                         EQU     0008H
VT_DISPATCH                                     EQU     0009H
VT_ERROR                                        EQU     000AH
VT_BOOL                                         EQU     000BH
VT_VARIANT                                      EQU     000CH
VT_UNKNOWN                                      EQU     000DH
VT_DECIMAL                                      EQU     000EH
VT_I1                                           EQU     0010H
VT_UI1                                          EQU     0011H
VT_UI2                                          EQU     0012H
VT_UI4                                          EQU     0013H
VT_I8                                           EQU     0014H
VT_UI8                                          EQU     0015H
VT_INT                                          EQU     0016H
VT_UINT                                         EQU     0017H
VT_VOID                                         EQU     0018H
VT_HRESULT                                      EQU     0019H
VT_PTR                                          EQU     001AH
VT_SAFEARRAY                                    EQU     001BH
VT_CARRAY                                       EQU     001CH
VT_USERDEFINED                                  EQU     001DH
VT_LPSTR                                        EQU     001EH
VT_LPWSTR                                       EQU     001FH
VT_RECORD                                       EQU     0024H
VT_INT_PTR                                      EQU     0025H
VT_UINT_PTR                                     EQU     0026H
VT_ARRAY                                        EQU     2000H
VT_BYREF                                        EQU     4000H
VT_ILLEGAL                                      EQU     0FFFFH
VT_ILLEGALMASKED                                EQU     0FFFH

IFNDEF RECT
    RECT STRUCT ALIGNMODE
        left    DD    ?
        top     DD    ?
        right   DD    ?
        bottom  DD    ?
    RECT ENDS
ENDIF

IFNDEF RECTL
    RECTL STRUCT ALIGNMODE
        left    DD    ?
        top     DD    ?
        right   DD    ?
        bottom  DD    ?
    RECTL ENDS
ENDIF

IFNDEF POINT
    POINT STRUCT ALIGNMODE
        x   DD  ?
        y   DD  ?
    POINT ENDS
ENDIF

IFNDEF POINTL
    POINTL STRUCT ALIGNMODE
        x   DD  ?
        y   DD  ?
    POINTL ENDS
ENDIF

IFNDEF SIZEL
    SIZEL STRUCT ALIGNMODE
        x   DD  ?
        y   DD  ?
    SIZEL ENDS
ENDIF

IFNDEF POINTS
    POINTS STRUCT ALIGNMODE
        x   DW  ?
        y   DW  ?
    POINTS ENDS
ENDIF

IFNDEF NMHDR
    NMHDR STRUCT ALIGNMODE
        hwndFrom HWND      ?
        idFrom   UINT_PTR  ?
        _code    UINT      ?
        IFDEF APP_WIN64
                 UINT      ?
        ENDIF
    NMHDR ENDS
ENDIF

IFNDEF LUID
    LUID STRUCT ALIGNMODE
        LowPart     DD  ?
        HighPart    DD  ?
    LUID ENDS
ENDIF

IFNDEF CY
    CY STRUCT ALIGNMODE
        Lo  LONG ?
        Hi  LONG ?
    CY ENDS
ENDIF

IFNDEF DECIMAL
    DECIMAL STRUCT ALIGNMODE
        Hi32 DWORD ?
        Lo64 QWORD ?
    DECIMAL ENDS
ENDIF

VARIANT STRUCT ALIGNMODE
    UNION __VARIANT_NAME_1
        STRUCT __VARIANT_NAME_2
            vt            WORD ?
            wReserved1    WORD ?
            wReserved2    WORD ?
            wReserved3    WORD ?
            UNION __VARIANT_NAME_3
                llVal       LONGLONG ?
                lVal        LONG     ?
                bVal        BYTE     ?
                iVal        WORD     ?
                fltVal      REAL4    ?
                dblVal      REAL8    ?
                boolVal     VARIANT_BOOL ?
                scode       SCODE    ?
                __OBSOLETE__VARIANT_BOOL VARIANT_BOOL ?
                cyVal       CY    <>
                date        DATE  ?
                bstrVal     WCHAR ?
                punkVal     XPTR  ?
                pdispVal    XPTR  ?
                parray      XPTR  ?
                pbVal       XPTR  ?
                piVal       XPTR  ?
                plVal       XPTR  ?
                pllVal      XPTR  ?
                pfltVal     XPTR  ?
                pdblVal     XPTR  ?
                pboolVal    XPTR  ?
                pscode      XPTR  ?
                pcyVal      XPTR  ?
                __OBSOLETE__VARIANT_PBOOL XPTR ?
                pdate       XPTR  ?
                pbstrVal    XPTR  ?
                ppunkVal    XPTR  ?
                ppdispVal   XPTR  ?
                pparray     XPTR  ?
                pvarVal     XPTR  ?
                byref       XPTR  ?
                cVal        CHAR  ?
                uiVal       USHORT ?
                ulVal       ULONG ?
                ullVal      ULONGLONG ?
                intVal      DWORD ?
                uintVal     UINT  ?
                pdecVal     XPTR  ?
                pcVal       XPTR  ?
                puiVal      XPTR  ?
                pulVal      XPTR  ?
                pullVal     XPTR  ?
                pintVal     XPTR  ?
                puintVal    XPTR  ?
                STRUCT __VARIANT_NAME_4
                    pvRecord  XPTR  ?
                    pRecInfo  XPTR  ?
                ENDS
            ENDS
        ENDS
        decVal  DECIMAL <>
    ENDS
VARIANT ENDS

ENDIF ;TYPES_INC
