// EFRITS
// project:     rts
// created on:  2024-02-07 - 11:08 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: loop implementation

#include "tcpConnect.hh"

void ef::TcpConnect::loop()
{
    pollfd fd;
    struct sockaddr_in tempSock;

    fd.fd = accecpt(fds[0].fd, (struct sockaddr *)&tempSock, (socklen_t)s);
    if (fd.fd != -1)
    {
        fd.events = POLLOUT | POLLIN;
        fds.push_back(fd);
        otherSock.push_back(tempSock);
    }
    poll(&fds[0], fds.size(), 1);
}

