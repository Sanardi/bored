; ====================================================;
;                                                     ;
;  dinput.inc for Easy Code 2.0 64-bit Masm projects  ;
;                   (version 1.0.0)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2020            ;
;                                                     ;
; ====================================================;

IFNDEF DINPUT_INC
DINPUT_INC  EQU 1

IFNDEF DIRECTINPUT_VERSION
    DIRECTINPUT_VERSION EQU                     EQU     0700H
ENDIF

MAKEDIPROP MACRO prop
    EXITM <(prop)>
ENDM

MAKE_HRESULT MACRO sev,fac,code
    EXITM <sev*80000000H+fac*10000H+code>
ENDM

DIENUM_STOP                                     EQU     0
DIENUM_CONTINUE                                 EQU     1


DIDFT_ALL                                       EQU     00000000H
DIDFT_RELAXIS                                   EQU     00000001H
DIDFT_ABSAXIS                                   EQU     00000002H
DIDFT_AXIS                                      EQU     00000003H
DIDFT_PSHBUTTON                                 EQU     00000004H
DIDFT_TGLBUTTON                                 EQU     00000008H
DIDFT_BUTTON                                    EQU     0000000CH

DISCL_EXCLUSIVE                                 EQU     00000001H
DISCL_NONEXCLUSIVE                              EQU     00000002H
DISCL_FOREGROUND                                EQU     00000004H
DISCL_BACKGROUND                                EQU     00000008H
DISCL_NOWINKEY                                  EQU     00000010H

DIPROP_BUFFERSIZE                               EQU     <MAKEDIPROP (1)>
DIPROP_AXISMODE                                 EQU     <MAKEDIPROP (2)>
DIPROP_GRANULARITY                              EQU     <MAKEDIPROP (3)>
DIPROP_RANGE                                    EQU     <MAKEDIPROP (4)>
DIPROP_DEADZONE                                 EQU     <MAKEDIPROP (5)>
DIPROP_SATURATION                               EQU     <MAKEDIPROP (6)>
DIPROP_FFGAIN                                   EQU     <MAKEDIPROP (7)>
DIPROP_FFLOAD                                   EQU     <MAKEDIPROP (8)>
DIPROP_AUTOCENTER                               EQU     <MAKEDIPROP (9)>
DIPROPAUTOCENTER_OFF                            EQU     0
DIPROPAUTOCENTER_ON                             EQU     1
DIPROP_CALIBRATIONMODE                          EQU     <MAKEDIPROP (10)>
DIPROPCALIBRATIONMODE_COOKED                    EQU     0
DIPROPCALIBRATIONMODE_RAW                       EQU     1
DIPROP_CALIBRATION                              EQU     <MAKEDIPROP (11)>
DIPROP_GUIDANDPATH                              EQU     <MAKEDIPROP (12)>
DIPROP_INSTANCENAME                             EQU     <MAKEDIPROP (13)>
DIPROP_PRODUCTNAME                              EQU     <MAKEDIPROP (14)>
DIPROP_JOYSTICKID                               EQU     <MAKEDIPROP (15)>
DIPROP_GETPORTDISPLAYNAME                       EQU     <MAKEDIPROP (16)>
DIPROP_PHYSICALRANGE                            EQU     <MAKEDIPROP (18)>
DIPROP_LOGICALRANGE                             EQU     <MAKEDIPROP (19)>
DIPROP_KEYNAME                                  EQU     <MAKEDIPROP (20)>
DIPROP_CPOINTS                                  EQU     <MAKEDIPROP (21)>
DIPROP_APPDATA                                  EQU     <MAKEDIPROP (22)>
DIPROP_SCANCODE                                 EQU     <MAKEDIPROP (23)>
DIPROP_VIDPID                                   EQU     <MAKEDIPROP (24)>
DIPROP_USERNAME                                 EQU     <MAKEDIPROP (25)>
DIPROP_TYPENAME                                 EQU     <MAKEDIPROP (26)>

MAXCPOINTSNUM                                   EQU     8

DIPROPAXISMODE_ABS                              EQU     0
DIPROPAXISMODE_REL                              EQU     1

DIDF_ABSAXIS                                    EQU     00000001H
DIDF_RELAXIS                                    EQU     00000002H

DIDEVTYPE_DEVICE                                EQU     1
DIDEVTYPE_MOUSE                                 EQU     2
DIDEVTYPE_KEYBOARD                              EQU     3
DIDEVTYPE_JOYSTICK                              EQU     4

DIDEVTYPEMOUSE_UNKNOWN                          EQU     1
DIDEVTYPEMOUSE_TRADITIONAL                      EQU     2
DIDEVTYPEMOUSE_FINGERSTICK                      EQU     3
DIDEVTYPEMOUSE_TOUCHPAD                         EQU     4
DIDEVTYPEMOUSE_TRACKBALL                        EQU     5
DIDEVTYPEKEYBOARD_UNKNOWN                       EQU     0
DIDEVTYPEKEYBOARD_PCXT                          EQU     1
DIDEVTYPEKEYBOARD_OLIVETTI                      EQU     2
DIDEVTYPEKEYBOARD_PCAT                          EQU     3
DIDEVTYPEKEYBOARD_PCENH                         EQU     4
DIDEVTYPEKEYBOARD_NOKIA1050                     EQU     5
DIDEVTYPEKEYBOARD_NOKIA9140                     EQU     6
DIDEVTYPEKEYBOARD_NEC98                         EQU     7
DIDEVTYPEKEYBOARD_NEC98LAPTOP                   EQU     8
DIDEVTYPEKEYBOARD_NEC98106                      EQU     9
DIDEVTYPEKEYBOARD_JAPAN106                      EQU     10
DIDEVTYPEKEYBOARD_JAPANAX                       EQU     11
DIDEVTYPEKEYBOARD_J3100                         EQU     12
DIDEVTYPEJOYSTICK_UNKNOWN                       EQU     1
DIDEVTYPEJOYSTICK_TRADITIONAL                   EQU     2
DIDEVTYPEJOYSTICK_FLIGHTSTICK                   EQU     3
DIDEVTYPEJOYSTICK_GAMEPAD                       EQU     4
DIDEVTYPEJOYSTICK_RUDDER                        EQU     5
DIDEVTYPEJOYSTICK_WHEEL                         EQU     6
DIDEVTYPEJOYSTICK_HEADTRACKER                   EQU     7

DIDC_ATTACHED                                   EQU     00000001H
DIDC_POLLEDDEVICE                               EQU     00000002H
DIDC_EMULATED                                   EQU     00000004H
DIDC_POLLEDDATAFORMAT                           EQU     00000008H
DIDC_FORCEFEEDBACK                              EQU     00000100H
DIDC_FFATTACK                                   EQU     00000200H
DIDC_FFFADE                                     EQU     00000400H
DIDC_SATURATION                                 EQU     00000800H
DIDC_POSNEGCOEFFICIENTS                         EQU     00001000H
DIDC_POSNEGSATURATION                           EQU     00002000H
DIDC_DEADBAND                                   EQU     00004000H
DIDC_STARTDELAY                                 EQU     00008000H
DIDC_ALIAS                                      EQU     00010000H
DIDC_PHANTOM                                    EQU     00020000H
DIDC_HIDDEN                                     EQU     00040000H

DI_OK                                           EQU     S_OK
DI_NOTATTACHED                                  EQU     S_FALSE
DI_BUFFEROVERFLOW                               EQU     S_FALSE
DI_PROPNOEFFECT                                 EQU     S_FALSE
DI_NOEFFECT                                     EQU     S_FALSE

DIERR_OLDDIRECTINPUTVERSION                     EQU     <MAKE_HRESULT (SEVERITY_ERROR,FACILITY_WIN32,ERROR_OLD_WIN_VERSION)>
DIERR_BETADIRECTINPUTVERSION                    EQU     <MAKE_HRESULT (SEVERITY_ERROR,FACILITY_WIN32,ERROR_RMODE_APP)>
DIERR_BADDRIVERVER                              EQU     <MAKE_HRESULT (SEVERITY_ERROR,FACILITY_WIN32,ERROR_BAD_DRIVER_LEVEL)>
DIERR_DEVICENOTREG                              EQU     REGDB_E_CLASSNOTREG
DIERR_NOTFOUND                                  EQU     <MAKE_HRESULT (SEVERITY_ERROR,FACILITY_WIN32,ERROR_FILE_NOT_FOUND)>
DIERR_OBJECTNOTFOUND                            EQU     <MAKE_HRESULT (SEVERITY_ERROR,FACILITY_WIN32,ERROR_FILE_NOT_FOUND)>
DIERR_INVALIDPARAM                              EQU     E_INVALIDARG
DIERR_NOINTERFACE                               EQU     80004002H
DIERR_GENERIC                                   EQU     E_FAIL
DIERR_OUTOFMEMORY                               EQU     E_OUTOFMEMORY
DIERR_UNSUPPORTED                               EQU     E_NOTIMPL
DIERR_NOTINITIALIZED                            EQU     <MAKE_HRESULT (SEVERITY_ERROR,FACILITY_WIN32,ERROR_NOT_READY)>
DIERR_ALREADYINITIALIZED                        EQU     <MAKE_HRESULT (SEVERITY_ERROR,FACILITY_WIN32,ERROR_ALREADY_INITIALIZED)>
DIERR_NOAGGREGATION                             EQU     CLASS_E_NOAGGREGATION
DIERR_OTHERAPPHASPRIO                           EQU     E_ACCESSDENIED
DIERR_INPUTLOST                                 EQU     <MAKE_HRESULT (SEVERITY_ERROR,FACILITY_WIN32,ERROR_READ_FAULT)>
DIERR_ACQUIRED                                  EQU     <MAKE_HRESULT (SEVERITY_ERROR,FACILITY_WIN32,ERROR_BUSY)>
DIERR_NOTACQUIRED                               EQU     <MAKE_HRESULT (SEVERITY_ERROR,FACILITY_WIN32,ERROR_INVALID_ACCESS)>
DIERR_READONLY                                  EQU     E_ACCESSDENIED
DIERR_HANDLEEXISTS                              EQU     E_ACCESSDENIED
IFNDEF E_PENDING
    E_PENDING                                   EQU     8000000AH
ENDIF
DIERR_INSUFFICIENTPRIVS                         EQU     80040200H
DIERR_DEVICEFULL                                EQU     80040201H
DIERR_MOREDATA                                  EQU     80040202H
DIERR_NOTDOWNLOADED                             EQU     80040203H
DIERR_HASEFFECTS                                EQU     80040204H
DIERR_NOTEXCLUSIVEACQUIRED                      EQU     80040205H
DIERR_INCOMPLETEEFFECT                          EQU     80040206H
DIERR_NOTBUFFERED                               EQU     80040207H
DIERR_EFFECTPLAYING                             EQU     80040208H
DIERR_UNPLUGGED                                 EQU     80040209H
DIERR_REPORTFULL                                EQU     8004020AH
DIERR_MAPFILEFAIL                               EQU     8004020BH

;======================================== Structures ======================================;
DINPUTVFT STRUCT ALIGNMODE
    pQueryInterface     XPTR ?
    pAddRef             XPTR ?
    pRelease            XPTR ?
    pCreateDevice       XPTR ?
    pEnumDevices        XPTR ?
    pGetDeviceStatus    XPTR ?
    pRunControlPanel    XPTR ?
    pInitialize         XPTR ?
DINPUTVFT ENDS

DINPDEVVFT STRUCT ALIGNMODE
    pQueryInterface         XPTR ?
    pAddRef                 XPTR ?
    pRelease                XPTR ?
    pGetCapabilities        XPTR ?
    pEnumObjects            XPTR ?
    pGetProperty            XPTR ?
    pSetProperty            XPTR ?
    pAcquire                XPTR ? 
    pUnacquire              XPTR ? 
    pGetDeviceState         XPTR ?
    pGetDeviceData          XPTR ?
    pSetDataFormat          XPTR ?
    pSetEventNotification   XPTR ?
    pSetCooperativeLevel    XPTR ?
    pGetObjectInfo          XPTR ?
    pGetDeviceInfo          XPTR ?
    pRunControlPanel        XPTR ?
    pInitialize             XPTR ?
DINPDEVVFT ENDS

DIEFFESCAPE STRUCT ALIGNMODE
    dwSize          DWORD  ?
    dwCommand       DWORD  ?
    lpvInBuffer     XPTR   ?
    cbInBuffer      DWORD  ?
    lpvOutBuffer    XPTR   ?
    cbOutBuffer     DWORD  ?
DIEFFESCAPE ENDS

DIDEVICEOBJECTDATA STRUCT ALIGNMODE
    dwOfs        DWORD ?
    dwData       DWORD ?
    dwTimeStamp  DWORD ?
    dwSequence   DWORD ?
    uAppData     XPTR  ?
DIDEVICEOBJECTDATA ENDS

DINPDEV2VFT STRUCT ALIGNMODE
                                DINPDEVVFT <>
    pCreateEffect               XPTR ?
    pEnumEffects                XPTR ?
    pGetEffectInfo              XPTR ?
    pGetForceFeedbackState      XPTR ?
    pSendForceFeedbackCommand   XPTR ?
    pEnumCreatedEffectObjects   XPTR ?
    pEscape                     XPTR ?
    pPoll                       XPTR ?
    pSendDeviceData             XPTR ?
DINPDEV2VFT ENDS

DIDEVCAPS STRUCT ALIGNMODE
    dwSize                DWORD ?
    dwFlags               DWORD ?
    dwDevType             DWORD ?
    dwAxes                DWORD ?
    dwButtons             DWORD ?
    dwPOVs                DWORD ?
    dwFFSamplePeriod      DWORD ?
    dwFFMinTimeResolution DWORD ?
    dwFirmwareRevision    DWORD ?
    dwHardwareRevision    DWORD ?
    dwFFDriverVersion     DWORD ?
DIDEVCAPS ENDS

DIPROPHEADER STRUCT ALIGNMODE
    dwSize       DWORD ?
    dwHeaderSize DWORD ?
    dwObj        DWORD ?
    dwHow        DWORD ?
DIPROPHEADER ENDS

DIPROPDWORD STRUCT ALIGNMODE
    diph    DIPROPHEADER <>
    dwData  DWORD ?
DIPROPDWORD ENDS

DIOBJECTDATAFORMAT STRUCT ALIGNMODE
    pguid   DWORD ?
    dwOfs   DWORD ?
    dwType  DWORD ?
    dwFlags DWORD ?
DIOBJECTDATAFORMAT ENDS

DIDATAFORMAT STRUCT ALIGNMODE
    dwSize      DWORD ?
    dwObjSize   DWORD ?
    dwFlags     DWORD ?
    dwDataSize  DWORD ?
    dwNumObjs   DWORD ?
    rgodf       XPTR  ?
DIDATAFORMAT ENDS

DIDEVICEOBJECTINSTANCEA STRUCT ALIGNMODE
    dwSize              DWORD   ?
    guidType            GUID    <>
    dwOfs               DWORD   ?
    dwType              DWORD   ?
    dwFlags             WORD    ?
    tszName             SBYTE MAX_PATH DUP(?)
    dwFFMaxForce        DWORD   ?
    dwFFForceResolution DWORD   ?
    wCollectionNumber   WORD    ?
    wDesignatorIndex    WORD    ?
    wUsagePage          WORD    ?
    wUsage              WORD    ?
    dwDimension         DWORD   ?
    wExponent           WORD    ?
    wReportId           WORD    ?
DIDEVICEOBJECTINSTANCEA ENDS

DIDEVICEINSTANCEA STRUCT ALIGNMODE
    dwSize          DWORD ?
    guidInstance    GUID  <>
    guidProduct     GUID  <>
    dwDevType       DWORD ?
    tszInstanceName SBYTE MAX_PATH DUP(?)
    tszProductName  SBYTE MAX_PATH DUP(?)
    guidFFDriver    GUID  <>
    wUsagePage      WORD  ?
    wUsage          WORD  ?
DIDEVICEINSTANCEA ENDS

DIEFFECTINFOA STRUCT ALIGNMODE
    dwSize          DWORD ?
    guid            GUID  <>
    dwEffType       DWORD ?
    dwStaticParams  DWORD ?
    dwDynamicParams DWORD ?
    tszName         SBYTE MAX_PATH DUP(?)
DIEFFECTINFOA ENDS

DIENVELOPE STRUCT ALIGNMODE
    dwSize          DWORD   ?
    dwAttackLevel   DWORD   ?
    dwAttackTime    DWORD   ?
    dwFadeLevel     DWORD   ?
    dwFadeTime      DWORD   ?
DIENVELOPE ENDS

DIEFFECT STRUCT ALIGNMODE
    dwSize                  DWORD ?
    dwFlags                 DWORD ?
    dwDuration              DWORD ?
    dwSamplePeriod          DWORD ?
    dwGain                  DWORD ?
    dwTriggerButton         DWORD ?
    dwTriggerRepeatInterval DWORD ?
    cAxes                   DWORD ?
    rgdwAxes                XPTR  ?
    rglDirection            XPTR  ?
    lpEnvelope              XPTR  ?
    cbTypeSpecificParams    DWORD ?
    lpvTypeSpecificParams   XPTR  ?
    dwStartDelay            DWORD ?
DIEFFECT ENDS

DIMOUSESTATE STRUCT ALIGNMODE
    lX         SDWORD ?
    lY         SDWORD ?
    lZ         SDWORD ?
    rgbButtons BYTE 4 DUP(?)
DIMOUSESTATE ENDS

DIMOFS_X                                        EQU     <DIMOUSESTATE.lX>
DIMOFS_Y                                        EQU     <DIMOUSESTATE.lY>
DIMOFS_Z                                        EQU     <DIMOUSESTATE.lZ>
DIMOFS_BUTTON0                                  EQU     (DIMOUSESTATE.rgbButtons + 0)
DIMOFS_BUTTON1                                  EQU     (DIMOUSESTATE.rgbButtons + 1)
DIMOFS_BUTTON2                                  EQU     (DIMOUSESTATE.rgbButtons + 2)
DIMOFS_BUTTON3                                  EQU     (DIMOUSESTATE.rgbButtons + 3)

;======================================== Functions =======================================;
DirectInputCreateA PROTO :XWORD,:XWORD,:XWORD,:XWORD
DirectInputCreateW PROTO :XWORD,:XWORD,:XWORD,:XWORD
DirectInputCreateEx PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD

IFDEF APP_UNICODE
  DirectInputCreate EQU <DirectInputCreateA>
ELSE
  DirectInputCreate EQU <DirectInputCreateW>
ENDIF

ENDIF ;DINPUT_INC
