// EFRITS
// project:     rts
// created on:  2024-02-27 - 10:54 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: makePath implementation

#include "clientPlayerInfo.hh"
#include <iostream>

static ef::Pos groupDest(ef::Pos dest,
			 int i,
			 int max)
{
  double realLenght = sqrt(max);
  int lenght = (int)sqrt(max);
  if (realLenght != (int)sqrt(max))
    lenght += 1;
  dest.x = dest.x - (lenght / 2 + i % lenght) + (lenght / 2);
  if (dest.x < 0)
    dest.x = 0;
  dest.y = dest.y - (lenght / 2 + i / lenght) + (lenght / 2);
  if (dest.y < 0)
    dest.y = 0;
  //std::cout << "makePath groupDest x=" << dest.x << " y=" << dest.y << " y < 0? " << (dest.y < 0) << std::endl;
  return dest;
}

void ef::ClientPlayerInfo::makePath(Pos dest,
                                    MoveType moveType)
{
  if (selectedUnit.size() == 0)
    return;
  for (int i = 0; i < (int)selectedUnit.size(); i += 1)
    {
      Pos tempDest = groupDest(dest, i, (int)selectedUnit.size());
      //std::cout << "makePath x=" << tempDest.x << " y=" << tempDest.y << std::endl;
      /*
      if (i % 5 == 1)
	tempDest.x += 1;
      else if (i % 5 == 2)
	tempDest.y += 1;
      else if (i % 5 == 3)
	tempDest.x -= 1;
      else if (i % 5 == 4)
	tempDest.y -= 1;
      */
      playerInfo.makePath(selectedUnit[i], tempDest, moveType);
      PacketMoveUnit pack;
      pack.type = MOVEUNIT;
      pack.datalen = sizeof(PacketMoveUnit);
      pack.unitId = selectedUnit[i]->getId();
      pack.dest = tempDest.get();
      pack.moveType = moveType;
      clientUdp->sendData((char *)&pack, pack.datalen, serverConnected);
    }
}

