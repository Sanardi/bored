;===========================================================;
;                                                           ;
;    devioctl.h for Easy Code 2.0 GoAsm 32-bit drivers      ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF DEVIOCTL_H
#Define DEVIOCTL_H 1

FILE_DEVICE_BEEP                            Equ     00000001H
FILE_DEVICE_CD_ROM                          Equ     00000002H
FILE_DEVICE_CD_ROM_FILE_SYSTEM              Equ     00000003H
FILE_DEVICE_CONTROLLER                      Equ     00000004H
FILE_DEVICE_DATALINK                        Equ     00000005H
FILE_DEVICE_DFS                             Equ     00000006H
FILE_DEVICE_DISK                            Equ     00000007H
FILE_DEVICE_DISK_FILE_SYSTEM                Equ     00000008H
FILE_DEVICE_FILE_SYSTEM                     Equ     00000009H
FILE_DEVICE_INPORT_PORT                     Equ     0000000AH
FILE_DEVICE_KEYBOARD                        Equ     0000000BH
FILE_DEVICE_MAILSLOT                        Equ     0000000CH
FILE_DEVICE_MIDI_IN                         Equ     0000000DH
FILE_DEVICE_MIDI_OUT                        Equ     0000000EH
FILE_DEVICE_MOUSE                           Equ     0000000FH
FILE_DEVICE_MULTI_UNC_PROVIDER              Equ     00000010H
FILE_DEVICE_NAMED_PIPE                      Equ     00000011H
FILE_DEVICE_NETWORK                         Equ     00000012H
FILE_DEVICE_NETWORK_BROWSER                 Equ     00000013H
FILE_DEVICE_NETWORK_FILE_SYSTEM             Equ     00000014H
FILE_DEVICE_NULL                            Equ     00000015H
FILE_DEVICE_PARALLEL_PORT                   Equ     00000016H
FILE_DEVICE_PHYSICAL_NETCARD                Equ     00000017H
FILE_DEVICE_PRINTER                         Equ     00000018H
FILE_DEVICE_SCANNER                         Equ     00000019H
FILE_DEVICE_SERIAL_MOUSE_PORT               Equ     0000001AH
FILE_DEVICE_SERIAL_PORT                     Equ     0000001BH
FILE_DEVICE_SCREEN                          Equ     0000001CH
FILE_DEVICE_SOUND                           Equ     0000001DH
FILE_DEVICE_STREAMS                         Equ     0000001EH
FILE_DEVICE_TAPE                            Equ     0000001FH
FILE_DEVICE_TAPE_FILE_SYSTEM                Equ     00000020H
FILE_DEVICE_TRANSPORT                       Equ     00000021H
FILE_DEVICE_UNKNOWN                         Equ     00000022H
FILE_DEVICE_VIDEO                           Equ     00000023H
FILE_DEVICE_VIRTUAL_DISK                    Equ     00000024H
FILE_DEVICE_WAVE_IN                         Equ     00000025H
FILE_DEVICE_WAVE_OUT                        Equ     00000026H
FILE_DEVICE_8042_PORT                       Equ     00000027H
FILE_DEVICE_NETWORK_REDIRECTOR              Equ     00000028H
FILE_DEVICE_BATTERY                         Equ     00000029H
FILE_DEVICE_BUS_EXTENDER                    Equ     0000002AH
FILE_DEVICE_MODEM                           Equ     0000002BH
FILE_DEVICE_VDM                             Equ     0000002CH
FILE_DEVICE_MASS_STORAGE                    Equ     0000002DH
FILE_DEVICE_SMB                             Equ     0000002EH
FILE_DEVICE_KS                              Equ     0000002FH
FILE_DEVICE_CHANGER                         Equ     00000030H
FILE_DEVICE_SMARTCARD                       Equ     00000031H
FILE_DEVICE_ACPI                            Equ     00000032H
FILE_DEVICE_DVD                             Equ     00000033H
FILE_DEVICE_FULLSCREEN_VIDEO                Equ     00000034H
FILE_DEVICE_DFS_FILE_SYSTEM                 Equ     00000035H
FILE_DEVICE_DFS_VOLUME                      Equ     00000036H
FILE_DEVICE_SERENUM                         Equ     00000037H
FILE_DEVICE_TERMSRV                         Equ     00000038H
FILE_DEVICE_KSEC                            Equ     00000039H
FILE_DEVICE_FIPS                            Equ     0000003AH
FILE_DEVICE_INFINIBAND                      Equ     0000003BH
FILE_DEVICE_VMBUS                           Equ     0000003EH
FILE_DEVICE_CRYPT_PROVIDER                  Equ     0000003FH
FILE_DEVICE_WPD                             Equ     00000040H
FILE_DEVICE_BLUETOOTH                       Equ     00000041H
FILE_DEVICE_MT_COMPOSITE                    Equ     00000042H
FILE_DEVICE_MT_TRANSPORT                    Equ     00000043H
FILE_DEVICE_BIOMETRIC                       Equ     00000044H
FILE_DEVICE_PMI                             Equ     00000045H

METHOD_BUFFERED                             Equ     0
METHOD_IN_DIRECT                            Equ     1
METHOD_OUT_DIRECT                           Equ     2
METHOD_NEITHER                              Equ     3

METHOD_DIRECT_TO_HARDWARE                   Equ     METHOD_IN_DIRECT
METHOD_DIRECT_FROM_HARDWARE                 Equ     METHOD_OUT_DIRECT

FILE_ANY_ACCESS                             Equ     0
FILE_SPECIAL_ACCESS                         Equ     FILE_ANY_ACCESS
FILE_READ_ACCESS                            Equ     00001H
FILE_WRITE_ACCESS                           Equ     00002H

#ENDIF ;DEVIOCTL_H
