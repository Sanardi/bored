;===========================================================;
;                                                           ;
;     ntiologc.h for Easy Code 2.0 GoAsm 32-bit drivers     ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF NTIOLOGC_H
#Define NTIOLOGC_H 1

FACILITY_RPC_STUBS                                          Equ         03H
FACILITY_RPC_RUNTIME                                        Equ         02H
FACILITY_MCA_ERROR_CODE                                     Equ         05H
FACILITY_IO_ERROR_CODE                                      Equ         04H

STATUS_SEVERITY_WARNING                                     Equ         02H
STATUS_SEVERITY_SUCCESS                                     Equ         00H
STATUS_SEVERITY_INFORMATIONAL                               Equ         01H
STATUS_SEVERITY_ERROR                                       Equ         03H

IO_ERR_INSUFFICIENT_RESOURCES                               Equ         (0C0040002H)
IO_ERR_DRIVER_ERROR                                         Equ         (0C0040004H)
IO_ERR_SEEK_ERROR                                           Equ         (0C0040006H)
IO_ERR_BAD_BLOCK                                            Equ         (0C0040007H)
IO_ERR_TIMEOUT                                              Equ         (0C0040009H)
IO_ERR_CONTROLLER_ERROR                                     Equ         (0C004000BH)
IO_ERR_NOT_READY                                            Equ         (0C004000FH)
IO_ERR_INVALID_REQUEST                                      Equ         (0C0040010H)
IO_ERR_RESET                                                Equ         (0C0040013H)
IO_ERR_BAD_FIRMWARE                                         Equ         (0C0040019H)

IO_WRN_BAD_FIRMWARE                                         Equ         (08004001AH)

IO_WRITE_CACHE_ENABLED                                      Equ         (080040020H)

IO_RECOVERED_VIA_ECC                                        Equ         (080040021H)

IO_WRITE_CACHE_DISABLED                                     Equ         (080040022H)

IO_WARNING_PAGING_FAILURE                                   Equ         (080040033H)

IO_WRN_FAILURE_PREDICTED                                    Equ         (080040034H)

IO_WARNING_ALLOCATION_FAILED                                Equ         (080040038H)
IO_WARNING_DUPLICATE_SIGNATURE                              Equ         (08004003AH)
IO_WARNING_DUPLICATE_PATH                                   Equ         (08004003BH)
IO_WARNING_WRITE_FUA_PROBLEM                                Equ         (080040084H)

IO_ERR_RETRY_SUCCEEDED                                      Equ         (000040001H)
IO_ERR_CONFIGURATION_ERROR                                  Equ         (0C0040003H)
IO_ERR_PARITY                                               Equ         (0C0040005H)
IO_ERR_OVERRUN_ERROR                                        Equ         (0C0040008H)
IO_ERR_SEQUENCE                                             Equ         (0C004000AH)
IO_ERR_INTERNAL_ERROR                                       Equ         (0C004000CH)
IO_ERR_INCORRECT_IRQL                                       Equ         (0C004000DH)
IO_ERR_INVALID_IOBASE                                       Equ         (0C004000EH)
IO_ERR_VERSION                                              Equ         (0C0040011H)
IO_ERR_LAYERED_FAILURE                                      Equ         (0C0040012H)
IO_ERR_PROTOCOL                                             Equ         (0C0040014H)
IO_ERR_MEMORY_CONFLICT_DETECTED                             Equ         (0C0040015H)
IO_ERR_PORT_CONFLICT_DETECTED                               Equ         (0C0040016H)
IO_ERR_DMA_CONFLICT_DETECTED                                Equ         (0C0040017H)
IO_ERR_IRQ_CONFLICT_DETECTED                                Equ         (0C0040018H)
IO_ERR_DMA_RESOURCE_CONFLICT                                Equ         (0C004001BH)
IO_ERR_INTERRUPT_RESOURCE_CONFLICT                          Equ         (0C004001CH)
IO_ERR_MEMORY_RESOURCE_CONFLICT                             Equ         (0C004001DH)
IO_ERR_PORT_RESOURCE_CONFLICT                               Equ         (0C004001EH)

IO_BAD_BLOCK_WITH_NAME                                      Equ         (0C004001FH)

IO_FILE_QUOTA_THRESHOLD                                     Equ         (040040024H)
IO_FILE_QUOTA_LIMIT                                         Equ         (040040025H)
IO_FILE_QUOTA_STARTED                                       Equ         (040040026H)
IO_FILE_QUOTA_SUCCEEDED                                     Equ         (040040027H)
IO_FILE_QUOTA_FAILED                                        Equ         (080040028H)
IO_FILE_SYSTEM_CORRUPT                                      Equ         (0C0040029H)
IO_FILE_QUOTA_CORRUPT                                       Equ         (0C004002AH)

IO_SYSTEM_SLEEP_FAILED                                      Equ         (0C004002BH)

IO_DUMP_POINTER_FAILURE                                     Equ         (0C004002CH)
IO_DUMP_DRIVER_LOAD_FAILURE                                 Equ         (0C004002DH)
IO_DUMP_INITIALIZATION_FAILURE                              Equ         (0C004002EH)
IO_DUMP_DUMPFILE_CONFLICT                                   Equ         (0C004002FH)
IO_DUMP_DIRECT_CONFIG_FAILED                                Equ         (0C0040030H)
IO_DUMP_PAGE_CONFIG_FAILED                                  Equ         (0C0040031H)

IO_LOST_DELAYED_WRITE                                       Equ         (080040032H)

IO_WARNING_INTERRUPT_STILL_PENDING                          Equ         (080040035H)

IO_DRIVER_CANCEL_TIMEOUT                                    Equ         (080040036H)

IO_FILE_SYSTEM_CORRUPT_WITH_NAME                            Equ         (0C0040037H)

IO_WARNING_LOG_FLUSH_FAILED                                 Equ         (080040039H)

MCA_WARNING_CACHE                                           Equ         (08005003CH)
MCA_ERROR_CACHE                                             Equ         (0C005003DH)
MCA_WARNING_TLB                                             Equ         (08005003EH)
MCA_ERROR_TLB                                               Equ         (0C005003FH)
MCA_WARNING_CPU_BUS                                         Equ         (080050040H)
MCA_ERROR_CPU_BUS                                           Equ         (0C0050041H)
MCA_WARNING_REGISTER_FILE                                   Equ         (080050042H)
MCA_ERROR_REGISTER_FILE                                     Equ         (0C0050043H)
MCA_WARNING_MAS                                             Equ         (080050044H)
MCA_ERROR_MAS                                               Equ         (0C0050045H)
MCA_WARNING_MEM_UNKNOWN                                     Equ         (080050046H)
MCA_ERROR_MEM_UNKNOWN                                       Equ         (0C0050047H)
MCA_WARNING_MEM_1_2                                         Equ         (080050048H)
MCA_ERROR_MEM_1_2                                           Equ         (0C0050049H)
MCA_WARNING_MEM_1_2_5                                       Equ         (08005004AH)
MCA_ERROR_MEM_1_2_5                                         Equ         (0C005004BH)
MCA_WARNING_MEM_1_2_5_4                                     Equ         (08005004CH)
MCA_ERROR_MEM_1_2_5_4                                       Equ         (0C005004DH)
MCA_WARNING_SYSTEM_EVENT                                    Equ         (08005004EH)
MCA_ERROR_SYSTEM_EVENT                                      Equ         (0C005004FH)
MCA_WARNING_PCI_BUS_PARITY                                  Equ         (080050050H)
MCA_ERROR_PCI_BUS_PARITY                                    Equ         (0C0050051H)
MCA_WARNING_PCI_BUS_PARITY_NO_INFO                          Equ         (080050052H)
MCA_ERROR_PCI_BUS_PARITY_NO_INFO                            Equ         (0C0050053H)
MCA_WARNING_PCI_BUS_SERR                                    Equ         (080050054H)
MCA_ERROR_PCI_BUS_SERR                                      Equ         (0C0050055H)
MCA_WARNING_PCI_BUS_SERR_NO_INFO                            Equ         (080050056H)
MCA_ERROR_PCI_BUS_SERR_NO_INFO                              Equ         (0C0050057H)
MCA_WARNING_PCI_BUS_MASTER_ABORT                            Equ         (080050058H)
MCA_ERROR_PCI_BUS_MASTER_ABORT                              Equ         (0C0050059H)
MCA_WARNING_PCI_BUS_MASTER_ABORT_NO_INFO                    Equ         (08005005AH)
MCA_ERROR_PCI_BUS_MASTER_ABORT_NO_INFO                      Equ         (0C005005BH)
MCA_WARNING_PCI_BUS_TIMEOUT                                 Equ         (08005005CH)
MCA_ERROR_PCI_BUS_TIMEOUT                                   Equ         (0C005005DH)
MCA_WARNING_PCI_BUS_TIMEOUT_NO_INFO                         Equ         (08005005EH)
MCA_ERROR_PCI_BUS_TIMEOUT_NO_INFO                           Equ         (0C005005FH)
MCA_WARNING_PCI_BUS_UNKNOWN                                 Equ         (080050060H)
MCA_ERROR_PCI_BUS_UNKNOWN                                   Equ         (0C0050061H)
MCA_WARNING_PCI_DEVICE                                      Equ         (080050062H)
MCA_ERROR_PCI_DEVICE                                        Equ         (0C0050063H)
MCA_WARNING_SMBIOS                                          Equ         (080050064H)
MCA_ERROR_SMBIOS                                            Equ         (0C0050065H)
MCA_WARNING_PLATFORM_SPECIFIC                               Equ         (080050066H)
MCA_ERROR_PLATFORM_SPECIFIC                                 Equ         (0C0050067H)
MCA_WARNING_UNKNOWN                                         Equ         (080050068H)
MCA_ERROR_UNKNOWN                                           Equ         (0C0050069H)
MCA_WARNING_UNKNOWN_NO_CPU                                  Equ         (08005006AH)
MCA_ERROR_UNKNOWN_NO_CPU                                    Equ         (0C005006BH)

IO_ERR_THREAD_STUCK_IN_DEVICE_DRIVER                        Equ         (0C004006CH)

MCA_WARNING_CMC_THRESHOLD_EXCEEDED                          Equ         (08005006DH)
MCA_WARNING_CPE_THRESHOLD_EXCEEDED                          Equ         (08005006EH)
MCA_WARNING_CPU_THERMAL_THROTTLED                           Equ         (08005006FH)

MCA_INFO_CPU_THERMAL_THROTTLING_REMOVED                     Equ         (040050070H)

MCA_WARNING_CPU                                             Equ         (080050071H)
MCA_ERROR_CPU                                               Equ         (0C0050072H)
MCA_INFO_NO_MORE_CORRECTED_ERROR_LOGS                       Equ         (040050073H)
MCA_INFO_MEMORY_PAGE_MARKED_BAD                             Equ         (040050074H)
IO_ERR_PORT_TIMEOUT                                         Equ         (0C0040075H)
IO_WARNING_BUS_RESET                                        Equ         (080040076H)
IO_INFO_THROTTLE_COMPLETE                                   Equ         (040040077H)

MCA_MEMORYHIERARCHY_ERROR                                   Equ         (0C0050078H)
MCA_TLB_ERROR                                               Equ         (0C0050079H)
MCA_BUS_ERROR                                               Equ         (0C005007AH)
MCA_BUS_TIMEOUT_ERROR                                       Equ         (0C005007BH)
MCA_INTERNALTIMER_ERROR                                     Equ         (0C005007CH)
MCA_MICROCODE_ROM_PARITY_ERROR                              Equ         (0C005007EH)
MCA_EXTERNAL_ERROR                                          Equ         (0C005007FH)

MCA_FRC_ERROR                                               Equ         (0C0050080H)

IO_WARNING_RESET                                            Equ         (080040081H)
IO_FILE_SYSTEM_REPAIR_SUCCESS                               Equ         (080040082H)
IO_FILE_SYSTEM_REPAIR_FAILED                                Equ         (0C0040083H)
IO_CDROM_EXCLUSIVE_LOCK                                     Equ         (040040085H)
IO_FILE_SYSTEM_TXF_RECOVERY_FAILURE                         Equ         (080040086H)
IO_FILE_SYSTEM_TXF_LOG_FULL_HANDLING_FAILED                 Equ         (0C0040087H)
IO_FILE_SYSTEM_TXF_RESOURCE_MANAGER_RESET                   Equ         (080040088H)
IO_FILE_SYSTEM_TXF_RESOURCE_MANAGER_START_FAILED            Equ         (0C0040089H)
IO_FILE_SYSTEM_TXF_RESOURCE_MANAGER_SHUT_DOWN               Equ         (0C004008AH)
IO_LOST_DELAYED_WRITE_NETWORK_DISCONNECTED                  Equ         (08004008BH)
IO_LOST_DELAYED_WRITE_NETWORK_SERVER_ERROR                  Equ         (08004008CH)
IO_LOST_DELAYED_WRITE_NETWORK_LOCAL_DISK_ERROR              Equ         (08004008DH)

#ENDIF ;NTIOLOGC_H
