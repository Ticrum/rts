// EFRITS
// project:     rts
// created on:  2024-02-13 - 15:36 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: computeActions implementation

#include "playerInfo.hh"

std::vector<ef::TargetReturn> ef::PlayerInfo::computeActions(double timePassed,
                                                             std::vector<ConfWeapon> & weaponsConf,
                                                             bool moveOther,
                                                             std::shared_ptr<UdpConnect> & serverUdp,
                                                             struct sockaddr_in & client)
{
  std::vector<std::shared_ptr<Object>> temp;
  std::vector<TargetReturn> tar;

  for (int i = 0; i < (int)otherUnits.size(); i += 1)
    temp.push_back(otherUnits[i]);
  for (int i = 0; i < (int)otherBuildings.size(); i += 1)
    temp.push_back(otherBuildings[i]);
  for (int i = 0; i < (int)buildings.size(); i += 1)
    {
      tar.push_back(buildings[i]->makeTargeting(temp));
      tar.back().unit = buildings[i];
      for (int compt = 0; compt < (int)tar.back().target.size(); compt += 1)
        {
	  std::shared_ptr<Building> build = std::static_pointer_cast<Building>(tar.back().target[compt]);
	  if (build == nullptr)
	    tar.back().isTargetBuilding.push_back(false);
	  else
	    tar.back().isTargetBuilding.push_back(true);
        }
      if (!moveOther)
        {
	  if (buildings[i]->getType() == PRODUCTION)
            {
	      std::shared_ptr<ProdBuilding> prod = std::static_pointer_cast<ProdBuilding>(buildings[i]);
	      std::shared_ptr<Unit> newUnit = prod->produceUnit(timePassed, weaponsConf, res.getSprit());
	      if (newUnit.get() != nullptr)
		units.push_back(newUnit);
	      Packet pack;
	      pack.type = ADDOTHERUNIT;
	      pack.addOtherUnit.unitId = newUnit->getId();
	      pack.addOtherUnit.alegence = newUnit->getAlegence();
	      pack.addOtherUnit.actualHp = newUnit->getHp();
	      pack.addOtherUnit.progress = 0;
	      pack.addOtherUnit.moveType = newUnit->getMoveType();
	      pack.addOtherUnit.nbrPos = 0;
	      pack.addOtherUnit.nbrCdr = 0;
	      pack.addOtherUnit.isOther = false;
	      serverUdp->loop();
	      serverUdp->sendData((char *)&pack, sizeof(Packet), client);
            }
	  else if (buildings[i]->getType() == CONSTRUCT)
            {
	      std::shared_ptr<ConstructBuilding> construct = std::static_pointer_cast<ConstructBuilding>(buildings[i]);
	      std::shared_ptr<Building> newBuilding = construct->produceBuilding(timePassed, weaponsConf,res.getSprit());
	      if (newBuilding.get() != nullptr)
		producedBuilding.push_back(newBuilding);
	      Packet pack;
	      pack.type = ADDOTHERBUILDING;
	      pack.addOtherBuilding.buildId = newBuilding->getId();
	      pack.addOtherBuilding.alegence = newBuilding->getAlegence();
	      pack.addOtherBuilding.actualHp = newBuilding->getHp();
	      pack.addOtherBuilding.isActive = true;
	      pack.addOtherBuilding.nbrCdr = 0;
	      pack.addOtherBuilding.isOther = false;
	      serverUdp->loop();
	      serverUdp->sendData((char *)&pack, sizeof(Packet), client);
            }
        }
      else if (buildings[i]->getType() == TECH)
        {
	  std::shared_ptr<TechBuilding> tech = std::static_pointer_cast<TechBuilding>(buildings[i]);
	  std::shared_ptr<Tech> newTech = tech->searchTech(timePassed);
	  if (newTech.get() != nullptr)
	    searchedTech.push_back(newTech);
        }
    }
  for (int i = 0; i < (int)units.size(); i += 1)
    {
      tar.push_back(units[i]->makeTargeting(temp));
      tar.back().unit = units[i];
      for (int compt = 0; compt < (int)tar.back().target.size(); compt += 1)
        {
	  std::shared_ptr<Building> build = std::static_pointer_cast<Building>(tar.back().target[compt]);
	  if (build == nullptr)
	    tar.back().isTargetBuilding.push_back(false);
	  else
	    tar.back().isTargetBuilding.push_back(true);
        }
      units[i]->moveUnit(timePassed);
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
	  otherUnits[i]->moveUnit(timePassed);
        }
      //for (int i = 0; i < (int)otherBuildings.size(); i += 1)
      //	otherBuildings[i]->makeTargeting(temp);
    }
  moneyCooldown -= timePassed;
  if (moneyCooldown <= 0)
    {
      money += moneyGain;
      moneyCooldown = 0.25;
    }
  return tar;
}

