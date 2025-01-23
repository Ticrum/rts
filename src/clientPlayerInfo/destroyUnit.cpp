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
        PacketDestroy pack;
        pack.type = DESTROY;
	pack.datalen = sizeof(PacketDestroy);
        pack.unitId = selectedUnit[i]->getId();
        pack.isOther = false;
        pack.isBuilding = false;
        clientUdp->sendData((char *)&pack, pack.datalen, serverConnected);
        playerInfo.destroyUnit(selectedUnit[i], false);
    }
    selectedUnit.clear();
}

