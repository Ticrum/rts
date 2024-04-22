// EFRITS
// project:     rts
// created on:  2024-02-19 - 17:51 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: makePath implementation

#include "serverPlayersInfo.hh"

#include <iostream>

void ef::ServerPlayersInfo::makePath(int unitId,
                                     Pos dest,
                                     MoveType moveType,
                                     int playerId)
{
    std::shared_ptr<Unit> unit;

    std::cout << "!!!!!!!!!!!!!!!!MAKE PATH!!!!!!!!!!!!!!!!!!!" << std::endl;
    unit = playersInfo[playerId]->getUnit(unitId, false);
    if (unit.get() == nullptr)
      return;
    if (moveType == STATIC)
      {
	std::cout << "make Path stop" << std::endl;
        stopUnit(unitId, playerId);
      }
    else
      {
        playersInfo[playerId]->makePath(unit, dest, moveType);
        Packet pack;
        pack.type = PATHUNIT;
        pack.pathUnit.unitId = unit->getId();
        pack.pathUnit.moveType = unit->getMoveType();
        std::vector<ConformPos> newPos = unit->getPathLeft();
	std::cout << "send New path (make path) size : " << newPos.size() << std::endl;
	//for (int i = (int)newPos.size() - 1; i >= 0; i -= 1)
	for (int i = 0; i < (int)newPos.size(); i += 1)
	  pack.pathUnit.pos[newPos.size() - 1 - i] = newPos[i];
	//std::cout << "makePath start Pos x : " << newPos[(int)newPos.size() - 1].x << " y : " << newPos[(int)newPos.size() - 1].y << " end x : " << newPos[0].x << " y : " << newPos[0].y << std::endl;
	//std::cout << "makePath pack start Pos x : " << pack.pathUnit.pos[0].x << " y : " << pack.pathUnit.pos[0].y << " end x : " << pack.pathUnit.pos[(int)newPos.size() - 1].x << " y : " << pack.pathUnit.pos[(int)newPos.size() - 1].y << std::endl;
        pack.pathUnit.nbrPos = newPos.size();
        for (int i = playerId + 1; i < playerId + (int)clientConnected.size(); i += 1)
	  if (playersInfo[i % playersInfo.size()]->isInVision(unit))
	    serverUdp->sendData((char *)&pack, sizeof(Packet), clientConnected[i % clientConnected.size()]);
      }
}

