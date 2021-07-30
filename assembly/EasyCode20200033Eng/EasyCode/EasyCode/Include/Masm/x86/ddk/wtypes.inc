;===================================================================;
;                                                                   ;
;   wtypes.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers    ;
;                        (version 1.0.2)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;               Copyright © Ramon Sala - 2015-2018                  ;
;                                                                   ;
;===================================================================;

IFNDEF WTYPES_INC
WTYPES_INC Equ 1

Include ntdef.inc

IFNDEF RemHGLOBAL
    RemHGLOBAL Struct
        fNullHGlobal                            LONG    ?
        cbData                                  LONG    ?
        data                                    Byte    1 Dup(?)
    RemHGLOBAL EndS
ENDIF

IFNDEF RemHMETAFILEPICT
    RemHMETAFILEPICT Struct
        _mm                                     LONG    ?   ;mm
        xExt                                    LONG    ?
        yExt                                    LONG    ?
        cbData                                  LONG    ?
        data                                    Byte    1 Dup(?)
    RemHMETAFILEPICT EndS
ENDIF

IFNDEF RemHENHMETAFILE
    RemHENHMETAFILE Struct
        cbData                                  LONG    ?
        data                                    Byte    1 Dup(?)
    RemHENHMETAFILE EndS
ENDIF

IFNDEF RemHBITMAP
    RemHBITMAP Struct
        cbData                                  LONG    ?
        data                                    Byte    1 Dup(?)
    RemHBITMAP EndS
ENDIF

IFNDEF RemHPALETTE
    RemHPALETTE Struct
        cbData                                  LONG    ?
        data                                    Byte    1 Dup(?)
    RemHPALETTE EndS
ENDIF

IFNDEF RemHBRUSH
    RemHBRUSH Struct
        cbData                                  LONG    ?
        data                                    Byte    1 Dup(?)
    RemHBRUSH EndS
ENDIF

PALETTEENTRY Struct
    peRed                                   Byte    ?
    peGreen                                 Byte    ?
    peBlue                                  Byte    ?
    peFlags                                 Byte    ?
PALETTEENTRY EndS
PPALETTEENTRY                               TypeDef DWord
LPPALETTEENTRY                              Equ     <PPALETTEENTRY>

IFNDEF LOGPALETTE
    LOGPALETTE Struct
        palVersion                              Word        ?
        palNumEntries                           Word        ?
        palPalEntry                             PALETTEENTRY 1 Dup(<>)
    LOGPALETTE EndS
ENDIF
IFNDEF PLOGPALETTE
    PLOGPALETTE                                 TypeDef DWord
ENDIF
IFNDEF LPLOGPALETTE
    LPLOGPALETTE                                Equ     <PLOGPALETTE>
ENDIF

IFNDEF _COLORREF_DEFINED
    _COLORREF_DEFINED                       Equ     1
    COLORREF                                TypeDef DWord
ENDIF

IFNDEF _LPCOLORREF_DEFINED
    _LPCOLORREF_DEFINED                     Equ     1
    LPCOLORREF                              TypeDef DWord
ENDIF

IFNDEF LARGE_INTEGER
    LARGE_INTEGER UNION
        STRUCT
            LowPart                         DD      ?
            HighPart                        DD      ?
        ENDS
        QuadPart                            LONGLONG ?
    LARGE_INTEGER EndS
    ULARGE_INTEGER                          Equ     <LARGE_INTEGER>
    PLARGE_INTEGER                          TypeDef DWord
ENDIF

IFNDEF WINBASE_INC
    IFNDEF _FILETIME_
        _FILETIME_                          Equ     1
        FILETIME Struct
            dwLowDateTime                   DWord   ?
            dwHighDateTime                  DWord   ?
        FILETIME EndS
        PFILETIME                           TypeDef DWord
        LPFILETIME                          Equ     <PFILETIME>
    ENDIF
    IFNDEF _SYSTEMTIME_
        _SYSTEMTIME_                        Equ     1
        SYSTEMTIME Struct
            wYear                           Word    ?
            wMonth                          Word    ?
            wDayOfWeek                      Word    ?
            wDay                            Word    ?
            wHour                           Word    ?
            wMinute                         Word    ?
            wSecond                         Word    ?
            wMilliseconds                   Word    ?
        SYSTEMTIME EndS
        PSYSTEMTIME                         TypeDef DWord
        LPSYSTEMTIME                        Equ     <PSYSTEMTIME>
    ENDIF
    IFNDEF _SECURITY_ATTRIBUTES_
        _SECURITY_ATTRIBUTES_               Equ     1
        SECURITY_ATTRIBUTES Struct
            nLength                         DWord   ?
            lpSecurityDescriptor            LPVOID  ?
            bInheritHandle                  BOOL    ?
        SECURITY_ATTRIBUTES EndS
        PSECURITY_ATTRIBUTES                TypeDef DWord
        LPSECURITY_ATTRIBUTES               Equ     <PSECURITY_ATTRIBUTES>
    ENDIF
    IFNDEF SECURITY_DESCRIPTOR_REVISION
        SECURITY_DESCRIPTOR_CONTROL         TypeDef Word
        PSECURITY_DESCRIPTOR_CONTROL        TypeDef DWord
        PSID                                TypeDef DWord
        ACL Struct
            AclRevision                     UCHAR   ?
            Sbz1                            UCHAR   ?
            AclSize                         USHORT  ?
            AceCount                        USHORT  ?
            Sbz2                            USHORT  ?
        ACL EndS
        PACL                                TypeDef DWord
        
        SECURITY_DESCRIPTOR Struct
            Revision                        UCHAR   ?
            Sbz1                            UCHAR   ?
            Control                         SECURITY_DESCRIPTOR_CONTROL ?
            Owner                           PSID    ?
            _Group                          PSID    ?   ;Group
            Sacl                            PACL    ?
            Dacl                            PACL    ?
        SECURITY_DESCRIPTOR EndS
        PISECURITY_DESCRIPTOR               TypeDef DWord
    ENDIF ;SECURITY_DESCRIPTOR_REVISION
ENDIF ;_WINBASE_

COAUTHIDENTITY Struct
    User                                    PSHORT  ?
    UserLength                              ULONG   ?
    Domain                                  PSHORT  ?
    DomainLength                            ULONG   ?
    Password                                PSHORT  ?
    PasswordLength                          ULONG   ?
    Flags                                   ULONG   ?
COAUTHIDENTITY EndS

COAUTHINFO Struct
    dwAuthnSvc                              DWord   ?
    dwAuthzSvc                              DWord   ?
    pwszServerPrincName                     LPWSTR  ?
    dwAuthnLevel                            DWord   ?
    dwImpersonationLevel                    DWord   ?
    pAuthIdentityData                       DWord   ?
    dwCapabilities                          DWord   ?
COAUTHINFO EndS

IFNDEF _WCHAR_T_DEFINED
    _WCHAR_T_DEFINED                        Equ     1
    wchar_t                                 TypeDef Word
ENDIF

IFNDEF _HRESULT_DEFINED
    _HRESULT_DEFINED                        Equ     1
    HRESULT                                 TypeDef DWord
ENDIF
PSCODE                                      TypeDef DWord

IFNDEF GUID_DEFINED
    Include guiddef.inc
ENDIF

IFNDEF __OBJECTID_DEFINED
    __OBJECTID_DEFINED                      Equ     1
    _OBJECTID_DEFINED                       Equ     __OBJECTID_DEFINED
    IFNDEF OBJECTID
        OBJECTID Struct
            Lineage                             GUID    <>
            Uniquifier                          LONG    ?
        OBJECTID EndS
    ENDIF
ENDIF

IFNDEF __IID_DEFINED__ 
    __IID_DEFINED__                         Equ     1
    LPIID                                   TypeDef DWord
    LPCLSID                                 TypeDef DWord
    LPFMTID                                 TypeDef DWord
    REFGUID                                 TypeDef DWord
    REFIID                                  TypeDef DWord
    REFCLSID                                TypeDef DWord
    REFFMTID                                TypeDef DWord
ENDIF

;MEMCTX enumeration
MEMCTX                                      TypeDef DWord
MEMCTX_TASK                                 Equ     1
MEMCTX_SHARED                               Equ     2
MEMCTX_MACSYSTEM                            Equ     3
MEMCTX_UNKNOWN                              Equ     -1
MEMCTX_SAME                                 Equ     -2

IFNDEF _ROTFLAGS_DEFINED
    _ROTFLAGS_DEFINED                       Equ     1
    ROTFLAGS_REGISTRATIONKEEPSALIVE         Equ     01H
    ROTFLAGS_ALLOWANYCLIENT                 Equ     02H
ENDIF

IFNDEF _ROT_COMPARE_MAX_DEFINED
    _ROT_COMPARE_MAX_DEFINED                Equ     1
    ROT_COMPARE_MAX                         Equ     2048
ENDIF

;CLSCTX Enumeration
CLSCTX                                      TypeDef DWord
CLSCTX_INPROC_SERVER                        Equ     00000001H
CLSCTX_INPROC_HANDLER                       Equ     00000002H
CLSCTX_LOCAL_SERVER                         Equ     00000004H
CLSCTX_INPROC_SERVER16                      Equ     00000008H
CLSCTX_REMOTE_SERVER                        Equ     00000010H
CLSCTX_INPROC_HANDLER16                     Equ     00000020H
CLSCTX_INPROC_SERVERX86                     Equ     00000040H
CLSCTX_RESERVED1                            Equ     00000040H
CLSCTX_RESERVED2                            Equ     00000080H
CLSCTX_INPROC_HANDLERX86                    Equ     00000080H
CLSCTX_ESERVER_HANDLER                      Equ     00000100H
CLSCTX_RESERVED3                            Equ     00000100H
CLSCTX_RESERVED4                            Equ     00000200H
CLSCTX_NO_CODE_DOWNLOAD                     Equ     00000400H
CLSCTX_RESERVED5                            Equ     00000800H
CLSCTX_NO_CUSTOM_MARSHAL                    Equ     00001000H
CLSCTX_ENABLE_CODE_DOWNLOAD                 Equ     00002000H
CLSCTX_NO_FAILURE_LOG                       Equ     00004000H
CLSCTX_DISABLE_AAA                          Equ     00008000H
CLSCTX_ENABLE_AAA                           Equ     00010000H
CLSCTX_FROM_DEFAULT_CONTEXT                 Equ     00020000H
CLSCTX_ACTIVATE_32_BIT_SERVER               Equ     00040000H
CLSCTX_ACTIVATE_64_BIT_SERVER               Equ     00080000H
CLSCTX_ENABLE_CLOAKING                      Equ     00100000H
CLSCTX_APPCONTAINER                         Equ     00400000H
CLSCTX_ACTIVATE_AAA_AS_IU                   Equ     00800000H
CLSCTX_PS_DLL                               Equ     80000000H


;MSHLFLAGS enumeration
MSHLFLAGS                                   TypeDef DWord
MSHLFLAGS_NORMAL                            Equ     0
MSHLFLAGS_TABLESTRONG                       Equ     1
MSHLFLAGS_TABLEWEAK                         Equ     2
MSHLFLAGS_NOPING                            Equ     4

;MSHCTX Enumeration
MSHCTX                                      TypeDef DWord
MSHCTX_LOCAL                                Equ     0
MSHCTX_NOSHAREDMEM                          Equ     1
MSHCTX_DIFFERENTMACHINE                     Equ     2
MSHCTX_INPROC                               Equ     3

;DVASPECT Enumeration
DVASPECT                                    TypeDef DWord
DVASPECT_CONTENT                            Equ     1
DVASPECT_THUMBNAIL                          Equ     2
DVASPECT_ICON                               Equ     4
DVASPECT_DOCPRINT                           Equ     8

;STGC Enumeration
STGC                                        TypeDef DWord
STGC_DEFAULT                                Equ     0
STGC_OVERWRITE                              Equ     1
STGC_ONLYIFCURRENT                          Equ     2
STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE     Equ     4
STGC_CONSOLIDATE                            Equ     8

;STGMOVE Enumeration
STGMOVE                                     TypeDef DWord
STGMOVE_MOVE                                Equ     0
STGMOVE_COPY                                Equ     1
STGMOVE_SHALLOWCOPY                         Equ     2

;STATFLAG Enumeration
STATFLAG                                    TypeDef DWord
STATFLAG_DEFAULT                            Equ     0
STATFLAG_NONAME                             Equ     1
STATFLAG_NOOPEN                             Equ     2

IFNDEF BYTE_BLOB
    BYTE_BLOB Struct
        clSize                                  LONG    ?
        abData                                  Byte    1 Dup(?)
    BYTE_BLOB EndS
ENDIF

IFNDEF WORD_BLOB
    WORD_BLOB Struct
        clSize                                  LONG    ?
        asData                                  USHORT  1 Dup(?)
    WORD_BLOB EndS
ENDIF

IFNDEF DWORD_BLOB
    DWORD_BLOB Struct
        clSize                                  LONG    ?
        alData                                  LONG    1 Dup(?)
    DWORD_BLOB EndS
ENDIF

IFNDEF FLAGGED_BYTE_BLOB
    FLAGGED_BYTE_BLOB Struct
        fFlags                                  LONG    ?
        clSize                                  LONG    ?
        abData                                  Byte    1 Dup(?)
    FLAGGED_BYTE_BLOB EndS
ENDIF

IFNDEF FLAGGED_WORD_BLOB
    FLAGGED_WORD_BLOB Struct
        fFlags                                  LONG    ?
        clSize                                  LONG    ?
        asData                                  USHORT  1 Dup(?)
    FLAGGED_WORD_BLOB EndS
ENDIF

BYTE_SIZEDARR Struct
    clSize                                  LONG    ?
    pData                                   LPBYTE  ?
BYTE_SIZEDARR EndS

WORD_SIZEDARR Struct
    clSize                                  LONG    ?
    pData                                   LPWORD  ?
WORD_SIZEDARR EndS

DWORD_SIZEDARR Struct
    clSize                                  LONG    ?
    pData                                   LPLONG  ?
DWORD_SIZEDARR EndS

HYPER_SIZEDARR Struct
    clSize                                  LONG    ?
    pData                                   LPDWORD ?
HYPER_SIZEDARR EndS

WDT_INPROC_CALL                             Equ     (048746457H)
WDT_REMOTE_CALL                             Equ     (052746457H)

IFNDEF userCLIPFORMAT
    userCLIPFORMAT Struct
        fContext                                LONG    ?
        union u
            dwValue                             DWord   ?
            pwszName                            LPWORD  ?
        EndS
    userCLIPFORMAT EndS
ENDIF
IFNDEF wireCLIPFORMAT
    wireCLIPFORMAT                              TypeDef DWord
ENDIF
IFNDEF CLIPFORMAT
    CLIPFORMAT                                  TypeDef Word
ENDIF

IFNDEF GDI_NONREMOTE
    GDI_NONREMOTE Struct
        fContext                                LONG    ?
        union u
            hInproc                             LONG    ?
            hRemote                             DWord   ?
        EndS
    GDI_NONREMOTE EndS
ENDIF

IFNDEF userHGLOBAL
    userHGLOBAL Struct
        fContext                                LONG    ?
        union u
            hInproc                             LONG    ?
            hRemote                             DWord   ?
            hGlobal                             LONG    ?
        EndS
    userHGLOBAL EndS
ENDIF
IFNDEF wireHGLOBAL
    wireHGLOBAL                                 TypeDef DWord
ENDIF

IFNDEF userHMETAFILE
    userHMETAFILE Struct
        fContext                                DWord   ?
        union u
            hInproc                             LONG    ?
            hRemote                             DWord   ?
            hGlobal                             LONG    ?
        EndS
    userHMETAFILE EndS
ENDIF

IFNDEF remoteMETAFILEPICT
    remoteMETAFILEPICT Struct
        _mm                                     LONG    ?
        xExt                                    LONG    ?
        yExt                                    LONG    ?
        hMF                                     DWord   ?
    remoteMETAFILEPICT EndS
ENDIF

IFNDEF userHMETAFILEPICT
    userHMETAFILEPICT Struct
        fContext                                LONG    ?
        Union u
            hInproc                             LONG    ?
            hRemote                             DWord   ?
            hGlobal                             LONG    ?
        EndS
    userHMETAFILEPICT EndS
ENDIF

IFNDEF userHENHMETAFILE
    userHENHMETAFILE Struct
        fContext                                LONG    ?
        Union u
            hInproc                             LONG    ?
            hRemote                             DWord   ?
            hGlobal                             LONG    ?
        EndS
    userHENHMETAFILE EndS
ENDIF

IFNDEF userBITMAP
    userBITMAP Struct
        bmType                                  LONG    ?
        bmWidth                                 LONG    ?
        bmHeight                                LONG    ?
        bmWidthBytes                            LONG    ?
        bmPlanes                                Word    ?
        bmBitsPixel                             Word    ?
        cbSize                                  ULONG   ?
        pBuffer                                 LPBYTE  1 Dup(?)
    userBITMAP EndS
ENDIF

IFNDEF userHBITMAP
    userHBITMAP Struct
        fContext                                LONG    ?
        Union u
            hInproc                             LONG    ?
            hRemote                             DWord   ?
            hGlobal                             LONG    ?
        EndS
    userHBITMAP EndS
ENDIF

IFNDEF rpcLOGPALETTE
    rpcLOGPALETTE Struct
        palVersion                              Word    ?
        palNumEntries                           Word    ?
        palPalEntry                             PALETTEENTRY 1 Dup(<>)
    rpcLOGPALETTE EndS
ENDIF

IFNDEF userHPALETTE
    userHPALETTE Struct
        fContext                                LONG    ?
        Union u
            hInproc                             LONG    ?
            hRemote                             DWord   ?
            hGlobal                             LONG    ?
        EndS
    userHPALETTE EndS
ENDIF

IFNDEF RemotableHandle
    RemotableHandle Struct
        fContext                                LONG    ?
        Union u
            hInproc                             LONG    ?
            hRemote                             LONG    ?
        EndS
    RemotableHandle EndS
ENDIF

IFNDEF TEXTMETRICW
    TEXTMETRICW Struct
        tmHeight                            LONG    ?
        tmAscent                            LONG    ?
        tmDescent                           LONG    ?
        tmInternalLeading                   LONG    ?
        tmExternalLeading                   LONG    ?
        tmAveCharWidth                      LONG    ?
        tmMaxCharWidth                      LONG    ?
        tmWeight                            LONG    ?
        tmOverhang                          LONG    ?
        tmDigitizedAspectX                  LONG    ?
        tmDigitizedAspectY                  LONG    ?
        tmFirstChar                         WCHAR   ?
        tmLastChar                          WCHAR   ?
        tmDefaultChar                       WCHAR   ?
        tmBreakChar                         WCHAR   ?
        tmItalic                            Byte    ?
        tmUnderlined                        Byte    ?
        tmStruckOut                         Byte    ?
        tmPitchAndFamily                    Byte    ?
        tmCharSet                           Byte    ?
    TEXTMETRICW EndS
ENDIF

IFNDEF MSG
    MSG Struct
        hwnd                                HWND    ?
        message                             UINT    ?
        wParam                              WPARAM  ?
        lParam                              LPARAM  ?
        time                                DWord   ?
        pt                                  POINT   <>
    MSG EndS
    PMSG                                    TypeDef DWord
    NPMSG                                   Equ     <PMSG>
    LPMSG                                   Equ     <NPMSG>
ENDIF

wireHBITMAP                                 TypeDef DWord
wireHPALETTE                                TypeDef DWord
wireHENHMETAFILE                            TypeDef DWord
wireHMETAFILE                               TypeDef DWord
wireHMETAFILEPICT                           TypeDef DWord

DATE                                        TypeDef DOUBLE

IFNDEF _CY_DEFINED
    _CY_DEFINED                             Equ     1
    IFNDEF CY
        CY Struct
            Lo                                  LONG    ?
            Hi                                  LONG    ?
        CY  EndS
    ENDIF
    IFNDEF LPCY
        LPCY                                    TypeDef DWord
    ENDIF
ENDIF

DECIMAL Struct
    wReserved                               USHORT  ?
    scale                                   Byte    ?
    sign                                    Byte    ?
    Hi32                                    ULONG   ?
    Lo64                                    ULONGLONG ?
DECIMAL EndS
LPDECIMAL                                   TypeDef DWord

wireBSTR                                    TypeDef DWord
BSTR                                        TypeDef DWord
LPBSTR                                      TypeDef DWord
VARIANT_BOOL                                TypeDef Word

IFNDEF _tagBSTRBLOB_DEFINED
    _tagBSTRBLOB_DEFINED                    Equ     1
    IFNDEF BSTRBLOB
        BSTRBLOB Struct
            cbSize                              ULONG   ?
            pData                               LPBYTE  ?
        BSTRBLOB EndS
    ENDIF
    IFNDEF LPBSTRBLOB
        LPBSTRBLOB                              TypeDef DWord
    ENDIF
ENDIF

IFNDEF _BLOB_DEFINED
    _BLOB_DEFINED                           Equ     1
    _LPBLOB_DEFINED                         Equ     1
    IFNDEF BLOB
        BLOB Struct
            cbSize                              ULONG   ?
            pBlobData                           LPBYTE  ?
        BLOB EndS
    ENDIF
    IFNDEF LPBLOB
        LPBLOB                                  TypeDef DWord
    ENDIF
ENDIF

IFNDEF CLIPDATA
    CLIPDATA Struct
        cbSize                                  ULONG   ?
        ulClipFmt                               LONG    ?
        pClipData                               LPBYTE  ?
    CLIPDATA EndS
ENDIF

VARTYPE                                     TypeDef Word

;VARENUM Enumeration
VARENUM                                     TypeDef DWord
VT_EMPTY                                    Equ     0
VT_NULL                                     Equ     1
VT_I2                                       Equ     2
VT_I4                                       Equ     3
VT_R4                                       Equ     4
VT_R8                                       Equ     5
VT_CY                                       Equ     6
VT_DATE                                     Equ     7
VT_BSTR                                     Equ     8
VT_DISPATCH                                 Equ     9
VT_ERROR                                    Equ     10
VT_BOOL                                     Equ     11
VT_VARIANT                                  Equ     12
VT_UNKNOWN                                  Equ     13
VT_DECIMAL                                  Equ     14
VT_I1                                       Equ     16
VT_UI1                                      Equ     17
VT_UI2                                      Equ     18
VT_UI4                                      Equ     19
VT_I8                                       Equ     20
VT_UI8                                      Equ     21
VT_INT                                      Equ     22
VT_UINT                                     Equ     23
VT_VOID                                     Equ     24
VT_HRESULT                                  Equ     25
VT_PTR                                      Equ     26
VT_SAFEARRAY                                Equ     27
VT_CARRAY                                   Equ     28
VT_USERDEFINED                              Equ     29
VT_LPSTR                                    Equ     30
VT_LPWSTR                                   Equ     31
VT_RECORD                                   Equ     36
VT_FILETIME                                 Equ     64
VT_BLOB                                     Equ     65
VT_STREAM                                   Equ     66
VT_STORAGE                                  Equ     67
VT_STREAMED_OBJECT                          Equ     68
VT_STORED_OBJECT                            Equ     69
VT_BLOB_OBJECT                              Equ     70
VT_CF                                       Equ     71
VT_CLSID                                    Equ     72
VT_BSTR_BLOB                                Equ     0FFFH
VT_VECTOR                                   Equ     01000H
VT_ARRAY                                    Equ     02000H
VT_BYREF                                    Equ     04000H
VT_RESERVED                                 Equ     08000H
VT_ILLEGAL                                  Equ     0FFFFH
VT_ILLEGALMASKED                            Equ     0FFFH
VT_TYPEMASK                                 Equ     0FFFH
PROPID                                      TypeDef DWord

IFNDEF SID_IDENTIFIER_AUTHORITY_DEFINED
    SID_IDENTIFIER_AUTHORITY_DEFINED        Equ     1
    SID_IDENTIFIER_AUTHORITY Struct
        Value                               UCHAR   6 Dup(?)
    SID_IDENTIFIER_AUTHORITY EndS
    PSID_IDENTIFIER_AUTHORITY               TypeDef DWord
ENDIF

IFNDEF SID_DEFINED
    SID_DEFINED                             Equ     1
    IFNDEF SID
        SID Struct
            Revision                            BYTE    ?
            SubAuthorityCount                   BYTE    ?
            IdentifierAuthority                 SID_IDENTIFIER_AUTHORITY <>
            SubAuthority                        ULONG   1 Dup(?)
        SID EndS
    ENDIF
    IFNDEF PISID
        PISID                                   TypeDef DWord
    ENDIF
    IFNDEF LPSID
        LPSID                                   Equ     PISID
    ENDIF
ENDIF

IFNDEF APPID
    APPID                                       Equ     <GUID>
ENDIF

IFNDEF CSPLATFORM
    CSPLATFORM Struct
        dwPlatformId                            DWord   ?
        dwVersionHi                             DWord   ?
        dwVersionLo                             DWord   ?
        dwProcessorArch                         DWord   ?
    CSPLATFORM EndS
ENDIF

IFNDEF QUERYCONTEXT
    QUERYCONTEXT Struct
        dwContext                               DWord   ?
        Platform                                CSPLATFORM  <>
        Locale                                  LCID    ?
        dwVersionHi                             DWord   ?
        dwVersionLo                             DWord   ?
    QUERYCONTEXT EndS
ENDIF

;TYSPEC Enumeration
TYSPEC                                      TypeDef DWord
TYSPEC_CLSID                                Equ     0
TYSPEC_FILEEXT                              Equ     (TYSPEC_CLSID + 1)
TYSPEC_MIMETYPE                             Equ     (TYSPEC_FILEEXT + 1)
TYSPEC_PROGID                               Equ     (TYSPEC_MIMETYPE + 1)
TYSPEC_IID                                  Equ     (TYSPEC_PROGID + 1)
TYSPEC_TYPELIB                              Equ     (TYSPEC_IID + 1)
TYSPEC_FILENAME                             Equ     (TYSPEC_TYPELIB + 1)
TYSPEC_JAVACLASS                            Equ     (TYSPEC_FILENAME + 1)
TYSPEC_PACKAGENAME                          Equ     (TYSPEC_JAVACLASS + 1)

IFNDEF uCLSSPEC
    uCLSSPEC Struct
        tyspec                                  DWord   ?
        Union tagged_union
            clsid                               CLSID   <>
            iid                                 IID     <>
            typelibID                           GUID    <>
            pFileExt                            LPOLESTR ?
            pMimeType                           LPOLESTR ?
            pProgId                             LPOLESTR ?
            pFileName                           LPOLESTR ?
            pJavaClassName                      LPOLESTR ?
            pPackageName                        LPOLESTR ?
        EndS
    uCLSSPEC EndS
ENDIF

IFNDEF PUBLISHEDAPPINFO
    PUBLISHEDAPPINFO Struct
        pwszFileExtension                       LPOLESTR ?
        pwszDisplayName                         LPOLESTR ?
        pwszPackagePath                         LPOLESTR ?
    PUBLISHEDAPPINFO EndS
ENDIF

;APPINFOTYPE Enumeration
APPINFOTYPE                                 TypeDef DWord
APPINFO_PUBLISHED                           Equ     1
APPINFO_SHELLNEW                            Equ     (APPINFO_PUBLISHED + 1)
APPINFO_INSERTABLE                          Equ     (APPINFO_SHELLNEW + 1)

;CLASSPATHTYPE Enumeration
CLASSPATHTYPE                               TypeDef DWord
ExeNamePath                                 Equ     0
DllNamePath                                 Equ     (ExeNamePath + 1)
TlbNamePath                                 Equ     (DllNamePath + 1)
CabFilePath                                 Equ     (TlbNamePath + 1)
InfFilePath                                 Equ     (CabFilePath + 1)
DrwFilePath                                 Equ     (InfFilePath + 1)
SetupNamePath                               Equ     (DrwFilePath + 1)

IFNDEF APPDETAIL
    APPDETAIL Struct
        AppID                                   GUID    <>
        cClasses                                DWord   ?
        prgClsIdList                            LPCLSID ?
        cTypeLibIds                             DWord   ?
        prgTypeLibIdList                        LPCLSID ?
        cServers                                DWord   ?
        prgServerNames                          LPOLESTR ?
    APPDETAIL EndS
ENDIF

PACKAGEDETAIL Struct
    PathType                                CLASSPATHTYPE ?
    pszPath                                 LPOLESTR ?
    pszIconPath                             LPOLESTR ?
    pszSetupCommand                         LPOLESTR ?
    dwActFlags                              DWord   ?
    pszVendor                               LPOLESTR ?
    pszPackageName                          LPOLESTR ?
    pszProductName                          LPOLESTR ?
    dwContext                               DWord   ?
    Platform                                CSPLATFORM <>
    Locale                                  LCID    ?
    dwVersionHi                             DWord   ?
    dwVersionLo                             DWord   ?
    Usn                                     ULONGLONG ?
    cApps                                   DWord   ?
    pAppDetail                              DWord   ?
PACKAGEDETAIL EndS

PACKAGEINFO Struct
    pszClassIconPath                        LPOLESTR ?
    pTreatAsClsid                           LPCLSID ?
    cPackages                               DWord   ?
    pPackageDetail                          DWord   ?
PACKAGEINFO EndS

ENDIF ;WTYPES_INC
