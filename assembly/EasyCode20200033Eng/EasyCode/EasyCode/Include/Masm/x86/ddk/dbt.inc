;===================================================================;
;                                                                   ;
;    dbt.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers      ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF DBT_INC
DBT_INC Equ 1

WM_DEVICECHANGE                             Equ     00219H

IFNDEF _WCHAR_T_DEFINED
    _WCHAR_T_DEFINED                        Equ     1
    wchar_t                                 TypeDef Word
ENDIF

IFNDEF GUID_DEFINED
    Include guiddef.inc
ENDIF

DBT_APPYBEGIN                               Equ     00000H
DBT_APPYEND                                 Equ     00001H
DBT_DEVNODES_CHANGED                        Equ     00007H
DBT_QUERYCHANGECONFIG                       Equ     00017H
DBT_CONFIGCHANGED                           Equ     00018H
DBT_CONFIGCHANGECANCELED                    Equ     00019H
DBT_MONITORCHANGE                           Equ     0001BH
DBT_SHELLLOGGEDON                           Equ     00020H
DBT_CONFIGMGAPI32                           Equ     00022H
DBT_VXDINITCOMPLETE                         Equ     00023H
DBT_VOLLOCKQUERYLOCK                        Equ     08041H
DBT_VOLLOCKLOCKTAKEN                        Equ     08042H
DBT_VOLLOCKLOCKFAILED                       Equ     08043H
DBT_VOLLOCKQUERYUNLOCK                      Equ     08044H
DBT_VOLLOCKLOCKRELEASED                     Equ     08045H
DBT_VOLLOCKUNLOCKFAILED                     Equ     08046H
DBT_NO_DISK_SPACE                           Equ     00047H
DBT_LOW_DISK_SPACE                          Equ     00048H
DBT_CONFIGMGPRIVATE                         Equ     07FFFH
DBT_DEVICEARRIVAL                           Equ     08000H
DBT_DEVICEQUERYREMOVE                       Equ     08001H
DBT_DEVICEQUERYREMOVEFAILED                 Equ     08002H
DBT_DEVICEREMOVEPENDING                     Equ     08003H
DBT_DEVICEREMOVECOMPLETE                    Equ     08004H
DBT_DEVICETYPESPECIFIC                      Equ     08005H
DBT_CUSTOMEVENT                             Equ     08006H
DBT_VPOWERDAPI                              Equ     08100H
DBT_USERDEFINED                             Equ     0FFFFH

DBT_DEVTYP_OEM                              Equ     00000000H
DBT_DEVTYP_DEVNODE                          Equ     00000001H
DBT_DEVTYP_VOLUME                           Equ     00000002H
DBT_DEVTYP_PORT                             Equ     00000003H
DBT_DEVTYP_NET                              Equ     00000004H
DBT_DEVTYP_DEVICEINTERFACE                  Equ     00000005H
DBT_DEVTYP_HANDLE                           Equ     00000006H

DBTF_MEDIA                                  Equ     1
DBTF_NET                                    Equ     2

DBTF_RESOURCE                               Equ     1
DBTF_XPORT                                  Equ     2
DBTF_SLOWNET                                Equ     4

BSF_QUERY                                   Equ     00000001H
BSF_IGNORECURRENTTASK                       Equ     00000002H
BSF_FLUSHDISK                               Equ     00000004H
BSF_NOHANG                                  Equ     00000008H
BSF_POSTMESSAGE                             Equ     00000010H
BSF_FORCEIFHUNG                             Equ     00000020H
BSF_NOTIMEOUTIFNOTHUNG                      Equ     00000040H
BSF_MSGSRV32ISOK                            Equ     80000000H
BSF_MSGSRV32ISOK_BIT                        Equ     31

BSM_ALLCOMPONENTS                           Equ     00000000H
BSM_VXDS                                    Equ     00000001H
BSM_NETDRIVER                               Equ     00000002H
BSM_INSTALLABLEDRIVERS                      Equ     00000004H
BSM_APPLICATIONS                            Equ     00000008H

LOCKP_ALLOW_WRITES                          Equ     01H
LOCKP_FAIL_WRITES                           Equ     00H
LOCKP_FAIL_MEM_MAPPING                      Equ     02H
LOCKP_ALLOW_MEM_MAPPING                     Equ     00H
LOCKP_USER_MASK                             Equ     03H
LOCKP_LOCK_FOR_FORMAT                       Equ     04H

LOCKF_LOGICAL_LOCK                          Equ     00H
LOCKF_PHYSICAL_LOCK                         Equ     01H

DEV_BROADCAST_HDR Struct
    dbch_size                               DD      ?
    dbch_devicetype                         DD      ?
    dbch_reserved                           DD      ?
DEV_BROADCAST_HDR EndS

VolLockBroadcast Struct
    vlb_dbh                                 DEV_BROADCAST_HDR   <>
    vlb_owner                               DD      ?
    vlb_perms                               DB      ?
    vlb_lockType                            DB      ?
    vlb_drive                               DB      ?
    vlb_flags                               DB      ?
VolLockBroadcast EndS

DEV_BROADCAST_DEVICEINTERFACE_A Struct
    dbcc_size                               DD      ?
    dbcc_devicetype                         DD      ?
    dbcc_reserved                           DD      ?
    dbcc_classguid                          GUID    <>
    dbcc_name                               DB      ?
DEV_BROADCAST_DEVICEINTERFACE_A EndS
DEV_BROADCAST_DEVICEINTERFACE               Equ     <DEV_BROADCAST_DEVICEINTERFACE_A>

DEV_BROADCAST_DEVNODE Struct
    dbcd_size                               DD      ?
    dbcd_devicetype                         DD      ?
    dbcd_reserved                           DD      ?
    dbcd_devnode                            DD      ?
DEV_BROADCAST_DEVNODE EndS

DEV_BROADCAST_HANDLE Struct
    dbch_size                               DD      ?
    dbch_devicetype                         DD      ?
    dbch_reserved                           DD      ?
    dbch_handle                             DD      ?
    dbch_hdevnotify                         DD      ?
    dbch_eventguid                          GUID    <>
    dbch_nameoffset                         DD      ?
    dbch_data                               DB      ?
DEV_BROADCAST_HANDLE EndS

DEV_BROADCAST_NET Struct
    dbcn_size                               DD      ?
    dbcn_devicetype                         DD      ?
    dbcn_reserved                           DD      ?
    dbcn_resource                           DD      ?
    dbcn_flags                              DD      ?
DEV_BROADCAST_NET EndS

DEV_BROADCAST_OEM Struct
    dbco_size                               DD      ?
    dbco_devicetype                         DD      ?
    dbco_reserved                           DD      ?
    dbco_identifier                         DD      ?
    dbco_suppfunc                           DD      ?
DEV_BROADCAST_OEM EndS

DEV_BROADCAST_PORT_A Struct
    dbcp_size                               DD      ?
    dbcp_devicetype                         DD      ?
    dbcp_reserved                           DD      ?
    dbcp_name                               DB      ?
DEV_BROADCAST_PORT_A EndS
DEV_BROADCAST_PORT                          Equ     <DEV_BROADCAST_PORT_A>

DEV_BROADCAST_USERDEFINED Struct
    dbud_dbh                                DEV_BROADCAST_HDR   <>
    dbud_szName                             DB      ?
DEV_BROADCAST_USERDEFINED EndS

DEV_BROADCAST_VOLUME Struct
    dbcv_size                               DD      ?
    dbcv_devicetype                         DD      ?
    dbcv_reserved                           DD      ?
    dbcv_unitmask                           DD      ?
    dbcv_flags                              DW      ?
DEV_BROADCAST_VOLUME EndS

DEV_BROADCAST_HANDLE32 Struct
    dbch_size                               DD      ?
    dbch_devicetype                         DD      ?
    dbch_reserved                           DD      ?
    dbch_handle                             DD      ?
    dbch_hdevnotify                         DD      ?
    dbch_eventguid                          GUID    <>
    dbch_nameoffset                         DD      ?
    dbch_data                               DB      ?
DEV_BROADCAST_HANDLE32 EndS

DEV_BROADCAST_HANDLE64 Struct
    dbch_size                               DD      ?
    dbch_devicetype                         DD      ?
    dbch_reserved                           DD      ?
    dbch_handle                             DQ      ?
    dbch_hdevnotify                         DQ      ?
    dbch_eventguid                          GUID    <>
    dbch_nameoffset                         DD      ?
    dbch_data                               DB      ?
DEV_BROADCAST_HANDLE64 EndS

ENDIF ;DBT_INC
