#include <capturePackets.hpp>
#include <pcap.h>
#include <cstring>
#include <vector>
#include <iomanip>
#include <fstream>
#include <filterPackets.hpp>

void CapturePackets::capturePackets()
{
    pcap_pkthdr *header;
    const u_char *packet;
    int number_of_packets = 100;
    int counter = 0;

    while (int returnValue = pcap_next_ex(handle, &header, &packet) >= 0)
    {
        if(counter > number_of_packets){
            break;
        }
        if(returnValue == 0)
        {
            continue;
        }
        std::vector<u_char> stored_packet_vector = {};
        size_t packet_size = header->len;
        for(int i = 0; i < packet_size; i++){
            stored_packet_vector.push_back(packet[i]);
        }
        FilterPackets f;
        f.filterPacketEtherType(stored_packet_vector);
        auto ether_type = f.getEtherType();
        if(ether_type != NetworkProtocols::UNKNOWN)
        {
            std::cout<<netProtAsString(ether_type)<<"\n";
            counter++;
        }
        save_packet_live(stored_packet_vector);
        cache.push_back(stored_packet_vector);
    }
    save_packet_into_file("out.txt");
}

void CapturePackets::show_packet(std::vector<u_char> stored_packet_vector)
{
    for(int i = 0; i < stored_packet_vector.size(); i++)
    {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(stored_packet_vector[i]) << " ";
    }
    std::cout << '\n';
}

void CapturePackets::save_packet_into_file(const std::string& filename)
{
    std::ofstream outfile(filename, std::ios::out | std::ios::binary);
    if(!outfile.good()) 
    {
        std::cerr << "Error occured while opening file: " << filename << std::endl;
        return;
    }

    for(int i = 0; i < cache.size(); i++)
    {
        for(int j = 0; j < cache[i].size(); j++)
        {
            outfile << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(cache[i][j]) << " ";
        }
        outfile << '\n';
    }
    outfile.close();
    std::cout << "Packet saved to file: " << filename << std::endl;
}
void CapturePackets::save_packet_live(const std::vector<u_char>& stored_packet_vector)
{
    std::ofstream outfile;
    outfile.open("live_data.txt", std::ios_base::app);
    for(int i = 0; i < stored_packet_vector.size(); i++)
    {
    outfile << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(stored_packet_vector[i]) << " ";
    }
    outfile << '\n';
}


CapturePackets::CapturePackets()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    handle = (pcap_open_live(nullptr, 1, 1000, 10, errbuf));
    std::cout << "Stream opened." << '\n';
}

CapturePackets::~CapturePackets()
{
    pcap_close(handle);
    std::cout << "Stream closed." << '\n';
}