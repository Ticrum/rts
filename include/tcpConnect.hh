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

namespace ef
{
    class TcpConnect
    {
    public:
        TcpConnect();
        void loop();
        bool sendData(char *data, int len, int ip, int port);
        int getData(char *data, int len, int ip, int port);
        bool connect(int ip, int port);

    protected:
        size_t s;
        vector<struct sockaddr_in> otherSock;
        vector<struct pollfd> fds;
        struct sockaddr_in mySock;
    };
}; // !ef

#endif // __TCPCONNECT_HH__
