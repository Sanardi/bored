;===========================================================;
;                                                           ;
;    ipfirewall.h for Easy Code 2.0 GoAsm 32-bit drivers    ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF IPFIREWALL_H
#Define IPFIREWALL_H 1

#IFNDEF MACRODRV_H
    #Include macrodrv.h
#ENDIF

INVALID_IF_INDEX                                    Equ         0FFFFFFFFH
LOCAL_IF_INDEX                                      Equ         0

;DIRECTION_E Enumeration
IP_TRANSMIT                                         Equ         0
IP_RECEIVE                                          Equ         1

FIREWALL_CONTEXT_T Struct
    Direction                                       DD
    NTE                                             DD
    LinkCtxt                                        DD
    LContext1                                       DD
    LContext2                                       DD
EndS

IPRcvBuf Struct
    ipr_next                                        DD
    ipr_owner                                       DD
    ipr_buffer                                      DD
    ipr_size                                        DD
    ipr_pMdl                                        DD
    ipr_pClientCnt                                  DD
    ipr_RcvContext                                  DD
    ipr_RcvOffset                                   DD
    ipr_flags                                       DD
EndS

IPR_FLAG_CHECKSUM_OFFLOAD                           Equ         00000002H

;FORWARD_ACTION Enumeration
FORWARD                                             Equ         0
DROP                                                Equ         1
ICMP_ON_DROP                                        Equ         2

;IPROUTEINFOCLASS Enumeration
IPRouteNoInformation                                Equ         0
IPRouteOutgoingFirewallContext                      Equ         1
IPRouteOutgoingFilterContext                        Equ         2
MaxIPRouteInfoClass                                 Equ         3

IP_SET_FIREWALL_HOOK_INFO Struct
    FirewallPtr                                     DD
    Priority                                        DD
    Add                                             DB
EndS

DEST_LOCAL                                          Equ         000H
DEST_BCAST                                          Equ         001H
DEST_SN_BCAST                                       Equ         003H
DEST_MCAST                                          Equ         005H
DEST_REMOTE                                         Equ         008H
DEST_REM_BCAST                                      Equ         00BH
DEST_REM_MCAST                                      Equ         00DH
DEST_INVALID                                        Equ         0FFH

DEST_PROMIS                                         Equ         020H

DEST_BCAST_BIT                                      Equ         001H
DEST_OFFNET_BIT                                     Equ         010H

DEST_MCAST_BIT                                      Equ         005H

#Define                                             DD_IP_DEVICE_NAME L"\Device\Ip"

#Define                                             FSCTL_IP_BASE FILE_DEVICE_NETWORK

#Define                                             IOCTL_IP_SET_FIREWALL_HOOK CTL_CODE(FSCTL_IP_BASE, 12, METHOD_BUFFERED, FILE_WRITE_ACCESS)

#ENDIF ;IPFIREWALL_H
