// EFRITS
// project:     rts
// created on:  2024-02-14 - 16:01 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: makePath implementation

#include "pathfinder.hh"

#include <iostream>

/*
static void print_map(ef::Map map)
{
    for (int i = 0; i < map.getMapSize().x * map.getMapSize().y; i += 1)
    {
        if (i % map.getMapSize().x == 0)
            printf("\n");
        printf("%c", map[i] + '0');
    }
}
*/
std::vector<ef::Pos> ef::Pathfinder::makePath(Pos start,
                                              Pos end)
{
  std::shared_ptr<Cell> tempCell;
  std::shared_ptr<Cell> bestCell = nullptr;
  int lastDist = 999999;
  std::vector<Pos> out;

  tempCell.reset(new Cell());
  tempCell->lastCell = nullptr;
  tempCell->pos = start;
  tempCell->dist = 0;
  checkIndex = 0;
  checking.clear();
  checking.push_back(tempCell);
  while (1)
    {
      if ((int)checking.size() > 0 && checkIndex < (int)checking.size())
	{
	  //std::cout << "makePath set new best" << std::endl;
	  int newDist = abs(checking[checkIndex]->pos.x - end.x) + abs(checking[checkIndex]->pos.y - end.y);
	  if (newDist < lastDist)
	    {
	      bestCell = checking[checkIndex];
	      lastDist = newDist;
	    }
	}
      if (checkIndex >= (int)checking.size())
        {
	  if (bestCell == nullptr)
	    {
	      //std::cout << "makePath no best cell" << std::endl;
	      return out;
	    }
	  std::shared_ptr<Cell> tempptr;
	  tempptr = bestCell;
	  while (start.isInRange(tempptr->pos, 0, 0) == -1)
            {
	      out.push_back(tempptr->pos);
	      tempptr = tempptr->lastCell;
            }
	  return out;
        }
      //printf("pass %d %d\n", checking[checkIndex]->pos.x, checking[checkIndex]->pos.y);
      if (end.isInRange(checking[checkIndex]->pos, 0, 0) != -1)
        {
	  //printf("finishing\n");
	  std::shared_ptr<Cell> tempptr;
	  tempptr = checking[checkIndex];
	  //printf("start loop\n");
	  while (start.isInRange(tempptr->pos, 0, 0) == -1)
            {
	      //printf("loop\n");
	      out.push_back(tempptr->pos);
	      tempptr = tempptr->lastCell;
            }
	  //printf("end loop\n");
	  //out.push_back(start);
	  return out;
        }
      // up
      if (checking[checkIndex]->pos.y > 0 && (map[checking[checkIndex]->pos.x + (checking[checkIndex]->pos.y - 1) * map.getMapSize().x] == 0 || map[checking[checkIndex]->pos.x + (checking[checkIndex]->pos.y - 1) * map.getMapSize().x] == 3))
        {
	  //printf("go top\n");
	  expendBorder(checking[checkIndex]->pos.x + (checking[checkIndex]->pos.y - 1) * map.getMapSize().x, 0);
        }
      // up right
      if (checking[checkIndex]->pos.y > 0 && checking[checkIndex]->pos.x < map.getMapSize().x - 1 && (map[checking[checkIndex]->pos.x + 1 + (checking[checkIndex]->pos.y - 1) * map.getMapSize().x] == 0 || map[checking[checkIndex]->pos.x + 1 + (checking[checkIndex]->pos.y - 1) * map.getMapSize().x] == 3))
        {
	  //printf("go top\n");
	  expendBorder(checking[checkIndex]->pos.x + 1 + (checking[checkIndex]->pos.y - 1) * map.getMapSize().x, 1);
        }
      // right
      if (checking[checkIndex]->pos.x < map.getMapSize().x - 1 && (map[checking[checkIndex]->pos.x + 1 + checking[checkIndex]->pos.y * map.getMapSize().x] == 0 || map[checking[checkIndex]->pos.x + 1 + checking[checkIndex]->pos.y * map.getMapSize().x] == 3))
        {
	  //printf("go right\n");
	  expendBorder(checking[checkIndex]->pos.x + 1 + checking[checkIndex]->pos.y * map.getMapSize().x, 2);
        }
      // down right
      if (checking[checkIndex]->pos.x < map.getMapSize().x - 1 && checking[checkIndex]->pos.y < map.getMapSize().y - 1 && (map[checking[checkIndex]->pos.x + 1 + (checking[checkIndex]->pos.y + 1) * map.getMapSize().x] == 0 || map[checking[checkIndex]->pos.x + 1 + (checking[checkIndex]->pos.y + 1) * map.getMapSize().x] == 3))
        {
	  //printf("go right\n");
	  expendBorder(checking[checkIndex]->pos.x + 1 + (checking[checkIndex]->pos.y + 1) * map.getMapSize().x, 3);
        }
      // down
      if (checking[checkIndex]->pos.y < map.getMapSize().y - 1 && (map[checking[checkIndex]->pos.x + (checking[checkIndex]->pos.y + 1) * map.getMapSize().x] == 0 || map[checking[checkIndex]->pos.x + (checking[checkIndex]->pos.y + 1) * map.getMapSize().x] == 3))
        {
	  //printf("go down\n");
	  expendBorder(checking[checkIndex]->pos.x + (checking[checkIndex]->pos.y + 1) * map.getMapSize().x, 4);
        }
      // down left
      if (checking[checkIndex]->pos.y < map.getMapSize().y - 1 && checking[checkIndex]->pos.x > 0 && (map[checking[checkIndex]->pos.x - 1 + (checking[checkIndex]->pos.y + 1) * map.getMapSize().x] == 0 || map[checking[checkIndex]->pos.x - 1 + (checking[checkIndex]->pos.y + 1) * map.getMapSize().x] == 3))
        {
	  //printf("go down\n");
	  expendBorder(checking[checkIndex]->pos.x - 1 + (checking[checkIndex]->pos.y + 1) * map.getMapSize().x, 5);
        }
      // left
      if (checking[checkIndex]->pos.x > 0 && (map[checking[checkIndex]->pos.x - 1 + checking[checkIndex]->pos.y * map.getMapSize().x] == 0 || map[checking[checkIndex]->pos.x - 1 + checking[checkIndex]->pos.y * map.getMapSize().x] == 3))
        {
	  //printf("go left\n");
	  expendBorder(checking[checkIndex]->pos.x - 1 + checking[checkIndex]->pos.y * map.getMapSize().x, 6);
        }
      // up left
      if (checking[checkIndex]->pos.x > 0 && checking[checkIndex]->pos.y > 0 && (map[checking[checkIndex]->pos.x - 1 + (checking[checkIndex]->pos.y - 1) * map.getMapSize().x] == 0 || map[checking[checkIndex]->pos.x - 1 + (checking[checkIndex]->pos.y - 1) * map.getMapSize().x] == 3))
        {
	  //printf("go left\n");
	  expendBorder(checking[checkIndex]->pos.x - 1 + (checking[checkIndex]->pos.y - 1) * map.getMapSize().x, 7);
        }
      map[checking[checkIndex]->pos.x + checking[checkIndex]->pos.y * map.getMapSize().x] = 2;
      //printf("\n");
      //print_map(map);
      //usleep(0.1e6);
      checkIndex += 1;
    }
  checking.clear();
  checkIndex = 0;
  return out;
}

