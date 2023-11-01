#include <capturePackets.hpp>
#include <pcap.h>
#include <cstring>
#include <vector>
#include <iomanip>

void CapturePackets::capturePackets()
{
    pcap_pkthdr *header;
    const u_char *packet;
    

    while (int returnValue = pcap_next_ex(handle, &header, &packet) >= 0)
    {
        if (returnValue == 0)
        {
            continue;
        }
        std::vector<u_char> stored_packet_vector = {};
        size_t packet_size = header->len;
        for(int i = 0; i < packet_size; i++){
            stored_packet_vector.push_back(packet[i]);
        }
        show_packet(stored_packet_vector);
    }
}

void CapturePackets::show_packet(std::vector<u_char> stored_packet_vector)
{
    for(int i = 0; i < stored_packet_vector.size(); i++){
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(stored_packet_vector[i]) << " ";
        }
    std::cout << '\n';
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
    free(handle);
    std::cout << "Stream closed." << '\n';
}