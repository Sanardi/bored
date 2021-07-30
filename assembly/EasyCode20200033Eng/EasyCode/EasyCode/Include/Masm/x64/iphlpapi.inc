; ======================================================;
;                                                       ;
;  iphlpapi.inc for Easy Code 2.0 64-bit Masm projects  ;
;                  (version 1.0.5)                      ;
;                                                       ;
;           Copyright © Ramon Sala 2016-2018            ;
;                                                       ;
; ======================================================;

IFNDEF IPHLPAPI_INC
IPHLPAPI_INC   EQU     1

IFNDEF WINDOWS_INC
    include windows.inc
ENDIF

IFNDEF ANY_SIZE
    ANY_SIZE                                    EQU     1
ENDIF 

IFNDEF MAXLEN_PHYSADDR
    MAXLEN_PHYSADDR                             EQU     8
ENDIF

IFNDEF MAXLEN_IFDESCR
    MAXLEN_IFDESCR                              EQU     256
ENDIF

IFNDEF MAX_ADAPTER_NAME
    MAX_ADAPTER_NAME                            EQU     128
ENDIF

IFNDEF MAX_INTERFACE_NAME_LEN
    MAX_INTERFACE_NAME_LEN                      EQU     256
ENDIF

IFNDEF IF_MAX_PHYS_ADDRESS_LENGTH
    IF_MAX_PHYS_ADDRESS_LENGTH                  EQU     32
ENDIF

IFNDEF MAX_MODULE_NAME32
    MAX_MODULE_NAME32                           EQU     255
ENDIF

IFNDEF MAX_HOSTNAME_LEN
    MAX_HOSTNAME_LEN                            EQU     128
ENDIF

IFNDEF MAX_DOMAIN_NAME_LEN
    MAX_DOMAIN_NAME_LEN                         EQU     128
ENDIF

IFNDEF MAX_SCOPE_ID_LEN
    MAX_SCOPE_ID_LEN                            EQU     256
ENDIF

IFNDEF TCPIP_OWNING_MODULE_SIZE
    TCPIP_OWNING_MODULE_SIZE                    EQU     16
ENDIF

IFNDEF DNS_MAX_NAME_BUFFER_LENGTH
    DNS_MAX_NAME_BUFFER_LENGTH                  EQU     256
ENDIF

IFNDEF IF_MAX_STRING_SIZE
    IF_MAX_STRING_SIZE                          Equ     256
ENDIF

IFNDEF AF_INET
    AF_INET                                     EQU     2
ENDIF

IFNDEF ADDRESS_FAMILY
    ADDRESS_FAMILY                              TYPEDEF WORD
ENDIF

IFNDEF IPAddr
    IPAddr                                      TYPEDEF DWORD
ENDIF

IFNDEF IPMask
    IPMask                                      TYPEDEF DWORD
ENDIF

IFNDEF IP_STATUS
    IP_STATUS                                   TYPEDEF DWORD
ENDIF

IFNDEF NET_IF_COMPARTMENT_ID
    NET_IF_COMPARTMENT_ID                       TYPEDEF DWORD
ENDIF

TH32CS_SNAPHEAPLIST                             EQU     00000001H
TH32CS_SNAPPROCESS                              EQU     00000002H
TH32CS_SNAPTHREAD                               EQU     00000004H
TH32CS_SNAPMODULE                               EQU     00000008H
TH32CS_SNAPMODULE32                             EQU     00000010H
TH32CS_SNAPALL                                  EQU     (TH32CS_SNAPHEAPLIST OR TH32CS_SNAPPROCESS OR TH32CS_SNAPTHREAD OR TH32CS_SNAPMODULE)
TH32CS_INHERIT                                  EQU     80000000H

HF32_DEFAULT                                    EQU     1
HF32_SHARED                                     EQU     2

LF32_FIXED                                      EQU     00000001H
LF32_FREE                                       EQU     00000002H
LF32_MOVEABLE                                   EQU     00000004H

IFNDEF ScopeLevelInterface
    ScopeLevelInterface                         EQU     1
    ScopeLevelLink                              EQU     2
    ScopeLevelSubnet                            EQU     3
    ScopeLevelAdmin                             EQU     4
    ScopeLevelSite                              EQU     5
    ScopeLevelOrganization                      EQU     8
    ScopeLevelGlobal                            EQU     14
    ScopeLevelCount                             EQU     16 
ENDIF

TCP_TABLE_BASIC_LISTENER                        EQU     0
TCP_TABLE_BASIC_CONNECTIONS                     EQU     1
TCP_TABLE_BASIC_ALL                             EQU     2
TCP_TABLE_OWNER_PID_LISTENER                    EQU     3
TCP_TABLE_OWNER_PID_CONNECTIONS                 EQU     4
TCP_TABLE_OWNER_PID_ALL                         EQU     5
TCP_TABLE_OWNER_MODULE_LISTENER                 EQU     6
TCP_TABLE_OWNER_MODULE_CONNECTIONS              EQU     7
TCP_TABLE_OWNER_MODULE_ALL                      EQU     8

UDP_TABLE_BASIC                                 EQU     0
UDP_TABLE_OWNER_PID                             EQU     1
UDP_TABLE_OWNER_MODULE                          EQU     2


;======================================== Structures ======================================;

HEAPLIST32 STRUCT ALIGNMODE
    dwSize        SIZE_T    ?
    th32ProcessID DD        ?
    th32HeapID    ULONG_PTR ?
    dwFlags       DD        ?
HEAPLIST32 ENDS

HEAPENTRY32 STRUCT ALIGNMODE
    dwSize        SIZE_T    ?
    hHandle       HANDLE    ?
    dwAddress     ULONG_PTR ?
    dwBlockSize   SIZE_T    ?
    dwFlags       DD        ?
    dwLockCount   DD        ?
    dwResvd       DD        ?
    th32ProcessID DD        ?
    th32HeapID    ULONG_PTR ?
HEAPENTRY32 ENDS

PROCESSENTRY32A STRUCT ALIGNMODE
    dwSize              DD        ?
    cntUsage            DD        ?
    th32ProcessID       DD        ?
    th32DefaultHeapID   ULONG_PTR ?
    th32ModuleID        DD        ?
    cntThreads          DD        ?
    th32ParentProcessID DD        ?
    pcPriClassBase      DD        ?
    dwFlags             DD        ?
    szExeFile           DB MAX_PATH DUP(?)
PROCESSENTRY32A ENDS

PROCESSENTRY32W STRUCT ALIGNMODE
    dwSize              DD        ?
    cntUsage            DD        ?
    th32ProcessID       DD        ?
    th32DefaultHeapID   ULONG_PTR ?
    th32ModuleID        DD        ?
    cntThreads          DD        ?
    th32ParentProcessID DD        ?
    pcPriClassBase      DD        ?
    dwFlags             DD        ?
    szExeFile           DW MAX_PATH DUP(?)
PROCESSENTRY32W ENDS

THREADENTRY32 STRUCT ALIGNMODE
    dwSize             DD ?
    cntUsage           DD ?
    th32ThreadID       DD ?
    th32OwnerProcessID DD ?
    tpBasePri          DD ?
    tpDeltaPri         DD ?
    dwFlags            DD ?
THREADENTRY32 ENDS

MODULEENTRY32A STRUCT ALIGNMODE
    dwSize          DD     ?
    th32ModuleID    DD     ?
    th32ProcessID   DD     ?
    GlblcntUsage    DD     ?
    ProccntUsage    DD     ?
    modBaseAddr     XPTR   ?
    modBaseSize     DD     ?
    hModule         HANDLE ?
    szModule        DB (MAX_MODULE_NAME32 + 1) DUP(?)
    szExePath       DB MAX_PATH DUP(?)
MODULEENTRY32A ENDS

MODULEENTRY32W STRUCT ALIGNMODE
    dwSize          DD     ?
    th32ModuleID    DD     ?
    th32ProcessID   DD     ?
    GlblcntUsage    DD     ?
    ProccntUsage    DD     ?
    modBaseAddr     XPTR   ?
    modBaseSize     DD     ?
    hModule         HANDLE ?
    szModule        DW (MAX_MODULE_NAME32 + 1) DUP(?)
    szExePath       DW MAX_PATH DUP(?)
MODULEENTRY32W ENDS

IFNDEF IN_ADDR
    IN_ADDR STRUCT ALIGNMODE
        UNION S_un
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
    IN_ADDR ENDS
ENDIF

IFNDEF IN6_ADDR
    IN6_ADDR STRUCT ALIGNMODE
        UNION u
            _Byte DB 16 DUP(?)
            _Word DW 8 DUP(?)
        ENDS
    IN6_ADDR ENDS
ENDIF

IFNDEF SOCKADDR_IN
    SOCKADDR_IN STRUCT ALIGNMODE
        sin_family DW ?
        sin_port   DW        ?
        sin_addr   IN_ADDR <> 
        sin_zero   DB 8 DUP(?)
    SOCKADDR_IN ENDS
ENDIF

IFNDEF SCOPE_ID
    RECASCOPE_ID RECORD QQLevel:4, QQZone:28
    SCOPE_ID STRUCT ALIGNMODE
        UNION
            STRUCT
                RECASCOPE_ID <>
            EndS
            _Value           DD ?
        ENDS
    SCOPE_ID ENDS
ENDIF

IFNDEF SOCKADDR_IN6
    SOCKADDR_IN6 STRUCT ALIGNMODE
        sin6_family           DD    ?
        sin6_port             DD    ?
        sin6_flowinfo         DD    ?
        sin6_addr             IN6_ADDR <>
        UNION
            sin6_scope_id     DD    ?
            sin6_scope_struct SCOPE_ID <> 
        ENDS
    SOCKADDR_IN6 ENDS
ENDIF

IFNDEF SOCKADDR_IN6_LH
    SOCKADDR_IN6_LH STRUCT ALIGNMODE
        sin6_family           DW ?
        sin6_port             DW ?
        sin6_flowinfo         DD ?
        sin6_addr             IN6_ADDR <>
        UNION
            sin6_scope_id     DD ?
            sin6_scope_struct SCOPE_ID <>
        ENDS
    SOCKADDR_IN6_LH ENDS
ENDIF

IFNDEF NET_LUID
    RECANET_LUID RECORD AQIfType:16, AQNetLuidIndex:24, AQReserved:24
    NET_LUID UNION ALIGNMODE
        Value   DQ  ?
        STRUCT Info
            RECANET_LUID <>
        ENDS
    NET_LUID ENDS
ENDIF
IFNDEF NET_LUID_LH
    NET_LUID_LH TYPEDEF NET_LUID
ENDIF

IFNDEF SOCKADDR_INET
    SOCKADDR_INET UNION ALIGNMODE
        Ipv4      SOCKADDR_IN  <> 
        Ipv6      SOCKADDR_IN6 <>
        si_family DW           ?
    SOCKADDR_INET ENDS
ENDIF

IFNDEF MIB_IPNETROW
    MIB_IPNETROW STRUCT ALIGNMODE
        dwIndex         DD ?
        dwPhysAddrLen   DD ?
        bPhysAddr       DB MAXLEN_PHYSADDR DUP(?)
        dwAddr          DD ?
        dwType          DD ?
    MIB_IPNETROW ENDS
ENDIF

IFNDEF MIB_IPNET_ROW2
    RECAMIB_IPNET_ROW2 RECORD IsUnreachable:1, IsRouter:1
    MIB_IPNET_ROW2 STRUCT ALIGNMODE
        Address               SOCKADDR_INET <>
        InterfaceIndex        DD    ?
        InterfaceLuid         NET_LUID <>
        PhysicalAddress       DB IF_MAX_PHYS_ADDRESS_LENGTH DUP(?)
        PhysicalAddressLength DD    ?
        State                 DD    ?
        UNION
            STRUCT
                RECAMIB_IPNET_ROW2 <>
            ENDS
            Flags             DB    ?
        ENDS
        UNION ReachabilityTime
            LastReachable     DD    ?
            LastUnreachable   DD    ?
        ENDS
    MIB_IPNET_ROW2 ENDS
ENDIF

IFNDEF MIBICMPSTATS
    MIBICMPSTATS STRUCT ALIGNMODE
        dwMsgs          DD  ?
        dwErrors        DD  ?
        dwDestUnreachs  DD  ?
        dwTimeExcds     DD  ?
        dwParmProbs     DD  ?
        dwSrcQuenchs    DD  ?
        dwRedirects     DD  ?
        dwEchos         DD  ?
        dwEchoReps      DD  ?
        dwTimestamps    DD  ?
        dwTimestampReps DD  ?
        dwAddrMasks     DD  ?
        dwAddrMaskReps  DD  ?
    MIBICMPSTATS ENDS
ENDIF

IFNDEF MIBICMPSTATS_EX
    MIBICMPSTATS_EX STRUCT ALIGNMODE
        dwMsgs        DD    ?
        dwErrors      DD    ?
        rgdwTypeCount DB 256 DUP(?)
    MIBICMPSTATS_EX ENDS
ENDIF

IFNDEF MIBICMPINFO
    MIBICMPINFO STRUCT ALIGNMODE
        icmpInStats  MIBICMPSTATS <>
        icmpOutStats MIBICMPSTATS <>
    MIBICMPINFO ENDS
ENDIF

IFNDEF MIB_ICMP
    MIB_ICMP STRUCT ALIGNMODE
        stats MIBICMPINFO <>
    MIB_ICMP ENDS
ENDIF

IFNDEF MIB_ICMP_EX
    MIB_ICMP_EX STRUCT ALIGNMODE
        icmpInStats  MIBICMPSTATS_EX <>
        icmpOutStats MIBICMPSTATS_EX <>
    MIB_ICMP_EX ENDS
ENDIF

IFNDEF MIB_IFROW
    MIB_IFROW STRUCT ALIGNMODE
        wszName           DW MAX_INTERFACE_NAME_LEN DUP(?)
        dwIndex           DD    ?
        dwType            DD    ?
        dwMtu             DD    ?
        dwSpeed           DD    ?
        dwPhysAddrLen     DD    ?
        bPhysAddr         DB MAXLEN_PHYSADDR DUP(?)
        dwAdminStatus     DD    ?
        dwOperStatus      DD    ?
        dwLastChange      DD    ?
        dwInOctets        DD    ?
        dwInUcastPkts     DD    ?
        dwInNUcastPkts    DD    ?
        dwInDiscards      DD    ?
        dwInErrors        DD    ?
        dwInUnknownProtos DD    ?
        dwOutOctets       DD    ?
        dwOutUcastPkts    DD    ?
        dwOutNUcastPkts   DD    ?
        dwOutDiscards     DD    ?
        dwOutErrors       DD    ?
        dwOutQLen         DD    ?
        dwDescrLen        DD    ?
        bDescr            DB MAXLEN_IFDESCR DUP(?)
    MIB_IFROW ENDS
ENDIF

IFNDEF MIB_IF_ROW2
    RECAMIB_IF_ROW2 RECORD ASEndPointInterface:1, ASLowPower:1, ASPaused:1, ASNotMediaConnected:1, ASNotAuthenticated:1, ASConnectorPresent:1, ASFilterInterface:1, ASHardwareInterface:1
    MIB_IF_ROW2 STRUCT ALIGNMODE
        InterfaceLuid            NET_LUID <>
        InterfaceIndex           DD     ?
        InterfaceGuid            GUID   <>
        _Alias                   DW     (IF_MAX_STRING_SIZE + 1) Dup(?)
        Description              DW     (IF_MAX_STRING_SIZE + 1) DUP(?)
        PhysicalAddressLength    DD     ?
        PhysicalAddress          DB     IF_MAX_PHYS_ADDRESS_LENGTH DUP(?)
        PermanentPhysicalAddress DB     IF_MAX_PHYS_ADDRESS_LENGTH Dup(?)
        Mtu                      DD     ?
        _Type                    DD     ?
        TunnelType               DD     ?
        MediaType                DD     ?
        PhysicalMediumType       DD     ?
        AccessType               DD     ?
        DirectionType            DD     ?
        STRUCT InterfaceAndOperStatusFlags
            RECAMIB_IF_ROW2      <>
        ENDS
        OperStatus               DD     ?
        AdminStatus              DD     ?
        MediaConnectState        DD     ?
        NetworkGuid              GUID   <> 
        ConnectionType           DD     ?
        TransmitLinkSpeed        DQ     ?
        ReceiveLinkSpeed         DQ     ?
        InOctets                 DQ     ?
        InUcastPkts              DQ     ?
        InNUcastPkts             DQ     ?
        InDiscards               DQ     ?
        InErrors                 DQ     ?
        InUnknownProtos          DQ     ?
        InUcastOctets            DQ     ?
        InMulticastOctets        DQ     ?
        InBroadcastOctets        DQ     ?
        OutOctets                DQ     ?
        OutUcastPkts             DQ     ?
        OutNUcastPkts            DQ     ?
        OutDiscards              DQ     ?
        OutErrors                DQ     ?
        OutUcastOctets           DQ     ?
        OutMulticastOctets       DQ     ?
        OutBroadcastOctets       DQ     ?
        OutQLen                  DQ     ?
    MIB_IF_ROW2 ENDS
ENDIF

IFNDEF MIB_IFSTACK_ROW
    MIB_IFSTACK_ROW STRUCT ALIGNMODE
        HigherLayerInterfaceIndex DD ?
        LowerLayerInterfaceIndex  DD ?
    MIB_IFSTACK_ROW ENDS
ENDIF

IFNDEF MIB_IFSTACK_TABLE
    MIB_IFSTACK_TABLE STRUCT ALIGNMODE
        NumEntries  DD  ?
        Table       MIB_IFSTACK_ROW ANY_SIZE DUP(<>)
    MIB_IFSTACK_TABLE ENDS
ENDIF

IFNDEF MIB_IFTABLE
    MIB_IFTABLE STRUCT ALIGNMODE
        dwNumEntries DD ?
        table        MIB_IFROW ANY_SIZE DUP(<>)
    MIB_IFTABLE ENDS
ENDIF

IFNDEF MIB_IF_TABLE2
    MIB_IF_TABLE2 STRUCT ALIGNMODE
        NumEntries  DD  ?
        Table       MIB_IF_ROW2 ANY_SIZE DUP(<>)
    MIB_IF_TABLE2 ENDS
ENDIF

IP_ADAPTER_INDEX_MAP STRUCT ALIGNMODE
    Index DD ?
    Name1 DW MAX_ADAPTER_NAME DUP(?)
IP_ADAPTER_INDEX_MAP ENDS

IFNDEF IP_INTERFACE_INFO
    IP_INTERFACE_INFO STRUCT ALIGNMODE
        NumAdapters DD  ?
        Adapter     IP_ADAPTER_INDEX_MAP 1 DUP(<>)
    IP_INTERFACE_INFO ENDS
ENDIF

IFNDEF MIB_INVERTEDIFSTACK_ROW
    MIB_INVERTEDIFSTACK_ROW STRUCT ALIGNMODE
        LowerLayerInterfaceIndex  DD ?
        HigherLayerInterfaceIndex DD ?
    MIB_INVERTEDIFSTACK_ROW ENDS
ENDIF

IFNDEF MIB_INVERTEDIFSTACK_TABLE
    MIB_INVERTEDIFSTACK_TABLE STRUCT ALIGNMODE
        NumEntries DD   ?
        Table      MIB_INVERTEDIFSTACK_ROW ANY_SIZE DUP(<>)
    MIB_INVERTEDIFSTACK_TABLE ENDS
ENDIF

IFNDEF MIB_IPADDRROW
    MIB_IPADDRROW STRUCT ALIGNMODE
        dwAddr      DD  ?
        dwIndex     DD  ?
        dwMask      DD  ?
        dwBCastAddr DD  ?
        dwReasmSize DD  ?
        unused1     DW  ?
        wType       DW  ?
    MIB_IPADDRROW ENDS
ENDIF
IFNDEF MIB_IPADDRROW_XP
    MIB_IPADDRROW_XP TYPEDEF MIB_IPADDRROW
ENDIF

IFNDEF IP_ADDRESS_PREFIX
    IP_ADDRESS_PREFIX STRUCT ALIGNMODE
        Prefix       SOCKADDR_INET <>
        PrefixLength DB ?
    IP_ADDRESS_PREFIX ENDS
ENDIF

IFNDEF MIB_IPFORWARD_ROW2
    MIB_IPFORWARD_ROW2 STRUCT ALIGNMODE
        InterfaceLuid        NET_LUID <>
        InterfaceIndex       DD ?
        DestinationPrefix    IP_ADDRESS_PREFIX <>
        NextHop              SOCKADDR_INET <>
        SitePrefixLength     DB ?
        ValidLifetime        DD ?
        PreferredLifetime    DD ?
        Metric               DD ?
        Protocol             DD ?
        Loopback             DB ?
        AutoconfigureAddress DB ?
        Publish              DB ?
        Immortal             DB ?
        Age                  DD ?
        Origin               DD ?
    MIB_IPFORWARD_ROW2 ENDS
ENDIF

IFNDEF MIB_IPFORWARDROW
    MIB_IPFORWARDROW STRUCT ALIGNMODE
        dwForwardDest     DD    ?
        dwForwardMask     DD    ?
        dwForwardPolicy   DD    ?
        dwForwardNextHop  DD    ?
        dwForwardIfIndex  DD    ?
        UNION
            dwForwardType DD    ?
            ForwardType   DD    ?
        ENDS
        UNION
            dwForwardProto DD   ?
            ForwardProto   DD   ?
        ENDS
        dwForwardAge       DD   ?
        dwForwardNextHopAS DD   ?
        dwForwardMetric1   DD   ?
        dwForwardMetric2   DD   ?
        dwForwardMetric3   DD   ?
        dwForwardMetric4   DD   ?
        dwForwardMetric5   DD   ?
    MIB_IPFORWARDROW ENDS
ENDIF

IFNDEF MIB_IPFORWARDTABLE
    MIB_IPFORWARDTABLE STRUCT ALIGNMODE
        dwNumEntries DD ?
        table        MIB_IPFORWARDROW ANY_SIZE DUP(<>)
    MIB_IPFORWARDTABLE ENDS
ENDIF

IFNDEF NL_INTERFACE_OFFLOAD_ROD
    RECANL_INTERFACE_OFFLOAD_ROD RECORD BNTlGiantSendOffloadSupported:1, BNTlLargeSendOffloadSupported:1, BNFastPathCompatible:1, BNTlStreamOptionsSupported:1, BNTlStreamChecksumSupported:1, BNTlDatagramChecksumSupported:1, BNNlOptionsSupported:1, BNNlChecksumSupported:1
    NL_INTERFACE_OFFLOAD_ROD STRUCT ALIGNMODE
        RECANL_INTERFACE_OFFLOAD_ROD <>
    NL_INTERFACE_OFFLOAD_ROD ENDS
ENDIF

IFNDEF MIB_IPINTERFACE_ROW
    MIB_IPINTERFACE_ROW STRUCT ALIGNMODE
        Family                               DW ?
        InterfaceLuid                        NET_LUID <> 
        InterfaceIndex                       DD ?
        MaxReassemblySize                    DD ?
        InterfaceIdentifier                  DQ ?
        MinRouterAdvertisementInterval       DD ?
        MaxRouterAdvertisementInterval       DD ?
        AdvertisingEnabled                   DB ?
        ForwardingEnabled                    DB ?
        WeakHostSend                         DB ?
        WeakHostReceive                      DB ?
        UseAutomaticMetric                   DB ?
        UseNeighborUnreachabilityDetection   DB ?
        ManagedAddressConfigurationSupported DB ?
        OtherStatefulConfigurationSupported  DB ?
        AdvertiseDefaultRoute                DB ?
        RouterDiscoveryBehavior              DD ?
        DadTransmits                         DD ?
        BaseReachableTime                    DD ?
        RetransmitTime                       DD ?
        PathMtuDiscoveryTimeout              DD ?
        LinkLocalAddressBehavior             DD ?
        LinkLocalAddressTimeout              DD ?
        ZoneIndices                          DD ScopeLevelCount DUP(?)
        SitePrefixLength                     DD ?
        Metric                               DD ?
        NlMtu                                DD ?
        Connected                            DB ?
        SupportsWakeUpPatterns               DB ?
        SupportsNeighborDiscovery            DB ?
        SupportsRouterDiscovery              DB ?
        ReachableTime                        DD ?
        TransmitOffload                      NL_INTERFACE_OFFLOAD_ROD <>
        ReceiveOffload                       NL_INTERFACE_OFFLOAD_ROD <>
        DisableDefaultRoutes                 DB ?
    MIB_IPINTERFACE_ROW ENDS
ENDIF

IFNDEF MIB_IPINTERFACE_TABLE
    MIB_IPINTERFACE_TABLE STRUCT ALIGNMODE
        NumEntries DD   ?
        Table      MIB_IPINTERFACE_ROW ANY_SIZE DUP(<>)
    MIB_IPINTERFACE_TABLE ENDS
ENDIF

IFNDEF MIB_IPNETTABLE
    MIB_IPNETTABLE STRUCT ALIGNMODE
        dwNumEntries DD ?
        table        MIB_IPNETROW ANY_SIZE Dup(<>)
    MIB_IPNETTABLE ENDS
ENDIF

IFNDEF MIB_IPNET_TABLE2
    MIB_IPNET_TABLE2 STRUCT ALIGNMODE
        NumEntries DD   ?
        Table      MIB_IPNET_ROW2 ANY_SIZE DUP(<>)
    MIB_IPNET_TABLE2 ENDS
ENDIF

IFNDEF MIB_IPPATH_ROW
    MIB_IPPATH_ROW STRUCT ALIGNMODE
        Source              SOCKADDR_INET <>
        Destination         SOCKADDR_INET <>
        InterfaceLuid       NET_LUID <>
        InterfaceIndex      DD  ?
        CurrentNextHop      SOCKADDR_INET <>
        PathMtu             DD  ?
        RttMean             DD  ?
        RttDeviation        DD  ?
        UNION
            LastReachable   DD  ?
            LastUnreachable DD  ?
        ENDS
        IsReachable         DB  ?
        LinkTransmitSpeed   DQ  ?
        LinkReceiveSpeed    DQ  ?
    MIB_IPPATH_ROW ENDS
ENDIF

IFNDEF MIB_IPPATH_TABLE
    MIB_IPPATH_TABLE STRUCT ALIGNMODE
        NumEntries DD   ?
        Table      MIB_IPPATH_ROW ANY_SIZE DUP(<>)
    MIB_IPPATH_TABLE ENDS
ENDIF

IFNDEF MIB_IPSTATS
    MIB_IPSTATS STRUCT ALIGNMODE
        dwForwarding      DD ?
        dwDefaultTTL      DD ?
        dwInReceives      DD ?
        dwInHdrErrors     DD ?
        dwInAddrErrors    DD ?
        dwForwDatagrams   DD ?
        dwInUnknownProtos DD ?
        dwInDiscards      DD ?
        dwInDelivers      DD ?
        dwOutRequests     DD ?
        dwRoutingDiscards DD ?
        dwOutDiscards     DD ?
        dwOutNoRoutes     DD ?
        dwReasmTimeout    DD ?
        dwReasmReqds      DD ?
        dwReasmOks        DD ?
        dwReasmFails      DD ?
        dwFragOks         DD ?
        dwFragFails       DD ?
        dwFragCreates     DD ?
        dwNumIf           DD ?
        dwNumAddr         DD ?
        dwNumRoutes       DD ?
    MIB_IPSTATS ENDS
ENDIF
IFNDEF MIB_IPSTATS_W2K
    MIB_IPSTATS_W2K TYPEDEF MIB_IPSTATS
ENDIF

IFNDEF MIB_MULTICASTIPADDRESS_ROW
    MIB_MULTICASTIPADDRESS_ROW STRUCT ALIGNMODE
        Address         SOCKADDR_INET <>
        InterfaceIndex  DD       ?
        InterfaceLuid   NET_LUID <>
        ScopeId         SCOPE_ID <>
    MIB_MULTICASTIPADDRESS_ROW ENDS
ENDIF

IFNDEF MIB_MULTICASTIPADDRESS_TABLE
    MIB_MULTICASTIPADDRESS_TABLE STRUCT ALIGNMODE
        NumEntries DD   ?
        Table      MIB_MULTICASTIPADDRESS_ROW ANY_SIZE DUP(<>)
    MIB_MULTICASTIPADDRESS_TABLE ENDS
ENDIF

IFNDEF IP_MASK_STRING
    IP_MASK_STRING STRUCT ALIGNMODE
        String DB 16 DUP(?)
    IP_MASK_STRING ENDS
ENDIF

IFNDEF IP_ADDRESS_STRING
    IP_ADDRESS_STRING STRUCT ALIGNMODE
        String DB 16 DUP(?)
    IP_ADDRESS_STRING ENDS
ENDIF

IFNDEF IP_ADDR_STRING
    IP_ADDR_STRING STRUCT ALIGNMODE
        Next        XPTR ? 
        IpAddress   IP_ADDRESS_STRING <>
        IpMask      IP_MASK_STRING <>
        Context DWORD ?
    IP_ADDR_STRING ENDS
ENDIF

IFNDEF FIXED_INFO
    FIXED_INFO STRUCT ALIGNMODE
        HostName         DB (MAX_HOSTNAME_LEN + 4) DUP(?)
        DomainName       DB (MAX_DOMAIN_NAME_LEN + 4) DUP(?)
        CurrentDnsServer XWORD ?
        DnsServerList    IP_ADDR_STRING <>
        NodeType         DD ?
        ScopeId          DB (MAX_SCOPE_ID_LEN + 4) DUP(?)
        EnableRouting    DD ?
        EnableProxy      DD ?
        EnableDns        DD ?
    FIXED_INFO ENDS
ENDIF
IFNDEF FIXED_INFO_W2KSP1
    FIXED_INFO_W2KSP1 TYPEDEF FIXED_INFO
ENDIF

IFNDEF MIB_TCP6ROW_OWNER_MODULE
    MIB_TCP6ROW_OWNER_MODULE STRUCT ALIGNMODE
        ucLocalAddr       DB 16 dup (?)
        dwLocalScopeId    DD ?
        dwLocalPort       DD ?
        ucRemoteAddr      DB 16 dup (?)
        dwRemoteScopeId   DD ?
        dwRemotePort      DD ?
        dwState           DD ?
        dwOwningPid       DD ?
        liCreateTimestamp LARGE_INTEGER <>
        OwningModuleInfo  REAL8 TCPIP_OWNING_MODULE_SIZE DUP(?)
    MIB_TCP6ROW_OWNER_MODULE ENDS
ENDIF

IFNDEF MIB_TCPROW_OWNER_MODULE
    MIB_TCPROW_OWNER_MODULE STRUCT ALIGNMODE
        dwState           DD    ?
        dwLocalAddr       DD    ?
        dwLocalPort       DD    ?
        dwRemoteAddr      DD    ?
        dwRemotePort      DD    ?
        dwOwningPid       DD    ?
        liCreateTimestamp LARGE_INTEGER <>
        OwningModuleInfo  REAL8 TCPIP_OWNING_MODULE_SIZE DUP(?)
    MIB_TCPROW_OWNER_MODULE ENDS
ENDIF

IFNDEF MIB_UDP6ROW_OWNER_MODULE
    RECAMIB_UDP6ROW_OWNER_MODULE RECORD PPSpecificPortBind:1
    MIB_UDP6ROW_OWNER_MODULE STRUCT ALIGNMODE
        ucLocalAddr       DB    16 DUP(?)
        dwLocalScopeId    DD    ?
        dwLocalPort       DD    ?
        dwOwningPid       DD    ?
        liCreateTimestamp LARGE_INTEGER <>
        UNION
            STRUCT
                RECAMIB_UDP6ROW_OWNER_MODULE <>
            ENDS
            dwFlags       DD    ?
        ENDS
        OwningModuleInfo  REAL8 TCPIP_OWNING_MODULE_SIZE DUP(?)
    MIB_UDP6ROW_OWNER_MODULE ENDS
ENDIF

IFNDEF MIB_UDPROW_OWNER_MODULE
    RECAMIB_UDPROW_OWNER_MODULE RECORD POSpecificPortBind:1
    MIB_UDPROW_OWNER_MODULE STRUCT ALIGNMODE
        dwLocalAddr       DD    ?
        dwLocalPort       DD    ?
        dwOwningPid       DD    ?
        liCreateTimestamp LARGE_INTEGER <>
        UNION
            STRUCT
                RECAMIB_UDPROW_OWNER_MODULE <>
            ENDS
            dwFlags       DD    ?
        ENDS
        OwningModuleInfo REAL8 TCPIP_OWNING_MODULE_SIZE DUP(?)
    MIB_UDPROW_OWNER_MODULE ENDS
ENDIF

IFNDEF IP_PER_ADAPTER_INFO
    IP_PER_ADAPTER_INFO STRUCT ALIGNMODE
        AutoconfigEnabled DD    ?
        AutoconfigActive  DD    ?
        CurrentDnsServer  XWORD ?
        DnsServerList     IP_ADDR_STRING <>
    IP_PER_ADAPTER_INFO ENDS
ENDIF
IFNDEF IP_PER_ADAPTER_INFO_W2KSP1
    IP_PER_ADAPTER_INFO_W2KSP1 TYPEDEF IP_PER_ADAPTER_INFO
ENDIF

IFNDEF MIB_TCP6ROW
    MIB_TCP6ROW STRUCT ALIGNMODE
        State           DD  ?
        LocalAddr       IN6_ADDR <>
        dwLocalScopeId  DD  ?
        dwLocalPort     DD  ?
        RemoteAddr      IN6_ADDR <>
        dwRemoteScopeId DD  ?
        dwRemotePort    DD  ?
    MIB_TCP6ROW ENDS
ENDIF

IFNDEF MIB_TCP6TABLE
    MIB_TCP6TABLE STRUCT ALIGNMODE
        dwNumEntries DD ?
        table        MIB_TCP6ROW ANY_SIZE DUP(<>)
    MIB_TCP6TABLE ENDS
ENDIF

IFNDEF MIB_TCP6ROW2
    MIB_TCP6ROW2 STRUCT ALIGNMODE
        LocalAddr       IN6_ADDR <>
        dwLocalScopeId  DD  ?
        dwLocalPort     DD  ?
        RemoteAddr      IN6_ADDR <>
        dwRemoteScopeId DD  ?
        dwRemotePort    DD  ?
        State           DD  ?
        dwOwningPid     DD  ?
        dwOffloadState  DD  ?
    MIB_TCP6ROW2 ENDS
ENDIF

IFNDEF MIB_TCP6TABLE2
    MIB_TCP6TABLE2 STRUCT ALIGNMODE
        dwNumEntries DD ?
        table        MIB_TCP6ROW2 ANY_SIZE DUP(<>)
    MIB_TCP6TABLE2 ENDS
ENDIF

IFNDEF MIB_TCPSTATS
    MIB_TCPSTATS STRUCT ALIGNMODE
        dwRtoAlgorithm DD   ?
        dwRtoMin       DD   ?
        dwRtoMax       DD   ?
        dwMaxConn      DD   ?
        dwActiveOpens  DD   ?
        dwPassiveOpens DD   ?
        dwAttemptFails DD   ?
        dwEstabResets  DD   ?
        dwCurrEstab    DD   ?
        dwInSegs       DD   ?
        dwOutSegs      DD   ?
        dwRetransSegs  DD   ?
        dwInErrs       DD   ?
        dwOutRsts      DD   ?
        dwNumConns     DD   ?
    MIB_TCPSTATS ENDS
ENDIF

IFNDEF MIB_TCPROW
    MIB_TCPROW STRUCT ALIGNMODE
        UNION
            dwState  DD ?
            State    DD ?
        ENDS
        dwLocalAddr  DD ?
        dwLocalPort  DD ?
        dwRemoteAddr DD ?
        dwRemotePort DD ?
    MIB_TCPROW ENDS
ENDIF
IFNDEF MIB_TCPROW_LH
    MIB_TCPROW_LH TYPEDEF MIB_TCPROW
ENDIF

IFNDEF MIB_TCPROW2
    MIB_TCPROW2 STRUCT ALIGNMODE
        dwState        DD   ?
        dwLocalAddr    DD   ?
        dwLocalPort    DD   ?
        dwRemoteAddr   DD   ?
        dwRemotePort   DD   ?
        dwOwningPid    DD   ?
        dwOffloadState DD   ?
    MIB_TCPROW2 ENDS
ENDIF

IFNDEF MIB_TCPTABLE2
    MIB_TCPTABLE2 STRUCT ALIGNMODE
        dwNumEntries DD ?
        table        MIB_TCPROW2 ANY_SIZE DUP(<>)
    MIB_TCPTABLE2 ENDS
ENDIF

IFNDEF MIB_UDP6ROW
    MIB_UDP6ROW STRUCT ALIGNMODE
        dwLocalAddr     IN6_ADDR <>
        dwLocalScopeId  DD  ?
        dwLocalPort     DD  ?
    MIB_UDP6ROW ENDS
ENDIF

IFNDEF MIB_UDP6TABLE
    MIB_UDP6TABLE STRUCT ALIGNMODE
        dwNumEntries DD ?
        table        MIB_UDP6ROW ANY_SIZE DUP(<>)
    MIB_UDP6TABLE ENDS
ENDIF

IFNDEF MIB_UDPSTATS
    MIB_UDPSTATS STRUCT ALIGNMODE
        dwInDatagrams   DD  ?
        dwNoPorts       DD  ?
        dwInErrors      DD  ?
        dwOutDatagrams  DD  ?
        dwNumAddrs      DD  ?
    MIB_UDPSTATS ENDS
ENDIF

IFNDEF MIB_UDPROW
    MIB_UDPROW STRUCT ALIGNMODE
        dwLocalAddr DD  ?
        dwLocalPort DD  ?
    MIB_UDPROW ENDS
ENDIF

IFNDEF MIB_UDPTABLE
    MIB_UDPTABLE STRUCT ALIGNMODE
        dwNumEntries DD ?
        table        MIB_UDPROW ANY_SIZE DUP(<>)
    MIB_UDPTABLE ENDS
ENDIF

IFNDEF IP_UNIDIRECTIONAL_ADAPTER_ADDRESS
    IP_UNIDIRECTIONAL_ADAPTER_ADDRESS STRUCT ALIGNMODE
        NumAdapters DD ?
        Address     DD 1 DUP(?)
    IP_UNIDIRECTIONAL_ADAPTER_ADDRESS ENDS
ENDIF

IFNDEF MIB_UNICASTIPADDRESS_ROW
    MIB_UNICASTIPADDRESS_ROW STRUCT ALIGNMODE
        Address             SOCKADDR_INET <>
        InterfaceLuid       NET_LUID <>
        InterfaceIndex      DD  ?
        PrefixOrigin        DD  ?
        SuffixOrigin        DD  ?
        ValidLifetime       DD  ?
        PreferredLifetime   DD  ?
        OnLinkPrefixLength  DB  ?
        SkipAsSource        DB  ?
        DadState            DD  ?
        ScopeId             SCOPE_ID <>
        CreationTimeStamp   LARGE_INTEGER <>
    MIB_UNICASTIPADDRESS_ROW ENDS
ENDIF

IFNDEF IPV6_ADDRESS_EX
    IPV6_ADDRESS_EX STRUCT ALIGNMODE
        sin6_port     DW ?
        sin6_flowinfo DD ?
        sin6_addr     DW 8 DUP(?)
        sin6_scope_id DD ?
    IPV6_ADDRESS_EX ENDS
ENDIF

IFNDEF ICMPV6_ECHO_REPLY
    ICMPV6_ECHO_REPLY STRUCT ALIGNMODE
        Address       IPV6_ADDRESS_EX <>
        Status        DD ?
        RoundTripTime DD ?
    ICMPV6_ECHO_REPLY ENDS
ENDIF
IFNDEF ICMPV6_ECHO_REPLY_LH
    ICMPV6_ECHO_REPLY_LH TYPEDEF ICMPV6_ECHO_REPLY
ENDIF

IFNDEF IP_OPTION_INFORMATION
    IP_OPTION_INFORMATION STRUCT ALIGNMODE
        Ttl         DB    ?
        Tos         DB    ?
        Flags       DB    ?
        OptionsSize DB    ?
        OptionsData XWORD ?
    IP_OPTION_INFORMATION ENDS
ENDIF

IFNDEF SOCKADDR
    SOCKADDR STRUCT ALIGNMODE
        IF (NTDDI_VERSION LT NTDDI_VISTA)
            sa_family DW ?
        ELSE
            sa_family ADDRESS_FAMILY ?
        ENDIF
        sa_data       BYTE 14 DUP(?)
    SOCKADDR ENDS
ENDIF

IFNDEF NET_ADDRESS_INFO
    NET_ADDRESS_INFO STRUCT ALIGNMODE
        Format          DD ?
        UNION
            STRUCT NamedAddress
                Address DW DNS_MAX_NAME_BUFFER_LENGTH DUP(?)
                Port    DW 6 DUP(?)
            ENDS
            Ipv4Address SOCKADDR_IN <>
            Ipv6Address SOCKADDR_IN6 <>
            IpAddress   SOCKADDR <>
        ENDS
    NET_ADDRESS_INFO ENDS
ENDIF

IFNDEF OVERLAPPED
    OVERLAPPED STRUCT ALIGNMODE
        Internal     XPTR ?
        InternalHigh XPTR ?
        UNION u
            STRUCT s
                _Offset     DD  ?
                OffsetHigh  DD  ?
            ENDS
            Pointer  XPTR ?
        ENDS
        hEvent       HANDLE ?
    OVERLAPPED ENDS
ENDIF

IFNDEF MIB_TCPROW_OWNER_PID
    MIB_TCPROW_OWNER_PID STRUCT ALIGNMODE
        dwState      DD ?
        dwLocalAddr  DD ?
        dwLocalPort  DD ?
        dwRemoteAddr DD ?
        dwRemotePort DD ?
        dwOwningPid  DD ?
    MIB_TCPROW_OWNER_PID ENDS
ENDIF

IFNDEF MIB_UDPROW_OWNER_PID
    MIB_UDPROW_OWNER_PID STRUCT ALIGNMODE
        dwLocalAddr DD ?
        dwLocalPort DD ?
        dwOwningPid DD ?
    MIB_UDPROW_OWNER_PID ENDS
ENDIF

IFNDEF MIB_IPADDRTABLE
    MIB_IPADDRTABLE STRUCT ALIGNMODE
        dwNumEntries DD ?
        table        MIB_IPADDRROW ANY_SIZE DUP(<>)
    MIB_IPADDRTABLE ENDS
ENDIF

IFNDEF MIB_TCPTABLE_OWNER_PID
    MIB_TCPTABLE_OWNER_PID STRUCT ALIGNMODE
        dwNumEntries DD ?
        table        MIB_TCPROW_OWNER_PID ANY_SIZE DUP(<>)
    MIB_TCPTABLE_OWNER_PID ENDS
ENDIF

IFNDEF MIB_UDPTABLE_OWNER_PID
    MIB_UDPTABLE_OWNER_PID STRUCT ALIGNMODE
        dwNumEntries DD ?
        table        MIB_UDPROW_OWNER_PID ANY_SIZE DUP(<>)
    MIB_UDPTABLE_OWNER_PID ENDS
ENDIF

IFNDEF MIB_TCP6ROW_OWNER_PID
    MIB_TCP6ROW_OWNER_PID STRUCT ALIGNMODE
        ucLocalAddr     DB 16 DUP(?)
        dwLocalScopeId  DD ?
        dwLocalPort     DD ?
        ucRemoteAddr    DB 16 DUP(?)
        dwRemoteScopeId DD ?
        dwRemotePort    DD ?
        dwState         DD ?
        dwOwningPid     DD ?
    MIB_TCP6ROW_OWNER_PID ENDS
ENDIF

IFNDEF MIB_TCP6TABLE_OWNER_PID
    MIB_TCP6TABLE_OWNER_PID STRUCT ALIGNMODE
        dwNumEntries DD ?
        table        MIB_TCP6ROW_OWNER_PID ANY_SIZE DUP(<>)
    MIB_TCP6TABLE_OWNER_PID ENDS
ENDIF

;======================================== Functions =======================================;
IF (NTDDI_VERSION EQ NTDDI_VISTA)
    _PfAddFiltersToInterface PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    _PfAddGlobalFilterToInterface PROTO :XWORD, :XWORD
    _PfBindInterfaceToIndex PROTO :XWORD, :XWORD, :XWORD, :XWORD
    _PfBindInterfaceToIPAddress PROTO :XWORD, :XWORD, :XWORD
    _PfCreateInterface PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    _PfDeleteInterface PROTO :XWORD
    _PfDeleteLog PROTO
    _PfGetInterfaceStatistics PROTO :XWORD, :XWORD, :XWORD, :XWORD
    _PfMakeLog PROTO :XWORD
    _PfRebindFilters PROTO :XWORD, :XWORD
    _PfRemoveFilterHandles PROTO :XWORD, :XWORD, :XWORD
    _PfRemoveFiltersFromInterface PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    _PfRemoveGlobalFilterFromInterface PROTO :XWORD, :XWORD
    _PfSetLogBuffer PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    _PfTestPacket PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    _PfUnBindInterface PROTO :XWORD
ENDIF
AddIPAddress PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    AllocateAndGetArpEntTableFromStack PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    AllocateAndGetIfTableFromStack PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    AllocateAndGetIpAddrTableFromStack PROTO :XWORD, :XWORD, :XWORD, :XWORD
    AllocateAndGetIpForwardTableFromStack PROTO :XPTR, :XWORD, :XWORD, :XWORD
    AllocateAndGetIpNetTableFromStack PROTO :XPTR, :XWORD, :XWORD, :XWORD
    AllocateAndGetTcpExTableFromStack PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XWORD
    AllocateAndGetTcpExTable2FromStack PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    AllocateAndGetTcpTableFromStack PROTO :XPTR, :XWORD, :XWORD, :XWORD
    AllocateAndGetUdpExTable2FromStack PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    AllocateAndGetUdpExTableFromStack PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    AllocateAndGetUdpTableFromStack PROTO :XWORD, :XWORD, :XWORD, :XWORD
ENDIF
CancelIPChangeNotify PROTO :XPTR
IF (NTDDI_VERSION GE NTDDI_VISTA)
    CancelMibChangeNotify2 PROTO :HANDLE
ENDIF
IF (NTDDI_VERSION GE NTDDI_WINXP)
    IF (NTDDI_VERSION LE NTDDI_WS03ALL)
        CancelSecurityHealthChangeNotify PROTO :XPTR
    ENDIF
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    ConvertGuidToStringA PROTO :XWORD
    ConvertGuidToStringW PROTO :XWORD
    IFDEF APP_UNICODE
        ConvertGuidToString EQU <ConvertGuidToStringW>
    ELSE
        ConvertGuidToString EQU <ConvertGuidToStringA>
    ENDIF
ENDIF
ConvertInterfaceAliasToLuid PROTO :XPTR, :XPTR
ConvertInterfaceGuidToLuid PROTO :XPTR, :XPTR
ConvertInterfaceIndexToLuid PROTO :XWORD, :XPTR
ConvertInterfaceLuidToAlias PROTO :XPTR, :XPTR, :SIZE_T
ConvertInterfaceLuidToGuid PROTO :XPTR, :XPTR
ConvertInterfaceLuidToIndex PROTO :XPTR, :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    ConvertInterfaceLuidToNameA PROTO :XPTR, :XPTR, :SIZE_T
    ConvertInterfaceLuidToNameW PROTO :XPTR, :XPTR, :SIZE_T
    ConvertInterfaceNameToLuidA PROTO :XPTR, :XWORD
    ConvertInterfaceNameToLuidW PROTO :XPTR, :XWORD
    ConvertInterfacePhysicalAddressToLuid PROTO :XWORD, :XWORD, :XWORD
    ConvertIpv4MaskToLength PROTO :XWORD, :XPTR
    ConvertLengthToIpv4Mask PROTO :XWORD, :XPTR
    ConvertRemoteInterfaceAliasToLuid PROTO :XWORD, :XWORD, :XWORD
    ConvertRemoteInterfaceGuidToLuid PROTO :XWORD, :XWORD, :XWORD
    ConvertRemoteInterfaceIndexToLuid PROTO :XWORD, :XWORD, :XWORD
    ConvertRemoteInterfaceLuidToAlias PROTO :XWORD, :XWORD, :XWORD, :XWORD
    ConvertRemoteInterfaceLuidToGuid PROTO :XWORD, :XWORD, :XWORD
    ConvertRemoteInterfaceLuidToIndex PROTO :XWORD, :XWORD, :XWORD
    ConvertStringToGuidA PROTO :XWORD, :XWORD
    ConvertStringToGuidW PROTO :XWORD, :XWORD
    IFDEF APP_UNICODE
        ConvertInterfaceLuidToName EQU <ConvertInterfaceLuidToNameW>
        ConvertInterfaceNameToLuid EQU <ConvertInterfaceNameToLuidW>
        ConvertStringToGuid EQU <ConvertStringToGuidW>
    ELSE
        ConvertInterfaceLuidToName EQU <ConvertInterfaceLuidToNameA>
        ConvertInterfaceNameToLuid EQU <ConvertInterfaceNameToLuidA>
        ConvertStringToGuid EQU <ConvertStringToGuidA>
    ENDIF
ENDIF
IF (NTDDI_VERSION EQ NTDDI_WIN7)
    ConvertStringToInterfacePhysicalAddress PROTO :XWORD, :XWORD
    CPNatfwtCreateProviderInstance PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    CPNatfwtDeregisterProviderInstance PROTO :XWORD
    CPNatfwtDestroyProviderInstance PROTO :XWORD
    CPNatfwtIndicateReceivedBuffers PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    CPNatfwtRegisterProviderInstance PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    CreateAnycastIpAddressEntry PROTO :XPTR
    CreateIpForwardEntry2 PROTO :XPTR
    CreateIpNetEntry2 PROTO :XPTR
ENDIF
CreateIpForwardEntry PROTO :XPTR
CreateIpNetEntry PROTO :XPTR
IF (NTDDI_VERSION GE NTDDI_VISTA)
    CreatePersistentTcpPortReservation PROTO :XWORD, :XWORD, :XPTR
    CreatePersistentUdpPortReservation PROTO :XWORD, :XWORD, :XPTR
ENDIF
CreateProxyArpEntry PROTO :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    CreateSortedAddressPairs PROTO :XPTR, :XWORD, :XPTR, :XWORD, :XWORD, :XPTR, :XWORD
    CreateUnicastIpAddressEntry PROTO :XPTR
    DeleteAnycastIpAddressEntry PROTO :XPTR
ENDIF
DeleteIPAddress PROTO :XWORD
DeleteIpForwardEntry PROTO :XPTR
IF (NTDDI_VERSION GE NTDDI_VISTA)
    DeleteIpForwardEntry2 PROTO :XPTR
    DeleteIpNetEntry2 PROTO :XPTR
ENDIF
DeleteIpNetEntry PROTO :XPTR
IF (NTDDI_VERSION GE NTDDI_VISTA)
    DeletePersistentTcpPortReservation PROTO :XWORD, :XWORD
    DeletePersistentUdpPortReservation PROTO :XWORD, :XWORD
    DeleteUnicastIpAddressEntry PROTO :XPTR
ENDIF
DeleteProxyArpEntry PROTO :XWORD, :XWORD, :XWORD
DisableMediaSense PROTO :HANDLE, :XPTR
do_echo_rep PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
do_echo_req PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
EnableRouter PROTO :XPTR, :XPTR
FlushIpNetTable PROTO :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    FlushIpNetTable2 PROTO :XWORD, :XWORD
    FlushIpPathTable PROTO :XWORD
    FreeMibTable PROTO :XPTR
ENDIF
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    FlushIpNetTableFromStack PROTO :XWORD
ENDIF
GetAdapterIndex PROTO :LPWSTR, :XPTR
GetAdapterOrderMap PROTO
GetAdaptersAddresses PROTO :XWORD, :XWORD, :XPTR, :XPTR, :XPTR
GetAdaptersInfo PROTO :XPTR, :XPTR
IF (NTDDI_VERSION GE NTDDI_VISTA)
    GetAnycastIpAddressEntry PROTO :XPTR
    GetAnycastIpAddressTable PROTO :XWORD, :XPTR
ENDIF
GetBestInterface PROTO :XPTR, :XPTR
GetBestInterfaceEx PROTO :XPTR, :XPTR
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    GetBestInterfaceFromStack PROTO :XWORD, :XWORD
ENDIF
GetBestRoute PROTO :XWORD, :XWORD, :XPTR
IF (NTDDI_VERSION GE NTDDI_VISTA)
    GetBestRoute2 PROTO :XWORD, :XWORD, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR
ENDIF
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    GetBestRouteFromStack PROTO :XWORD, :XWORD, :XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    GetCurrentThreadCompartmentId PROTO
ENDIF
IF (NTDDI_VERSION GE NTDDI_WIN10)
    GetCurrentThreadCompartmentScope PROTO :XWORD, :XWORD
ENDIF
GetExtendedTcpTable PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XWORD
GetExtendedUdpTable PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XWORD
GetFriendlyIfIndex PROTO :XWORD
GetIcmpStatistics PROTO :XPTR
GetIcmpStatisticsEx PROTO :XPTR, :XWORD
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    GetIcmpStatsFromStack PROTO :XWORD
    GetIcmpStatsFromStackEx PROTO :XWORD, :XWORD
    GetIfEntryFromStack PROTO :XWORD, :XWORD, :XWORD
ENDIF
GetIfEntry PROTO :XPTR
IF (NTDDI_VERSION GE NTDDI_VISTA)
    GetIfEntry2 PROTO :XPTR
    GetIfStackTable PROTO :XPTR
ENDIF
GetIfTable PROTO :XPTR, :XPTR, :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    GetIfTable2 PROTO :XPTR
    GetIfTable2Ex PROTO :XWORD, :XPTR
    GetInvertedIfStackTable PROTO :XPTR
ENDIF
GetInterfaceInfo PROTO :XPTR, :XPTR
GetIpAddrTable PROTO :XPTR, :XPTR, :XWORD
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    GetIpAddrTableFromStack PROTO :XWORD, :XWORD, :XWORD
    GetIpForwardTableFromStack PROTO :XWORD, :XWORD, :XWORD
ENDIF
GetIpErrorString PROTO :XWORD, :XPTR, :XPTR
IF (NTDDI_VERSION GE NTDDI_VISTA)
    GetIpForwardEntry2 PROTO :XPTR
    GetIpForwardTable2 PROTO :XWORD, :XPTR
    GetIpInterfaceEntry PROTO :XPTR
    GetIpInterfaceTable PROTO :XWORD, :XPTR
    GetIpNetEntry2 PROTO :XPTR
    GetIpNetTable2 PROTO :XWORD, :XPTR
ENDIF
GetIpForwardTable PROTO :XPTR, :XPTR, :XWORD
GetIpNetTable PROTO :XPTR, :XPTR, :XWORD
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    GetIpNetTableFromStack PROTO :XWORD, :XWORD, :XWORD, :XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_WIN8)
    GetIpNetworkConnectionBandwidthEstimates PROTO :XWORD, :XWORD, :XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    GetIpPathEntry PROTO :XWORD
    GetIpPathTable PROTO :XWORD, :XPTR
ENDIF
GetIpStatistics PROTO :XPTR
GetIpStatisticsEx PROTO :XPTR, :XWORD
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    GetIpStatsFromStack PROTO :XWORD
    GetIpStatsFromStackEx PROTO :XWORD, :XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    GetMulticastIpAddressEntry PROTO :XPTR
    GetMulticastIpAddressTable PROTO :XWORD, :XPTR
    GetNetworkInformation PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XWORD
ENDIF
GetNetworkParams PROTO :XPTR, :XWORD
GetNumberOfInterfaces PROTO :XPTR
IF (NTDDI_VERSION GE NTDDI_VISTA)
    GetOwnerModuleFromPidAndInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ENDIF
GetOwnerModuleFromTcp6Entry PROTO :XPTR, :XWORD, :XPTR, :XPTR
GetOwnerModuleFromTcpEntry PROTO :XPTR, :XWORD, :XPTR, :XPTR
GetOwnerModuleFromUdp6Entry PROTO :XPTR, :XWORD, :XPTR, :XPTR
GetOwnerModuleFromUdpEntry PROTO :XPTR, :XWORD, :XPTR, :XPTR
GetPerAdapterInfo PROTO :XWORD, :XPTR, :XPTR
IF (NTDDI_VERSION GE NTDDI_VISTA)
    GetPerTcp6ConnectionEStats PROTO :XPTR, :XWORD, :XPTR, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD
    GetPerTcp6ConnectionStats PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    GetPerTcpConnectionEStats PROTO :XPTR, :XWORD, :XPTR, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD
    GetPerTcpConnectionStats PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ENDIF
GetRTTAndHopCount PROTO :XPTR, :XPTR, :XWORD, :XPTR
IF (NTDDI_VERSION GE NTDDI_VISTA)
    GetSessionCompartmentId PROTO :XWORD
    GetTcp6Table PROTO :XPTR, :XPTR, :XWORD
    GetTcp6Table2 PROTO :XPTR, :XPTR, :XWORD
ENDIF
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    GetTcpExTable2FromStack PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    GetTcpStatsFromStack PROTO :XWORD
    GetTcpTableFromStack PROTO :XWORD, :XWORD, :XWORD
ENDIF
GetTcpStatistics PROTO :XPTR
GetTcpStatisticsEx PROTO :XPTR, :XWORD
GetTcpTable PROTO :XPTR, :XPTR, :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    GetTcpTable2 PROTO :XPTR, :XPTR, :XWORD
    GetTeredoPort PROTO :XWORD
    GetUdp6Table PROTO :XPTR, :XPTR, :XWORD
ENDIF
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    GetUdpExTable2FromStack PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ENDIF
GetUdpStatistics PROTO :XPTR
GetUdpStatisticsEx PROTO :XPTR, :XWORD
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    GetUdpStatsFromStack PROTO :XWORD
    GetUdpStatsFromStackEx PROTO :XWORD, :XWORD
    GetUdpTableFromStack PROTO :XWORD, :XWORD, :XWORD
ENDIF
GetUdpTable PROTO :XPTR, :XPTR, :XWORD
GetUniDirectionalAdapterInfo PROTO :XPTR, :XPTR
IF (NTDDI_VERSION GE NTDDI_VISTA)
    GetUnicastIpAddressEntry PROTO :XPTR
    GetUnicastIpAddressTable PROTO :XPTR
ENDIF
Icmp6CreateFile PROTO
Icmp6ParseReplies PROTO :XPTR, :XWORD
Icmp6SendEcho2 PROTO :HANDLE, :HANDLE, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR, :XWORD, :XWORD
IcmpCloseHandle PROTO :HANDLE
IcmpCreateFile PROTO
IcmpParseReplies PROTO :XPTR, :XWORD
IcmpSendEcho PROTO :HANDLE, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR, :XWORD, :XWORD
IcmpSendEcho2 PROTO :HANDLE, :HANDLE, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR, :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    IcmpSendEcho2Ex PROTO :HANDLE, :HANDLE, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR, :XWORD, :XWORD
    if_indextoname PROTO :XWORD, :XPTR
    if_nametoindex PROTO :XPTR
ENDIF
IF (NTDDI_VERSION GE NTDDI_WIN10)
    InitializeCompartmentEntry PROTO :XPTR
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    InitializeIpForwardEntry PROTO :XPTR
    InitializeIpInterfaceEntry PROTO :XPTR
    InitializeUnicastIpAddressEntry PROTO :XPTR
    InternalCleanupPersistentStore PROTO :XWORD, :XWORD
    InternalCreateAnycastIpAddressEntry PROTO :XWORD, :XWORD
    InternalCreateIpForwardEntry2 PROTO :XWORD, :XWORD
    InternalCreateIpNetEntry2 PROTO :XWORD, :XWORD
    InternalCreateUnicastIpAddressEntry PROTO :XWORD, :XWORD
    InternalDeleteAnycastIpAddressEntry PROTO :XWORD, :XWORD
    InternalDeleteIpForwardEntry2 PROTO :XWORD, :XWORD
ENDIF
InternalCreateIpNetEntry PROTO :XWORD
InternalCreateIpForwardEntry PROTO :XWORD
InternalDeleteIpForwardEntry PROTO :XWORD
InternalDeleteIpNetEntry PROTO :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    InternalDeleteIpNetEntry2 PROTO :XWORD, :XWORD
    InternalDeleteUnicastIpAddressEntry PROTO :XWORD, :XWORD
    InternalFindInterfaceByAddress PROTO :XWORD, :XWORD
    InternalGetAnycastIpAddressEntry PROTO :XWORD, :XWORD
    InternalGetAnycastIpAddressTable PROTO :XWORD, :XWORD, :XWORD
    InternalGetForwardIpTable2 PROTO :XWORD, :XWORD, :XWORD
    InternalGetIfEntry2 PROTO :XWORD, :XWORD
    InternalGetIfTable2 PROTO :XWORD, :XWORD
    InternalGetIpForwardEntry2 PROTO :XWORD, :XWORD
    InternalGetIpInterfaceEntry PROTO :XWORD, :XWORD
    InternalGetIpInterfaceTable PROTO :XWORD, :XWORD, :XWORD
    InternalGetIpNetEntry2 PROTO :XWORD, :XWORD
    InternalGetIpNetTable2 PROTO :XWORD, :XWORD, :XWORD
ENDIF
InternalGetIfTable PROTO :XWORD, :XWORD, :XWORD
InternalGetIpAddrTable PROTO :XWORD, :XWORD, :XWORD
InternalGetIpForwardTable PROTO :XWORD, :XWORD, :XWORD
InternalGetIpNetTable PROTO :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    InternalGetMulticastIpAddressEntry PROTO :XWORD, :XWORD
    InternalGetMulticastIpAddressTable PROTO :XWORD, :XWORD, :XWORD
    InternalGetTcp6Table2 PROTO :XWORD, :XWORD, :XWORD
    InternalGetTcp6TableWithOwnerModule PROTO :XWORD, :XWORD, :XWORD
    InternalGetTcp6TableWithOwnerPid PROTO :XWORD, :XWORD, :XWORD
ENDIF
InternalGetTcpTable PROTO :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    InternalGetTcpTable2 PROTO :XWORD, :XWORD, :XWORD
    InternalGetTcpTableEx PROTO :XWORD, :XWORD, :XWORD
    InternalGetTcpTableWithOwnerModule PROTO :XWORD, :XWORD, :XWORD
    InternalGetTcpTableWithOwnerPid PROTO :XWORD, :XWORD, :XWORD
    InternalGetTunnelPhysicalAdapter PROTO :XWORD, :XWORD
    InternalGetUdp6TableWithOwnerModule PROTO :XWORD, :XWORD, :XWORD
    InternalGetUdp6TableWithOwnerPid PROTO :XWORD, :XWORD, :XWORD
ENDIF
InternalGetUdpTable PROTO :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    InternalGetUdpTableEx PROTO :XWORD, :XWORD, :XWORD
    InternalGetUdpTableWithOwnerModule PROTO :XWORD, :XWORD, :XWORD
    InternalGetUdpTableWithOwnerPid PROTO :XWORD, :XWORD, :XWORD
    InternalGetUnicastIpAddressEntry PROTO :XWORD, :XWORD
    InternalGetUnicastIpAddressTable PROTO :XWORD, :XWORD, :XWORD
ENDIF
InternalSetIfEntry PROTO :XWORD
InternalSetIpForwardEntry PROTO :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    InternalSetIpForwardEntry2 PROTO :XWORD, :XWORD
    InternalSetIpInterfaceEntry PROTO :XWORD, :XWORD
    InternalSetIpNetEntry2 PROTO :XWORD, :XWORD
ENDIF
InternalSetIpNetEntry PROTO :XWORD
InternalSetIpStats PROTO :XWORD
InternalSetTcpEntry PROTO :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    InternalSetTeredoPort PROTO :XWORD
    InternalSetUnicastIpAddressEntry PROTO :XWORD, :XWORD
ENDIF
IpReleaseAddress PROTO :XPTR
IpRenewAddress PROTO :XPTR
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    IsLocalAddress PROTO :XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    LookupPersistentTcpPortReservation PROTO :XWORD, :XWORD, :XPTR
    LookupPersistentUdpPortReservation PROTO :XWORD, :XWORD, :XPTR
    NhGetInterfaceDescriptionFromGuid PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NhGetInterfaceNameFromGuid PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ENDIF
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    NhpGetInterfaceIndexFromStack PROTO :XWORD, :XWORD
ENDIF
NhGetGuidFromInterfaceName PROTO :XWORD, :XWORD, :XWORD, :XWORD
NhGetInterfaceNameFromDeviceGuid PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
NhpAllocateAndGetInterfaceInfoFromStack PROTO :XPTR, :XPTR, :XWORD, :HANDLE, :XWORD
NotifyAddrChange PROTO :XPTR, :XPTR
IF (NTDDI_VERSION GE NTDDI_VISTA)
    NotifyIpInterfaceChange PROTO :XWORD, :XPTR, :XPTR, :XWORD, :HANDLE
    NotifyRouteChange2 PROTO :XWORD, :XPTR, :XPTR, :XWORD, :HANDLE
ENDIF
NotifyRouteChange PROTO :XPTR, :XPTR
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    NotifyRouteChangeEx PROTO :XWORD, :XWORD, :XWORD
    NotifySecurityHealthChange PROTO :XPTR, :XPTR, :XPTR
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    NotifyStableUnicastIpAddressTable PROTO :XWORD, :XPTR, :XPTR, :XPTR, :HANDLE
    NotifyTeredoPortChange PROTO :XPTR, :XPTR, :XWORD, :HANDLE
    NotifyUnicastIpAddressChange PROTO :XWORD, :XPTR, :XPTR, :XWORD, :HANDLE
ENDIF
NTPTimeToNTFileTime PROTO :XWORD, :XWORD, :XWORD
NTTimeToNTPTime PROTO :XWORD, :XWORD
ParseNetworkString PROTO :XPTR, :XWORD, :XPTR, :XWORD, :XWORD
IF (NTDDI_VERSION NE NTDDI_VISTA)
    PfAddFiltersToInterface PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    PfAddGlobalFilterToInterface PROTO :XWORD, :XWORD
    PfBindInterfaceToIndex PROTO :XWORD, :XWORD, :XWORD, :XWORD
    PfBindInterfaceToIPAddress PROTO :XWORD, :XWORD, :XWORD
    PfCreateInterface PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    PfDeleteInterface PROTO :XWORD
    PfDeleteLog PROTO
    PfGetInterfaceStatistics PROTO :XWORD, :XWORD, :XWORD, :XWORD
    PfMakeLog PROTO :XWORD
    PfRebindFilters PROTO :XWORD, :XWORD
    PfRemoveFilterHandles PROTO :XWORD, :XWORD, :XWORD
    PfRemoveFiltersFromInterface PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    PfRemoveGlobalFilterFromInterface PROTO :XWORD, :XWORD
    PfSetLogBuffer PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    PfTestPacket PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    PfUnBindInterface PROTO :XWORD
ENDIF
register_icmp PROTO
IF (NTDDI_VERSION GE NTDDI_VISTA)
    ResolveIpNetEntry2 PROTO :XPTR, :XPTR
    ResolveNeighbor PROTO :XPTR, :XPTR, :XPTR
ENDIF
RestoreMediaSense PROTO :XPTR, :XPTR
SendARP PROTO :XWORD, :XWORD, :XPTR, :XPTR
SetAdapterIpAddress PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    SetBlockRoutes PROTO :XWORD, :XWORD, :XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    SetCurrentThreadCompartmentId PROTO :XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_WIN10)
    SetCurrentThreadCompartmentScope PROTO :XWORD
ENDIF
SetIfEntry PROTO :XPTR
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    SetIfEntryToStack PROTO :XWORD, :XWORD
    SetIpForwardEntryToStack PROTO :XWORD
    SetIpMultihopRouteEntryToStack PROTO :XWORD
    SetIpNetEntryToStack PROTO :XWORD, :XWORD
    SetIpRouteEntryToStack PROTO :XWORD
    SetIpStatsToStack PROTO :XWORD
ENDIF
SetIpForwardEntry PROTO :XPTR
IF (NTDDI_VERSION GE NTDDI_VISTA)
    SetIpForwardEntry2 PROTO :XPTR
    SetIpInterfaceEntry PROTO :XPTR
    SetIpNetEntry2 PROTO :XPTR
    SetIpStatisticsEx PROTO :XPTR, :XWORD
ENDIF
SetIpNetEntry PROTO :XPTR
SetIpStatistics PROTO :XPTR
SetIpTTL PROTO :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN10)
    SetJobCompartmentId PROTO :HANDLE, :XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    SetNetworkInformation PROTO
    SetPerTcp6ConnectionEStats PROTO :XPTR, :XWORD, :XPTR, :XWORD, :XWORD, :XWORD
    SetPerTcp6ConnectionStats PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    SetPerTcpConnectionEStats PROTO :XPTR, :XWORD, :XPTR, :XWORD, :XWORD, :XWORD
    SetPerTcpConnectionStats PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ENDIF
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    SetProxyArpEntryToStack PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    SetRouteWithRef PROTO :XWORD
    SetTcpEntryToStack PROTO :XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    SetSessionCompartmentId PROTO :XWORD, :XWORD
    SetUnicastIpAddressEntry PROTO :XWORD, :XWORD
ENDIF
SetTcpEntry PROTO :XPTR
UnenableRouter PROTO :XPTR, :XPTR

IFDEF APP_UNICODE
    PROCESSENTRY32 EQU <PROCESSENTRY32W>
    MODULEENTRY32 EQU <MODULEENTRY32W>
ELSE
    PROCESSENTRY32 EQU <PROCESSENTRY32A>
    MODULEENTRY32 EQU <MODULEENTRY32A>
ENDIF

;======================= Undocumented functions (unknown arguments) =======================;
;AllocateAndGetInterfaceInfoFromStack PROTO
;CloseCompartment PROTO
;CloseGetIPPhysicalInterfaceForDestination PROTO
;ConvertCompartmentGuidToId PROTO
;ConvertCompartmentIdToGuid PROTO
;CreateCompartment PROTO
;DeleteCompartment PROTO
;GetWPAOACSupportLevel PROTO
;InternalGetBoundTcp6EndpointTable PROTO
;InternalGetIPPhysicalInterfaceForDestination PROTO
;InternalGetRtcSlotInformation PROTO
;InternalIcmpCreateFileEx PROTO
;NotifyCompartmentChange PROTO
;OpenCompartment PROTO

ENDIF ;IPHLPAPI_INC
