;===================================================================;
;                                                                   ;
;    ntddk.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers    ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF NTDDK_INC
NTDDK_INC Equ 1

NTDDK_INCLUDED                                              Equ         1
DDK_DRIVER                                                  Equ         1

Include macrodrv.inc
Include wtypes.inc
Include ntstatus.inc
Include bugcodes.inc
Include ntiologc.inc

IFNDEF NTDDK
    NO_INTERLOCKED_INTRINSICS                               Equ         1
ENDIF

NTDDK                                                       Equ         1
STRSAFE_USE_SECURE_CRT                                      Equ         0

IFNDEF APP_WIN64
    KADDRESS_BASE                                           Equ         0
    UADDRESS_BASE                                           Equ         0
ENDIF

PsGetCurrentProcess                                         Equ         <IoGetCurrentProcess>

PASSIVE_LEVEL                                               Equ         0
LOW_LEVEL                                                   Equ         0
APC_LEVEL                                                   Equ         1
DISPATCH_LEVEL                                              Equ         2
CMCI_LEVEL                                                  Equ         5

PROFILE_LEVEL                                               Equ         27
CLOCK1_LEVEL                                                Equ         28
CLOCK2_LEVEL                                                Equ         28
IPI_LEVEL                                                   Equ         29
POWER_LEVEL                                                 Equ         30
HIGH_LEVEL                                                  Equ         31

CLOCK_LEVEL                                                 Equ         (CLOCK2_LEVEL)

LOW_PRIORITY                                                Equ         0
LOW_REALTIME_PRIORITY                                       Equ         16
HIGH_PRIORITY                                               Equ         31
MAXIMUM_PRIORITY                                            Equ         32

MAXIMUM_WAIT_OBJECTS                                        Equ         64

MAXIMUM_SUSPEND_COUNT                                       Equ         MAXCHAR

IFDEF JWASM_COMPILER
    Include ddkjwasm.inc
ELSEIFDEF POASM_COMPILER
    Include ddkpoasm.inc
ELSE
    Include ddkmasm.inc
ENDIF

Include undoc.inc

ENDIF ;NTDDK_INC
