// EFRITS
// project:     rts
// created on:  2024-02-07 - 12:49 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: tcpConnect header

#ifndef __TCPCONNECT_HH__
#define __TCPCONNECT_HH__

#include <sys/socket.h>
#include <poll.h>
#include <vector>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>

#include <stdio.h>

namespace ef
{
    class TcpConnect
    {
    public:
        TcpConnect(int port);
        bool loop();
        bool sendData(char *data, int len, struct sockaddr_in addr);
        int getData(char *data, int len, struct sockaddr_in addr);
        bool connectClient(int ip, int port);
        struct sockaddr_in getLastConnected();
        std::vector<struct sockaddr_in> getAllConnected();
        ~TcpConnect();

    protected:
        size_t s;
        std::vector<struct sockaddr_in> otherSock;
        std::vector<struct pollfd> fds;
        struct sockaddr_in mySock;
    };
}; // !ef

#endif // __TCPCONNECT_HH__
