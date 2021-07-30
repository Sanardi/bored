; ====================================================;
;                                                     ;
;    iphlpapi.inc for EC v2 Fasm classic projects     ;
;                   (version 1.0.2)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

if ~defined IPHLPAPI_INC
define IPHLPAPI_INC 1

if  ~defined ANY_SIZE
    ANY_SIZE                                    equ     1
end if

if  ~defined MAXLEN_PHYSADDR
    MAXLEN_PHYSADDR                             equ     8
end if

if  ~defined MAXLEN_IFDESCR
    MAXLEN_IFDESCR                              equ     256
end if

if  ~defined MAX_ADAPTER_NAME
    MAX_ADAPTER_NAME                            equ     128
end if

if  ~defined MAX_INTERFACE_NAME_LEN
    MAX_INTERFACE_NAME_LEN                      equ     256
end if

if  ~defined IF_MAX_PHYS_ADDRESS_LENGTH
    IF_MAX_PHYS_ADDRESS_LENGTH                  equ     32
end if

if  ~defined MAX_MODULE_NAME32
    MAX_MODULE_NAME32                           equ     255
end if

if  ~defined MAX_HOSTNAME_LEN
    MAX_HOSTNAME_LEN                            equ     128
end if

if  ~defined MAX_DOMAIN_NAME_LEN
    MAX_DOMAIN_NAME_LEN                         equ     128
end if

if  ~defined MAX_SCOPE_ID_LEN
    MAX_SCOPE_ID_LEN                            equ     256
end if

if  ~defined TCPIP_OWNING_MODULE_SIZE
    TCPIP_OWNING_MODULE_SIZE                    equ     16
end if

if  ~defined DNS_MAX_NAME_BUFFER_LENGTH
    DNS_MAX_NAME_BUFFER_LENGTH                  equ     256
end if

if  ~defined IF_MAX_STRING_SIZE
    IF_MAX_STRING_SIZE                          equ     256
end if

if  ~defined AF_INET
    AF_INET                                     equ     2
end if

if  ~defined ADDRESS_FAMILY
    TYPEDEF                                     ADDRESS_FAMILY, dw
end if

if  ~defined IPAddr
    TYPEDEF                                     IPAddr, dd
end if

if  ~defined IPMask
    TYPEDEF                                     IPMask, dd
end if

if  ~defined IP_STATUS
    TYPEDEF                                     IP_STATUS, dd
end if

if  ~defined NET_IF_COMPARTMENT_ID
    TYPEDEF                                     NET_IF_COMPARTMENT_ID, dd
end if

TH32CS_SNAPHEAPLIST                             equ     00000001H
TH32CS_SNAPPROCESS                              equ     00000002H
TH32CS_SNAPTHREAD                               equ     00000004H
TH32CS_SNAPMODULE                               equ     00000008H
TH32CS_SNAPMODULE32                             equ     00000010H
TH32CS_SNAPALL                                  equ     (TH32CS_SNAPHEAPLIST or TH32CS_SNAPPROCESS or TH32CS_SNAPTHREAD or TH32CS_SNAPMODULE)
TH32CS_INHERIT                                  equ     80000000H

HF32_DEFAULT                                    equ     1
HF32_SHARED                                     equ     2

LF32_FIXED                                      equ     00000001H
LF32_FREE                                       equ     00000002H
LF32_MOVEABLE                                   equ     00000004H

if  ~defined ScopeLevelInterface
    ScopeLevelInterface                         equ     1
    ScopeLevelLink                              equ     2
    ScopeLevelSubnet                            equ     3
    ScopeLevelAdmin                             equ     4
    ScopeLevelSite                              equ     5
    ScopeLevelOrganization                      equ     8
    ScopeLevelGlobal                            equ     14
    ScopeLevelCount                             equ     16 
end if

TCP_TABLE_BASIC_LISTENER                        equ     0
TCP_TABLE_BASIC_CONNECTIONS                     equ     1
TCP_TABLE_BASIC_ALL                             equ     2
TCP_TABLE_OWNER_PID_LISTENER                    equ     3
TCP_TABLE_OWNER_PID_CONNECTIONS                 equ     4
TCP_TABLE_OWNER_PID_ALL                         equ     5
TCP_TABLE_OWNER_MODULE_LISTENER                 equ     6
TCP_TABLE_OWNER_MODULE_CONNECTIONS              equ     7
TCP_TABLE_OWNER_MODULE_ALL                      equ     8

UDP_TABLE_BASIC                                 equ     0
UDP_TABLE_OWNER_PID                             equ     1
UDP_TABLE_OWNER_MODULE                          equ     2


;======================================== Structures ======================================;
if ~defined LARGE_INTEGER_DEF
    LARGE_INTEGER_DEF equ 1
    struct LARGE_INTEGER
        union
            LowPart  dd ?
            HighPart dd ?
            QuadPart dq ?
        ends                  
    ends
end if

struct HEAPLIST32
    dwSize        xptr      ?
    th32ProcessID dd        ?
    th32HeapID    xptr      ?
    dwFlags       dd        ?
ends

struct HEAPENTRY32
    dwSize        xptr      ?
    hHandle       xptr      ?
    dwAddress     xptr      ?
    dwBlockSize   xptr      ?
    dwFlags       dd        ?
    dwLockCount   dd        ?
    dwResvd       dd        ?
    th32ProcessID dd        ?
    th32HeapID    xptr      ?
ends

struct PROCESSENTRY32A
    dwSize              dd        ?
    cntUsage            dd        ?
    th32ProcessID       dd        ?
    th32DefaultHeapID   xptr      ?
    th32ModuleID        dd        ?
    cntThreads          dd        ?
    th32ParentProcessID dd        ?
    pcPriClassBase      dd        ?
    dwFlags             dd        ?
    szExeFile           db MAX_PATH dup(?)
ends

struct PROCESSENTRY32W
    dwSize              dd        ?
    cntUsage            dd        ?
    th32ProcessID       dd        ?
    th32DefaultHeapID   xptr      ?
    th32ModuleID        dd        ?
    cntThreads          dd        ?
    th32ParentProcessID dd        ?
    pcPriClassBase      dd        ?
    dwFlags             dd        ?
    szExeFile           dw MAX_PATH dup(?)
ends

struct THREADENTRY32
    dwSize             dd ?
    cntUsage           dd ?
    th32ThreadID       dd ?
    th32OwnerProcessID dd ?
    tpBasePri          dd ?
    tpDeltaPri         dd ?
    dwFlags            dd ?
ends

struct MODULEENTRY32A
    dwSize          dd     ?
    th32ModuleID    dd     ?
    th32ProcessID   dd     ?
    GlblcntUsage    dd     ?
    ProccntUsage    dd     ?
    modBaseAddr     xptr   ?
    modBaseSize     dd     ?
    hModule         xptr   ?
    szModule        db (MAX_MODULE_NAME32 + 1) dup(?)
    szExePath       db MAX_PATH dup(?)
ends

struct MODULEENTRY32W
    dwSize          dd     ?
    th32ModuleID    dd     ?
    th32ProcessID   dd     ?
    GlblcntUsage    dd     ?
    ProccntUsage    dd     ?
    modBaseAddr     xptr   ?
    modBaseSize     dd     ?
    hModule         xptr   ?
    szModule        dw (MAX_MODULE_NAME32 + 1) dup(?)
    szExePath       dw MAX_PATH dup(?)
ends

if ~defined IN_ADDR_DEF
    IN_ADDR_DEF equ 1
    struct IN_ADDR
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
            S_addr dd ?
        ends
    ends
end if

if ~defined IN6_ADDR_DEF
    IN6_ADDR_DEF equ 1
    struct IN6_ADDR
        union
            Byte db 16 dup(?)
            Word dw 8 dup(?)
        ends
    ends
end if

if ~defined SOCKADDR_IN_DEF
    SOCKADDR_IN_DEF equ 1
    struct SOCKADDR_IN
        sin_family dw      ?
        sin_port   dw      ?
        sin_addr   IN_ADDR
        sin_zero   db 8 dup(?)
    ends
end if

if ~defined SCOPE_ID_DEF
    SCOPE_ID_DEF equ 1
    struct RECASCOPE_ID
        QQ  dd ?
    ends

    struct SCOPE_ID
        union
            struct
                RECASCOPE_ID
            ends
            Value           dd ?
        ends
    ends
end if

if ~defined SOCKADDR_IN6_DEF
    SOCKADDR_IN6_DEF equ 1
    struct SOCKADDR_IN6
        sin6_family           dd    ?
        sin6_port             dd    ?
        sin6_flowinfo         dd    ?
        sin6_addr             IN6_ADDR
        union
            sin6_scope_id     dd    ?
            sin6_scope_struct SCOPE_ID 
        ends
    ends
end if

if ~defined NET_LUID_DEF
    NET_LUID_DEF equ 1
    struct RECANET_LUID
        AQ  dq ?
    ends

    struct NET_LUID
        union
            Value   dq  ?
            struct
                RECANET_LUID
            ends
        ends
    ends
end if
if ~defined NET_LUID_LH_DEF
    NET_LUID_LH_DEF equ 1
    define NET_LUID_LH NET_LUID
end if

if ~defined SOCKADDR_INET_DEF
    SOCKADDR_INET_DEF equ 1
    struct SOCKADDR_INET
        union
            Ipv4      SOCKADDR_IN        ;ATECI”””!!! 
            Ipv6      SOCKADDR_IN6       ;ATECI”””!!!
            si_family dw           ?
        ends
    ends
end if

if ~defined MIB_IPNETROW_DEF
    MIB_IPNETROW_DEF equ 1
    struct MIB_IPNETROW
        dwIndex         dd ?
        dwPhysAddrLen   dd ?
        bPhysAddr       db MAXLEN_PHYSADDR dup(?)
        dwAddr          dd ?
        dwType          dd ?
    ends
end if

if ~defined MIB_IPNET_ROW2_DEF
    MIB_IPNET_ROW2_DEF equ 1
    struct RECAMIB_IPNET_ROW2
        _Is  dd ?
    ends

    struct MIB_IPNET_ROW2
        Address               SOCKADDR_INET
        InterfaceIndex        dd    ?
        InterfaceLuid         NET_LUID
        PhysicalAddress       db IF_MAX_PHYS_ADDRESS_LENGTH dup(?)
        PhysicalAddressLength dd    ?
        State                 dd    ?
        union
            struct
                RECAMIB_IPNET_ROW2
            ends
            Flags             db    ?
        ends
        union
            LastReachable     dd    ?
            LastUnreachable   dd    ?
        ends
    ends
end if

if ~defined MIBICMPSTATS_DEF
    MIBICMPSTATS_DEF equ 1
    struct MIBICMPSTATS
        dwMsgs          dd  ?
        dwErrors        dd  ?
        dwDestUnreachs  dd  ?
        dwTimeExcds     dd  ?
        dwParmProbs     dd  ?
        dwSrcQuenchs    dd  ?
        dwRedirects     dd  ?
        dwEchos         dd  ?
        dwEchoReps      dd  ?
        dwTimestamps    dd  ?
        dwTimestampReps dd  ?
        dwAddrMasks     dd  ?
        dwAddrMaskReps  dd  ?
    ends
end if

if ~defined MIBICMPSTATS_EX_DEF
    MIBICMPSTATS_EX_DEF equ 1
    struct MIBICMPSTATS_EX
        dwMsgs        dd    ?
        dwErrors      dd    ?
        rgdwTypeCount db 256 dup(?)
    ends
end if

if ~defined MIBICMPINFO_DEF
    MIBICMPINFO_DEF equ 1
    struct MIBICMPINFO
        icmpInStats  MIBICMPSTATS
        icmpOutStats MIBICMPSTATS
    ends
end if

if ~defined MIB_ICMP_DEF
    MIB_ICMP_DEF equ 1
    struct MIB_ICMP
        stats MIBICMPINFO
    ends
end if

if ~defined MIB_ICMP_EX_DEF
    MIB_ICMP_EX_DEF equ 1
    struct MIB_ICMP_EX
        icmpInStats  MIBICMPSTATS_EX
        icmpOutStats MIBICMPSTATS_EX
    ends
end if

if ~defined MIB_IFROW_DEF
    MIB_IFROW_DEF equ 1
    struct MIB_IFROW
        wszName           dw MAX_INTERFACE_NAME_LEN dup(?)
        dwIndex           dd    ?
        dwType            dd    ?
        dwMtu             dd    ?
        dwSpeed           dd    ?
        dwPhysAddrLen     dd    ?
        bPhysAddr         db MAXLEN_PHYSADDR dup(?)
        dwAdminStatus     dd    ?
        dwOperStatus      dd    ?
        dwLastChange      dd    ?
        dwInOctets        dd    ?
        dwInUcastPkts     dd    ?
        dwInNUcastPkts    dd    ?
        dwInDiscards      dd    ?
        dwInErrors        dd    ?
        dwInUnknownProtos dd    ?
        dwOutOctets       dd    ?
        dwOutUcastPkts    dd    ?
        dwOutNUcastPkts   dd    ?
        dwOutDiscards     dd    ?
        dwOutErrors       dd    ?
        dwOutQLen         dd    ?
        dwDescrLen        dd    ?
        bDescr            db MAXLEN_IFDESCR dup(?)
    ends
end if

if ~defined MIB_IF_ROW2_DEF
    MIB_IF_ROW2_DEF equ 1
    struct RECAMIB_IF_ROW2
        _AS dd ?
    ends

    struct MIB_IF_ROW2
        InterfaceLuid            NET_LUID
        InterfaceIndex           dd     ?
        InterfaceGuid            GUID
        Alias                    dw     (IF_MAX_STRING_SIZE + 1) dup(?)
        Description              dw     (IF_MAX_STRING_SIZE + 1) dup(?)
        PhysicalAddressLength    dd     ?
        PhysicalAddress          db     IF_MAX_PHYS_ADDRESS_LENGTH dup(?)
        PermanentPhysicalAddress db     IF_MAX_PHYS_ADDRESS_LENGTH dup(?)
        Mtu                      dd     ?
        Type                     dd     ?
        TunnelType               dd     ?
        MediaType                dd     ?
        PhysicalMediumType       dd     ?
        AccessType               dd     ?
        DirectionType            dd     ?
        struct
            RECAMIB_IF_ROW2
        ends
        OperStatus               dd     ?
        AdminStatus              dd     ?
        MediaConnectState        dd     ?
        NetworkGuid              GUID 
        ConnectionType           dd     ?
        TransmitLinkSpeed        dq     ?
        ReceiveLinkSpeed         dq     ?
        InOctets                 dq     ?
        InUcastPkts              dq     ?
        InNUcastPkts             dq     ?
        InDiscards               dq     ?
        InErrors                 dq     ?
        InUnknownProtos          dq     ?
        InUcastOctets            dq     ?
        InMulticastOctets        dq     ?
        InBroadcastOctets        dq     ?
        OutOctets                dq     ?
        OutUcastPkts             dq     ?
        OutNUcastPkts            dq     ?
        OutDiscards              dq     ?
        OutErrors                dq     ?
        OutUcastOctets           dq     ?
        OutMulticastOctets       dq     ?
        OutBroadcastOctets       dq     ?
        OutQLen                  dq     ?
    ends
end if

if ~defined MIB_IFSTACK_ROW_DEF
    MIB_IFSTACK_ROW_DEF equ 1
    struct MIB_IFSTACK_ROW
        HigherLayerInterfaceIndex dd ?
        LowerLayerInterfaceIndex  dd ?
    ends
end if

if ~defined MIB_IFSTACK_TABLE_DEF
    MIB_IFSTACK_TABLE_DEF equ 1
    struct MIB_IFSTACK_TABLE
        NumEntries  dd  ?
        Table       MIB_IFSTACK_ROW ANY_SIZE
    ends
end if

if ~defined MIB_IFTABLE_DEF
    MIB_IFTABLE_DEF equ 1
    struct MIB_IFTABLE
        dwNumEntries dd ?
        table        MIB_IFROW ANY_SIZE
    ends
end if

if ~defined MIB_IF_TABLE2_DEF
    MIB_IF_TABLE2_DEF equ 1
    struct MIB_IF_TABLE2
        NumEntries  dd  ?
        Table       MIB_IF_ROW2 ANY_SIZE
    ends
end if

struct IP_ADAPTER_INDEX_MAP
    Index dd ?
    Name1 dw MAX_ADAPTER_NAME dup(?)
ends

if ~defined IP_INTERFACE_INFO_DEF
    IP_INTERFACE_INFO_DEF equ 1
    struct IP_INTERFACE_INFO
        NumAdapters dd  ?
        Adapter     IP_ADAPTER_INDEX_MAP 1
    ends
end if

if ~defined MIB_INVERTEDIFSTACK_ROW_DEF
    MIB_INVERTEDIFSTACK_ROW_DEF equ 1
    struct MIB_INVERTEDIFSTACK_ROW
        LowerLayerInterfaceIndex  dd ?
        HigherLayerInterfaceIndex dd ?
    ends
end if

if ~defined MIB_INVERTEDIFSTACK_TABLE_DEF
    MIB_INVERTEDIFSTACK_TABLE_DEF equ 1
    struct MIB_INVERTEDIFSTACK_TABLE
        NumEntries dd   ?
        Table      MIB_INVERTEDIFSTACK_ROW ANY_SIZE
    ends
end if

if ~defined MIB_IPADDRROW_DEF
    MIB_IPADDRROW_DEF equ 1
    struct MIB_IPADDRROW
        dwAddr      dd  ?
        dwIndex     dd  ?
        dwMask      dd  ?
        dwBCastAddr dd  ?
        dwReasmSize dd  ?
        unused1     dw  ?
        wType       dw  ?
    ends
end if
if ~defined MIB_IPADDRROW_XP_DEF
    MIB_IPADDRROW_XP_DEF equ 1
    define MIB_IPADDRROW_XP MIB_IPADDRROW
end if

if ~defined IP_ADDRESS_PREFIX_DEF
    IP_ADDRESS_PREFIX_DEF equ 1
    struct IP_ADDRESS_PREFIX
        Prefix       SOCKADDR_INET
        PrefixLength db ?
    ends
end if

if ~defined MIB_IPFORWARD_ROW2_DEF
    MIB_IPFORWARD_ROW2_DEF equ 1
    struct MIB_IPFORWARD_ROW2
        InterfaceLuid        NET_LUID
        InterfaceIndex       dd ?
        DestinationPrefix    IP_ADDRESS_PREFIX
        NextHop              SOCKADDR_INET
        SitePrefixLength     db ?
        ValidLifetime        dd ?
        PreferredLifetime    dd ?
        Metric               dd ?
        Protocol             dd ?
        Loopback             db ?
        AutoconfigureAddress db ?
        Publish              db ?
        Immortal             db ?
        Age                  dd ?
        Origin               dd ?
    ends
end if

if ~defined MIB_IPFORWARDROW_DEF
    MIB_IPFORWARDROW_DEF equ 1
    struct MIB_IPFORWARDROW
        dwForwardDest     dd    ?
        dwForwardMask     dd    ?
        dwForwardPolicy   dd    ?
        dwForwardNextHop  dd    ?
        dwForwardIfIndex  dd    ?
        union
            dwForwardType dd    ?
            ForwardType   dd    ?
        ends
        union
            dwForwardProto dd   ?
            ForwardProto   dd   ?
        ends
        dwForwardAge       dd   ?
        dwForwardNextHopAS dd   ?
        dwForwardMetric1   dd   ?
        dwForwardMetric2   dd   ?
        dwForwardMetric3   dd   ?
        dwForwardMetric4   dd   ?
        dwForwardMetric5   dd   ?
    ends
end if

if ~defined MIB_IPFORWARDTABLE_DEF
    MIB_IPFORWARDTABLE_DEF equ 1
    struct MIB_IPFORWARDTABLE
        dwNumEntries dd ?
        table        MIB_IPFORWARDROW ANY_SIZE
    ends
end if

if ~defined NL_INTERFACE_OFFLOAD_ROD_DEF
    NL_INTERFACE_OFFLOAD_ROD_DEF equ 1
    struct RECANL_INTERFACE_OFFLOAD_ROD
        BNT dd ?
    ends

    struct NL_INTERFACE_OFFLOAD_ROD
        RECANL_INTERFACE_OFFLOAD_ROD
    ends
end if

if ~defined MIB_IPINTERFACE_ROW_DEF
    MIB_IPINTERFACE_ROW_DEF equ 1
    struct MIB_IPINTERFACE_ROW
        Family                               dw ?
        InterfaceLuid                        NET_LUID 
        InterfaceIndex                       dd ?
        MaxReassemblySize                    dd ?
        InterfaceIdentifier                  dq ?
        MinRouterAdvertisementInterval       dd ?
        MaxRouterAdvertisementInterval       dd ?
        AdvertisingEnabled                   db ?
        ForwardingEnabled                    db ?
        WeakHostSend                         db ?
        WeakHostReceive                      db ?
        UseAutomaticMetric                   db ?
        UseNeighborUnreachabilityDetection   db ?
        ManagedAddressConfigurationSupported db ?
        OtherStatefulConfigurationSupported  db ?
        AdvertiseDefaultRoute                db ?
        RouterDiscoveryBehavior              dd ?
        DadTransmits                         dd ?
        BaseReachableTime                    dd ?
        RetransmitTime                       dd ?
        PathMtuDiscoveryTimeout              dd ?
        LinkLocalAddressBehavior             dd ?
        LinkLocalAddressTimeout              dd ?
        ZoneIndices                          dd ScopeLevelCount dup(?)
        SitePrefixLength                     dd ?
        Metric                               dd ?
        NlMtu                                dd ?
        Connected                            db ?
        SupportsWakeUpPatterns               db ?
        SupportsNeighborDiscovery            db ?
        SupportsRouterDiscovery              db ?
        ReachableTime                        dd ?
        TransmitOffload                      NL_INTERFACE_OFFLOAD_ROD
        ReceiveOffload                       NL_INTERFACE_OFFLOAD_ROD
        DisableDefaultRoutes                 db ?
    ends
end if

if ~defined MIB_IPINTERFACE_TABLE_DEF
    MIB_IPINTERFACE_TABLE_DEF equ 1
    struct MIB_IPINTERFACE_TABLE
        NumEntries dd   ?
        Table      MIB_IPINTERFACE_ROW ANY_SIZE
    ends
end if

if ~defined MIB_IPNETTABLE_DEF
    MIB_IPNETTABLE_DEF equ 1
    struct MIB_IPNETTABLE
        dwNumEntries dd ?
        table        MIB_IPNETROW ANY_SIZE
    ends
end if

if ~defined MIB_IPNET_TABLE2_DEF
    MIB_IPNET_TABLE2_DEF equ 1
    struct MIB_IPNET_TABLE2
        NumEntries dd   ?
        Table      MIB_IPNET_ROW2 ANY_SIZE
    ends
end if

if ~defined MIB_IPPATH_ROW_DEF
    MIB_IPPATH_ROW_DEF equ 1
    struct MIB_IPPATH_ROW
        Source              SOCKADDR_INET
        Destination         SOCKADDR_INET
        InterfaceLuid       NET_LUID
        InterfaceIndex      dd  ?
        CurrentNextHop      SOCKADDR_INET
        PathMtu             dd  ?
        RttMean             dd  ?
        RttDeviation        dd  ?
        union
            LastReachable   dd  ?
            LastUnreachable dd  ?
        ends
        IsReachable         db  ?
        LinkTransmitSpeed   dq  ?
        LinkReceiveSpeed    dq  ?
    ends
end if

if ~defined MIB_IPPATH_TABLE_DEF
    MIB_IPPATH_TABLE_DEF equ 1
    struct MIB_IPPATH_TABLE
        NumEntries dd   ?
        Table      MIB_IPPATH_ROW ANY_SIZE
    ends
end if

if ~defined MIB_IPSTATS_DEF
    MIB_IPSTATS_DEF equ 1
    struct MIB_IPSTATS
        dwForwarding      dd ?
        dwDefaultTTL      dd ?
        dwInReceives      dd ?
        dwInHdrErrors     dd ?
        dwInAddrErrors    dd ?
        dwForwDatagrams   dd ?
        dwInUnknownProtos dd ?
        dwInDiscards      dd ?
        dwInDelivers      dd ?
        dwOutRequests     dd ?
        dwRoutingDiscards dd ?
        dwOutDiscards     dd ?
        dwOutNoRoutes     dd ?
        dwReasmTimeout    dd ?
        dwReasmReqds      dd ?
        dwReasmOks        dd ?
        dwReasmFails      dd ?
        dwFragOks         dd ?
        dwFragFails       dd ?
        dwFragCreates     dd ?
        dwNumIf           dd ?
        dwNumAddr         dd ?
        dwNumRoutes       dd ?
    ends
end if
if ~defined MIB_IPSTATS_W2K_DEF
    MIB_IPSTATS_W2K_DEF equ 1
    define MIB_IPSTATS_W2K MIB_IPSTATS
end if

if ~defined MIB_MULTICASTIPADDRESS_ROW_DEF
    MIB_MULTICASTIPADDRESS_ROW_DEF equ 1
    struct MIB_MULTICASTIPADDRESS_ROW
        Address         SOCKADDR_INET
        InterfaceIndex  dd       ?
        InterfaceLuid   NET_LUID
        ScopeId         SCOPE_ID
    ends
end if

if ~defined MIB_MULTICASTIPADDRESS_TABLE_DEF
    MIB_MULTICASTIPADDRESS_TABLE_DEF equ 1
    struct MIB_MULTICASTIPADDRESS_TABLE
        NumEntries dd   ?
        Table      MIB_MULTICASTIPADDRESS_ROW ANY_SIZE
    ends
end if

if ~defined IP_MASK_STRING_DEF
    IP_MASK_STRING_DEF equ 1
    struct IP_MASK_STRING
        String db 16 dup(?)
    ends
end if

if ~defined IP_ADDRESS_STRING_DEF
    IP_ADDRESS_STRING_DEF equ 1
    struct IP_ADDRESS_STRING
        String db 16 dup(?)
    ends
end if

if ~defined IP_ADDR_STRING_DEF
    IP_ADDR_STRING_DEF equ 1
    struct IP_ADDR_STRING
        Next        xptr ? 
        IpAddress   IP_ADDRESS_STRING
        IpMask      IP_MASK_STRING
        Context     dd   ?
    ends
end if

if ~defined FIXED_INFO_DEF
    FIXED_INFO_DEF equ 1
    struct FIXED_INFO
        HostName         db (MAX_HOSTNAME_LEN + 4) dup(?)
        DomainName       db (MAX_DOMAIN_NAME_LEN + 4) dup(?)
        CurrentDnsServer xptr ?
        DnsServerList    IP_ADDR_STRING
        NodeType         dd ?
        ScopeId          db (MAX_SCOPE_ID_LEN + 4) dup(?)
        EnableRouting    dd ?
        EnableProxy      dd ?
        EnableDns        dd ?
    ends
end if
if ~defined FIXED_INFO_W2KSP1_DEF
    FIXED_INFO_W2KSP1_DEF equ 1
    define FIXED_INFO_W2KSP1 FIXED_INFO
end if

if ~defined MIB_TCP6ROW_OWNER_MODULE_DEF
    MIB_TCP6ROW_OWNER_MODULE_DEF equ 1
    struct MIB_TCP6ROW_OWNER_MODULE
        ucLocalAddr       db 16 dup (?)
        dwLocalScopeId    dd ?
        dwLocalPort       dd ?
        ucRemoteAddr      db 16 dup (?)
        dwRemoteScopeId   dd ?
        dwRemotePort      dd ?
        dwState           dd ?
        dwOwningPid       dd ?
        liCreateTimestamp LARGE_INTEGER
        OwningModuleInfo  dq TCPIP_OWNING_MODULE_SIZE dup(?)
    ends
end if

if ~defined MIB_TCPROW_OWNER_MODULE_DEF
    MIB_TCPROW_OWNER_MODULE_DEF equ 1
    struct MIB_TCPROW_OWNER_MODULE
        dwState           dd    ?
        dwLocalAddr       dd    ?
        dwLocalPort       dd    ?
        dwRemoteAddr      dd    ?
        dwRemotePort      dd    ?
        dwOwningPid       dd    ?
        liCreateTimestamp LARGE_INTEGER
        OwningModuleInfo  dq TCPIP_OWNING_MODULE_SIZE dup(?)
    ends
end if

if ~defined MIB_UDP6ROW_OWNER_MODULE_DEF
    MIB_UDP6ROW_OWNER_MODULE_DEF equ 1
    struct RECAMIB_UDP6ROW_OWNER_MODULE
        PP  dd ?
    ends

    struct MIB_UDP6ROW_OWNER_MODULE
        ucLocalAddr       db    16 dup(?)
        dwLocalScopeId    dd    ?
        dwLocalPort       dd    ?
        dwOwningPid       dd    ?
        liCreateTimestamp LARGE_INTEGER
        union
            struct
                RECAMIB_UDP6ROW_OWNER_MODULE
            ends
            dwFlags       dd    ?
        ends
        OwningModuleInfo  dq TCPIP_OWNING_MODULE_SIZE dup(?)
    ends
end if

if ~defined MIB_UDPROW_OWNER_MODULE_DEF
    MIB_UDPROW_OWNER_MODULE_DEF equ 1
    struct RECAMIB_UDPROW_OWNER_MODULE
        POSpecificPortBind  dd  ?
    ends

    struct MIB_UDPROW_OWNER_MODULE
        dwLocalAddr       dd    ?
        dwLocalPort       dd    ?
        dwOwningPid       dd    ?
        liCreateTimestamp LARGE_INTEGER
        union
            struct
                RECAMIB_UDPROW_OWNER_MODULE
            ends
            dwFlags       dd    ?
        ends
        OwningModuleInfo dq TCPIP_OWNING_MODULE_SIZE dup(?)
    ends
end if

if ~defined IP_PER_ADAPTER_INFO_DEF
    IP_PER_ADAPTER_INFO_DEF equ 1
    struct IP_PER_ADAPTER_INFO
        AutoconfigEnabled dd    ?
        AutoconfigActive  dd    ?
        CurrentDnsServer  xptr  ?
        DnsServerList     IP_ADDR_STRING
    ends
end if
if ~defined IP_PER_ADAPTER_INFO_W2KSP1_DEF
    IP_PER_ADAPTER_INFO_W2KSP1_DEF equ 1
    define IP_PER_ADAPTER_INFO_W2KSP1 IP_PER_ADAPTER_INFO
end if

if ~defined MIB_TCP6ROW_DEF
    MIB_TCP6ROW_DEF equ 1
    struct MIB_TCP6ROW
        State           dd  ?
        LocalAddr       IN6_ADDR
        dwLocalScopeId  dd  ?
        dwLocalPort     dd  ?
        RemoteAddr      IN6_ADDR
        dwRemoteScopeId dd  ?
        dwRemotePort    dd  ?
    ends
end if

if ~defined MIB_TCP6TABLE_DEF
    MIB_TCP6TABLE_DEF equ 1
    struct MIB_TCP6TABLE
        dwNumEntries dd ?
        table        MIB_TCP6ROW ANY_SIZE
    ends
end if

if ~defined MIB_TCP6ROW2_DEF
    MIB_TCP6ROW2_DEF equ 1
    struct MIB_TCP6ROW2
        LocalAddr       IN6_ADDR
        dwLocalScopeId  dd  ?
        dwLocalPort     dd  ?
        RemoteAddr      IN6_ADDR
        dwRemoteScopeId dd  ?
        dwRemotePort    dd  ?
        State           dd  ?
        dwOwningPid     dd  ?
        dwOffloadState  dd  ?
    ends
end if

if ~defined MIB_TCP6TABLE2_DEF
    MIB_TCP6TABLE2_DEF equ 1
    struct MIB_TCP6TABLE2
        dwNumEntries dd ?
        table        MIB_TCP6ROW2 ANY_SIZE
    ends
end if

if ~defined MIB_TCPSTATS_DEF
    MIB_TCPSTATS_DEF equ 1
    struct MIB_TCPSTATS
        dwRtoAlgorithm dd   ?
        dwRtoMin       dd   ?
        dwRtoMax       dd   ?
        dwMaxConn      dd   ?
        dwActiveOpens  dd   ?
        dwPassiveOpens dd   ?
        dwAttemptFails dd   ?
        dwEstabResets  dd   ?
        dwCurrEstab    dd   ?
        dwInSegs       dd   ?
        dwOutSegs      dd   ?
        dwRetransSegs  dd   ?
        dwInErrs       dd   ?
        dwOutRsts      dd   ?
        dwNumConns     dd   ?
    ends
end if

if ~defined MIB_TCPROW_DEF
    MIB_TCPROW_DEF equ 1
    struct MIB_TCPROW
        union
            dwState  dd ?
            State    dd ?
        ends
        dwLocalAddr  dd ?
        dwLocalPort  dd ?
        dwRemoteAddr dd ?
        dwRemotePort dd ?
    ends
end if
if ~defined MIB_TCPROW_LH_DEF
    MIB_TCPROW_LH_DEF equ 1
    define MIB_TCPROW_LH MIB_TCPROW
end if

if ~defined MIB_TCPROW2_DEF
    MIB_TCPROW2_DEF equ 1
    struct MIB_TCPROW2
        dwState        dd   ?
        dwLocalAddr    dd   ?
        dwLocalPort    dd   ?
        dwRemoteAddr   dd   ?
        dwRemotePort   dd   ?
        dwOwningPid    dd   ?
        dwOffloadState dd   ?
    ends
end if

if ~defined MIB_TCPTABLE2_DEF
    MIB_TCPTABLE2_DEF equ 1
    struct MIB_TCPTABLE2
        dwNumEntries dd ?
        table        MIB_TCPROW2 ANY_SIZE
    ends
end if

if ~defined MIB_UDP6ROW_DEF
    MIB_UDP6ROW_DEF equ 1
    struct MIB_UDP6ROW
        dwLocalAddr     IN6_ADDR
        dwLocalScopeId  dd  ?
        dwLocalPort     dd  ?
    ends
end if

if ~defined MIB_UDP6TABLE_DEF
    MIB_UDP6TABLE_DEF equ 1
    struct MIB_UDP6TABLE
        dwNumEntries dd ?
        table        MIB_UDP6ROW ANY_SIZE
    ends
end if

if ~defined MIB_UDPSTATS_DEF
    MIB_UDPSTATS_DEF equ 1
    struct MIB_UDPSTATS
        dwInDatagrams   dd  ?
        dwNoPorts       dd  ?
        dwInErrors      dd  ?
        dwOutDatagrams  dd  ?
        dwNumAddrs      dd  ?
    ends
end if

if ~defined MIB_UDPROW_DEF
    MIB_UDPROW_DEF equ 1
    struct MIB_UDPROW
        dwLocalAddr dd  ?
        dwLocalPort dd  ?
    ends
end if

if ~defined MIB_UDPTABLE_DEF
    MIB_UDPTABLE_DEF equ 1
    struct MIB_UDPTABLE
        dwNumEntries dd ?
        table        MIB_UDPROW ANY_SIZE
    ends
end if

if ~defined IP_UNIDIRECTIONAL_ADAPTER_ADDRESS_DEF
    IP_UNIDIRECTIONAL_ADAPTER_ADDRESS_DEF equ 1
    struct IP_UNIDIRECTIONAL_ADAPTER_ADDRESS
        NumAdapters dd ?
        Address     dd 1 dup(?)
    ends
end if

if ~defined MIB_UNICASTIPADDRESS_ROW_DEF
    MIB_UNICASTIPADDRESS_ROW_DEF equ 1
    struct MIB_UNICASTIPADDRESS_ROW
        Address             SOCKADDR_INET
        InterfaceLuid       NET_LUID
        InterfaceIndex      dd  ?
        PrefixOrigin        dd  ?
        SuffixOrigin        dd  ?
        ValidLifetime       dd  ?
        PreferredLifetime   dd  ?
        OnLinkPrefixLength  db  ?
        SkipAsSource        db  ?
        DadState            dd  ?
        ScopeId             SCOPE_ID
        CreationTimeStamp   LARGE_INTEGER
    ends
end if

if ~defined IPV6_ADDRESS_EX_DEF
    IPV6_ADDRESS_EX_DEF equ 1
    struct IPV6_ADDRESS_EX
        sin6_port     dw ?
        sin6_flowinfo dd ?
        sin6_addr     dw 8 dup(?)
        sin6_scope_id dd ?
    ends
end if

if ~defined ICMPV6_ECHO_REPLY_DEF
    ICMPV6_ECHO_REPLY_DEF equ 1
    struct ICMPV6_ECHO_REPLY
        Address       IPV6_ADDRESS_EX
        Status        dd ?
        RoundTripTime dd ?
    ends
end if
if ~defined ICMPV6_ECHO_REPLY_LH_DEF
    ICMPV6_ECHO_REPLY_LH_DEF equ 1
    define ICMPV6_ECHO_REPLY_LH ICMPV6_ECHO_REPLY
end if

if ~defined SOCKADDR_IN6_LH_DEF
    SOCKADDR_IN6_LH_DEF equ 1
    struct SOCKADDR_IN6_LH
        sin6_family           dw ?
        sin6_port             dw ?
        sin6_flowinfo         dd ?
        sin6_addr             IN6_ADDR
        union
            sin6_scope_id     dd ?
            sin6_scope_struct SCOPE_ID
        ends
    ends
end if

if ~defined IP_OPTION_INFORMATION_DEF
    IP_OPTION_INFORMATION_DEF equ 1
    struct IP_OPTION_INFORMATION
        Ttl         db    ?
        Tos         db    ?
        Flags       db    ?
        OptionsSize db    ?
        OptionsData xptr  ?
    ends
end if

if ~defined SOCKADDR_DEF
    SOCKADDR_DEF equ 1
    struct SOCKADDR
        if (NTDDI_VERSION < NTDDI_VISTA)
            sa_family dw ?
        else
            sa_family2 ADDRESS_FAMILY ?
        end if
        sa_data       db 14 dup(?)
    ends
end if

if ~defined NET_ADDRESS_INFO_DEF
    NET_ADDRESS_INFO_DEF equ 1
    struct NET_ADDRESS_INFO
        Format          dd ?
        union
            struct
                Address dw DNS_MAX_NAME_BUFFER_LENGTH dup(?)
                Port    dw 6 dup(?)
            ends
            Ipv4Address SOCKADDR_IN
            Ipv6Address SOCKADDR_IN6
            IpAddress   SOCKADDR
        ends
    ends
end if

if ~defined OVERLAPPED_DEF
    OVERLAPPED_DEF equ 1
    struct OVERLAPPED
        Internal     xptr ?
        InternalHigh xptr ?
        union
            struct
                Offset     dd  ?
                OffsetHigh  dd  ?
            ends
            Pointer  xptr   ?
        ends
        hEvent       xptr   ?
    ends
end if

if ~defined MIB_TCPROW_OWNER_PID_DEF
    MIB_TCPROW_OWNER_PID_DEF equ 1
    struct MIB_TCPROW_OWNER_PID
        dwState      dd ?
        dwLocalAddr  dd ?
        dwLocalPort  dd ?
        dwRemoteAddr dd ?
        dwRemotePort dd ?
        dwOwningPid  dd ?
    ends
end if

if ~defined MIB_UDPROW_OWNER_PID_DEF
    MIB_UDPROW_OWNER_PID_DEF equ 1
    struct MIB_UDPROW_OWNER_PID
        dwLocalAddr dd ?
        dwLocalPort dd ?
        dwOwningPid dd ?
    ends
end if

if ~defined MIB_IPADDRTABLE_DEF
    MIB_IPADDRTABLE_DEF equ 1
    struct MIB_IPADDRTABLE
        dwNumEntries dd ?
        table        MIB_IPADDRROW ANY_SIZE
    ends
end if

if ~defined MIB_TCPTABLE_OWNER_PID_DEF
    MIB_TCPTABLE_OWNER_PID_DEF equ 1
    struct MIB_TCPTABLE_OWNER_PID
        dwNumEntries dd ?
        table        MIB_TCPROW_OWNER_PID ANY_SIZE
    ends
end if

if ~defined MIB_UDPTABLE_OWNER_PID_DEF
    MIB_UDPTABLE_OWNER_PID_DEF equ 1
    struct MIB_UDPTABLE_OWNER_PID
        dwNumEntries dd ?
        table        MIB_UDPROW_OWNER_PID ANY_SIZE
    ends
end if

if ~defined MIB_TCP6ROW_OWNER_PID_DEF
    MIB_TCP6ROW_OWNER_PID_DEF equ 1
    struct MIB_TCP6ROW_OWNER_PID
        ucLocalAddr     db 16 dup(?)
        dwLocalScopeId  dd ?
        dwLocalPort     dd ?
        ucRemoteAddr    db 16 dup(?)
        dwRemoteScopeId dd ?
        dwRemotePort    dd ?
        dwState         dd ?
        dwOwningPid     dd ?
    ends
end if

if ~defined MIB_TCP6TABLE_OWNER_PID_DEF
    MIB_TCP6TABLE_OWNER_PID_DEF equ 1
    struct MIB_TCP6TABLE_OWNER_PID
        dwNumEntries dd ?
        table        MIB_TCP6ROW_OWNER_PID ANY_SIZE
    ends
end if


;======================================== Functions =======================================;
import iphlpapi,\
    _PfAddFiltersToInterface,'_PfAddFiltersToInterface',\
    _PfAddGlobalFilterToInterface,'_PfAddGlobalFilterToInterface',\
    _PfBindInterfaceToIndex,'_PfBindInterfaceToIndex',\
    _PfBindInterfaceToIPAddress,'_PfBindInterfaceToIPAddress',\
    _PfCreateInterface,'_PfCreateInterface',\
    _PfDeleteInterface,'_PfDeleteInterface',\
    _PfDeleteLog,'_PfDeleteLog',\
    _PfGetInterfaceStatistics,'_PfGetInterfaceStatistics',\
    _PfMakeLog,'_PfMakeLog',\
    _PfRebindFilters,'_PfRebindFilters',\
    _PfRemoveFilterHandles,'_PfRemoveFilterHandles',\
    _PfRemoveFiltersFromInterface,'_PfRemoveFiltersFromInterface',\
    _PfRemoveGlobalFilterFromInterface,'_PfRemoveGlobalFilterFromInterface',\
    _PfSetLogBuffer,'_PfSetLogBuffer',\
    _PfTestPacket,'_PfTestPacket',\
    _PfUnBindInterface,'_PfUnBindInterface',\
    AddIPAddress,'AddIPAddress',\
    AllocateAndGetArpEntTableFromStack,'AllocateAndGetArpEntTableFromStack',\
    AllocateAndGetIfTableFromStack,'AllocateAndGetIfTableFromStack',\
    AllocateAndGetIpAddrTableFromStack,'AllocateAndGetIpAddrTableFromStack',\
    AllocateAndGetIpForwardTableFromStack,'AllocateAndGetIpForwardTableFromStack',\
    AllocateAndGetIpNetTableFromStack,'AllocateAndGetIpNetTableFromStack',\
    AllocateAndGetTcpExTableFromStack,'AllocateAndGetTcpExTableFromStack',\
    AllocateAndGetTcpExTable2FromStack,'AllocateAndGetTcpExTable2FromStack',\
    AllocateAndGetTcpTableFromStack,'AllocateAndGetTcpTableFromStack',\
    AllocateAndGetUdpExTable2FromStack,'AllocateAndGetUdpExTable2FromStack',\
    AllocateAndGetUdpExTableFromStack,'AllocateAndGetUdpExTableFromStack',\
    AllocateAndGetUdpTableFromStack,'AllocateAndGetUdpTableFromStack',\
    CancelIPChangeNotify,'CancelIPChangeNotify',\
    CancelMibChangeNotify2,'CancelMibChangeNotify2',\
    CancelSecurityHealthChangeNotify,'CancelSecurityHealthChangeNotify',\
    ConvertGuidToStringA,'ConvertGuidToStringA',\
    ConvertGuidToStringW,'ConvertGuidToStringW',\
    ConvertInterfaceAliasToLuid,'ConvertInterfaceAliasToLuid',\
    ConvertInterfaceGuidToLuid,'ConvertInterfaceGuidToLuid',\
    ConvertInterfaceIndexToLuid,'ConvertInterfaceIndexToLuid',\
    ConvertInterfaceLuidToAlias,'ConvertInterfaceLuidToAlias',\
    ConvertInterfaceLuidToGuid,'ConvertInterfaceLuidToGuid',\
    ConvertInterfaceLuidToIndex,'ConvertInterfaceLuidToIndex',\
    ConvertInterfaceLuidToNameA,'ConvertInterfaceLuidToNameA',\
    ConvertInterfaceLuidToNameW,'ConvertInterfaceLuidToNameW',\
    ConvertInterfaceNameToLuidA,'ConvertInterfaceNameToLuidA',\
    ConvertInterfaceNameToLuidW,'ConvertInterfaceNameToLuidW',\
    ConvertInterfacePhysicalAddressToLuid,'ConvertInterfacePhysicalAddressToLuid',\
    ConvertIpv4MaskToLength,'ConvertIpv4MaskToLength',\
    ConvertLengthToIpv4Mask,'ConvertLengthToIpv4Mask',\
    ConvertRemoteInterfaceAliasToLuid,'ConvertRemoteInterfaceAliasToLuid',\
    ConvertRemoteInterfaceGuidToLuid,'ConvertRemoteInterfaceGuidToLuid',\
    ConvertRemoteInterfaceIndexToLuid,'ConvertRemoteInterfaceIndexToLuid',\
    ConvertRemoteInterfaceLuidToAlias,'ConvertRemoteInterfaceLuidToAlias',\
    ConvertRemoteInterfaceLuidToGuid,'ConvertRemoteInterfaceLuidToGuid',\
    ConvertRemoteInterfaceLuidToIndex,'ConvertRemoteInterfaceLuidToIndex',\
    ConvertStringToGuidA,'ConvertStringToGuidA',\
    ConvertStringToGuidW,'ConvertStringToGuidW',\
    ConvertStringToInterfacePhysicalAddress,'ConvertStringToInterfacePhysicalAddress',\
    CPNatfwtCreateProviderInstance,'CPNatfwtCreateProviderInstance',\
    CPNatfwtDeregisterProviderInstance,'CPNatfwtDeregisterProviderInstance',\
    CPNatfwtDestroyProviderInstance,'CPNatfwtDestroyProviderInstance',\
    CPNatfwtIndicateReceivedBuffers,'CPNatfwtIndicateReceivedBuffers',\
    CPNatfwtRegisterProviderInstance,'CPNatfwtRegisterProviderInstance',\
    CreateAnycastIpAddressEntry,'CreateAnycastIpAddressEntry',\
    CreateIpForwardEntry2,'CreateIpForwardEntry2',\
    CreateIpNetEntry2,'CreateIpNetEntry2',\
    CreateIpForwardEntry,'CreateIpForwardEntry',\
    CreateIpNetEntry,'CreateIpNetEntry',\
    CreatePersistentTcpPortReservation,'CreatePersistentTcpPortReservation',\
    CreatePersistentUdpPortReservation,'CreatePersistentUdpPortReservation',\
    CreateProxyArpEntry,'CreateProxyArpEntry',\
    CreateSortedAddressPairs,'CreateSortedAddressPairs',\
    CreateUnicastIpAddressEntry,'CreateUnicastIpAddressEntry',\
    DeleteAnycastIpAddressEntry,'DeleteAnycastIpAddressEntry',\
    DeleteIPAddress,'DeleteIPAddress',\
    DeleteIpForwardEntry,'DeleteIpForwardEntry',\
    DeleteIpForwardEntry2,'DeleteIpForwardEntry2',\
    DeleteIpNetEntry2,'DeleteIpNetEntry2',\
    DeleteIpNetEntry,'DeleteIpNetEntry',\
    DeletePersistentTcpPortReservation,'DeletePersistentTcpPortReservation',\
    DeletePersistentUdpPortReservation,'DeletePersistentUdpPortReservation',\
    DeleteUnicastIpAddressEntry,'DeleteUnicastIpAddressEntry',\
    DeleteProxyArpEntry,'DeleteProxyArpEntry',\
    DisableMediaSense,'DisableMediaSense',\
    do_echo_rep0,'do_echo_rep',\
    do_echo_req0,'do_echo_req',\
    EnableRouter,'EnableRouter',\
    FlushIpNetTable,'FlushIpNetTable',\
    FlushIpNetTable2,'FlushIpNetTable2',\
    FlushIpPathTable,'FlushIpPathTable',\
    FreeMibTable,'FreeMibTable',\
    FlushIpNetTableFromStack,'FlushIpNetTableFromStack',\
    GetAdapterIndex,'GetAdapterIndex',\
    GetAdapterOrderMap,'GetAdapterOrderMap',\
    GetAdaptersAddresses,'GetAdaptersAddresses',\
    GetAdaptersInfo,'GetAdaptersInfo',\
    GetAnycastIpAddressEntry,'GetAnycastIpAddressEntry',\
    GetAnycastIpAddressTable,'GetAnycastIpAddressTable',\
    GetBestInterface,'GetBestInterface',\
    GetBestInterfaceEx,'GetBestInterfaceEx',\
    GetBestInterfaceFromStack,'GetBestInterfaceFromStack',\
    GetBestRoute,'GetBestRoute',\
    GetBestRoute2,'GetBestRoute2',\
    GetBestRouteFromStack,'GetBestRouteFromStack',\
    GetCurrentThreadCompartmentId,'GetCurrentThreadCompartmentId',\
    GetCurrentThreadCompartmentScope,'GetCurrentThreadCompartmentScope',\
    GetExtendedTcpTable,'GetExtendedTcpTable',\
    GetExtendedUdpTable,'GetExtendedUdpTable',\
    GetFriendlyIfIndex,'GetFriendlyIfIndex',\
    GetIcmpStatistics,'GetIcmpStatistics',\
    GetIcmpStatisticsEx,'GetIcmpStatisticsEx',\
    GetIcmpStatsFromStack,'GetIcmpStatsFromStack',\
    GetIcmpStatsFromStackEx,'GetIcmpStatsFromStackEx',\
    GetIfEntryFromStack,'GetIfEntryFromStack',\
    GetIfEntry,'GetIfEntry',\
    GetIfEntry2,'GetIfEntry2',\
    GetIfStackTable,'GetIfStackTable',\
    GetIfTable,'GetIfTable',\
    GetIfTable2,'GetIfTable2',\
    GetIfTable2Ex,'GetIfTable2Ex',\
    GetInvertedIfStackTable,'GetInvertedIfStackTable',\
    GetInterfaceInfo,'GetInterfaceInfo',\
    GetIpAddrTable,'GetIpAddrTable',\
    GetIpAddrTableFromStack,'GetIpAddrTableFromStack',\
    GetIpForwardTableFromStack,'GetIpForwardTableFromStack',\
    GetIpErrorString,'GetIpErrorString',\
    GetIpForwardEntry2,'GetIpForwardEntry2',\
    GetIpForwardTable2,'GetIpForwardTable2',\
    GetIpInterfaceEntry,'GetIpInterfaceEntry',\
    GetIpInterfaceTable,'GetIpInterfaceTable',\
    GetIpNetEntry2,'GetIpNetEntry2',\
    GetIpNetTable2,'GetIpNetTable2',\
    GetIpForwardTable,'GetIpForwardTable',\
    GetIpNetTable,'GetIpNetTable',\
    GetIpNetTableFromStack,'GetIpNetTableFromStack',\
    GetIpNetworkConnectionBandwidthEstimates,'GetIpNetworkConnectionBandwidthEstimates',\
    GetIpPathEntry,'GetIpPathEntry',\
    GetIpPathTable,'GetIpPathTable',\
    GetIpStatistics,'GetIpStatistics',\
    GetIpStatisticsEx,'GetIpStatisticsEx',\
    GetIpStatsFromStack,'GetIpStatsFromStack',\
    GetIpStatsFromStackEx,'GetIpStatsFromStackEx',\
    GetMulticastIpAddressEntry,'GetMulticastIpAddressEntry',\
    GetMulticastIpAddressTable,'GetMulticastIpAddressTable',\
    GetNetworkInformation,'GetNetworkInformation',\
    GetNetworkParams,'GetNetworkParams',\
    GetNumberOfInterfaces,'GetNumberOfInterfaces',\
    GetOwnerModuleFromPidAndInfo,'GetOwnerModuleFromPidAndInfo',\
    GetOwnerModuleFromTcp6Entry,'GetOwnerModuleFromTcp6Entry',\
    GetOwnerModuleFromTcpEntry,'GetOwnerModuleFromTcpEntry',\
    GetOwnerModuleFromUdp6Entry,'GetOwnerModuleFromUdp6Entry',\
    GetOwnerModuleFromUdpEntry,'GetOwnerModuleFromUdpEntry',\
    GetPerAdapterInfo,'GetPerAdapterInfo',\
    GetPerTcp6ConnectionEStats,'GetPerTcp6ConnectionEStats',\
    GetPerTcp6ConnectionStats,'GetPerTcp6ConnectionStats',\
    GetPerTcpConnectionEStats,'GetPerTcpConnectionEStats',\
    GetPerTcpConnectionStats,'GetPerTcpConnectionStats',\
    GetRTTAndHopCount,'GetRTTAndHopCount',\
    GetSessionCompartmentId,'GetSessionCompartmentId',\
    GetTcp6Table,'GetTcp6Table',\
    GetTcp6Table2,'GetTcp6Table2',\
    GetTcpExTable2FromStack,'GetTcpExTable2FromStack',\
    GetTcpStatsFromStack,'GetTcpStatsFromStack',\
    GetTcpTableFromStack,'GetTcpTableFromStack',\
    GetTcpStatistics,'GetTcpStatistics',\
    GetTcpStatisticsEx,'GetTcpStatisticsEx',\
    GetTcpTable,'GetTcpTable',\
    GetTcpTable2,'GetTcpTable2',\
    GetTeredoPort,'GetTeredoPort',\
    GetUdp6Table,'GetUdp6Table',\
    GetUdpExTable2FromStack,'GetUdpExTable2FromStack',\
    GetUdpStatistics,'GetUdpStatistics',\
    GetUdpStatisticsEx,'GetUdpStatisticsEx',\
    GetUdpStatsFromStack,'GetUdpStatsFromStack',\
    GetUdpStatsFromStackEx,'GetUdpStatsFromStackEx',\
    GetUdpTableFromStack,'GetUdpTableFromStack',\
    GetUdpTable,'GetUdpTable',\
    GetUniDirectionalAdapterInfo,'GetUniDirectionalAdapterInfo',\
    GetUnicastIpAddressEntry,'GetUnicastIpAddressEntry',\
    GetUnicastIpAddressTable,'GetUnicastIpAddressTable',\
    Icmp6CreateFile,'Icmp6CreateFile',\
    Icmp6ParseReplies,'Icmp6ParseReplies',\
    Icmp6SendEcho2,'Icmp6SendEcho2',\
    IcmpCloseHandle,'IcmpCloseHandle',\
    IcmpCreateFile,'IcmpCreateFile',\
    IcmpParseReplies,'IcmpParseReplies',\
    IcmpSendEcho,'IcmpSendEcho',\
    IcmpSendEcho2,'IcmpSendEcho2',\
    IcmpSendEcho2Ex,'IcmpSendEcho2Ex',\
    if_indextoname,'if_indextoname',\
    if_nametoindex,'if_nametoindex',\
    InitializeCompartmentEntry,'InitializeCompartmentEntry',\
    InitializeIpForwardEntry,'InitializeIpForwardEntry',\
    InitializeIpInterfaceEntry,'InitializeIpInterfaceEntry',\
    InitializeUnicastIpAddressEntry,'InitializeUnicastIpAddressEntry',\
    InternalCleanupPersistentStore,'InternalCleanupPersistentStore',\
    InternalCreateAnycastIpAddressEntry,'InternalCreateAnycastIpAddressEntry',\
    InternalCreateIpForwardEntry2,'InternalCreateIpForwardEntry2',\
    InternalCreateIpNetEntry2,'InternalCreateIpNetEntry2',\
    InternalCreateUnicastIpAddressEntry,'InternalCreateUnicastIpAddressEntry',\
    InternalDeleteAnycastIpAddressEntry,'InternalDeleteAnycastIpAddressEntry',\
    InternalDeleteIpForwardEntry2,'InternalDeleteIpForwardEntry2',\
    InternalCreateIpNetEntry,'InternalCreateIpNetEntry',\
    InternalCreateIpForwardEntry,'InternalCreateIpForwardEntry',\
    InternalDeleteIpForwardEntry,'InternalDeleteIpForwardEntry',\
    InternalDeleteIpNetEntry,'InternalDeleteIpNetEntry',\
    InternalDeleteIpNetEntry2,'InternalDeleteIpNetEntry2',\
    InternalDeleteUnicastIpAddressEntry,'InternalDeleteUnicastIpAddressEntry',\
    InternalFindInterfaceByAddress,'InternalFindInterfaceByAddress',\
    InternalGetAnycastIpAddressEntry,'InternalGetAnycastIpAddressEntry',\
    InternalGetAnycastIpAddressTable,'InternalGetAnycastIpAddressTable',\
    InternalGetForwardIpTable2,'InternalGetForwardIpTable2',\
    InternalGetIfEntry2,'InternalGetIfEntry2',\
    InternalGetIfTable2,'InternalGetIfTable2',\
    InternalGetIpForwardEntry2,'InternalGetIpForwardEntry2',\
    InternalGetIpInterfaceEntry,'InternalGetIpInterfaceEntry',\
    InternalGetIpInterfaceTable,'InternalGetIpInterfaceTable',\
    InternalGetIpNetEntry2,'InternalGetIpNetEntry2',\
    InternalGetIpNetTable2,'InternalGetIpNetTable2',\
    InternalGetIfTable,'InternalGetIfTable',\
    InternalGetIpAddrTable,'InternalGetIpAddrTable',\
    InternalGetIpForwardTable,'InternalGetIpForwardTable',\
    InternalGetIpNetTable,'InternalGetIpNetTable',\
    InternalGetMulticastIpAddressEntry,'InternalGetMulticastIpAddressEntry',\
    InternalGetMulticastIpAddressTable,'InternalGetMulticastIpAddressTable',\
    InternalGetTcp6Table2,'InternalGetTcp6Table2',\
    InternalGetTcp6TableWithOwnerModule,'InternalGetTcp6TableWithOwnerModule',\
    InternalGetTcp6TableWithOwnerPid,'InternalGetTcp6TableWithOwnerPid',\
    InternalGetTcpTable,'InternalGetTcpTable',\
    InternalGetTcpTable2,'InternalGetTcpTable2',\
    InternalGetTcpTableEx,'InternalGetTcpTableEx',\
    InternalGetTcpTableWithOwnerModule,'InternalGetTcpTableWithOwnerModule',\
    InternalGetTcpTableWithOwnerPid,'InternalGetTcpTableWithOwnerPid',\
    InternalGetTunnelPhysicalAdapter,'InternalGetTunnelPhysicalAdapter',\
    InternalGetUdp6TableWithOwnerModule,'InternalGetUdp6TableWithOwnerModule',\
    InternalGetUdp6TableWithOwnerPid,'InternalGetUdp6TableWithOwnerPid',\
    InternalGetUdpTable,'InternalGetUdpTable',\
    InternalGetUdpTableEx,'InternalGetUdpTableEx',\
    InternalGetUdpTableWithOwnerModule,'InternalGetUdpTableWithOwnerModule',\
    InternalGetUdpTableWithOwnerPid,'InternalGetUdpTableWithOwnerPid',\
    InternalGetUnicastIpAddressEntry,'InternalGetUnicastIpAddressEntry',\
    InternalGetUnicastIpAddressTable,'InternalGetUnicastIpAddressTable',\
    InternalSetIfEntry,'InternalSetIfEntry',\
    InternalSetIpForwardEntry,'InternalSetIpForwardEntry',\
    InternalSetIpForwardEntry2,'InternalSetIpForwardEntry2',\
    InternalSetIpInterfaceEntry,'InternalSetIpInterfaceEntry',\
    InternalSetIpNetEntry2,'InternalSetIpNetEntry2',\
    InternalSetIpNetEntry,'InternalSetIpNetEntry',\
    InternalSetIpStats,'InternalSetIpStats',\
    InternalSetTcpEntry,'InternalSetTcpEntry',\
    InternalSetTeredoPort,'InternalSetTeredoPort',\
    InternalSetUnicastIpAddressEntry,'InternalSetUnicastIpAddressEntry',\
    IpReleaseAddress,'IpReleaseAddress',\
    IpRenewAddress,'IpRenewAddress',\
    IsLocalAddress,'IsLocalAddress',\
    LookupPersistentTcpPortReservation,'LookupPersistentTcpPortReservation',\
    LookupPersistentUdpPortReservation,'LookupPersistentUdpPortReservation',\
    NhGetInterfaceDescriptionFromGuid,'NhGetInterfaceDescriptionFromGuid',\
    NhGetInterfaceNameFromGuid,'NhGetInterfaceNameFromGuid',\
    NhpGetInterfaceIndexFromStack,'NhpGetInterfaceIndexFromStack',\
    NhGetGuidFromInterfaceName,'NhGetGuidFromInterfaceName',\
    NhGetInterfaceNameFromDeviceGuid,'NhGetInterfaceNameFromDeviceGuid',\
    NhpAllocateAndGetInterfaceInfoFromStack,'NhpAllocateAndGetInterfaceInfoFromStack',\
    NotifyAddrChange,'NotifyAddrChange',\
    NotifyIpInterfaceChange,'NotifyIpInterfaceChange',\
    NotifyRouteChange2,'NotifyRouteChange2',\
    NotifyRouteChange,'NotifyRouteChange',\
    NotifyRouteChangeEx,'NotifyRouteChangeEx',\
    NotifySecurityHealthChange,'NotifySecurityHealthChange',\
    NotifyStableUnicastIpAddressTable,'NotifyStableUnicastIpAddressTable',\
    NotifyTeredoPortChange,'NotifyTeredoPortChange',\
    NotifyUnicastIpAddressChange,'NotifyUnicastIpAddressChange',\
    NTPTimeToNTFileTime,'NTPTimeToNTFileTime',\
    NTTimeToNTPTime,'NTTimeToNTPTime',\
    ParseNetworkString,'ParseNetworkString',\
    PfAddFiltersToInterface,'PfAddFiltersToInterface',\
    PfAddGlobalFilterToInterface,'PfAddGlobalFilterToInterface',\
    PfBindInterfaceToIndex,'PfBindInterfaceToIndex',\
    PfBindInterfaceToIPAddress,'PfBindInterfaceToIPAddress',\
    PfCreateInterface,'PfCreateInterface',\
    PfDeleteInterface,'PfDeleteInterface',\
    PfDeleteLog,'PfDeleteLog',\
    PfGetInterfaceStatistics,'PfGetInterfaceStatistics',\
    PfMakeLog,'PfMakeLog',\
    PfRebindFilters,'PfRebindFilters',\
    PfRemoveFilterHandles,'PfRemoveFilterHandles',\
    PfRemoveFiltersFromInterface,'PfRemoveFiltersFromInterface',\
    PfRemoveGlobalFilterFromInterface,'PfRemoveGlobalFilterFromInterface',\
    PfSetLogBuffer,'PfSetLogBuffer',\
    PfTestPacket,'PfTestPacket',\
    PfUnBindInterface,'PfUnBindInterface',\
    register_icmp,'register_icmp',\
    ResolveIpNetEntry2,'ResolveIpNetEntry2',\
    ResolveNeighbor,'ResolveNeighbor',\
    RestoreMediaSense,'RestoreMediaSense',\
    SendARP,'SendARP',\
    SetAdapterIpAddress,'SetAdapterIpAddress',\
    SetBlockRoutes,'SetBlockRoutes',\
    SetCurrentThreadCompartmentId,'SetCurrentThreadCompartmentId',\
    SetCurrentThreadCompartmentScope,'SetCurrentThreadCompartmentScope',\
    SetIfEntry,'SetIfEntry',\
    SetIfEntryToStack,'SetIfEntryToStack',\
    SetIpForwardEntryToStack,'SetIpForwardEntryToStack',\
    SetIpMultihopRouteEntryToStack,'SetIpMultihopRouteEntryToStack',\
    SetIpNetEntryToStack,'SetIpNetEntryToStack',\
    SetIpRouteEntryToStack,'SetIpRouteEntryToStack',\
    SetIpStatsToStack,'SetIpStatsToStack',\
    SetIpForwardEntry,'SetIpForwardEntry',\
    SetIpForwardEntry2,'SetIpForwardEntry2',\
    SetIpInterfaceEntry,'SetIpInterfaceEntry',\
    SetIpNetEntry2,'SetIpNetEntry2',\
    SetIpStatisticsEx,'SetIpStatisticsEx',\
    SetIpNetEntry,'SetIpNetEntry',\
    SetIpStatistics,'SetIpStatistics',\
    SetIpTTL,'SetIpTTL',\
    SetJobCompartmentId,'SetJobCompartmentId',\
    SetNetworkInformation,'SetNetworkInformation',\
    SetPerTcp6ConnectionEStats,'SetPerTcp6ConnectionEStats',\
    SetPerTcp6ConnectionStats,'SetPerTcp6ConnectionStats',\
    SetPerTcpConnectionEStats,'SetPerTcpConnectionEStats',\
    SetPerTcpConnectionStats,'SetPerTcpConnectionStats',\
    SetProxyArpEntryToStack,'SetProxyArpEntryToStack',\
    SetRouteWithRef,'SetRouteWithRef',\
    SetTcpEntryToStack,'SetTcpEntryToStack',\
    SetSessionCompartmentId,'SetSessionCompartmentId',\
    SetUnicastIpAddressEntry,'SetUnicastIpAddressEntry',\
    SetTcpEntry,'SetTcpEntry',\
    UnenableRouter,'UnenableRouter'

    api PROCESSENTRY32,\
        MODULEENTRY32,\
        ConvertGuidToString,\
        ConvertInterfaceLuidToName,\
        ConvertInterfaceNameToLuid,\
        ConvertStringToGuid

;======================= Undocumented functions (unknown arguments) =======================;
;AllocateAndGetInterfaceInfoFromStack,'AllocateAndGetInterfaceInfoFromStack',\
;CloseCompartment,'CloseCompartment',\
;CloseGetIPPhysicalInterfaceForDestination,'CloseGetIPPhysicalInterfaceForDestination',\
;ConvertCompartmentGuidToId,'ConvertCompartmentGuidToId',\
;ConvertCompartmentIdToGuid,'ConvertCompartmentIdToGuid',\
;CreateCompartment,'CreateCompartment',\
;DeleteCompartment,'DeleteCompartment',\
;GetWPAOACSupportLevel,'GetWPAOACSupportLevel',\
;InternalGetBoundTcp6EndpointTable,'InternalGetBoundTcp6EndpointTable',\
;InternalGetIPPhysicalInterfaceForDestination,'InternalGetIPPhysicalInterfaceForDestination',\
;InternalGetRtcSlotInformation,'InternalGetRtcSlotInformation',\
;InternalIcmpCreateFileEx,'InternalIcmpCreateFileEx',\
;NotifyCompartmentChange,'NotifyCompartmentChange',\
;OpenCompartment,'OpenCompartment'

end if ;IPHLPAPI_INC
