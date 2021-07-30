; ====================================================;
;                                                     ;
;     ole32.inc for EC v2 SolAsm classic projects     ;
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

;======================= Undocumented functions (unknown arguments) =======================;
;import CheckInitDde
;import CleanROTForApartment
;import ClipboardProcessUninitialize
;import CLIPFORMAT_UserFree64
;import CLIPFORMAT_UserFreeExt
;import CLIPFORMAT_UserMarshal64
;import CLIPFORMAT_UserMarshalExt
;import CLIPFORMAT_UserSize64
;import CLIPFORMAT_UserSizeExt
;import CLIPFORMAT_UserUnmarshal64
;import CLIPFORMAT_UserUnmarshalExt
;import CoAicGetTokenForCOM
;import CoAllowUnmarshalerCLSID
;import CoCheckElevationEnabled
;import CoGetComCatalog
;import CoGetInterceptorForOle32
;import CoGetSystemWow64DirectoryW
;import CoPopServiceDomain
;import CoPushServiceDomain
;import CoRegisterActivationFilter
;import CoVrfCheckThreadState
;import CoVrfGetThreadState
;import CoVrfReleaseThreadState
;import DdeBindToObject
;import DeletePatternAndExtensionTables
;import DestroyRunningObjectTable
;import DllRegisterServer
;import DragDropSetFDT
;import FindExt
;import GetActiveObjectExt
;import GetObjectFromRotByPath
;import HACCEL_UserFree64
;import HACCEL_UserMarshal64
;import HACCEL_UserSize64
;import HACCEL_UserUnmarshal64
;import HBITMAP_UserFree64
;import HBITMAP_UserMarshal64
;import HBITMAP_UserSize64
;import HBITMAP_UserUnmarshal64
;import HBRUSH_UserFree64
;import HBRUSH_UserMarshal64
;import HBRUSH_UserSize64
;import HBRUSH_UserUnmarshal64
;import HDC_UserFree64
;import HDC_UserMarshal64
;import HDC_UserSize64
;import HDC_UserUnmarshal64
;import HENHMETAFILE_UserFree64
;import HENHMETAFILE_UserMarshal64
;import HENHMETAFILE_UserSize64
;import HENHMETAFILE_UserUnmarshal64
;import HGLOBAL_UserFree64
;import HGLOBAL_UserMarshal64
;import HGLOBAL_UserSize64
;import HGLOBAL_UserUnmarshal64
;import HICON_UserFree64
;import HICON_UserMarshal64
;import HICON_UserSize64
;import HICON_UserUnmarshal64
;import HMENU_UserFree64
;import HMENU_UserMarshal64
;import HMENU_UserSize64
;import HMENU_UserUnmarshal64
;import HMETAFILE_UserFree64
;import HMETAFILE_UserMarshal64
;import HMETAFILE_UserSize64
;import HMETAFILE_UserUnmarshal64
;import HMETAFILEPICT_UserFree64
;import HMETAFILEPICT_UserMarshal64
;import HMETAFILEPICT_UserSize64
;import HMETAFILEPICT_UserUnmarshal64
;import HMONITOR_UserFree
;import HMONITOR_UserFree64
;import HMONITOR_UserMarshal
;import HMONITOR_UserMarshal64
;import HMONITOR_UserSize
;import HMONITOR_UserSize64
;import HMONITOR_UserUnmarshal
;import HMONITOR_UserUnmarshal64
;import HPALETTE_UserFree64
;import HPALETTE_UserFreeExt
;import HPALETTE_UserMarshal64
;import HPALETTE_UserMarshalExt
;import HPALETTE_UserSize64
;import HPALETTE_UserSizeExt
;import HPALETTE_UserUnmarshal64
;import HPALETTE_UserUnmarshalExt
;import HRGN_UserFree
;import HRGN_UserMarshal
;import HRGN_UserSize
;import HRGN_UserUnmarshal
;import HWND_UserFree64
;import HWND_UserFree64Ext
;import HWND_UserFreeExt
;import HWND_UserMarshal64
;import HWND_UserMarshal64Ext
;import HWND_UserMarshalExt
;import HWND_UserSize64
;import HWND_UserSize64Ext
;import HWND_UserSizeExt
;import HWND_UserUnmarshal64
;import HWND_UserUnmarshal64Ext
;import HWND_UserUnmarshalExt
;import IsRoInitializeASTAAllowedInDesktop
;import MonikerLoadTypeLib
;import NdrProxyForwardingFunction10
;import NdrProxyForwardingFunction11
;import NdrProxyForwardingFunction12
;import NdrProxyForwardingFunction13
;import NdrProxyForwardingFunction14
;import NdrProxyForwardingFunction15
;import NdrProxyForwardingFunction16
;import NdrProxyForwardingFunction17
;import NdrProxyForwardingFunction18
;import NdrProxyForwardingFunction19
;import NdrProxyForwardingFunction20
;import NdrProxyForwardingFunction21
;import NdrProxyForwardingFunction22
;import NdrProxyForwardingFunction23
;import NdrProxyForwardingFunction24
;import NdrProxyForwardingFunction25
;import NdrProxyForwardingFunction26
;import NdrProxyForwardingFunction27
;import NdrProxyForwardingFunction28
;import NdrProxyForwardingFunction29
;import NdrProxyForwardingFunction3
;import NdrProxyForwardingFunction30
;import NdrProxyForwardingFunction31
;import NdrProxyForwardingFunction32
;import NdrProxyForwardingFunction4
;import NdrProxyForwardingFunction5
;import NdrProxyForwardingFunction6
;import NdrProxyForwardingFunction7
;import NdrProxyForwardingFunction8
;import NdrProxyForwardingFunction9
;import ObjectStublessClient10
;import ObjectStublessClient11
;import ObjectStublessClient12
;import ObjectStublessClient13
;import ObjectStublessClient14
;import ObjectStublessClient15
;import ObjectStublessClient16
;import ObjectStublessClient17
;import ObjectStublessClient18
;import ObjectStublessClient19
;import ObjectStublessClient20
;import ObjectStublessClient21
;import ObjectStublessClient22
;import ObjectStublessClient23
;import ObjectStublessClient24
;import ObjectStublessClient25
;import ObjectStublessClient26
;import ObjectStublessClient27
;import ObjectStublessClient28
;import ObjectStublessClient29
;import ObjectStublessClient3
;import ObjectStublessClient30
;import ObjectStublessClient31
;import ObjectStublessClient32
;import ObjectStublessClient4
;import ObjectStublessClient5
;import ObjectStublessClient6
;import ObjectStublessClient7
;import ObjectStublessClient8
;import ObjectStublessClient9
;import OleCreateFontIndirectExt
;import OleCreatePictureIndirectExt
;import OleCreatePropertyFrameIndirectExt
;import OleGetPackageClipboardOwner
;import OleIconToCursorExt
;import OleLoadPictureExt
;import OleLoadPictureFileExt
;import OleLoadPicturePathExt
;import OleReleaseEnumVerbCache
;import OleSavePictureFileExt
;import OleTranslateColorExt
;import ReadStorageProperties
;import RegisterActiveObjectExt
;import RevokeActiveObjectExt
;import SetOleautModule
;import SetWOWThunkGlobalPtr
;import SNB_UserFree64
;import SNB_UserMarshal64
;import SNB_UserSize64
;import SNB_UserUnmarshal64
;import StdTypesGetClassObject
;import StdTypesRegisterServer
;import STGMEDIUM_UserFreeExt
;import STGMEDIUM_UserMarshalExt
;import STGMEDIUM_UserSizeExt
;import STGMEDIUM_UserUnmarshalExt
;import StgOpenStorageOnHandle
;import UpdateProcessTracing
;import WdtpInterfacePointer_UserFree64
;import WdtpInterfacePointer_UserMarshal64
;import WdtpInterfacePointer_UserSize64
;import WdtpInterfacePointer_UserUnmarshal64
;import WriteStorageProperties

#endif ;OLE32_INC
