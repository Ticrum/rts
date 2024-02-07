// EFRITS
// project:     rts
// created on:  2024-02-06 - 17:01 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: loop implementation

#include "udpConnect.hh"

void ef::UdpConnect::loop()
{
    poll(fd, 1, 1);
}

