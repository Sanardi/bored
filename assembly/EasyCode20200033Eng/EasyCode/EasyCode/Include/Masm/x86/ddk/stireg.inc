;===================================================================;
;                                                                   ;
;   stireg.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers    ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF STIREG_INC
STIREG_INC Equ 1

REGSTR_VAL_TYPE_W                                           Equ         L("Type")
REGSTR_VAL_VENDOR_NAME_W                                    Equ         L("Vendor")
REGSTR_VAL_DEVICETYPE_W                                     Equ         L("DeviceType")
REGSTR_VAL_DEVICESUBTYPE_W                                  Equ         L("DeviceSubType")
REGSTR_VAL_DEV_NAME_W                                       Equ         L("DeviceName")
REGSTR_VAL_DRIVER_DESC_W                                    Equ         L("DriverDesc")
REGSTR_VAL_FRIENDLY_NAME_W                                  Equ         L("FriendlyName")
REGSTR_VAL_GENERIC_CAPS_W                                   Equ         L("Capabilities")
REGSTR_VAL_HARDWARE_W                                       Equ         L("HardwareConfig")
REGSTR_VAL_HARDWARE                                         Equ         TEXT("HardwareConfig")
REGSTR_VAL_DEVICE_NAME_W                                    Equ         L("DriverDesc")
REGSTR_VAL_DATA_W                                           Equ         L("DeviceData")
REGSTR_VAL_GUID_W                                           Equ         L("GUID")
REGSTR_VAL_GUID                                             Equ         TEXT("GUID")
REGSTR_VAL_LAUNCH_APPS_W                                    Equ         L("LaunchApplications")
REGSTR_VAL_LAUNCH_APPS                                      Equ         TEXT("LaunchApplications")
REGSTR_VAL_LAUNCHABLE_W                                     Equ         L("Launchable")
REGSTR_VAL_LAUNCHABLE                                       Equ         TEXT("Launchable")
REGSTR_VAL_SHUTDOWNDELAY_W                                  Equ         L"ShutdownIfUnusedDelay")
REGSTR_VAL_SHUTDOWNDELAY                                    Equ         TEXT("ShutdownIfUnusedDelay")

IS_DIGITAL_CAMERA_STR                                       Equ         L("IsDigitalCamera")
IS_DIGITAL_CAMERA_VAL                                       Equ         1
SUPPORTS_MSCPLUS_STR                                        Equ         L("SupportsMSCPlus")
SUPPORTS_MSCPLUS_VAL                                        Equ         1

STI_DEVICE_VALUE_TWAIN_NAME                                 Equ         L("TwainDS")
STI_DEVICE_VALUE_ISIS_NAME                                  Equ         L("ISISDriverName")
STI_DEVICE_VALUE_ICM_PROFILE                                Equ         L("ICMProfile")
STI_DEVICE_VALUE_DEFAULT_LAUNCHAPP                          Equ         L("DefaultLaunchApp")
STI_DEVICE_VALUE_TIMEOUT                                    Equ         L("PollTimeout")
STI_DEVICE_VALUE_DISABLE_NOTIFICATIONS                      Equ         L("DisableNotifications")
REGSTR_VAL_BAUDRATE                                         Equ         L("BaudRate"

STI_DEVICE_VALUE_TWAIN_NAME_A                               Equ         A("TwainDS")
STI_DEVICE_VALUE_ISIS_NAME_A                                Equ         A("ISISDriverName")
STI_DEVICE_VALUE_ICM_PROFILE_A                              Equ         A("ICMProfile")
STI_DEVICE_VALUE_DEFAULT_LAUNCHAPP_A                        Equ         A("DefaultLaunchApp")
STI_DEVICE_VALUE_TIMEOUT_A                                  Equ         A("PollTimeout")
STI_DEVICE_VALUE_DISABLE_NOTIFICATIONS_A                    Equ         A("DisableNotifications")
REGSTR_VAL_BAUDRATE_A                                       Equ         A("BaudRate")

ENDIF ;STIREG_INC
