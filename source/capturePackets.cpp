#include<capturePackets.hpp>
#include<pcap.h>

void CapturePackets::capturePackets(){
    char errbuf[PCAP_ERRBUF_SIZE];
    auto handle = pcap_open_live(nullptr, 1, 1000, 10, errbuf);
    pcap_pkthdr* header;
    std::cout << "pcap opened"<< '\n';
    const u_char* packet;
    while(int returnValue = pcap_next_ex(handle, &header, &packet) >=0){
        if(returnValue == 0){
            
            continue;
        }
        std::cout << "packet:\n";
        std::cout << packet;
    }
    pcap_close(handle);

}