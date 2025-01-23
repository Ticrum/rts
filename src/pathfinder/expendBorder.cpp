// EFRITS
// project:     rts
// created on:  2024-02-15 - 12:26 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: expendBorder implementation

#include "pathfinder.hh"

void ef::Pathfinder::expendBorder(int mapId,
                                  int sens)
{
    std::shared_ptr<Cell> tempCell;
    Pos tempPos;

    tempPos = checking[checkIndex]->pos;
    if (sens == 0)
        tempPos.y -= 1;
    else if (sens == 1)
      {
        tempPos.x += 1;
        tempPos.y -= 1;
      }
    else if (sens == 2)
        tempPos.x += 1;
    else if (sens == 3)
      {
        tempPos.x += 1;
        tempPos.y += 1;
      }
    else if (sens == 4)
        tempPos.y += 1;
    else if (sens == 5)
      {
        tempPos.x -= 1;
        tempPos.y += 1;
      }
    else if (sens == 6)
        tempPos.x -= 1;
    else if (sens == 7)
      {
        tempPos.x -= 1;
        tempPos.y -= 1;
      }
    if (map[mapId] == 3)
    {
        tempCell = getConflictCell(tempPos);
        if (tempCell.get() == nullptr)
        {
            printf("pas trouver\n");
            return;
        }
        if (checking[checkIndex]->dist < tempCell->dist - 1)
            tempCell->lastCell = checking[checkIndex];
    }
    else
    {
        tempCell.reset(new Cell());
        tempCell->lastCell = checking[checkIndex];
        tempCell->pos = tempPos;
        map[tempCell->pos.x + tempCell->pos.y * map.getMapSize().x] = 3;
        tempCell->dist = checking[checkIndex]->dist + 1;
        checking.push_back(tempCell);
    }
}

