;===========================================================;
;                                                           ;
;     parallel.h for Easy Code 2.0 GoAsm 32-bit drivers     ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF PARALLEL_H
#Define PARALLEL_H 1

#Include ntddpar.h
#IFNDEF NTDEF_H
    #Include ntdef.h
#ENDIF

#Define                                         DD_PARALLEL_PORT_BASE_NAME_U L"ParallelPort"

IEEE_1284_3_DAISY_CHAIN_MAX_ID                  Equ         3

IOCTL_INTERNAL_PARALLEL_PORT_ALLOCATE           Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 11, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_INTERNAL_GET_PARALLEL_PORT_INFO           Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_PARALLEL_CONNECT_INTERRUPT       Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 13, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_PARALLEL_DISCONNECT_INTERRUPT    Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 14, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_RELEASE_PARALLEL_PORT_INFO       Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 15, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_GET_MORE_PARALLEL_PORT_INFO      Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 17, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_INTERNAL_PARCHIP_CONNECT                  Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 18, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_INTERNAL_PARALLEL_SET_CHIP_MODE           Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 19, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_PARALLEL_CLEAR_CHIP_MODE         Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 20, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_INTERNAL_GET_PARALLEL_PNP_INFO            Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 21, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_INIT_1284_3_BUS                  Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 22, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_SELECT_DEVICE                    Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 23, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_DESELECT_DEVICE                  Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 24, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_INTERNAL_GET_PARPORT_FDO                  Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 29, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_PARCLASS_CONNECT                 Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 30, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_PARCLASS_DISCONNECT              Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 31, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_DISCONNECT_IDLE                  Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 32, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_LOCK_PORT                        Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 37, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_UNLOCK_PORT                      Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 38, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_INTERNAL_PARALLEL_PORT_FREE               Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 40, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_INTERNAL_PARDOT3_CONNECT                  Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 41, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_PARDOT3_DISCONNECT               Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 42, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_PARDOT3_RESET                    Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 43, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_PARDOT3_SIGNAL                   Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 44, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_INTERNAL_REGISTER_FOR_REMOVAL_RELATIONS   Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 50, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_UNREGISTER_FOR_REMOVAL_RELATIONS Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 51, METHOD_BUFFERED, FILE_ANY_ACCESS)

PARPORT_REMOVAL_RELATIONS Struct
    DeviceObject                                DD
    Flags                                       DD
    DeviceName                                  DD
EndS

IOCTL_INTERNAL_LOCK_PORT_NO_SELECT              Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 52, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_UNLOCK_PORT_NO_DESELECT          Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 53, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_INTERNAL_DISABLE_END_OF_CHAIN_BUS_RESCAN  Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 54, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_ENABLE_END_OF_CHAIN_BUS_RESCAN   Equ         CTL_CODE(FILE_DEVICE_PARALLEL_PORT, 55, METHOD_BUFFERED, FILE_ANY_ACCESS)

MODE_LEN_1284_3                                 Equ         7

LEGACYZIP_MODE_LEN                              Equ         3

;P12843_DL_MODES Enumeration
P12843DL_OFF                                    Equ         0
P12843DL_DOT3_DL                                Equ         1
P12843DL_MLC_DL                                 Equ         2
P12843DL_DOT4_DL                                Equ         3

CPP_ASSIGN_ADDR                                 Equ         000H
CPP_SELECT                                      Equ         0E0H
CPP_DESELECT                                    Equ         030H
CPP_QUERY_INT                                   Equ         008H
CPP_DISABLE_INT                                 Equ         040H
CPP_ENABLE_INT                                  Equ         048H
CPP_CLEAR_INT_LAT                               Equ         050H
CPP_SET_INT_LAT                                 Equ         058H
CPP_COMMAND_FILTER                              Equ         0F8H

PPT_NO_HARDWARE_PRESENT                         Equ         00000000H
PPT_ECP_PRESENT                                 Equ         00000001H
PPT_EPP_PRESENT                                 Equ         00000002H
PPT_EPP_32_PRESENT                              Equ         00000004H
PPT_BYTE_PRESENT                                Equ         00000008H
PPT_BIDI_PRESENT                                Equ         00000008H
PPT_1284_3_PRESENT                              Equ         00000010H

PARALLEL_PARCHIP_INFO Struct
    Controller                                  DD
    EcrController                               DD
    HardwareModes                               DD
    ParChipSetMode                              DD
    ParChipClearMode                            DD
    Context                                     DD
    success                                     DB
EndS

PARALLEL_PORT_INFORMATION Struct
    OriginalController                          PHYSICAL_ADDRESS
    Controller                                  DD
    SpanOfController                            DD
    TryAllocatePort                             DD
    FreePort                                    DD
    QueryNumWaiters                             DD
    Context                                     DD
EndS

PARALLEL_PNP_INFORMATION Struct
    OriginalEcpController                       PHYSICAL_ADDRESS
    EcpController                               DD
    SpanOfEcpController                         DD
    PortNumber                                  DD
    HardwareCapabilities                        DD
    TrySetChipMode                              DD
    ClearChipMode                               DD
    FifoDepth                                   DD
    FifoWidth                                   DD
    EppControllerPhysicalAddress                PHYSICAL_ADDRESS
    SpanOfEppController                         DD
    Ieee1284_3DeviceCount                       DD
    TrySelectDevice                             DD
    DeselectDevice                              DD
    Context                                     DD
    CurrentMode                                 DD
    PortName                                    DD
EndS

PAR_END_OF_CHAIN_DEVICE                         Equ         (00000001H)
PAR_HAVE_PORT_KEEP_PORT                         Equ         (00000002H)
PAR_LEGACY_ZIP_DRIVE                            Equ         (00000004H)
PAR_LEGACY_ZIP_DRIVE_STD_MODE                   Equ         (00000010H)
PAR_LEGACY_ZIP_DRIVE_EPP_MODE                   Equ         (00000020H)

DOT3_END_OF_CHAIN_ID                            Equ         4
DOT3_LEGACY_ZIP_ID                              Equ         5

PARALLEL_1284_COMMAND Struct
    ID                                          DB
    Port                                        DB
    CommandFlags                                DD
EndS

INITIAL_MODE                                    Equ         00000000H

PARCHIP_ECR_ARBITRATOR                          Equ         1

PARALLEL_CHIP_MODE Struct
    ModeFlags                                   DB
    success                                     DB
EndS

PARALLEL_INTERRUPT_SERVICE_ROUTINE Struct
    InterruptServiceRoutine                     DD
    InterruptServiceContext                     DD
    DeferredPortCheckRoutine                    DD
    DeferredPortCheckContext                    DD
EndS

PARALLEL_INTERRUPT_INFORMATION Struct
    InterruptObject                             DD
    TryAllocatePortAtInterruptLevel             DD
    FreePortFromInterruptLevel                  DD
    Context                                     DD
EndS

MORE_PARALLEL_PORT_INFORMATION Struct
    InterfaceType                               DD
    BusNumber                                   DD
    InterruptLevel                              DD
    InterruptVector                             DD
    InterruptAffinity                           DD
    InterruptMode                               DD
EndS

;PARALLEL_SAFETY Enumeration
SAFE_MODE                                       Equ         0
UNSAFE_MODE                                     Equ         1

OLD_PARCLASS                                    Equ         0

PARCLASS_INFORMATION Struct
    Controller                                  DD
    EcrController                               DD
    SpanOfController                            DD
    DetermineIeeeModes                          DD
    NegotiateIeeeMode                           DD
    TerminateIeeeMode                           DD
    IeeeFwdToRevMode                            DD
    IeeeRevToFwdMode                            DD
    ParallelRead                                DD
    ParallelWrite                               DD
    ParclassContext                             DD
    HardwareCapabilities                        DD
    FifoDepth                                   DD
    FifoWidth                                   DD
    ParallelTryselect                           DD
    ParallelDeSelect                            DD
EndS

DATA_OFFSET                                     Equ         0
OFFSET_ECP_AFIFO                                Equ         0000H
AFIFO_OFFSET                                    Equ         OFFSET_ECP_AFIFO
DSR_OFFSET                                      Equ         1
DCR_OFFSET                                      Equ         2
EPP_OFFSET                                      Equ         4

#IFNDEF DVRH_USE_PARPORT_ECP_ADDR
    DVRH_USE_PARPORT_ECP_ADDR                   Equ 0
#ENDIF

#IFDEF DVRH_USE_PARPORT_ECP_ADDR
    #IF DVRH_USE_PARPORT_ECP_ADDR == 0
        ECP_OFFSET                              Equ         0400H
        CNFGB_OFFSET                            Equ         0401H
        ECR_OFFSET                              Equ         0402H
    #ELSE
        ECP_OFFSET                              Equ         00H
        CNFGB_OFFSET                            Equ         01H
        ECR_OFFSET                              Equ         02H
    #ENDIF
#ELSE
    ECP_OFFSET                                  Equ         00H
    CNFGB_OFFSET                                Equ         01H
    ECR_OFFSET                                  Equ         02H
#ENDIF

FIFO_OFFSET                                     Equ         ECP_OFFSET
CFIFO_OFFSET                                    Equ         ECP_OFFSET
CNFGA_OFFSET                                    Equ         ECP_OFFSET
ECP_DFIFO_OFFSET                                Equ         ECP_OFFSET
TFIFO_OFFSET                                    Equ         ECP_OFFSET
OFFSET_ECP_DFIFO                                Equ         ECP_OFFSET
OFFSET_TFIFO                                    Equ         ECP_OFFSET
OFFSET_CFIFO                                    Equ         ECP_OFFSET
OFFSET_ECR                                      Equ         ECR_OFFSET

OFFSET_PARALLEL_REGISTER_SPAN                   Equ         0003H

ECP_SPAN                                        Equ         3
EPP_SPAN                                        Equ         4

DSR_NOT_BUSY                                    Equ         080H
DSR_NOT_ACK                                     Equ         040H
DSR_PERROR                                      Equ         020H
DSR_SELECT                                      Equ         010H
DSR_NOT_FAULT                                   Equ         008H

DSR_NOT_PTR_BUSY                                Equ         080H
DSR_NOT_PERIPH_ACK                              Equ         080H
DSR_WAIT                                        Equ         080H
DSR_PTR_CLK                                     Equ         040H
DSR_PERIPH_CLK                                  Equ         040H
DSR_INTR                                        Equ         040H
DSR_ACK_DATA_REQ                                Equ         020H
DSR_NOT_ACK_REVERSE                             Equ         020H
DSR_XFLAG                                       Equ         010H
DSR_NOT_DATA_AVAIL                              Equ         008H
DSR_NOT_PERIPH_REQUEST                          Equ         008H

DCR_RESERVED                                    Equ         0C0H
DCR_DIRECTION                                   Equ         020H
DCR_ACKINT_ENABLED                              Equ         010H
DCR_SELECT_IN                                   Equ         008H
DCR_NOT_INIT                                    Equ         004H
DCR_AUTOFEED                                    Equ         002H
DCR_STROBE                                      Equ         001H

DCR_NOT_1284_ACTIVE                             Equ         008H
DCR_ASTRB                                       Equ         008H
DCR_NOT_REVERSE_REQUEST                         Equ         004H
DCR_NULL                                        Equ         004H
DCR_NOT_HOST_BUSY                               Equ         002H
DCR_NOT_HOST_ACK                                Equ         002H
DCR_DSTRB                                       Equ         002H
DCR_NOT_HOST_CLK                                Equ         001H
DCR_WRITE                                       Equ         001H

CNFGA_IMPID_MASK                                Equ         070H
CNFGA_IMPID_16BIT                               Equ         000H
CNFGA_IMPID_8BIT                                Equ         010H
CNFGA_IMPID_32BIT                               Equ         020H

CNFGA_NO_TRANS_BYTE                             Equ         004H

#IF (PARCHIP_ECR_ARBITRATOR Eq 0)
    DEFAULT_ECR_PS2                             Equ         034H
    DEFAULT_ECR_ECP                             Equ         074H
#ENDIF

ECR_ERRINT_DISABLED                             Equ         010H
ECR_DMA_ENABLED                                 Equ         008H
ECR_SVC_INT_DISABLED                            Equ         004H

ECR_MODE_MASK                                   Equ         01FH
ECR_SPP_MODE                                    Equ         000H
ECR_BYTE_MODE                                   Equ         020H
ECR_BYTE_PIO_MODE                               Equ         (ECR_BYTE_MODE | ECR_ERRINT_DISABLED | ECR_SVC_INT_DISABLED)

ECR_FASTCENT_MODE                               Equ         040H
ECR_ECP_MODE                                    Equ         060H
ECR_ECP_PIO_MODE                                Equ         (ECR_ECP_MODE | ECR_ERRINT_DISABLED | ECR_SVC_INT_DISABLED)

ECR_EPP_MODE                                    Equ         080H
ECR_EPP_PIO_MODE                                Equ         (ECR_EPP_MODE | ECR_ERRINT_DISABLED | ECR_SVC_INT_DISABLED)

ECR_RESERVED_MODE                               Equ         010H
ECR_TEST_MODE                                   Equ         0C0H
ECR_CONFIG_MODE                                 Equ         0E0H

DEFAULT_ECR_TEST                                Equ         0D4H
DEFAULT_ECR_COMPATIBILITY                       Equ         014H

DEFAULT_ECR_CONFIGURATION                       Equ         0F4H

ECR_FIFO_MASK                                   Equ         003H
ECR_FIFO_FULL                                   Equ         002H
ECR_FIFO_EMPTY                                  Equ         001H
ECR_FIFO_SOME_DATA                              Equ         000H

ECP_MAX_FIFO_DEPTH                              Equ         4098

CNFGA_IMPID_MASK                                Equ         070H
CNFGA_IMPID_SHIFT                               Equ         4

FIFO_PWORD_8BIT                                 Equ         1
FIFO_PWORD_16BIT                                Equ         0
FIFO_PWORD_32BIT                                Equ         2

BIT_7                                           Equ         7
BIT_6                                           Equ         6
BIT_5                                           Equ         5
BIT_4                                           Equ         4
BIT_3                                           Equ         3
BIT_2                                           Equ         2
BIT_1                                           Equ         1
BIT_0                                           Equ         0

BIT_7_SET                                       Equ         080H
BIT_6_SET                                       Equ         040H
BIT_5_SET                                       Equ         020H
BIT_4_SET                                       Equ         010H
BIT_3_SET                                       Equ         08H
BIT_2_SET                                       Equ         04H
BIT_1_SET                                       Equ         02H
BIT_0_SET                                       Equ         01H

DIR_READ                                        Equ         1
DIR_WRITE                                       Equ         0

IRQEN_ENABLE                                    Equ         1
IRQEN_DISABLE                                   Equ         0
             
ACTIVE                                          Equ         1
INACTIVE                                        Equ         0             
DONT_CARE                                       Equ         2

DVRH_USE_FAST_MACROS                            Equ         1
DVRH_USE_NIBBLE_MACROS                          Equ         1

;P1284_PHASE Enumeration
PHASE_UNKNOWN                                   Equ         0
PHASE_NEGOTIATION                               Equ         1
PHASE_SETUP                                     Equ         2
PHASE_FORWARD_IDLE                              Equ         3
PHASE_FORWARD_XFER                              Equ         4
PHASE_FWD_TO_REV                                Equ         5
PHASE_REVERSE_IDLE                              Equ         6
PHASE_REVERSE_XFER                              Equ         7
PHASE_REV_TO_FWD                                Equ         8
PHASE_TERMINATE                                 Equ         9
PHASE_DATA_AVAILABLE                            Equ         10
PHASE_DATA_NOT_AVAIL                            Equ         11
PHASE_INTERRUPT_HOST                            Equ         12

;P1284_HW_MODE Enumeration
HW_MODE_COMPATIBILITY                           Equ         0
HW_MODE_PS2                                     Equ         1
HW_MODE_FAST_CENTRONICS                         Equ         2
HW_MODE_ECP                                     Equ         3
HW_MODE_EPP                                     Equ         4
HW_MODE_RESERVED                                Equ         5
HW_MODE_TEST                                    Equ         6
HW_MODE_CONFIGURATION                           Equ         7

#ENDIF ;PARALLEL_H
