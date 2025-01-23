// EFRITS
// project:     rts
// created on:  2024-02-06 - 16:56 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: udpconnect implementation

#include "udpConnect.hh"

ef::UdpConnect::UdpConnect(int port)
    :
    s(sizeof(struct sockaddr))
{
    int tempfd;

    int temp2 = INADDR_ANY;

    tempfd = socket(AF_INET, SOCK_DGRAM, 0);
    fd[0].fd = tempfd;
    fd[0].events = POLLOUT | POLLIN;
    mySock.sin_family = AF_INET;
    mySock.sin_port = (in_port_t)htons(port);
    mySock.sin_addr = *((in_addr *)&temp2);
    bind(fd[0].fd, (struct sockaddr *)&mySock, (socklen_t)s);
    sockGet = mySock;
}

ef::UdpConnect::~UdpConnect()
{
    close(fd[0].fd);
}

