;======================================================;
;                                                      ;
;   ole32.inc for Easy Code 2.0 64-bit Masm projects   ;
;                   (version 1.0.2)                    ;
;                                                      ;
;              Copyright © Ramon Sala 2018             ;
;                                                      ;
;======================================================;

IFNDEF OLE32_INC
OLE32_INC       EQU        1

E_DRAW                                                  EQU     VIEW_E_DRAW

OLEIVERB_PRIMARY                                        EQU     0
OLEIVERB_SHOW                                           EQU     (-1)
OLEIVERB_OPEN                                           EQU     (-2)
OLEIVERB_HIDE                                           EQU     (-3)
OLEIVERB_UIACTIVATE                                     EQU     (-4)
OLEIVERB_INPLACEACTIVATE                                EQU     (-5)
OLEIVERB_DISCARDUNDOSTATE                               EQU     (-6)

EMBDHLP_INPROC_HANDLER                                  EQU     00000000H
EMBDHLP_INPROC_SERVER                                   EQU     00000001H
EMBDHLP_CREATENOW                                       EQU     00000000H
EMBDHLP_DELAYCREATE                                     EQU     00010000H

OLECREATE_LEAVERUNNING                                  EQU     00000001H

COINIT_MULTITHREADED                                    EQU     0
COINIT_APARTMENTTHREADED                                EQU     2
COINIT_DISABLE_OLE1DDE                                  EQU     4
COINIT_SPEED_OVER_MEMORY                                EQU     8


;======================================== Structures ======================================;
DRAG_FLAVORINFO STRUCT ALIGNMODE
    cfFormat    DD ?
    FlavorFlags DD ?
    fAddData    DD ?
    reserved    DD ?
DRAG_FLAVORINFO ENDS

OleMBarRec STRUCT ALIGNMODE
    reserved DD ?
OleMBarRec ENDS

OLESTREAMVTBL STRUCT ALIGNMODE
    Get    XPTR ?
    Put    XPTR ?
OLESTREAMVTBL ENDS

OLESTREAM STRUCT ALIGNMODE
    lpstbl XPTR ?
OLESTREAM ENDS


;======================================== Functions =======================================;
BindMoniker PROTO :XWORD, :XWORD, :XWORD, :XWORD
CLIPFORMAT_UserFree PROTO :XWORD, :XWORD
CLIPFORMAT_UserMarshal PROTO :XWORD, :XWORD, :XWORD
CLIPFORMAT_UserSize PROTO :XWORD, :XWORD, :XWORD
CLIPFORMAT_UserUnmarshal PROTO :XWORD, :XWORD, :XWORD
CLSIDFromOle1Class PROTO :XWORD, :XWORD, :XWORD
CLSIDFromProgID PROTO :XWORD, :XWORD
CLSIDFromProgIDEx PROTO :XWORD, :XWORD
CLSIDFromString PROTO :XWORD, :XWORD
CoAddRefServerProcess PROTO
CoAllowSetForegroundWindow PROTO :XWORD, :XWORD
CoBuildVersion PROTO
CoCancelCall PROTO :XWORD, :XWORD
CoCopyProxy PROTO :XWORD, :XWORD
CoCreateFreeThreadedMarshaler PROTO :XWORD, :XWORD
CoCreateGuid PROTO :XWORD
CoCreateInstance PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CoCreateInstanceEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN8)
    IFNDEF CoCreateInstanceFromApp
        CoCreateInstanceFromApp PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ENDIF
ENDIF
CoCreateObjectInContext PROTO :XWORD, :XWORD, :XWORD, :XWORD
CoDeactivateObject PROTO :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN8)
    CoDecodeProxy PROTO :XWORD, :UINT64, :XPTR
    CoDecrementMTAUsage PROTO :PVOID
ENDIF
CoDisableCallCancellation PROTO :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    CoDisconnectContext PROTO :XWORD
ENDIF
CoDisconnectObject PROTO :XWORD, :XWORD
CoDosDateTimeToFileTime PROTO :XWORD, :XWORD, :XWORD
CoEnableCallCancellation PROTO :XWORD
CoFileTimeNow PROTO :XWORD
CoFileTimeToDosDateTime PROTO :XWORD, :XWORD, :XWORD
CoFreeAllLibraries PROTO
CoFreeLibrary PROTO :XWORD
CoFreeUnusedLibraries PROTO
CoFreeUnusedLibrariesEx PROTO :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    CoGetActivationState PROTO :XPTR, :XPTR
ENDIF
CoGetApartmentID PROTO :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN7)
    CoGetApartmentType PROTO :XPTR, :XPTR
ENDIF
CoGetCallContext PROTO :XWORD, :XWORD
CoGetCallerTID PROTO :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    CoGetCallState PROTO :XWORD, :XWORD
ENDIF
CoGetCancelObject PROTO :XWORD, :XWORD, :XWORD
CoGetClassObject PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CoGetClassVersion PROTO :XWORD, :XWORD, :XWORD
CoGetContextToken PROTO :XWORD
CoGetCurrentLogicalThreadId PROTO :XWORD
CoGetCurrentProcess PROTO
CoGetDefaultContext PROTO :XWORD, :XWORD, :XWORD
CoGetInstanceFromFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CoGetInstanceFromIStorage PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CoGetInterceptor PROTO :XWORD, :XWORD, :XWORD, :XWORD
CoGetInterceptorFromTypeInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CoGetInterfaceAndReleaseStream PROTO :XWORD, :XWORD, :XWORD
CoGetMalloc PROTO :XWORD, :XWORD
CoGetMarshalSizeMax PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CoGetModuleType PROTO :XPTR, :XPTR
CoGetObject PROTO :XWORD, :XWORD, :XWORD, :XWORD
CoGetObjectContext PROTO :XWORD, :XWORD
CoGetProcessIdentifier PROTO :XWORD
CoGetPSClsid PROTO :XWORD, :XWORD
CoGetStandardMarshal PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION LE NTDDI_VISTA)
    CoGetState PROTO :XWORD
ENDIF
CoGetStdMarshalEx PROTO :XWORD, :XWORD, :XWORD
CoGetSystemSecurityPermissions PROTO :XWORD, :XWORD
CoGetTreatAsClass PROTO :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN8)
    CoHandlePriorityEventsFromMessagePump PROTO
ENDIF
CoImpersonateClient PROTO
IF (NTDDI_VERSION GE NTDDI_WIN8)
    CoIncrementMTAUsage PROTO :PVOID
ENDIF
CoInitialize PROTO :XWORD
CoInitializeEx PROTO :XWORD, :XWORD
CoInitializeSecurity PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CoInitializeWOW PROTO :XWORD, :XWORD
CoInstall PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CoInvalidateRemoteMachineBindings PROTO :XWORD
CoIsHandlerConnected PROTO :XWORD
CoIsOle1Class PROTO :XWORD
CoLoadLibrary PROTO :XWORD, :XWORD
CoLockObjectExternal PROTO :XWORD, :XWORD, :XWORD
CoMarshalHresult PROTO :XWORD, :XWORD
CoMarshalInterface PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CoMarshalInterThreadInterfaceInStream PROTO :XWORD, :XWORD, :XWORD
ComPs_NdrDllCanUnloadNow PROTO :XWORD
ComPs_NdrDllGetClassObject PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ComPs_NdrDllRegisterProxy PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ComPs_NdrDllUnregisterProxy PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CoQueryAuthenticationServices PROTO :XWORD, :XWORD
CoQueryClientBlanket PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CoQueryProxyBlanket PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CoQueryReleaseObject PROTO :XWORD
CoReactivateObject PROTO :XWORD, :XWORD
CoRegisterChannelHook PROTO :XWORD, :XWORD
CoRegisterClassObject PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CoRegisterInitializeSpy PROTO :XWORD, :XWORD
CoRegisterMallocSpy PROTO :XWORD
CoRegisterMessageFilter PROTO :XWORD, :XWORD
CoRegisterPSClsid PROTO :XWORD, :XWORD
CoRegisterSurrogate PROTO :XWORD
CoRegisterSurrogateEx PROTO :XWORD, :XWORD
CoReleaseMarshalData PROTO :XWORD
CoReleaseServerProcess PROTO
CoResumeClassObjects PROTO
CoRetireServer PROTO :XWORD
CoRevertToSelf PROTO
CoRevokeClassObject PROTO :XWORD
CoRevokeInitializeSpy PROTO :XWORD, :XWORD
CoRevokeMallocSpy PROTO
CoSetCancelObject PROTO :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN8)
    CoSetMessageDispatcher PROTO :XPTR
ENDIF
CoSetProxyBlanket PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CoSetState PROTO :XWORD
CoSuspendClassObjects PROTO
CoSwitchCallContext PROTO :XWORD, :XWORD
CoTaskMemAlloc PROTO :XWORD
CoTaskMemFree PROTO :XWORD
CoTaskMemRealloc PROTO :XWORD, :XWORD
CoTestCancel PROTO
CoTreatAsClass PROTO :XWORD, :XWORD
CoUninitialize PROTO
CoUnloadingWOW PROTO :XWORD
CoUnmarshalHresult PROTO :XWORD, :XWORD
CoUnmarshalInterface PROTO :XWORD, :XWORD, :XWORD
CoWaitForMultipleHandles PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN8)
    CoWaitForMultipleObjects PROTO :XWORD, :XWORD, :ULONG, :LPHANDLE, :LPDWORD
ENDIF
CreateAntiMoniker PROTO :XWORD
CreateBindCtx PROTO :XWORD, :XWORD
CreateClassMoniker PROTO :XWORD, :XWORD
CreateDataAdviseHolder PROTO :XWORD
CreateDataCache PROTO :XWORD, :XWORD, :XWORD, :XWORD
IFNDEF CreateErrorInfo
    CreateErrorInfo PROTO :XPTR
ENDIF
CreateFileMoniker PROTO :XWORD, :XWORD
CreateGenericComposite PROTO :XWORD, :XWORD, :XWORD
CreateILockBytesOnHGlobal PROTO :XWORD, :XWORD, :XWORD
CreateItemMoniker PROTO :XWORD, :XWORD, :XWORD
CreateObjrefMoniker PROTO :XWORD, :XWORD
CreateOleAdviseHolder PROTO :XWORD
CreatePointerMoniker PROTO :XWORD, :XWORD
CreateStdProgressIndicator PROTO :XWORD, :XWORD, :XWORD, :XWORD
CreateStreamOnHGlobal PROTO :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN10)
    CStdAsyncStubBuffer_AddRef PROTO :XPTR
    CStdAsyncStubBuffer_Connect PROTO :XPTR, :XPTR
    CStdAsyncStubBuffer_Disconnect PROTO :XPTR
    CStdAsyncStubBuffer_Invoke PROTO :XPTR, :XPTR, :XPTR
    CStdAsyncStubBuffer_QueryInterface PROTO :XPTR, :XWORD, :XPTR
    CStdAsyncStubBuffer_Release PROTO :XPTR
    CStdAsyncStubBuffer2_Connect PROTO :XPTR, :XPTR
    CStdAsyncStubBuffer2_Disconnect PROTO :XPTR
    CStdAsyncStubBuffer2_Release PROTO :XPTR
    CStdStubBuffer2_Connect PROTO :XPTR, :XPTR
    CStdStubBuffer2_CountRefs PROTO :XPTR
    CStdStubBuffer2_Disconnect PROTO :XPTR
    CStdStubBuffer2_QueryInterface PROTO :XPTR, :XWORD, :XPTR
ENDIF
DcomChannelSetHResult PROTO :XWORD, :XWORD, :XWORD
DllDebugObjectRPCHook PROTO :XWORD, :XWORD
DllGetClassObject PROTO :XWORD, :XWORD, :XPTR
DllGetClassObjectWOW PROTO :XWORD, :XWORD, :XWORD
DoDragDrop PROTO :XWORD, :XWORD, :XWORD, :XWORD
EnableHookObject PROTO :XWORD, :XWORD
FmtIdToPropStgName PROTO :XWORD, :XWORD
FreePropVariantArray PROTO :XWORD, :XWORD
GetClassFile PROTO :XWORD, :XWORD
GetConvertStg PROTO :XWORD
GetDocumentBitStg PROTO :XWORD
IFNDEF GetErrorInfo
    GetErrorInfo PROTO :XWORD, :XPTR
ENDIF
GetHGlobalFromILockBytes PROTO :XWORD, :XWORD
GetHGlobalFromStream PROTO :XWORD, :XWORD
GetHookInterface PROTO :XWORD
GetRunningObjectTable PROTO :XWORD, :XWORD
HACCEL_UserFree PROTO :XWORD, :XWORD
HACCEL_UserMarshal PROTO :XWORD, :XWORD, :XWORD
HACCEL_UserSize PROTO :XWORD, :XWORD, :XWORD
HACCEL_UserUnmarshal PROTO :XWORD, :XWORD, :XWORD
HBITMAP_UserFree PROTO :XWORD, :XWORD
HBITMAP_UserMarshal PROTO :XWORD, :XWORD, :XWORD
HBITMAP_UserSize PROTO :XWORD, :XWORD, :XWORD
HBITMAP_UserUnmarshal PROTO :XWORD, :XWORD, :XWORD
HBRUSH_UserFree PROTO :XWORD, :XWORD
HBRUSH_UserMarshal PROTO :XWORD, :XWORD, :XWORD
HBRUSH_UserSize PROTO :XWORD, :XWORD, :XWORD
HBRUSH_UserUnmarshal PROTO :XWORD, :XWORD, :XWORD
HDC_UserFree PROTO :XWORD, :XWORD
HDC_UserMarshal PROTO :XWORD, :XWORD, :XWORD
HDC_UserSize PROTO :XWORD, :XWORD, :XWORD
HDC_UserUnmarshal PROTO :XWORD, :XWORD, :XWORD
HENHMETAFILE_UserFree PROTO :XWORD, :XWORD
HENHMETAFILE_UserMarshal PROTO :XWORD, :XWORD, :XWORD
HENHMETAFILE_UserSize PROTO :XWORD, :XWORD, :XWORD
HENHMETAFILE_UserUnmarshal PROTO :XWORD, :XWORD, :XWORD
HGLOBAL_UserFree PROTO :XWORD, :XWORD
HGLOBAL_UserMarshal PROTO :XWORD, :XWORD, :XWORD
HGLOBAL_UserSize PROTO :XWORD, :XWORD, :XWORD
HGLOBAL_UserUnmarshal PROTO :XWORD, :XWORD, :XWORD
HICON_UserFree PROTO :XWORD, :XWORD
HICON_UserMarshal PROTO :XWORD, :XWORD, :XWORD
HICON_UserSize PROTO :XWORD, :XWORD, :XWORD
HICON_UserUnmarshal PROTO :XWORD, :XWORD, :XWORD
HkOleRegisterObject PROTO :XWORD, :XWORD, :XWORD, :XWORD
HMENU_UserFree PROTO :XWORD, :XWORD
HMENU_UserMarshal PROTO :XWORD, :XWORD, :XWORD
HMENU_UserSize PROTO :XWORD, :XWORD, :XWORD
HMENU_UserUnmarshal PROTO :XWORD, :XWORD, :XWORD
HMETAFILE_UserFree PROTO :XWORD, :XWORD
HMETAFILE_UserMarshal PROTO :XWORD, :XWORD, :XWORD
HMETAFILE_UserSize PROTO :XWORD, :XWORD, :XWORD
HMETAFILE_UserUnmarshal PROTO :XWORD, :XWORD, :XWORD
HMETAFILEPICT_UserFree PROTO :XWORD, :XWORD
HMETAFILEPICT_UserMarshal PROTO :XWORD, :XWORD, :XWORD
HMETAFILEPICT_UserSize PROTO :XWORD, :XWORD, :XWORD
HMETAFILEPICT_UserUnmarshal PROTO :XWORD, :XWORD, :XWORD
HPALETTE_UserFree PROTO :XWORD, :XWORD
HPALETTE_UserMarshal PROTO :XWORD, :XWORD, :XWORD
HPALETTE_UserSize PROTO :XWORD, :XWORD, :XWORD
HPALETTE_UserUnmarshal PROTO :XWORD, :XWORD, :XWORD
HWND_UserFree PROTO :XWORD, :XWORD
HWND_UserMarshal PROTO :XWORD, :XWORD, :XWORD
HWND_UserSize PROTO :XWORD, :XWORD, :XWORD
HWND_UserUnmarshal PROTO :XWORD, :XWORD, :XWORD
IIDFromString PROTO :XWORD, :XWORD
IsAccelerator PROTO :XWORD, :XWORD, :XWORD, :XWORD
IsEqualGUID PROTO :XWORD, :XWORD
IsValidIid PROTO :XWORD
IsValidInterface PROTO :XWORD
IsValidPtrIn PROTO :XWORD, :XWORD
IsValidPtrOut PROTO :XWORD, :XWORD
MkParseDisplayName PROTO :XWORD, :XWORD, :XWORD, :XWORD
MonikerCommonPrefixWith PROTO :XWORD, :XWORD, :XWORD
MonikerRelativePathTo PROTO :XWORD, :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN7)
    NdrOleInitializeExtension PROTO :XWORD, :XWORD
ENDIF
OleBuildVersion PROTO
OleConvertIStorageToOLESTREAM PROTO :XWORD, :XWORD
OleConvertIStorageToOLESTREAMEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleConvertOLESTREAMToIStorage PROTO :XWORD, :XWORD, :XWORD
OleConvertOLESTREAMToIStorageEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleCreate PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleCreateDefaultHandler PROTO :XWORD, :XWORD, :XWORD, :XWORD
OleCreateEmbeddingHelper PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleCreateEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleCreateFromData PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleCreateFromDataEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleCreateFromFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleCreateFromFileEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleCreateLink PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleCreateLinkEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleCreateLinkFromData PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleCreateLinkFromDataEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleCreateLinkToFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleCreateLinkToFileEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleCreateMenuDescriptor PROTO :XWORD, :XWORD
OleCreateStaticFromData PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleDestroyMenuDescriptor PROTO :XWORD
OleDoAutoConvert PROTO :XWORD, :XWORD
OleDraw PROTO :XWORD, :XWORD, :XWORD, :XWORD
OleDuplicateData PROTO :XWORD, :XWORD, :XWORD
OleFlushClipboard PROTO
OleGetAutoConvert PROTO :XWORD, :XWORD
OleGetClipboard PROTO :XWORD
OleGetIconOfClass PROTO :XWORD, :XWORD, :XWORD
OleGetIconOfFile PROTO :XWORD, :XWORD
OleInitialize PROTO :XWORD
OleInitializeWOW PROTO :XWORD, :XWORD
OleIsCurrentClipboard PROTO :XWORD
OleIsRunning PROTO :XWORD
OleLoad PROTO :XWORD, :XWORD, :XWORD, :XWORD
OleLoadFromStream PROTO :XWORD, :XWORD, :XWORD
OleLockRunning PROTO :XWORD, :XWORD, :XWORD
OleMetafilePictFromIconAndLabel PROTO :XWORD, :XWORD, :XWORD, :XWORD
OleNoteObjectVisible PROTO :XWORD, :XWORD
OleQueryCreateFromData PROTO :XWORD
OleQueryLinkFromData PROTO :XWORD
OleRegEnumFormatEtc PROTO :XWORD, :XWORD, :XWORD
OleRegEnumVerbs PROTO :XWORD, :XWORD
OleRegGetMiscStatus PROTO :XWORD, :XWORD, :XWORD
OleRegGetUserType PROTO :XWORD, :XWORD, :XWORD
OleRun PROTO :XWORD
OleSave PROTO :XWORD, :XWORD, :XWORD
OleSaveToStream PROTO :XWORD, :XWORD
OleSetAutoConvert PROTO :XWORD, :XWORD
OleSetClipboard PROTO :XWORD
OleSetContainedObject PROTO :XWORD, :XWORD
OleSetMenuDescriptor PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
OleTranslateAccelerator PROTO :XWORD, :XWORD, :XWORD
OleUninitialize PROTO
OpenOrCreateStream PROTO :XWORD, :XWORD, :XWORD
ProgIDFromCLSID PROTO :XWORD, :XWORD
PropStgNameToFmtId PROTO :XWORD, :XWORD
PropSysAllocString PROTO :XWORD
PropSysFreeString PROTO :XWORD
PropVariantChangeType PROTO :XPTR, :XWORD, :XWORD, :XWORD
PropVariantClear PROTO :XWORD
PropVariantCopy PROTO :XWORD, :XWORD
ReadClassStg PROTO :XWORD, :XWORD
ReadClassStm PROTO :XWORD, :XWORD
ReadFmtUserTypeStg PROTO :XWORD, :XWORD, :XWORD
ReadOleStg PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ReadStringStream PROTO :XWORD, :XWORD
RegisterDragDrop PROTO :XWORD, :XWORD
ReleaseStgMedium PROTO :XWORD
RevokeDragDrop PROTO :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN10)
    RoGetAgileReference PROTO :XWORD, :XWORD, :XPTR, :XPTR
ENDIF
SetConvertStg PROTO :XWORD, :XWORD
SetDocumentBitStg PROTO :XWORD, :XWORD
IFNDEF SetErrorInfo
    SetErrorInfo PROTO :ULONG, :XPTR
ENDIF
SNB_UserFree PROTO :XWORD, :XWORD
SNB_UserMarshal PROTO :XWORD, :XWORD, :XWORD
SNB_UserSize PROTO :XWORD, :XWORD, :XWORD
SNB_UserUnmarshal PROTO :XWORD, :XWORD, :XWORD
StgConvertPropertyToVariant PROTO :XWORD, :XWORD, :XWORD, :XWORD
StgConvertVariantToProperty PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
StgCreateDocfile PROTO :XWORD, :XWORD, :XWORD, :XWORD
StgCreateDocfileOnILockBytes PROTO :XWORD, :XWORD, :XWORD, :XWORD
StgCreatePropSetStg PROTO :XWORD, :XWORD, :XWORD
StgCreatePropStg PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
StgCreateStorageEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
StgGetIFillLockBytesOnFile PROTO :XWORD, :XWORD
StgGetIFillLockBytesOnILockBytes PROTO :XWORD, :XWORD
StgIsStorageFile PROTO :XWORD
StgIsStorageILockBytes PROTO :XWORD
STGMEDIUM_UserFree PROTO :XWORD, :XWORD
STGMEDIUM_UserFree64 PROTO :XPTR, :XPTR
STGMEDIUM_UserMarshal PROTO :XWORD, :XWORD, :XWORD
STGMEDIUM_UserMarshal64 PROTO :XPTR, :XPTR, :XPTR
STGMEDIUM_UserSize PROTO :XWORD, :XWORD, :XWORD
STGMEDIUM_UserSize64 PROTO :XPTR, :XWORD, :XPTR
STGMEDIUM_UserUnmarshal PROTO :XWORD, :XWORD, :XWORD
STGMEDIUM_UserUnmarshal64 PROTO :XPTR, :XPTR, :XPTR
StgOpenAsyncDocfileOnIFillLockBytes PROTO :XWORD, :XWORD, :XWORD, :XWORD
StgOpenPropStg PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
StgOpenStorage PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
StgOpenStorageEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
StgOpenStorageOnILockBytes PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
StgPropertyLengthAsVariant PROTO :XWORD, :XWORD, :XWORD, :XWORD
StgSetTimes PROTO :XWORD, :XWORD, :XWORD, :XWORD
StringFromCLSID PROTO :XWORD, :XWORD
StringFromGUID2 PROTO :XWORD, :XWORD, :XWORD
StringFromIID PROTO :XWORD, :XWORD
UpdateDCOMSettings PROTO
UtConvertDvtd16toDvtd32 PROTO :XWORD, :XWORD, :XWORD
UtConvertDvtd32toDvtd16 PROTO :XWORD, :XWORD, :XWORD
UtGetDvtd16Info PROTO :XWORD, :XWORD
UtGetDvtd32Info PROTO :XWORD, :XWORD
WdtpInterfacePointer_UserFree PROTO :XWORD
WdtpInterfacePointer_UserMarshal PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
WdtpInterfacePointer_UserSize PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
WdtpInterfacePointer_UserUnmarshal PROTO :XWORD, :XWORD, :XWORD, :XWORD
WriteClassStg PROTO :XWORD, :XWORD
WriteClassStm PROTO :XWORD, :XWORD
WriteFmtUserTypeStg PROTO :XWORD, :XWORD, :XWORD
WriteOleStg PROTO :XWORD, :XWORD, :XWORD, :XWORD
WriteStringStream PROTO :XWORD, :XWORD


;======================= Undocumented functions (unknown arguments) =======================;
;CheckInitDde PROTO
;CleanROTForApartment PROTO
;ClipboardProcessUninitialize PROTO
;CLIPFORMAT_UserFree64 PROTO
;CLIPFORMAT_UserFreeExt PROTO
;CLIPFORMAT_UserMarshal64 PROTO
;CLIPFORMAT_UserMarshalExt PROTO
;CLIPFORMAT_UserSize64 PROTO
;CLIPFORMAT_UserSizeExt PROTO
;CLIPFORMAT_UserUnmarshal64 PROTO
;CLIPFORMAT_UserUnmarshalExt PROTO
;CoAicGetTokenForCOM PROTO
;CoAllowUnmarshalerCLSID PROTO
;CoCheckElevationEnabled PROTO
;CoGetComCatalog PROTO
;CoGetInterceptorForOle32 PROTO
;CoGetSystemWow64DirectoryW PROTO
;CoPopServiceDomain PROTO
;CoPushServiceDomain PROTO
;CoRegisterActivationFilter PROTO
;CoVrfCheckThreadState PROTO
;CoVrfGetThreadState PROTO
;CoVrfReleaseThreadState PROTO
;DdeBindToObject PROTO
;DeletePatternAndExtensionTables PROTO
;DestroyRunningObjectTable PROTO
;DllRegisterServer PROTO
;DragDropSetFDT PROTO
;FindExt PROTO
;GetActiveObjectExt PROTO
;GetObjectFromRotByPath PROTO
;HACCEL_UserFree64 PROTO
;HACCEL_UserMarshal64 PROTO
;HACCEL_UserSize64 PROTO
;HACCEL_UserUnmarshal64 PROTO
;HBITMAP_UserFree64 PROTO
;HBITMAP_UserMarshal64 PROTO
;HBITMAP_UserSize64 PROTO
;HBITMAP_UserUnmarshal64 PROTO
;HBRUSH_UserFree64 PROTO
;HBRUSH_UserMarshal64 PROTO
;HBRUSH_UserSize64 PROTO
;HBRUSH_UserUnmarshal64 PROTO
;HDC_UserFree64 PROTO
;HDC_UserMarshal64 PROTO
;HDC_UserSize64 PROTO
;HDC_UserUnmarshal64 PROTO
;HENHMETAFILE_UserFree64 PROTO
;HENHMETAFILE_UserMarshal64 PROTO
;HENHMETAFILE_UserSize64 PROTO
;HENHMETAFILE_UserUnmarshal64 PROTO
;HGLOBAL_UserFree64 PROTO
;HGLOBAL_UserMarshal64 PROTO
;HGLOBAL_UserSize64 PROTO
;HGLOBAL_UserUnmarshal64 PROTO
;HICON_UserFree64 PROTO
;HICON_UserMarshal64 PROTO
;HICON_UserSize64 PROTO
;HICON_UserUnmarshal64 PROTO
;HMENU_UserFree64 PROTO
;HMENU_UserMarshal64 PROTO
;HMENU_UserSize64 PROTO
;HMENU_UserUnmarshal64 PROTO
;HMETAFILE_UserFree64 PROTO
;HMETAFILE_UserMarshal64 PROTO
;HMETAFILE_UserSize64 PROTO
;HMETAFILE_UserUnmarshal64 PROTO
;HMETAFILEPICT_UserFree64 PROTO
;HMETAFILEPICT_UserMarshal64 PROTO
;HMETAFILEPICT_UserSize64 PROTO
;HMETAFILEPICT_UserUnmarshal64 PROTO
;HMONITOR_UserFree PROTO
;HMONITOR_UserFree64 PROTO
;HMONITOR_UserMarshal PROTO
;HMONITOR_UserMarshal64 PROTO
;HMONITOR_UserSize PROTO
;HMONITOR_UserSize64 PROTO
;HMONITOR_UserUnmarshal PROTO
;HMONITOR_UserUnmarshal64 PROTO
;HPALETTE_UserFree64 PROTO
;HPALETTE_UserFreeExt PROTO
;HPALETTE_UserMarshal64 PROTO
;HPALETTE_UserMarshalExt PROTO
;HPALETTE_UserSize64 PROTO
;HPALETTE_UserSizeExt PROTO
;HPALETTE_UserUnmarshal64 PROTO
;HPALETTE_UserUnmarshalExt PROTO
;HRGN_UserFree PROTO
;HRGN_UserMarshal PROTO
;HRGN_UserSize PROTO
;HRGN_UserUnmarshal PROTO
;HWND_UserFree64 PROTO
;HWND_UserFree64Ext PROTO
;HWND_UserFreeExt PROTO
;HWND_UserMarshal64 PROTO
;HWND_UserMarshal64Ext PROTO
;HWND_UserMarshalExt PROTO
;HWND_UserSize64 PROTO
;HWND_UserSize64Ext PROTO
;HWND_UserSizeExt PROTO
;HWND_UserUnmarshal64 PROTO
;HWND_UserUnmarshal64Ext PROTO
;HWND_UserUnmarshalExt PROTO
;IsRoInitializeASTAAllowedInDesktop PROTO
;MonikerLoadTypeLib PROTO
;NdrProxyForwardingFunction10 PROTO
;NdrProxyForwardingFunction11 PROTO
;NdrProxyForwardingFunction12 PROTO
;NdrProxyForwardingFunction13 PROTO
;NdrProxyForwardingFunction14 PROTO
;NdrProxyForwardingFunction15 PROTO
;NdrProxyForwardingFunction16 PROTO
;NdrProxyForwardingFunction17 PROTO
;NdrProxyForwardingFunction18 PROTO
;NdrProxyForwardingFunction19 PROTO
;NdrProxyForwardingFunction20 PROTO
;NdrProxyForwardingFunction21 PROTO
;NdrProxyForwardingFunction22 PROTO
;NdrProxyForwardingFunction23 PROTO
;NdrProxyForwardingFunction24 PROTO
;NdrProxyForwardingFunction25 PROTO
;NdrProxyForwardingFunction26 PROTO
;NdrProxyForwardingFunction27 PROTO
;NdrProxyForwardingFunction28 PROTO
;NdrProxyForwardingFunction29 PROTO
;NdrProxyForwardingFunction3 PROTO
;NdrProxyForwardingFunction30 PROTO
;NdrProxyForwardingFunction31 PROTO
;NdrProxyForwardingFunction32 PROTO
;NdrProxyForwardingFunction4 PROTO
;NdrProxyForwardingFunction5 PROTO
;NdrProxyForwardingFunction6 PROTO
;NdrProxyForwardingFunction7 PROTO
;NdrProxyForwardingFunction8 PROTO
;NdrProxyForwardingFunction9 PROTO
;ObjectStublessClient10 PROTO
;ObjectStublessClient11 PROTO
;ObjectStublessClient12 PROTO
;ObjectStublessClient13 PROTO
;ObjectStublessClient14 PROTO
;ObjectStublessClient15 PROTO
;ObjectStublessClient16 PROTO
;ObjectStublessClient17 PROTO
;ObjectStublessClient18 PROTO
;ObjectStublessClient19 PROTO
;ObjectStublessClient20 PROTO
;ObjectStublessClient21 PROTO
;ObjectStublessClient22 PROTO
;ObjectStublessClient23 PROTO
;ObjectStublessClient24 PROTO
;ObjectStublessClient25 PROTO
;ObjectStublessClient26 PROTO
;ObjectStublessClient27 PROTO
;ObjectStublessClient28 PROTO
;ObjectStublessClient29 PROTO
;ObjectStublessClient3 PROTO
;ObjectStublessClient30 PROTO
;ObjectStublessClient31 PROTO
;ObjectStublessClient32 PROTO
;ObjectStublessClient4 PROTO
;ObjectStublessClient5 PROTO
;ObjectStublessClient6 PROTO
;ObjectStublessClient7 PROTO
;ObjectStublessClient8 PROTO
;ObjectStublessClient9 PROTO
;OleCreateFontIndirectExt PROTO
;OleCreatePictureIndirectExt PROTO
;OleCreatePropertyFrameIndirectExt PROTO
;OleGetPackageClipboardOwner PROTO
;OleIconToCursorExt PROTO
;OleLoadPictureExt PROTO
;OleLoadPictureFileExt PROTO
;OleLoadPicturePathExt PROTO
;OleReleaseEnumVerbCache PROTO
;OleSavePictureFileExt PROTO
;OleTranslateColorExt PROTO
;ReadStorageProperties PROTO
;RegisterActiveObjectExt PROTO
;RevokeActiveObjectExt PROTO
;SetOleautModule PROTO
;SetWOWThunkGlobalPtr PROTO
;SNB_UserFree64 PROTO
;SNB_UserMarshal64 PROTO
;SNB_UserSize64 PROTO
;SNB_UserUnmarshal64 PROTO
;StdTypesGetClassObject PROTO
;StdTypesRegisterServer PROTO
;STGMEDIUM_UserFreeExt PROTO
;STGMEDIUM_UserMarshalExt PROTO
;STGMEDIUM_UserSizeExt PROTO
;STGMEDIUM_UserUnmarshalExt PROTO
;StgOpenStorageOnHandle PROTO
;UpdateProcessTracing PROTO
;WdtpInterfacePointer_UserFree64 PROTO
;WdtpInterfacePointer_UserMarshal64 PROTO
;WdtpInterfacePointer_UserSize64 PROTO
;WdtpInterfacePointer_UserUnmarshal64 PROTO
;WriteStorageProperties PROTO

ENDIF ;OLE32_INC
