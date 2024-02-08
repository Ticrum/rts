// EFRITS
// project:     rts
// created on:  2024-02-07 - 11:35 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getData implementation

#include "tcpConnect.hh"

int ef::TcpConnect::getData(char *data,
                            int len,
                            int ip,
                            int port)
{
    in_port_t tempPort = (in_port_t)htons(port);
    struct in_addr tempIp = (struct in_addr)ip;
    for (int i = 0; i < (int)otherSock.size(); i += 1)
        if (tempPort == otherSock[i].sin_port && memcmp((char *)&tempIp, (char *)&otherSock[i].sin_addr, 4) == 0 && fds[i + 1].revents & POLLIN)
            return recv(fds[i + 1].fd, data, len, 0);
    return -1;
}

