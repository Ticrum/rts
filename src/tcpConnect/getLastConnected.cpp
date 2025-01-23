// EFRITS
// project:     rts
// created on:  2024-02-08 - 11:48 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getLastConnected implementation

#include "tcpConnect.hh"

struct sockaddr_in ef::TcpConnect::getLastConnected()
{
    struct sockaddr_in temp;

    int temp2 = 0;

    temp.sin_family = AF_INET;
    temp.sin_port = (in_port_t)0;
    temp.sin_addr = *((in_addr *)&temp);
    if ((int)otherSock.size() == 0)
        return temp;
    return otherSock.back();
}

