; ====================================================;
;                                                     ;
;     wsock32.inc for EC v2 Fasm classic projects     ;
;                   (version 1.0.3)                   ;
;                                                     ;
;         Copyright � Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

if ~defined WSOCK32_INC
define WSOCK32_INC 1

if ~defined FD_SETSIZE
    FD_SETSIZE                                      equ     64
end if

IOCPARM_MASK                                        equ     07FH
IOC_VOID                                            equ     020000000H
IOC_OUT                                             equ     040000000H
IOC_IN                                              equ     080000000H
IOC_INOUT                                           equ     (IOC_IN or IOC_OUT)

FIONREAD                                            equ     (IOC_OUT or (4 and IOCPARM_MASK) shl 16 or 66H shl 8 or 127)
FIONBIO                                             equ     (IOC_IN or (4 and IOCPARM_MASK) shl 16 or 66H shl 8 or 126)
FIOASYNC                                            equ     (IOC_IN or (4 and IOCPARM_MASK) shl 16 or 66H shl 8 or 125)

SIOCSHIWAT                                          equ     (IOC_IN or (4 and IOCPARM_MASK) shl 16 or 73H shl 8)
SIOCGHIWAT                                          equ     (IOC_OUT or (4 and IOCPARM_MASK) shl 16 or 73H shl 8 or 1)
SIOCSLOWAT                                          equ     (IOC_IN or (4 and IOCPARM_MASK) shl 16 or 73H shl 8 or 2)
SIOCGLOWAT                                          equ     (IOC_OUT or (4 and IOCPARM_MASK) shl 16 or 73H shl 8 or 3)
SIOCATMARK                                          equ     (IOC_OUT or (4 and IOCPARM_MASK) shl 16 or 73H shl 8 or 7)

IPPROTO_IP                                          equ     0
IPPROTO_ICMP                                        equ     1
IPPROTO_IGMP                                        equ     2
IPPROTO_GGP                                         equ     3
IPPROTO_TCP                                         equ     6
IPPROTO_PUP                                         equ     12
IPPROTO_UDP                                         equ     17
IPPROTO_IDP                                         equ     22
IPPROTO_ND                                          equ     77

IPPROTO_RAW                                         equ     255
IPPROTO_MAX                                         equ     256

IPPORT_ECHO                                         equ     7
IPPORT_DISCARD                                      equ     9
IPPORT_SYSTAT                                       equ     11
IPPORT_DAYTIME                                      equ     13
IPPORT_NETSTAT                                      equ     15
IPPORT_FTP                                          equ     21
IPPORT_TELNET                                       equ     23
IPPORT_SMTP                                         equ     25
IPPORT_TIMESERVER                                   equ     37
IPPORT_NAMESERVER                                   equ     42
IPPORT_WHOIS                                        equ     43
IPPORT_MTP                                          equ     57

IPPORT_TFTP                                         equ     69
IPPORT_RJE                                          equ     77
IPPORT_FINGER                                       equ     79
IPPORT_TTYLINK                                      equ     87
IPPORT_SUPDUP                                       equ     95

IPPORT_EXECSERVER                                   equ     512
IPPORT_LOGINSERVER                                  equ     513
IPPORT_CMDSERVER                                    equ     514
IPPORT_EFSSERVER                                    equ     520

IPPORT_BIFFUDP                                      equ     512
IPPORT_WHOSERVER                                    equ     513
IPPORT_ROUTESERVER                                  equ     520

IPPORT_RESERVED                                     equ     1024

IMPLINK_IP                                          equ     155
IMPLINK_LOWEXPER                                    equ     156
IMPLINK_HIGHEXPER                                   equ     158

IN_CLASSA_NET                                       equ     0FF000000H
IN_CLASSA_NSHIFT                                    equ     24
IN_CLASSA_HOST                                      equ     000FFFFFFH
IN_CLASSA_MAX                                       equ     128

IN_CLASSB_NET                                       equ     0FFFF0000H
IN_CLASSB_NSHIFT                                    equ     16
IN_CLASSB_HOST                                      equ     00000FFFFH
IN_CLASSB_MAX                                       equ     65536

IN_CLASSC_NET                                       equ     0FFFFFF00H
IN_CLASSC_NSHIFT                                    equ     8
IN_CLASSC_HOST                                      equ     0000000FFH

INADDR_ANY                                          equ     000000000H
INADDR_LOOPBACK                                     equ     07F000001H
INADDR_BROADCAST                                    equ     0FFFFFFFFH
INADDR_NONE                                         equ     0FFFFFFFFH

WSADESCRIPTION_LEN                                  equ     256
WSASYS_STATUS_LEN                                   equ     128

IP_OPTIONS                                          equ     1
IP_MULTICAST_IF                                     equ     2
IP_MULTICAST_TTL                                    equ     3
IP_MULTICAST_LOOP                                   equ     4
IP_ADD_MEMBERSHIP                                   equ     5
IP_DROP_MEMBERSHIP                                  equ     6
IP_TTL                                              equ     7
IP_TOS                                              equ     8
IP_DONTFRAGMENT                                     equ     9

IP_DEFAULT_MULTICAST_TTL                            equ     1
IP_DEFAULT_MULTICAST_LOOP                           equ     1
IP_MAX_MEMBERSHIPS                                  equ     20

INVALID_SOCKET                                      equ     (not 0)

SOCK_STREAM                                         equ     1
SOCK_DGRAM                                          equ     2
SOCK_RAW                                            equ     3
SOCK_RDM                                            equ     4
SOCK_SEQPACKET                                      equ     5

SO_DEBUG                                            equ     00001H
SO_ACCEPTCONN                                       equ     00002H
SO_REUSEADDR                                        equ     00004H
SO_KEEPALIVE                                        equ     00008H
SO_DONTROUTE                                        equ     00010H
SO_BROADCAST                                        equ     00020H
SO_USELOOPBACK                                      equ     00040H
SO_LINGER                                           equ     00080H
SO_OOBINLINE                                        equ     00100H

SO_DONTLINGER                                       equ     (not SO_LINGER)

SO_SNDBUF                                           equ     01001H
SO_RCVBUF                                           equ     01002H
SO_SNDLOWAT                                         equ     01003H
SO_RCVLOWAT                                         equ     01004H
SO_SNDTIMEO                                         equ     01005H
SO_RCVTIMEO                                         equ     01006H
SO_ERROR                                            equ     01007H
SO_TYPE                                             equ     01008H

SO_CONNDATA                                         equ     07000H
SO_CONNOPT                                          equ     07001H
SO_DISCDATA                                         equ     07002H
SO_DISCOPT                                          equ     07003H
SO_CONNDATALEN                                      equ     07004H
SO_CONNOPTLEN                                       equ     07005H
SO_DISCDATALEN                                      equ     07006H
SO_DISCOPTLEN                                       equ     07007H

SO_OPENTYPE                                         equ     07008H

SO_SYNCHRONOUS_ALERT                                equ     010H
SO_SYNCHRONOUS_NONALERT                             equ     020H

SO_MAXDG                                            equ     07009H
SO_MAXPATHDG                                        equ     0700AH
SO_UPDATE_ACCEPT_CONTEXT                            equ     0700BH
SO_CONNECT_TIME                                     equ     0700CH

TCP_NODELAY                                         equ     00001H
TCP_BSDURGENT                                       equ     07000H

AF_UNSPEC                                           equ     0
AF_UNIX                                             equ     1
AF_INET                                             equ     2
AF_IMPLINK                                          equ     3
AF_PUP                                              equ     4
AF_CHAOS                                            equ     5
AF_IPX                                              equ     6
AF_NS                                               equ     6
AF_ISO                                              equ     7
AF_OSI                                              equ     AF_ISO
AF_ECMA                                             equ     8
AF_DATAKIT                                          equ     9
AF_CCITT                                            equ     10
AF_SNA                                              equ     11
AF_DECnet                                           equ     12
AF_DLI                                              equ     13
AF_LAT                                              equ     14
AF_HYLINK                                           equ     15
AF_APPLETALK                                        equ     16
AF_NETBIOS                                          equ     17
AF_VOICEVIEW                                        equ     18
AF_FIREFOX                                          equ     19
AF_UNKNOWN1                                         equ     20
AF_BAN                                              equ     21

AF_MAX                                              equ     22

PF_UNSPEC                                           equ     AF_UNSPEC
PF_UNIX                                             equ     AF_UNIX
PF_INET                                             equ     AF_INET
PF_IMPLINK                                          equ     AF_IMPLINK
PF_PUP                                              equ     AF_PUP
PF_CHAOS                                            equ     AF_CHAOS
PF_NS                                               equ     AF_NS
PF_IPX                                              equ     AF_IPX
PF_ISO                                              equ     AF_ISO
PF_OSI                                              equ     AF_OSI
PF_ECMA                                             equ     AF_ECMA
PF_DATAKIT                                          equ     AF_DATAKIT
PF_CCITT                                            equ     AF_CCITT
PF_SNA                                              equ     AF_SNA
PF_DECnet                                           equ     AF_DECnet
PF_DLI                                              equ     AF_DLI
PF_LAT                                              equ     AF_LAT
PF_HYLINK                                           equ     AF_HYLINK
PF_APPLETALK                                        equ     AF_APPLETALK
PF_VOICEVIEW                                        equ     AF_VOICEVIEW
PF_FIREFOX                                          equ     AF_FIREFOX
PF_UNKNOWN1                                         equ     AF_UNKNOWN1
PF_BAN                                              equ     AF_BAN

PF_MAX                                              equ     AF_MAX

SOL_SOCKET                                          equ     0FFFFH

SOMAXCONN                                           equ     5

MSG_OOB                                             equ     01H
MSG_PEEK                                            equ     02H
MSG_DONTROUTE                                       equ     04H

MSG_MAXIOVLEN                                       equ     16

MSG_PARTIAL                                         equ     08000H

MAXGETHOSTSTRUCT                                    equ     1024

WSABASEERR                                          equ     10000

WSAEINTR                                            equ     (WSABASEERR+4)
WSAEBADF                                            equ     (WSABASEERR+9)
WSAEACCES                                           equ     (WSABASEERR+13)
WSAEFAULT                                           equ     (WSABASEERR+14)
WSAEINVAL                                           equ     (WSABASEERR+22)
WSAEMFILE                                           equ     (WSABASEERR+24)

WSAEWOULDBLOCK                                      equ     (WSABASEERR+35)
WSAEINPROGRESS                                      equ     (WSABASEERR+36)
WSAEALREADY                                         equ     (WSABASEERR+37)
WSAENOTSOCK                                         equ     (WSABASEERR+38)
WSAEDESTADDRREQ                                     equ     (WSABASEERR+39)
WSAEMSGSIZE                                         equ     (WSABASEERR+40)
WSAEPROTOTYPE                                       equ     (WSABASEERR+41)
WSAENOPROTOOPT                                      equ     (WSABASEERR+42)
WSAEPROTONOSUPPORT                                  equ     (WSABASEERR+43)
WSAESOCKTNOSUPPORT                                  equ     (WSABASEERR+44)
WSAEOPNOTSUPP                                       equ     (WSABASEERR+45)
WSAEPFNOSUPPORT                                     equ     (WSABASEERR+46)
WSAEAFNOSUPPORT                                     equ     (WSABASEERR+47)
WSAEADDRINUSE                                       equ     (WSABASEERR+48)
WSAEADDRNOTAVAIL                                    equ     (WSABASEERR+49)
WSAENETDOWN                                         equ     (WSABASEERR+50)
WSAENETUNREACH                                      equ     (WSABASEERR+51)
WSAENETRESET                                        equ     (WSABASEERR+52)
WSAECONNABORTED                                     equ     (WSABASEERR+53)
WSAECONNRESET                                       equ     (WSABASEERR+54)
WSAENOBUFS                                          equ     (WSABASEERR+55)
WSAEISCONN                                          equ     (WSABASEERR+56)
WSAENOTCONN                                         equ     (WSABASEERR+57)
WSAESHUTDOWN                                        equ     (WSABASEERR+58)
WSAETOOMANYREFS                                     equ     (WSABASEERR+59)
WSAETIMEDOUT                                        equ     (WSABASEERR+60)
WSAECONNREFUSED                                     equ     (WSABASEERR+61)
WSAELOOP                                            equ     (WSABASEERR+62)
WSAENAMETOOLONG                                     equ     (WSABASEERR+63)
WSAEHOSTDOWN                                        equ     (WSABASEERR+64)
WSAEHOSTUNREACH                                     equ     (WSABASEERR+65)
WSAENOTEMPTY                                        equ     (WSABASEERR+66)
WSAEPROCLIM                                         equ     (WSABASEERR+67)
WSAEUSERS                                           equ     (WSABASEERR+68)
WSAEDQUOT                                           equ     (WSABASEERR+69)
WSAESTALE                                           equ     (WSABASEERR+70)
WSAEREMOTE                                          equ     (WSABASEERR+71)

WSAEDISCON                                          equ     (WSABASEERR+101)

WSASYSNOTREADY                                      equ     (WSABASEERR+91)
WSAVERNOTSUPPORTED                                  equ     (WSABASEERR+92)
WSANOTINITIALISED                                   equ     (WSABASEERR+93)

WSAHOST_NOT_FOUND                                   equ     (WSABASEERR+1001)
HOST_NOT_FOUND                                      equ     WSAHOST_NOT_FOUND

WSATRY_AGAIN                                        equ     (WSABASEERR+1002)
TRY_AGAIN                                           equ     WSATRY_AGAIN

WSANO_RECOVERY                                      equ     (WSABASEERR+1003)
NO_RECOVERY                                         equ     WSANO_RECOVERY

WSANO_DATA                                          equ     (WSABASEERR+1004)
NO_DATA                                             equ     WSANO_DATA

WSANO_ADDRESS                                       equ     WSANO_DATA
NO_ADDRESS                                          equ     WSANO_ADDRESS

EWOULDBLOCK                                         equ     WSAEWOULDBLOCK
EINPROGRESS                                         equ     WSAEINPROGRESS
EALREADY                                            equ     WSAEALREADY
ENOTSOCK                                            equ     WSAENOTSOCK
EDESTADDRREQ                                        equ     WSAEDESTADDRREQ
EMSGSIZE                                            equ     WSAEMSGSIZE
EPROTOTYPE                                          equ     WSAEPROTOTYPE
ENOPROTOOPT                                         equ     WSAENOPROTOOPT
EPROTONOSUPPORT                                     equ     WSAEPROTONOSUPPORT
ESOCKTNOSUPPORT                                     equ     WSAESOCKTNOSUPPORT
EOPNOTSUPP                                          equ     WSAEOPNOTSUPP
EPFNOSUPPORT                                        equ     WSAEPFNOSUPPORT
EAFNOSUPPORT                                        equ     WSAEAFNOSUPPORT
EADDRINUSE                                          equ     WSAEADDRINUSE
EADDRNOTAVAIL                                       equ     WSAEADDRNOTAVAIL
ENETDOWN                                            equ     WSAENETDOWN
ENETUNREACH                                         equ     WSAENETUNREACH
ENETRESET                                           equ     WSAENETRESET
ECONNABORTED                                        equ     WSAECONNABORTED
ECONNRESET                                          equ     WSAECONNRESET
ENOBUFS                                             equ     WSAENOBUFS
EISCONN                                             equ     WSAEISCONN
ENOTCONN                                            equ     WSAENOTCONN
ESHUTDOWN                                           equ     WSAESHUTDOWN
ETOOMANYREFS                                        equ     WSAETOOMANYREFS
ETIMEDOUT                                           equ     WSAETIMEDOUT
ECONNREFUSED                                        equ     WSAECONNREFUSED
ELOOP                                               equ     WSAELOOP
ENAMETOOLONG                                        equ     WSAENAMETOOLONG
EHOSTDOWN                                           equ     WSAEHOSTDOWN
EHOSTUNREACH                                        equ     WSAEHOSTUNREACH
ENOTEMPTY                                           equ     WSAENOTEMPTY
EPROCLIM                                            equ     WSAEPROCLIM
EUSERS                                              equ     WSAEUSERS
EDQUOT                                              equ     WSAEDQUOT
ESTALE                                              equ     WSAESTALE
EREMOTE                                             equ     WSAEREMOTE

TF_DISCONNECT                                       equ     001H
TF_REUSE_SOCKET                                     equ     002H
TF_WRITE_BEHIND                                     equ     004H


IOCPARM_MASK                                        equ     07FH
IOC_VOID                                            equ     020000000H
IOC_OUT                                             equ     040000000H
IOC_IN                                              equ     080000000H
IOC_INOUT                                           equ     (IOC_IN or IOC_OUT)

FIONREAD                                            equ     (IOC_OUT or (4 and IOCPARM_MASK) shl 16 or 66H shl 8 or 127)
FIONBIO                                             equ     (IOC_IN or (4 and IOCPARM_MASK) shl 16 or 66H shl 8 or 126)
FIOASYNC                                            equ     (IOC_IN or (4 and IOCPARM_MASK) shl 16 or 66H shl 8 or 125)

if ~defined SOCKET_ERROR
    SOCKET_ERROR                                    equ     (-1)
end if

if ~defined FD_READ_BIT
    FD_READ_BIT                                     equ     0
    FD_READ                                         equ     (1 shl FD_READ_BIT)
    FD_WRITE_BIT                                    equ     1
    FD_WRITE                                        equ     (1 shl FD_WRITE_BIT)
    FD_OOB_BIT                                      equ     2
    FD_OOB                                          equ     (1 shl FD_OOB_BIT)
    FD_ACCEPT_BIT                                   equ     3
    FD_ACCEPT                                       equ     (1 shl FD_ACCEPT_BIT)
    FD_CONNECT_BIT                                  equ     4
    FD_CONNECT                                      equ     (1 shl FD_CONNECT_BIT)
    FD_CLOSE_BIT                                    equ     5
    FD_CLOSE                                        equ     (1 shl FD_CLOSE_BIT)
    FD_QOS_BIT                                      equ     6
    FD_QOS                                          equ     (1 shl FD_QOS_BIT)
    FD_GROUP_QOS_BIT                                equ     7
    FD_GROUP_QOS                                    equ     (1 shl FD_GROUP_QOS_BIT)
    FD_ROUTING_INTERFACE_CHANGE_BIT                 equ     8
    FD_ROUTING_INTERFACE_CHANGE                     equ     (1 shl FD_ROUTING_INTERFACE_CHANGE_BIT)
    FD_ADDRESS_LIST_CHANGE_BIT                      equ     9
    FD_ADDRESS_LIST_CHANGE                          equ     (1 shl FD_ADDRESS_LIST_CHANGE_BIT)
    FD_MAX_EVENTS                                   equ     10
    FD_ALL_EVENTS                                   equ     ((1 shl FD_MAX_EVENTS) - 1)
end if


if ~defined fd_set_DEF
    fd_set_DEF equ 1
    struct fd_set
        fd_count dd ?
        fd_array dd FD_SETSIZE dup(?)
    ends
end if

if ~defined timeval_DEF
    timeval_DEF equ 1
    struct timeval
        tv_sec  dd ?
        tv_usec dd ?
    ends
end if

if ~defined WSADATA_DEF
    WSADATA_DEF equ 1
    struct WSADATA
        wVersion       dw ?
        wHighVersion   dw ?
        szDescription  db 256+1 dup(?)
        szSystemStatus db 128+1 dup(?)
        iMaxSockets    dw ?
        iMaxUdpDg      dw ?
        _padding_      db 2 dup(?)
        lpVendorInfo   dq ?
    ends
end if

if ~defined hostent_DEF
    hostent_DEF equ 1
    struct hostent
        h_name         xptr ?
        h_aliases      xptr ?
        h_addrtype     dw   ?
        h_length       dw   ?
        if defined APP_WIN64
            _padding   dd   ?
        end if
        h_addr_list    xptr ?
    ends
end if

if ~defined netent_DEF
    netent_DEF equ 1
    struct netent
        n_name       dd ?
        n_aliases    dd ?
        n_addrtype   dw ?
        n_net        dd ?
    ends
end if

if ~defined servent_DEF
    servent_DEF equ 1
    struct servent
        s_name       dd ?
        s_aliases    dd ?
        s_port       dw ?
        s_proto      dd ?
    ends
end if

if ~defined protoent_DEF
    protoent_DEF equ 1
    struct protoent
        p_name       dd ?
        p_aliases    dd ?
        p_proto      dw ?
    ends
end if

if ~defined in_addr_DEF
    in_addr_DEF equ 1
    struct in_addr
        union
            struct
                s_b1 db ?
                s_b2 db ?
                s_b3 db ?
                s_b4 db ?
            ends
            struct
                s_w1 dw ?
                s_w2 dw ?
            ends
            S_addr   dd ?
        ends
    ends
end if

if ~defined sockaddr_in_DEF
    sockaddr_in_DEF equ 1
    struct sockaddr_in
        sin_family     dw ?
        sin_port       dw ?
        sin_addr       dd ?
        sin_zero       db 8 dup(?)
    ends
end if

if ~defined sockaddr_DEF
    sockaddr_DEF equ 1
    struct sockaddr
        sa_family      dw ?
        sa_data        db 14 dup(?)
    ends
end if

if ~defined ip_mreq_DEF
    ip_mreq_DEF equ 1
    struct ip_mreq
        imr_multiaddr in_addr
        imr_interface in_addr
    ends
end if

if ~defined sockproto_DEF
    sockproto_DEF equ 1
    struct sockproto
        sp_family    dw ?
        sp_protocol  dw ?
    ends
end if

if ~defined linger_DEF
    linger_DEF equ 1
    struct linger
        l_onoff      dw ?
        l_linger     dw ?
    ends
end if

if ~defined TRANSMIT_FILE_BUFFERS_DEF
    TRANSMIT_FILE_BUFFERS_DEF equ 1
    struct TRANSMIT_FILE_BUFFERS
        Head         dd ?
        HeadLength   dd ?
        Tail         dd ?
        TailLength   dd ?
    ends
end if


import wsock32,\
    __WSAFDIsSet,'__WSAFDIsSet',\
    accept,'accept',\
    AcceptEx,'AcceptEx',\
    bind,'bind',\
    closesocket,'closesocket',\
    connect,'connect',\
    dn_expand,'dn_expand',\
    EnumProtocolsA,'EnumProtocolsA',\
    EnumProtocolsW,'EnumProtocolsW',\
    GetAcceptExSockaddrs,'GetAcceptExSockaddrs',\
    GetAddressByNameA,'GetAddressByNameA',\
    GetAddressByNameW,'GetAddressByNameW',\
    gethostbyaddr,'gethostbyaddr',\
    gethostbyname,'gethostbyname',\
    gethostname,'gethostname',\
    GetNameByTypeA,'GetNameByTypeA',\
    GetNameByTypeW,'GetNameByTypeW',\
    getnetbyname,'getnetbyname',\
    getpeername,'getpeername',\
    getprotobyname,'getprotobyname',\
    getprotobynumber,'getprotobynumber',\
    getservbyname,'getservbyname',\
    getservbyport,'getservbyport',\
    GetServiceA,'GetServiceA',\
    GetServiceW,'GetServiceW',\
    getsockname,'getsockname',\
    getsockopt,'getsockopt',\
    GetTypeByNameA,'GetTypeByNameA',\
    GetTypeByNameW,'GetTypeByNameW',\
    htonl,'htonl',\
    htons,'htons',\
    inet_addr,'inet_addr',\
    inet_network,'inet_network',\
    inet_ntoa,'inet_ntoa',\
    ioctlsocket,'ioctlsocket',\
    listen,'listen',\
    MigrateWinsockConfiguration,'MigrateWinsockConfiguration',\
    NPLoadNameSpaces,'NPLoadNameSpaces',\
    ntohl,'ntohl',\
    ntohs,'ntohs',\
    rcmd,'rcmd',\
    recv,'recv',\
    recvfrom,'recvfrom',\
    rexec,'rexec',\
    rresvport,'rresvport',\
    s_perror,'s_perror',\
    select,'select',\
    send,'send',\
    sendto,'sendto',\
    sethostname,'sethostname',\
    SetServiceA,'SetServiceA',\
    SetServiceW,'SetServiceW',\
    setsockopt,'setsockopt',\
    shutdown,'shutdown',\
    socket,'socket',\
    TransmitFile,'TransmitFile',\
    WEP,'WEP',\
    WSAAsyncGetHostByAddr,'WSAAsyncGetHostByAddr',\
    WSAAsyncGetHostByName,'WSAAsyncGetHostByName',\
    WSAAsyncGetProtoByName,'WSAAsyncGetProtoByName',\
    WSAAsyncGetProtoByNumber,'WSAAsyncGetProtoByNumber',\
    WSAAsyncGetServByName,'WSAAsyncGetServByName',\
    WSAAsyncGetServByPort,'WSAAsyncGetServByPort',\
    WSAAsyncSelect,'WSAAsyncSelect',\
    WSACancelAsyncRequest,'WSACancelAsyncRequest',\
    WSACancelBlockingCall,'WSACancelBlockingCall',\
    WSACleanup,'WSACleanup',\
    WSAGetLastError,'WSAGetLastError',\
    WSAIsBlocking,'WSAIsBlocking',\
    WSARecvEx,'WSARecvEx',\
    WSASetBlockingHook,'WSASetBlockingHook',\
    WSASetLastError,'WSASetLastError',\
    WSAStartup,'WSAStartup',\
    WSAUnhookBlockingHook,'WSAUnhookBlockingHook'

api EnumProtocols,\
    GetAddressByName,\
    GetNameByType,\
    GetService,\
    GetTypeByName,\
    SetService

end if ;WSOCK32_INC
