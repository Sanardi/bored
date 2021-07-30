;===========================================================;
;                                                           ;
;      stireg.h for Easy Code 2.0 GoAsm 32-bit drivers      ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF STIREG_H
#Define STIREG_H 1

#Define REGSTR_VAL_TYPE_W                               L"Type"
#Define REGSTR_VAL_VENDOR_NAME_W                        L"Vendor"
#Define REGSTR_VAL_DEVICETYPE_W                         L"DeviceType"
#Define REGSTR_VAL_DEVICESUBTYPE_W                      L"DeviceSubType"
#Define REGSTR_VAL_DEV_NAME_W                           L"DeviceName"
#Define REGSTR_VAL_DRIVER_DESC_W                        L"DriverDesc"
#Define REGSTR_VAL_FRIENDLY_NAME_W                      L"FriendlyName"
#Define REGSTR_VAL_GENERIC_CAPS_W                       L"Capabilities"
#Define REGSTR_VAL_HARDWARE_W                           L"HardwareConfig"
#Define REGSTR_VAL_HARDWARE                             TEXT("HardwareConfig")
#Define REGSTR_VAL_DEVICE_NAME_W                        L"DriverDesc"
#Define REGSTR_VAL_DATA_W                               L"DeviceData"
#Define REGSTR_VAL_GUID_W                               L"GUID"
#Define REGSTR_VAL_GUID                                 TEXT("GUID")
#Define REGSTR_VAL_LAUNCH_APPS_W                        L"LaunchApplications"
#Define REGSTR_VAL_LAUNCH_APPS                          TEXT("LaunchApplications")
#Define REGSTR_VAL_LAUNCHABLE_W                         L"Launchable"
#Define REGSTR_VAL_LAUNCHABLE                           TEXT("Launchable")
#Define REGSTR_VAL_SHUTDOWNDELAY_W                      L"ShutdownIfUnusedDelay"
#Define REGSTR_VAL_SHUTDOWNDELAY                        TEXT("ShutdownIfUnusedDelay")

#Define IS_DIGITAL_CAMERA_STR                           L"IsDigitalCamera"
#Define IS_DIGITAL_CAMERA_VAL                           1
#Define SUPPORTS_MSCPLUS_STR                            L"SupportsMSCPlus"
#Define SUPPORTS_MSCPLUS_VAL 1

#Define STI_DEVICE_VALUE_TWAIN_NAME                     L"TwainDS"
#Define STI_DEVICE_VALUE_ISIS_NAME                      L"ISISDriverName"
#Define STI_DEVICE_VALUE_ICM_PROFILE                    L"ICMProfile"
#Define STI_DEVICE_VALUE_DEFAULT_LAUNCHAPP              L"DefaultLaunchApp"
#Define STI_DEVICE_VALUE_TIMEOUT                        L"PollTimeout"
#Define STI_DEVICE_VALUE_DISABLE_NOTIFICATIONS          L"DisableNotifications"
#Define REGSTR_VAL_BAUDRATE                             L"BaudRate"

#Define STI_DEVICE_VALUE_TWAIN_NAME_A                   "TwainDS"
#Define STI_DEVICE_VALUE_ISIS_NAME_A                    "ISISDriverName"
#Define STI_DEVICE_VALUE_ICM_PROFILE_A                  "ICMProfile"
#Define STI_DEVICE_VALUE_DEFAULT_LAUNCHAPP_A            "DefaultLaunchApp"
#Define STI_DEVICE_VALUE_TIMEOUT_A                      "PollTimeout"
#Define STI_DEVICE_VALUE_DISABLE_NOTIFICATIONS_A        "DisableNotifications"
#Define REGSTR_VAL_BAUDRATE_A                           "BaudRate"

#ENDIF ;STIREG_H
