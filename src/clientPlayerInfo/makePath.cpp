// EFRITS
// project:     rts
// created on:  2024-02-27 - 10:54 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: makePath implementation

#include "clientPlayerInfo.hh"

void ef::ClientPlayerInfo::makePath(Pos dest,
                                    MoveType moveType)
{
    for (int i = 0; i < (int)selectedUnit.size(); i += 1)
    {
        playerInfo.makePath(selectedUnit[i], dest, moveType);
        Packet pack;
        pack.type = MOVEUNIT;
        pack.moveUnit.unitId = selectedUnit[i]->getId();
        pack.moveUnit.dest = dest.get();
        pack.moveUnit.moveType = moveType;
        clientUdp->sendData((char *)&pack, sizeof(Packet), serverConnected);
    }
}

