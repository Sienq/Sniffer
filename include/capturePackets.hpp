#include<pcap/pcap.h>
#include<iostream>
#include<memory>
class CapturePackets{
    private:
    pcap_t* handle;

    public:
    void capturePackets();
    CapturePackets();
    ~CapturePackets();
};


