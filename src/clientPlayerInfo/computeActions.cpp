// EFRITS
// project:     rts
// created on:  2024-02-26 - 16:43 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: computeActions implementation

#include "clientPlayerInfo.hh"

#include <iostream>

void ef::ClientPlayerInfo::computeActions(double realTimePassed)
{
  double timePassed = 0.016;
  while (realTimePassed > 0)
    {
      Packet pack;

      if (isConnected)
	{
	  if (gameStarted)
	    {
	      std::vector<Killed> & tempKill = playerInfo.getKillList();
	      for (int i = 0; i < (int)tempKill.size(); i += 1)
		if (tempKill[i].time >= 0.2)
		  {
		    std::shared_ptr<Unit> tempUnit;
		    std::shared_ptr<Building> tempBuilding;
		    if ((tempUnit = std::static_pointer_cast<Unit>(tempKill[i].obj)).get() != nullptr)
		      playerInfo.addOther(tempUnit, tempKill[i].isOther);
		    else if ((tempBuilding = std::static_pointer_cast<Building>(tempKill[i].obj)).get() != nullptr)
		      playerInfo.addOther(tempBuilding, tempKill[i].isOther);
		    deleteFromKillList(tempKill[i].obj);
		  }
	      playerInfo.updateOther();
	    }
	  clientUdp->loop();
	  while (clientUdp->getData((char *)&pack, sizeof(pack)) != -1)
	    {
	      std::cout << "receve PACKET cli : " << pack.type << std::endl;
	      if (pack.type == GAMESTART && pack.gameStart.isStart)
		gameStarted = true;
	      if (gameStarted)
		{
		  if (pack.type == DESTROY)
		    {
		      std::cout << "receve destroy" << std::endl;
		      if (pack.destroy.isBuilding)
			{
			  std::shared_ptr<Building> tempBuild = playerInfo.getBuild(pack.destroy.unitId);
			  if (tempBuild.get() != nullptr)
			    {
			      playerInfo.destroyBuilding(tempBuild, pack.destroy.isOther);
			      deleteFromKillList(tempBuild);
			    }
			}
		      else
			{
			  std::shared_ptr<Unit> tempUnit = playerInfo.getUnit(pack.destroy.unitId);
			  if (tempUnit.get() != nullptr)
			    {
			      playerInfo.destroyUnit(tempUnit, pack.destroy.isOther);
			      deleteFromKillList(tempUnit);
			    }
			}
		    }
		  else if (pack.type == ADDOTHERUNIT)
		    {
		      std::cout << "receve addUnit" << std::endl;
		      std::shared_ptr<Unit> tempUnit;
		      std::string confName(pack.addOtherUnit.conf, pack.addOtherUnit.len);
		      ConfUnit conf = res.getUnit(confName);
		      std::vector<Pos> path;
		      for (int i = 0; i < pack.addOtherUnit.nbrPos; i += 1)
			path.push_back(pack.addOtherUnit.pos[i].get());
		      std::vector<double> cdr;
		      for (int i = 0; i < pack.addOtherUnit.nbrCdr; i += 1)
			cdr.push_back(pack.addOtherUnit.cdr[i]);
		      tempUnit.reset(new Unit(conf, res.getSprit()[conf.img], pack.addOtherUnit.posi.get(), pack.addOtherUnit.unitId, pack.addOtherUnit.alegence, res.getWeaponConf(), pack.addOtherUnit.actualHp, pack.addOtherUnit.progress, pack.addOtherUnit.actualIndex, pack.addOtherUnit.moveType, path, cdr));
		      playerInfo.addOther(tempUnit, pack.addOtherUnit.isOther);
		    }
		  else if (pack.type == ADDOTHERBUILDING)
		    {
		      std::cout << "receve addBuilding" << std::endl;
		      std::shared_ptr<Building> tempBuilding;
		      std::string confName(pack.addOtherBuilding.conf, pack.addOtherBuilding.len);
		      ConfBuilding conf = res.getBuild(confName);
		      std::vector<double> cdr;
		      for (int i = 0; i < pack.addOtherBuilding.nbrCdr; i += 1)
			cdr.push_back(pack.addOtherBuilding.cdr[i]);
		      if (conf.type == PRODUCTION)
			tempBuilding.reset(new ProdBuilding(conf, res.getSprit()[conf.img], pack.addOtherBuilding.posi.get(), pack.addOtherBuilding.buildId, pack.addOtherBuilding.alegence, res.getWeaponConf(), pack.addOtherBuilding.actualHp, cdr));
		      else if (conf.type == CONSTRUCT)
			tempBuilding.reset(new ConstructBuilding(conf, res.getSprit()[conf.img], pack.addOtherBuilding.posi.get(), pack.addOtherBuilding.buildId, pack.addOtherBuilding.alegence, res.getWeaponConf(), pack.addOtherBuilding.actualHp, cdr));
		      else if (conf.type == TECH)
			tempBuilding.reset(new TechBuilding(conf, res.getSprit()[conf.img], pack.addOtherBuilding.posi.get(), pack.addOtherBuilding.buildId, pack.addOtherBuilding.alegence, res.getWeaponConf(), pack.addOtherBuilding.actualHp, cdr));
		      else
			tempBuilding.reset(new Building(conf, res.getSprit()[conf.img], pack.addOtherBuilding.posi.get(), pack.addOtherBuilding.buildId, pack.addOtherBuilding.alegence, res.getWeaponConf(), pack.addOtherBuilding.actualHp, cdr));

		      std::cout << "Placed building is other : " << pack.addOtherBuilding.isOther << std::endl;
		      playerInfo.addOther(tempBuilding, pack.addOtherBuilding.isOther);
		    }
		  else if (pack.type == UPDATETARGET)
		    {
		      std::cout << "receve updateTarget" << std::endl;
		      std::shared_ptr<Unit> tempUnit = nullptr;
		      std::shared_ptr<Building> tempBuild = nullptr;
		      std::vector<std::shared_ptr<Object>> targets;
		      if (!pack.updateTarget.isBuilding && pack.updateTarget.isEnemy)
			tempUnit = std::static_pointer_cast<Unit>(playerInfo.getOtherObject(pack.updateTarget.unitId, false));
		      else if (pack.updateTarget.isBuilding && pack.updateTarget.isEnemy)
			tempBuild = std::static_pointer_cast<Building>(playerInfo.getOtherObject(pack.updateTarget.unitId, true));
		      if (tempBuild != nullptr || tempUnit != nullptr)
			{
			  for (int i = 0; i < pack.updateTarget.otherLen; i += 1)
			    {
			      std::shared_ptr<Object> tempObj = playerInfo.getOtherObject(pack.updateTarget.otherId[i], pack.updateTarget.isEnemyBuilding[i]);
			      if (tempObj.get() == nullptr && !pack.updateTarget.isEnemyBuilding[i])
				tempObj = playerInfo.getUnit(pack.updateTarget.otherId[i]);
			      else if (tempObj.get() == nullptr && pack.updateTarget.isEnemyBuilding[i])
				tempObj = playerInfo.getBuild(pack.updateTarget.otherId[i]);
			      if (tempObj.get() == nullptr)
				tempObj = dummy;
			      targets.push_back(tempObj);
			    }
			}
		      if (tempUnit != nullptr)
			playerInfo.refreshTarget(tempUnit, targets);
		      else if (tempBuild != nullptr)
			playerInfo.refreshTarget(tempBuild, targets);
		    }
		  else if (pack.type == ADDSHOT)
		    {
		      std::cout << "receve addShot" << std::endl;
		      std::shared_ptr<Object> tempObj;
		      std::string str(pack.addShot.conf, pack.addShot.len);
		      ConfObj tempConf = res.getShot(str);
		      tempObj.reset(new Object(tempConf, res.getSprit()[tempConf.img], pack.addShot.pos.get(), pack.addShot.buildId, pack.addShot.alegence));
		      playerInfo.addOtherShot(tempObj);
		    }
		  else if (pack.type == PATHUNIT)
		    {
		      std::cout << "receve pathUnit" << std::endl;
		      std::shared_ptr<Unit> tempOUnit = std::static_pointer_cast<Unit>(playerInfo.getOtherObject(pack.pathUnit.unitId, false));
		      if (tempOUnit.get() != nullptr)
			{
			  std::vector<Pos> tempPath;
			  for (int i = 0; i < pack.pathUnit.nbrPos; i += 1)
			    tempPath.push_back(pack.pathUnit.pos[i].get());
			  tempOUnit->changePath(tempPath, pack.pathUnit.moveType);
			}
		    }
		}
	      clientUdp->loop();
	      //std::cout << "PACKET cli FIN" << std::endl;
	    }
	  if (gameStarted)
	    {
	      playerInfo.computeActions(timePassed, res.getWeaponConf(), true, clientUdp, serverConnected);
	      playerInfo.updateVisionMap();
	      playerInfo.computeShot(true);
	    }
	}
      realTimePassed -= timePassed;
    }
  //std::cout << "end of FUNC client" << std::endl;
}


