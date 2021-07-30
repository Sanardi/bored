;===================================================================;
;                                                                   ;
;   ntddser.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF NTDDSER_INC
NTDDSER_INC Equ 1

IFNDEF MACRODRV_INC
    Include macrodrv.inc
ENDIF

IFDEF DEFINE_GUID
    DEFINE_GUID GUID_DEVINTERFACE_COMPORT,                  86E0D1E0H, 08089H, 11D0H, 09CH, 0E4H, 08H, 00H, 3EH, 030H, 1FH, 73H
    DEFINE_GUID GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR,   4D36E978H, 0E325H, 11CEH, 0BFH, 0C1H, 08H, 00H, 2BH, 0E1H, 03H, 18H

    GUID_CLASS_COMPORT                                      Equ         GUID_DEVINTERFACE_COMPORT
    GUID_SERENUM_BUS_ENUMERATOR                             Equ         GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR
ENDIF

IOCTL_SERIAL_SET_BAUD_RATE                                  Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_SET_QUEUE_SIZE                                 Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_SET_LINE_CONTROL                               Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 3, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_SET_BREAK_ON                                   Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 4, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_SET_BREAK_OFF                                  Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 5, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_IMMEDIATE_CHAR                                 Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 6, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_SET_TIMEOUTS                                   Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 7, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_GET_TIMEOUTS                                   Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 8, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_SET_DTR                                        Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 9, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_CLR_DTR                                        Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 10, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_RESET_DEVICE                                   Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 11, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_SET_RTS                                        Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_CLR_RTS                                        Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 13, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_SET_XOFF                                       Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 14, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_SET_XON                                        Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 15, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_GET_WAIT_MASK                                  Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 16, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_SET_WAIT_MASK                                  Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 17, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_WAIT_ON_MASK                                   Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 18, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_PURGE                                          Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 19, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_GET_BAUD_RATE                                  Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 20, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_GET_LINE_CONTROL                               Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 21, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_GET_CHARS                                      Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 22, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_SET_CHARS                                      Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 23, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_GET_HANDFLOW                                   Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 24, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_SET_HANDFLOW                                   Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 25, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_GET_MODEMSTATUS                                Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 26, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_GET_COMMSTATUS                                 Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 27, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_XOFF_COUNTER                                   Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 28, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_GET_PROPERTIES                                 Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 29, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_GET_DTRRTS                                     Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 30, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_SERIAL_LSRMST_INSERT                                  Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 31, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_SERENUM_EXPOSE_HARDWARE                               Equ         CTL_CODE(FILE_DEVICE_SERENUM, 128, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERENUM_REMOVE_HARDWARE                               Equ         CTL_CODE(FILE_DEVICE_SERENUM, 129, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERENUM_PORT_DESC                                     Equ         CTL_CODE(FILE_DEVICE_SERENUM, 130, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERENUM_GET_PORT_NAME                                 Equ         CTL_CODE(FILE_DEVICE_SERENUM, 131, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_SERIAL_CONFIG_SIZE                                    Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 32,METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_GET_COMMCONFIG                                 Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 33, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_SET_COMMCONFIG                                 Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 34, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_SERIAL_GET_STATS                                      Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 35, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_CLEAR_STATS                                    Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 36, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_GET_MODEM_CONTROL                              Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 37, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_SET_MODEM_CONTROL                              Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 38, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_SET_FIFO_CONTROL                               Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 39, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_SERIAL_INTERNAL_DO_WAIT_WAKE                          Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_INTERNAL_CANCEL_WAIT_WAKE                      Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_INTERNAL_BASIC_SETTINGS                        Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 3, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SERIAL_INTERNAL_RESTORE_SETTINGS                      Equ         CTL_CODE(FILE_DEVICE_SERIAL_PORT, 4, METHOD_BUFFERED, FILE_ANY_ACCESS)

SERIALPERF_STATS Struct
    ReceivedCount                                           DD          ?
    TransmittedCount                                        DD          ?
    FrameErrorCount                                         DD          ?
    SerialOverrunErrorCount                                 DD          ?
    BufferOverrunErrorCount                                 DD          ?
    ParityErrorCount                                        DD          ?
SERIALPERF_STATS EndS
PSERIALPERF_STATS                                           TypeDef     DWord

SERIALCONFIG Struct
    _Size                                                   DD          ?   ;Size
    Version                                                 DW          ?
    SubType                                                 DD          ?
    ProvOffset                                              DD          ?
    ProviderSize                                            DD          ?
    ProviderData                                            DW          1 Dup(?)
SERIALCONFIG EndS
PSERIALCONFIG                                               TypeDef     DWord

SERIAL_LINE_CONTROL Struct
    StopBits                                                DB          ?
    Parity                                                  DB          ?
    WordLength                                              DB          ?
SERIAL_LINE_CONTROL EndS
PSERIAL_LINE_CONTROL                                        TypeDef     DWord

SERIAL_TIMEOUTS Struct
    ReadIntervalTimeout                                     DD          ?
    ReadTotalTimeoutMultiplier                              DD          ?
    ReadTotalTimeoutConstant                                DD          ?
    WriteTotalTimeoutMultiplier                             DD          ?
    WriteTotalTimeoutConstant                               DD          ?
SERIAL_TIMEOUTS EndS
PSERIAL_TIMEOUTS                                            TypeDef     DWord

SERIAL_QUEUE_SIZE Struct
    InSize                                                  DD          ?
    OutSize                                                 DD          ?
SERIAL_QUEUE_SIZE EndS
PSERIAL_QUEUE_SIZE                                          TypeDef     DWord

SERIAL_BAUD_RATE Struct
    BaudRate                                                DD          ?
SERIAL_BAUD_RATE EndS
PSERIAL_BAUD_RATE                                           TypeDef     DWord

SERIAL_EV_RXCHAR                                            Equ         0001H
SERIAL_EV_RXFLAG                                            Equ         0002H
SERIAL_EV_TXEMPTY                                           Equ         0004H
SERIAL_EV_CTS                                               Equ         0008H
SERIAL_EV_DSR                                               Equ         0010H
SERIAL_EV_RLSD                                              Equ         0020H
SERIAL_EV_BREAK                                             Equ         0040H
SERIAL_EV_ERR                                               Equ         0080H
SERIAL_EV_RING                                              Equ         0100H
SERIAL_EV_PERR                                              Equ         0200H
SERIAL_EV_RX80FULL                                          Equ         0400H
SERIAL_EV_EVENT1                                            Equ         0800H
SERIAL_EV_EVENT2                                            Equ         1000H

SERIAL_PURGE_TXABORT                                        Equ         00000001H
SERIAL_PURGE_RXABORT                                        Equ         00000002H
SERIAL_PURGE_TXCLEAR                                        Equ         00000004H
SERIAL_PURGE_RXCLEAR                                        Equ         00000008H

STOP_BIT_1                                                  Equ         0
STOP_BITS_1_5                                               Equ         1
STOP_BITS_2                                                 Equ         2

NO_PARITY                                                   Equ         0
ODD_PARITY                                                  Equ         1
EVEN_PARITY                                                 Equ         2
MARK_PARITY                                                 Equ         3
SPACE_PARITY                                                Equ         4

SERIAL_CHARS Struct
    EofChar                                                 DB          ?
    ErrorChar                                               DB          ?
    BreakChar                                               DB          ?
    EventChar                                               DB          ?
    XonChar                                                 DB          ?
    XoffChar                                                DB          ?
SERIAL_CHARS EndS
PSERIAL_CHARS                                               TypeDef     DWord

SERIAL_HANDFLOW Struct
    ControlHandShake                                        DD          ?
    FlowReplace                                             DD          ?
    XonLimit                                                DD          ?
    XoffLimit                                               DD          ?
SERIAL_HANDFLOW EndS
PSERIAL_HANDFLOW                                            TypeDef     DWord

SERIAL_DTR_MASK                                             Equ         (03H)
SERIAL_DTR_CONTROL                                          Equ         (01H)
SERIAL_DTR_HANDSHAKE                                        Equ         (02H)
SERIAL_CTS_HANDSHAKE                                        Equ         (08H)
SERIAL_DSR_HANDSHAKE                                        Equ         (10H)
SERIAL_DCD_HANDSHAKE                                        Equ         (20H)
SERIAL_OUT_HANDSHAKEMASK                                    Equ         (38H)
SERIAL_DSR_SENSITIVITY                                      Equ         (40H)
SERIAL_ERROR_ABORT                                          Equ         (80000000H)
SERIAL_CONTROL_INVALID                                      Equ         (7FFFFF84H)
SERIAL_AUTO_TRANSMIT                                        Equ         (01H)
SERIAL_AUTO_RECEIVE                                         Equ         (02H)
SERIAL_ERROR_CHAR                                           Equ         (04H)
SERIAL_NULL_STRIPPING                                       Equ         (08H)
SERIAL_BREAK_CHAR                                           Equ         (10H)
SERIAL_RTS_MASK                                             Equ         (0C0H)
SERIAL_RTS_CONTROL                                          Equ         (40H)
SERIAL_RTS_HANDSHAKE                                        Equ         (80H)
SERIAL_TRANSMIT_TOGGLE                                      Equ         (0C0H)
SERIAL_XOFF_CONTINUE                                        Equ         (80000000H)
SERIAL_FLOW_INVALID                                         Equ         (7FFFFF20H)

SERIAL_TX_WAITING_FOR_CTS                                   Equ         (00000001H)
SERIAL_TX_WAITING_FOR_DSR                                   Equ         (00000002H)
SERIAL_TX_WAITING_FOR_DCD                                   Equ         (00000004H)
SERIAL_TX_WAITING_FOR_XON                                   Equ         (00000008H)
SERIAL_TX_WAITING_XOFF_SENT                                 Equ         (00000010H)
SERIAL_TX_WAITING_ON_BREAK                                  Equ         (00000020H)
SERIAL_RX_WAITING_FOR_DSR                                   Equ         (00000040H)

SERIAL_ERROR_BREAK                                          Equ         (00000001H)
SERIAL_ERROR_FRAMING                                        Equ         (00000002H)
SERIAL_ERROR_OVERRUN                                        Equ         (00000004H)
SERIAL_ERROR_QUEUEOVERRUN                                   Equ         (00000008H)
SERIAL_ERROR_PARITY                                         Equ         (00000010H)

SERIAL_BASIC_SETTINGS Struct
   Timeouts                                                 SERIAL_TIMEOUTS <>
   HandFlow                                                 SERIAL_HANDFLOW <>
   RxFifo                                                   DD          ?
   TxFifo                                                   DD          ?
SERIAL_BASIC_SETTINGS EndS
PSERIAL_BASIC_SETTINGS                                      TypeDef     DWord

SERIAL_STATUS Struct
    Errors                                                  DD          ?
    HoldReasons                                             DD          ?
    AmountInInQueue                                         DD          ?
    AmountInOutQueue                                        DD          ?
    EofReceived                                             BOOLEAN     ?
    WaitForImmediate                                        BOOLEAN     ?
SERIAL_STATUS EndS
PSERIAL_STATUS                                              TypeDef     DWord

SERIAL_XOFF_COUNTER Struct
    Timeout                                                 DD          ?
    Counter                                                 DD          ?
    XoffChar                                                DB          ?
SERIAL_XOFF_COUNTER EndS
PSERIAL_XOFF_COUNTER                                        TypeDef     DWord

SERIAL_SP_SERIALCOMM                                        Equ         (00000001H)

SERIAL_SP_UNSPECIFIED                                       Equ         (00000000H)
SERIAL_SP_RS232                                             Equ         (00000001H)
SERIAL_SP_PARALLEL                                          Equ         (00000002H)
SERIAL_SP_RS422                                             Equ         (00000003H)
SERIAL_SP_RS423                                             Equ         (00000004H)
SERIAL_SP_RS449                                             Equ         (00000005H)
SERIAL_SP_MODEM                                             Equ         (00000006H)
SERIAL_SP_FAX                                               Equ         (00000021H)
SERIAL_SP_SCANNER                                           Equ         (00000022H)
SERIAL_SP_BRIDGE                                            Equ         (00000100H)
SERIAL_SP_LAT                                               Equ         (00000101H)
SERIAL_SP_TELNET                                            Equ         (00000102H)
SERIAL_SP_X25                                               Equ         (00000103H)

SERIAL_PCF_DTRDSR                                           Equ         (0001H)
SERIAL_PCF_RTSCTS                                           Equ         (0002H)
SERIAL_PCF_CD                                               Equ         (0004H)
SERIAL_PCF_PARITY_CHECK                                     Equ         (0008H)
SERIAL_PCF_XONXOFF                                          Equ         (0010H)
SERIAL_PCF_SETXCHAR                                         Equ         (0020H)
SERIAL_PCF_TOTALTIMEOUTS                                    Equ         (0040H)
SERIAL_PCF_INTTIMEOUTS                                      Equ         (0080H)
SERIAL_PCF_SPECIALCHARS                                     Equ         (0100H)
SERIAL_PCF_16BITMODE                                        Equ         (0200H)

SERIAL_SP_PARITY                                            Equ         (0001H)
SERIAL_SP_BAUD                                              Equ         (0002H)
SERIAL_SP_DATABITS                                          Equ         (0004H)
SERIAL_SP_STOPBITS                                          Equ         (0008H)
SERIAL_SP_HANDSHAKING                                       Equ         (0010H)
SERIAL_SP_PARITY_CHECK                                      Equ         (0020H)
SERIAL_SP_CARRIER_DETECT                                    Equ         (0040H)

SERIAL_BAUD_075                                             Equ         (00000001H)
SERIAL_BAUD_110                                             Equ         (00000002H)
SERIAL_BAUD_134_5                                           Equ         (00000004H)
SERIAL_BAUD_150                                             Equ         (00000008H)
SERIAL_BAUD_300                                             Equ         (00000010H)
SERIAL_BAUD_600                                             Equ         (00000020H)
SERIAL_BAUD_1200                                            Equ         (00000040H)
SERIAL_BAUD_1800                                            Equ         (00000080H)
SERIAL_BAUD_2400                                            Equ         (00000100H)
SERIAL_BAUD_4800                                            Equ         (00000200H)
SERIAL_BAUD_7200                                            Equ         (00000400H)
SERIAL_BAUD_9600                                            Equ         (00000800H)
SERIAL_BAUD_14400                                           Equ         (00001000H)
SERIAL_BAUD_19200                                           Equ         (00002000H)
SERIAL_BAUD_38400                                           Equ         (00004000H)
SERIAL_BAUD_56K                                             Equ         (00008000H)
SERIAL_BAUD_128K                                            Equ         (00010000H)
SERIAL_BAUD_115200                                          Equ         (00020000H)
SERIAL_BAUD_57600                                           Equ         (00040000H)
SERIAL_BAUD_USER                                            Equ         (10000000H)

SERIAL_DATABITS_5                                           Equ         (0001H)
SERIAL_DATABITS_6                                           Equ         (0002H)
SERIAL_DATABITS_7                                           Equ         (0004H)
SERIAL_DATABITS_8                                           Equ         (0008H)
SERIAL_DATABITS_16                                          Equ         (0010H)
SERIAL_DATABITS_16X                                         Equ         (0020H)

SERIAL_STOPBITS_10                                          Equ         (0001H)
SERIAL_STOPBITS_15                                          Equ         (0002H)
SERIAL_STOPBITS_20                                          Equ         (0004H)
SERIAL_PARITY_NONE                                          Equ         (0100H)
SERIAL_PARITY_ODD                                           Equ         (0200H)
SERIAL_PARITY_EVEN                                          Equ         (0400H)
SERIAL_PARITY_MARK                                          Equ         (0800H)
SERIAL_PARITY_SPACE                                         Equ         (1000H)

SERIAL_COMMPROP Struct
    PacketLength                                            DW          ?
    PacketVersion                                           DW          ?
    ServiceMask                                             DD          ?
    Reserved1                                               DD          ?
    MaxTxQueue                                              DD          ?
    MaxRxQueue                                              DD          ?
    MaxBaud                                                 DD          ?
    ProvSubType                                             DD          ?
    ProvCapabilities                                        DD          ?
    SettableParams                                          DD          ?
    SettableBaud                                            DD          ?
    SettableData                                            DW          ?
    SettableStopParity                                      DW          ?
    CurrentTxQueue                                          DD          ?
    CurrentRxQueue                                          DD          ?
    ProvSpec1                                               DD          ?   
    ProvSpec2                                               DD          ?
    ProvChar                                                DW          1 Dup(?)
SERIAL_COMMPROP EndS
PSERIAL_COMMPROP                                            TypeDef     DWord

SERIAL_DTR_STATE                                            Equ         (00000001H)
SERIAL_RTS_STATE                                            Equ         (00000002H)
SERIAL_CTS_STATE                                            Equ         (00000010H)
SERIAL_DSR_STATE                                            Equ         (00000020H)
SERIAL_RI_STATE                                             Equ         (00000040H)
SERIAL_DCD_STATE                                            Equ         (00000080H)

SERIAL_LSRMST_ESCAPE                                        Equ         (00H)
SERIAL_LSRMST_LSR_DATA                                      Equ         (01H)
SERIAL_LSRMST_LSR_NODATA                                    Equ         (02H)
SERIAL_LSRMST_MST                                           Equ         (03H)

SERIAL_IOC_FCR_FIFO_ENABLE                                  Equ         (00000001H)
SERIAL_IOC_FCR_RCVR_RESET                                   Equ         (00000002H)
SERIAL_IOC_FCR_XMIT_RESET                                   Equ         (00000004H)
SERIAL_IOC_FCR_DMA_MODE                                     Equ         (00000008H)
SERIAL_IOC_FCR_RES1                                         Equ         (00000010H)
SERIAL_IOC_FCR_RES2                                         Equ         (00000020H)
SERIAL_IOC_FCR_RCVR_TRIGGER_LSB                             Equ         (00000040H)
SERIAL_IOC_FCR_RCVR_TRIGGER_MSB                             Equ         (00000080H)

SERIAL_IOC_MCR_DTR                                          Equ         (00000001H)
SERIAL_IOC_MCR_RTS                                          Equ         (00000002H)
SERIAL_IOC_MCR_OUT1                                         Equ         (00000004H)
SERIAL_IOC_MCR_OUT2                                         Equ         (00000008H)
SERIAL_IOC_MCR_LOOP                                         Equ         (00000010H)

SERENUM_PORT_DESC Struct
    _Size                                                   DD          ?   ;Size
    PortHandle                                              PVOID       ?
    PortAddress                                             PHYSICAL_ADDRESS <>
    Reserved                                                DW          1 Dup(?)
SERENUM_PORT_DESC EndS
PSERENUM_PORT_DESC                                          TypeDef     DWord

IOCTL_INTERNAL_SERENUM_REMOVE_SELF                          Equ         CTL_CODE(FILE_DEVICE_SERENUM, 129, METHOD_NEITHER, FILE_ANY_ACCESS)

;SERENUM_PORTION Enumeration
SERENUM_PORTION                                             TypeDef     DWord
SerenumFirstHalf                                            Equ         0
SerenumSecondHalf                                           Equ         1
SerenumWhole                                                Equ         2

SERENUM_PORT_PARAMETERS Struct
    _Size                                                   DD          ?   ;Size
    ReadAccessor                                            PVOID       ?   ;PSERENUM_READPORT
    WriteAccessor                                           PVOID       ?   ;PSERENUM_WRITEPORT
    SerPortAddress                                          PVOID       ?
    HardwareHandle                                          PVOID       ?
    Portion                                                 SERENUM_PORTION ?
    NumberAxis                                              DW          ?
    Reserved                                                DW          3 Dup(?)
SERENUM_PORT_PARAMETERS EndS
PSERENUM_PORT_PARAMETERS                                    TypeDef     DWord

ENDIF ;NTDDSER_INC
