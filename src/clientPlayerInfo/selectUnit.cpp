// EFRITS
// project:     rts
// created on:  2024-02-27 - 11:27 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: selectUnit implementation

#include "clientPlayerInfo.hh"

void ef::ClientPlayerInfo::select(Pos start,
                                  Pos end,
				  std::function<void(std::string)> func)
{
  if (selectedBuilding.size() > 0)
    selectedBuilding[0]->removeButon(man);
  selectedUnit = playerInfo.selectUnit(start, end);
  selectedBuilding = playerInfo.selectBuilding(start, end);
  if (selectedBuilding.size() > 0)
    selectedBuilding[0]->displayButon(man, func, res.getSprit());
}

