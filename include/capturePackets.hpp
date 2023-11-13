#include<pcap/pcap.h>
#include<iostream>
#include<memory>
#include<vector>
#include<string>

#ifndef CAPTURE_PACKETS_HPP
#define CAPTURE_PACKETS_HPP



class CapturePackets{
    private:
    pcap_t* handle;
    u_char* user;
    std::vector<std::vector<u_char>> cache;

    public:
    void capturePackets();
    void show_packet(std::vector<u_char>);
    void save_packet_into_file(const std::string&);
    void save_packet_live(const std::vector<u_char>&);
    CapturePackets();
    ~CapturePackets();

};


#endif // !CAPTURE_PACKETS_HPP