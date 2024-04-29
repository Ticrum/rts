// EFRITS
// project:     rts
// created on:  2024-02-27 - 10:54 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: makePath implementation

#include "clientPlayerInfo.hh"

static ef::Pos groupDest(ef::Pos dest,
			 int i,
			 int max)
{
  double realLenght = sqrt(max);
  int lenght = (int)sqrt(max);
  if (realLenght != (int)sqrt(max))
    lenght += 1;
  dest.x = dest.x - lenght / 2 + i % lenght;
  dest.y = dest.y - lenght / 2 + i / lenght;
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
      Packet pack;
      pack.type = MOVEUNIT;
      pack.moveUnit.unitId = selectedUnit[i]->getId();
      pack.moveUnit.dest = tempDest.get();
      pack.moveUnit.moveType = moveType;
      clientUdp->sendData((char *)&pack, sizeof(Packet), serverConnected);
    }
}

