
#ifndef FILTER_PACKETS_HPP
#define FILTER_PACKETS_HPP


#include<pcap/pcap.h>
#include<iostream>
#include<vector>
#include<string>

enum class NetworkProtocols 
{
    IPv4, //IPV4
    IPv6, //IPV6
    ARP, //Address Resolution Protocol
    VLANtag, //VLAN Tagging
    WoL, //Wake-on-LAN
    TFTP, //Trivial File Transfer Protocol
    ICMP, //Internet Control Message Protocol
    IGMP, //Internet Group Management Protocol
    RARP, // Reverse ARP
    p8021X,
    STP,
    IPX,
    NetWare,
    NetBEUI,
    DECnet,
    SNMP,
    IGMPv3,
    PPP,
    LLDP,
    IPCP,
    EtherCAT,
    LACP,
    OAM,
    MPLSU,
    MPLSM,
    HomePug,
    TokenRing,
    UNKNOWN
 };

 enum class TransportProtocols
 {
    
 };

static std::string netProtAsString(const NetworkProtocols n) noexcept //constexpr should be placed
{
    switch (n)
    {
        case NetworkProtocols::IPv4: return "IPv4";
        break;
        case NetworkProtocols::IPv6: return "IPv6";
        break;
        case NetworkProtocols::ARP: return "ARP";
        break;
        case NetworkProtocols::VLANtag: return "VLAN tag";
        break;
        case NetworkProtocols::WoL: return "WoL";
        break;
        case NetworkProtocols::TFTP: return "TFTP";
        break;
        case NetworkProtocols::ICMP: return "ICMP";
        break;
        case NetworkProtocols::IGMP: return "IGMP";
        break;
        case NetworkProtocols::RARP: return "RARP";
        break;
        case NetworkProtocols::p8021X: return "802.1x";
        break;
        case NetworkProtocols::STP: return "STP";
        break;
        case NetworkProtocols::IPX: return "IPX";
        break;
        case NetworkProtocols::NetWare: return "NetWare";
        break;
        case NetworkProtocols::NetBEUI: return "NetBEUI";
        break;
        case NetworkProtocols::DECnet: return "DECnet";
        break;
        case NetworkProtocols::SNMP: return "SNMP";
        break;
        case NetworkProtocols::IGMPv3: return "IGMPv3";
        break;
        case NetworkProtocols::PPP: return "PPP";
        break;
        case NetworkProtocols::LLDP: return "LLDP";
        break;
        case NetworkProtocols::IPCP: return "IPCP";
        break;
        case NetworkProtocols::EtherCAT: return "EtherCAT";
        break;
        case NetworkProtocols::LACP: return "LACP";
        break;
        case NetworkProtocols::OAM: return "OAM";
        break;
        case NetworkProtocols::MPLSU: return "MPLSU";
        break;
        case NetworkProtocols::MPLSM: return "MPLSM";
        break;
        case NetworkProtocols::HomePug: return "Home Pug";
        break;
        case NetworkProtocols::TokenRing: return "TokenRing";
        break;
        case NetworkProtocols::UNKNOWN: return "UNKNOWN";
        break;
        default:
            break;
    }
}

class FilterPackets{
    private:
    NetworkProtocols ether_type;
    std::string transportType;
    public:
    void filterPacketEtherType(const std::vector<u_char>&);
    void filterPacketTransportLayer(const std::vector<u_char>&);
    NetworkProtocols getEtherType() const;
};

#endif // !FILTER_PACKETS_HPP