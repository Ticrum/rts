// EFRITS
// project:     rts
// created on:  2024-02-27 - 16:24 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: destroyUnit implementation

#include "clientPlayerInfo.hh"

void ef::ClientPlayerInfo::destroyUnit()
{
    for (int i = 0; i < (int)selectedUnit.size(); i += 1)
    {
        Packet pack;
        pack.type = DESTROY;
        pack.destroy.unitId = selectedUnit[i]->getId();
        pack.destroy.isOther = false;
        pack.destroy.isBuilding = false;
        clientUdp->sendData((char *)&pack, sizeof(Packet), serverConnected);
        playerInfo.destroyUnit(selectedUnit[i], false);
    }
    selectedUnit.clear();
}

