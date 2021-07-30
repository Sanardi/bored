;===========================================================;
;                                                           ;
;     ntddpar.h for Easy Code 2.0 GoAsm 32-bit drivers      ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF NTDDPAR_H
#Define NTDDPAR_H 1

#IFNDEF MACRODRV_H
    #Include macrodrv.h
#ENDIF

DEFINE_GUID                                 (GUID_DEVINTERFACE_PARALLEL, 097F76EF0H, 0F883H, 011D0H, 0AFH, 01FH, 000H, 000H, 0F8H, 000H, 084H, 05CH)
DEFINE_GUID                                 (GUID_DEVINTERFACE_PARCLASS, 0811FC6A5H, 0F728H, 011D0H, 0A5H, 037H, 000H, 000H, 0F8H, 075H, 03EH, 0D1H)

GUID_PARALLEL_DEVICE                        Equ         GUID_DEVINTERFACE_PARALLEL
GUID_PARCLASS_DEVICE                        Equ         GUID_DEVINTERFACE_PARCLASS

IOCTL_IEEE1284_GET_MODE                     Equ         CTL_CODE (FILE_DEVICE_PARALLEL_PORT, 5, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_IEEE1284_NEGOTIATE                    Equ         CTL_CODE (FILE_DEVICE_PARALLEL_PORT, 6, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_PAR_GET_DEFAULT_MODES                 Equ         CTL_CODE (FILE_DEVICE_PARALLEL_PORT, 10, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_PAR_GET_DEVICE_CAPS                   Equ         CTL_CODE (FILE_DEVICE_PARALLEL_PORT, 9, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_PAR_IS_PORT_FREE                      Equ         CTL_CODE (FILE_DEVICE_PARALLEL_PORT, 21, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_PAR_QUERY_DEVICE_ID                   Equ         CTL_CODE (FILE_DEVICE_PARALLEL_PORT, 3, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_PAR_QUERY_DEVICE_ID_SIZE              Equ         CTL_CODE (FILE_DEVICE_PARALLEL_PORT, 4, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_PAR_QUERY_INFORMATION                 Equ         CTL_CODE (FILE_DEVICE_PARALLEL_PORT, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_PAR_QUERY_LOCATION                    Equ         CTL_CODE (FILE_DEVICE_PARALLEL_PORT, 22, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_PAR_QUERY_RAW_DEVICE_ID               Equ         CTL_CODE (FILE_DEVICE_PARALLEL_PORT, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_PAR_SET_INFORMATION                   Equ         CTL_CODE (FILE_DEVICE_PARALLEL_PORT, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_PAR_SET_READ_ADDRESS                  Equ         CTL_CODE (FILE_DEVICE_PARALLEL_PORT, 8, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_PAR_SET_WRITE_ADDRESS                 Equ         CTL_CODE (FILE_DEVICE_PARALLEL_PORT, 7, METHOD_BUFFERED, FILE_ANY_ACCESS)

PAR_DEVICE_ID_SIZE_INFORMATION Struct
  DeviceIdSize                              DD
EndS

PARALLEL_INIT                               Equ         001H
PARALLEL_AUTOFEED                           Equ         002H
PARALLEL_PAPER_EMPTY                        Equ         004H
PARALLEL_OFF_LINE                           Equ         008H
PARALLEL_POWER_OFF                          Equ         010H
PARALLEL_NOT_CONNECTED                      Equ         020H
PARALLEL_BUSY                               Equ         040H
PARALLEL_SELECTED                           Equ         080H

PAR_QUERY_INFORMATION Struct
  Status                                    DB
EndS

PAR_SET_INFORMATION Struct
  Init                                      DB
EndS

PARCLASS_NEGOTIATION_MASK Struct
  usReadMask                                DW
  usWriteMask                               DW
EndS

NONE                                        Equ         0000H
CENTRONICS                                  Equ         0001H
IEEE_COMPATIBILITY                          Equ         0002H
NIBBLE                                      Equ         0004H
CHANNEL_NIBBLE                              Equ         0008H
BYTE_BIDIR                                  Equ         0010H
EPP_HW                                      Equ         0020H
EPP_SW                                      Equ         0040H
EPP_ANY                                     Equ         0060H
BOUNDED_ECP                                 Equ         0080H
ECP_HW_NOIRQ                                Equ         0100H
ECP_HW_IRQ                                  Equ         0200H
ECP_SW                                      Equ         0400H
ECP_ANY                                     Equ         0780H

#ENDIF ;NTDDPAR_H
