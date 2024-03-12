// EFRITS
// project:     rts
// created on:  2024-02-26 - 17:04 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: connectToServ implementation

#include "clientPlayerInfo.hh"

#include <iostream>

void ef::ClientPlayerInfo::connectToServ(int ip,
                                         int port)
{
    clientTcp->loop();
    if (clientTcp->connectClient(ip, port))
    {
        isConnected = true;
        serverConnected = clientTcp->getLastConnected();
	Packet pack;
	pack.type = CLIENTINFO;
	pack.clientInfo.port = clientPort;
	clientTcp->loop();
	clientTcp->sendData((char *)&pack, sizeof(Packet), serverConnected);
	clientUdp->sendData("test", 4, serverConnected);
	std::cout << "client" << (int)ntohs(serverConnected.sin_port) << std::endl;
    }
}

