; ====================================================;
;                                                     ;
;     iphlpapi.inc for EC v2 Fasm visual projects     ;
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
if defined APP_WIN64
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__PfAddFiltersToInterface' as _PfAddFiltersToInterface:qword
        extrn '__imp__PfAddGlobalFilterToInterface' as _PfAddGlobalFilterToInterface:qword
        extrn '__imp__PfBindInterfaceToIndex' as _PfBindInterfaceToIndex:qword
        extrn '__imp__PfBindInterfaceToIPAddress' as _PfBindInterfaceToIPAddress:qword
        extrn '__imp__PfCreateInterface' as _PfCreateInterface:qword
        extrn '__imp__PfDeleteInterface' as _PfDeleteInterface:qword
        extrn '__imp__PfDeleteLog' as _PfDeleteLog:qword
        extrn '__imp__PfGetInterfaceStatistics' as _PfGetInterfaceStatistics:qword
        extrn '__imp__PfMakeLog' as _PfMakeLog:qword
        extrn '__imp__PfRebindFilters' as _PfRebindFilters:qword
        extrn '__imp__PfRemoveFilterHandles' as _PfRemoveFilterHandles:qword
        extrn '__imp__PfRemoveFiltersFromInterface' as _PfRemoveFiltersFromInterface:qword
        extrn '__imp__PfRemoveGlobalFilterFromInterface' as _PfRemoveGlobalFilterFromInterface:qword
        extrn '__imp__PfSetLogBuffer' as _PfSetLogBuffer:qword
        extrn '__imp__PfTestPacket' as _PfTestPacket:qword
        extrn '__imp__PfUnBindInterface' as _PfUnBindInterface:qword
    end if
    extrn '__imp_AddIPAddress' as AddIPAddress:qword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp_AllocateAndGetArpEntTableFromStack' as AllocateAndGetArpEntTableFromStack:qword
        extrn '__imp_AllocateAndGetIfTableFromStack' as AllocateAndGetIfTableFromStack:qword
        extrn '__imp_AllocateAndGetIpAddrTableFromStack' as AllocateAndGetIpAddrTableFromStack:qword
        extrn '__imp_AllocateAndGetIpForwardTableFromStack' as AllocateAndGetIpForwardTableFromStack:qword
        extrn '__imp_AllocateAndGetIpNetTableFromStack' as AllocateAndGetIpNetTableFromStack:qword
        extrn '__imp_AllocateAndGetTcpExTableFromStack' as AllocateAndGetTcpExTableFromStack:qword
        extrn '__imp_AllocateAndGetTcpExTable2FromStack' as AllocateAndGetTcpExTable2FromStack:qword
        extrn '__imp_AllocateAndGetTcpTableFromStack' as AllocateAndGetTcpTableFromStack:qword
        extrn '__imp_AllocateAndGetUdpExTable2FromStack' as AllocateAndGetUdpExTable2FromStack:qword
        extrn '__imp_AllocateAndGetUdpExTableFromStack' as AllocateAndGetUdpExTableFromStack:qword
        extrn '__imp_AllocateAndGetUdpTableFromStack' as AllocateAndGetUdpTableFromStack:qword
    end if
    extrn '__imp_CancelIPChangeNotify' as CancelIPChangeNotify:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_CancelMibChangeNotify2' as CancelMibChangeNotify2:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WINXP)
        if (NTDDI_VERSION <= NTDDI_WS03ALL)
            extrn '__imp_CancelSecurityHealthChangeNotify' as CancelSecurityHealthChangeNotify:qword
        end if
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_ConvertGuidToStringA' as ConvertGuidToStringA:qword
        extrn '__imp_ConvertGuidToStringW' as ConvertGuidToStringW:qword
        api ConvertGuidToString
    end if
    extrn '__imp_ConvertInterfaceAliasToLuid' as ConvertInterfaceAliasToLuid:qword
    extrn '__imp_ConvertInterfaceGuidToLuid' as ConvertInterfaceGuidToLuid:qword
    extrn '__imp_ConvertInterfaceIndexToLuid' as ConvertInterfaceIndexToLuid:qword
    extrn '__imp_ConvertInterfaceLuidToAlias' as ConvertInterfaceLuidToAlias:qword
    extrn '__imp_ConvertInterfaceLuidToGuid' as ConvertInterfaceLuidToGuid:qword
    extrn '__imp_ConvertInterfaceLuidToIndex' as ConvertInterfaceLuidToIndex:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_ConvertInterfaceLuidToNameA' as ConvertInterfaceLuidToNameA:qword
        extrn '__imp_ConvertInterfaceLuidToNameW' as ConvertInterfaceLuidToNameW:qword
        extrn '__imp_ConvertInterfaceNameToLuidA' as ConvertInterfaceNameToLuidA:qword
        extrn '__imp_ConvertInterfaceNameToLuidW' as ConvertInterfaceNameToLuidW:qword
        extrn '__imp_ConvertInterfacePhysicalAddressToLuid' as ConvertInterfacePhysicalAddressToLuid:qword
        extrn '__imp_ConvertIpv4MaskToLength' as ConvertIpv4MaskToLength:qword
        extrn '__imp_ConvertLengthToIpv4Mask' as ConvertLengthToIpv4Mask:qword
        extrn '__imp_ConvertRemoteInterfaceAliasToLuid' as ConvertRemoteInterfaceAliasToLuid:qword
        extrn '__imp_ConvertRemoteInterfaceGuidToLuid' as ConvertRemoteInterfaceGuidToLuid:qword
        extrn '__imp_ConvertRemoteInterfaceIndexToLuid' as ConvertRemoteInterfaceIndexToLuid:qword
        extrn '__imp_ConvertRemoteInterfaceLuidToAlias' as ConvertRemoteInterfaceLuidToAlias:qword
        extrn '__imp_ConvertRemoteInterfaceLuidToGuid' as ConvertRemoteInterfaceLuidToGuid:qword
        extrn '__imp_ConvertRemoteInterfaceLuidToIndex' as ConvertRemoteInterfaceLuidToIndex:qword
        extrn '__imp_ConvertStringToGuidA' as ConvertStringToGuidA:qword
        extrn '__imp_ConvertStringToGuidW' as ConvertStringToGuidW:qword
        api ConvertInterfaceLuidToName,\
            ConvertInterfaceNameToLuid,\
            ConvertStringToGuid
    end if
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_ConvertStringToInterfacePhysicalAddress' as ConvertStringToInterfacePhysicalAddress:qword
        extrn '__imp_CPNatfwtCreateProviderInstance' as CPNatfwtCreateProviderInstance:qword
        extrn '__imp_CPNatfwtDeregisterProviderInstance' as CPNatfwtDeregisterProviderInstance:qword
        extrn '__imp_CPNatfwtDestroyProviderInstance' as CPNatfwtDestroyProviderInstance:qword
        extrn '__imp_CPNatfwtIndicateReceivedBuffers' as CPNatfwtIndicateReceivedBuffers:qword
        extrn '__imp_CPNatfwtRegisterProviderInstance' as CPNatfwtRegisterProviderInstance:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_CreateAnycastIpAddressEntry' as CreateAnycastIpAddressEntry:qword
        extrn '__imp_CreateIpForwardEntry2' as CreateIpForwardEntry2:qword
        extrn '__imp_CreateIpNetEntry2' as CreateIpNetEntry2:qword
    end if
    extrn '__imp_CreateIpForwardEntry' as CreateIpForwardEntry:qword
    extrn '__imp_CreateIpNetEntry' as CreateIpNetEntry:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_CreatePersistentTcpPortReservation' as CreatePersistentTcpPortReservation:qword
        extrn '__imp_CreatePersistentUdpPortReservation' as CreatePersistentUdpPortReservation:qword
    end if
    extrn '__imp_CreateProxyArpEntry' as CreateProxyArpEntry:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_CreateSortedAddressPairs' as CreateSortedAddressPairs:qword
        extrn '__imp_CreateUnicastIpAddressEntry' as CreateUnicastIpAddressEntry:qword
        extrn '__imp_DeleteAnycastIpAddressEntry' as DeleteAnycastIpAddressEntry:qword
    end if
    extrn '__imp_DeleteIPAddress' as DeleteIPAddress:qword
    extrn '__imp_DeleteIpForwardEntry' as DeleteIpForwardEntry:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_DeleteIpForwardEntry2' as DeleteIpForwardEntry2:qword
        extrn '__imp_DeleteIpNetEntry2' as DeleteIpNetEntry2:qword
    end if
    extrn '__imp_DeleteIpNetEntry' as DeleteIpNetEntry:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_DeletePersistentTcpPortReservation' as DeletePersistentTcpPortReservation:qword
        extrn '__imp_DeletePersistentUdpPortReservation' as DeletePersistentUdpPortReservation:qword
        extrn '__imp_DeleteUnicastIpAddressEntry' as DeleteUnicastIpAddressEntry:qword
    end if
    extrn '__imp_DeleteProxyArpEntry' as DeleteProxyArpEntry:qword
    extrn '__imp_DisableMediaSense' as DisableMediaSense:qword
    extrn '__imp_do_echo_rep' as do_echo_rep:qword
    extrn '__imp_do_echo_req' as do_echo_req:qword
    extrn '__imp_EnableRouter' as EnableRouter:qword
    extrn '__imp_FlushIpNetTable' as FlushIpNetTable:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_FlushIpNetTable2' as FlushIpNetTable2:qword
        extrn '__imp_FlushIpPathTable' as FlushIpPathTable:qword
        extrn '__imp_FreeMibTable' as FreeMibTable:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp_FlushIpNetTableFromStack' as FlushIpNetTableFromStack:qword
    end if
    extrn '__imp_GetAdapterIndex' as GetAdapterIndex:qword
    extrn '__imp_GetAdapterOrderMap' as GetAdapterOrderMap:qword
    extrn '__imp_GetAdaptersAddresses' as GetAdaptersAddresses:qword
    extrn '__imp_GetAdaptersInfo' as GetAdaptersInfo:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetAnycastIpAddressEntry' as GetAnycastIpAddressEntry:qword
        extrn '__imp_GetAnycastIpAddressTable' as GetAnycastIpAddressTable:qword
    end if
    extrn '__imp_GetBestInterface' as GetBestInterface:qword
    extrn '__imp_GetBestInterfaceEx' as GetBestInterfaceEx:qword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp_GetBestInterfaceFromStack' as GetBestInterfaceFromStack:qword
    end if
    extrn '__imp_GetBestRoute' as GetBestRoute:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetBestRoute2' as GetBestRoute2:qword
    end if

    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp_GetBestRouteFromStack' as GetBestRouteFromStack:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetCurrentThreadCompartmentId' as GetCurrentThreadCompartmentId:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp_GetCurrentThreadCompartmentScope' as GetCurrentThreadCompartmentScope:qword
    end if
    extrn '__imp_GetExtendedTcpTable' as GetExtendedTcpTable:qword
    extrn '__imp_GetExtendedUdpTable' as GetExtendedUdpTable:qword
    extrn '__imp_GetFriendlyIfIndex' as GetFriendlyIfIndex:qword
    extrn '__imp_GetIcmpStatistics' as GetIcmpStatistics:qword
    extrn '__imp_GetIcmpStatisticsEx' as GetIcmpStatisticsEx:qword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp_GetIcmpStatsFromStack' as GetIcmpStatsFromStack:qword
        extrn '__imp_GetIcmpStatsFromStackEx' as GetIcmpStatsFromStackEx:qword
        extrn '__imp_GetIfEntryFromStack' as GetIfEntryFromStack:qword
    end if
    extrn '__imp_GetIfEntry' as GetIfEntry:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetIfEntry2' as GetIfEntry2:qword
        extrn '__imp_GetIfStackTable' as GetIfStackTable:qword
    end if
    extrn '__imp_GetIfTable' as GetIfTable:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetIfTable2' as GetIfTable2:qword
        extrn '__imp_GetIfTable2Ex' as GetIfTable2Ex:qword
        extrn '__imp_GetInvertedIfStackTable' as GetInvertedIfStackTable:qword
    end if
    extrn '__imp_GetInterfaceInfo' as GetInterfaceInfo:qword
    extrn '__imp_GetIpAddrTable' as GetIpAddrTable:qword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp_GetIpAddrTableFromStack' as GetIpAddrTableFromStack:qword
        extrn '__imp_GetIpForwardTableFromStack' as GetIpForwardTableFromStack:qword
    end if
    extrn '__imp_GetIpErrorString' as GetIpErrorString:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetIpForwardEntry2' as GetIpForwardEntry2:qword
        extrn '__imp_GetIpForwardTable2' as GetIpForwardTable2:qword
        extrn '__imp_GetIpInterfaceEntry' as GetIpInterfaceEntry:qword
        extrn '__imp_GetIpInterfaceTable' as GetIpInterfaceTable:qword
        extrn '__imp_GetIpNetEntry2' as GetIpNetEntry2:qword
        extrn '__imp_GetIpNetTable2' as GetIpNetTable2:qword
    end if
    extrn '__imp_GetIpForwardTable' as GetIpForwardTable:qword
    extrn '__imp_GetIpNetTable' as GetIpNetTable:qword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp_GetIpNetTableFromStack' as GetIpNetTableFromStack:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_GetIpNetworkConnectionBandwidthEstimates' as GetIpNetworkConnectionBandwidthEstimates:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetIpPathEntry' as GetIpPathEntry:qword
        extrn '__imp_GetIpPathTable' as GetIpPathTable:qword
    end if
    extrn '__imp_GetIpStatistics' as GetIpStatistics:qword
    extrn '__imp_GetIpStatisticsEx' as GetIpStatisticsEx:qword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp_GetIpStatsFromStack' as GetIpStatsFromStack:qword
        extrn '__imp_GetIpStatsFromStackEx' as GetIpStatsFromStackEx:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetMulticastIpAddressEntry' as GetMulticastIpAddressEntry:qword
        extrn '__imp_GetMulticastIpAddressTable' as GetMulticastIpAddressTable:qword
        extrn '__imp_GetNetworkInformation' as GetNetworkInformation:qword
    end if
    extrn '__imp_GetNetworkParams' as GetNetworkParams:qword
    extrn '__imp_GetNumberOfInterfaces' as GetNumberOfInterfaces:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetOwnerModuleFromPidAndInfo' as GetOwnerModuleFromPidAndInfo:qword
    end if
    extrn '__imp_GetOwnerModuleFromTcp6Entry' as GetOwnerModuleFromTcp6Entry:qword
    extrn '__imp_GetOwnerModuleFromTcpEntry' as GetOwnerModuleFromTcpEntry:qword
    extrn '__imp_GetOwnerModuleFromUdp6Entry' as GetOwnerModuleFromUdp6Entry:qword
    extrn '__imp_GetOwnerModuleFromUdpEntry' as GetOwnerModuleFromUdpEntry:qword
    extrn '__imp_GetPerAdapterInfo' as GetPerAdapterInfo:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetPerTcp6ConnectionEStats' as GetPerTcp6ConnectionEStats:qword
        extrn '__imp_GetPerTcp6ConnectionStats' as GetPerTcp6ConnectionStats:qword
        extrn '__imp_GetPerTcpConnectionEStats' as GetPerTcpConnectionEStats:qword
        extrn '__imp_GetPerTcpConnectionStats' as GetPerTcpConnectionStats:qword
    end if
    extrn '__imp_GetRTTAndHopCount' as GetRTTAndHopCount:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetSessionCompartmentId' as GetSessionCompartmentId:qword
        extrn '__imp_GetTcp6Table' as GetTcp6Table:qword
        extrn '__imp_GetTcp6Table2' as GetTcp6Table2:qword
    end if
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp_GetTcpExTable2FromStack' as GetTcpExTable2FromStack:qword
        extrn '__imp_GetTcpStatsFromStack' as GetTcpStatsFromStack:qword
        extrn '__imp_GetTcpTableFromStack' as GetTcpTableFromStack:qword
    end if
    extrn '__imp_GetTcpStatistics' as GetTcpStatistics:qword
    extrn '__imp_GetTcpStatisticsEx' as GetTcpStatisticsEx:qword
    extrn '__imp_GetTcpTable' as GetTcpTable:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetTcpTable2' as GetTcpTable2:qword
        extrn '__imp_GetTeredoPort' as GetTeredoPort:qword
        extrn '__imp_GetUdp6Table' as GetUdp6Table:qword
    end if
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp_GetUdpExTable2FromStack' as GetUdpExTable2FromStack:qword
    end if
    extrn '__imp_GetUdpStatistics' as GetUdpStatistics:qword
    extrn '__imp_GetUdpStatisticsEx' as GetUdpStatisticsEx:qword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp_GetUdpStatsFromStack' as GetUdpStatsFromStack:qword
        extrn '__imp_GetUdpStatsFromStackEx' as GetUdpStatsFromStackEx:qword
        extrn '__imp_GetUdpTableFromStack' as GetUdpTableFromStack:qword
    end if
    extrn '__imp_GetUdpTable' as GetUdpTable:qword
    extrn '__imp_GetUniDirectionalAdapterInfo' as GetUniDirectionalAdapterInfo:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetUnicastIpAddressEntry' as GetUnicastIpAddressEntry:qword
        extrn '__imp_GetUnicastIpAddressTable' as GetUnicastIpAddressTable:qword
    end if
    extrn '__imp_Icmp6CreateFile' as Icmp6CreateFile:qword
    extrn '__imp_Icmp6ParseReplies' as Icmp6ParseReplies:qword
    extrn '__imp_Icmp6SendEcho2' as Icmp6SendEcho2:qword
    extrn '__imp_IcmpCloseHandle' as IcmpCloseHandle:qword
    extrn '__imp_IcmpCreateFile' as IcmpCreateFile:qword
    extrn '__imp_IcmpParseReplies' as IcmpParseReplies:qword
    extrn '__imp_IcmpSendEcho' as IcmpSendEcho:qword
    extrn '__imp_IcmpSendEcho2' as IcmpSendEcho2:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_IcmpSendEcho2Ex' as IcmpSendEcho2Ex:qword
        extrn '__imp_if_indextoname' as if_indextoname:qword
        extrn '__imp_if_nametoindex' as if_nametoindex:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp_InitializeCompartmentEntry' as InitializeCompartmentEntry:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_InitializeIpForwardEntry' as InitializeIpForwardEntry:qword
        extrn '__imp_InitializeIpInterfaceEntry' as InitializeIpInterfaceEntry:qword
        extrn '__imp_InitializeUnicastIpAddressEntry' as InitializeUnicastIpAddressEntry:qword
        extrn '__imp_InternalCleanupPersistentStore' as InternalCleanupPersistentStore:qword
        extrn '__imp_InternalCreateAnycastIpAddressEntry' as InternalCreateAnycastIpAddressEntry:qword
        extrn '__imp_InternalCreateIpForwardEntry2' as InternalCreateIpForwardEntry2:qword
        extrn '__imp_InternalCreateIpNetEntry2' as InternalCreateIpNetEntry2:qword
        extrn '__imp_InternalCreateUnicastIpAddressEntry' as InternalCreateUnicastIpAddressEntry:qword
        extrn '__imp_InternalDeleteAnycastIpAddressEntry' as InternalDeleteAnycastIpAddressEntry:qword
        extrn '__imp_InternalDeleteIpForwardEntry2' as InternalDeleteIpForwardEntry2:qword
    end if
    extrn '__imp_InternalCreateIpNetEntry' as InternalCreateIpNetEntry:qword
    extrn '__imp_InternalCreateIpForwardEntry' as InternalCreateIpForwardEntry:qword
    extrn '__imp_InternalDeleteIpForwardEntry' as InternalDeleteIpForwardEntry:qword
    extrn '__imp_InternalDeleteIpNetEntry' as InternalDeleteIpNetEntry:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_InternalDeleteIpNetEntry2' as InternalDeleteIpNetEntry2:qword
        extrn '__imp_InternalDeleteUnicastIpAddressEntry' as InternalDeleteUnicastIpAddressEntry:qword
        extrn '__imp_InternalFindInterfaceByAddress' as InternalFindInterfaceByAddress:qword
        extrn '__imp_InternalGetAnycastIpAddressEntry' as InternalGetAnycastIpAddressEntry:qword
        extrn '__imp_InternalGetAnycastIpAddressTable' as InternalGetAnycastIpAddressTable:qword
        extrn '__imp_InternalGetForwardIpTable2' as InternalGetForwardIpTable2:qword
        extrn '__imp_InternalGetIfEntry2' as InternalGetIfEntry2:qword
        extrn '__imp_InternalGetIfTable2' as InternalGetIfTable2:qword
        extrn '__imp_InternalGetIpForwardEntry2' as InternalGetIpForwardEntry2:qword
        extrn '__imp_InternalGetIpInterfaceEntry' as InternalGetIpInterfaceEntry:qword
        extrn '__imp_InternalGetIpInterfaceTable' as InternalGetIpInterfaceTable:qword
        extrn '__imp_InternalGetIpNetEntry2' as InternalGetIpNetEntry2:qword
        extrn '__imp_InternalGetIpNetTable2' as InternalGetIpNetTable2:qword
    end if
    extrn '__imp_InternalGetIfTable' as InternalGetIfTable:qword
    extrn '__imp_InternalGetIpAddrTable' as InternalGetIpAddrTable:qword
    extrn '__imp_InternalGetIpForwardTable' as InternalGetIpForwardTable:qword
    extrn '__imp_InternalGetIpNetTable' as InternalGetIpNetTable:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_InternalGetMulticastIpAddressEntry' as InternalGetMulticastIpAddressEntry:qword
        extrn '__imp_InternalGetMulticastIpAddressTable' as InternalGetMulticastIpAddressTable:qword
        extrn '__imp_InternalGetTcp6Table2' as InternalGetTcp6Table2:qword
        extrn '__imp_InternalGetTcp6TableWithOwnerModule' as InternalGetTcp6TableWithOwnerModule:qword
        extrn '__imp_InternalGetTcp6TableWithOwnerPid' as InternalGetTcp6TableWithOwnerPid:qword
    end if
    extrn '__imp_InternalGetTcpTable' as InternalGetTcpTable:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_InternalGetTcpTable2' as InternalGetTcpTable2:qword
        extrn '__imp_InternalGetTcpTableEx' as InternalGetTcpTableEx:qword
        extrn '__imp_InternalGetTcpTableWithOwnerModule' as InternalGetTcpTableWithOwnerModule:qword
        extrn '__imp_InternalGetTcpTableWithOwnerPid' as InternalGetTcpTableWithOwnerPid:qword
        extrn '__imp_InternalGetTunnelPhysicalAdapter' as InternalGetTunnelPhysicalAdapter:qword
        extrn '__imp_InternalGetUdp6TableWithOwnerModule' as InternalGetUdp6TableWithOwnerModule:qword
        extrn '__imp_InternalGetUdp6TableWithOwnerPid' as InternalGetUdp6TableWithOwnerPid:qword
    end if
    extrn '__imp_InternalGetUdpTable' as InternalGetUdpTable:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_InternalGetUdpTableEx' as InternalGetUdpTableEx:qword
        extrn '__imp_InternalGetUdpTableWithOwnerModule' as InternalGetUdpTableWithOwnerModule:qword
        extrn '__imp_InternalGetUdpTableWithOwnerPid' as InternalGetUdpTableWithOwnerPid:qword
        extrn '__imp_InternalGetUnicastIpAddressEntry' as InternalGetUnicastIpAddressEntry:qword
        extrn '__imp_InternalGetUnicastIpAddressTable' as InternalGetUnicastIpAddressTable:qword
    end if
    extrn '__imp_InternalSetIfEntry' as InternalSetIfEntry:qword
    extrn '__imp_InternalSetIpForwardEntry' as InternalSetIpForwardEntry:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_InternalSetIpForwardEntry2' as InternalSetIpForwardEntry2:qword
        extrn '__imp_InternalSetIpInterfaceEntry' as InternalSetIpInterfaceEntry:qword
        extrn '__imp_InternalSetIpNetEntry2' as InternalSetIpNetEntry2:qword
    end if
    extrn '__imp_InternalSetIpNetEntry' as InternalSetIpNetEntry:qword
    extrn '__imp_InternalSetIpStats' as InternalSetIpStats:qword
    extrn '__imp_InternalSetTcpEntry' as InternalSetTcpEntry:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_InternalSetTeredoPort' as InternalSetTeredoPort:qword
        extrn '__imp_InternalSetUnicastIpAddressEntry' as InternalSetUnicastIpAddressEntry:qword
    end if
    extrn '__imp_IpReleaseAddress' as IpReleaseAddress:qword
    extrn '__imp_IpRenewAddress' as IpRenewAddress:qword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp_IsLocalAddress' as IsLocalAddress:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_LookupPersistentTcpPortReservation' as LookupPersistentTcpPortReservation:qword
        extrn '__imp_LookupPersistentUdpPortReservation' as LookupPersistentUdpPortReservation:qword
        extrn '__imp_NhGetInterfaceDescriptionFromGuid' as NhGetInterfaceDescriptionFromGuid:qword
        extrn '__imp_NhGetInterfaceNameFromGuid' as NhGetInterfaceNameFromGuid:qword
    end if
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp_NhpGetInterfaceIndexFromStack' as NhpGetInterfaceIndexFromStack:qword
    end if
    extrn '__imp_NhGetGuidFromInterfaceName' as NhGetGuidFromInterfaceName:qword
    extrn '__imp_NhGetInterfaceNameFromDeviceGuid' as NhGetInterfaceNameFromDeviceGuid:qword
    extrn '__imp_NhpAllocateAndGetInterfaceInfoFromStack' as NhpAllocateAndGetInterfaceInfoFromStack:qword
    extrn '__imp_NotifyAddrChange' as NotifyAddrChange:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_NotifyIpInterfaceChange' as NotifyIpInterfaceChange:qword
        extrn '__imp_NotifyRouteChange2' as NotifyRouteChange2:qword
    end if
    extrn '__imp_NotifyRouteChange' as NotifyRouteChange:qword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp_NotifyRouteChangeEx' as NotifyRouteChangeEx:qword
        extrn '__imp_NotifySecurityHealthChange' as NotifySecurityHealthChange:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_NotifyStableUnicastIpAddressTable' as NotifyStableUnicastIpAddressTable:qword
        extrn '__imp_NotifyTeredoPortChange' as NotifyTeredoPortChange:qword
        extrn '__imp_NotifyUnicastIpAddressChange' as NotifyUnicastIpAddressChange:qword
    end if
    extrn '__imp_NTPTimeToNTFileTime' as NTPTimeToNTFileTime:qword
    extrn '__imp_NTTimeToNTPTime' as NTTimeToNTPTime:qword
    extrn '__imp_ParseNetworkString' as ParseNetworkString:qword
    if (NTDDI_VERSION <> NTDDI_VISTA)
        extrn '__imp_PfAddFiltersToInterface' as PfAddFiltersToInterface:qword
        extrn '__imp_PfAddGlobalFilterToInterface' as PfAddGlobalFilterToInterface:qword
        extrn '__imp_PfBindInterfaceToIndex' as PfBindInterfaceToIndex:qword
        extrn '__imp_PfBindInterfaceToIPAddress' as PfBindInterfaceToIPAddress:qword
        extrn '__imp_PfCreateInterface' as PfCreateInterface:qword
        extrn '__imp_PfDeleteInterface' as PfDeleteInterface:qword
        extrn '__imp_PfDeleteLog' as PfDeleteLog:qword
        extrn '__imp_PfGetInterfaceStatistics' as PfGetInterfaceStatistics:qword
        extrn '__imp_PfMakeLog' as PfMakeLog:qword
        extrn '__imp_PfRebindFilters' as PfRebindFilters:qword
        extrn '__imp_PfRemoveFilterHandles' as PfRemoveFilterHandles:qword
        extrn '__imp_PfRemoveFiltersFromInterface' as PfRemoveFiltersFromInterface:qword
        extrn '__imp_PfRemoveGlobalFilterFromInterface' as PfRemoveGlobalFilterFromInterface:qword
        extrn '__imp_PfSetLogBuffer' as PfSetLogBuffer:qword
        extrn '__imp_PfTestPacket' as PfTestPacket:qword
        extrn '__imp_PfUnBindInterface' as PfUnBindInterface:qword
    end if
    extrn '__imp_register_icmp' as register_icmp:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_ResolveIpNetEntry2' as ResolveIpNetEntry2:qword
        extrn '__imp_ResolveNeighbor' as ResolveNeighbor:qword
    end if
    extrn '__imp_RestoreMediaSense' as RestoreMediaSense:qword
    extrn '__imp_SendARP' as SendARP:qword
    extrn '__imp_SetAdapterIpAddress' as SetAdapterIpAddress:qword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp_SetBlockRoutes' as SetBlockRoutes:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_SetCurrentThreadCompartmentId' as SetCurrentThreadCompartmentId:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp_SetCurrentThreadCompartmentScope' as SetCurrentThreadCompartmentScope:qword
    end if
    extrn '__imp_SetIfEntry' as SetIfEntry:qword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp_SetIfEntryToStack' as SetIfEntryToStack:qword
        extrn '__imp_SetIpForwardEntryToStack' as SetIpForwardEntryToStack:qword
        extrn '__imp_SetIpMultihopRouteEntryToStack' as SetIpMultihopRouteEntryToStack:qword
        extrn '__imp_SetIpNetEntryToStack' as SetIpNetEntryToStack:qword
        extrn '__imp_SetIpRouteEntryToStack' as SetIpRouteEntryToStack:qword
        extrn '__imp_SetIpStatsToStack' as SetIpStatsToStack:qword
    end if
    extrn '__imp_SetIpForwardEntry' as SetIpForwardEntry:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_SetIpForwardEntry2' as SetIpForwardEntry2:qword
        extrn '__imp_SetIpInterfaceEntry' as SetIpInterfaceEntry:qword
        extrn '__imp_SetIpNetEntry2' as SetIpNetEntry2:qword
        extrn '__imp_SetIpStatisticsEx' as SetIpStatisticsEx:qword
    end if
    extrn '__imp_SetIpNetEntry' as SetIpNetEntry:qword
    extrn '__imp_SetIpStatistics' as SetIpStatistics:qword
    extrn '__imp_SetIpTTL' as SetIpTTL:qword
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp_SetJobCompartmentId' as SetJobCompartmentId:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_SetNetworkInformation' as SetNetworkInformation:qword
        extrn '__imp_SetPerTcp6ConnectionEStats' as SetPerTcp6ConnectionEStats:qword
        extrn '__imp_SetPerTcp6ConnectionStats' as SetPerTcp6ConnectionStats:qword
        extrn '__imp_SetPerTcpConnectionEStats' as SetPerTcpConnectionEStats:qword
        extrn '__imp_SetPerTcpConnectionStats' as SetPerTcpConnectionStats:qword
    end if
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp_SetProxyArpEntryToStack' as SetProxyArpEntryToStack:qword
        extrn '__imp_SetRouteWithRef' as SetRouteWithRef:qword
        extrn '__imp_SetTcpEntryToStack' as SetTcpEntryToStack:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_SetSessionCompartmentId' as SetSessionCompartmentId:qword
        extrn '__imp_SetUnicastIpAddressEntry' as SetUnicastIpAddressEntry:qword
    end if
    extrn '__imp_SetTcpEntry' as SetTcpEntry:qword
    extrn '__imp_UnenableRouter' as UnenableRouter:qword
else
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp___PfAddFiltersToInterface@24' as _PfAddFiltersToInterface:dword
        extrn '__imp___PfAddGlobalFilterToInterface@8' as _PfAddGlobalFilterToInterface:dword
        extrn '__imp___PfBindInterfaceToIndex@16' as _PfBindInterfaceToIndex:dword
        extrn '__imp___PfBindInterfaceToIPAddress@12' as _PfBindInterfaceToIPAddress:dword
        extrn '__imp___PfCreateInterface@24' as _PfCreateInterface:dword
        extrn '__imp___PfDeleteInterface@4' as _PfDeleteInterface:dword
        extrn '__imp___PfDeleteLog@0' as _PfDeleteLog:dword
        extrn '__imp___PfGetInterfaceStatistics@16' as _PfGetInterfaceStatistics:dword
        extrn '__imp___PfMakeLog@4' as _PfMakeLog:dword
        extrn '__imp___PfRebindFilters@8' as _PfRebindFilters:dword
        extrn '__imp___PfRemoveFilterHandles@12' as _PfRemoveFilterHandles:dword
        extrn '__imp___PfRemoveFiltersFromInterface@20' as _PfRemoveFiltersFromInterface:dword
        extrn '__imp___PfRemoveGlobalFilterFromInterface@8' as _PfRemoveGlobalFilterFromInterface:dword
        extrn '__imp___PfSetLogBuffer@28' as _PfSetLogBuffer:dword
        extrn '__imp___PfTestPacket@20' as _PfTestPacket:dword
        extrn '__imp___PfUnBindInterface@4' as _PfUnBindInterface:dword
    end if
    extrn '__imp__AddIPAddress@20' as AddIPAddress:dword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp__AllocateAndGetArpEntTableFromStack@20' as AllocateAndGetArpEntTableFromStack:dword
        extrn '__imp__AllocateAndGetIfTableFromStack@20' as AllocateAndGetIfTableFromStack:dword
        extrn '__imp__AllocateAndGetIpAddrTableFromStack@16' as AllocateAndGetIpAddrTableFromStack:dword
        extrn '__imp__AllocateAndGetIpForwardTableFromStack@16' as AllocateAndGetIpForwardTableFromStack:dword
        extrn '__imp__AllocateAndGetIpNetTableFromStack@20' as AllocateAndGetIpNetTableFromStack:dword
        extrn '__imp__AllocateAndGetTcpExTableFromStack@20' as AllocateAndGetTcpExTableFromStack:dword
        extrn '__imp__AllocateAndGetTcpExTable2FromStack@24' as AllocateAndGetTcpExTable2FromStack:dword
        extrn '__imp__AllocateAndGetTcpTableFromStack@16' as AllocateAndGetTcpTableFromStack:dword
        extrn '__imp__AllocateAndGetUdpExTable2FromStack@24' as AllocateAndGetUdpExTable2FromStack:dword
        extrn '__imp__AllocateAndGetUdpExTableFromStack@20' as AllocateAndGetUdpExTableFromStack:dword
        extrn '__imp__AllocateAndGetUdpTableFromStack@16' as AllocateAndGetUdpTableFromStack:dword
    end if
    extrn '__imp__CancelIPChangeNotify@4' as CancelIPChangeNotify:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__CancelMibChangeNotify2@4' as CancelMibChangeNotify2:dword
    end if
    if (NTDDI_VERSION >= NTDDI_WINXP)
        if (NTDDI_VERSION <= NTDDI_WS03ALL)
            extrn '__imp__CancelSecurityHealthChangeNotify@4' as CancelSecurityHealthChangeNotify:dword
        end if
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ConvertGuidToStringA@4' as ConvertGuidToStringA:dword
        extrn '__imp__ConvertGuidToStringW@4' as ConvertGuidToStringW:dword
    end if
    ;extrn '__imp__ConvertInterfaceAliasToLuid@8' as ConvertInterfaceAliasToLuid:dword  ;Not present in MASM32 iphlpapi.lib
    ;extrn '__imp__ConvertInterfaceGuidToLuid@8' as ConvertInterfaceGuidToLuid:dword    ;Not present in MASM32 iphlpapi.lib
    ;extrn '__imp__ConvertInterfaceIndexToLuid@8' as ConvertInterfaceIndexToLuid:dword  ;Not present in MASM32 iphlpapi.lib
    ;extrn '__imp__ConvertInterfaceLuidToAlias@12' as ConvertInterfaceLuidToAlias:dword ;Not present in MASM32 iphlpapi.lib
    ;extrn '__imp__ConvertInterfaceLuidToGuid@8' as ConvertInterfaceLuidToGuid:dword    ;Not present in MASM32 iphlpapi.lib
    ;extrn '__imp__ConvertInterfaceLuidToIndex@8' as ConvertInterfaceLuidToIndex:dword  ;Not present in MASM32 iphlpapi.lib
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ConvertInterfaceLuidToNameA@12' as ConvertInterfaceLuidToNameA:dword
        extrn '__imp__ConvertInterfaceLuidToNameW@12' as ConvertInterfaceLuidToNameW:dword
        extrn '__imp__ConvertInterfaceNameToLuidA@8' as ConvertInterfaceNameToLuidA:dword
        extrn '__imp__ConvertInterfaceNameToLuidW@8' as ConvertInterfaceNameToLuidW:dword
        extrn '__imp__ConvertInterfacePhysicalAddressToLuid@12' as ConvertInterfacePhysicalAddressToLuid:dword
        extrn '__imp__ConvertIpv4MaskToLength@8' as ConvertIpv4MaskToLength:dword
        extrn '__imp__ConvertLengthToIpv4Mask@8' as ConvertLengthToIpv4Mask:dword
        extrn '__imp__ConvertRemoteInterfaceAliasToLuid@12' as ConvertRemoteInterfaceAliasToLuid:dword
        extrn '__imp__ConvertRemoteInterfaceGuidToLuid@12' as ConvertRemoteInterfaceGuidToLuid:dword
        extrn '__imp__ConvertRemoteInterfaceIndexToLuid@12' as ConvertRemoteInterfaceIndexToLuid:dword
        extrn '__imp__ConvertRemoteInterfaceLuidToAlias@16' as ConvertRemoteInterfaceLuidToAlias:dword
        extrn '__imp__ConvertRemoteInterfaceLuidToGuid@12' as ConvertRemoteInterfaceLuidToGuid:dword
        extrn '__imp__ConvertRemoteInterfaceLuidToIndex@12' as ConvertRemoteInterfaceLuidToIndex:dword
        extrn '__imp__ConvertStringToGuidA@8' as ConvertStringToGuidA:dword
        extrn '__imp__ConvertStringToGuidW@8' as ConvertStringToGuidW:dword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp__ConvertStringToInterfacePhysicalAddress@8' as ConvertStringToInterfacePhysicalAddress:dword
        extrn '__imp__CPNatfwtCreateProviderInstance@20' as CPNatfwtCreateProviderInstance:dword
        extrn '__imp__CPNatfwtDeregisterProviderInstance@4' as CPNatfwtDeregisterProviderInstance:dword
        extrn '__imp__CPNatfwtDestroyProviderInstance@4' as CPNatfwtDestroyProviderInstance:dword
        extrn '__imp__CPNatfwtIndicateReceivedBuffers@24' as CPNatfwtIndicateReceivedBuffers:dword
        extrn '__imp__CPNatfwtRegisterProviderInstance@20' as CPNatfwtRegisterProviderInstance:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__CreateAnycastIpAddressEntry@4' as CreateAnycastIpAddressEntry:dword
        extrn '__imp__CreateIpForwardEntry2@4' as CreateIpForwardEntry2:dword
        extrn '__imp__CreateIpNetEntry2@4' as CreateIpNetEntry2:dword
    end if
    extrn '__imp__CreateIpForwardEntry@4' as CreateIpForwardEntry:dword
    extrn '__imp__CreateIpNetEntry@4' as CreateIpNetEntry:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__CreatePersistentTcpPortReservation@12' as CreatePersistentTcpPortReservation:dword
        extrn '__imp__CreatePersistentUdpPortReservation@12' as CreatePersistentUdpPortReservation:dword
    end if
    extrn '__imp__CreateProxyArpEntry@12' as CreateProxyArpEntry:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__CreateSortedAddressPairs@28' as CreateSortedAddressPairs:dword
        extrn '__imp__CreateUnicastIpAddressEntry@4' as CreateUnicastIpAddressEntry:dword
        extrn '__imp__DeleteAnycastIpAddressEntry@4' as DeleteAnycastIpAddressEntry:dword
    end if
    extrn '__imp__DeleteIPAddress@4' as DeleteIPAddress:dword
    extrn '__imp__DeleteIpForwardEntry@4' as DeleteIpForwardEntry:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__DeleteIpForwardEntry2@4' as DeleteIpForwardEntry2:dword
        extrn '__imp__DeleteIpNetEntry2@4' as DeleteIpNetEntry2:dword
    end if
    extrn '__imp__DeleteIpNetEntry@4' as DeleteIpNetEntry:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__DeletePersistentTcpPortReservation@8' as DeletePersistentTcpPortReservation:dword
        extrn '__imp__DeletePersistentUdpPortReservation@8' as DeletePersistentUdpPortReservation:dword
        extrn '__imp__DeleteUnicastIpAddressEntry@4' as DeleteUnicastIpAddressEntry:dword
    end if
    extrn '__imp__DeleteProxyArpEntry@12' as DeleteProxyArpEntry:dword
    extrn '__imp__DisableMediaSense@8' as DisableMediaSense:dword
    extrn '__imp__do_echo_rep@40' as do_echo_rep:dword
    extrn '__imp__do_echo_req@40' as do_echo_req:dword
    extrn '__imp__EnableRouter@8' as EnableRouter:dword
    extrn '__imp__FlushIpNetTable@4' as FlushIpNetTable:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__FlushIpNetTable2@8' as FlushIpNetTable2:dword
        extrn '__imp__FlushIpPathTable@4' as FlushIpPathTable:dword
        extrn '__imp__FreeMibTable@4' as FreeMibTable:dword
    end if
    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp__FlushIpNetTableFromStack@4' as FlushIpNetTableFromStack:dword
    end if
    extrn '__imp__GetAdapterIndex@8' as GetAdapterIndex:dword
    extrn '__imp__GetAdapterOrderMap@0' as GetAdapterOrderMap:dword
    extrn '__imp__GetAdaptersAddresses@20' as GetAdaptersAddresses:dword
    extrn '__imp__GetAdaptersInfo@8' as GetAdaptersInfo:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__GetAnycastIpAddressEntry@4' as GetAnycastIpAddressEntry:dword
        extrn '__imp__GetAnycastIpAddressTable@8' as GetAnycastIpAddressTable:dword
    end if
    extrn '__imp__GetBestInterface@8' as GetBestInterface:dword
    extrn '__imp__GetBestInterfaceEx@8' as GetBestInterfaceEx:dword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp__GetBestInterfaceFromStack@8' as GetBestInterfaceFromStack:dword
    end if
    extrn '__imp__GetBestRoute@12' as GetBestRoute:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__GetBestRoute2@28' as GetBestRoute2:dword
    end if
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp__GetBestRouteFromStack@12' as GetBestRouteFromStack:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__GetCurrentThreadCompartmentId@0' as GetCurrentThreadCompartmentId:dword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp__GetCurrentThreadCompartmentScope@8' as GetCurrentThreadCompartmentScope:dword
    end if
    extrn '__imp__GetExtendedTcpTable@24' as GetExtendedTcpTable:dword
    extrn '__imp__GetExtendedUdpTable@24' as GetExtendedUdpTable:dword
    extrn '__imp__GetFriendlyIfIndex@4' as GetFriendlyIfIndex:dword
    extrn '__imp__GetIcmpStatistics@4' as GetIcmpStatistics:dword
    extrn '__imp__GetIcmpStatisticsEx@8' as GetIcmpStatisticsEx:dword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp__GetIcmpStatsFromStack@4' as GetIcmpStatsFromStack:dword
        extrn '__imp__GetIcmpStatsFromStackEx@8' as GetIcmpStatsFromStackEx:dword
        extrn '__imp__GetIfEntryFromStack@12' as GetIfEntryFromStack:dword
    end if
    extrn '__imp__GetIfEntry@4' as GetIfEntry:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__GetIfEntry2@4' as GetIfEntry2:dword
        extrn '__imp__GetIfStackTable@4' as GetIfStackTable:dword
    end if
    extrn '__imp__GetIfTable@12' as GetIfTable:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__GetIfTable2@4' as GetIfTable2:dword
        extrn '__imp__GetIfTable2Ex@8' as GetIfTable2Ex:dword
        extrn '__imp__GetInvertedIfStackTable@4' as GetInvertedIfStackTable:dword
    end if
    extrn '__imp__GetInterfaceInfo@8' as GetInterfaceInfo:dword
    extrn '__imp__GetIpAddrTable@12' as GetIpAddrTable:dword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp__GetIpAddrTableFromStack@12' as GetIpAddrTableFromStack:dword
        extrn '__imp__GetIpForwardTableFromStack@12' as GetIpForwardTableFromStack:dword
    end if
    extrn '__imp__GetIpErrorString@12' as GetIpErrorString:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__GetIpForwardEntry2@4' as GetIpForwardEntry2:dword
        extrn '__imp__GetIpForwardTable2@8' as GetIpForwardTable2:dword
        extrn '__imp__GetIpInterfaceEntry@4' as GetIpInterfaceEntry:dword
        extrn '__imp__GetIpInterfaceTable@8' as GetIpInterfaceTable:dword
        extrn '__imp__GetIpNetEntry2@4' as GetIpNetEntry2:dword
        extrn '__imp__GetIpNetTable2@8' as GetIpNetTable2:dword
    end if
    extrn '__imp__GetIpForwardTable@12' as GetIpForwardTable:dword
    extrn '__imp__GetIpNetTable@12' as GetIpNetTable:dword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp__GetIpNetTableFromStack@16' as GetIpNetTableFromStack:dword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__GetIpNetworkConnectionBandwidthEstimates@12' as GetIpNetworkConnectionBandwidthEstimates:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__GetIpPathEntry@4' as GetIpPathEntry:dword
        extrn '__imp__GetIpPathTable@8' as GetIpPathTable:dword
    end if
    extrn '__imp__GetIpStatistics@4' as GetIpStatistics:dword
    extrn '__imp__GetIpStatisticsEx@8' as GetIpStatisticsEx:dword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp__GetIpStatsFromStack@4' as GetIpStatsFromStack:dword
        extrn '__imp__GetIpStatsFromStackEx@8' as GetIpStatsFromStackEx:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__GetMulticastIpAddressEntry@4' as GetMulticastIpAddressEntry:dword
        extrn '__imp__GetMulticastIpAddressTable@8' as GetMulticastIpAddressTable:dword
        extrn '__imp__GetNetworkInformation@20' as GetNetworkInformation:dword
    end if
    extrn '__imp__GetNetworkParams@8' as GetNetworkParams:dword
    extrn '__imp__GetNumberOfInterfaces@4' as GetNumberOfInterfaces:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__GetOwnerModuleFromPidAndInfo@20' as GetOwnerModuleFromPidAndInfo:dword
    end if
    extrn '__imp__GetOwnerModuleFromTcp6Entry@16' as GetOwnerModuleFromTcp6Entry:dword
    extrn '__imp__GetOwnerModuleFromTcpEntry@16' as GetOwnerModuleFromTcpEntry:dword
    extrn '__imp__GetOwnerModuleFromUdp6Entry@16' as GetOwnerModuleFromUdp6Entry:dword
    extrn '__imp__GetOwnerModuleFromUdpEntry@16' as GetOwnerModuleFromUdpEntry:dword
    extrn '__imp__GetPerAdapterInfo@12' as GetPerAdapterInfo:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__GetPerTcp6ConnectionEStats@44' as GetPerTcp6ConnectionEStats:dword
        extrn '__imp__GetPerTcp6ConnectionStats@32' as GetPerTcp6ConnectionStats:dword
        extrn '__imp__GetPerTcpConnectionEStats@44' as GetPerTcpConnectionEStats:dword
        extrn '__imp__GetPerTcpConnectionStats@32' as GetPerTcpConnectionStats:dword
    end if
    extrn '__imp__GetRTTAndHopCount@16' as GetRTTAndHopCount:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__GetSessionCompartmentId@4' as GetSessionCompartmentId:dword
        extrn '__imp__GetTcp6Table@12' as GetTcp6Table:dword
        extrn '__imp__GetTcp6Table2@12' as GetTcp6Table2:dword
    end if
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp__GetTcpExTable2FromStack@20' as GetTcpExTable2FromStack:dword
        extrn '__imp__GetTcpStatsFromStack@4' as GetTcpStatsFromStack:dword
        extrn '__imp__GetTcpTableFromStack@12' as GetTcpTableFromStack:dword
    end if
    extrn '__imp__GetTcpStatistics@4' as GetTcpStatistics:dword
    extrn '__imp__GetTcpStatisticsEx@8' as GetTcpStatisticsEx:dword
    extrn '__imp__GetTcpTable@12' as GetTcpTable:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__GetTcpTable2@12' as GetTcpTable2:dword
        extrn '__imp__GetTeredoPort@4' as GetTeredoPort:dword
        extrn '__imp__GetUdp6Table@12' as GetUdp6Table:dword
    end if
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp__GetUdpExTable2FromStack@20' as GetUdpExTable2FromStack:dword
    end if
    extrn '__imp__GetUdpStatistics@4' as GetUdpStatistics:dword
    extrn '__imp__GetUdpStatisticsEx@8' as GetUdpStatisticsEx:dword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp__GetUdpStatsFromStack@4' as GetUdpStatsFromStack:dword
        extrn '__imp__GetUdpStatsFromStackEx@8' as GetUdpStatsFromStackEx:dword
        extrn '__imp__GetUdpTableFromStack@12' as GetUdpTableFromStack:dword
    end if
    extrn '__imp__GetUdpTable@12' as GetUdpTable:dword
    extrn '__imp__GetUniDirectionalAdapterInfo@8' as GetUniDirectionalAdapterInfo:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__GetUnicastIpAddressEntry@4' as GetUnicastIpAddressEntry:dword
        extrn '__imp__GetUnicastIpAddressTable@4' as GetUnicastIpAddressTable:dword
    end if
    extrn '__imp__Icmp6CreateFile@0' as Icmp6CreateFile:dword
    extrn '__imp__Icmp6ParseReplies@8' as Icmp6ParseReplies:dword
    extrn '__imp__Icmp6SendEcho2@48' as Icmp6SendEcho2:dword
    extrn '__imp__IcmpCloseHandle@4' as IcmpCloseHandle:dword
    extrn '__imp__IcmpCreateFile@0' as IcmpCreateFile:dword
    extrn '__imp__IcmpParseReplies@8' as IcmpParseReplies:dword
    extrn '__imp__IcmpSendEcho@32' as IcmpSendEcho:dword
    extrn '__imp__IcmpSendEcho2@44' as IcmpSendEcho2:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__IcmpSendEcho2Ex@48' as IcmpSendEcho2Ex:dword
        extrn '__imp__if_indextoname@8' as if_indextoname:dword
        extrn '__imp__if_nametoindex@4' as if_nametoindex:dword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp__InitializeCompartmentEntry@4' as InitializeCompartmentEntry:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__InitializeIpForwardEntry@4' as InitializeIpForwardEntry:dword
        extrn '__imp__InitializeIpInterfaceEntry@4' as InitializeIpInterfaceEntry:dword
        extrn '__imp__InitializeUnicastIpAddressEntry@4' as InitializeUnicastIpAddressEntry:dword
        extrn '__imp__InternalCleanupPersistentStore@8' as InternalCleanupPersistentStore:dword
        extrn '__imp__InternalCreateAnycastIpAddressEntry@8' as InternalCreateAnycastIpAddressEntry:dword
        extrn '__imp__InternalCreateIpForwardEntry2@8' as InternalCreateIpForwardEntry2:dword
        extrn '__imp__InternalCreateIpNetEntry2@8' as InternalCreateIpNetEntry2:dword
        extrn '__imp__InternalCreateUnicastIpAddressEntry@8' as InternalCreateUnicastIpAddressEntry:dword
        extrn '__imp__InternalDeleteAnycastIpAddressEntry@8' as InternalDeleteAnycastIpAddressEntry:dword
        extrn '__imp__InternalDeleteIpForwardEntry2@8' as InternalDeleteIpForwardEntry2:dword
    end if
    extrn '__imp__InternalCreateIpNetEntry@4' as InternalCreateIpNetEntry:dword
    extrn '__imp__InternalCreateIpForwardEntry@4' as InternalCreateIpForwardEntry:dword
    extrn '__imp__InternalDeleteIpForwardEntry@4' as InternalDeleteIpForwardEntry:dword
    extrn '__imp__InternalDeleteIpNetEntry@4' as InternalDeleteIpNetEntry:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__InternalDeleteIpNetEntry2@8' as InternalDeleteIpNetEntry2:dword
        extrn '__imp__InternalDeleteUnicastIpAddressEntry@8' as InternalDeleteUnicastIpAddressEntry:dword
        extrn '__imp__InternalFindInterfaceByAddress@8' as InternalFindInterfaceByAddress:dword
        extrn '__imp__InternalGetAnycastIpAddressEntry@8' as InternalGetAnycastIpAddressEntry:dword
        extrn '__imp__InternalGetAnycastIpAddressTable@12' as InternalGetAnycastIpAddressTable:dword
        extrn '__imp__InternalGetForwardIpTable2@12' as InternalGetForwardIpTable2:dword
        extrn '__imp__InternalGetIfEntry2@8' as InternalGetIfEntry2:dword
        extrn '__imp__InternalGetIfTable2@8' as InternalGetIfTable2:dword
        extrn '__imp__InternalGetIpForwardEntry2@8' as InternalGetIpForwardEntry2:dword
        extrn '__imp__InternalGetIpInterfaceEntry@8' as InternalGetIpInterfaceEntry:dword
        extrn '__imp__InternalGetIpInterfaceTable@12' as InternalGetIpInterfaceTable:dword
        extrn '__imp__InternalGetIpNetEntry2@8' as InternalGetIpNetEntry2:dword
        extrn '__imp__InternalGetIpNetTable2@12' as InternalGetIpNetTable2:dword
    end if
    extrn '__imp__InternalGetIfTable@12' as InternalGetIfTable:dword
    extrn '__imp__InternalGetIpAddrTable@12' as InternalGetIpAddrTable:dword
    extrn '__imp__InternalGetIpForwardTable@12' as InternalGetIpForwardTable:dword
    extrn '__imp__InternalGetIpNetTable@12' as InternalGetIpNetTable:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__InternalGetMulticastIpAddressEntry@8' as InternalGetMulticastIpAddressEntry:dword
        extrn '__imp__InternalGetMulticastIpAddressTable@12' as InternalGetMulticastIpAddressTable:dword
        extrn '__imp__InternalGetTcp6Table2@12' as InternalGetTcp6Table2:dword
        extrn '__imp__InternalGetTcp6TableWithOwnerModule@12' as InternalGetTcp6TableWithOwnerModule:dword
        extrn '__imp__InternalGetTcp6TableWithOwnerPid@12' as InternalGetTcp6TableWithOwnerPid:dword
    end if
    extrn '__imp__InternalGetTcpTable@12' as InternalGetTcpTable:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__InternalGetTcpTable2@12' as InternalGetTcpTable2:dword
        extrn '__imp__InternalGetTcpTableEx@12' as InternalGetTcpTableEx:dword
        extrn '__imp__InternalGetTcpTableWithOwnerModule@12' as InternalGetTcpTableWithOwnerModule:dword
        extrn '__imp__InternalGetTcpTableWithOwnerPid@12' as InternalGetTcpTableWithOwnerPid:dword
        extrn '__imp__InternalGetTunnelPhysicalAdapter@8' as InternalGetTunnelPhysicalAdapter:dword
        extrn '__imp__InternalGetUdp6TableWithOwnerModule@12' as InternalGetUdp6TableWithOwnerModule:dword
        extrn '__imp__InternalGetUdp6TableWithOwnerPid@12' as InternalGetUdp6TableWithOwnerPid:dword
    end if
    extrn '__imp__InternalGetUdpTable@12' as InternalGetUdpTable:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__InternalGetUdpTableEx@12' as InternalGetUdpTableEx:dword
        extrn '__imp__InternalGetUdpTableWithOwnerModule@12' as InternalGetUdpTableWithOwnerModule:dword
        extrn '__imp__InternalGetUdpTableWithOwnerPid@12' as InternalGetUdpTableWithOwnerPid:dword
        extrn '__imp__InternalGetUnicastIpAddressEntry@8' as InternalGetUnicastIpAddressEntry:dword
        extrn '__imp__InternalGetUnicastIpAddressTable@12' as InternalGetUnicastIpAddressTable:dword
    end if
    extrn '__imp__InternalSetIfEntry@4' as InternalSetIfEntry:dword
    extrn '__imp__InternalSetIpForwardEntry@4' as InternalSetIpForwardEntry:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__InternalSetIpForwardEntry2@8' as InternalSetIpForwardEntry2:dword
        extrn '__imp__InternalSetIpInterfaceEntry@8' as InternalSetIpInterfaceEntry:dword
        extrn '__imp__InternalSetIpNetEntry2@8' as InternalSetIpNetEntry2:dword
    end if
    extrn '__imp__InternalSetIpNetEntry@4' as InternalSetIpNetEntry:dword
    extrn '__imp__InternalSetIpStats@4' as InternalSetIpStats:dword
    extrn '__imp__InternalSetTcpEntry@4' as InternalSetTcpEntry:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__InternalSetTeredoPort@4' as InternalSetTeredoPort:dword
        extrn '__imp__InternalSetUnicastIpAddressEntry@8' as InternalSetUnicastIpAddressEntry:dword
    end if
    extrn '__imp__IpReleaseAddress@4' as IpReleaseAddress:dword
    extrn '__imp__IpRenewAddress@4' as IpRenewAddress:dword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp__IsLocalAddress@4' as IsLocalAddress:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__LookupPersistentTcpPortReservation@12' as LookupPersistentTcpPortReservation:dword
        extrn '__imp__LookupPersistentUdpPortReservation@12' as LookupPersistentUdpPortReservation:dword
        extrn '__imp__NhGetInterfaceDescriptionFromGuid@20' as NhGetInterfaceDescriptionFromGuid:dword
        extrn '__imp__NhGetInterfaceNameFromGuid@20' as NhGetInterfaceNameFromGuid:dword
    end if
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp__NhpGetInterfaceIndexFromStack@8' as NhpGetInterfaceIndexFromStack:dword
    end if
    extrn '__imp__NhGetGuidFromInterfaceName@16' as NhGetGuidFromInterfaceName:dword
    extrn '__imp__NhGetInterfaceNameFromDeviceGuid@20' as NhGetInterfaceNameFromDeviceGuid:dword
    extrn '__imp__NhpAllocateAndGetInterfaceInfoFromStack@20' as NhpAllocateAndGetInterfaceInfoFromStack:dword
    extrn '__imp__NotifyAddrChange@8' as NotifyAddrChange:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__NotifyIpInterfaceChange@20' as NotifyIpInterfaceChange:dword
        extrn '__imp__NotifyRouteChange2@20' as NotifyRouteChange2:dword
    end if
    extrn '__imp__NotifyRouteChange@8' as NotifyRouteChange:dword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp__NotifyRouteChangeEx@12' as NotifyRouteChangeEx:dword
        extrn '__imp__NotifySecurityHealthChange@12' as NotifySecurityHealthChange:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__NotifyStableUnicastIpAddressTable@20' as NotifyStableUnicastIpAddressTable:dword
        extrn '__imp__NotifyTeredoPortChange@16' as NotifyTeredoPortChange:dword
        extrn '__imp__NotifyUnicastIpAddressChange@20' as NotifyUnicastIpAddressChange:dword
    end if
    extrn '__imp__NTPTimeToNTFileTime@12' as NTPTimeToNTFileTime:dword
    extrn '__imp__NTTimeToNTPTime@8' as NTTimeToNTPTime:dword
    ;extrn '__imp__ParseNetworkString@20' as ParseNetworkString:dword ;Not present in MASM32 iphlpapi.lib
    if (NTDDI_VERSION <> NTDDI_VISTA)
        extrn '__imp__PfAddFiltersToInterface@24' as PfAddFiltersToInterface:dword
        extrn '__imp__PfAddGlobalFilterToInterface@8' as PfAddGlobalFilterToInterface:dword
        extrn '__imp__PfBindInterfaceToIndex@16' as PfBindInterfaceToIndex:dword
        extrn '__imp__PfBindInterfaceToIPAddress@12' as PfBindInterfaceToIPAddress:dword
        extrn '__imp__PfCreateInterface@24' as PfCreateInterface:dword
        extrn '__imp__PfDeleteInterface@4' as PfDeleteInterface:dword
        extrn '__imp__PfDeleteLog@0' as PfDeleteLog:dword
        extrn '__imp__PfGetInterfaceStatistics@16' as PfGetInterfaceStatistics:dword
        extrn '__imp__PfMakeLog@4' as PfMakeLog:dword
        extrn '__imp__PfRebindFilters@8' as PfRebindFilters:dword
        extrn '__imp__PfRemoveFilterHandles@12' as PfRemoveFilterHandles:dword
        extrn '__imp__PfRemoveFiltersFromInterface@20' as PfRemoveFiltersFromInterface:dword
        extrn '__imp__PfRemoveGlobalFilterFromInterface@8' as PfRemoveGlobalFilterFromInterface:dword
        extrn '__imp__PfSetLogBuffer@28' as PfSetLogBuffer:dword
        extrn '__imp__PfTestPacket@20' as PfTestPacket:dword
        extrn '__imp__PfUnBindInterface@4' as PfUnBindInterface:dword
    end if
    extrn '__imp__register_icmp@0' as register_icmp:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ResolveIpNetEntry2@8' as ResolveIpNetEntry2:dword
        extrn '__imp__ResolveNeighbor@12' as ResolveNeighbor:dword
    end if
    extrn '__imp__RestoreMediaSense@8' as RestoreMediaSense:dword
    extrn '__imp__SendARP@16' as SendARP:dword
    extrn '__imp__SetAdapterIpAddress@20' as SetAdapterIpAddress:dword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp__SetBlockRoutes@12' as SetBlockRoutes:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__SetCurrentThreadCompartmentId@4' as SetCurrentThreadCompartmentId:dword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp__SetCurrentThreadCompartmentScope@4' as SetCurrentThreadCompartmentScope:dword
    end if
    extrn '__imp__SetIfEntry@4' as SetIfEntry:dword
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp__SetIfEntryToStack@8' as SetIfEntryToStack:dword
        extrn '__imp__SetIpForwardEntryToStack@4' as SetIpForwardEntryToStack:dword
        extrn '__imp__SetIpMultihopRouteEntryToStack@4' as SetIpMultihopRouteEntryToStack:dword
        extrn '__imp__SetIpNetEntryToStack@8' as SetIpNetEntryToStack:dword
        extrn '__imp__SetIpRouteEntryToStack@4' as SetIpRouteEntryToStack:dword
        extrn '__imp__SetIpStatsToStack@4' as SetIpStatsToStack:dword
    end if
    extrn '__imp__SetIpForwardEntry@4' as SetIpForwardEntry:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__SetIpForwardEntry2@4' as SetIpForwardEntry2:dword
        extrn '__imp__SetIpInterfaceEntry@4' as SetIpInterfaceEntry:dword
        extrn '__imp__SetIpNetEntry2@4' as SetIpNetEntry2:dword
        extrn '__imp__SetIpStatisticsEx@8' as SetIpStatisticsEx:dword
    end if
    extrn '__imp__SetIpNetEntry@4' as SetIpNetEntry:dword
    extrn '__imp__SetIpStatistics@4' as SetIpStatistics:dword
    extrn '__imp__SetIpTTL@4' as SetIpTTL:dword
    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp__SetJobCompartmentId@8' as SetJobCompartmentId:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__SetNetworkInformation@0' as SetNetworkInformation:dword
        extrn '__imp__SetPerTcp6ConnectionEStats@24' as SetPerTcp6ConnectionEStats:dword
        extrn '__imp__SetPerTcp6ConnectionStats@20' as SetPerTcp6ConnectionStats:dword
        extrn '__imp__SetPerTcpConnectionEStats@24' as SetPerTcpConnectionEStats:dword
        extrn '__imp__SetPerTcpConnectionStats@20' as SetPerTcpConnectionStats:dword
    end if
    if (NTDDI_VERSION = NTDDI_WINXP)
        extrn '__imp__SetProxyArpEntryToStack@20' as SetProxyArpEntryToStack:dword
        extrn '__imp__SetRouteWithRef@4' as SetRouteWithRef:dword
        extrn '__imp__SetTcpEntryToStack@4' as SetTcpEntryToStack:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__SetSessionCompartmentId@8' as SetSessionCompartmentId:dword
        extrn '__imp__SetUnicastIpAddressEntry@8' as SetUnicastIpAddressEntry:dword
    end if
    extrn '__imp__SetTcpEntry@4' as SetTcpEntry:dword
    extrn '__imp__UnenableRouter@8' as UnenableRouter:dword
end if

api PROCESSENTRY32,\
    MODULEENTRY32

;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
;    extrn '__imp_AllocateAndGetInterfaceInfoFromStack' as AllocateAndGetInterfaceInfoFromStack:qword
;    extrn '__imp_CloseCompartment' as CloseCompartment:qword
;    extrn '__imp_CloseGetIPPhysicalInterfaceForDestination' as CloseGetIPPhysicalInterfaceForDestination:qword
;    extrn '__imp_ConvertCompartmentGuidToId' as ConvertCompartmentGuidToId:qword
;    extrn '__imp_ConvertCompartmentIdToGuid' as ConvertCompartmentIdToGuid:qword
;    extrn '__imp_CreateCompartment' as CreateCompartment:qword
;    extrn '__imp_DeleteCompartment' as DeleteCompartment:qword
;    extrn '__imp_GetWPAOACSupportLevel' as GetWPAOACSupportLevel:qword
;    extrn '__imp_InternalGetBoundTcp6EndpointTable' as InternalGetBoundTcp6EndpointTable:qword
;    extrn '__imp_InternalGetIPPhysicalInterfaceForDestination' as InternalGetIPPhysicalInterfaceForDestination:qword
;    extrn '__imp_InternalGetRtcSlotInformation' as InternalGetRtcSlotInformation:qword
;    extrn '__imp_InternalIcmpCreateFileEx' as InternalIcmpCreateFileEx:qword
;    extrn '__imp_NotifyCompartmentChange' as NotifyCompartmentChange:qword
;    extrn '__imp_OpenCompartment' as OpenCompartment:qword
;else
;    extrn '__imp__AllocateAndGetInterfaceInfoFromStack@??' as AllocateAndGetInterfaceInfoFromStack:dword
;    extrn '__imp__CloseCompartment@??' as CloseCompartment:dword
;    extrn '__imp__CloseGetIPPhysicalInterfaceForDestination@??' as CloseGetIPPhysicalInterfaceForDestination:dword
;    extrn '__imp__ConvertCompartmentGuidToId@??' as ConvertCompartmentGuidToId:dword
;    extrn '__imp__ConvertCompartmentIdToGuid@??' as ConvertCompartmentIdToGuid:dword
;    extrn '__imp__CreateCompartment@??' as CreateCompartment:dword
;    extrn '__imp__DeleteCompartment@??' as DeleteCompartment:dword
;    extrn '__imp__GetWPAOACSupportLevel@??' as GetWPAOACSupportLevel:dword
;    extrn '__imp__InternalGetBoundTcp6EndpointTable@??' as InternalGetBoundTcp6EndpointTable:dword
;    extrn '__imp__InternalGetIPPhysicalInterfaceForDestination@??' as InternalGetIPPhysicalInterfaceForDestination:dword
;    extrn '__imp__InternalGetRtcSlotInformation@??' as InternalGetRtcSlotInformation:dword
;    extrn '__imp__InternalIcmpCreateFileEx@??' as InternalIcmpCreateFileEx:dword
;    extrn '__imp__NotifyCompartmentChange@??' as NotifyCompartmentChange:dword
;    extrn '__imp__OpenCompartment@??' as OpenCompartment:dword
;end if

end if ;IPHLPAPI2_INC
