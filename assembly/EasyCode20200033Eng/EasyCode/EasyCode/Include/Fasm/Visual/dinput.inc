; ====================================================;
;                                                     ;
;      dinput.inc for EC v2 Fasm visual projects      ;
;                   (version 1.0.0)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2020            ;
;                                                     ;
; ====================================================;

if ~defined DINPUT_INC
define DINPUT_INC 1

if ~defined DIRECTINPUT_VERSION
    DIRECTINPUT_VERSION                         equ     0700H
end if

DIENUM_STOP                                     equ     0
DIENUM_CONTINUE                                 equ     1


DIDFT_ALL                                       equ     00000000H
DIDFT_RELAXIS                                   equ     00000001H
DIDFT_ABSAXIS                                   equ     00000002H
DIDFT_AXIS                                      equ     00000003H
DIDFT_PSHBUTTON                                 equ     00000004H
DIDFT_TGLBUTTON                                 equ     00000008H
DIDFT_BUTTON                                    equ     0000000CH

DISCL_EXCLUSIVE                                 equ     00000001H
DISCL_NONEXCLUSIVE                              equ     00000002H
DISCL_FOREGROUND                                equ     00000004H
DISCL_BACKGROUND                                equ     00000008H
DISCL_NOWINKEY                                  equ     00000010H

DIPROP_BUFFERSIZE                               equ     1
DIPROP_AXISMODE                                 equ     2
DIPROP_GRANULARITY                              equ     3
DIPROP_RANGE                                    equ     4
DIPROP_DEADZONE                                 equ     5
DIPROP_SATURATION                               equ     6
DIPROP_FFGAIN                                   equ     7
DIPROP_FFLOAD                                   equ     8
DIPROP_AUTOCENTER                               equ     9
DIPROPAUTOCENTER_OFF                            equ     0
DIPROPAUTOCENTER_ON                             equ     1
DIPROP_CALIBRATIONMODE                          equ     10
DIPROPCALIBRATIONMODE_COOKED                    equ     0
DIPROPCALIBRATIONMODE_RAW                       equ     1
DIPROP_CALIBRATION                              equ     11
DIPROP_GUIDANDPATH                              equ     12
DIPROP_INSTANCENAME                             equ     13
DIPROP_PRODUCTNAME                              equ     14
DIPROP_JOYSTICKID                               equ     15
DIPROP_GETPORTDISPLAYNAME                       equ     16
DIPROP_PHYSICALRANGE                            equ     18
DIPROP_LOGICALRANGE                             equ     19
DIPROP_KEYNAME                                  equ     20
DIPROP_CPOINTS                                  equ     21
DIPROP_APPDATA                                  equ     22
DIPROP_SCANCODE                                 equ     23
DIPROP_VIDPID                                   equ     24
DIPROP_USERNAME                                 equ     25
DIPROP_TYPENAME                                 equ     26

DIPROPAXISMODE_ABS                              equ     0
DIPROPAXISMODE_REL                              equ     1

DIDF_ABSAXIS                                    equ     00000001H
DIDF_RELAXIS                                    equ     00000002H

DIDEVTYPE_DEVICE                                equ     1
DIDEVTYPE_MOUSE                                 equ     2
DIDEVTYPE_KEYBOARD                              equ     3
DIDEVTYPE_JOYSTICK                              equ     4

DIDEVTYPEMOUSE_UNKNOWN                          equ     1
DIDEVTYPEMOUSE_TRADITIONAL                      equ     2
DIDEVTYPEMOUSE_FINGERSTICK                      equ     3
DIDEVTYPEMOUSE_TOUCHPAD                         equ     4
DIDEVTYPEMOUSE_TRACKBALL                        equ     5
DIDEVTYPEKEYBOARD_UNKNOWN                       equ     0
DIDEVTYPEKEYBOARD_PCXT                          equ     1
DIDEVTYPEKEYBOARD_OLIVETTI                      equ     2
DIDEVTYPEKEYBOARD_PCAT                          equ     3
DIDEVTYPEKEYBOARD_PCENH                         equ     4
DIDEVTYPEKEYBOARD_NOKIA1050                     equ     5
DIDEVTYPEKEYBOARD_NOKIA9140                     equ     6
DIDEVTYPEKEYBOARD_NEC98                         equ     7
DIDEVTYPEKEYBOARD_NEC98LAPTOP                   equ     8
DIDEVTYPEKEYBOARD_NEC98106                      equ     9
DIDEVTYPEKEYBOARD_JAPAN106                      equ     10
DIDEVTYPEKEYBOARD_JAPANAX                       equ     11
DIDEVTYPEKEYBOARD_J3100                         equ     12
DIDEVTYPEJOYSTICK_UNKNOWN                       equ     1
DIDEVTYPEJOYSTICK_TRADITIONAL                   equ     2
DIDEVTYPEJOYSTICK_FLIGHTSTICK                   equ     3
DIDEVTYPEJOYSTICK_GAMEPAD                       equ     4
DIDEVTYPEJOYSTICK_RUDDER                        equ     5
DIDEVTYPEJOYSTICK_WHEEL                         equ     6
DIDEVTYPEJOYSTICK_HEADTRACKER                   equ     7

DIDC_ATTACHED                                   equ     00000001H
DIDC_POLLEDDEVICE                               equ     00000002H
DIDC_EMULATED                                   equ     00000004H
DIDC_POLLEDDATAFORMAT                           equ     00000008H
DIDC_FORCEFEEDBACK                              equ     00000100H
DIDC_FFATTACK                                   equ     00000200H
DIDC_FFFADE                                     equ     00000400H
DIDC_SATURATION                                 equ     00000800H
DIDC_POSNEGCOEFFICIENTS                         equ     00001000H
DIDC_POSNEGSATURATION                           equ     00002000H
DIDC_DEADBAND                                   equ     00004000H
DIDC_STARTDELAY                                 equ     00008000H
DIDC_ALIAS                                      equ     00010000H
DIDC_PHANTOM                                    equ     00020000H
DIDC_HIDDEN                                     equ     00040000H

DI_OK                                           equ     S_OK
DI_NOTATTACHED                                  equ     S_FALSE
DI_BUFFEROVERFLOW                               equ     S_FALSE
DI_PROPNOEFFECT                                 equ     S_FALSE
DI_NOEFFECT                                     equ     S_FALSE

DIERR_OLDDIRECTINPUTVERSION                     equ     (SEVERITY_ERROR*80000000H+FACILITY_WIN32*10000H+ERROR_OLD_WIN_VERSION)
DIERR_BETADIRECTINPUTVERSION                    equ     (SEVERITY_ERROR*80000000H+FACILITY_WIN32*10000H+ERROR_RMODE_APP)
DIERR_BADDRIVERVER                              equ     (SEVERITY_ERROR*80000000H+FACILITY_WIN32*10000H+ERROR_BAD_DRIVER_LEVEL)
DIERR_DEVICENOTREG                              equ     REGDB_E_CLASSNOTREG
DIERR_NOTFOUND                                  equ     (SEVERITY_ERROR*80000000H+FACILITY_WIN32*10000H+ERROR_FILE_NOT_FOUND)
DIERR_OBJECTNOTFOUND                            equ     (SEVERITY_ERROR*80000000H+FACILITY_WIN32*10000H+ERROR_FILE_NOT_FOUND)
DIERR_INVALIDPARAM                              equ     E_INVALIDARG
DIERR_NOINTERFACE                               equ     80004002H
DIERR_GENERIC                                   equ     E_FAIL
DIERR_OUTOFMEMORY                               equ     E_OUTOFMEMORY
DIERR_UNSUPPORTED                               equ     E_NOTIMPL
DIERR_NOTINITIALIZED                            equ     (SEVERITY_ERROR*80000000H+FACILITY_WIN32*10000H+ERROR_NOT_READY)
DIERR_ALREADYINITIALIZED                        equ     (SEVERITY_ERROR*80000000H+FACILITY_WIN32*10000H+ERROR_ALREADY_INITIALIZED)
DIERR_NOAGGREGATION                             equ     CLASS_E_NOAGGREGATION
DIERR_OTHERAPPHASPRIO                           equ     E_ACCESSDENIED
DIERR_INPUTLOST                                 equ     (SEVERITY_ERROR*80000000H+FACILITY_WIN32*10000H+ERROR_READ_FAULT)
DIERR_ACQUIRED                                  equ     (SEVERITY_ERROR*80000000H+FACILITY_WIN32*10000H+ERROR_BUSY)
DIERR_NOTACQUIRED                               equ     (SEVERITY_ERROR*80000000H+FACILITY_WIN32*10000H+ERROR_INVALID_ACCESS)
DIERR_READONLY                                  equ     E_ACCESSDENIED
DIERR_HANDLEEXISTS                              equ     E_ACCESSDENIED
if ~defined E_PENDING
    E_PENDING                                   equ     8000000AH
end if 
DIERR_INSUFFICIENTPRIVS                         equ     80040200H
DIERR_DEVICEFULL                                equ     80040201H
DIERR_MOREDATA                                  equ     80040202H
DIERR_NOTDOWNLOADED                             equ     80040203H
DIERR_HASEFFECTS                                equ     80040204H
DIERR_NOTEXCLUSIVEACQUIRED                      equ     80040205H
DIERR_INCOMPLETEEFFECT                          equ     80040206H
DIERR_NOTBUFFERED                               equ     80040207H
DIERR_EFFECTPLAYING                             equ     80040208H
DIERR_UNPLUGGED                                 equ     80040209H
DIERR_REPORTFULL                                equ     8004020AH
DIERR_MAPFILEFAIL                               equ     8004020BH

;======================================== Structures ======================================;
interface DINPUTVFT,\
    pQueryInterface,\
    pAddRef,\
    pRelease,\
    pCreateDevice,\
    pEnumDevices,\
    pGetDeviceStatus,\
    pRunControlPanel,\
    pInitialize

interface DINPDEVVFT,\
    pQueryInterface,\
    pAddRef,\
    pRelease,\
    pGetCapabilities,\
    pEnumObjects,\
    pGetProperty,\
    pSetProperty,\
    pAcquire,\
    pUnacquire,\
    pGetDeviceState,\
    pGetDeviceData,\
    pSetDataFormat,\
    pSetEventNotification,\
    pSetCooperativeLevel,\
    pGetObjectInfo,\
    pGetDeviceInfo,\
    pRunControlPanel,\
    pInitialize

struct DIEFFESCAPE
    dwSize          dd   ?
    dwCommand       dd   ?
    lpvInBuffer     xptr ?
    cbInBuffer      dd   ?
    lpvOutBuffer    xptr ?
    cbOutBuffer     dd   ?
ends

struct DIDEVICEOBJECTDATA
    dwOfs        dd   ?
    dwData       dd   ?
    dwTimeStamp  dd   ?
    dwSequence   dd   ?
    uAppData     xptr ?
ends

struct DINPDEV2VFT
    unknown                     DINPDEVVFT
    pCreateEffect               xptr ?
    pEnumEffects                xptr ?
    pGetEffectInfo              xptr ?
    pGetForceFeedbackState      xptr ?
    pSendForceFeedbackCommand   xptr ?
    pEnumCreatedEffectObjects   xptr ?
    pEscape                     xptr ?
    pPoll                       xptr ?
    pSendDeviceData             xptr ?
ends

struct DIDEVCAPS
    dwSize                dd ?
    dwFlags               dd ?
    dwDevType             dd ?
    dwAxes                dd ?
    dwButtons             dd ?
    dwPOVs                dd ?
    dwFFSamplePeriod      dd ?
    dwFFMinTimeResolution dd ?
    dwFirmwareRevision    dd ?
    dwHardwareRevision    dd ?
    dwFFDriverVersion     dd ?
ends

struct DIPROPHEADER
    dwSize       dd ?
    dwHeaderSize dd ?
    dwObj        dd ?
    dwHow        dd ?
ends

struct DIPROPDWORD
    diph    DIPROPHEADER
    dwData  dd ?
ends

struct DIOBJECTDATAFORMAT
    pguid   dd ?
    dwOfs   dd ?
    dwType  dd ?
    dwFlags dd ?
ends

struct DIDATAFORMAT
    dwSize      dd   ?
    dwObjSize   dd   ?
    dwFlags     dd   ?
    dwDataSize  dd   ?
    dwNumObjs   dd   ?
    rgodf       xptr ?
ends

struct DIDEVICEOBJECTINSTANCEA
    dwSize              dd   ?
    guidType            GUID    
    dwOfs               dd   ?
    dwType              dd   ?
    dwFlags             dw   ?
    tszName             db MAX_PATH dup(?)
    dwFFMaxForce        dd   ?
    dwFFForceResolution dd   ?
    wCollectionNumber   dw   ?
    wDesignatorIndex    dw   ?
    wUsagePage          dw   ?
    wUsage              dw   ?
    dwDimension         dd   ?
    wExponent           dw   ?
    wReportId           dw   ?
ends

struct DIDEVICEINSTANCEA
    dwSize          dd ?
    guidInstance    GUID  
    guidProduct     GUID  
    dwDevType       dd ?
    tszInstanceName db MAX_PATH dup(?)
    tszProductName  db MAX_PATH dup(?)
    guidFFDriver    GUID  
    wUsagePage      dw ?
    wUsage          dw ?
ends

struct DIEFFECTINFOA
    dwSize          dd ?
    guid            GUID  
    dwEffType       dd ?
    dwStaticParams  dd ?
    dwDynamicParams dd ?
    tszName         db MAX_PATH dup(?)
ends

struct DIENVELOPE
    dwSize          dd ?
    dwAttackLevel   dd ?
    dwAttackTime    dd ?
    dwFadeLevel     dd ?
    dwFadeTime      dd ?
ends

struct DIEFFECT
    dwSize                  dd   ?
    dwFlags                 dd   ?
    dwDuration              dd   ?
    dwSamplePeriod          dd   ?
    dwGain                  dd   ?
    dwTriggerButton         dd   ?
    dwTriggerRepeatInterval dd   ?
    cAxes                   dd   ?
    rgdwAxes                xptr ?
    rglDirection            xptr ?
    lpEnvelope              xptr ?
    cbTypeSpecificParams    dd   ?
    lpvTypeSpecificParams   xptr ?
    dwStartDelay            dd   ?
ends

struct DIMOUSESTATE
    lX         dd ?
    lY         dd ?
    lZ         dd ?
    rgbButtons db 4 dup(?)
ends

DIMOFS_X                                        equ     DIMOUSESTATE.lX
DIMOFS_Y                                        equ     DIMOUSESTATE.lY
DIMOFS_Z                                        equ     DIMOUSESTATE.lZ
DIMOFS_BUTTON0                                  equ     (DIMOUSESTATE.rgbButtons + 0)
DIMOFS_BUTTON1                                  equ     (DIMOUSESTATE.rgbButtons + 1)
DIMOFS_BUTTON2                                  equ     (DIMOUSESTATE.rgbButtons + 2)
DIMOFS_BUTTON3                                  equ     (DIMOUSESTATE.rgbButtons + 3)

;======================================== Functions =======================================;
if defined APP_WIN64
    extrn '__imp_DirectInputCreateA' as DirectInputCreateA:qword
    extrn '__imp_DirectInputCreateW' as DirectInputCreateW:qword
    extrn '__imp_DirectInputCreateEx' as DirectInputCreateEx:qword
else
    extrn '__imp__DirectInputCreateA@16' as DirectInputCreateA:dword
    extrn '__imp__DirectInputCreateW@16' as DirectInputCreateW:dword
    extrn '__imp__DirectInputCreateEx@20' as DirectInputCreateEx:dword
end if

api DirectInputCreate

end if ;DINPUT_INC
