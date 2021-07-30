; =========================================================;
;                                                          ;
;    wsock32.inc for Easy Code 2.0 64-bit Masm projects    ;
;                    (version 1.0.3)                       ;
;                                                          ;
; Copyright © Ramon Sala / Héctor A. Medina - 2015-2016    ;
;                                                          ;
; =========================================================;

IFNDEF WSOCK32_INC
WSOCK32_INC     EQU     1


IFNDEF FD_SETSIZE
    FD_SETSIZE                                      EQU     64
ENDIF

IOCPARM_MASK                                        EQU     07FH
IOC_VOID                                            EQU     020000000H
IOC_OUT                                             EQU     040000000H
IOC_IN                                              EQU     080000000H
IOC_INOUT                                           EQU     (IOC_IN OR IOC_OUT)

FIONREAD                                            EQU     (IOC_OUT OR (4 AND IOCPARM_MASK) SHL 16 OR 66H SHL 8 OR 127)
FIONBIO                                             EQU     (IOC_IN OR (4 AND IOCPARM_MASK) SHL 16 OR 66H SHL 8 OR 126)
FIOASYNC                                            EQU     (IOC_IN OR (4 AND IOCPARM_MASK) SHL 16 OR 66H SHL 8 OR 125)

SIOCSHIWAT                                          EQU     (IOC_IN OR (4 AND IOCPARM_MASK) SHL 16 OR 73H SHL 8)
SIOCGHIWAT                                          EQU     (IOC_OUT OR (4 AND IOCPARM_MASK) SHL 16 OR 73H SHL 8 OR 1)
SIOCSLOWAT                                          EQU     (IOC_IN OR (4 AND IOCPARM_MASK) SHL 16 OR 73H SHL 8 OR 2)
SIOCGLOWAT                                          EQU     (IOC_OUT OR (4 AND IOCPARM_MASK) SHL 16 OR 73H SHL 8 OR 3)
SIOCATMARK                                          EQU     (IOC_OUT OR (4 AND IOCPARM_MASK) SHL 16 OR 73H SHL 8 OR 7)

IPPROTO_IP                                          EQU     0
IPPROTO_ICMP                                        EQU     1
IPPROTO_IGMP                                        EQU     2
IPPROTO_GGP                                         EQU     3
IPPROTO_TCP                                         EQU     6
IPPROTO_PUP                                         EQU     12
IPPROTO_UDP                                         EQU     17
IPPROTO_IDP                                         EQU     22
IPPROTO_ND                                          EQU     77

IPPROTO_RAW                                         EQU     255
IPPROTO_MAX                                         EQU     256

IPPORT_ECHO                                         EQU     7
IPPORT_DISCARD                                      EQU     9
IPPORT_SYSTAT                                       EQU     11
IPPORT_DAYTIME                                      EQU     13
IPPORT_NETSTAT                                      EQU     15
IPPORT_FTP                                          EQU     21
IPPORT_TELNET                                       EQU     23
IPPORT_SMTP                                         EQU     25
IPPORT_TIMESERVER                                   EQU     37
IPPORT_NAMESERVER                                   EQU     42
IPPORT_WHOIS                                        EQU     43
IPPORT_MTP                                          EQU     57

IPPORT_TFTP                                         EQU     69
IPPORT_RJE                                          EQU     77
IPPORT_FINGER                                       EQU     79
IPPORT_TTYLINK                                      EQU     87
IPPORT_SUPDUP                                       EQU     95

IPPORT_EXECSERVER                                   EQU     512
IPPORT_LOGINSERVER                                  EQU     513
IPPORT_CMDSERVER                                    EQU     514
IPPORT_EFSSERVER                                    EQU     520

IPPORT_BIFFUDP                                      EQU     512
IPPORT_WHOSERVER                                    EQU     513
IPPORT_ROUTESERVER                                  EQU     520

IPPORT_RESERVED                                     EQU     1024

IMPLINK_IP                                          EQU     155
IMPLINK_LOWEXPER                                    EQU     156
IMPLINK_HIGHEXPER                                   EQU     158

IN_CLASSA_NET                                       EQU     0FF000000H
IN_CLASSA_NSHIFT                                    EQU     24
IN_CLASSA_HOST                                      EQU     000FFFFFFH
IN_CLASSA_MAX                                       EQU     128

IN_CLASSB_NET                                       EQU     0FFFF0000H
IN_CLASSB_NSHIFT                                    EQU     16
IN_CLASSB_HOST                                      EQU     00000FFFFH
IN_CLASSB_MAX                                       EQU     65536

IN_CLASSC_NET                                       EQU     0FFFFFF00H
IN_CLASSC_NSHIFT                                    EQU     8
IN_CLASSC_HOST                                      EQU     0000000FFH

INADDR_ANY                                          EQU     000000000H
INADDR_LOOPBACK                                     EQU     07F000001H
INADDR_BROADCAST                                    EQU     0FFFFFFFFH
INADDR_NONE                                         EQU     0FFFFFFFFH

WSADESCRIPTION_LEN                                  EQU     256
WSASYS_STATUS_LEN                                   EQU     128

IP_OPTIONS                                          EQU     1
IP_MULTICAST_IF                                     EQU     2
IP_MULTICAST_TTL                                    EQU     3
IP_MULTICAST_LOOP                                   EQU     4
IP_ADD_MEMBERSHIP                                   EQU     5
IP_DROP_MEMBERSHIP                                  EQU     6
IP_TTL                                              EQU     7
IP_TOS                                              EQU     8
IP_DONTFRAGMENT                                     EQU     9

IP_DEFAULT_MULTICAST_TTL                            EQU     1
IP_DEFAULT_MULTICAST_LOOP                           EQU     1
IP_MAX_MEMBERSHIPS                                  EQU     20

INVALID_SOCKET                                      EQU     (NOT 0)
SOCKET_ERROR                                        EQU     (-1)

SOCK_STREAM                                         EQU     1
SOCK_DGRAM                                          EQU     2
SOCK_RAW                                            EQU     3
SOCK_RDM                                            EQU     4
SOCK_SEQPACKET                                      EQU     5

SO_DEBUG                                            EQU     00001H
SO_ACCEPTCONN                                       EQU     00002H
SO_REUSEADDR                                        EQU     00004H
SO_KEEPALIVE                                        EQU     00008H
SO_DONTROUTE                                        EQU     00010H
SO_BROADCAST                                        EQU     00020H
SO_USELOOPBACK                                      EQU     00040H
SO_LINGER                                           EQU     00080H
SO_OOBINLINE                                        EQU     00100H

SO_DONTLINGER                                       EQU     (NOT SO_LINGER)

SO_SNDBUF                                           EQU     01001H
SO_RCVBUF                                           EQU     01002H
SO_SNDLOWAT                                         EQU     01003H
SO_RCVLOWAT                                         EQU     01004H
SO_SNDTIMEO                                         EQU     01005H
SO_RCVTIMEO                                         EQU     01006H
SO_ERROR                                            EQU     01007H
SO_TYPE                                             EQU     01008H

SO_CONNDATA                                         EQU     07000H
SO_CONNOPT                                          EQU     07001H
SO_DISCDATA                                         EQU     07002H
SO_DISCOPT                                          EQU     07003H
SO_CONNDATALEN                                      EQU     07004H
SO_CONNOPTLEN                                       EQU     07005H
SO_DISCDATALEN                                      EQU     07006H
SO_DISCOPTLEN                                       EQU     07007H

SO_OPENTYPE                                         EQU     07008H

SO_SYNCHRONOUS_ALERT                                EQU     010H
SO_SYNCHRONOUS_NONALERT                             EQU     020H

SO_MAXDG                                            EQU     07009H
SO_MAXPATHDG                                        EQU     0700AH
SO_UPDATE_ACCEPT_CONTEXT                            EQU     0700BH
SO_CONNECT_TIME                                     EQU     0700CH

TCP_NODELAY                                         EQU     00001H
TCP_BSDURGENT                                       EQU     07000H

AF_UNSPEC                                           EQU     0
AF_UNIX                                             EQU     1
AF_INET                                             EQU     2
AF_IMPLINK                                          EQU     3
AF_PUP                                              EQU     4
AF_CHAOS                                            EQU     5
AF_IPX                                              EQU     6
AF_NS                                               EQU     6
AF_ISO                                              EQU     7
AF_OSI                                              EQU     AF_ISO
AF_ECMA                                             EQU     8
AF_DATAKIT                                          EQU     9
AF_CCITT                                            EQU     10
AF_SNA                                              EQU     11
AF_DECnet                                           EQU     12
AF_DLI                                              EQU     13
AF_LAT                                              EQU     14
AF_HYLINK                                           EQU     15
AF_APPLETALK                                        EQU     16
AF_NETBIOS                                          EQU     17
AF_VOICEVIEW                                        EQU     18
AF_FIREFOX                                          EQU     19
AF_UNKNOWN1                                         EQU     20
AF_BAN                                              EQU     21

AF_MAX                                              EQU     22

PF_UNSPEC                                           EQU     AF_UNSPEC
PF_UNIX                                             EQU     AF_UNIX
PF_INET                                             EQU     AF_INET
PF_IMPLINK                                          EQU     AF_IMPLINK
PF_PUP                                              EQU     AF_PUP
PF_CHAOS                                            EQU     AF_CHAOS
PF_NS                                               EQU     AF_NS
PF_IPX                                              EQU     AF_IPX
PF_ISO                                              EQU     AF_ISO
PF_OSI                                              EQU     AF_OSI
PF_ECMA                                             EQU     AF_ECMA
PF_DATAKIT                                          EQU     AF_DATAKIT
PF_CCITT                                            EQU     AF_CCITT
PF_SNA                                              EQU     AF_SNA
PF_DECnet                                           EQU     AF_DECnet
PF_DLI                                              EQU     AF_DLI
PF_LAT                                              EQU     AF_LAT
PF_HYLINK                                           EQU     AF_HYLINK
PF_APPLETALK                                        EQU     AF_APPLETALK
PF_VOICEVIEW                                        EQU     AF_VOICEVIEW
PF_FIREFOX                                          EQU     AF_FIREFOX
PF_UNKNOWN1                                         EQU     AF_UNKNOWN1
PF_BAN                                              EQU     AF_BAN

PF_MAX                                              EQU     AF_MAX

SOL_SOCKET                                          EQU     0FFFFH

SOMAXCONN                                           EQU     5

MSG_OOB                                             EQU     01H
MSG_PEEK                                            EQU     02H
MSG_DONTROUTE                                       EQU     04H

MSG_MAXIOVLEN                                       EQU     16

MSG_PARTIAL                                         EQU     08000H

MAXGETHOSTSTRUCT                                    EQU     1024

FD_READ                                             EQU     001H
FD_WRITE                                            EQU     002H
FD_OOB                                              EQU     004H
FD_ACCEPT                                           EQU     008H
FD_CONNECT                                          EQU     010H
FD_CLOSE                                            EQU     020H

WSABASEERR                                          EQU     10000

WSAEINTR                                            EQU     (WSABASEERR+4)
WSAEBADF                                            EQU     (WSABASEERR+9)
WSAEACCES                                           EQU     (WSABASEERR+13)
WSAEFAULT                                           EQU     (WSABASEERR+14)
WSAEINVAL                                           EQU     (WSABASEERR+22)
WSAEMFILE                                           EQU     (WSABASEERR+24)

WSAEWOULDBLOCK                                      EQU     (WSABASEERR+35)
WSAEINPROGRESS                                      EQU     (WSABASEERR+36)
WSAEALREADY                                         EQU     (WSABASEERR+37)
WSAENOTSOCK                                         EQU     (WSABASEERR+38)
WSAEDESTADDRREQ                                     EQU     (WSABASEERR+39)
WSAEMSGSIZE                                         EQU     (WSABASEERR+40)
WSAEPROTOTYPE                                       EQU     (WSABASEERR+41)
WSAENOPROTOOPT                                      EQU     (WSABASEERR+42)
WSAEPROTONOSUPPORT                                  EQU     (WSABASEERR+43)
WSAESOCKTNOSUPPORT                                  EQU     (WSABASEERR+44)
WSAEOPNOTSUPP                                       EQU     (WSABASEERR+45)
WSAEPFNOSUPPORT                                     EQU     (WSABASEERR+46)
WSAEAFNOSUPPORT                                     EQU     (WSABASEERR+47)
WSAEADDRINUSE                                       EQU     (WSABASEERR+48)
WSAEADDRNOTAVAIL                                    EQU     (WSABASEERR+49)
WSAENETDOWN                                         EQU     (WSABASEERR+50)
WSAENETUNREACH                                      EQU     (WSABASEERR+51)
WSAENETRESET                                        EQU     (WSABASEERR+52)
WSAECONNABORTED                                     EQU     (WSABASEERR+53)
WSAECONNRESET                                       EQU     (WSABASEERR+54)
WSAENOBUFS                                          EQU     (WSABASEERR+55)
WSAEISCONN                                          EQU     (WSABASEERR+56)
WSAENOTCONN                                         EQU     (WSABASEERR+57)
WSAESHUTDOWN                                        EQU     (WSABASEERR+58)
WSAETOOMANYREFS                                     EQU     (WSABASEERR+59)
WSAETIMEDOUT                                        EQU     (WSABASEERR+60)
WSAECONNREFUSED                                     EQU     (WSABASEERR+61)
WSAELOOP                                            EQU     (WSABASEERR+62)
WSAENAMETOOLONG                                     EQU     (WSABASEERR+63)
WSAEHOSTDOWN                                        EQU     (WSABASEERR+64)
WSAEHOSTUNREACH                                     EQU     (WSABASEERR+65)
WSAENOTEMPTY                                        EQU     (WSABASEERR+66)
WSAEPROCLIM                                         EQU     (WSABASEERR+67)
WSAEUSERS                                           EQU     (WSABASEERR+68)
WSAEDQUOT                                           EQU     (WSABASEERR+69)
WSAESTALE                                           EQU     (WSABASEERR+70)
WSAEREMOTE                                          EQU     (WSABASEERR+71)

WSAEDISCON                                          EQU     (WSABASEERR+101)

WSASYSNOTREADY                                      EQU     (WSABASEERR+91)
WSAVERNOTSUPPORTED                                  EQU     (WSABASEERR+92)
WSANOTINITIALISED                                   EQU     (WSABASEERR+93)

WSAHOST_NOT_FOUND                                   EQU     (WSABASEERR+1001)
HOST_NOT_FOUND                                      EQU     WSAHOST_NOT_FOUND

WSATRY_AGAIN                                        EQU     (WSABASEERR+1002)
TRY_AGAIN                                           EQU     WSATRY_AGAIN

WSANO_RECOVERY                                      EQU     (WSABASEERR+1003)
NO_RECOVERY                                         EQU     WSANO_RECOVERY

WSANO_DATA                                          EQU     (WSABASEERR+1004)
NO_DATA                                             EQU     WSANO_DATA

WSANO_ADDRESS                                       EQU     WSANO_DATA
NO_ADDRESS                                          EQU     WSANO_ADDRESS

EWOULDBLOCK                                         EQU     WSAEWOULDBLOCK
EINPROGRESS                                         EQU     WSAEINPROGRESS
EALREADY                                            EQU     WSAEALREADY
ENOTSOCK                                            EQU     WSAENOTSOCK
EDESTADDRREQ                                        EQU     WSAEDESTADDRREQ
EMSGSIZE                                            EQU     WSAEMSGSIZE
EPROTOTYPE                                          EQU     WSAEPROTOTYPE
ENOPROTOOPT                                         EQU     WSAENOPROTOOPT
EPROTONOSUPPORT                                     EQU     WSAEPROTONOSUPPORT
ESOCKTNOSUPPORT                                     EQU     WSAESOCKTNOSUPPORT
EOPNOTSUPP                                          EQU     WSAEOPNOTSUPP
EPFNOSUPPORT                                        EQU     WSAEPFNOSUPPORT
EAFNOSUPPORT                                        EQU     WSAEAFNOSUPPORT
EADDRINUSE                                          EQU     WSAEADDRINUSE
EADDRNOTAVAIL                                       EQU     WSAEADDRNOTAVAIL
ENETDOWN                                            EQU     WSAENETDOWN
ENETUNREACH                                         EQU     WSAENETUNREACH
ENETRESET                                           EQU     WSAENETRESET
ECONNABORTED                                        EQU     WSAECONNABORTED
ECONNRESET                                          EQU     WSAECONNRESET
ENOBUFS                                             EQU     WSAENOBUFS
EISCONN                                             EQU     WSAEISCONN
ENOTCONN                                            EQU     WSAENOTCONN
ESHUTDOWN                                           EQU     WSAESHUTDOWN
ETOOMANYREFS                                        EQU     WSAETOOMANYREFS
ETIMEDOUT                                           EQU     WSAETIMEDOUT
ECONNREFUSED                                        EQU     WSAECONNREFUSED
ELOOP                                               EQU     WSAELOOP
ENAMETOOLONG                                        EQU     WSAENAMETOOLONG
EHOSTDOWN                                           EQU     WSAEHOSTDOWN
EHOSTUNREACH                                        EQU     WSAEHOSTUNREACH
ENOTEMPTY                                           EQU     WSAENOTEMPTY
EPROCLIM                                            EQU     WSAEPROCLIM
EUSERS                                              EQU     WSAEUSERS
EDQUOT                                              EQU     WSAEDQUOT
ESTALE                                              EQU     WSAESTALE
EREMOTE                                             EQU     WSAEREMOTE

TF_DISCONNECT                                       EQU     001H
TF_REUSE_SOCKET                                     EQU     002H
TF_WRITE_BEHIND                                     EQU     004H

;======================================== Structures ======================================;

IFNDEF fd_set
    fd_set STRUCT ALIGNMODE
        fd_count DD ?
        fd_array DD FD_SETSIZE DUP(?)
    fd_set ENDS
ENDIF

IFNDEF timeval
    timeval STRUCT ALIGNMODE
        tv_sec  DD ?
        tv_usec DD ?
    timeval ENDS
ENDIF

IFNDEF WSADATA
    WSADATA STRUCT ALIGNMODE
        wVersion       DW   ?
        wHighVersion   DW   ?
        szDescription  DB   256+1 DUP(?)
        szSystemStatus DB   128+1 DUP(?)
        iMaxSockets    DW   ?
        iMaxUdpDg      DW   ?
        _padding_      DB   2 DUP(?)
        lpVendorInfo   XPTR ?
    WSADATA ENDS
ENDIF

IFNDEF hostent
    hostent STRUCT ALIGNMODE
        h_name         XWORD ?
        h_aliases      XWORD ?
        h_addrtype     DW    ?
        h_length       DW    ?
        IFDEF APP_WIN64
                       DD    ?
        ENDIF
        h_addr_list    XWORD ?
    hostent ENDS
ENDIF

IFNDEF netent
    netent STRUCT ALIGNMODE
        n_name       DD ?
        n_aliases    DD ?
        n_addrtype   DW ?
        n_net        DD ?
    netent ENDS
ENDIF

IFNDEF servent
    servent STRUCT ALIGNMODE
        s_name       DD ?
        s_aliases    DD ?
        s_port       DW ?
        s_proto      DD ?
    servent ENDS
ENDIF

IFNDEF protoent
    protoent STRUCT ALIGNMODE
        p_name       DD ?
        p_aliases    DD ?
        p_proto      DW ?
    protoent ENDS
ENDIF

IFNDEF in_addr
    in_addr STRUCT ALIGNMODE
        Union S_un
            STRUCT S_un_b
                s_b1 DB ?
                s_b2 DB ?
                s_b3 DB ?
                s_b4 DB ?
            ENDS
            STRUCT S_un_w
                s_w1 DW ?
                s_w2 DW ?
            ENDS
            S_addr   DD ?
        ENDS
    in_addr ENDS
ENDIF

IFNDEF sockaddr_in
    sockaddr_in STRUCT ALIGNMODE
        sin_family     DW ?
        sin_port       DW ?
        sin_addr       DD ?
        sin_zero       DB 8 DUP(?)
    sockaddr_in ENDS
ENDIF

IFNDEF sockaddr
    sockaddr STRUCT ALIGNMODE
        sa_family      DW ?
        sa_data        DB 14 DUP(?)
    sockaddr ENDS
ENDIF

IFNDEF ip_mreq
    ip_mreq STRUCT ALIGNMODE
        imr_multiaddr in_addr <>
        imr_interface in_addr <>
    ip_mreq ENDS
ENDIF

IFNDEF sockproto
    sockproto STRUCT ALIGNMODE
        sp_family    DW ?
        sp_protocol  DW ?
    sockproto ENDS
ENDIF

IFNDEF linger
    linger STRUCT ALIGNMODE
        l_onoff      DW ?
        l_linger     DW ?
    linger ENDS
ENDIF

IFNDEF TRANSMIT_FILE_BUFFERS
    TRANSMIT_FILE_BUFFERS STRUCT ALIGNMODE
        Head         DD ?
        HeadLength   DD ?
        Tail         DD ?
        TailLength   DD ?
    TRANSMIT_FILE_BUFFERS ENDS
ENDIF


;======================================== Functions =======================================;
accept PROTO :XWORD,:XPTR,:XPTR
AcceptEx PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
EnumProtocolsA PROTO :XWORD,:XWORD,:XWORD
EnumProtocolsW PROTO :XWORD,:XWORD,:XWORD
GetAcceptExSockaddrs PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetAddressByNameA PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetAddressByNameW PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetNameByTypeA PROTO :XWORD,:XWORD,:XWORD
GetNameByTypeW PROTO :XWORD,:XWORD,:XWORD
GetServiceA PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetServiceW PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetTypeByNameA PROTO :XWORD,:XWORD
GetTypeByNameW PROTO :XWORD,:XWORD
MigrateWinsockConfiguration PROTO :XWORD,:XWORD,:XWORD
NPLoadNameSpaces PROTO :XWORD,:XWORD,:XWORD
SetServiceA PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
SetServiceW PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
TransmitFile PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WEP PROTO
WSAAsyncGetHostByAddr PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WSAAsyncGetHostByName PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WSAAsyncGetProtoByName PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WSAAsyncGetProtoByNumber PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WSAAsyncGetServByName PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WSAAsyncGetServByPort PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
WSAAsyncSelect PROTO :XWORD,:XWORD,:XWORD,:XWORD
WSACancelAsyncRequest PROTO :XWORD
WSACancelBlockingCall PROTO
WSACleanup PROTO
WSAGetLastError PROTO
WSAIsBlocking PROTO
WSApSetPostRoutine PROTO :XPTR
WSARecvEx PROTO :XWORD,:XWORD,:XWORD,:XWORD
WSASetBlockingHook PROTO :XWORD
WSASetLastError PROTO :XWORD
WSAStartup PROTO :XWORD,:XWORD
WSAUnhookBlockingHook PROTO
__WSAFDIsSet PROTO :XWORD,:XWORD
bind PROTO :XWORD,:XWORD,:XWORD
closesocket PROTO :XWORD
connect PROTO :XWORD,:XWORD,:XWORD
dn_expand PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
gethostbyaddr PROTO :XWORD,:XWORD,:XWORD
gethostbyname PROTO :XWORD
gethostname PROTO :XWORD,:XWORD
getnetbyname PROTO :XWORD
getpeername PROTO :XWORD,:XWORD,:XWORD
getprotobyname PROTO :XWORD
getprotobynumber PROTO :XWORD
getservbyname PROTO :XWORD,:XWORD
getservbyport PROTO :XWORD,:XWORD
getsockname PROTO :XWORD,:XWORD,:XWORD
getsockopt PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
htonl PROTO :XWORD
htons PROTO :XWORD
inet_addr PROTO :XWORD
inet_network PROTO :XWORD
inet_ntoa PROTO :XWORD
ioctlsocket PROTO :XWORD,:XWORD,:XWORD
listen PROTO :XWORD,:XWORD
ntohl PROTO :XWORD
ntohs PROTO :XWORD
rcmd PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
recv PROTO :XWORD,:XWORD,:XWORD,:XWORD
recvfrom PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
rexec PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
rresvport PROTO :XWORD
s_perror PROTO :XWORD,:XWORD
select PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
send PROTO :XWORD,:XWORD,:XWORD,:XWORD
sendto PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
sethostname PROTO :XWORD,:XWORD
setsockopt PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
shutdown PROTO :XWORD,:XWORD
socket PROTO :XWORD,:XWORD,:XWORD

IFDEF APP_UNICODE
    EnumProtocols EQU <EnumProtocolsW>
    GetAddressByName EQU <GetAddressByNameW>
    GetNameByType EQU <GetNameByTypeW>
    GetService EQU <GetServiceW>
    GetTypeByName EQU <GetTypeByNameW>
    SetService EQU <SetServiceW>
ELSE
    EnumProtocols EQU <EnumProtocolsA>
    GetAddressByName EQU <GetAddressByNameA>
    GetNameByType EQU <GetNameByTypeA>
    GetService EQU <GetServiceA>
    GetTypeByName EQU <GetTypeByNameA>
    SetService EQU <SetServiceA>
ENDIF

ENDIF ;WSOCK32_INC
