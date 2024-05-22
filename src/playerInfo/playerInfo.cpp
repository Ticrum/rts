// EFRITS
// project:     rts
// created on:  2024-02-12 - 16:53 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: playerinfo implementation

#include "playerInfo.hh"

ef::PlayerInfo::PlayerInfo(ResourceManager & res,
			   int _alegence,
			   bool isClient)
  :
  alegence(_alegence),
  money(1000),
  moneyGain(0),
  moneyCooldown(0.25),
  totalEnergy(0),
  actualEnergy(0),
  map("testMap.dab"),
  buildingMap(64, 64),
  visionMap(64, 64),
  path(buildingMap),
  rallyPoint(nullptr),
  res(res)
{
  buildingMap.clear(0);
  visionMap.clear(0);
  if (!isClient)
    {
      std::shared_ptr<Building> tempBuild;
      ConfBuilding confBuild = res.getBuild("MainBuild");
      Pos tempPos;
      tempPos.x = 5;
      tempPos.y = 5;
      if (alegence == 1)
	tempPos.x = map.getMapSize().x - 6;
      else if (alegence == 2)
	tempPos.y = map.getMapSize().y - 6;
      else if (alegence > 2)
	{
	  tempPos.x = map.getMapSize().x - 6;
	  tempPos.y = map.getMapSize().y - 6;
	}
      tempBuild.reset(new ConstructBuilding(confBuild, res.getSprit()[confBuild.img], tempPos, rand(), alegence, res.getWeaponConf(), res.getShotConf()));
      addOther(tempBuild, false);
    }
}

