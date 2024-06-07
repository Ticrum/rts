// EFRITS
// project:     rts
// created on:  2024-02-27 - 11:27 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: selectUnit implementation

#include "clientPlayerInfo.hh"

void ef::ClientPlayerInfo::select(Pos size,
				  Pos start,
                                  Pos end,
				  std::function<void(std::string)> func,
				  bool isSame)
{
  if (selectedBuilding.size() > 0)
    selectedBuilding[0]->removeButon(man);
  if (isSame)
    selectedUnit = playerInfo.selectSameUnit(start, end);
  else
    selectedUnit = playerInfo.selectUnit(start, end);
  if (isSame)
    selectedBuilding = playerInfo.selectSameBuilding(start, end);
  else
    selectedBuilding = playerInfo.selectBuilding(start, end);
  if (selectedBuilding.size() > 0)
    selectedBuilding[0]->displayButon(size, man, func, res.getSprit());
}

