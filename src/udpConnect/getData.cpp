// EFRITS
// project:     rts
// created on:  2024-02-06 - 17:30 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getData implementation

#include "udpConnect.hh"

int ef::UdpConnect::getData(char *data,
                            int len)
{
    if (fd[0].revents & POLLIN)
        return recvfrom(fd[0].fd, data, len, 0, (struct sockaddr *)&sockGet, (socklen_t *)&s);
    return -1;
}

