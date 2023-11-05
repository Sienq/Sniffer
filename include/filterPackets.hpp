#include<pcap/pcap.h>
#include<iostream>
#include<vector>
#include<string>

class FilterPackets{
    private:
    std::string ether_type;
    public:
    void filterPacketEtherType(const std::vector<u_char>&);
    std::string getEtherType() const;
};