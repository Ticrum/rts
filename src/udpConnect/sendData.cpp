// EFRITS
// project:     rts
// created on:  2024-02-06 - 17:09 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: sendData implementation

#include "udpConnect.hh"

bool ef::UdpConnect::sendData(char *data,
                              int len,
                              int ip,
                              int port)
{
    sockGet.sin_port = (in_port_t)htons(port);
    sockGet.sin_addr = (struct in_addr)ip;
    if (fd[0].revents & POLLOUT)
    {
        sendto(fd[0].fd, data, len, 0, (struct sockaddr *)&sockGet, (socklen_t)s);
        return true;
    }
    return false;
}

