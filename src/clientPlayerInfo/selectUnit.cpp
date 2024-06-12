// EFRITS
// project:     rts
// created on:  2024-02-27 - 11:27 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: selectUnit implementation

#include "clientPlayerInfo.hh"
#include <iostream>

void ef::ClientPlayerInfo::select(Pos size,
				  Pos start,
                                  Pos end,
				  std::function<void(std::string)> func,
				  bool isSame)
{
  if (selectedBuilding.size() > 0)
    selectedBuilding[0]->removeInfo(man);
  if (isSame)
    selectedUnit = playerInfo.selectSameUnit(start, end);
  else
    selectedUnit = playerInfo.selectUnit(start, end);
  if (isSame)
    selectedBuilding = playerInfo.selectSameBuilding(start, end);
  else
    selectedBuilding = playerInfo.selectBuilding(start, end);
  if (selectedBuilding.size() > 0)
    {
      selectedBuilding[0]->displayButon(size, man, func, res.getSprit());
      switch(selectedBuilding[0]->getType())
	{
	case CONSTRUCT:
	  //std::cout<< "select unit prod"<< std::endl;
	  std::static_pointer_cast<ef::ConstructBuilding>(selectedBuilding[0])->displayInfo(size, man, func, res.getSprit());
	  break;
	case PRODUCTION:
	  //std::cout<< "select unit prod"<< std::endl;
	  std::static_pointer_cast<ef::ProdBuilding>(selectedBuilding[0])->displayInfo(size, man, func, res.getSprit());
	  break;
	default:
	  //std::cout<< "select unit default"<< std::endl;
	  selectedBuilding[0]->displayInfo(size, man, res.getSprit());
	}
    }
}


