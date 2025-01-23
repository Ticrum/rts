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

    unit = playersInfo[playerId]->getUnit(unitId, false);
    if (unit.get() == nullptr)
        return;
    playersInfo[playerId]->stopUnit(unit);
    PacketPathUnit pack;
    pack.type = PATHUNIT;
    pack.datalen = sizeof (PacketPathUnit);
    pack.unitId = unit->getId();
    pack.moveType = STATIC;
    pack.nbrPos = 0;
    for (int i = playerId + 1; i < playerId + (int)clientConnected.size(); i += 1)
        if (playersInfo[i % playersInfo.size()]->isInVision(unit))
            serverUdp->sendData((char *)&pack, pack.datalen, clientConnected[i % clientConnected.size()]);
}

