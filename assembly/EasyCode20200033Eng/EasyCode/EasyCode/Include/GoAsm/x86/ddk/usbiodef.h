;===========================================================;
;                                                           ;
;     usbiodef.h for Easy Code 2.0 GoAsm 32-bit drivers     ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF USBIODEF_H
#Define USBIODEF_H 1

#IFNDEF MACRODRV_H
    #Include macrodrv.h
#ENDIF

USB_SUBMIT_URB                                              Equ         0
USB_RESET_PORT                                              Equ         1
USB_GET_ROOTHUB_PDO                                         Equ         3
USB_GET_PORT_STATUS                                         Equ         4
USB_ENABLE_PORT                                             Equ         5
USB_GET_HUB_COUNT                                           Equ         6
USB_CYCLE_PORT                                              Equ         7
USB_GET_HUB_NAME                                            Equ         8
USB_IDLE_NOTIFICATION                                       Equ         9
USB_RECORD_FAILURE                                          Equ         10
USB_GET_BUS_INFO                                            Equ         264
USB_GET_CONTROLLER_NAME                                     Equ         265
USB_GET_BUSGUID_INFO                                        Equ         266
USB_GET_PARENT_HUB_INFO                                     Equ         267
USB_GET_DEVICE_HANDLE                                       Equ         268
USB_GET_DEVICE_HANDLE_EX                                    Equ         269
USB_GET_TT_DEVICE_HANDLE                                    Equ         270
USB_GET_TOPOLOGY_ADDRESS                                    Equ         271
USB_IDLE_NOTIFICATION_EX                                    Equ         272
USB_REQ_GLOBAL_SUSPEND                                      Equ         273
USB_REQ_GLOBAL_RESUME                                       Equ         274
USB_GET_HUB_CONFIG_INFO                                     Equ         275

HCD_GET_STATS_1                                             Equ         255
HCD_DIAGNOSTIC_MODE_ON                                      Equ         256
HCD_DIAGNOSTIC_MODE_OFF                                     Equ         257
HCD_GET_ROOT_HUB_NAME                                       Equ         258
HCD_GET_DRIVERKEY_NAME                                      Equ         265
HCD_GET_STATS_2                                             Equ         266
HCD_DISABLE_PORT                                            Equ         268
HCD_ENABLE_PORT                                             Equ         269
HCD_USER_REQUEST                                            Equ         270
HCD_TRACE_READ_REQUEST                                      Equ         275

USB_GET_NODE_INFORMATION                                    Equ         258
USB_GET_NODE_CONNECTION_INFORMATION                         Equ         259
USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION                     Equ         260
USB_GET_NODE_CONNECTION_NAME                                Equ         261
USB_DIAG_IGNORE_HUBS_ON                                     Equ         262
USB_DIAG_IGNORE_HUBS_OFF                                    Equ         263
USB_GET_NODE_CONNECTION_DRIVERKEY_NAME                      Equ         264
USB_GET_HUB_CAPABILITIES                                    Equ         271
USB_GET_NODE_CONNECTION_ATTRIBUTES                          Equ         272
USB_HUB_CYCLE_PORT                                          Equ         273
USB_GET_NODE_CONNECTION_INFORMATION_EX                      Equ         274
USB_RESET_HUB                                               Equ         275
USB_GET_HUB_CAPABILITIES_EX                                 Equ         276

DEFINE_GUID     (GUID_DEVINTERFACE_USB_HUB,                  0F18A0E88H, 0C30CH, 011D0H, 088H, 015H, 000H, 0A0H, 0C9H, 006H, 0BEH, 0D8H)
DEFINE_GUID     (GUID_DEVINTERFACE_USB_DEVICE,               0A5DCBF10H, 06530H, 011D2H, 090H, 01FH, 000H, 0C0H, 04FH, 0B9H, 051H, 0EDH)
DEFINE_GUID     (GUID_DEVINTERFACE_USB_HOST_CONTROLLER,      03ABF6F2DH, 071C4H, 0462AH, 08AH, 092H, 01EH, 068H, 061H, 0E6H, 0AFH, 027H)

DEFINE_GUID     (GUID_USB_WMI_STD_DATA,                      04E623B20H, 0CB14H, 011D1H, 0B3H, 031H, 000H, 0A0H, 0C9H, 059H, 0BBH, 0D2H)
DEFINE_GUID     (GUID_USB_WMI_STD_NOTIFICATION,              04E623B20H, 0CB14H, 011D1H, 0B3H, 031H, 000H, 0A0H, 0C9H, 059H, 0BBH, 0D2H)
DEFINE_GUID     (GUID_USB_WMI_DEVICE_PERF_INFO,              066C1AA3CH, 0499FH, 049A0H, 0A9H, 0A5H, 061H, 0E2H, 035H, 09FH, 064H, 007H)
DEFINE_GUID     (GUID_USB_WMI_NODE_INFO,                     09C179357H, 0DC7AH, 04F41H, 0B6H, 06BH, 032H, 03BH, 09DH, 0DCH, 0B5H, 0B1H)
DEFINE_GUID     (GUID_USB_WMI_HUB_DIAGNOSTICS,               0AD0379E4H, 072DBH, 042EDH, 0BAH, 06EH, 067H, 057H, 004H, 079H, 007H, 00DH)
DEFINE_GUID     (GUID_USB_WMI_TRACING,                       03A61881BH, 0B4E6H, 04BF9H, 0AEH, 00FH, 03CH, 0D8H, 0F3H, 094H, 0E5H, 02FH)

DEFINE_GUID     (GUID_USB_TRANSFER_TRACING,                  0681EB8AAH, 0403DH, 0452CH, 09FH, 08AH, 0F0H, 061H, 06FH, 0ACH, 095H, 040H)

DEFINE_GUID     (GUID_USB_PERFORMANCE_TRACING,               0D5DE77A6H, 06AE9H, 0425CH, 0B1H, 0E2H, 0F5H, 061H, 05FH, 0D3H, 048H, 0A9H)

GUID_CLASS_USBHUB                                           Equ         GUID_DEVINTERFACE_USB_HUB
GUID_CLASS_USB_DEVICE                                       Equ         GUID_DEVINTERFACE_USB_DEVICE
GUID_CLASS_USB_HOST_CONTROLLER                              Equ         GUID_DEVINTERFACE_USB_HOST_CONTROLLER

FILE_DEVICE_USB                                             Equ         FILE_DEVICE_UNKNOWN

#ENDIF ;USBIODEF_H
