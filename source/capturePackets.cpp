#include<capturePackets.hpp>
#include<pcap.h>
#include<cstring>

void CapturePackets::capturePackets(){
    pcap_pkthdr* header;
    const u_char* packet;
    while(int returnValue = pcap_next_ex(handle, &header, &packet) >=0){
        if(returnValue == 0){  
            continue;
        }
        std::cout<< returnValue;
        std::cout << "packet:\n";
        for(int i = 0; i < header->len; i++){
        std::printf("%02X ", packet[i]);
        }
        std::cout << '\n';
    }

}
CapturePackets::CapturePackets(){
    char errbuf[PCAP_ERRBUF_SIZE];
    handle = (pcap_open_live(nullptr, 1, 1000, 10, errbuf));
    std::cout<<"Stream opened."<<'\n';
}

CapturePackets::~CapturePackets(){
    pcap_close(handle);
    free(handle);
    std::cout<<"Stream closed."<<'\n';
}