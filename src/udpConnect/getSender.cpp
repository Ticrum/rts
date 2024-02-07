// EFRITS
// project:     rts
// created on:  2024-02-06 - 17:41 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getSender implementation

#include "udpConnect.hh"

struct sockaddr_in ef::UdpConnect::getSender()
{
    return sockGet;
}

