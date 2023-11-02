#include<pcap/pcap.h>
#include<iostream>
#include<memory>
#include<vector>
#include<string>

class CapturePackets{
    private:
    pcap_t* handle;
    u_char* user;
    std::vector<std::vector<u_char>> cache;

    public:
    void capturePackets();
    void show_packet(std::vector<u_char> stored_packet_vector);
    void save_packet_into_file(const std::string&);
    CapturePackets();
    ~CapturePackets();

};


