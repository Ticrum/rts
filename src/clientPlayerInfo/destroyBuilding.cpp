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
        Packet pack;
        pack.type = DESTROY;
        pack.destroy.unitId = selectedBuilding[i]->getId();
        pack.destroy.isOther = false;
        pack.destroy.isBuilding = true;
        clientUdp->sendData((char *)&pack, sizeof(Packet), serverConnected);
        playerInfo.destroyBuilding(selectedBuilding[i], false);
    }
    selectedBuilding.clear();
}

