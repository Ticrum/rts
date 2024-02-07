// EFRITS
// project:     rts
// created on:  2024-02-07 - 10:46 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: tcpConnect implementation

#include "tcpConnect.hh"

ef::TcpConnect::TcpConnect(int ip, int port)
    :
    s(sizeof(struct sockaddr)),
{
    fds.push_back(socket(AF_INET, SOCK_STREAM, 0));
    fds[0].events = POLLOUT | POLLIN;
    mySock.sin_family = AF_INET;
    mySock.sin_port = (in_port_t)htons(port);
    mySock.sin_addr = (struct in_addr)INADDR_ANY;
    bind(fds[0], (struct sockaddr *)&mySock, (socklen_t)s);
}

