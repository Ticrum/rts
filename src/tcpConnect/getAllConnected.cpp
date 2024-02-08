// EFRITS
// project:     rts
// created on:  2024-02-08 - 17:53 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getAllConnected implementation

#include "tcpConnect.hh"

std::vector<struct sockaddr_in> ef::TcpConnect::getAllConnected()
{
    return otherSock;
}


