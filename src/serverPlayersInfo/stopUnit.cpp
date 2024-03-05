// EFRITS
// project:     rts
// created on:  2024-02-19 - 18:06 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: stopUnit implementation

#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::stopUnit(int unitId,
                                     int playerId)
{
    std::shared_ptr<Unit> unit;

    unit = playersInfo[playerId]->getUnit(unitId);
    if (unit.get() == nullptr)
        return;
    playersInfo[playerId]->stopUnit(unit);
    Packet pack;
    pack.type = PATHUNIT;
    pack.pathUnit.unitId = unit->getId();
    pack.pathUnit.moveType = STATIC;
    pack.pathUnit.nbrPos = 0;
    for (int i = playerId + 1; i < playerId + (int)clientConnected.size(); i += 1)
        if (playersInfo[i % playersInfo.size()]->isInVision(unit))
            serverUdp->sendData((char *)&pack, sizeof(Packet), clientConnected[i % clientConnected.size()]);
}

