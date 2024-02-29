// EFRITS
// project:     rts
// created on:  2024-02-26 - 16:33 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: clientPlayerInfo implementation

#include "clientPlayerInfo.hh"

ef::ClientPlayerInfo::ClientPlayerInfo(int port)
    :
    playerInfo(res),
    clientUdp(new UdpConnect(port)),
    clientTcp(new TcpConnect(port)),
    gameStarted(false),
    isConnected(false)
{
}

