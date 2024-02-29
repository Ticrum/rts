// EFRITS
// project:     rts
// created on:  2024-02-16 - 17:42 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: serverPlayersInfo implementation

#include "serverPlayersInfo.hh"

ef::ServerPlayersInfo::ServerPlayersInfo(int port)
    :
    trueMap(64, 64),
    serverUdp(new UdpConnect(port)),
    serverTcp(new TcpConnect(port)),
    gameStarted(false)
{
}

