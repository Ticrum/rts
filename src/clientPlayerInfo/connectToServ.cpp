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
  if (!isConnected)
    {
      clientTcp->loop();
      if (clientTcp->connectClient(ip, port))
	{
	  isConnected = true;
	  serverConnected = clientTcp->getLastConnected();
	  PacketClientInfo pack;
	  pack.type = CLIENTINFO;
	  pack.datalen = sizeof(PacketClientInfo);
	  pack.port = clientPort;
	  clientTcp->loop();
	  clientTcp->sendData((char *)&pack, pack.datalen, serverConnected);
	  clientUdp->sendData((char *)&"test"[0], 4, serverConnected);
	  std::cout << "client" << (int)ntohs(serverConnected.sin_port) << std::endl;
	}
    }
}

