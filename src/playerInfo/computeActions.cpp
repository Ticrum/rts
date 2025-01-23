// EFRITS
// project:     rts
// created on:  2024-02-13 - 15:36 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: computeActions implementation

#include "playerInfo.hh"

#include <iostream>

std::vector<ef::TargetReturn> ef::PlayerInfo::computeActions(double timePassed,
                                                             std::vector<ConfWeapon> & weaponsConf,
                                                             std::vector<ConfObj> & shotConf,
                                                             bool moveOther,
                                                             std::shared_ptr<UdpConnect> & serverUdp,
                                                             struct sockaddr_in & client)
{
  std::vector<std::shared_ptr<Object>> tempUnits;
  std::vector<std::shared_ptr<Object>> tempBuilds;
  std::vector<TargetReturn> tar;

  for (int i = 0; i < (int)killList.size(); i += 1)
    killList[i].time += timePassed;
  for (int i = 0; i < (int)otherUnits.size(); i += 1)
    tempUnits.push_back(otherUnits[i]);
  for (int i = 0; i < (int)otherBuildings.size(); i += 1)
    tempBuilds.push_back(otherBuildings[i]);
  for (int i = 0; i < (int)buildings.size(); i += 1)
    {
      tar.push_back(buildings[i]->makeTargeting(tempUnits, false));
      tar.push_back(buildings[i]->makeTargeting(tempBuilds, true));
      tar.back().unit = buildings[i];
      for (int compt = 0; compt < (int)tar.back().target.size(); compt += 1)
        {
	  std::shared_ptr<Building> build = std::static_pointer_cast<Building>(tar.back().target[compt]);
	  if (build == nullptr)
	    tar.back().isTargetBuilding.push_back(false);
	  else
	    tar.back().isTargetBuilding.push_back(true);
        }
      if (buildings[i]->getType() == PRODUCTION && actualEnergy >= 0 && units.size() < 100)
	{
	  std::shared_ptr<ProdBuilding> prod = std::static_pointer_cast<ProdBuilding>(buildings[i]);
	  std::shared_ptr<Unit> newUnit = prod->produceUnit(timePassed, weaponsConf, res.getShotConf(), res.getSprit());
	  if (newUnit.get() != nullptr && !moveOther)
	    {
	      units.push_back(newUnit);
	      PacketAddOtherUnit pack;
	      pack.type = ADDOTHERUNIT;
	      pack.datalen = sizeof(PacketAddOtherUnit);
	      pack.unitId = newUnit->getId();
	      pack.alegence = newUnit->getAlegence();
	      pack.posi = newUnit->getPos().get();
	      pack.actualHp = newUnit->getHp();
	      pack.progress = 0;
	      pack.actualIndex = 0;
	      pack.moveType = newUnit->getMoveType();
	      pack.nbrPos = 0;
	      std::vector<double> tempCdr = newUnit->getWeaponsCd();
	      pack.nbrCdr = tempCdr.size();
	      for (int i = 0; i < (int)tempCdr.size(); i += 1)
		pack.cdr[i] = tempCdr[i];
	      pack.isOther = false;
	      pack.len = newUnit->getConf().size();
	      memcpy(pack.conf, &newUnit->getConf()[0], newUnit->getConf().size());
	      serverUdp->loop();
	      serverUdp->sendData((char *)&pack, pack.datalen, client);
	    }
	}
      else if (buildings[i]->getType() == CONSTRUCT)
	{
	  std::shared_ptr<ConstructBuilding> construct = std::static_pointer_cast<ConstructBuilding>(buildings[i]);
	  std::shared_ptr<Building> newBuilding = construct->produceBuilding(timePassed, weaponsConf, shotConf, res.getSprit());
	  if (newBuilding.get() != nullptr)
	    producedBuilding.push_back(newBuilding);
	}
      else if (buildings[i]->getType() == TECH && actualEnergy >= 0)
        {
	  std::shared_ptr<TechBuilding> tech = std::static_pointer_cast<TechBuilding>(buildings[i]);
	  std::shared_ptr<Tech> newTech = tech->searchTech(timePassed);
	  if (newTech.get() != nullptr)
	    searchedTech.push_back(newTech);
        }
    }
  for (int i = 0; i < (int)units.size(); i += 1)
    {
      tar.push_back(units[i]->makeTargeting(tempUnits, false));
      tar.push_back(units[i]->makeTargeting(tempBuilds, true));
      tar.back().unit = units[i];
      for (int compt = 0; compt < (int)tar.back().target.size(); compt += 1)
        {
	  std::shared_ptr<Building> build = std::static_pointer_cast<Building>(tar.back().target[compt]);
	  if (build == nullptr)
	    tar.back().isTargetBuilding.push_back(false);
	  else
	    tar.back().isTargetBuilding.push_back(true);
        }
      units[i]->moveUnit(timePassed, buildingMap);
    }
  if (moveOther)
    {
      /*
      for (int i = 0; i < (int)units.size(); i += 1)
	temp.push_back(units[i]);
      for (int i = 0; i < (int)buildings.size(); i += 1)
	temp.push_back(buildings[i]);
      */
      for (int i = 0; i < (int)otherUnits.size(); i += 1)
        {
	  //otherUnits[i]->makeTargeting(temp);
	  otherUnits[i]->moveUnit(timePassed, buildingMap);
        }
      //for (int i = 0; i < (int)otherBuildings.size(); i += 1)
      //	otherBuildings[i]->makeTargeting(temp);
    }
  if (actualEnergy > 0)
    {
      moneyCooldown -= timePassed;
      if (moneyCooldown < 0)
	{
	  money += moneyGain;
	  moneyCooldown = 0.25;
	}
    }
  //std::cout << "[[[ MAP ]]]" << std::endl;
  //map.print();
  //std::cout << "[[[ BUILDING MAP ]]]" << std::endl;
  //buildingMap.print();
  //std::cout << "[[[ VISION MAP ]]]" << std::endl;
  //visionMap.print();
  return tar;
}

