// EFRITS
// project:     rts
// created on:  2024-02-19 - 17:51 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: makePath implementation

#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::makePath(int unitId,
                                     Pos dest,
                                     MoveType moveType,
                                     int playerId)
{
    std::shared_ptr<Unit> unit;

    unit = playersInfo[playerId]->getUnit(unitId);
    if (unit.get() == nullptr)
        return;
    playersInfo[playerId]->makePath(unit, dest, moveType);
    Packet pack;
    pack.type = PATHUNIT;
    pack.pathUnit.unitId = unit->getId();
    pack.pathUnit.moveType = unit->getMoveType();
    std::vector<ConformPos> newPos = unit->getPathLeft();
    for (int i = 0; i < (int)newPos.size(); i += 1)
        pack.pathUnit.pos[i] = newPos[i];
    pack.pathUnit.nbrPos = newPos.size();
    for (int i = playerId + 1; i < playerId + (int)clientConnected.size(); i += 1)
        if (playersInfo[i % playersInfo.size()]->isInVision(unit))
            serverUdp->sendData((char *)&pack, sizeof(Packet), clientConnected[i % clientConnected.size()]);

}

