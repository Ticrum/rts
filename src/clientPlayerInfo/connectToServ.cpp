// EFRITS
// project:     rts
// created on:  2024-02-26 - 17:04 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: connectToServ implementation

#include "clientPlayerInfo.hh"

void ef::ClientPlayerInfo::connectToServ(int ip,
                                         int port)
{
    clientTcp->loop();
    if (clientTcp->connectClient(ip, port))
    {
        isConnected = true;
        serverConnected = clientTcp->getLastConnected();
    }
}

