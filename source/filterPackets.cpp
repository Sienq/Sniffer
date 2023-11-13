#include<pcap/pcap.h>
#include<iostream>
#include<filterPackets.hpp>
#include<vector>
#include<string>

void FilterPackets::filterPacketEtherType(const std::vector<u_char>& packet)
{
    if(packet.size() >= 14)
    {
        const uint16_t ether_type = (packet[12] << 8) | packet[13];
        switch (ether_type)
        {
        case 0x0800:
            this->ether_type = NetworkProtocols::IPv4;
            break;
        case 0x86DD:
            this->ether_type = NetworkProtocols::IPv6;
            break;
        case 0x0806:
            this->ether_type = NetworkProtocols::ARP;
            break;
        case 0x8100:
            this->ether_type = NetworkProtocols::VLANtag;
            break;
        case 0x0842:
            this->ether_type = NetworkProtocols::WoL;
            break;
        case 0x0801:
            this->ether_type = NetworkProtocols::TFTP;
            break;
        // case 0x0800: already reserved by ipv4?
        //     this->ether_type = NetworkProtocols::ICMP
        case 0x0802:
            this->ether_type = NetworkProtocols::IGMP;
            break;
        case 0x8035:
            this->ether_type = NetworkProtocols::RARP;
            break;
        case 0x888E:
            this->ether_type = NetworkProtocols::p8021X;
            break;
        // case 0x0802: already in use by IGMP
        //     this->ether_type = NetworkProtocols::STP
        case 0x8137:
            this->ether_type = NetworkProtocols::IPX;
            break;
        case 0x8138:
            this->ether_type = NetworkProtocols::NetWare;
            break;
        case 0x8037:
            this->ether_type = NetworkProtocols::NetBEUI;
            break;
        case 0x6003:
            this->ether_type = NetworkProtocols::DECnet;
            break;
        case 0x814C:
            this->ether_type = NetworkProtocols::SNMP;
            break;
        case 0x88BE:
            this->ether_type = NetworkProtocols::IGMPv3;
            break;
        case 0x880B:
            this->ether_type = NetworkProtocols::PPP;
            break;
        case 0x88CC:
            this->ether_type = NetworkProtocols::LLDP;
            break;
        case 0x8021:
            this->ether_type = NetworkProtocols::IPCP;
            break;
        case 0x88A4:
            this->ether_type = NetworkProtocols::EtherCAT;
            break;
        case 0x8809:
            this->ether_type = NetworkProtocols::LACP;
            break;
        case 0x8902:
            this->ether_type = NetworkProtocols::OAM;
            break;
        case 0x8847:
            this->ether_type = NetworkProtocols::MPLSU;
            break;
        case 0x8848:
            this->ether_type = NetworkProtocols::MPLSM;
            break;
        case 0x887B:
            this->ether_type = NetworkProtocols::HomePug;
            break;
        case 0x8127:
            this->ether_type = NetworkProtocols::TokenRing;
            break;
        default:
            this->ether_type = NetworkProtocols::UNKNOWN;
            break;
        }
    }
}

void FilterPackets::filterPacketTransportLayer(const std::vector<u_char> &packet)
{

}

NetworkProtocols FilterPackets::getEtherType() const
{
    return ether_type;
}
