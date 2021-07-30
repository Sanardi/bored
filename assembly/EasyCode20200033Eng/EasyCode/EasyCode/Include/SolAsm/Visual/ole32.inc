; ====================================================;
;                                                     ;
;     ole32.inc for EC v2 SolAsm visual projects      ;
;                   (version 1.0.2)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2019          ;
;                                                     ;
; ====================================================;

#ifndef OLE32_INC
OLE32_INC equ 1

E_DRAW                                                  equ     VIEW_E_DRAW

OLEIVERB_PRIMARY                                        equ     0
OLEIVERB_SHOW                                           equ     (-1)
OLEIVERB_OPEN                                           equ     (-2)
OLEIVERB_HIDE                                           equ     (-3)
OLEIVERB_UIACTIVATE                                     equ     (-4)
OLEIVERB_INPLACEACTIVATE                                equ     (-5)
OLEIVERB_DISCARDUNDOSTATE                               equ     (-6)

EMBDHLP_INPROC_HANDLER                                  equ     00000000H
EMBDHLP_INPROC_SERVER                                   equ     00000001H
EMBDHLP_CREATENOW                                       equ     00000000H
EMBDHLP_DELAYCREATE                                     equ     00010000H

OLECREATE_LEAVERUNNING                                  equ     00000001H

COINIT_MULTITHREADED                                    equ     0
COINIT_APARTMENTTHREADED                                equ     2
COINIT_DISABLE_OLE1DDE                                  equ     4
COINIT_SPEED_OVER_MEMORY                                equ     8

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib ole32.lib
#else
    from_dll ole32.dll
#endif

#ifdef APP_WIN64
    import BindMoniker
    import CLIPFORMAT_UserFree
    import CLIPFORMAT_UserMarshal
    import CLIPFORMAT_UserSize
    import CLIPFORMAT_UserUnmarshal
    import CLSIDFromOle1Class
    import CLSIDFromProgID
    import CLSIDFromProgIDEx
    import CLSIDFromString
    import CoAddRefServerProcess
    import CoAllowSetForegroundWindow
    import CoBuildVersion
    import CoCancelCall
    import CoCopyProxy
    import CoCreateFreeThreadedMarshaler
    import CoCreateGuid
    import CoCreateInstance
    import CoCreateInstanceEx
    #if NTDDI_VERSION >= NTDDI_WIN8
        #ifndef CoCreateInstanceFromApp
            import CoCreateInstanceFromApp
        #endif
    #endif
    import CoCreateObjectInContext
    import CoDeactivateObject
    #if NTDDI_VERSION >= NTDDI_WIN8
        import CoDecodeProxy
        import CoDecrementMTAUsage
    #endif
    import CoDisableCallCancellation
    #if NTDDI_VERSION >= NTDDI_VISTA
        import CoDisconnectContext
    #endif
    import CoDisconnectObject
    import CoDosDateTimeToFileTime
    import CoEnableCallCancellation
    import CoFileTimeNow
    import CoFileTimeToDosDateTime
    import CoFreeAllLibraries
    import CoFreeLibrary
    import CoFreeUnusedLibraries
    import CoFreeUnusedLibrariesEx
    #if NTDDI_VERSION >= NTDDI_VISTA
        import CoGetActivationState
    #endif
    import CoGetApartmentID
    #if NTDDI_VERSION >= NTDDI_WIN7
        import CoGetApartmentType
    #endif
    import CoGetCallContext
    import CoGetCallerTID
    #if NTDDI_VERSION >= NTDDI_VISTA
        import CoGetCallState
    #endif
    import CoGetCancelObject
    import CoGetClassObject
    import CoGetClassVersion
    import CoGetContextToken
    import CoGetCurrentLogicalThreadId
    import CoGetCurrentProcess
    import CoGetDefaultContext
    import CoGetInstanceFromFile
    import CoGetInstanceFromIStorage
    import CoGetInterceptor
    import CoGetInterceptorFromTypeInfo
    import CoGetInterfaceAndReleaseStream
    import CoGetMalloc
    import CoGetMarshalSizeMax
    import CoGetModuleType
    import CoGetObject
    import CoGetObjectContext
    import CoGetProcessIdentifier
    import CoGetPSClsid
    import CoGetStandardMarshal
    #if NTDDI_VERSION <= NTDDI_VISTA
        import CoGetState
    #endif
    import CoGetStdMarshalEx
    import CoGetSystemSecurityPermissions
    import CoGetTreatAsClass
    #if NTDDI_VERSION >= NTDDI_WIN8
        import CoHandlePriorityEventsFromMessagePump
    #endif
    import CoImpersonateClient
    #if NTDDI_VERSION >= NTDDI_WIN8
        import CoIncrementMTAUsage
    #endif
    import CoInitialize
    import CoInitializeEx
    import CoInitializeSecurity
    import CoInitializeWOW
    import CoInstall
    import CoInvalidateRemoteMachineBindings
    import CoIsHandlerConnected
    import CoIsOle1Class
    import CoLoadLibrary
    import CoLockObjectExternal
    import CoMarshalHresult
    import CoMarshalInterface
    import CoMarshalInterThreadInterfaceInStream
    import ComPs_NdrDllCanUnloadNow
    import ComPs_NdrDllGetClassObject
    import ComPs_NdrDllRegisterProxy
    import ComPs_NdrDllUnregisterProxy
    import CoQueryAuthenticationServices
    import CoQueryClientBlanket
    import CoQueryProxyBlanket
    import CoQueryReleaseObject
    import CoReactivateObject
    import CoRegisterChannelHook
    import CoRegisterClassObject
    import CoRegisterInitializeSpy
    import CoRegisterMallocSpy
    import CoRegisterMessageFilter
    import CoRegisterPSClsid
    import CoRegisterSurrogate
    import CoRegisterSurrogateEx
    import CoReleaseMarshalData
    import CoReleaseServerProcess
    import CoResumeClassObjects
    import CoRetireServer
    import CoRevertToSelf
    import CoRevokeClassObject
    import CoRevokeInitializeSpy
    import CoRevokeMallocSpy
    import CoSetCancelObject
    #if NTDDI_VERSION >= NTDDI_WIN8
        import CoSetMessageDispatcher
    #endif
    import CoSetProxyBlanket
    import CoSetState
    import CoSuspendClassObjects
    import CoSwitchCallContext
    import CoTaskMemAlloc
    import CoTaskMemFree
    import CoTaskMemRealloc
    import CoTestCancel
    import CoTreatAsClass
    import CoUninitialize
    import CoUnloadingWOW
    import CoUnmarshalHresult
    import CoUnmarshalInterface
    import CoWaitForMultipleHandles
    #if NTDDI_VERSION >= NTDDI_WIN8
        import CoWaitForMultipleObjects
    #endif
    import CreateAntiMoniker
    import CreateBindCtx
    import CreateClassMoniker
    import CreateDataAdviseHolder
    import CreateDataCache
    #ifndef CreateErrorInfo
        import CreateErrorInfo
    #endif
    import CreateFileMoniker
    import CreateGenericComposite
    import CreateILockBytesOnHGlobal
    import CreateItemMoniker
    import CreateObjrefMoniker
    import CreateOleAdviseHolder
    import CreatePointerMoniker
    import CreateStdProgressIndicator
    import CreateStreamOnHGlobal
    #if NTDDI_VERSION >= NTDDI_WIN10
        import CStdAsyncStubBuffer_AddRef
        import CStdAsyncStubBuffer_Connect
        import CStdAsyncStubBuffer_Disconnect
        import CStdAsyncStubBuffer_Invoke
        import CStdAsyncStubBuffer_QueryInterface
        import CStdAsyncStubBuffer_Release
        import CStdAsyncStubBuffer2_Connect
        import CStdAsyncStubBuffer2_Disconnect
        import CStdAsyncStubBuffer2_Release
        import CStdStubBuffer2_Connect
        import CStdStubBuffer2_CountRefs
        import CStdStubBuffer2_Disconnect
        import CStdStubBuffer2_QueryInterface
    #endif
    import DcomChannelSetHResult
    import DllDebugObjectRPCHook
    import DllGetClassObject
    import DllGetClassObjectWOW
    import DoDragDrop
    import EnableHookObject
    import FmtIdToPropStgName
    import FreePropVariantArray
    import GetClassFile
    import GetConvertStg
    import GetDocumentBitStg
    #ifndef GetErrorInfo
        import GetErrorInfo
    #endif
    import GetHGlobalFromILockBytes
    import GetHGlobalFromStream
    import GetHookInterface
    import GetRunningObjectTable
    import HACCEL_UserFree
    import HACCEL_UserMarshal
    import HACCEL_UserSize
    import HACCEL_UserUnmarshal
    import HBITMAP_UserFree
    import HBITMAP_UserMarshal
    import HBITMAP_UserSize
    import HBITMAP_UserUnmarshal
    import HBRUSH_UserFree
    import HBRUSH_UserMarshal
    import HBRUSH_UserSize
    import HBRUSH_UserUnmarshal
    import HDC_UserFree
    import HDC_UserMarshal
    import HDC_UserSize
    import HDC_UserUnmarshal
    import HENHMETAFILE_UserFree
    import HENHMETAFILE_UserMarshal
    import HENHMETAFILE_UserSize
    import HENHMETAFILE_UserUnmarshal
    import HGLOBAL_UserFree
    import HGLOBAL_UserMarshal
    import HGLOBAL_UserSize
    import HGLOBAL_UserUnmarshal
    import HICON_UserFree
    import HICON_UserMarshal
    import HICON_UserSize
    import HICON_UserUnmarshal
    import HkOleRegisterObject
    import HMENU_UserFree
    import HMENU_UserMarshal
    import HMENU_UserSize
    import HMENU_UserUnmarshal
    import HMETAFILE_UserFree
    import HMETAFILE_UserMarshal
    import HMETAFILE_UserSize
    import HMETAFILE_UserUnmarshal
    import HMETAFILEPICT_UserFree
    import HMETAFILEPICT_UserMarshal
    import HMETAFILEPICT_UserSize
    import HMETAFILEPICT_UserUnmarshal
    import HPALETTE_UserFree
    import HPALETTE_UserMarshal
    import HPALETTE_UserSize
    import HPALETTE_UserUnmarshal
    import HWND_UserFree
    import HWND_UserMarshal
    import HWND_UserSize
    import HWND_UserUnmarshal
    import IIDFromString
    import IsAccelerator
    import IsEqualGUID
    import IsValidIid
    import IsValidInterface
    import IsValidPtrIn
    import IsValidPtrOut
    import MkParseDisplayName
    import MonikerCommonPrefixWith
    import MonikerRelativePathTo
    #if NTDDI_VERSION >= NTDDI_WIN7
        import NdrOleInitializeExtension
    #endif
    import OleBuildVersion
    import OleConvertIStorageToOLESTREAM
    import OleConvertIStorageToOLESTREAMEx
    import OleConvertOLESTREAMToIStorage
    import OleConvertOLESTREAMToIStorageEx
    import OleCreate
    import OleCreateDefaultHandler
    import OleCreateEmbeddingHelper
    import OleCreateEx
    import OleCreateFromData
    import OleCreateFromDataEx
    import OleCreateFromFile
    import OleCreateFromFileEx
    import OleCreateLink
    import OleCreateLinkEx
    import OleCreateLinkFromData
    import OleCreateLinkFromDataEx
    import OleCreateLinkToFile
    import OleCreateLinkToFileEx
    import OleCreateMenuDescriptor
    import OleCreateStaticFromData
    import OleDestroyMenuDescriptor
    import OleDoAutoConvert
    import OleDraw
    import OleDuplicateData
    import OleFlushClipboard
    import OleGetAutoConvert
    import OleGetClipboard
    import OleGetIconOfClass
    import OleGetIconOfFile
    import OleInitialize
    import OleInitializeWOW
    import OleIsCurrentClipboard
    import OleIsRunning
    import OleLoad
    import OleLoadFromStream
    import OleLockRunning
    import OleMetafilePictFromIconAndLabel
    import OleNoteObjectVisible
    import OleQueryCreateFromData
    import OleQueryLinkFromData
    import OleRegEnumFormatEtc
    import OleRegEnumVerbs
    import OleRegGetMiscStatus
    import OleRegGetUserType
    import OleRun
    import OleSave
    import OleSaveToStream
    import OleSetAutoConvert
    import OleSetClipboard
    import OleSetContainedObject
    import OleSetMenuDescriptor
    import OleTranslateAccelerator
    import OleUninitialize
    import OpenOrCreateStream
    import ProgIDFromCLSID
    import PropStgNameToFmtId
    import PropSysAllocString
    import PropSysFreeString
    import PropVariantChangeType
    import PropVariantClear
    import PropVariantCopy
    import ReadClassStg
    import ReadClassStm
    import ReadFmtUserTypeStg
    import ReadOleStg
    import ReadStringStream
    import RegisterDragDrop
    import ReleaseStgMedium
    import RevokeDragDrop
    #if NTDDI_VERSION >= NTDDI_WIN10
        import RoGetAgileReference
    #endif
    import SetConvertStg
    import SetDocumentBitStg
    #ifndef SetErrorInfo
        import SetErrorInfo
    #endif
    import SNB_UserFree
    import SNB_UserMarshal
    import SNB_UserSize
    import SNB_UserUnmarshal
    import StgConvertPropertyToVariant
    import StgConvertVariantToProperty
    import StgCreateDocfile
    import StgCreateDocfileOnILockBytes
    import StgCreatePropSetStg
    import StgCreatePropStg
    import StgCreateStorageEx
    import StgGetIFillLockBytesOnFile
    import StgGetIFillLockBytesOnILockBytes
    import StgIsStorageFile
    import StgIsStorageILockBytes
    import STGMEDIUM_UserFree
    import STGMEDIUM_UserFree64
    import STGMEDIUM_UserMarshal
    import STGMEDIUM_UserMarshal64
    import STGMEDIUM_UserSize
    import STGMEDIUM_UserSize64
    import STGMEDIUM_UserUnmarshal
    import STGMEDIUM_UserUnmarshal64
    import StgOpenAsyncDocfileOnIFillLockBytes
    import StgOpenPropStg
    import StgOpenStorage
    import StgOpenStorageEx
    import StgOpenStorageOnILockBytes
    import StgPropertyLengthAsVariant
    import StgSetTimes
    import StringFromCLSID
    import StringFromGUID2
    import StringFromIID
    import UpdateDCOMSettings
    import UtConvertDvtd16toDvtd32
    import UtConvertDvtd32toDvtd16
    import UtGetDvtd16Info
    import UtGetDvtd32Info
    import WdtpInterfacePointer_UserFree
    import WdtpInterfacePointer_UserMarshal
    import WdtpInterfacePointer_UserSize
    import WdtpInterfacePointer_UserUnmarshal
    import WriteClassStg
    import WriteClassStm
    import WriteFmtUserTypeStg
    import WriteOleStg
    import WriteStringStream
#else
    extern CloseODBCPerfData alias _CloseODBCPerfData@0
    extern CollectODBCPerfData alias _CollectODBCPerfData@16
    extern CursorLibLockDbc alias _CursorLibLockDbc@8
    extern CursorLibLockDesc alias _CursorLibLockDesc@8
    extern CursorLibLockStmt alias _CursorLibLockStmt@8
    extern CursorLibTransact alias _CursorLibTransact@12
    extern DllBidEntryPoint alias _DllBidEntryPoint@36
    extern GetODBCSharedData alias _GetODBCSharedData@0
    extern LockHandle alias _LockHandle@12
    extern ODBCGetTryWaitValue alias _ODBCGetTryWaitValue@0
    extern ODBCInternalConnectW alias _ODBCInternalConnectW@36
    extern ODBCQualifyFileDSNW alias _ODBCQualifyFileDSNW@4
    extern ODBCSetTryWaitValue alias _ODBCSetTryWaitValue@4
    extern OpenODBCPerfData alias _OpenODBCPerfData@4
    extern PostComponentError alias _PostComponentError@4
    extern PostODBCComponentError alias _PostODBCComponentError@4
    extern PostODBCError alias _PostODBCError@16
    extern SQLAllocConnect alias _SQLAllocConnect@8
    extern SQLAllocEnv alias _SQLAllocEnv@4
    extern SQLAllocHandle alias _SQLAllocHandle@12
    extern SQLAllocHandleStd alias _SQLAllocHandleStd@12
    extern SQLAllocStmt alias _SQLAllocStmt@8
    extern SQLBindCol alias _SQLBindCol@24
    extern SQLBindParam alias _SQLBindParam@32
    extern SQLBindParameter alias _SQLBindParameter@40
    extern SQLBrowseConnectA alias _SQLBrowseConnectA@24
    extern SQLBrowseConnectW alias _SQLBrowseConnectW@24
    extern SQLBulkOperations alias _SQLBulkOperations@8
    extern SQLCancel alias _SQLCancel@4
    #if NTDDI_VERSION >= NTDDI_WIN7
        extern SQLCancelHandle alias _SQLCancelHandle@8
    #endif
    extern SQLCloseCursor alias _SQLCloseCursor@4
    extern SQLColAttributeA alias _SQLColAttributeA@28
    extern SQLColAttributeW alias _SQLColAttributeW@28
    extern SQLColAttributesA alias _SQLColAttributesA@28
    extern SQLColAttributesW alias _SQLColAttributesW@28
    extern SQLColumnPrivilegesA alias _SQLColumnPrivilegesA@36
    extern SQLColumnPrivilegesW alias _SQLColumnPrivilegesW@36
    extern SQLColumnsA alias _SQLColumnsA@36
    extern SQLColumnsW alias _SQLColumnsW@36
    #if NTDDI_VERSION >= NTDDI_WIN8
        extern SQLCompleteAsync alias _SQLCompleteAsync2 @12
    #endif
    ;extern SQLConnectA alias _SQLConnectA@36
    ;extern SQLConnectW alias _SQLConnectW@36
    extern SQLCopyDesc alias _SQLCopyDesc@8
    extern SQLDataSourcesA alias _SQLDataSourcesA@32
    extern SQLDataSourcesW alias _SQLDataSourcesW@32
    extern SQLDescribeColA alias _SQLDescribeColA@36
    extern SQLDescribeColW alias _SQLDescribeColW@36
    extern SQLDescribeParam alias _SQLDescribeParam@24
    extern SQLDisconnect alias _SQLDisconnect@4
    extern SQLDriverConnectA alias _SQLDriverConnectA@32
    extern SQLDriverConnectW alias _SQLDriverConnectW@32
    extern SQLDriversA alias _SQLDriversA@32
    extern SQLDriversW alias _SQLDriversW@32
    extern SQLEndTran alias _SQLEndTran@12
    extern SQLErrorA alias _SQLErrorA@32
    extern SQLErrorW alias _SQLErrorW@32
    extern SQLExecDirectA alias _SQLExecDirectA@12
    extern SQLExecDirectW alias _SQLExecDirectW@12
    extern SQLExecute alias _SQLExecute@4
    extern SQLExtendedFetch alias _SQLExtendedFetch@20
    extern SQLFetch alias _SQLFetch@4
    extern SQLFetchScroll alias _SQLFetchScroll@12
    extern SQLForeignKeysA alias _SQLForeignKeysA@52
    extern SQLForeignKeysW alias _SQLForeignKeysW@52
    extern SQLFreeConnect alias _SQLFreeConnect@4
    extern SQLFreeEnv alias _SQLFreeEnv@4
    extern SQLFreeHandle alias _SQLFreeHandle@8
    extern SQLFreeStmt alias _SQLFreeStmt@8
    extern SQLGetConnectAttrA alias _SQLGetConnectAttrA@20
    extern SQLGetConnectAttrW alias _SQLGetConnectAttrW@20
    extern SQLGetConnectOptionA alias _SQLGetConnectOptionA@12
    extern SQLGetConnectOptionW alias _SQLGetConnectOptionW@12
    extern SQLGetCursorNameA alias _SQLGetCursorNameA@16
    extern SQLGetCursorNameW alias _SQLGetCursorNameW@16
    extern SQLGetData alias _SQLGetData@24
    extern SQLGetDescFieldA alias _SQLGetDescFieldA@24
    extern SQLGetDescFieldW alias _SQLGetDescFieldW@24
    extern SQLGetDescRecA alias _SQLGetDescRecA@44
    extern SQLGetDescRecW alias _SQLGetDescRecW@44
    extern SQLGetDiagFieldA alias _SQLGetDiagFieldA@28
    extern SQLGetDiagFieldW alias _SQLGetDiagFieldW@28
    extern SQLGetDiagRecA alias _SQLGetDiagRecA@32
    extern SQLGetDiagRecW alias _SQLGetDiagRecW@32
    extern SQLGetEnvAttr alias _SQLGetEnvAttr@20
    extern SQLGetFunctions alias _SQLGetFunctions@12
    extern SQLGetInfoA alias _SQLGetInfoA@20
    extern SQLGetInfoW alias _SQLGetInfoW@20
    extern SQLGetStmtAttrA alias _SQLGetStmtAttrA@20
    extern SQLGetStmtAttrW alias _SQLGetStmtAttrW@20
    extern SQLGetStmtOption alias _SQLGetStmtOption@12
    extern SQLGetTypeInfoA alias _SQLGetTypeInfoA@8
    extern SQLGetTypeInfoW alias _SQLGetTypeInfoW@8
    extern SQLMoreResults alias _SQLMoreResults@4
    extern SQLNativeSqlA alias _SQLNativeSqlA@24
    extern SQLNativeSqlW alias _SQLNativeSqlW@24
    extern SQLNumParams alias _SQLNumParams@8
    extern SQLNumResultCols alias _SQLNumResultCols@8
    extern SQLParamData alias _SQLParamData@8
    extern SQLParamOptions alias _SQLParamOptions@12
    extern SQLPrepareA alias _SQLPrepareA@12
    extern SQLPrepareW alias _SQLPrepareW@12
    extern SQLPrimaryKeysA alias _SQLPrimaryKeysA@28
    extern SQLPrimaryKeysW alias _SQLPrimaryKeysW@28
    extern SQLProcedureColumnsA alias _SQLProcedureColumnsA@36
    extern SQLProcedureColumnsW alias _SQLProcedureColumnsW@36
    extern SQLProceduresA alias _SQLProceduresA@28
    extern SQLProceduresW alias _SQLProceduresW@28
    extern SQLPutData alias _SQLPutData@12
    extern SQLRowCount alias _SQLRowCount@8
    extern SQLSetConnectAttrA alias _SQLSetConnectAttrA@16
    extern SQLSetConnectAttrW alias _SQLSetConnectAttrW@16
    extern SQLSetConnectOptionA alias _SQLSetConnectOptionA@12
    extern SQLSetConnectOptionW alias _SQLSetConnectOptionW@12
    extern SQLSetCursorNameA alias _SQLSetCursorNameA@12
    extern SQLSetCursorNameW alias _SQLSetCursorNameW@12
    extern SQLSetDescFieldA alias _SQLSetDescFieldA@20
    extern SQLSetDescFieldW alias _SQLSetDescFieldW@20
    extern SQLSetDescRec alias _SQLSetDescRec@40
    extern SQLSetEnvAttr alias _SQLSetEnvAttr@16
    extern SQLSetParam alias _SQLSetParam@32
    extern SQLSetPos alias _SQLSetPos@16
    extern SQLSetScrollOptions alias _SQLSetScrollOptions@16
    extern SQLSetStmtAttrA alias _SQLSetStmtAttrA@16
    extern SQLSetStmtAttrW alias _SQLSetStmtAttrW@16
    extern SQLSetStmtOption alias _SQLSetStmtOption@12
    extern SQLSpecialColumnsA alias _SQLSpecialColumnsA@40
    extern SQLSpecialColumnsW alias _SQLSpecialColumnsW@40
    extern SQLStatisticsA alias _SQLStatisticsA@36
    extern SQLStatisticsW alias _SQLStatisticsW@36
    extern SQLTablePrivilegesA alias _SQLTablePrivilegesA@28
    extern SQLTablePrivilegesW alias _SQLTablePrivilegesW@28
    extern SQLTablesA alias _SQLTablesA@36
    extern SQLTablesW alias _SQLTablesW@36
    extern SQLTransact alias _SQLTransact@12
    extern SearchStatusCode alias _SearchStatusCode@8
    extern VFreeErrors alias _VFreeErrors@4
    extern VRetrieveDriverErrorsRowCol alias _VRetrieveDriverErrorsRowCol@24
    extern ValidateErrorQueue alias _ValidateErrorQueue@8
#endif

;======================= Undocumented functions (unknown arguments) =======================;
;#ifdef APP_WIN64
;    import CheckInitDde
;    import CleanROTForApartment
;    import ClipboardProcessUninitialize
;    import CLIPFORMAT_UserFree64
;    import CLIPFORMAT_UserFreeExt
;    import CLIPFORMAT_UserMarshal64
;    import CLIPFORMAT_UserMarshalExt
;    import CLIPFORMAT_UserSize64
;    import CLIPFORMAT_UserSizeExt
;    import CLIPFORMAT_UserUnmarshal64
;    import CLIPFORMAT_UserUnmarshalExt
;    import CoAicGetTokenForCOM
;    import CoAllowUnmarshalerCLSID
;    import CoCheckElevationEnabled
;    import CoGetComCatalog
;    import CoGetInterceptorForOle32
;    import CoGetSystemWow64DirectoryW
;    import CoPopServiceDomain
;    import CoPushServiceDomain
;    import CoRegisterActivationFilter
;    import CoVrfCheckThreadState
;    import CoVrfGetThreadState
;    import CoVrfReleaseThreadState
;    import DdeBindToObject
;    import DeletePatternAndExtensionTables
;    import DestroyRunningObjectTable
;    import DllRegisterServer
;    import DragDropSetFDT
;    import FindExt
;    import GetActiveObjectExt
;    import GetObjectFromRotByPath
;    import HACCEL_UserFree64
;    import HACCEL_UserMarshal64
;    import HACCEL_UserSize64
;    import HACCEL_UserUnmarshal64
;    import HBITMAP_UserFree64
;    import HBITMAP_UserMarshal64
;    import HBITMAP_UserSize64
;    import HBITMAP_UserUnmarshal64
;    import HBRUSH_UserFree64
;    import HBRUSH_UserMarshal64
;    import HBRUSH_UserSize64
;    import HBRUSH_UserUnmarshal64
;    import HDC_UserFree64
;    import HDC_UserMarshal64
;    import HDC_UserSize64
;    import HDC_UserUnmarshal64
;    import HENHMETAFILE_UserFree64
;    import HENHMETAFILE_UserMarshal64
;    import HENHMETAFILE_UserSize64
;    import HENHMETAFILE_UserUnmarshal64
;    import HGLOBAL_UserFree64
;    import HGLOBAL_UserMarshal64
;    import HGLOBAL_UserSize64
;    import HGLOBAL_UserUnmarshal64
;    import HICON_UserFree64
;    import HICON_UserMarshal64
;    import HICON_UserSize64
;    import HICON_UserUnmarshal64
;    import HMENU_UserFree64
;    import HMENU_UserMarshal64
;    import HMENU_UserSize64
;    import HMENU_UserUnmarshal64
;    import HMETAFILE_UserFree64
;    import HMETAFILE_UserMarshal64
;    import HMETAFILE_UserSize64
;    import HMETAFILE_UserUnmarshal64
;    import HMETAFILEPICT_UserFree64
;    import HMETAFILEPICT_UserMarshal64
;    import HMETAFILEPICT_UserSize64
;    import HMETAFILEPICT_UserUnmarshal64
;    import HMONITOR_UserFree
;    import HMONITOR_UserFree64
;    import HMONITOR_UserMarshal
;    import HMONITOR_UserMarshal64
;    import HMONITOR_UserSize
;    import HMONITOR_UserSize64
;    import HMONITOR_UserUnmarshal
;    import HMONITOR_UserUnmarshal64
;    import HPALETTE_UserFree64
;    import HPALETTE_UserFreeExt
;    import HPALETTE_UserMarshal64
;    import HPALETTE_UserMarshalExt
;    import HPALETTE_UserSize64
;    import HPALETTE_UserSizeExt
;    import HPALETTE_UserUnmarshal64
;    import HPALETTE_UserUnmarshalExt
;    import HRGN_UserFree
;    import HRGN_UserMarshal
;    import HRGN_UserSize
;    import HRGN_UserUnmarshal
;    import HWND_UserFree64
;    import HWND_UserFree64Ext
;    import HWND_UserFreeExt
;    import HWND_UserMarshal64
;    import HWND_UserMarshal64Ext
;    import HWND_UserMarshalExt
;    import HWND_UserSize64
;    import HWND_UserSize64Ext
;    import HWND_UserSizeExt
;    import HWND_UserUnmarshal64
;    import HWND_UserUnmarshal64Ext
;    import HWND_UserUnmarshalExt
;    import IsRoInitializeASTAAllowedInDesktop
;    import MonikerLoadTypeLib
;    import NdrProxyForwardingFunction10
;    import NdrProxyForwardingFunction11
;    import NdrProxyForwardingFunction12
;    import NdrProxyForwardingFunction13
;    import NdrProxyForwardingFunction14
;    import NdrProxyForwardingFunction15
;    import NdrProxyForwardingFunction16
;    import NdrProxyForwardingFunction17
;    import NdrProxyForwardingFunction18
;    import NdrProxyForwardingFunction19
;    import NdrProxyForwardingFunction20
;    import NdrProxyForwardingFunction21
;    import NdrProxyForwardingFunction22
;    import NdrProxyForwardingFunction23
;    import NdrProxyForwardingFunction24
;    import NdrProxyForwardingFunction25
;    import NdrProxyForwardingFunction26
;    import NdrProxyForwardingFunction27
;    import NdrProxyForwardingFunction28
;    import NdrProxyForwardingFunction29
;    import NdrProxyForwardingFunction3
;    import NdrProxyForwardingFunction30
;    import NdrProxyForwardingFunction31
;    import NdrProxyForwardingFunction32
;    import NdrProxyForwardingFunction4
;    import NdrProxyForwardingFunction5
;    import NdrProxyForwardingFunction6
;    import NdrProxyForwardingFunction7
;    import NdrProxyForwardingFunction8
;    import NdrProxyForwardingFunction9
;    import ObjectStublessClient10
;    import ObjectStublessClient11
;    import ObjectStublessClient12
;    import ObjectStublessClient13
;    import ObjectStublessClient14
;    import ObjectStublessClient15
;    import ObjectStublessClient16
;    import ObjectStublessClient17
;    import ObjectStublessClient18
;    import ObjectStublessClient19
;    import ObjectStublessClient20
;    import ObjectStublessClient21
;    import ObjectStublessClient22
;    import ObjectStublessClient23
;    import ObjectStublessClient24
;    import ObjectStublessClient25
;    import ObjectStublessClient26
;    import ObjectStublessClient27
;    import ObjectStublessClient28
;    import ObjectStublessClient29
;    import ObjectStublessClient3
;    import ObjectStublessClient30
;    import ObjectStublessClient31
;    import ObjectStublessClient32
;    import ObjectStublessClient4
;    import ObjectStublessClient5
;    import ObjectStublessClient6
;    import ObjectStublessClient7
;    import ObjectStublessClient8
;    import ObjectStublessClient9
;    import OleCreateFontIndirectExt
;    import OleCreatePictureIndirectExt
;    import OleCreatePropertyFrameIndirectExt
;    import OleGetPackageClipboardOwner
;    import OleIconToCursorExt
;    import OleLoadPictureExt
;    import OleLoadPictureFileExt
;    import OleLoadPicturePathExt
;    import OleReleaseEnumVerbCache
;    import OleSavePictureFileExt
;    import OleTranslateColorExt
;    import ReadStorageProperties
;    import RegisterActiveObjectExt
;    import RevokeActiveObjectExt
;    import SetOleautModule
;    import SetWOWThunkGlobalPtr
;    import SNB_UserFree64
;    import SNB_UserMarshal64
;    import SNB_UserSize64
;    import SNB_UserUnmarshal64
;    import StdTypesGetClassObject
;    import StdTypesRegisterServer
;    import STGMEDIUM_UserFreeExt
;    import STGMEDIUM_UserMarshalExt
;    import STGMEDIUM_UserSizeExt
;    import STGMEDIUM_UserUnmarshalExt
;    import StgOpenStorageOnHandle
;    import UpdateProcessTracing
;    import WdtpInterfacePointer_UserFree64
;    import WdtpInterfacePointer_UserMarshal64
;    import WdtpInterfacePointer_UserSize64
;    import WdtpInterfacePointer_UserUnmarshal64
;    import WriteStorageProperties
;#else
;    extern CheckInitDde alias _CheckInitDde@??
;    extern CleanROTForApartment alias _CleanROTForApartment@??
;    extern ClipboardProcessUninitialize alias _ClipboardProcessUninitialize@??
;    extern CLIPFORMAT_UserFree64 alias _CLIPFORMAT_UserFree64@??
;    extern CLIPFORMAT_UserFreeExt alias _CLIPFORMAT_UserFreeExt@??
;    extern CLIPFORMAT_UserMarshal64 alias _CLIPFORMAT_UserMarshal64@??
;    extern CLIPFORMAT_UserMarshalExt alias _CLIPFORMAT_UserMarshalExt@??
;    extern CLIPFORMAT_UserSize64 alias _CLIPFORMAT_UserSize64@??
;    extern CLIPFORMAT_UserSizeExt alias _CLIPFORMAT_UserSizeExt@??
;    extern CLIPFORMAT_UserUnmarshal64 alias _CLIPFORMAT_UserUnmarshal64@??
;    extern CLIPFORMAT_UserUnmarshalExt alias _CLIPFORMAT_UserUnmarshalExt@??
;    extern CoAicGetTokenForCOM alias _CoAicGetTokenForCOM@??
;    extern CoAllowUnmarshalerCLSID alias _CoAllowUnmarshalerCLSID@??
;    extern CoCheckElevationEnabled alias _CoCheckElevationEnabled@??
;    extern CoGetComCatalog alias _CoGetComCatalog@??
;    extern CoGetInterceptorForOle32 alias _CoGetInterceptorForOle32@??
;    extern CoGetSystemWow64DirectoryW alias _CoGetSystemWow64DirectoryW@??
;    extern CoPopServiceDomain alias _CoPopServiceDomain@??
;    extern CoPushServiceDomain alias _CoPushServiceDomain@??
;    extern CoRegisterActivationFilter alias _CoRegisterActivationFilter@??
;    extern CoVrfCheckThreadState alias _CoVrfCheckThreadState@??
;    extern CoVrfGetThreadState alias _CoVrfGetThreadState@??
;    extern CoVrfReleaseThreadState alias _CoVrfReleaseThreadState@??
;    extern DdeBindToObject alias _DdeBindToObject@??
;    extern DeletePatternAndExtensionTables alias _DeletePatternAndExtensionTables@??
;    extern DestroyRunningObjectTable alias _DestroyRunningObjectTable@??
;    extern DllRegisterServer alias _DllRegisterServer@??
;    extern DragDropSetFDT alias _DragDropSetFDT@??
;    extern FindExt alias _FindExt@??
;    extern GetActiveObjectExt alias _GetActiveObjectExt@??
;    extern GetObjectFromRotByPath alias _GetObjectFromRotByPath@??
;    extern HACCEL_UserFree64 alias _HACCEL_UserFree64@??
;    extern HACCEL_UserMarshal64 alias _HACCEL_UserMarshal64@??
;    extern HACCEL_UserSize64 alias _HACCEL_UserSize64@??
;    extern HACCEL_UserUnmarshal64 alias _HACCEL_UserUnmarshal64@??
;    extern HBITMAP_UserFree64 alias _HBITMAP_UserFree64@??
;    extern HBITMAP_UserMarshal64 alias _HBITMAP_UserMarshal64@??
;    extern HBITMAP_UserSize64 alias _HBITMAP_UserSize64@??
;    extern HBITMAP_UserUnmarshal64 alias _HBITMAP_UserUnmarshal64@??
;    extern HBRUSH_UserFree64 alias _HBRUSH_UserFree64@??
;    extern HBRUSH_UserMarshal64 alias _HBRUSH_UserMarshal64@??
;    extern HBRUSH_UserSize64 alias _HBRUSH_UserSize64@??
;    extern HBRUSH_UserUnmarshal64 alias _HBRUSH_UserUnmarshal64@??
;    extern HDC_UserFree64 alias _HDC_UserFree64@??
;    extern HDC_UserMarshal64 alias _HDC_UserMarshal64@??
;    extern HDC_UserSize64 alias _HDC_UserSize64@??
;    extern HDC_UserUnmarshal64 alias _HDC_UserUnmarshal64@??
;    extern HENHMETAFILE_UserFree64 alias _HENHMETAFILE_UserFree64@??
;    extern HENHMETAFILE_UserMarshal64 alias _HENHMETAFILE_UserMarshal64@??
;    extern HENHMETAFILE_UserSize64 alias _HENHMETAFILE_UserSize64@??
;    extern HENHMETAFILE_UserUnmarshal64 alias _HENHMETAFILE_UserUnmarshal64@??
;    extern HGLOBAL_UserFree64 alias _HGLOBAL_UserFree64@??
;    extern HGLOBAL_UserMarshal64 alias _HGLOBAL_UserMarshal64@??
;    extern HGLOBAL_UserSize64 alias _HGLOBAL_UserSize64@??
;    extern HGLOBAL_UserUnmarshal64 alias _HGLOBAL_UserUnmarshal64@??
;    extern HICON_UserFree64 alias _HICON_UserFree64@??
;    extern HICON_UserMarshal64 alias _HICON_UserMarshal64@??
;    extern HICON_UserSize64 alias _HICON_UserSize64@??
;    extern HICON_UserUnmarshal64 alias _HICON_UserUnmarshal64@??
;    extern HMENU_UserFree64 alias _HMENU_UserFree64@??
;    extern HMENU_UserMarshal64 alias _HMENU_UserMarshal64@??
;    extern HMENU_UserSize64 alias _HMENU_UserSize64@??
;    extern HMENU_UserUnmarshal64 alias _HMENU_UserUnmarshal64@??
;    extern HMETAFILE_UserFree64 alias _HMETAFILE_UserFree64@??
;    extern HMETAFILE_UserMarshal64 alias _HMETAFILE_UserMarshal64@??
;    extern HMETAFILE_UserSize64 alias _HMETAFILE_UserSize64@??
;    extern HMETAFILE_UserUnmarshal64 alias _HMETAFILE_UserUnmarshal64@??
;    extern HMETAFILEPICT_UserFree64 alias _HMETAFILEPICT_UserFree64@??
;    extern HMETAFILEPICT_UserMarshal64 alias _HMETAFILEPICT_UserMarshal64@??
;    extern HMETAFILEPICT_UserSize64 alias _HMETAFILEPICT_UserSize64@??
;    extern HMETAFILEPICT_UserUnmarshal64 alias _HMETAFILEPICT_UserUnmarshal64@??
;    extern HMONITOR_UserFree alias _HMONITOR_UserFree@??
;    extern HMONITOR_UserFree64 alias _HMONITOR_UserFree64@??
;    extern HMONITOR_UserMarshal alias _HMONITOR_UserMarshal@??
;    extern HMONITOR_UserMarshal64 alias _HMONITOR_UserMarshal64@??
;    extern HMONITOR_UserSize alias _HMONITOR_UserSize@??
;    extern HMONITOR_UserSize64 alias _HMONITOR_UserSize64@??
;    extern HMONITOR_UserUnmarshal alias _HMONITOR_UserUnmarshal@??
;    extern HMONITOR_UserUnmarshal64 alias _HMONITOR_UserUnmarshal64@??
;    extern HPALETTE_UserFree64 alias _HPALETTE_UserFree64@??
;    extern HPALETTE_UserFreeExt alias _HPALETTE_UserFreeExt@??
;    extern HPALETTE_UserMarshal64 alias _HPALETTE_UserMarshal64@??
;    extern HPALETTE_UserMarshalExt alias _HPALETTE_UserMarshalExt@??
;    extern HPALETTE_UserSize64 alias _HPALETTE_UserSize64@??
;    extern HPALETTE_UserSizeExt alias _HPALETTE_UserSizeExt@??
;    extern HPALETTE_UserUnmarshal64 alias _HPALETTE_UserUnmarshal64@??
;    extern HPALETTE_UserUnmarshalExt alias _HPALETTE_UserUnmarshalExt@??
;    extern HRGN_UserFree alias _HRGN_UserFree@??
;    extern HRGN_UserMarshal alias _HRGN_UserMarshal@??
;    extern HRGN_UserSize alias _HRGN_UserSize@??
;    extern HRGN_UserUnmarshal alias _HRGN_UserUnmarshal@??
;    extern HWND_UserFree64 alias _HWND_UserFree64@??
;    extern HWND_UserFree64Ext alias _HWND_UserFree64Ext@??
;    extern HWND_UserFreeExt alias _HWND_UserFreeExt@??
;    extern HWND_UserMarshal64 alias _HWND_UserMarshal64@??
;    extern HWND_UserMarshal64Ext alias _HWND_UserMarshal64Ext@??
;    extern HWND_UserMarshalExt alias _HWND_UserMarshalExt@??
;    extern HWND_UserSize64 alias _HWND_UserSize64@??
;    extern HWND_UserSize64Ext alias _HWND_UserSize64Ext@??
;    extern HWND_UserSizeExt alias _HWND_UserSizeExt@??
;    extern HWND_UserUnmarshal64 alias _HWND_UserUnmarshal64@??
;    extern HWND_UserUnmarshal64Ext alias _HWND_UserUnmarshal64Ext@??
;    extern HWND_UserUnmarshalExt alias _HWND_UserUnmarshalExt@??
;    extern IsRoInitializeASTAAllowedInDesktop alias _IsRoInitializeASTAAllowedInDesktop@??
;    extern MonikerLoadTypeLib alias _MonikerLoadTypeLib@??
;    extern NdrProxyForwardingFunction10 alias _NdrProxyForwardingFunction10@??
;    extern NdrProxyForwardingFunction11 alias _NdrProxyForwardingFunction11@??
;    extern NdrProxyForwardingFunction12 alias _NdrProxyForwardingFunction12@??
;    extern NdrProxyForwardingFunction13 alias _NdrProxyForwardingFunction13@??
;    extern NdrProxyForwardingFunction14 alias _NdrProxyForwardingFunction14@??
;    extern NdrProxyForwardingFunction15 alias _NdrProxyForwardingFunction15@??
;    extern NdrProxyForwardingFunction16 alias _NdrProxyForwardingFunction16@??
;    extern NdrProxyForwardingFunction17 alias _NdrProxyForwardingFunction17@??
;    extern NdrProxyForwardingFunction18 alias _NdrProxyForwardingFunction18@??
;    extern NdrProxyForwardingFunction19 alias _NdrProxyForwardingFunction19@??
;    extern NdrProxyForwardingFunction20 alias _NdrProxyForwardingFunction20@??
;    extern NdrProxyForwardingFunction21 alias _NdrProxyForwardingFunction21@??
;    extern NdrProxyForwardingFunction22 alias _NdrProxyForwardingFunction22@??
;    extern NdrProxyForwardingFunction23 alias _NdrProxyForwardingFunction23@??
;    extern NdrProxyForwardingFunction24 alias _NdrProxyForwardingFunction24@??
;    extern NdrProxyForwardingFunction25 alias _NdrProxyForwardingFunction25@??
;    extern NdrProxyForwardingFunction26 alias _NdrProxyForwardingFunction26@??
;    extern NdrProxyForwardingFunction27 alias _NdrProxyForwardingFunction27@??
;    extern NdrProxyForwardingFunction28 alias _NdrProxyForwardingFunction28@??
;    extern NdrProxyForwardingFunction29 alias _NdrProxyForwardingFunction29@??
;    extern NdrProxyForwardingFunction3 alias _NdrProxyForwardingFunction3@??
;    extern NdrProxyForwardingFunction30 alias _NdrProxyForwardingFunction30@??
;    extern NdrProxyForwardingFunction31 alias _NdrProxyForwardingFunction31@??
;    extern NdrProxyForwardingFunction32 alias _NdrProxyForwardingFunction32@??
;    extern NdrProxyForwardingFunction4 alias _NdrProxyForwardingFunction4@??
;    extern NdrProxyForwardingFunction5 alias _NdrProxyForwardingFunction5@??
;    extern NdrProxyForwardingFunction6 alias _NdrProxyForwardingFunction6@??
;    extern NdrProxyForwardingFunction7 alias _NdrProxyForwardingFunction7@??
;    extern NdrProxyForwardingFunction8 alias _NdrProxyForwardingFunction8@??
;    extern NdrProxyForwardingFunction9 alias _NdrProxyForwardingFunction9@??
;    extern ObjectStublessClient10 alias _ObjectStublessClient10@??
;    extern ObjectStublessClient11 alias _ObjectStublessClient11@??
;    extern ObjectStublessClient12 alias _ObjectStublessClient12@??
;    extern ObjectStublessClient13 alias _ObjectStublessClient13@??
;    extern ObjectStublessClient14 alias _ObjectStublessClient14@??
;    extern ObjectStublessClient15 alias _ObjectStublessClient15@??
;    extern ObjectStublessClient16 alias _ObjectStublessClient16@??
;    extern ObjectStublessClient17 alias _ObjectStublessClient17@??
;    extern ObjectStublessClient18 alias _ObjectStublessClient18@??
;    extern ObjectStublessClient19 alias _ObjectStublessClient19@??
;    extern ObjectStublessClient20 alias _ObjectStublessClient20@??
;    extern ObjectStublessClient21 alias _ObjectStublessClient21@??
;    extern ObjectStublessClient22 alias _ObjectStublessClient22@??
;    extern ObjectStublessClient23 alias _ObjectStublessClient23@??
;    extern ObjectStublessClient24 alias _ObjectStublessClient24@??
;    extern ObjectStublessClient25 alias _ObjectStublessClient25@??
;    extern ObjectStublessClient26 alias _ObjectStublessClient26@??
;    extern ObjectStublessClient27 alias _ObjectStublessClient27@??
;    extern ObjectStublessClient28 alias _ObjectStublessClient28@??
;    extern ObjectStublessClient29 alias _ObjectStublessClient29@??
;    extern ObjectStublessClient3 alias _ObjectStublessClient3@??
;    extern ObjectStublessClient30 alias _ObjectStublessClient30@??
;    extern ObjectStublessClient31 alias _ObjectStublessClient31@??
;    extern ObjectStublessClient32 alias _ObjectStublessClient32@??
;    extern ObjectStublessClient4 alias _ObjectStublessClient4@??
;    extern ObjectStublessClient5 alias _ObjectStublessClient5@??
;    extern ObjectStublessClient6 alias _ObjectStublessClient6@??
;    extern ObjectStublessClient7 alias _ObjectStublessClient7@??
;    extern ObjectStublessClient8 alias _ObjectStublessClient8@??
;    extern ObjectStublessClient9 alias _ObjectStublessClient9@??
;    extern OleCreateFontIndirectExt alias _OleCreateFontIndirectExt@??
;    extern OleCreatePictureIndirectExt alias _OleCreatePictureIndirectExt@??
;    extern OleCreatePropertyFrameIndirectExt alias _OleCreatePropertyFrameIndirectExt@??
;    extern OleGetPackageClipboardOwner alias _OleGetPackageClipboardOwner@??
;    extern OleIconToCursorExt alias _OleIconToCursorExt@??
;    extern OleLoadPictureExt alias _OleLoadPictureExt@??
;    extern OleLoadPictureFileExt alias _OleLoadPictureFileExt@??
;    extern OleLoadPicturePathExt alias _OleLoadPicturePathExt@??
;    extern OleReleaseEnumVerbCache alias _OleReleaseEnumVerbCache@??
;    extern OleSavePictureFileExt alias _OleSavePictureFileExt@??
;    extern OleTranslateColorExt alias _OleTranslateColorExt@??
;    extern ReadStorageProperties alias _ReadStorageProperties@??
;    extern RegisterActiveObjectExt alias _RegisterActiveObjectExt@??
;    extern RevokeActiveObjectExt alias _RevokeActiveObjectExt@??
;    extern SetOleautModule alias _SetOleautModule@??
;    extern SetWOWThunkGlobalPtr alias _SetWOWThunkGlobalPtr@??
;    extern SNB_UserFree64 alias _SNB_UserFree64@??
;    extern SNB_UserMarshal64 alias _SNB_UserMarshal64@??
;    extern SNB_UserSize64 alias _SNB_UserSize64@??
;    extern SNB_UserUnmarshal64 alias _SNB_UserUnmarshal64@??
;    extern StdTypesGetClassObject alias _StdTypesGetClassObject@??
;    extern StdTypesRegisterServer alias _StdTypesRegisterServer@??
;    extern STGMEDIUM_UserFreeExt alias _STGMEDIUM_UserFreeExt@??
;    extern STGMEDIUM_UserMarshalExt alias _STGMEDIUM_UserMarshalExt@??
;    extern STGMEDIUM_UserSizeExt alias _STGMEDIUM_UserSizeExt@??
;    extern STGMEDIUM_UserUnmarshalExt alias _STGMEDIUM_UserUnmarshalExt@??
;    extern StgOpenStorageOnHandle alias _StgOpenStorageOnHandle@??
;    extern UpdateProcessTracing alias _UpdateProcessTracing@??
;    extern WdtpInterfacePointer_UserFree64 alias _WdtpInterfacePointer_UserFree64@??
;    extern WdtpInterfacePointer_UserMarshal64 alias _WdtpInterfacePointer_UserMarshal64@??
;    extern WdtpInterfacePointer_UserSize64 alias _WdtpInterfacePointer_UserSize64@??
;    extern WdtpInterfacePointer_UserUnmarshal64 alias _WdtpInterfacePointer_UserUnmarshal64@??
;    extern WriteStorageProperties alias _WriteStorageProperties@??
;#endif

#endif ;OLE32_INC
