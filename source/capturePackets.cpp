#include <capturePackets.hpp>
#include <pcap.h>
#include <cstring>
#include <vector>
#include <iomanip>
#include <fstream>

void CapturePackets::capturePackets()
{
    pcap_pkthdr *header;
    const u_char *packet;
    int number_of_packets = 100;
    int counter = 0;

    while (int returnValue = pcap_next_ex(handle, &header, &packet) >= 0)
    {   
        if(counter > 100){
            break;
        }
        if (returnValue == 0)
        {
            continue;
        }
        std::vector<u_char> stored_packet_vector = {};
        size_t packet_size = header->len;
        for(int i = 0; i < packet_size; i++){
            stored_packet_vector.push_back(packet[i]);
        }
        cache.push_back(stored_packet_vector);
        show_packet(stored_packet_vector);
        counter++;
    }
    save_packet_into_file("out.txt");
}

void CapturePackets::show_packet(std::vector<u_char> stored_packet_vector)
{
    for(int i = 0; i < stored_packet_vector.size(); i++){
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(stored_packet_vector[i]) << " ";
        }
    std::cout << '\n';
}

void CapturePackets::save_packet_into_file(const std::string& filename)
{
    std::ofstream outfile(filename, std::ios::out | std::ios::binary);
    if (!outfile.good()) {
        std::cerr << "Error occured while opening file: " << filename << std::endl;
        return;
    }

    for(int i = 0; i < cache.size(); i++){
        for(int j = 0; j < cache[i].size(); j++){
            outfile << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(cache[i][j]) << " ";
        }
        outfile << '\n';
    }
    outfile.close();
    std::cout << "Packet saved to file: " << filename << std::endl;
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