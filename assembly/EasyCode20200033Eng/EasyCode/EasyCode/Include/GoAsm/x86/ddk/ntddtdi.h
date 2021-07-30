;===========================================================;
;                                                           ;
;     ntddtdi.h for Easy Code 2.0 GoAsm 32-bit drivers      ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF NTDDTDI_H
#Define NTDDTDI_H 1

#Define                                 DD_TDI_DEVICE_NAME "\Device\UNKNOWN"

#IFNDEF MACRODRV_H
    #Include macrodrv.h
#ENDIF

IOCTL_TDI_ACCEPT                        Equ     CTL_CODE(FILE_DEVICE_TRANSPORT, 0, METHOD_BUFFERED , FILE_ANY_ACCESS)
IOCTL_TDI_CONNECT                       Equ     CTL_CODE(FILE_DEVICE_TRANSPORT, 1, METHOD_BUFFERED , FILE_ANY_ACCESS)
IOCTL_TDI_DISCONNECT                    Equ     CTL_CODE(FILE_DEVICE_TRANSPORT, 2, METHOD_BUFFERED , FILE_ANY_ACCESS)
IOCTL_TDI_LISTEN                        Equ     CTL_CODE(FILE_DEVICE_TRANSPORT, 3, METHOD_BUFFERED , FILE_ANY_ACCESS)
IOCTL_TDI_QUERY_INFORMATION             Equ     CTL_CODE(FILE_DEVICE_TRANSPORT, 4, METHOD_OUT_DIRECT , FILE_ANY_ACCESS)
IOCTL_TDI_RECEIVE                       Equ     CTL_CODE(FILE_DEVICE_TRANSPORT, 5, METHOD_OUT_DIRECT , FILE_ANY_ACCESS)
IOCTL_TDI_RECEIVE_DATAGRAM              Equ     CTL_CODE(FILE_DEVICE_TRANSPORT, 6, METHOD_OUT_DIRECT , FILE_ANY_ACCESS)
IOCTL_TDI_SEND                          Equ     CTL_CODE(FILE_DEVICE_TRANSPORT, 7, METHOD_IN_DIRECT , FILE_ANY_ACCESS)
IOCTL_TDI_SEND_DATAGRAM                 Equ     CTL_CODE(FILE_DEVICE_TRANSPORT, 8, METHOD_IN_DIRECT , FILE_ANY_ACCESS)
IOCTL_TDI_SET_EVENT_HANDLER             Equ     CTL_CODE(FILE_DEVICE_TRANSPORT, 9, METHOD_BUFFERED , FILE_ANY_ACCESS)
IOCTL_TDI_SET_INFORMATION               Equ     CTL_CODE(FILE_DEVICE_TRANSPORT, 10, METHOD_IN_DIRECT , FILE_ANY_ACCESS)
IOCTL_TDI_ASSOCIATE_ADDRESS             Equ     CTL_CODE(FILE_DEVICE_TRANSPORT, 11, METHOD_BUFFERED , FILE_ANY_ACCESS)
IOCTL_TDI_DISASSOCIATE_ADDRESS          Equ     CTL_CODE(FILE_DEVICE_TRANSPORT, 12, METHOD_BUFFERED , FILE_ANY_ACCESS)
IOCTL_TDI_ACTION                        Equ     CTL_CODE(FILE_DEVICE_TRANSPORT, 13, METHOD_OUT_DIRECT , FILE_ANY_ACCESS)

#ENDIF ;NTDDTDI_H
