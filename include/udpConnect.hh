// EFRITS
// project:     rts
// created on:  2024-02-06 - 16:57 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: udpServer header

#ifndef __UDPCONNECT_HH__
#define __UDPCONNECT_HH__

#include <sys/socket.h>
#include <poll.h>
//#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

namespace ef
{
    class UdpConnect
    {
    public:
        UdpConnect(int port);
        void loop();
        bool sendData(char *data, int len, struct sockaddr_in addr);
        int getData(char *data, int len);
        struct sockaddr_in getSender();
        ~UdpConnect();

    protected:
        size_t s;
        struct pollfd fd[1];
        struct sockaddr_in mySock;
        struct sockaddr_in sockGet;
    };
}; // !ef

#endif // __UDPCONNECT_HH__
