// EFRITS
// project:     rts
// created on:  2024-02-27 - 11:37 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: stopUnit implementation

#include "clientPlayerInfo.hh"

void ef::ClientPlayerInfo::stopUnit()
{
    for (int i = 0; i < (int)selectedUnit.size(); i += 1)
    {
        playerInfo.stopUnit(selectedUnit[i]);
        Packet pack;
        pack.type = MOVEUNIT;
        pack.moveUnit.unitId = selectedUnit[i]->getId();
        pack.moveUnit.dest = selectedUnit[i]->getPos().get();
        pack.moveUnit.moveType = STATIC;
        clientUdp->sendData((char *)&pack, sizeof(Packet), serverConnected);
    }
}

