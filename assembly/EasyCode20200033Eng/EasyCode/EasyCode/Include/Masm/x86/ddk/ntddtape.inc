;===================================================================;
;                                                                   ;
;  ntddtape.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF NTDDTAPE_INC
NTDDTAPE_INC Equ 1

Include ntddstor.inc

DD_TAPE_DEVICE_NAME                         Equ         A("\Device\Tape")
DD_TAPE_DEVICE_NAME_U                       Equ         L("\Device\Tape")

IOCTL_TAPE_BASE                             Equ         FILE_DEVICE_TAPE

IOCTL_TAPE_CHECK_VERIFY                     Equ         CTL_CODE(IOCTL_TAPE_BASE, 0200H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_TAPE_CREATE_PARTITION                 Equ         CTL_CODE(IOCTL_TAPE_BASE, 000AH, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_TAPE_ERASE                            Equ         CTL_CODE(IOCTL_TAPE_BASE, 0000H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_TAPE_FIND_NEW_DEVICES                 Equ         CTL_CODE(IOCTL_DISK_BASE, 0206H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_TAPE_GET_DRIVE_PARAMS                 Equ         CTL_CODE(IOCTL_TAPE_BASE, 0005H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_TAPE_GET_MEDIA_PARAMS                 Equ         CTL_CODE(IOCTL_TAPE_BASE, 0007H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_TAPE_GET_POSITION                     Equ         CTL_CODE(IOCTL_TAPE_BASE, 0003H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_TAPE_GET_STATUS                       Equ         CTL_CODE(IOCTL_TAPE_BASE, 0009H, METHOD_BUFFERED, FILE_READ_ACCESS)

IOCTL_TAPE_PREPARE                          Equ         CTL_CODE(IOCTL_TAPE_BASE, 0001H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_TAPE_SET_DRIVE_PARAMS                 Equ         CTL_CODE(IOCTL_TAPE_BASE, 0006H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_TAPE_SET_MEDIA_PARAMS                 Equ         CTL_CODE(IOCTL_TAPE_BASE, 0008H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_TAPE_SET_POSITION                     Equ         CTL_CODE(IOCTL_TAPE_BASE, 0004H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_TAPE_WRITE_MARKS                      Equ         CTL_CODE(IOCTL_TAPE_BASE, 0002H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)

;TAPE_DRIVE_PROBLEM_TYPE Enumeration
TapeDriveProblemNone                        Equ         0
TapeDriveReadWriteWarning                   Equ         1
TapeDriveReadWriteError                     Equ         2
TapeDriveReadWarning                        Equ         3
TapeDriveWriteWarning                       Equ         4
TapeDriveReadError                          Equ         5
TapeDriveWriteError                         Equ         6
TapeDriveHardwareError                      Equ         7
TapeDriveUnsupportedMedia                   Equ         8
TapeDriveScsiConnectionError                Equ         9
TapeDriveTimetoClean                        Equ         10
TapeDriveCleanDriveNow                      Equ         11
TapeDriveMediaLifeExpired                   Equ         12
TapeDriveSnappedTape                        Equ         13

ENDIF ;NTDDTAPE_INC
