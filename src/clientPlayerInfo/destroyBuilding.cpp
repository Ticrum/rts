// EFRITS
// project:     rts
// created on:  2024-02-27 - 16:44 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: destroyBuilding implementation

#include "clientPlayerInfo.hh"

void ef::ClientPlayerInfo::destroyBuilding()
{
    for (int i = 0; i < (int)selectedBuilding.size(); i += 1)
    {
        PacketDestroy pack;
        pack.type = DESTROY;
	pack.datalen = sizeof(PacketDestroy);
        pack.unitId = selectedBuilding[i]->getId();
        pack.isOther = false;
        pack.isBuilding = true;
        clientUdp->sendData((char *)&pack, pack.datalen, serverConnected);
        playerInfo.destroyBuilding(selectedBuilding[i], false);
    }
    selectedBuilding.clear();
}

