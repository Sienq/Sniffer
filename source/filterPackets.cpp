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
    if(ether_type == 0x0800)
    {
        this->ether_type = "IPv4"; //Captured IPv4
    }else if(ether_type == 0x86DD)
    {
        this->ether_type = "IPv6"; //Captured IPv6
    }else
    {
        this->ether_type = "Unknown";//Captured a packet with unknown EtherType
    }
    }else
    {
        //Captured packet is too short to check its type"
    }
}

std::string FilterPackets::getEtherType() const
{
    return ether_type;
}
