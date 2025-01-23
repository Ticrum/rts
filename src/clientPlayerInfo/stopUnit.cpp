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
        PacketMoveUnit pack;
        pack.type = MOVEUNIT;
	pack.datalen = sizeof(PacketMoveUnit);
        pack.unitId = selectedUnit[i]->getId();
        pack.dest = selectedUnit[i]->getPos().get();
        pack.moveType = STATIC;
        clientUdp->sendData((char *)&pack, pack.datalen, serverConnected);
    }
}

