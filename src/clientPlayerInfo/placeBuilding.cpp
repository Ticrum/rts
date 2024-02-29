// EFRITS
// project:     rts
// created on:  2024-02-27 - 13:06 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: placeBuilding implementation

#include "clientPlayerInfo.hh"

void ef::ClientPlayerInfo::placeBuilding(Pos pos)
{
    playerInfo.placeBuilding(pos);
    Packet pack;
    pack.type = PLACEBUILD;
    pack.placeBuild.pos = pos.get();
    clientUdp->sendData((char *)&pack, sizeof(Packet), serverConnected);
}

