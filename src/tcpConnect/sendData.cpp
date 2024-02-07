// EFRITS
// project:     rts
// created on:  2024-02-07 - 11:13 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: sendData implementation

#include "tcpConnect.hh"

bool ef::TcpConnect::sendData(char *data,
                              int len,
                              int ip,
                              int port)
{
    in_port_t tempPort = (in_port_t)htons(port);
    struct in_addr tempIp = (struct in_addr)ip;
    for (int i = 0; i < otherSock.size(); i += 1)
        if (tempPort == otherSock[i].sin_port && tempIp == otherSock[i].sin_addr && fds[i + 1].revents & POLLOUT)
        {
            send(fds[i + 1].fd, data, len, 0);
            return true;
        }
    return false;
}

