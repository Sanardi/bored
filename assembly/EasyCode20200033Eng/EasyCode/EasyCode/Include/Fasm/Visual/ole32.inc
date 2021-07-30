; ====================================================;
;                                                     ;
;      ole32.inc for EC v2 Fasm visual projects       ;
;                   (version 1.0.2)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

if ~defined OLE32_INC
define OLE32_INC 1
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

;======================================== Structures ======================================;
struct DRAG_FLAVORINFO
    cfFormat    dd ?
    FlavorFlags dd ?
    fAddData    dd ?
    reserved    dd ?
ends

struct OleMBarRec
    reserved dd ?
ends

struct OLESTREAMVTBL
    Get    xptr ?
    Put    xptr ?
ends

struct OLESTREAM
    lpstbl xptr ?
ends

;======================================== Functions =======================================;
if defined APP_WIN64
    extrn '__imp_BindMoniker' as BindMoniker:qword
    extrn '__imp_CLIPFORMAT_UserFree' as CLIPFORMAT_UserFree:qword
    extrn '__imp_CLIPFORMAT_UserMarshal' as CLIPFORMAT_UserMarshal:qword
    extrn '__imp_CLIPFORMAT_UserSize' as CLIPFORMAT_UserSize:qword
    extrn '__imp_CLIPFORMAT_UserUnmarshal' as CLIPFORMAT_UserUnmarshal:qword
    extrn '__imp_CLSIDFromOle1Class' as CLSIDFromOle1Class:qword
    extrn '__imp_CLSIDFromProgID' as CLSIDFromProgID:qword
    extrn '__imp_CLSIDFromProgIDEx' as CLSIDFromProgIDEx:qword
    extrn '__imp_CLSIDFromString' as CLSIDFromString:qword
    extrn '__imp_CoAddRefServerProcess' as CoAddRefServerProcess:qword
    extrn '__imp_CoAllowSetForegroundWindow' as CoAllowSetForegroundWindow:qword
    extrn '__imp_CoBuildVersion' as CoBuildVersion:qword
    extrn '__imp_CoCancelCall' as CoCancelCall:qword
    extrn '__imp_CoCopyProxy' as CoCopyProxy:qword
    extrn '__imp_CoCreateFreeThreadedMarshaler' as CoCreateFreeThreadedMarshaler:qword
    extrn '__imp_CoCreateGuid' as CoCreateGuid:qword
    extrn '__imp_CoCreateInstance' as CoCreateInstance:qword
    extrn '__imp_CoCreateInstanceEx' as CoCreateInstanceEx:qword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        if ~defined __imp_CoCreateInstanceFromApp
            extrn '__imp_CoCreateInstanceFromApp' as CoCreateInstanceFromApp:qword
        end if
    end if
    extrn '__imp_CoCreateObjectInContext' as CoCreateObjectInContext:qword
    extrn '__imp_CoDeactivateObject' as CoDeactivateObject:qword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_CoDecodeProxy' as CoDecodeProxy:qword
        extrn '__imp_CoDecrementMTAUsage' as CoDecrementMTAUsage:qword
    end if
    extrn '__imp_CoDisableCallCancellation' as CoDisableCallCancellation:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_CoDisconnectContext' as CoDisconnectContext:qword
    end if
    extrn '__imp_CoDisconnectObject' as CoDisconnectObject:qword
    extrn '__imp_CoDosDateTimeToFileTime' as CoDosDateTimeToFileTime:qword
    extrn '__imp_CoEnableCallCancellation' as CoEnableCallCancellation:qword
    extrn '__imp_CoFileTimeNow' as CoFileTimeNow:qword
    extrn '__imp_CoFileTimeToDosDateTime' as CoFileTimeToDosDateTime:qword
    extrn '__imp_CoFreeAllLibraries' as CoFreeAllLibraries:qword
    extrn '__imp_CoFreeLibrary' as CoFreeLibrary:qword
    extrn '__imp_CoFreeUnusedLibraries' as CoFreeUnusedLibraries:qword
    extrn '__imp_CoFreeUnusedLibrariesEx' as CoFreeUnusedLibrariesEx:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_CoGetActivationState' as CoGetActivationState:qword
    end if
    extrn '__imp_CoGetApartmentID' as CoGetApartmentID:qword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_CoGetApartmentType' as CoGetApartmentType:qword
    end if
    extrn '__imp_CoGetCallContext' as CoGetCallContext:qword
    extrn '__imp_CoGetCallerTID' as CoGetCallerTID:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_CoGetCallState' as CoGetCallState:qword
    end if
    extrn '__imp_CoGetCancelObject' as CoGetCancelObject:qword
    extrn '__imp_CoGetClassObject' as CoGetClassObject:qword
    extrn '__imp_CoGetClassVersion' as CoGetClassVersion:qword
    extrn '__imp_CoGetContextToken' as CoGetContextToken:qword
    extrn '__imp_CoGetCurrentLogicalThreadId' as CoGetCurrentLogicalThreadId:qword
    extrn '__imp_CoGetCurrentProcess' as CoGetCurrentProcess:qword
    extrn '__imp_CoGetDefaultContext' as CoGetDefaultContext:qword
    extrn '__imp_CoGetInstanceFromFile' as CoGetInstanceFromFile:qword
    extrn '__imp_CoGetInstanceFromIStorage' as CoGetInstanceFromIStorage:qword
    extrn '__imp_CoGetInterceptor' as CoGetInterceptor:qword
    extrn '__imp_CoGetInterceptorFromTypeInfo' as CoGetInterceptorFromTypeInfo:qword
    extrn '__imp_CoGetInterfaceAndReleaseStream' as CoGetInterfaceAndReleaseStream:qword
    extrn '__imp_CoGetMalloc' as CoGetMalloc:qword
    extrn '__imp_CoGetMarshalSizeMax' as CoGetMarshalSizeMax:qword
    extrn '__imp_CoGetModuleType' as CoGetModuleType:qword
    extrn '__imp_CoGetObject' as CoGetObject:qword
    extrn '__imp_CoGetObjectContext' as CoGetObjectContext:qword
    extrn '__imp_CoGetProcessIdentifier' as CoGetProcessIdentifier:qword
    extrn '__imp_CoGetPSClsid' as CoGetPSClsid:qword
    extrn '__imp_CoGetStandardMarshal' as CoGetStandardMarshal:qword
    if (NTDDI_VERSION <= NTDDI_VISTA)
        extrn '__imp_CoGetState' as CoGetState:qword
    end if
    extrn '__imp_CoGetStdMarshalEx' as CoGetStdMarshalEx:qword
    extrn '__imp_CoGetSystemSecurityPermissions' as CoGetSystemSecurityPermissions:qword
    extrn '__imp_CoGetTreatAsClass' as CoGetTreatAsClass:qword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_CoHandlePriorityEventsFromMessagePump' as CoHandlePriorityEventsFromMessagePump:qword
    end if
    extrn '__imp_CoImpersonateClient' as CoImpersonateClient:qword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_CoIncrementMTAUsage' as CoIncrementMTAUsage:qword
    end if
    extrn '__imp_CoInitialize' as CoInitialize:qword
    extrn '__imp_CoInitializeEx' as CoInitializeEx:qword
    extrn '__imp_CoInitializeSecurity' as CoInitializeSecurity:qword
    extrn '__imp_CoInitializeWOW' as CoInitializeWOW:qword
    extrn '__imp_CoInstall' as CoInstall:qword
    extrn '__imp_CoInvalidateRemoteMachineBindings' as CoInvalidateRemoteMachineBindings:qword
    extrn '__imp_CoIsHandlerConnected' as CoIsHandlerConnected:qword
    extrn '__imp_CoIsOle1Class' as CoIsOle1Class:qword
    extrn '__imp_CoLoadLibrary' as CoLoadLibrary:qword
    extrn '__imp_CoLockObjectExternal' as CoLockObjectExternal:qword
    extrn '__imp_CoMarshalHresult' as CoMarshalHresult:qword
    extrn '__imp_CoMarshalInterface' as CoMarshalInterface:qword
    extrn '__imp_CoMarshalInterThreadInterfaceInStream' as CoMarshalInterThreadInterfaceInStream:qword
    extrn '__imp_ComPs_NdrDllCanUnloadNow' as ComPs_NdrDllCanUnloadNow:qword
    extrn '__imp_ComPs_NdrDllGetClassObject' as ComPs_NdrDllGetClassObject:qword
    extrn '__imp_ComPs_NdrDllRegisterProxy' as ComPs_NdrDllRegisterProxy:qword
    extrn '__imp_ComPs_NdrDllUnregisterProxy' as ComPs_NdrDllUnregisterProxy:qword
    extrn '__imp_CoQueryAuthenticationServices' as CoQueryAuthenticationServices:qword
    extrn '__imp_CoQueryClientBlanket' as CoQueryClientBlanket:qword
    extrn '__imp_CoQueryProxyBlanket' as CoQueryProxyBlanket:qword
    extrn '__imp_CoQueryReleaseObject' as CoQueryReleaseObject:qword
    extrn '__imp_CoReactivateObject' as CoReactivateObject:qword
    extrn '__imp_CoRegisterChannelHook' as CoRegisterChannelHook:qword
    extrn '__imp_CoRegisterClassObject' as CoRegisterClassObject:qword
    extrn '__imp_CoRegisterInitializeSpy' as CoRegisterInitializeSpy:qword
    extrn '__imp_CoRegisterMallocSpy' as CoRegisterMallocSpy:qword
    extrn '__imp_CoRegisterMessageFilter' as CoRegisterMessageFilter:qword
    extrn '__imp_CoRegisterPSClsid' as CoRegisterPSClsid:qword
    extrn '__imp_CoRegisterSurrogate' as CoRegisterSurrogate:qword
    extrn '__imp_CoRegisterSurrogateEx' as CoRegisterSurrogateEx:qword
    extrn '__imp_CoReleaseMarshalData' as CoReleaseMarshalData:qword
    extrn '__imp_CoReleaseServerProcess' as CoReleaseServerProcess:qword
    extrn '__imp_CoResumeClassObjects' as CoResumeClassObjects:qword
    extrn '__imp_CoRetireServer' as CoRetireServer:qword
    extrn '__imp_CoRevertToSelf' as CoRevertToSelf:qword
    extrn '__imp_CoRevokeClassObject' as CoRevokeClassObject:qword
    extrn '__imp_CoRevokeInitializeSpy' as CoRevokeInitializeSpy:qword
    extrn '__imp_CoRevokeMallocSpy' as CoRevokeMallocSpy:qword
    extrn '__imp_CoSetCancelObject' as CoSetCancelObject:qword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_CoSetMessageDispatcher' as CoSetMessageDispatcher:qword
    end if
    extrn '__imp_CoSetProxyBlanket' as CoSetProxyBlanket:qword
    extrn '__imp_CoSetState' as CoSetState:qword
    extrn '__imp_CoSuspendClassObjects' as CoSuspendClassObjects:qword
    extrn '__imp_CoSwitchCallContext' as CoSwitchCallContext:qword
    extrn '__imp_CoTaskMemAlloc' as CoTaskMemAlloc:qword
    extrn '__imp_CoTaskMemFree' as CoTaskMemFree:qword
    extrn '__imp_CoTaskMemRealloc' as CoTaskMemRealloc:qword
    extrn '__imp_CoTestCancel' as CoTestCancel:qword
    extrn '__imp_CoTreatAsClass' as CoTreatAsClass:qword
    extrn '__imp_CoUninitialize' as CoUninitialize:qword
    extrn '__imp_CoUnloadingWOW' as CoUnloadingWOW:qword
    extrn '__imp_CoUnmarshalHresult' as CoUnmarshalHresult:qword
    extrn '__imp_CoUnmarshalInterface' as CoUnmarshalInterface:qword
    extrn '__imp_CoWaitForMultipleHandles' as CoWaitForMultipleHandles:qword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_CoWaitForMultipleObjects' as CoWaitForMultipleObjects:qword
    end if
    extrn '__imp_CreateAntiMoniker' as CreateAntiMoniker:qword
    extrn '__imp_CreateBindCtx' as CreateBindCtx:qword
    extrn '__imp_CreateClassMoniker' as CreateClassMoniker:qword
    extrn '__imp_CreateDataAdviseHolder' as CreateDataAdviseHolder:qword
    extrn '__imp_CreateDataCache' as CreateDataCache:qword
    extrn '__imp_CreateFileMoniker' as CreateFileMoniker:qword
    extrn '__imp_CreateGenericComposite' as CreateGenericComposite:qword
    extrn '__imp_CreateILockBytesOnHGlobal' as CreateILockBytesOnHGlobal:qword
    extrn '__imp_CreateItemMoniker' as CreateItemMoniker:qword
    extrn '__imp_CreateObjrefMoniker' as CreateObjrefMoniker:qword
    extrn '__imp_CreateOleAdviseHolder' as CreateOleAdviseHolder:qword
    extrn '__imp_CreatePointerMoniker' as CreatePointerMoniker:qword
    extrn '__imp_CreateStdProgressIndicator' as CreateStdProgressIndicator:qword
    extrn '__imp_CreateStreamOnHGlobal' as CreateStreamOnHGlobal:qword
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp_CStdAsyncStubBuffer_AddRef' as CStdAsyncStubBuffer_AddRef:qword
        extrn '__imp_CStdAsyncStubBuffer_Connect' as CStdAsyncStubBuffer_Connect:qword
        extrn '__imp_CStdAsyncStubBuffer_Disconnect' as CStdAsyncStubBuffer_Disconnect:qword
        extrn '__imp_CStdAsyncStubBuffer_Invoke' as CStdAsyncStubBuffer_Invoke:qword
        extrn '__imp_CStdAsyncStubBuffer_QueryInterface' as CStdAsyncStubBuffer_QueryInterface:qword
        extrn '__imp_CStdAsyncStubBuffer_Release' as CStdAsyncStubBuffer_Release:qword
        extrn '__imp_CStdAsyncStubBuffer2_Connect' as CStdAsyncStubBuffer2_Connect:qword
        extrn '__imp_CStdAsyncStubBuffer2_Disconnect' as CStdAsyncStubBuffer2_Disconnect:qword
        extrn '__imp_CStdAsyncStubBuffer2_Release' as CStdAsyncStubBuffer2_Release:qword
        extrn '__imp_CStdStubBuffer2_Connect' as CStdStubBuffer2_Connect:qword
        extrn '__imp_CStdStubBuffer2_CountRefs' as CStdStubBuffer2_CountRefs:qword
        extrn '__imp_CStdStubBuffer2_Disconnect' as CStdStubBuffer2_Disconnect:qword
        extrn '__imp_CStdStubBuffer2_QueryInterface' as CStdStubBuffer2_QueryInterface:qword
    end if
    extrn '__imp_DcomChannelSetHResult' as DcomChannelSetHResult:qword
    extrn '__imp_DllDebugObjectRPCHook' as DllDebugObjectRPCHook:qword
    extrn '__imp_DllGetClassObject' as DllGetClassObject:qword
    extrn '__imp_DllGetClassObjectWOW' as DllGetClassObjectWOW:qword
    extrn '__imp_DoDragDrop' as DoDragDrop:qword
    extrn '__imp_EnableHookObject' as EnableHookObject:qword
    extrn '__imp_FmtIdToPropStgName' as FmtIdToPropStgName:qword
    extrn '__imp_FreePropVariantArray' as FreePropVariantArray:qword
    extrn '__imp_GetClassFile' as GetClassFile:qword
    extrn '__imp_GetConvertStg' as GetConvertStg:qword
    extrn '__imp_GetDocumentBitStg' as GetDocumentBitStg:qword
    extrn '__imp_GetHGlobalFromILockBytes' as GetHGlobalFromILockBytes:qword
    extrn '__imp_GetHGlobalFromStream' as GetHGlobalFromStream:qword
    extrn '__imp_GetHookInterface' as GetHookInterface:qword
    extrn '__imp_GetRunningObjectTable' as GetRunningObjectTable:qword
    extrn '__imp_HACCEL_UserFree' as HACCEL_UserFree:qword
    extrn '__imp_HACCEL_UserMarshal' as HACCEL_UserMarshal:qword
    extrn '__imp_HACCEL_UserSize' as HACCEL_UserSize:qword
    extrn '__imp_HACCEL_UserUnmarshal' as HACCEL_UserUnmarshal:qword
    extrn '__imp_HBITMAP_UserFree' as HBITMAP_UserFree:qword
    extrn '__imp_HBITMAP_UserMarshal' as HBITMAP_UserMarshal:qword
    extrn '__imp_HBITMAP_UserSize' as HBITMAP_UserSize:qword
    extrn '__imp_HBITMAP_UserUnmarshal' as HBITMAP_UserUnmarshal:qword
    extrn '__imp_HBRUSH_UserFree' as HBRUSH_UserFree:qword
    extrn '__imp_HBRUSH_UserMarshal' as HBRUSH_UserMarshal:qword
    extrn '__imp_HBRUSH_UserSize' as HBRUSH_UserSize:qword
    extrn '__imp_HBRUSH_UserUnmarshal' as HBRUSH_UserUnmarshal:qword
    extrn '__imp_HDC_UserFree' as HDC_UserFree:qword
    extrn '__imp_HDC_UserMarshal' as HDC_UserMarshal:qword
    extrn '__imp_HDC_UserSize' as HDC_UserSize:qword
    extrn '__imp_HDC_UserUnmarshal' as HDC_UserUnmarshal:qword
    extrn '__imp_HENHMETAFILE_UserFree' as HENHMETAFILE_UserFree:qword
    extrn '__imp_HENHMETAFILE_UserMarshal' as HENHMETAFILE_UserMarshal:qword
    extrn '__imp_HENHMETAFILE_UserSize' as HENHMETAFILE_UserSize:qword
    extrn '__imp_HENHMETAFILE_UserUnmarshal' as HENHMETAFILE_UserUnmarshal:qword
    extrn '__imp_HGLOBAL_UserFree' as HGLOBAL_UserFree:qword
    extrn '__imp_HGLOBAL_UserMarshal' as HGLOBAL_UserMarshal:qword
    extrn '__imp_HGLOBAL_UserSize' as HGLOBAL_UserSize:qword
    extrn '__imp_HGLOBAL_UserUnmarshal' as HGLOBAL_UserUnmarshal:qword
    extrn '__imp_HICON_UserFree' as HICON_UserFree:qword
    extrn '__imp_HICON_UserMarshal' as HICON_UserMarshal:qword
    extrn '__imp_HICON_UserSize' as HICON_UserSize:qword
    extrn '__imp_HICON_UserUnmarshal' as HICON_UserUnmarshal:qword
    extrn '__imp_HkOleRegisterObject' as HkOleRegisterObject:qword
    extrn '__imp_HMENU_UserFree' as HMENU_UserFree:qword
    extrn '__imp_HMENU_UserMarshal' as HMENU_UserMarshal:qword
    extrn '__imp_HMENU_UserSize' as HMENU_UserSize:qword
    extrn '__imp_HMENU_UserUnmarshal' as HMENU_UserUnmarshal:qword
    extrn '__imp_HMETAFILE_UserFree' as HMETAFILE_UserFree:qword
    extrn '__imp_HMETAFILE_UserMarshal' as HMETAFILE_UserMarshal:qword
    extrn '__imp_HMETAFILE_UserSize' as HMETAFILE_UserSize:qword
    extrn '__imp_HMETAFILE_UserUnmarshal' as HMETAFILE_UserUnmarshal:qword
    extrn '__imp_HMETAFILEPICT_UserFree' as HMETAFILEPICT_UserFree:qword
    extrn '__imp_HMETAFILEPICT_UserMarshal' as HMETAFILEPICT_UserMarshal:qword
    extrn '__imp_HMETAFILEPICT_UserSize' as HMETAFILEPICT_UserSize:qword
    extrn '__imp_HMETAFILEPICT_UserUnmarshal' as HMETAFILEPICT_UserUnmarshal:qword
    extrn '__imp_HPALETTE_UserFree' as HPALETTE_UserFree:qword
    extrn '__imp_HPALETTE_UserMarshal' as HPALETTE_UserMarshal:qword
    extrn '__imp_HPALETTE_UserSize' as HPALETTE_UserSize:qword
    extrn '__imp_HPALETTE_UserUnmarshal' as HPALETTE_UserUnmarshal:qword
    extrn '__imp_HWND_UserFree' as HWND_UserFree:qword
    extrn '__imp_HWND_UserMarshal' as HWND_UserMarshal:qword
    extrn '__imp_HWND_UserSize' as HWND_UserSize:qword
    extrn '__imp_HWND_UserUnmarshal' as HWND_UserUnmarshal:qword
    extrn '__imp_IIDFromString' as IIDFromString:qword
    extrn '__imp_IsAccelerator' as IsAccelerator:qword
    extrn '__imp_IsEqualGUID' as IsEqualGUID:qword
    extrn '__imp_IsValidIid' as IsValidIid:qword
    extrn '__imp_IsValidInterface' as IsValidInterface:qword
    extrn '__imp_IsValidPtrIn' as IsValidPtrIn:qword
    extrn '__imp_IsValidPtrOut' as IsValidPtrOut:qword
    extrn '__imp_MkParseDisplayName' as MkParseDisplayName:qword
    extrn '__imp_MonikerCommonPrefixWith' as MonikerCommonPrefixWith:qword
    extrn '__imp_MonikerRelativePathTo' as MonikerRelativePathTo:qword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_NdrOleInitializeExtension' as NdrOleInitializeExtension:qword
    end if
    extrn '__imp_OleBuildVersion' as OleBuildVersion:qword
    extrn '__imp_OleConvertIStorageToOLESTREAM' as OleConvertIStorageToOLESTREAM:qword
    extrn '__imp_OleConvertIStorageToOLESTREAMEx' as OleConvertIStorageToOLESTREAMEx:qword
    extrn '__imp_OleConvertOLESTREAMToIStorage' as OleConvertOLESTREAMToIStorage:qword
    extrn '__imp_OleConvertOLESTREAMToIStorageEx' as OleConvertOLESTREAMToIStorageEx:qword
    extrn '__imp_OleCreate' as OleCreate:qword
    extrn '__imp_OleCreateDefaultHandler' as OleCreateDefaultHandler:qword
    extrn '__imp_OleCreateEmbeddingHelper' as OleCreateEmbeddingHelper:qword
    extrn '__imp_OleCreateEx' as OleCreateEx:qword
    extrn '__imp_OleCreateFromData' as OleCreateFromData:qword
    extrn '__imp_OleCreateFromDataEx' as OleCreateFromDataEx:qword
    extrn '__imp_OleCreateFromFile' as OleCreateFromFile:qword
    extrn '__imp_OleCreateFromFileEx' as OleCreateFromFileEx:qword
    extrn '__imp_OleCreateLink' as OleCreateLink:qword
    extrn '__imp_OleCreateLinkEx' as OleCreateLinkEx:qword
    extrn '__imp_OleCreateLinkFromData' as OleCreateLinkFromData:qword
    extrn '__imp_OleCreateLinkFromDataEx' as OleCreateLinkFromDataEx:qword
    extrn '__imp_OleCreateLinkToFile' as OleCreateLinkToFile:qword
    extrn '__imp_OleCreateLinkToFileEx' as OleCreateLinkToFileEx:qword
    extrn '__imp_OleCreateMenuDescriptor' as OleCreateMenuDescriptor:qword
    extrn '__imp_OleCreateStaticFromData' as OleCreateStaticFromData:qword
    extrn '__imp_OleDestroyMenuDescriptor' as OleDestroyMenuDescriptor:qword
    extrn '__imp_OleDoAutoConvert' as OleDoAutoConvert:qword
    extrn '__imp_OleDraw' as OleDraw:qword
    extrn '__imp_OleDuplicateData' as OleDuplicateData:qword
    extrn '__imp_OleFlushClipboard' as OleFlushClipboard:qword
    extrn '__imp_OleGetAutoConvert' as OleGetAutoConvert:qword
    extrn '__imp_OleGetClipboard' as OleGetClipboard:qword
    extrn '__imp_OleGetIconOfClass' as OleGetIconOfClass:qword
    extrn '__imp_OleGetIconOfFile' as OleGetIconOfFile:qword
    extrn '__imp_OleInitialize' as OleInitialize:qword
    extrn '__imp_OleInitializeWOW' as OleInitializeWOW:qword
    extrn '__imp_OleIsCurrentClipboard' as OleIsCurrentClipboard:qword
    extrn '__imp_OleIsRunning' as OleIsRunning:qword
    extrn '__imp_OleLoad' as OleLoad:qword
    extrn '__imp_OleLoadFromStream' as OleLoadFromStream:qword
    extrn '__imp_OleLockRunning' as OleLockRunning:qword
    extrn '__imp_OleMetafilePictFromIconAndLabel' as OleMetafilePictFromIconAndLabel:qword
    extrn '__imp_OleNoteObjectVisible' as OleNoteObjectVisible:qword
    extrn '__imp_OleQueryCreateFromData' as OleQueryCreateFromData:qword
    extrn '__imp_OleQueryLinkFromData' as OleQueryLinkFromData:qword
    extrn '__imp_OleRegEnumFormatEtc' as OleRegEnumFormatEtc:qword
    extrn '__imp_OleRegEnumVerbs' as OleRegEnumVerbs:qword
    extrn '__imp_OleRegGetMiscStatus' as OleRegGetMiscStatus:qword
    extrn '__imp_OleRegGetUserType' as OleRegGetUserType:qword
    extrn '__imp_OleRun' as OleRun:qword
    extrn '__imp_OleSave' as OleSave:qword
    extrn '__imp_OleSaveToStream' as OleSaveToStream:qword
    extrn '__imp_OleSetAutoConvert' as OleSetAutoConvert:qword
    extrn '__imp_OleSetClipboard' as OleSetClipboard:qword
    extrn '__imp_OleSetContainedObject' as OleSetContainedObject:qword
    extrn '__imp_OleSetMenuDescriptor' as OleSetMenuDescriptor:qword
    extrn '__imp_OleTranslateAccelerator' as OleTranslateAccelerator:qword
    extrn '__imp_OleUninitialize' as OleUninitialize:qword
    extrn '__imp_OpenOrCreateStream' as OpenOrCreateStream:qword
    extrn '__imp_ProgIDFromCLSID' as ProgIDFromCLSID:qword
    extrn '__imp_PropStgNameToFmtId' as PropStgNameToFmtId:qword
    extrn '__imp_PropSysAllocString' as PropSysAllocString:qword
    extrn '__imp_PropSysFreeString' as PropSysFreeString:qword
    extrn '__imp_PropVariantChangeType' as PropVariantChangeType:qword
    extrn '__imp_PropVariantClear' as PropVariantClear:qword
    extrn '__imp_PropVariantCopy' as PropVariantCopy:qword
    extrn '__imp_ReadClassStg' as ReadClassStg:qword
    extrn '__imp_ReadClassStm' as ReadClassStm:qword
    extrn '__imp_ReadFmtUserTypeStg' as ReadFmtUserTypeStg:qword
    extrn '__imp_ReadOleStg' as ReadOleStg:qword
    extrn '__imp_ReadStringStream' as ReadStringStream:qword
    extrn '__imp_RegisterDragDrop' as RegisterDragDrop:qword
    extrn '__imp_ReleaseStgMedium' as ReleaseStgMedium:qword
    extrn '__imp_RevokeDragDrop' as RevokeDragDrop:qword
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp_RoGetAgileReference' as RoGetAgileReference:qword
    end if
    extrn '__imp_SetConvertStg' as SetConvertStg:qword
    extrn '__imp_SetDocumentBitStg' as SetDocumentBitStg:qword
    extrn '__imp_SNB_UserFree' as SNB_UserFree:qword
    extrn '__imp_SNB_UserMarshal' as SNB_UserMarshal:qword
    extrn '__imp_SNB_UserSize' as SNB_UserSize:qword
    extrn '__imp_SNB_UserUnmarshal' as SNB_UserUnmarshal:qword
    extrn '__imp_StgConvertPropertyToVariant' as StgConvertPropertyToVariant:qword
    extrn '__imp_StgConvertVariantToProperty' as StgConvertVariantToProperty:qword
    extrn '__imp_StgCreateDocfile' as StgCreateDocfile:qword
    extrn '__imp_StgCreateDocfileOnILockBytes' as StgCreateDocfileOnILockBytes:qword
    extrn '__imp_StgCreatePropSetStg' as StgCreatePropSetStg:qword
    extrn '__imp_StgCreatePropStg' as StgCreatePropStg:qword
    extrn '__imp_StgCreateStorageEx' as StgCreateStorageEx:qword
    extrn '__imp_StgGetIFillLockBytesOnFile' as StgGetIFillLockBytesOnFile:qword
    extrn '__imp_StgGetIFillLockBytesOnILockBytes' as StgGetIFillLockBytesOnILockBytes:qword
    extrn '__imp_StgIsStorageFile' as StgIsStorageFile:qword
    extrn '__imp_StgIsStorageILockBytes' as StgIsStorageILockBytes:qword
    extrn '__imp_STGMEDIUM_UserFree' as STGMEDIUM_UserFree:qword
    extrn '__imp_STGMEDIUM_UserFree64' as STGMEDIUM_UserFree64:qword
    extrn '__imp_STGMEDIUM_UserMarshal' as STGMEDIUM_UserMarshal:qword
    extrn '__imp_STGMEDIUM_UserMarshal64' as STGMEDIUM_UserMarshal64:qword
    extrn '__imp_STGMEDIUM_UserSize' as STGMEDIUM_UserSize:qword
    extrn '__imp_STGMEDIUM_UserSize64' as STGMEDIUM_UserSize64:qword
    extrn '__imp_STGMEDIUM_UserUnmarshal' as STGMEDIUM_UserUnmarshal:qword
    extrn '__imp_STGMEDIUM_UserUnmarshal64' as STGMEDIUM_UserUnmarshal64:qword
    extrn '__imp_StgOpenAsyncDocfileOnIFillLockBytes' as StgOpenAsyncDocfileOnIFillLockBytes:qword
    extrn '__imp_StgOpenPropStg' as StgOpenPropStg:qword
    extrn '__imp_StgOpenStorage' as StgOpenStorage:qword
    extrn '__imp_StgOpenStorageEx' as StgOpenStorageEx:qword
    extrn '__imp_StgOpenStorageOnILockBytes' as StgOpenStorageOnILockBytes:qword
    extrn '__imp_StgPropertyLengthAsVariant' as StgPropertyLengthAsVariant:qword
    extrn '__imp_StgSetTimes' as StgSetTimes:qword
    extrn '__imp_StringFromCLSID' as StringFromCLSID:qword
    extrn '__imp_StringFromGUID2' as StringFromGUID2:qword
    extrn '__imp_StringFromIID' as StringFromIID:qword
    extrn '__imp_UpdateDCOMSettings' as UpdateDCOMSettings:qword
    extrn '__imp_UtConvertDvtd16toDvtd32' as UtConvertDvtd16toDvtd32:qword
    extrn '__imp_UtConvertDvtd32toDvtd16' as UtConvertDvtd32toDvtd16:qword
    extrn '__imp_UtGetDvtd16Info' as UtGetDvtd16Info:qword
    extrn '__imp_UtGetDvtd32Info' as UtGetDvtd32Info:qword
    extrn '__imp_WdtpInterfacePointer_UserFree' as WdtpInterfacePointer_UserFree:qword
    extrn '__imp_WdtpInterfacePointer_UserMarshal' as WdtpInterfacePointer_UserMarshal:qword
    extrn '__imp_WdtpInterfacePointer_UserSize' as WdtpInterfacePointer_UserSize:qword
    extrn '__imp_WdtpInterfacePointer_UserUnmarshal' as WdtpInterfacePointer_UserUnmarshal:qword
    extrn '__imp_WriteClassStg' as WriteClassStg:qword
    extrn '__imp_WriteClassStm' as WriteClassStm:qword
    extrn '__imp_WriteFmtUserTypeStg' as WriteFmtUserTypeStg:qword
    extrn '__imp_WriteOleStg' as WriteOleStg:qword
    extrn '__imp_WriteStringStream' as WriteStringStream:qword
else
    extrn '__imp__BindMoniker@16' as BindMoniker:dword
    extrn '__imp__CLIPFORMAT_UserFree@8' as CLIPFORMAT_UserFree:dword
    extrn '__imp__CLIPFORMAT_UserMarshal@12' as CLIPFORMAT_UserMarshal:dword
    extrn '__imp__CLIPFORMAT_UserSize@12' as CLIPFORMAT_UserSize:dword
    extrn '__imp__CLIPFORMAT_UserUnmarshal@12' as CLIPFORMAT_UserUnmarshal:dword
    ;extrn '__imp__CLSIDFromOle1Class@12' as CLSIDFromOle1Class:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__CLSIDFromProgID@8' as CLSIDFromProgID:dword
    extrn '__imp__CLSIDFromProgIDEx@8' as CLSIDFromProgIDEx:dword
    extrn '__imp__CLSIDFromString@8' as CLSIDFromString:dword
    extrn '__imp__CoAddRefServerProcess@0' as CoAddRefServerProcess:dword
    extrn '__imp__CoAllowSetForegroundWindow@8' as CoAllowSetForegroundWindow:dword
    extrn '__imp__CoBuildVersion@0' as CoBuildVersion:dword
    extrn '__imp__CoCancelCall@8' as CoCancelCall:dword
    extrn '__imp__CoCopyProxy@8' as CoCopyProxy:dword
    extrn '__imp__CoCreateFreeThreadedMarshaler@8' as CoCreateFreeThreadedMarshaler:dword
    extrn '__imp__CoCreateGuid@4' as CoCreateGuid:dword
    extrn '__imp__CoCreateInstance@20' as CoCreateInstance:dword
    extrn '__imp__CoCreateInstanceEx@24' as CoCreateInstanceEx:dword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        if ~defined __imp__CoCreateInstanceFromApp
            extrn '__imp__CoCreateInstanceFromApp@24' as CoCreateInstanceFromApp:dword
        end if
    end if
    extrn '__imp__CoCreateObjectInContext@16' as CoCreateObjectInContext:dword
    extrn '__imp__CoDeactivateObject@8' as CoDeactivateObject:dword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__CoDecodeProxy@12' as CoDecodeProxy:dword
        extrn '__imp__CoDecrementMTAUsage@4' as CoDecrementMTAUsage:dword
    end if
    extrn '__imp__CoDisableCallCancellation@4' as CoDisableCallCancellation:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__CoDisconnectContext@4' as CoDisconnectContext:dword
    end if
    extrn '__imp__CoDisconnectObject@8' as CoDisconnectObject:dword
    extrn '__imp__CoDosDateTimeToFileTime@12' as CoDosDateTimeToFileTime:dword
    extrn '__imp__CoEnableCallCancellation@4' as CoEnableCallCancellation:dword
    extrn '__imp__CoFileTimeNow@4' as CoFileTimeNow:dword
    extrn '__imp__CoFileTimeToDosDateTime@12' as CoFileTimeToDosDateTime:dword
    extrn '__imp__CoFreeAllLibraries@0' as CoFreeAllLibraries:dword
    extrn '__imp__CoFreeLibrary@4' as CoFreeLibrary:dword
    extrn '__imp__CoFreeUnusedLibraries@0' as CoFreeUnusedLibraries:dword
    extrn '__imp__CoFreeUnusedLibrariesEx@8' as CoFreeUnusedLibrariesEx:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__CoGetActivationState@8' as CoGetActivationState:dword
    end if
    extrn '__imp__CoGetApartmentID@8' as CoGetApartmentID:dword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp__CoGetApartmentType@8' as CoGetApartmentType:dword
    end if
    extrn '__imp__CoGetCallContext@8' as CoGetCallContext:dword
    extrn '__imp__CoGetCallerTID@4' as CoGetCallerTID:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__CoGetCallState@8' as CoGetCallState:dword
    end if
    extrn '__imp__CoGetCancelObject@12' as CoGetCancelObject:dword
    extrn '__imp__CoGetClassObject@20' as CoGetClassObject:dword
    extrn '__imp__CoGetClassVersion@12' as CoGetClassVersion:dword
    extrn '__imp__CoGetContextToken@4' as CoGetContextToken:dword
    extrn '__imp__CoGetCurrentLogicalThreadId@4' as CoGetCurrentLogicalThreadId:dword
    extrn '__imp__CoGetCurrentProcess@0' as CoGetCurrentProcess:dword
    extrn '__imp__CoGetDefaultContext@12' as CoGetDefaultContext:dword
    extrn '__imp__CoGetInstanceFromFile@32' as CoGetInstanceFromFile:dword
    extrn '__imp__CoGetInstanceFromIStorage@28' as CoGetInstanceFromIStorage:dword
    extrn '__imp__CoGetInterceptor@16' as CoGetInterceptor:dword
    extrn '__imp__CoGetInterceptorFromTypeInfo@20' as CoGetInterceptorFromTypeInfo:dword
    extrn '__imp__CoGetInterfaceAndReleaseStream@12' as CoGetInterfaceAndReleaseStream:dword
    extrn '__imp__CoGetMalloc@8' as CoGetMalloc:dword
    extrn '__imp__CoGetMarshalSizeMax@24' as CoGetMarshalSizeMax:dword
    ;extrn '__imp__CoGetModuleType@8' as CoGetModuleType:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__CoGetObject@16' as CoGetObject:dword
    extrn '__imp__CoGetObjectContext@8' as CoGetObjectContext:dword
    extrn '__imp__CoGetProcessIdentifier@4' as CoGetProcessIdentifier:dword
    extrn '__imp__CoGetPSClsid@8' as CoGetPSClsid:dword
    extrn '__imp__CoGetStandardMarshal@24' as CoGetStandardMarshal:dword
    if (NTDDI_VERSION <= NTDDI_VISTA)
        extrn '__imp__CoGetState@4' as CoGetState:dword
    end if
    extrn '__imp__CoGetStdMarshalEx@12' as CoGetStdMarshalEx:dword
    extrn '__imp__CoGetSystemSecurityPermissions@8' as CoGetSystemSecurityPermissions:dword
    extrn '__imp__CoGetTreatAsClass@8' as CoGetTreatAsClass:dword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__CoHandlePriorityEventsFromMessagePump@0' as CoHandlePriorityEventsFromMessagePump:dword
    end if
    extrn '__imp__CoImpersonateClient@0' as CoImpersonateClient:dword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__CoIncrementMTAUsage@4' as CoIncrementMTAUsage:dword
    end if
    extrn '__imp__CoInitialize@4' as CoInitialize:dword
    extrn '__imp__CoInitializeEx@8' as CoInitializeEx:dword
    extrn '__imp__CoInitializeSecurity@36' as CoInitializeSecurity:dword
    extrn '__imp__CoInitializeWOW@8' as CoInitializeWOW:dword
    extrn '__imp__CoInstall@20' as CoInstall:dword
    extrn '__imp__CoInvalidateRemoteMachineBindings@4' as CoInvalidateRemoteMachineBindings:dword
    extrn '__imp__CoIsHandlerConnected@4' as CoIsHandlerConnected:dword
    extrn '__imp__CoIsOle1Class@4' as CoIsOle1Class:dword
    extrn '__imp__CoLoadLibrary@8' as CoLoadLibrary:dword
    extrn '__imp__CoLockObjectExternal@12' as CoLockObjectExternal:dword
    extrn '__imp__CoMarshalHresult@8' as CoMarshalHresult:dword
    extrn '__imp__CoMarshalInterface@24' as CoMarshalInterface:dword
    extrn '__imp__CoMarshalInterThreadInterfaceInStream@12' as CoMarshalInterThreadInterfaceInStream:dword
    extrn '__imp__ComPs_NdrDllCanUnloadNow@4' as ComPs_NdrDllCanUnloadNow:dword
    extrn '__imp__ComPs_NdrDllGetClassObject@24' as ComPs_NdrDllGetClassObject:dword
    extrn '__imp__ComPs_NdrDllRegisterProxy@20' as ComPs_NdrDllRegisterProxy:dword
    extrn '__imp__ComPs_NdrDllUnregisterProxy@20' as ComPs_NdrDllUnregisterProxy:dword
    extrn '__imp__CoQueryAuthenticationServices@8' as CoQueryAuthenticationServices:dword
    extrn '__imp__CoQueryClientBlanket@28' as CoQueryClientBlanket:dword
    extrn '__imp__CoQueryProxyBlanket@32' as CoQueryProxyBlanket:dword
    extrn '__imp__CoQueryReleaseObject@4' as CoQueryReleaseObject:dword
    extrn '__imp__CoReactivateObject@8' as CoReactivateObject:dword
    extrn '__imp__CoRegisterChannelHook@8' as CoRegisterChannelHook:dword
    extrn '__imp__CoRegisterClassObject@20' as CoRegisterClassObject:dword
    extrn '__imp__CoRegisterInitializeSpy@8' as CoRegisterInitializeSpy:dword
    extrn '__imp__CoRegisterMallocSpy@4' as CoRegisterMallocSpy:dword
    extrn '__imp__CoRegisterMessageFilter@8' as CoRegisterMessageFilter:dword
    extrn '__imp__CoRegisterPSClsid@8' as CoRegisterPSClsid:dword
    extrn '__imp__CoRegisterSurrogate@4' as CoRegisterSurrogate:dword
    extrn '__imp__CoRegisterSurrogateEx@8' as CoRegisterSurrogateEx:dword
    extrn '__imp__CoReleaseMarshalData@4' as CoReleaseMarshalData:dword
    extrn '__imp__CoReleaseServerProcess@0' as CoReleaseServerProcess:dword
    extrn '__imp__CoResumeClassObjects@0' as CoResumeClassObjects:dword
    extrn '__imp__CoRetireServer@4' as CoRetireServer:dword
    extrn '__imp__CoRevertToSelf@0' as CoRevertToSelf:dword
    extrn '__imp__CoRevokeClassObject@4' as CoRevokeClassObject:dword
    extrn '__imp__CoRevokeInitializeSpy@8' as CoRevokeInitializeSpy:dword
    extrn '__imp__CoRevokeMallocSpy@0' as CoRevokeMallocSpy:dword
    extrn '__imp__CoSetCancelObject@4' as CoSetCancelObject:dword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__CoSetMessageDispatcher@4' as CoSetMessageDispatcher:dword
    end if
    extrn '__imp__CoSetProxyBlanket@32' as CoSetProxyBlanket:dword
    extrn '__imp__CoSetState@4' as CoSetState:dword
    extrn '__imp__CoSuspendClassObjects@0' as CoSuspendClassObjects:dword
    extrn '__imp__CoSwitchCallContext@8' as CoSwitchCallContext:dword
    extrn '__imp__CoTaskMemAlloc@4' as CoTaskMemAlloc:dword
    extrn '__imp__CoTaskMemFree@4' as CoTaskMemFree:dword
    extrn '__imp__CoTaskMemRealloc@8' as CoTaskMemRealloc:dword
    extrn '__imp__CoTestCancel@0' as CoTestCancel:dword
    extrn '__imp__CoTreatAsClass@8' as CoTreatAsClass:dword
    extrn '__imp__CoUninitialize@0' as CoUninitialize:dword
    extrn '__imp__CoUnloadingWOW@4' as CoUnloadingWOW:dword
    extrn '__imp__CoUnmarshalHresult@8' as CoUnmarshalHresult:dword
    extrn '__imp__CoUnmarshalInterface@12' as CoUnmarshalInterface:dword
    extrn '__imp__CoWaitForMultipleHandles@20' as CoWaitForMultipleHandles:dword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__CoWaitForMultipleObjects@20' as CoWaitForMultipleObjects:dword
    end if
    extrn '__imp__CreateAntiMoniker@4' as CreateAntiMoniker:dword
    extrn '__imp__CreateBindCtx@8' as CreateBindCtx:dword
    extrn '__imp__CreateClassMoniker@8' as CreateClassMoniker:dword
    extrn '__imp__CreateDataAdviseHolder@4' as CreateDataAdviseHolder:dword
    extrn '__imp__CreateDataCache@16' as CreateDataCache:dword
    extrn '__imp__CreateFileMoniker@8' as CreateFileMoniker:dword
    extrn '__imp__CreateGenericComposite@12' as CreateGenericComposite:dword
    extrn '__imp__CreateILockBytesOnHGlobal@12' as CreateILockBytesOnHGlobal:dword
    extrn '__imp__CreateItemMoniker@12' as CreateItemMoniker:dword
    extrn '__imp__CreateObjrefMoniker@8' as CreateObjrefMoniker:dword
    extrn '__imp__CreateOleAdviseHolder@4' as CreateOleAdviseHolder:dword
    extrn '__imp__CreatePointerMoniker@8' as CreatePointerMoniker:dword
    extrn '__imp__CreateStdProgressIndicator@16' as CreateStdProgressIndicator:dword
    extrn '__imp__CreateStreamOnHGlobal@12' as CreateStreamOnHGlobal:dword
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp__CStdAsyncStubBuffer_AddRef@4' as CStdAsyncStubBuffer_AddRef:dword
        extrn '__imp__CStdAsyncStubBuffer_Connect@8' as CStdAsyncStubBuffer_Connect:dword
        extrn '__imp__CStdAsyncStubBuffer_Disconnect@4' as CStdAsyncStubBuffer_Disconnect:dword
        extrn '__imp__CStdAsyncStubBuffer_Invoke@12' as CStdAsyncStubBuffer_Invoke:dword
        extrn '__imp__CStdAsyncStubBuffer_QueryInterface@12' as CStdAsyncStubBuffer_QueryInterface:dword
        extrn '__imp__CStdAsyncStubBuffer_Release@4' as CStdAsyncStubBuffer_Release:dword
        extrn '__imp__CStdAsyncStubBuffer2_Connect@8' as CStdAsyncStubBuffer2_Connect:dword
        extrn '__imp__CStdAsyncStubBuffer2_Disconnect@4' as CStdAsyncStubBuffer2_Disconnect:dword
        extrn '__imp__CStdAsyncStubBuffer2_Release@4' as CStdAsyncStubBuffer2_Release:dword
        extrn '__imp__CStdStubBuffer2_Connect@8' as CStdStubBuffer2_Connect:dword
        extrn '__imp__CStdStubBuffer2_CountRefs@4' as CStdStubBuffer2_CountRefs:dword
        extrn '__imp__CStdStubBuffer2_Disconnect@4' as CStdStubBuffer2_Disconnect:dword
        extrn '__imp__CStdStubBuffer2_QueryInterface@12' as CStdStubBuffer2_QueryInterface:dword
    end if
    extrn '__imp__DcomChannelSetHResult@12' as DcomChannelSetHResult:dword
    extrn '__imp__DllDebugObjectRPCHook@8' as DllDebugObjectRPCHook:dword
    ;extrn '__imp__DllGetClassObject@12' as DllGetClassObject:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__DllGetClassObjectWOW@12' as DllGetClassObjectWOW:dword
    extrn '__imp__DoDragDrop@16' as DoDragDrop:dword
    extrn '__imp__EnableHookObject@8' as EnableHookObject:dword
    extrn '__imp__FmtIdToPropStgName@8' as FmtIdToPropStgName:dword
    extrn '__imp__FreePropVariantArray@8' as FreePropVariantArray:dword
    extrn '__imp__GetClassFile@8' as GetClassFile:dword
    extrn '__imp__GetConvertStg@4' as GetConvertStg:dword
    extrn '__imp__GetDocumentBitStg@4' as GetDocumentBitStg:dword
    extrn '__imp__GetHGlobalFromILockBytes@8' as GetHGlobalFromILockBytes:dword
    extrn '__imp__GetHGlobalFromStream@8' as GetHGlobalFromStream:dword
    extrn '__imp__GetHookInterface@4' as GetHookInterface:dword
    extrn '__imp__GetRunningObjectTable@8' as GetRunningObjectTable:dword
    extrn '__imp__HACCEL_UserFree@8' as HACCEL_UserFree:dword
    extrn '__imp__HACCEL_UserMarshal@12' as HACCEL_UserMarshal:dword
    extrn '__imp__HACCEL_UserSize@12' as HACCEL_UserSize:dword
    extrn '__imp__HACCEL_UserUnmarshal@12' as HACCEL_UserUnmarshal:dword
    extrn '__imp__HBITMAP_UserFree@8' as HBITMAP_UserFree:dword
    extrn '__imp__HBITMAP_UserMarshal@12' as HBITMAP_UserMarshal:dword
    extrn '__imp__HBITMAP_UserSize@12' as HBITMAP_UserSize:dword
    extrn '__imp__HBITMAP_UserUnmarshal@12' as HBITMAP_UserUnmarshal:dword
    extrn '__imp__HBRUSH_UserFree@8' as HBRUSH_UserFree:dword
    extrn '__imp__HBRUSH_UserMarshal@12' as HBRUSH_UserMarshal:dword
    extrn '__imp__HBRUSH_UserSize@12' as HBRUSH_UserSize:dword
    extrn '__imp__HBRUSH_UserUnmarshal@12' as HBRUSH_UserUnmarshal:dword
    extrn '__imp__HDC_UserFree@8' as HDC_UserFree:dword
    extrn '__imp__HDC_UserMarshal@12' as HDC_UserMarshal:dword
    extrn '__imp__HDC_UserSize@12' as HDC_UserSize:dword
    extrn '__imp__HDC_UserUnmarshal@12' as HDC_UserUnmarshal:dword
    extrn '__imp__HENHMETAFILE_UserFree@8' as HENHMETAFILE_UserFree:dword
    extrn '__imp__HENHMETAFILE_UserMarshal@12' as HENHMETAFILE_UserMarshal:dword
    extrn '__imp__HENHMETAFILE_UserSize@12' as HENHMETAFILE_UserSize:dword
    extrn '__imp__HENHMETAFILE_UserUnmarshal@12' as HENHMETAFILE_UserUnmarshal:dword
    extrn '__imp__HGLOBAL_UserFree@8' as HGLOBAL_UserFree:dword
    extrn '__imp__HGLOBAL_UserMarshal@12' as HGLOBAL_UserMarshal:dword
    extrn '__imp__HGLOBAL_UserSize@12' as HGLOBAL_UserSize:dword
    extrn '__imp__HGLOBAL_UserUnmarshal@12' as HGLOBAL_UserUnmarshal:dword
    extrn '__imp__HICON_UserFree@8' as HICON_UserFree:dword
    extrn '__imp__HICON_UserMarshal@12' as HICON_UserMarshal:dword
    extrn '__imp__HICON_UserSize@12' as HICON_UserSize:dword
    extrn '__imp__HICON_UserUnmarshal@12' as HICON_UserUnmarshal:dword
    extrn '__imp__HkOleRegisterObject@16' as HkOleRegisterObject:dword
    extrn '__imp__HMENU_UserFree@8' as HMENU_UserFree:dword
    extrn '__imp__HMENU_UserMarshal@12' as HMENU_UserMarshal:dword
    extrn '__imp__HMENU_UserSize@12' as HMENU_UserSize:dword
    extrn '__imp__HMENU_UserUnmarshal@12' as HMENU_UserUnmarshal:dword
    extrn '__imp__HMETAFILE_UserFree@8' as HMETAFILE_UserFree:dword
    extrn '__imp__HMETAFILE_UserMarshal@12' as HMETAFILE_UserMarshal:dword
    extrn '__imp__HMETAFILE_UserSize@12' as HMETAFILE_UserSize:dword
    extrn '__imp__HMETAFILE_UserUnmarshal@12' as HMETAFILE_UserUnmarshal:dword
    extrn '__imp__HMETAFILEPICT_UserFree@8' as HMETAFILEPICT_UserFree:dword
    extrn '__imp__HMETAFILEPICT_UserMarshal@12' as HMETAFILEPICT_UserMarshal:dword
    extrn '__imp__HMETAFILEPICT_UserSize@12' as HMETAFILEPICT_UserSize:dword
    extrn '__imp__HMETAFILEPICT_UserUnmarshal@12' as HMETAFILEPICT_UserUnmarshal:dword
    extrn '__imp__HPALETTE_UserFree@8' as HPALETTE_UserFree:dword
    extrn '__imp__HPALETTE_UserMarshal@12' as HPALETTE_UserMarshal:dword
    extrn '__imp__HPALETTE_UserSize@12' as HPALETTE_UserSize:dword
    extrn '__imp__HPALETTE_UserUnmarshal@12' as HPALETTE_UserUnmarshal:dword
    extrn '__imp__HWND_UserFree@8' as HWND_UserFree:dword
    extrn '__imp__HWND_UserMarshal@12' as HWND_UserMarshal:dword
    extrn '__imp__HWND_UserSize@12' as HWND_UserSize:dword
    extrn '__imp__HWND_UserUnmarshal@12' as HWND_UserUnmarshal:dword
    extrn '__imp__IIDFromString@8' as IIDFromString:dword
    extrn '__imp__IsAccelerator@16' as IsAccelerator:dword
    extrn '__imp__IsEqualGUID@8' as IsEqualGUID:dword
    extrn '__imp__IsValidIid@4' as IsValidIid:dword
    extrn '__imp__IsValidInterface@4' as IsValidInterface:dword
    extrn '__imp__IsValidPtrIn@8' as IsValidPtrIn:dword
    extrn '__imp__IsValidPtrOut@8' as IsValidPtrOut:dword
    extrn '__imp__MkParseDisplayName@16' as MkParseDisplayName:dword
    extrn '__imp__MonikerCommonPrefixWith@12' as MonikerCommonPrefixWith:dword
    extrn '__imp__MonikerRelativePathTo@16' as MonikerRelativePathTo:dword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp__NdrOleInitializeExtension@8' as NdrOleInitializeExtension:dword
    end if
    extrn '__imp__OleBuildVersion@0' as OleBuildVersion:dword
    extrn '__imp__OleConvertIStorageToOLESTREAM@8' as OleConvertIStorageToOLESTREAM:dword
    extrn '__imp__OleConvertIStorageToOLESTREAMEx@28' as OleConvertIStorageToOLESTREAMEx:dword
    extrn '__imp__OleConvertOLESTREAMToIStorage@12' as OleConvertOLESTREAMToIStorage:dword
    extrn '__imp__OleConvertOLESTREAMToIStorageEx@28' as OleConvertOLESTREAMToIStorageEx:dword
    extrn '__imp__OleCreate@28' as OleCreate:dword
    extrn '__imp__OleCreateDefaultHandler@16' as OleCreateDefaultHandler:dword
    extrn '__imp__OleCreateEmbeddingHelper@24' as OleCreateEmbeddingHelper:dword
    extrn '__imp__OleCreateEx@48' as OleCreateEx:dword
    extrn '__imp__OleCreateFromData@28' as OleCreateFromData:dword
    extrn '__imp__OleCreateFromDataEx@48' as OleCreateFromDataEx:dword
    extrn '__imp__OleCreateFromFile@32' as OleCreateFromFile:dword
    extrn '__imp__OleCreateFromFileEx@52' as OleCreateFromFileEx:dword
    extrn '__imp__OleCreateLink@28' as OleCreateLink:dword
    extrn '__imp__OleCreateLinkEx@48' as OleCreateLinkEx:dword
    extrn '__imp__OleCreateLinkFromData@28' as OleCreateLinkFromData:dword
    extrn '__imp__OleCreateLinkFromDataEx@48' as OleCreateLinkFromDataEx:dword
    extrn '__imp__OleCreateLinkToFile@28' as OleCreateLinkToFile:dword
    extrn '__imp__OleCreateLinkToFileEx@48' as OleCreateLinkToFileEx:dword
    extrn '__imp__OleCreateMenuDescriptor@8' as OleCreateMenuDescriptor:dword
    extrn '__imp__OleCreateStaticFromData@28' as OleCreateStaticFromData:dword
    extrn '__imp__OleDestroyMenuDescriptor@4' as OleDestroyMenuDescriptor:dword
    extrn '__imp__OleDoAutoConvert@8' as OleDoAutoConvert:dword
    extrn '__imp__OleDraw@16' as OleDraw:dword
    extrn '__imp__OleDuplicateData@12' as OleDuplicateData:dword
    extrn '__imp__OleFlushClipboard@0' as OleFlushClipboard:dword
    extrn '__imp__OleGetAutoConvert@8' as OleGetAutoConvert:dword
    extrn '__imp__OleGetClipboard@4' as OleGetClipboard:dword
    extrn '__imp__OleGetIconOfClass@12' as OleGetIconOfClass:dword
    extrn '__imp__OleGetIconOfFile@8' as OleGetIconOfFile:dword
    extrn '__imp__OleInitialize@4' as OleInitialize:dword
    extrn '__imp__OleInitializeWOW@8' as OleInitializeWOW:dword
    extrn '__imp__OleIsCurrentClipboard@4' as OleIsCurrentClipboard:dword
    extrn '__imp__OleIsRunning@4' as OleIsRunning:dword
    extrn '__imp__OleLoad@16' as OleLoad:dword
    extrn '__imp__OleLoadFromStream@12' as OleLoadFromStream:dword
    extrn '__imp__OleLockRunning@12' as OleLockRunning:dword
    extrn '__imp__OleMetafilePictFromIconAndLabel@16' as OleMetafilePictFromIconAndLabel:dword
    extrn '__imp__OleNoteObjectVisible@8' as OleNoteObjectVisible:dword
    extrn '__imp__OleQueryCreateFromData@4' as OleQueryCreateFromData:dword
    extrn '__imp__OleQueryLinkFromData@4' as OleQueryLinkFromData:dword
    extrn '__imp__OleRegEnumFormatEtc@12' as OleRegEnumFormatEtc:dword
    extrn '__imp__OleRegEnumVerbs@8' as OleRegEnumVerbs:dword
    extrn '__imp__OleRegGetMiscStatus@12' as OleRegGetMiscStatus:dword
    extrn '__imp__OleRegGetUserType@12' as OleRegGetUserType:dword
    extrn '__imp__OleRun@4' as OleRun:dword
    extrn '__imp__OleSave@12' as OleSave:dword
    extrn '__imp__OleSaveToStream@8' as OleSaveToStream:dword
    extrn '__imp__OleSetAutoConvert@8' as OleSetAutoConvert:dword
    extrn '__imp__OleSetClipboard@4' as OleSetClipboard:dword
    extrn '__imp__OleSetContainedObject@8' as OleSetContainedObject:dword
    extrn '__imp__OleSetMenuDescriptor@20' as OleSetMenuDescriptor:dword
    extrn '__imp__OleTranslateAccelerator@12' as OleTranslateAccelerator:dword
    extrn '__imp__OleUninitialize@0' as OleUninitialize:dword
    extrn '__imp__OpenOrCreateStream@12' as OpenOrCreateStream:dword
    extrn '__imp__ProgIDFromCLSID@8' as ProgIDFromCLSID:dword
    extrn '__imp__PropStgNameToFmtId@8' as PropStgNameToFmtId:dword
    extrn '__imp__PropSysAllocString@4' as PropSysAllocString:dword
    extrn '__imp__PropSysFreeString@4' as PropSysFreeString:dword
    ;extrn '__imp__PropVariantChangeType@16' as PropVariantChangeType:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__PropVariantClear@4' as PropVariantClear:dword
    extrn '__imp__PropVariantCopy@8' as PropVariantCopy:dword
    extrn '__imp__ReadClassStg@8' as ReadClassStg:dword
    extrn '__imp__ReadClassStm@8' as ReadClassStm:dword
    extrn '__imp__ReadFmtUserTypeStg@12' as ReadFmtUserTypeStg:dword
    extrn '__imp__ReadOleStg@24' as ReadOleStg:dword
    extrn '__imp__ReadStringStream@8' as ReadStringStream:dword
    extrn '__imp__RegisterDragDrop@8' as RegisterDragDrop:dword
    extrn '__imp__ReleaseStgMedium@4' as ReleaseStgMedium:dword
    extrn '__imp__RevokeDragDrop@4' as RevokeDragDrop:dword
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp__RoGetAgileReference@16' as RoGetAgileReference:dword
    end if
    extrn '__imp__SetConvertStg@8' as SetConvertStg:dword
    extrn '__imp__SetDocumentBitStg@8' as SetDocumentBitStg:dword
    extrn '__imp__SNB_UserFree@8' as SNB_UserFree:dword
    extrn '__imp__SNB_UserMarshal@12' as SNB_UserMarshal:dword
    extrn '__imp__SNB_UserSize@12' as SNB_UserSize:dword
    extrn '__imp__SNB_UserUnmarshal@12' as SNB_UserUnmarshal:dword
    extrn '__imp__StgConvertPropertyToVariant@16' as StgConvertPropertyToVariant:dword
    extrn '__imp__StgConvertVariantToProperty@28' as StgConvertVariantToProperty:dword
    extrn '__imp__StgCreateDocfile@16' as StgCreateDocfile:dword
    extrn '__imp__StgCreateDocfileOnILockBytes@16' as StgCreateDocfileOnILockBytes:dword
    extrn '__imp__StgCreatePropSetStg@12' as StgCreatePropSetStg:dword
    extrn '__imp__StgCreatePropStg@24' as StgCreatePropStg:dword
    extrn '__imp__StgCreateStorageEx@32' as StgCreateStorageEx:dword
    extrn '__imp__StgGetIFillLockBytesOnFile@8' as StgGetIFillLockBytesOnFile:dword
    extrn '__imp__StgGetIFillLockBytesOnILockBytes@8' as StgGetIFillLockBytesOnILockBytes:dword
    extrn '__imp__StgIsStorageFile@4' as StgIsStorageFile:dword
    extrn '__imp__StgIsStorageILockBytes@4' as StgIsStorageILockBytes:dword
    extrn '__imp__STGMEDIUM_UserFree@8' as STGMEDIUM_UserFree:dword
    ;extrn '__imp__STGMEDIUM_UserFree64@8' as STGMEDIUM_UserFree64:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__STGMEDIUM_UserMarshal@12' as STGMEDIUM_UserMarshal:dword
    ;extrn '__imp__STGMEDIUM_UserMarshal64@12' as STGMEDIUM_UserMarshal64:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__STGMEDIUM_UserSize@12' as STGMEDIUM_UserSize:dword
    ;extrn '__imp__STGMEDIUM_UserSize64@12' as STGMEDIUM_UserSize64:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__STGMEDIUM_UserUnmarshal@12' as STGMEDIUM_UserUnmarshal:dword
    ;extrn '__imp__STGMEDIUM_UserUnmarshal64@12' as STGMEDIUM_UserUnmarshal64:dword ;Not present in MASM32 ol32.lib
    extrn '__imp__StgOpenAsyncDocfileOnIFillLockBytes@16' as StgOpenAsyncDocfileOnIFillLockBytes:dword
    extrn '__imp__StgOpenPropStg@20' as StgOpenPropStg:dword
    extrn '__imp__StgOpenStorage@24' as StgOpenStorage:dword
    extrn '__imp__StgOpenStorageEx@32' as StgOpenStorageEx:dword
    extrn '__imp__StgOpenStorageOnILockBytes@24' as StgOpenStorageOnILockBytes:dword
    extrn '__imp__StgPropertyLengthAsVariant@16' as StgPropertyLengthAsVariant:dword
    extrn '__imp__StgSetTimes@16' as StgSetTimes:dword
    extrn '__imp__StringFromCLSID@8' as StringFromCLSID:dword
    extrn '__imp__StringFromGUID2@12' as StringFromGUID2:dword
    extrn '__imp__StringFromIID@8' as StringFromIID:dword
    extrn '__imp__UpdateDCOMSettings@0' as UpdateDCOMSettings:dword
    extrn '__imp__UtConvertDvtd16toDvtd32@12' as UtConvertDvtd16toDvtd32:dword
    extrn '__imp__UtConvertDvtd32toDvtd16@12' as UtConvertDvtd32toDvtd16:dword
    extrn '__imp__UtGetDvtd16Info@8' as UtGetDvtd16Info:dword
    extrn '__imp__UtGetDvtd32Info@8' as UtGetDvtd32Info:dword
    extrn '__imp__WdtpInterfacePointer_UserFree@4' as WdtpInterfacePointer_UserFree:dword
    extrn '__imp__WdtpInterfacePointer_UserMarshal@20' as WdtpInterfacePointer_UserMarshal:dword
    extrn '__imp__WdtpInterfacePointer_UserSize@20' as WdtpInterfacePointer_UserSize:dword
    extrn '__imp__WdtpInterfacePointer_UserUnmarshal@16' as WdtpInterfacePointer_UserUnmarshal:dword
    extrn '__imp__WriteClassStg@8' as WriteClassStg:dword
    extrn '__imp__WriteClassStm@8' as WriteClassStm:dword
    extrn '__imp__WriteFmtUserTypeStg@12' as WriteFmtUserTypeStg:dword
    extrn '__imp__WriteOleStg@16' as WriteOleStg:dword
    extrn '__imp__WriteStringStream@8' as WriteStringStream:dword
end if


;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
;    extrn '__imp_CheckInitDde' as CheckInitDde:qword
;    extrn '__imp_CleanROTForApartment' as CleanROTForApartment:qword
;    extrn '__imp_ClipboardProcessUninitialize' as ClipboardProcessUninitialize:qword
;    extrn '__imp_CLIPFORMAT_UserFree64' as CLIPFORMAT_UserFree64:qword
;    extrn '__imp_CLIPFORMAT_UserFreeExt' as CLIPFORMAT_UserFreeExt:qword
;    extrn '__imp_CLIPFORMAT_UserMarshal64' as CLIPFORMAT_UserMarshal64:qword
;    extrn '__imp_CLIPFORMAT_UserMarshalExt' as CLIPFORMAT_UserMarshalExt:qword
;    extrn '__imp_CLIPFORMAT_UserSize64' as CLIPFORMAT_UserSize64:qword
;    extrn '__imp_CLIPFORMAT_UserSizeExt' as CLIPFORMAT_UserSizeExt:qword
;    extrn '__imp_CLIPFORMAT_UserUnmarshal64' as CLIPFORMAT_UserUnmarshal64:qword
;    extrn '__imp_CLIPFORMAT_UserUnmarshalExt' as CLIPFORMAT_UserUnmarshalExt:qword
;    extrn '__imp_CoAicGetTokenForCOM' as CoAicGetTokenForCOM:qword
;    extrn '__imp_CoAllowUnmarshalerCLSID' as CoAllowUnmarshalerCLSID:qword
;    extrn '__imp_CoCheckElevationEnabled' as CoCheckElevationEnabled:qword
;    extrn '__imp_CoGetComCatalog' as CoGetComCatalog:qword
;    extrn '__imp_CoGetInterceptorForOle32' as CoGetInterceptorForOle32:qword
;    extrn '__imp_CoGetSystemWow64DirectoryW' as CoGetSystemWow64DirectoryW:qword
;    extrn '__imp_CoPopServiceDomain' as CoPopServiceDomain:qword
;    extrn '__imp_CoPushServiceDomain' as CoPushServiceDomain:qword
;    extrn '__imp_CoRegisterActivationFilter' as CoRegisterActivationFilter:qword
;    extrn '__imp_CoVrfCheckThreadState' as CoVrfCheckThreadState:qword
;    extrn '__imp_CoVrfGetThreadState' as CoVrfGetThreadState:qword
;    extrn '__imp_CoVrfReleaseThreadState' as CoVrfReleaseThreadState:qword
;    extrn '__imp_DdeBindToObject' as DdeBindToObject:qword
;    extrn '__imp_DeletePatternAndExtensionTables' as DeletePatternAndExtensionTables:qword
;    extrn '__imp_DestroyRunningObjectTable' as DestroyRunningObjectTable:qword
;    extrn '__imp_DllRegisterServer' as DllRegisterServer:qword
;    extrn '__imp_DragDropSetFDT' as DragDropSetFDT:qword
;    extrn '__imp_FindExt' as FindExt:qword
;    extrn '__imp_GetActiveObjectExt' as GetActiveObjectExt:qword
;    extrn '__imp_GetObjectFromRotByPath' as GetObjectFromRotByPath:qword
;    extrn '__imp_HACCEL_UserFree64' as HACCEL_UserFree64:qword
;    extrn '__imp_HACCEL_UserMarshal64' as HACCEL_UserMarshal64:qword
;    extrn '__imp_HACCEL_UserSize64' as HACCEL_UserSize64:qword
;    extrn '__imp_HACCEL_UserUnmarshal64' as HACCEL_UserUnmarshal64:qword
;    extrn '__imp_HBITMAP_UserFree64' as HBITMAP_UserFree64:qword
;    extrn '__imp_HBITMAP_UserMarshal64' as HBITMAP_UserMarshal64:qword
;    extrn '__imp_HBITMAP_UserSize64' as HBITMAP_UserSize64:qword
;    extrn '__imp_HBITMAP_UserUnmarshal64' as HBITMAP_UserUnmarshal64:qword
;    extrn '__imp_HBRUSH_UserFree64' as HBRUSH_UserFree64:qword
;    extrn '__imp_HBRUSH_UserMarshal64' as HBRUSH_UserMarshal64:qword
;    extrn '__imp_HBRUSH_UserSize64' as HBRUSH_UserSize64:qword
;    extrn '__imp_HBRUSH_UserUnmarshal64' as HBRUSH_UserUnmarshal64:qword
;    extrn '__imp_HDC_UserFree64' as HDC_UserFree64:qword
;    extrn '__imp_HDC_UserMarshal64' as HDC_UserMarshal64:qword
;    extrn '__imp_HDC_UserSize64' as HDC_UserSize64:qword
;    extrn '__imp_HDC_UserUnmarshal64' as HDC_UserUnmarshal64:qword
;    extrn '__imp_HENHMETAFILE_UserFree64' as HENHMETAFILE_UserFree64:qword
;    extrn '__imp_HENHMETAFILE_UserMarshal64' as HENHMETAFILE_UserMarshal64:qword
;    extrn '__imp_HENHMETAFILE_UserSize64' as HENHMETAFILE_UserSize64:qword
;    extrn '__imp_HENHMETAFILE_UserUnmarshal64' as HENHMETAFILE_UserUnmarshal64:qword
;    extrn '__imp_HGLOBAL_UserFree64' as HGLOBAL_UserFree64:qword
;    extrn '__imp_HGLOBAL_UserMarshal64' as HGLOBAL_UserMarshal64:qword
;    extrn '__imp_HGLOBAL_UserSize64' as HGLOBAL_UserSize64:qword
;    extrn '__imp_HGLOBAL_UserUnmarshal64' as HGLOBAL_UserUnmarshal64:qword
;    extrn '__imp_HICON_UserFree64' as HICON_UserFree64:qword
;    extrn '__imp_HICON_UserMarshal64' as HICON_UserMarshal64:qword
;    extrn '__imp_HICON_UserSize64' as HICON_UserSize64:qword
;    extrn '__imp_HICON_UserUnmarshal64' as HICON_UserUnmarshal64:qword
;    extrn '__imp_HMENU_UserFree64' as HMENU_UserFree64:qword
;    extrn '__imp_HMENU_UserMarshal64' as HMENU_UserMarshal64:qword
;    extrn '__imp_HMENU_UserSize64' as HMENU_UserSize64:qword
;    extrn '__imp_HMENU_UserUnmarshal64' as HMENU_UserUnmarshal64:qword
;    extrn '__imp_HMETAFILE_UserFree64' as HMETAFILE_UserFree64:qword
;    extrn '__imp_HMETAFILE_UserMarshal64' as HMETAFILE_UserMarshal64:qword
;    extrn '__imp_HMETAFILE_UserSize64' as HMETAFILE_UserSize64:qword
;    extrn '__imp_HMETAFILE_UserUnmarshal64' as HMETAFILE_UserUnmarshal64:qword
;    extrn '__imp_HMETAFILEPICT_UserFree64' as HMETAFILEPICT_UserFree64:qword
;    extrn '__imp_HMETAFILEPICT_UserMarshal64' as HMETAFILEPICT_UserMarshal64:qword
;    extrn '__imp_HMETAFILEPICT_UserSize64' as HMETAFILEPICT_UserSize64:qword
;    extrn '__imp_HMETAFILEPICT_UserUnmarshal64' as HMETAFILEPICT_UserUnmarshal64:qword
;    extrn '__imp_HMONITOR_UserFree' as HMONITOR_UserFree:qword
;    extrn '__imp_HMONITOR_UserFree64' as HMONITOR_UserFree64:qword
;    extrn '__imp_HMONITOR_UserMarshal' as HMONITOR_UserMarshal:qword
;    extrn '__imp_HMONITOR_UserMarshal64' as HMONITOR_UserMarshal64:qword
;    extrn '__imp_HMONITOR_UserSize' as HMONITOR_UserSize:qword
;    extrn '__imp_HMONITOR_UserSize64' as HMONITOR_UserSize64:qword
;    extrn '__imp_HMONITOR_UserUnmarshal' as HMONITOR_UserUnmarshal:qword
;    extrn '__imp_HMONITOR_UserUnmarshal64' as HMONITOR_UserUnmarshal64:qword
;    extrn '__imp_HPALETTE_UserFree64' as HPALETTE_UserFree64:qword
;    extrn '__imp_HPALETTE_UserFreeExt' as HPALETTE_UserFreeExt:qword
;    extrn '__imp_HPALETTE_UserMarshal64' as HPALETTE_UserMarshal64:qword
;    extrn '__imp_HPALETTE_UserMarshalExt' as HPALETTE_UserMarshalExt:qword
;    extrn '__imp_HPALETTE_UserSize64' as HPALETTE_UserSize64:qword
;    extrn '__imp_HPALETTE_UserSizeExt' as HPALETTE_UserSizeExt:qword
;    extrn '__imp_HPALETTE_UserUnmarshal64' as HPALETTE_UserUnmarshal64:qword
;    extrn '__imp_HPALETTE_UserUnmarshalExt' as HPALETTE_UserUnmarshalExt:qword
;    extrn '__imp_HRGN_UserFree' as HRGN_UserFree:qword
;    extrn '__imp_HRGN_UserMarshal' as HRGN_UserMarshal:qword
;    extrn '__imp_HRGN_UserSize' as HRGN_UserSize:qword
;    extrn '__imp_HRGN_UserUnmarshal' as HRGN_UserUnmarshal:qword
;    extrn '__imp_HWND_UserFree64' as HWND_UserFree64:qword
;    extrn '__imp_HWND_UserFree64Ext' as HWND_UserFree64Ext:qword
;    extrn '__imp_HWND_UserFreeExt' as HWND_UserFreeExt:qword
;    extrn '__imp_HWND_UserMarshal64' as HWND_UserMarshal64:qword
;    extrn '__imp_HWND_UserMarshal64Ext' as HWND_UserMarshal64Ext:qword
;    extrn '__imp_HWND_UserMarshalExt' as HWND_UserMarshalExt:qword
;    extrn '__imp_HWND_UserSize64' as HWND_UserSize64:qword
;    extrn '__imp_HWND_UserSize64Ext' as HWND_UserSize64Ext:qword
;    extrn '__imp_HWND_UserSizeExt' as HWND_UserSizeExt:qword
;    extrn '__imp_HWND_UserUnmarshal64' as HWND_UserUnmarshal64:qword
;    extrn '__imp_HWND_UserUnmarshal64Ext' as HWND_UserUnmarshal64Ext:qword
;    extrn '__imp_HWND_UserUnmarshalExt' as HWND_UserUnmarshalExt:qword
;    extrn '__imp_IsRoInitializeASTAAllowedInDesktop' as IsRoInitializeASTAAllowedInDesktop:qword
;    extrn '__imp_MonikerLoadTypeLib' as MonikerLoadTypeLib:qword
;    extrn '__imp_NdrProxyForwardingFunction10' as NdrProxyForwardingFunction10:qword
;    extrn '__imp_NdrProxyForwardingFunction11' as NdrProxyForwardingFunction11:qword
;    extrn '__imp_NdrProxyForwardingFunction12' as NdrProxyForwardingFunction12:qword
;    extrn '__imp_NdrProxyForwardingFunction13' as NdrProxyForwardingFunction13:qword
;    extrn '__imp_NdrProxyForwardingFunction14' as NdrProxyForwardingFunction14:qword
;    extrn '__imp_NdrProxyForwardingFunction15' as NdrProxyForwardingFunction15:qword
;    extrn '__imp_NdrProxyForwardingFunction16' as NdrProxyForwardingFunction16:qword
;    extrn '__imp_NdrProxyForwardingFunction17' as NdrProxyForwardingFunction17:qword
;    extrn '__imp_NdrProxyForwardingFunction18' as NdrProxyForwardingFunction18:qword
;    extrn '__imp_NdrProxyForwardingFunction19' as NdrProxyForwardingFunction19:qword
;    extrn '__imp_NdrProxyForwardingFunction20' as NdrProxyForwardingFunction20:qword
;    extrn '__imp_NdrProxyForwardingFunction21' as NdrProxyForwardingFunction21:qword
;    extrn '__imp_NdrProxyForwardingFunction22' as NdrProxyForwardingFunction22:qword
;    extrn '__imp_NdrProxyForwardingFunction23' as NdrProxyForwardingFunction23:qword
;    extrn '__imp_NdrProxyForwardingFunction24' as NdrProxyForwardingFunction24:qword
;    extrn '__imp_NdrProxyForwardingFunction25' as NdrProxyForwardingFunction25:qword
;    extrn '__imp_NdrProxyForwardingFunction26' as NdrProxyForwardingFunction26:qword
;    extrn '__imp_NdrProxyForwardingFunction27' as NdrProxyForwardingFunction27:qword
;    extrn '__imp_NdrProxyForwardingFunction28' as NdrProxyForwardingFunction28:qword
;    extrn '__imp_NdrProxyForwardingFunction29' as NdrProxyForwardingFunction29:qword
;    extrn '__imp_NdrProxyForwardingFunction3' as NdrProxyForwardingFunction3:qword
;    extrn '__imp_NdrProxyForwardingFunction30' as NdrProxyForwardingFunction30:qword
;    extrn '__imp_NdrProxyForwardingFunction31' as NdrProxyForwardingFunction31:qword
;    extrn '__imp_NdrProxyForwardingFunction32' as NdrProxyForwardingFunction32:qword
;    extrn '__imp_NdrProxyForwardingFunction4' as NdrProxyForwardingFunction4:qword
;    extrn '__imp_NdrProxyForwardingFunction5' as NdrProxyForwardingFunction5:qword
;    extrn '__imp_NdrProxyForwardingFunction6' as NdrProxyForwardingFunction6:qword
;    extrn '__imp_NdrProxyForwardingFunction7' as NdrProxyForwardingFunction7:qword
;    extrn '__imp_NdrProxyForwardingFunction8' as NdrProxyForwardingFunction8:qword
;    extrn '__imp_NdrProxyForwardingFunction9' as NdrProxyForwardingFunction9:qword
;    extrn '__imp_ObjectStublessClient10' as ObjectStublessClient10:qword
;    extrn '__imp_ObjectStublessClient11' as ObjectStublessClient11:qword
;    extrn '__imp_ObjectStublessClient12' as ObjectStublessClient12:qword
;    extrn '__imp_ObjectStublessClient13' as ObjectStublessClient13:qword
;    extrn '__imp_ObjectStublessClient14' as ObjectStublessClient14:qword
;    extrn '__imp_ObjectStublessClient15' as ObjectStublessClient15:qword
;    extrn '__imp_ObjectStublessClient16' as ObjectStublessClient16:qword
;    extrn '__imp_ObjectStublessClient17' as ObjectStublessClient17:qword
;    extrn '__imp_ObjectStublessClient18' as ObjectStublessClient18:qword
;    extrn '__imp_ObjectStublessClient19' as ObjectStublessClient19:qword
;    extrn '__imp_ObjectStublessClient20' as ObjectStublessClient20:qword
;    extrn '__imp_ObjectStublessClient21' as ObjectStublessClient21:qword
;    extrn '__imp_ObjectStublessClient22' as ObjectStublessClient22:qword
;    extrn '__imp_ObjectStublessClient23' as ObjectStublessClient23:qword
;    extrn '__imp_ObjectStublessClient24' as ObjectStublessClient24:qword
;    extrn '__imp_ObjectStublessClient25' as ObjectStublessClient25:qword
;    extrn '__imp_ObjectStublessClient26' as ObjectStublessClient26:qword
;    extrn '__imp_ObjectStublessClient27' as ObjectStublessClient27:qword
;    extrn '__imp_ObjectStublessClient28' as ObjectStublessClient28:qword
;    extrn '__imp_ObjectStublessClient29' as ObjectStublessClient29:qword
;    extrn '__imp_ObjectStublessClient3' as ObjectStublessClient3:qword
;    extrn '__imp_ObjectStublessClient30' as ObjectStublessClient30:qword
;    extrn '__imp_ObjectStublessClient31' as ObjectStublessClient31:qword
;    extrn '__imp_ObjectStublessClient32' as ObjectStublessClient32:qword
;    extrn '__imp_ObjectStublessClient4' as ObjectStublessClient4:qword
;    extrn '__imp_ObjectStublessClient5' as ObjectStublessClient5:qword
;    extrn '__imp_ObjectStublessClient6' as ObjectStublessClient6:qword
;    extrn '__imp_ObjectStublessClient7' as ObjectStublessClient7:qword
;    extrn '__imp_ObjectStublessClient8' as ObjectStublessClient8:qword
;    extrn '__imp_ObjectStublessClient9' as ObjectStublessClient9:qword
;    extrn '__imp_OleCreateFontIndirectExt' as OleCreateFontIndirectExt:qword
;    extrn '__imp_OleCreatePictureIndirectExt' as OleCreatePictureIndirectExt:qword
;    extrn '__imp_OleCreatePropertyFrameIndirectExt' as OleCreatePropertyFrameIndirectExt:qword
;    extrn '__imp_OleGetPackageClipboardOwner' as OleGetPackageClipboardOwner:qword
;    extrn '__imp_OleIconToCursorExt' as OleIconToCursorExt:qword
;    extrn '__imp_OleLoadPictureExt' as OleLoadPictureExt:qword
;    extrn '__imp_OleLoadPictureFileExt' as OleLoadPictureFileExt:qword
;    extrn '__imp_OleLoadPicturePathExt' as OleLoadPicturePathExt:qword
;    extrn '__imp_OleReleaseEnumVerbCache' as OleReleaseEnumVerbCache:qword
;    extrn '__imp_OleSavePictureFileExt' as OleSavePictureFileExt:qword
;    extrn '__imp_OleTranslateColorExt' as OleTranslateColorExt:qword
;    extrn '__imp_ReadStorageProperties' as ReadStorageProperties:qword
;    extrn '__imp_RegisterActiveObjectExt' as RegisterActiveObjectExt:qword
;    extrn '__imp_RevokeActiveObjectExt' as RevokeActiveObjectExt:qword
;    extrn '__imp_SetOleautModule' as SetOleautModule:qword
;    extrn '__imp_SetWOWThunkGlobalPtr' as SetWOWThunkGlobalPtr:qword
;    extrn '__imp_SNB_UserFree64' as SNB_UserFree64:qword
;    extrn '__imp_SNB_UserMarshal64' as SNB_UserMarshal64:qword
;    extrn '__imp_SNB_UserSize64' as SNB_UserSize64:qword
;    extrn '__imp_SNB_UserUnmarshal64' as SNB_UserUnmarshal64:qword
;    extrn '__imp_StdTypesGetClassObject' as StdTypesGetClassObject:qword
;    extrn '__imp_StdTypesRegisterServer' as StdTypesRegisterServer:qword
;    extrn '__imp_STGMEDIUM_UserFreeExt' as STGMEDIUM_UserFreeExt:qword
;    extrn '__imp_STGMEDIUM_UserMarshalExt' as STGMEDIUM_UserMarshalExt:qword
;    extrn '__imp_STGMEDIUM_UserSizeExt' as STGMEDIUM_UserSizeExt:qword
;    extrn '__imp_STGMEDIUM_UserUnmarshalExt' as STGMEDIUM_UserUnmarshalExt:qword
;    extrn '__imp_StgOpenStorageOnHandle' as StgOpenStorageOnHandle:qword
;    extrn '__imp_UpdateProcessTracing' as UpdateProcessTracing:qword
;    extrn '__imp_WdtpInterfacePointer_UserFree64' as WdtpInterfacePointer_UserFree64:qword
;    extrn '__imp_WdtpInterfacePointer_UserMarshal64' as WdtpInterfacePointer_UserMarshal64:qword
;    extrn '__imp_WdtpInterfacePointer_UserSize64' as WdtpInterfacePointer_UserSize64:qword
;    extrn '__imp_WdtpInterfacePointer_UserUnmarshal64' as WdtpInterfacePointer_UserUnmarshal64:qword
;    extrn '__imp_WriteStorageProperties' as WriteStorageProperties:qword
;else
;    extrn '__imp__CheckInitDde@??' as CheckInitDde:dword
;    extrn '__imp__CleanROTForApartment@??' as CleanROTForApartment:dword
;    extrn '__imp__ClipboardProcessUninitialize@??' as ClipboardProcessUninitialize:dword
;    extrn '__imp__CLIPFORMAT_UserFree64@??' as CLIPFORMAT_UserFree64:dword
;    extrn '__imp__CLIPFORMAT_UserFreeExt@??' as CLIPFORMAT_UserFreeExt:dword
;    extrn '__imp__CLIPFORMAT_UserMarshal64@??' as CLIPFORMAT_UserMarshal64:dword
;    extrn '__imp__CLIPFORMAT_UserMarshalExt@??' as CLIPFORMAT_UserMarshalExt:dword
;    extrn '__imp__CLIPFORMAT_UserSize64@??' as CLIPFORMAT_UserSize64:dword
;    extrn '__imp__CLIPFORMAT_UserSizeExt@??' as CLIPFORMAT_UserSizeExt:dword
;    extrn '__imp__CLIPFORMAT_UserUnmarshal64@??' as CLIPFORMAT_UserUnmarshal64:dword
;    extrn '__imp__CLIPFORMAT_UserUnmarshalExt@??' as CLIPFORMAT_UserUnmarshalExt:dword
;    extrn '__imp__CoAicGetTokenForCOM@??' as CoAicGetTokenForCOM:dword
;    extrn '__imp__CoAllowUnmarshalerCLSID@??' as CoAllowUnmarshalerCLSID:dword
;    extrn '__imp__CoCheckElevationEnabled@??' as CoCheckElevationEnabled:dword
;    extrn '__imp__CoGetComCatalog@??' as CoGetComCatalog:dword
;    extrn '__imp__CoGetInterceptorForOle32@??' as CoGetInterceptorForOle32:dword
;    extrn '__imp__CoGetSystemWow64DirectoryW@??' as CoGetSystemWow64DirectoryW:dword
;    extrn '__imp__CoPopServiceDomain@??' as CoPopServiceDomain:dword
;    extrn '__imp__CoPushServiceDomain@??' as CoPushServiceDomain:dword
;    extrn '__imp__CoRegisterActivationFilter@??' as CoRegisterActivationFilter:dword
;    extrn '__imp__CoVrfCheckThreadState@??' as CoVrfCheckThreadState:dword
;    extrn '__imp__CoVrfGetThreadState@??' as CoVrfGetThreadState:dword
;    extrn '__imp__CoVrfReleaseThreadState@??' as CoVrfReleaseThreadState:dword
;    extrn '__imp__DdeBindToObject@??' as DdeBindToObject:dword
;    extrn '__imp__DeletePatternAndExtensionTables@??' as DeletePatternAndExtensionTables:dword
;    extrn '__imp__DestroyRunningObjectTable@??' as DestroyRunningObjectTable:dword
;    extrn '__imp__DllRegisterServer@??' as DllRegisterServer:dword
;    extrn '__imp__DragDropSetFDT@??' as DragDropSetFDT:dword
;    extrn '__imp__FindExt@??' as FindExt:dword
;    extrn '__imp__GetActiveObjectExt@??' as GetActiveObjectExt:dword
;    extrn '__imp__GetObjectFromRotByPath@??' as GetObjectFromRotByPath:dword
;    extrn '__imp__HACCEL_UserFree64@??' as HACCEL_UserFree64:dword
;    extrn '__imp__HACCEL_UserMarshal64@??' as HACCEL_UserMarshal64:dword
;    extrn '__imp__HACCEL_UserSize64@??' as HACCEL_UserSize64:dword
;    extrn '__imp__HACCEL_UserUnmarshal64@??' as HACCEL_UserUnmarshal64:dword
;    extrn '__imp__HBITMAP_UserFree64@??' as HBITMAP_UserFree64:dword
;    extrn '__imp__HBITMAP_UserMarshal64@??' as HBITMAP_UserMarshal64:dword
;    extrn '__imp__HBITMAP_UserSize64@??' as HBITMAP_UserSize64:dword
;    extrn '__imp__HBITMAP_UserUnmarshal64@??' as HBITMAP_UserUnmarshal64:dword
;    extrn '__imp__HBRUSH_UserFree64@??' as HBRUSH_UserFree64:dword
;    extrn '__imp__HBRUSH_UserMarshal64@??' as HBRUSH_UserMarshal64:dword
;    extrn '__imp__HBRUSH_UserSize64@??' as HBRUSH_UserSize64:dword
;    extrn '__imp__HBRUSH_UserUnmarshal64@??' as HBRUSH_UserUnmarshal64:dword
;    extrn '__imp__HDC_UserFree64@??' as HDC_UserFree64:dword
;    extrn '__imp__HDC_UserMarshal64@??' as HDC_UserMarshal64:dword
;    extrn '__imp__HDC_UserSize64@??' as HDC_UserSize64:dword
;    extrn '__imp__HDC_UserUnmarshal64@??' as HDC_UserUnmarshal64:dword
;    extrn '__imp__HENHMETAFILE_UserFree64@??' as HENHMETAFILE_UserFree64:dword
;    extrn '__imp__HENHMETAFILE_UserMarshal64@??' as HENHMETAFILE_UserMarshal64:dword
;    extrn '__imp__HENHMETAFILE_UserSize64@??' as HENHMETAFILE_UserSize64:dword
;    extrn '__imp__HENHMETAFILE_UserUnmarshal64@??' as HENHMETAFILE_UserUnmarshal64:dword
;    extrn '__imp__HGLOBAL_UserFree64@??' as HGLOBAL_UserFree64:dword
;    extrn '__imp__HGLOBAL_UserMarshal64@??' as HGLOBAL_UserMarshal64:dword
;    extrn '__imp__HGLOBAL_UserSize64@??' as HGLOBAL_UserSize64:dword
;    extrn '__imp__HGLOBAL_UserUnmarshal64@??' as HGLOBAL_UserUnmarshal64:dword
;    extrn '__imp__HICON_UserFree64@??' as HICON_UserFree64:dword
;    extrn '__imp__HICON_UserMarshal64@??' as HICON_UserMarshal64:dword
;    extrn '__imp__HICON_UserSize64@??' as HICON_UserSize64:dword
;    extrn '__imp__HICON_UserUnmarshal64@??' as HICON_UserUnmarshal64:dword
;    extrn '__imp__HMENU_UserFree64@??' as HMENU_UserFree64:dword
;    extrn '__imp__HMENU_UserMarshal64@??' as HMENU_UserMarshal64:dword
;    extrn '__imp__HMENU_UserSize64@??' as HMENU_UserSize64:dword
;    extrn '__imp__HMENU_UserUnmarshal64@??' as HMENU_UserUnmarshal64:dword
;    extrn '__imp__HMETAFILE_UserFree64@??' as HMETAFILE_UserFree64:dword
;    extrn '__imp__HMETAFILE_UserMarshal64@??' as HMETAFILE_UserMarshal64:dword
;    extrn '__imp__HMETAFILE_UserSize64@??' as HMETAFILE_UserSize64:dword
;    extrn '__imp__HMETAFILE_UserUnmarshal64@??' as HMETAFILE_UserUnmarshal64:dword
;    extrn '__imp__HMETAFILEPICT_UserFree64@??' as HMETAFILEPICT_UserFree64:dword
;    extrn '__imp__HMETAFILEPICT_UserMarshal64@??' as HMETAFILEPICT_UserMarshal64:dword
;    extrn '__imp__HMETAFILEPICT_UserSize64@??' as HMETAFILEPICT_UserSize64:dword
;    extrn '__imp__HMETAFILEPICT_UserUnmarshal64@??' as HMETAFILEPICT_UserUnmarshal64:dword
;    extrn '__imp__HMONITOR_UserFree@??' as HMONITOR_UserFree:dword
;    extrn '__imp__HMONITOR_UserFree64@??' as HMONITOR_UserFree64:dword
;    extrn '__imp__HMONITOR_UserMarshal@??' as HMONITOR_UserMarshal:dword
;    extrn '__imp__HMONITOR_UserMarshal64@??' as HMONITOR_UserMarshal64:dword
;    extrn '__imp__HMONITOR_UserSize@??' as HMONITOR_UserSize:dword
;    extrn '__imp__HMONITOR_UserSize64@??' as HMONITOR_UserSize64:dword
;    extrn '__imp__HMONITOR_UserUnmarshal@??' as HMONITOR_UserUnmarshal:dword
;    extrn '__imp__HMONITOR_UserUnmarshal64@??' as HMONITOR_UserUnmarshal64:dword
;    extrn '__imp__HPALETTE_UserFree64@??' as HPALETTE_UserFree64:dword
;    extrn '__imp__HPALETTE_UserFreeExt@??' as HPALETTE_UserFreeExt:dword
;    extrn '__imp__HPALETTE_UserMarshal64@??' as HPALETTE_UserMarshal64:dword
;    extrn '__imp__HPALETTE_UserMarshalExt@??' as HPALETTE_UserMarshalExt:dword
;    extrn '__imp__HPALETTE_UserSize64@??' as HPALETTE_UserSize64:dword
;    extrn '__imp__HPALETTE_UserSizeExt@??' as HPALETTE_UserSizeExt:dword
;    extrn '__imp__HPALETTE_UserUnmarshal64@??' as HPALETTE_UserUnmarshal64:dword
;    extrn '__imp__HPALETTE_UserUnmarshalExt@??' as HPALETTE_UserUnmarshalExt:dword
;    extrn '__imp__HRGN_UserFree@??' as HRGN_UserFree:dword
;    extrn '__imp__HRGN_UserMarshal@??' as HRGN_UserMarshal:dword
;    extrn '__imp__HRGN_UserSize@??' as HRGN_UserSize:dword
;    extrn '__imp__HRGN_UserUnmarshal@??' as HRGN_UserUnmarshal:dword
;    extrn '__imp__HWND_UserFree64@??' as HWND_UserFree64:dword
;    extrn '__imp__HWND_UserFree64Ext@??' as HWND_UserFree64Ext:dword
;    extrn '__imp__HWND_UserFreeExt@??' as HWND_UserFreeExt:dword
;    extrn '__imp__HWND_UserMarshal64@??' as HWND_UserMarshal64:dword
;    extrn '__imp__HWND_UserMarshal64Ext@??' as HWND_UserMarshal64Ext:dword
;    extrn '__imp__HWND_UserMarshalExt@??' as HWND_UserMarshalExt:dword
;    extrn '__imp__HWND_UserSize64@??' as HWND_UserSize64:dword
;    extrn '__imp__HWND_UserSize64Ext@??' as HWND_UserSize64Ext:dword
;    extrn '__imp__HWND_UserSizeExt@??' as HWND_UserSizeExt:dword
;    extrn '__imp__HWND_UserUnmarshal64@??' as HWND_UserUnmarshal64:dword
;    extrn '__imp__HWND_UserUnmarshal64Ext@??' as HWND_UserUnmarshal64Ext:dword
;    extrn '__imp__HWND_UserUnmarshalExt@??' as HWND_UserUnmarshalExt:dword
;    extrn '__imp__IsRoInitializeASTAAllowedInDesktop@??' as IsRoInitializeASTAAllowedInDesktop:dword
;    extrn '__imp__MonikerLoadTypeLib@??' as MonikerLoadTypeLib:dword
;    extrn '__imp__NdrProxyForwardingFunction10@??' as NdrProxyForwardingFunction10:dword
;    extrn '__imp__NdrProxyForwardingFunction11@??' as NdrProxyForwardingFunction11:dword
;    extrn '__imp__NdrProxyForwardingFunction12@??' as NdrProxyForwardingFunction12:dword
;    extrn '__imp__NdrProxyForwardingFunction13@??' as NdrProxyForwardingFunction13:dword
;    extrn '__imp__NdrProxyForwardingFunction14@??' as NdrProxyForwardingFunction14:dword
;    extrn '__imp__NdrProxyForwardingFunction15@??' as NdrProxyForwardingFunction15:dword
;    extrn '__imp__NdrProxyForwardingFunction16@??' as NdrProxyForwardingFunction16:dword
;    extrn '__imp__NdrProxyForwardingFunction17@??' as NdrProxyForwardingFunction17:dword
;    extrn '__imp__NdrProxyForwardingFunction18@??' as NdrProxyForwardingFunction18:dword
;    extrn '__imp__NdrProxyForwardingFunction19@??' as NdrProxyForwardingFunction19:dword
;    extrn '__imp__NdrProxyForwardingFunction20@??' as NdrProxyForwardingFunction20:dword
;    extrn '__imp__NdrProxyForwardingFunction21@??' as NdrProxyForwardingFunction21:dword
;    extrn '__imp__NdrProxyForwardingFunction22@??' as NdrProxyForwardingFunction22:dword
;    extrn '__imp__NdrProxyForwardingFunction23@??' as NdrProxyForwardingFunction23:dword
;    extrn '__imp__NdrProxyForwardingFunction24@??' as NdrProxyForwardingFunction24:dword
;    extrn '__imp__NdrProxyForwardingFunction25@??' as NdrProxyForwardingFunction25:dword
;    extrn '__imp__NdrProxyForwardingFunction26@??' as NdrProxyForwardingFunction26:dword
;    extrn '__imp__NdrProxyForwardingFunction27@??' as NdrProxyForwardingFunction27:dword
;    extrn '__imp__NdrProxyForwardingFunction28@??' as NdrProxyForwardingFunction28:dword
;    extrn '__imp__NdrProxyForwardingFunction29@??' as NdrProxyForwardingFunction29:dword
;    extrn '__imp__NdrProxyForwardingFunction3@??' as NdrProxyForwardingFunction3:dword
;    extrn '__imp__NdrProxyForwardingFunction30@??' as NdrProxyForwardingFunction30:dword
;    extrn '__imp__NdrProxyForwardingFunction31@??' as NdrProxyForwardingFunction31:dword
;    extrn '__imp__NdrProxyForwardingFunction32@??' as NdrProxyForwardingFunction32:dword
;    extrn '__imp__NdrProxyForwardingFunction4@??' as NdrProxyForwardingFunction4:dword
;    extrn '__imp__NdrProxyForwardingFunction5@??' as NdrProxyForwardingFunction5:dword
;    extrn '__imp__NdrProxyForwardingFunction6@??' as NdrProxyForwardingFunction6:dword
;    extrn '__imp__NdrProxyForwardingFunction7@??' as NdrProxyForwardingFunction7:dword
;    extrn '__imp__NdrProxyForwardingFunction8@??' as NdrProxyForwardingFunction8:dword
;    extrn '__imp__NdrProxyForwardingFunction9@??' as NdrProxyForwardingFunction9:dword
;    extrn '__imp__ObjectStublessClient10@??' as ObjectStublessClient10:dword
;    extrn '__imp__ObjectStublessClient11@??' as ObjectStublessClient11:dword
;    extrn '__imp__ObjectStublessClient12@??' as ObjectStublessClient12:dword
;    extrn '__imp__ObjectStublessClient13@??' as ObjectStublessClient13:dword
;    extrn '__imp__ObjectStublessClient14@??' as ObjectStublessClient14:dword
;    extrn '__imp__ObjectStublessClient15@??' as ObjectStublessClient15:dword
;    extrn '__imp__ObjectStublessClient16@??' as ObjectStublessClient16:dword
;    extrn '__imp__ObjectStublessClient17@??' as ObjectStublessClient17:dword
;    extrn '__imp__ObjectStublessClient18@??' as ObjectStublessClient18:dword
;    extrn '__imp__ObjectStublessClient19@??' as ObjectStublessClient19:dword
;    extrn '__imp__ObjectStublessClient20@??' as ObjectStublessClient20:dword
;    extrn '__imp__ObjectStublessClient21@??' as ObjectStublessClient21:dword
;    extrn '__imp__ObjectStublessClient22@??' as ObjectStublessClient22:dword
;    extrn '__imp__ObjectStublessClient23@??' as ObjectStublessClient23:dword
;    extrn '__imp__ObjectStublessClient24@??' as ObjectStublessClient24:dword
;    extrn '__imp__ObjectStublessClient25@??' as ObjectStublessClient25:dword
;    extrn '__imp__ObjectStublessClient26@??' as ObjectStublessClient26:dword
;    extrn '__imp__ObjectStublessClient27@??' as ObjectStublessClient27:dword
;    extrn '__imp__ObjectStublessClient28@??' as ObjectStublessClient28:dword
;    extrn '__imp__ObjectStublessClient29@??' as ObjectStublessClient29:dword
;    extrn '__imp__ObjectStublessClient3@??' as ObjectStublessClient3:dword
;    extrn '__imp__ObjectStublessClient30@??' as ObjectStublessClient30:dword
;    extrn '__imp__ObjectStublessClient31@??' as ObjectStublessClient31:dword
;    extrn '__imp__ObjectStublessClient32@??' as ObjectStublessClient32:dword
;    extrn '__imp__ObjectStublessClient4@??' as ObjectStublessClient4:dword
;    extrn '__imp__ObjectStublessClient5@??' as ObjectStublessClient5:dword
;    extrn '__imp__ObjectStublessClient6@??' as ObjectStublessClient6:dword
;    extrn '__imp__ObjectStublessClient7@??' as ObjectStublessClient7:dword
;    extrn '__imp__ObjectStublessClient8@??' as ObjectStublessClient8:dword
;    extrn '__imp__ObjectStublessClient9@??' as ObjectStublessClient9:dword
;    extrn '__imp__OleCreateFontIndirectExt@??' as OleCreateFontIndirectExt:dword
;    extrn '__imp__OleCreatePictureIndirectExt@??' as OleCreatePictureIndirectExt:dword
;    extrn '__imp__OleCreatePropertyFrameIndirectExt@??' as OleCreatePropertyFrameIndirectExt:dword
;    extrn '__imp__OleGetPackageClipboardOwner@??' as OleGetPackageClipboardOwner:dword
;    extrn '__imp__OleIconToCursorExt@??' as OleIconToCursorExt:dword
;    extrn '__imp__OleLoadPictureExt@??' as OleLoadPictureExt:dword
;    extrn '__imp__OleLoadPictureFileExt@??' as OleLoadPictureFileExt:dword
;    extrn '__imp__OleLoadPicturePathExt@??' as OleLoadPicturePathExt:dword
;    extrn '__imp__OleReleaseEnumVerbCache@??' as OleReleaseEnumVerbCache:dword
;    extrn '__imp__OleSavePictureFileExt@??' as OleSavePictureFileExt:dword
;    extrn '__imp__OleTranslateColorExt@??' as OleTranslateColorExt:dword
;    extrn '__imp__ReadStorageProperties@??' as ReadStorageProperties:dword
;    extrn '__imp__RegisterActiveObjectExt@??' as RegisterActiveObjectExt:dword
;    extrn '__imp__RevokeActiveObjectExt@??' as RevokeActiveObjectExt:dword
;    extrn '__imp__SetOleautModule@??' as SetOleautModule:dword
;    extrn '__imp__SetWOWThunkGlobalPtr@??' as SetWOWThunkGlobalPtr:dword
;    extrn '__imp__SNB_UserFree64@??' as SNB_UserFree64:dword
;    extrn '__imp__SNB_UserMarshal64@??' as SNB_UserMarshal64:dword
;    extrn '__imp__SNB_UserSize64@??' as SNB_UserSize64:dword
;    extrn '__imp__SNB_UserUnmarshal64@??' as SNB_UserUnmarshal64:dword
;    extrn '__imp__StdTypesGetClassObject@??' as StdTypesGetClassObject:dword
;    extrn '__imp__StdTypesRegisterServer@??' as StdTypesRegisterServer:dword
;    extrn '__imp__STGMEDIUM_UserFreeExt@??' as STGMEDIUM_UserFreeExt:dword
;    extrn '__imp__STGMEDIUM_UserMarshalExt@??' as STGMEDIUM_UserMarshalExt:dword
;    extrn '__imp__STGMEDIUM_UserSizeExt@??' as STGMEDIUM_UserSizeExt:dword
;    extrn '__imp__STGMEDIUM_UserUnmarshalExt@??' as STGMEDIUM_UserUnmarshalExt:dword
;    extrn '__imp__StgOpenStorageOnHandle@??' as StgOpenStorageOnHandle:dword
;    extrn '__imp__UpdateProcessTracing@??' as UpdateProcessTracing:dword
;    extrn '__imp__WdtpInterfacePointer_UserFree64@??' as WdtpInterfacePointer_UserFree64:dword
;    extrn '__imp__WdtpInterfacePointer_UserMarshal64@??' as WdtpInterfacePointer_UserMarshal64:dword
;    extrn '__imp__WdtpInterfacePointer_UserSize64@??' as WdtpInterfacePointer_UserSize64:dword
;    extrn '__imp__WdtpInterfacePointer_UserUnmarshal64@??' as WdtpInterfacePointer_UserUnmarshal64:dword
;    extrn '__imp__WriteStorageProperties@??' as WriteStorageProperties:dword
;end if

end if ;OLE32_INC
