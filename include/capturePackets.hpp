#include<pcap/pcap.h>
#include<iostream>
#include<memory>
#include<vector>

class CapturePackets{
    private:
    pcap_t* handle;
    u_char* user;

    public:
    void capturePackets();
    void show_packet(std::vector<u_char> stored_packet_vector);
    CapturePackets();
    ~CapturePackets();

};


