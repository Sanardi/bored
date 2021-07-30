;===================================================================;
;                                                                   ;
;  ntddchgr.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF NTDDCHGR_INC
NTDDCHGR_INC Equ 1

Include ntddstor.inc

DD_CHANGER_DEVICE_NAME                                      Equ         A("\Device\Changer")

IOCTL_CHANGER_BASE                                          Equ         FILE_DEVICE_CHANGER

IOCTL_CHANGER_GET_PARAMETERS                                Equ         CTL_CODE(IOCTL_CHANGER_BASE, 0000H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CHANGER_GET_STATUS                                    Equ         CTL_CODE(IOCTL_CHANGER_BASE, 0001H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CHANGER_GET_PRODUCT_DATA                              Equ         CTL_CODE(IOCTL_CHANGER_BASE, 0002H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CHANGER_SET_ACCESS                                    Equ         CTL_CODE(IOCTL_CHANGER_BASE, 0004H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_CHANGER_GET_ELEMENT_STATUS                            Equ         CTL_CODE(IOCTL_CHANGER_BASE, 0005H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS                     Equ         CTL_CODE(IOCTL_CHANGER_BASE, 0006H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CHANGER_SET_POSITION                                  Equ         CTL_CODE(IOCTL_CHANGER_BASE, 0007H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CHANGER_EXCHANGE_MEDIUM                               Equ         CTL_CODE(IOCTL_CHANGER_BASE, 0008H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CHANGER_MOVE_MEDIUM                                   Equ         CTL_CODE(IOCTL_CHANGER_BASE, 0009H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CHANGER_REINITIALIZE_TRANSPORT                        Equ         CTL_CODE(IOCTL_CHANGER_BASE, 000AH, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CHANGER_QUERY_VOLUME_TAGS                             Equ         CTL_CODE(IOCTL_CHANGER_BASE, 000BH, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)

MAX_VOLUME_ID_SIZE                                          Equ         36
MAX_VOLUME_TEMPLATE_SIZE                                    Equ         40

VENDOR_ID_LENGTH                                            Equ         8
PRODUCT_ID_LENGTH                                           Equ         16
REVISION_LENGTH                                             Equ         4
SERIAL_NUMBER_LENGTH                                        Equ         32

;ELEMENT_TYPE Enumeration
ELEMENT_TYPE                                                TypeDef     DWord
AllElements                                                 Equ         0
ChangerTransport                                            Equ         1
ChangerSlot                                                 Equ         2
ChangerIEPort                                               Equ         3
ChangerDrive                                                Equ         4
ChangerDoor                                                 Equ         5
ChangerKeypad                                               Equ         6
ChangerMaxElement                                           Equ         7
PELEMENT_TYPE                                               TypeDef     DWord

CHANGER_ELEMENT Struct
    ElementType                                             ELEMENT_TYPE ?
    ElementAddress                                          DD          ?
CHANGER_ELEMENT EndS
PCHANGER_ELEMENT                                            TypeDef     DWord

CHANGER_ELEMENT_LIST Struct
    Element                                                 CHANGER_ELEMENT <>
    NumberOfElements                                        DD          ?
CHANGER_ELEMENT_LIST EndS
PCHANGER_ELEMENT_LIST                                       TypeDef     DWord

CHANGER_BAR_CODE_SCANNER_INSTALLED                          Equ         00000001H
CHANGER_INIT_ELEM_STAT_WITH_RANGE                           Equ         00000002H
CHANGER_CLOSE_IEPORT                                        Equ         00000004H
CHANGER_OPEN_IEPORT                                         Equ         00000008H

CHANGER_STATUS_NON_VOLATILE                                 Equ         00000010H
CHANGER_EXCHANGE_MEDIA                                      Equ         00000020H
CHANGER_CLEANER_SLOT                                        Equ         00000040H
CHANGER_LOCK_UNLOCK                                         Equ         00000080H

CHANGER_CARTRIDGE_MAGAZINE                                  Equ         00000100H
CHANGER_MEDIUM_FLIP                                         Equ         00000200H
CHANGER_POSITION_TO_ELEMENT                                 Equ         00000400H
CHANGER_REPORT_IEPORT_STATE                                 Equ         00000800H

CHANGER_STORAGE_DRIVE                                       Equ         00001000H
CHANGER_STORAGE_IEPORT                                      Equ         00002000H
CHANGER_STORAGE_SLOT                                        Equ         00004000H
CHANGER_STORAGE_TRANSPORT                                   Equ         00008000H

CHANGER_DRIVE_CLEANING_REQUIRED                             Equ         00010000H

CHANGER_PREDISMOUNT_EJECT_REQUIRED                          Equ         00020000H

CHANGER_CLEANER_ACCESS_NOT_VALID                            Equ         00040000H
CHANGER_PREMOUNT_EJECT_REQUIRED                             Equ         00080000H

CHANGER_VOLUME_IDENTIFICATION                               Equ         00100000H
CHANGER_VOLUME_SEARCH                                       Equ         00200000H
CHANGER_VOLUME_ASSERT                                       Equ         00400000H
CHANGER_VOLUME_REPLACE                                      Equ         00800000H
CHANGER_VOLUME_UNDEFINE                                     Equ         01000000H

CHANGER_SERIAL_NUMBER_VALID                                 Equ         04000000H

CHANGER_DEVICE_REINITIALIZE_CAPABLE                         Equ         08000000H
CHANGER_KEYPAD_ENABLE_DISABLE                               Equ         10000000H
CHANGER_DRIVE_EMPTY_ON_DOOR_ACCESS                          Equ         20000000H

CHANGER_RESERVED_BIT                                        Equ         80000000H

CHANGER_PREDISMOUNT_ALIGN_TO_SLOT                           Equ         80000001H
CHANGER_PREDISMOUNT_ALIGN_TO_DRIVE                          Equ         80000002H
CHANGER_CLEANER_AUTODISMOUNT                                Equ         80000004H
CHANGER_TRUE_EXCHANGE_CAPABLE                               Equ         80000008H
CHANGER_SLOTS_USE_TRAYS                                     Equ         80000010H
CHANGER_RTN_MEDIA_TO_ORIGINAL_ADDR                          Equ         80000020H
CHANGER_CLEANER_OPS_NOT_SUPPORTED                           Equ         80000040H
CHANGER_IEPORT_USER_CONTROL_OPEN                            Equ         80000080H
CHANGER_IEPORT_USER_CONTROL_CLOSE                           Equ         80000100H
CHANGER_MOVE_EXTENDS_IEPORT                                 Equ         80000200H
CHANGER_MOVE_RETRACTS_IEPORT                                Equ         80000400H

CHANGER_TO_TRANSPORT                                        Equ         01H
CHANGER_TO_SLOT                                             Equ         02H
CHANGER_TO_IEPORT                                           Equ         04H
CHANGER_TO_DRIVE                                            Equ         08H

LOCK_UNLOCK_IEPORT                                          Equ         01H
LOCK_UNLOCK_DOOR                                            Equ         02H
LOCK_UNLOCK_KEYPAD                                          Equ         04H

GET_CHANGER_PARAMETERS Struct
    _Size                                                   DD          ?   ;Size
    NumberTransportElements                                 DW          ?
    NumberStorageElements                                   DW          ?
    NumberCleanerSlots                                      DW          ?
    NumberIEElements                                        DW          ?
    NumberDataTransferElements                              DW          ?
    NumberOfDoors                                           DW          ?
    FirstSlotNumber                                         DW          ?
    FirstDriveNumber                                        DW          ?
    FirstTransportNumber                                    DW          ?
    FirstIEPortNumber                                       DW          ?
    FirstCleanerSlotAddress                                 DW          ?
    MagazineSize                                            DW          ?
    DriveCleanTimeout                                       DD          ?
    Features0                                               DD          ?
    Features1                                               DD          ?
    MoveFromTransport                                       DB          ?
    MoveFromSlot                                            DB          ?
    MoveFromIePort                                          DB          ?
    MoveFromDrive                                           DB          ?
    ExchangeFromTransport                                   DB          ?
    ExchangeFromSlot                                        DB          ?
    ExchangeFromIePort                                      DB          ?
    ExchangeFromDrive                                       DB          ?
    LockUnlockCapabilities                                  DB          ?
    PositionCapabilities                                    DB          ?
    Reserved1                                               DB          2 Dup(?)
    Reserved2                                               DD          2 Dup(?)
GET_CHANGER_PARAMETERS EndS
PGET_CHANGER_PARAMETERS                                     TypeDef     DWord

CHANGER_PRODUCT_DATA Struct
    VendorId                                                DB          VENDOR_ID_LENGTH Dup(?)
    ProductId                                               DB          PRODUCT_ID_LENGTH Dup(?)
    Revision                                                DB          REVISION_LENGTH Dup(?)
    SerialNumber                                            DB          SERIAL_NUMBER_LENGTH Dup(?)
    DeviceType                                              DB          ?
CHANGER_PRODUCT_DATA EndS
PCHANGER_PRODUCT_DATA                                       TypeDef     DWord

LOCK_ELEMENT                                                Equ         0
UNLOCK_ELEMENT                                              Equ         1
EXTEND_IEPORT                                               Equ         2
RETRACT_IEPORT                                              Equ         3

CHANGER_SET_ACCESS Struct
    Element                                                 CHANGER_ELEMENT <>
    Control                                                 DD          ?
CHANGER_SET_ACCESS EndS
PCHANGER_SET_ACCESS                                         TypeDef     DWord

CHANGER_READ_ELEMENT_STATUS Struct
    ElementList                                             CHANGER_ELEMENT_LIST    <>
    VolumeTagInfo                                           BOOLEAN     ?
CHANGER_READ_ELEMENT_STATUS EndS
PCHANGER_READ_ELEMENT_STATUS                                TypeDef     DWord

CHANGER_ELEMENT_STATUS Struct
    Element                                                 CHANGER_ELEMENT <>
    SrcElementAddress                                       CHANGER_ELEMENT <>
    Flags                                                   DD          ?
    ExceptionCode                                           DD          ?
    TargetId                                                DB          ?
    Lun                                                     DB          ?
    Reserved                                                DW          ?
    PrimaryVolumeID                                         DB          MAX_VOLUME_ID_SIZE Dup(?)
    AlternateVolumeID                                       DB          MAX_VOLUME_ID_SIZE Dup(?)
CHANGER_ELEMENT_STATUS EndS
PCHANGER_ELEMENT_STATUS                                     TypeDef     DWord

CHANGER_ELEMENT_STATUS_EX Struct
    Element                                                 CHANGER_ELEMENT <>
    SrcElementAddress                                       CHANGER_ELEMENT <>
    Flags                                                   DD          ?
    ExceptionCode                                           DD          ?
    TargetId                                                DB          ?
    Lun                                                     DB          ?
    Reserved                                                DW          ?
    PrimaryVolumeID                                         DB          MAX_VOLUME_ID_SIZE Dup(?)
    AlternateVolumeID                                       DB          MAX_VOLUME_ID_SIZE Dup(?)
    VendorIdentification                                    DB          VENDOR_ID_LENGTH Dup(?)
    ProductIdentification                                   DB          PRODUCT_ID_LENGTH Dup(?)
    SerialNumber                                            DB          SERIAL_NUMBER_LENGTH Dup(?)
CHANGER_ELEMENT_STATUS_EX EndS
PCHANGER_ELEMENT_STATUS_EX                                  TypeDef     DWord

ELEMENT_STATUS_FULL                                         Equ         00000001H
ELEMENT_STATUS_IMPEXP                                       Equ         00000002H
ELEMENT_STATUS_EXCEPT                                       Equ         00000004H
ELEMENT_STATUS_ACCESS                                       Equ         00000008H
ELEMENT_STATUS_EXENAB                                       Equ         00000010H
ELEMENT_STATUS_INENAB                                       Equ         00000020H

ELEMENT_STATUS_PRODUCT_DATA                                 Equ         00000040H

ELEMENT_STATUS_LUN_VALID                                    Equ         00001000H
ELEMENT_STATUS_ID_VALID                                     Equ         00002000H
ELEMENT_STATUS_NOT_BUS                                      Equ         00008000H
ELEMENT_STATUS_INVERT                                       Equ         00400000H
ELEMENT_STATUS_SVALID                                       Equ         00800000H

ELEMENT_STATUS_PVOLTAG                                      Equ         10000000H
ELEMENT_STATUS_AVOLTAG                                      Equ         20000000H

ERROR_LABEL_UNREADABLE                                      Equ         00000001H
ERROR_LABEL_QUESTIONABLE                                    Equ         00000002H
ERROR_SLOT_NOT_PRESENT                                      Equ         00000004H
ERROR_DRIVE_NOT_INSTALLED                                   Equ         00000008H
ERROR_TRAY_MALFUNCTION                                      Equ         00000010H
ERROR_INIT_STATUS_NEEDED                                    Equ         00000011H
ERROR_UNHANDLED_ERROR                                       Equ         0FFFFFFFFH

CHANGER_INITIALIZE_ELEMENT_STATUS Struct
    ElementList                                             CHANGER_ELEMENT_LIST    <>
    BarCodeScan                                             BOOLEAN     ?
CHANGER_INITIALIZE_ELEMENT_STATUS EndS
PCHANGER_INITIALIZE_ELEMENT_STATUS                          TypeDef     DWord

CHANGER_SET_POSITION Struct
    Transport                                               CHANGER_ELEMENT <>
    Destination                                             CHANGER_ELEMENT <>
    Flip                                                    BOOLEAN     ?
CHANGER_SET_POSITION EndS
PCHANGER_SET_POSITION                                       TypeDef     DWord

CHANGER_EXCHANGE_MEDIUM Struct
    Transport                                               CHANGER_ELEMENT <>
    Source                                                  CHANGER_ELEMENT <>
    Destination1                                            CHANGER_ELEMENT <>
    Destination2                                            CHANGER_ELEMENT <>
    Flip1                                                   BOOLEAN     ?
    Flip2                                                   BOOLEAN     ?
CHANGER_EXCHANGE_MEDIUM EndS
PCHANGER_EXCHANGE_MEDIUM                                    TypeDef     DWord

CHANGER_MOVE_MEDIUM Struct
    Transport                                               CHANGER_ELEMENT <>
    Source                                                  CHANGER_ELEMENT <>
    Destination                                             CHANGER_ELEMENT <>
    Flip                                                    BOOLEAN     ?
CHANGER_MOVE_MEDIUM EndS
PCHANGER_MOVE_MEDIUM                                        TypeDef     DWord

CHANGER_SEND_VOLUME_TAG_INFORMATION Struct
    StartingElement                                         CHANGER_ELEMENT <>
    ActionCode                                              DD          ?
    VolumeIDTemplate                                        DB  MAX_VOLUME_TEMPLATE_SIZE Dup(?)
CHANGER_SEND_VOLUME_TAG_INFORMATION EndS
PCHANGER_SEND_VOLUME_TAG_INFORMATION                        TypeDef     DWord

READ_ELEMENT_ADDRESS_INFO Struct
    NumberOfElements                                        DD          ?
    ElementStatus                                           CHANGER_ELEMENT_STATUS  1 Dup(<>)
READ_ELEMENT_ADDRESS_INFO EndS
PREAD_ELEMENT_ADDRESS_INFO                                  TypeDef     DWord

SEARCH_ALL                                                  Equ         0H
SEARCH_PRIMARY                                              Equ         1H
SEARCH_ALTERNATE                                            Equ         2H
SEARCH_ALL_NO_SEQ                                           Equ         4H
SEARCH_PRI_NO_SEQ                                           Equ         5H
SEARCH_ALT_NO_SEQ                                           Equ         6H

ASSERT_PRIMARY                                              Equ         8H
ASSERT_ALTERNATE                                            Equ         9H

REPLACE_PRIMARY                                             Equ         0AH
REPLACE_ALTERNATE                                           Equ         0BH

UNDEFINE_PRIMARY                                            Equ         0CH
UNDEFINE_ALTERNATE                                          Equ         0DH

;CHANGER_DEVICE_PROBLEM_TYPE Enumeration
CHANGER_DEVICE_PROBLEM_TYPE                                 TypeDef     DWord
DeviceProblemNone                                           Equ         0
DeviceProblemHardware                                       Equ         1
DeviceProblemCHMError                                       Equ         2
DeviceProblemDoorOpen                                       Equ         3
DeviceProblemCalibrationError                               Equ         4
DeviceProblemTargetFailure                                  Equ         5
DeviceProblemCHMMoveError                                   Equ         6
DeviceProblemCHMZeroError                                   Equ         7
DeviceProblemCartridgeInsertError                           Equ         8
DeviceProblemPositionError                                  Equ         9
DeviceProblemSensorError                                    Equ         10
DeviceProblemCartridgeEjectError                            Equ         11
DeviceProblemGripperError                                   Equ         12
DeviceProblemDriveError                                     Equ         13
PCHANGER_DEVICE_PROBLEM_TYPE                                TypeDef     DWord

ENDIF ;NTDDCHGR_INC
