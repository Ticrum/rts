// EFRITS
// project:     rts
// created on:  2024-02-07 - 12:00 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: connect implementation

#include "tcpConnect.hh"

bool ef::TcpConnect::connect(int ip, int port)
{
    struct pollfd fd;
    struct sockaddr_in tempSock;

    fd.events = POLLOUT | POLLIN;
    tempSock.sin_family = AF_INET;
    tempSock.sin_port = (in_port_t)htons(port);
    tempSock.sin_addr = (struct in_addr)ip;
    if (connect(fd.fd, (struct sockaddr *)&tempSock, (socklen_t)s) != -1)
    {
        fds.push_back(fd);
        otherSock.push_back(tempSock);
        return true;
    }
    return false;
}

