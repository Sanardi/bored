;===================================================================;
;                                                                   ;
;   winsvc.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers    ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF WINSVC_INC
WINSVC_INC Equ 1

SERVICES_ACTIVE_DATABASEA                   Equ     A("ServicesActive")
SERVICES_ACTIVE_DATABASEW                   Equ     L("ServicesActive")

SERVICES_FAILED_DATABASEA                   Equ     A("ServicesFailed")
SERVICES_FAILED_DATABASEW                   Equ     L("ServicesFailed")

SC_GROUP_IDENTIFIERA                        Equ     A("+")
SC_GROUP_IDENTIFIERW                        Equ     L("+")

SERVICES_ACTIVE_DATABASE                    Equ     <SERVICES_ACTIVE_DATABASEA>
SERVICES_FAILED_DATABASE                    Equ     <SERVICES_FAILED_DATABASEA>
SC_GROUP_IDENTIFIER                         Equ     <SC_GROUP_IDENTIFIERA>

SERVICE_NO_CHANGE                           Equ     0FFFFFFFFH

SERVICE_ACTIVE                              Equ     000000001H
SERVICE_INACTIVE                            Equ     000000002H
SERVICE_STATE_ALL                           Equ     (SERVICE_ACTIVE Or SERVICE_INACTIVE)

SERVICE_CONTROL_STOP                        Equ     000000001H
SERVICE_CONTROL_PAUSE                       Equ     000000002H
SERVICE_CONTROL_CONTINUE                    Equ     000000003H
SERVICE_CONTROL_INTERROGATE                 Equ     000000004H
SERVICE_CONTROL_SHUTDOWN                    Equ     000000005H
SERVICE_CONTROL_PARAMCHANGE                 Equ     000000006H
SERVICE_CONTROL_NETBINDADD                  Equ     000000007H
SERVICE_CONTROL_NETBINDREMOVE               Equ     000000008H
SERVICE_CONTROL_NETBINDENABLE               Equ     000000009H
SERVICE_CONTROL_NETBINDDISABLE              Equ     00000000AH

SERVICE_STOPPED                             Equ     000000001H
SERVICE_START_PENDING                       Equ     000000002H
SERVICE_STOP_PENDING                        Equ     000000003H
SERVICE_RUNNING                             Equ     000000004H
SERVICE_CONTINUE_PENDING                    Equ     000000005H
SERVICE_PAUSE_PENDING                       Equ     000000006H
SERVICE_PAUSED                              Equ     000000007H

SERVICE_ACCEPT_STOP                         Equ     000000001H
SERVICE_ACCEPT_PAUSE_CONTINUE               Equ     000000002H
SERVICE_ACCEPT_SHUTDOWN                     Equ     000000004H
SERVICE_ACCEPT_PARAMCHANGE                  Equ     000000008H
SERVICE_ACCEPT_NETBINDCHANGE                Equ     000000010H

SC_MANAGER_CONNECT                          Equ     00001H
SC_MANAGER_CREATE_SERVICE                   Equ     00002H
SC_MANAGER_ENUMERATE_SERVICE                Equ     00004H
SC_MANAGER_LOCK                             Equ     00008H
SC_MANAGER_QUERY_LOCK_STATUS                Equ     00010H
SC_MANAGER_MODIFY_BOOT_CONFIG               Equ     00020H

SC_MANAGER_ALL_ACCESS                       Equ     (STANDARD_RIGHTS_REQUIRED Or SC_MANAGER_CONNECT Or SC_MANAGER_CREATE_SERVICE Or SC_MANAGER_ENUMERATE_SERVICE Or SC_MANAGER_LOCK Or SC_MANAGER_QUERY_LOCK_STATUS Or SC_MANAGER_MODIFY_BOOT_CONFIG)

SERVICE_QUERY_CONFIG                        Equ     00001H
SERVICE_CHANGE_CONFIG                       Equ     00002H
SERVICE_QUERY_STATUS                        Equ     00004H
SERVICE_ENUMERATE_DEPENDENTS                Equ     00008H
SERVICE_START                               Equ     00010H
SERVICE_STOP                                Equ     00020H
SERVICE_PAUSE_CONTINUE                      Equ     00040H
SERVICE_INTERROGATE                         Equ     00080H
SERVICE_USER_DEFINED_CONTROL                Equ     00100H

SERVICE_ALL_ACCESS                          Equ     (STANDARD_RIGHTS_REQUIRED Or SERVICE_QUERY_CONFIG Or SERVICE_CHANGE_CONFIG Or SERVICE_QUERY_STATUS Or SERVICE_ENUMERATE_DEPENDENTS Or SERVICE_START Or SERVICE_STOP Or SERVICE_PAUSE_CONTINUE Or SERVICE_INTERROGATE Or SERVICE_USER_DEFINED_CONTROL)

SERVICE_CONFIG_DESCRIPTION                  Equ     1
SERVICE_CONFIG_FAILURE_ACTIONS              Equ     2

;SC_ACTION_TYPE Enumeration
SC_ACTION_TYPE                              TypeDef DWord
SC_ACTION_NONE                              Equ     0
SC_ACTION_RESTART                           Equ     1
SC_ACTION_REBOOT                            Equ     2
SC_ACTION_RUN_COMMAND                       Equ     3

SERVICE_DESCRIPTIONA Struct
    lpDescription                           DD      ?
SERVICE_DESCRIPTIONA EndS
SERVICE_DESCRIPTION                         Equ     <SERVICE_DESCRIPTIONA>
SERVICE_DESCRIPTIONW                        Equ     <SERVICE_DESCRIPTION>

SC_ACTION Struct
    _Type                                   DD      ?
    Delay                                   DD      ?
SC_ACTION EndS

SERVICE_FAILURE_ACTIONSA Struct
    dwResetPeriod                           DD      ?
    lpRebootMsg                             DD      ?
    lpCommand                               DD      ?
    cActions                                DD      ?
    lpsaActions                             DD      ?
SERVICE_FAILURE_ACTIONSA EndS
SERVICE_FAILURE_ACTIONS                     Equ     <SERVICE_FAILURE_ACTIONSA>

SERVICE_STATUS Struct
    dwServiceType                           DD      ?
    dwCurrentState                          DD      ?
    dwControlsAccepted                      DD      ?
    dwWin32ExitCode                         DD      ?
    dwServiceSpecificExitCode               DD      ?
    dwCheckPoint                            DD      ?
    dwWaitHint                              DD      ?
SERVICE_STATUS EndS

ENUM_SERVICE_STATUSA Struct
    lpServiceName                           DD      ?
    lpDisplayName                           DD      ?
    ServiceStatus                           SERVICE_STATUS  <>
ENUM_SERVICE_STATUSA EndS
ENUM_SERVICE_STATUS                         Equ     <ENUM_SERVICE_STATUSA>

QUERY_SERVICE_LOCK_STATUSA Struct
    fIsLocked                               DD      ?
    lpLockOwner                             DD      ?
    dwLockDuration                          DD      ?
QUERY_SERVICE_LOCK_STATUSA EndS
QUERY_SERVICE_LOCK_STATUS                   Equ     <QUERY_SERVICE_LOCK_STATUSA>

QUERY_SERVICE_CONFIGA Struct
    dwServiceType                           DD      ?
    dwStartType                             DD      ?
    dwErrorControl                          DD      ?
    lpBinaryPathName                        DD      ?
    lpLoadOrderGroup                        DD      ?
    dwTagId                                 DD      ?
    lpDependencies                          DD      ?
    lpServiceStartName                      DD      ?
    lpDisplayName                           DD      ?
QUERY_SERVICE_CONFIGA EndS
QUERY_SERVICE_CONFIG                        Equ     <QUERY_SERVICE_CONFIGA>

SERVICE_TABLE_ENTRYA Struct
    lpServiceName                           DD      ?
    lpServiceProc                           DD      ?
SERVICE_TABLE_ENTRYA EndS
SERVICE_TABLE_ENTRY                         Equ     <SERVICE_TABLE_ENTRYA>

ENDIF ;WINSVC_INC
