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
		if (tempKill[i].time >= 1)
		  {
		    //std::cout << "computeAction rea unit ou build" << std::endl;
		    /*std::shared_ptr<Unit> tempUnit;
		    std::shared_ptr<Building> tempBuilding;
		    if ((tempUnit = std::static_pointer_cast<Unit>(tempKill[i].obj)).get() != nullptr)
		      playerInfo.addOther(tempUnit, tempKill[i].isOther);
		    else if ((tempBuilding = std::static_pointer_cast<Building>(tempKill[i].obj)).get() != nullptr)
		      playerInfo.addOther(tempBuilding, tempKill[i].isOther);
		    */
		    deleteFromKillList(tempKill[i].obj);
		  }
	      playerInfo.updateOther();
	      // UPDATING OTHERUNITS BY FORCE
	      playerInfo.increaseUpdateIndex();
	      std::shared_ptr<Unit> tempUnit = playerInfo.getUnitToUpdate();
	      if (tempUnit.get() != nullptr)
		{
		  PacketSync pack2;
		  
		  pack2.type = SYNC;
		  pack2.datalen = sizeof(PacketSync);
		  pack2.unitId = tempUnit->getId();
		  pack2.alegence = playerInfo.getAlegence();
		  
		  clientUdp->sendData((char *)&pack2, pack2.datalen, serverConnected);
		}
	    }
	  clientUdp->loop();
	  while (clientUdp->getData((char *)&pack, sizeof(pack)) != -1)
	    {
	      //std::cout << "receve PACKET cli : " << pack.type << std::endl;
	      if (pack.type == GAMESTART && ((PacketGameStart *)&pack)->isStart)
		gameStarted = true;
	      if (gameStarted)
		{
		  if (pack.type == DESTROY)
		    {
		      //std::cout << "receve destroy" << std::endl;
		      if (((PacketDestroy *)&pack)->isBuilding)
			{
			  std::shared_ptr<Building> tempBuild = playerInfo.getBuild(((PacketDestroy *)&pack)->unitId, ((PacketDestroy *)&pack)->isOther);
			  if (tempBuild.get() != nullptr)
			    {
			      //std::cout << "computeAction tempBuild pos x : " << tempBuild->getPos().x << " y : " << tempBuild->getPos().y << std::endl;
			      playerInfo.destroyBuilding(tempBuild, ((PacketDestroy *)&pack)->isOther);
			      deleteFromKillList(tempBuild);
			    }
			}
		      else
			{
			  std::shared_ptr<Unit> tempUnit = playerInfo.getUnit(((PacketDestroy *)&pack)->unitId, ((PacketDestroy *)&pack)->isOther);
			  if (tempUnit.get() != nullptr)
			    {
			      //std::cout << "computeAction tempUnit pos x : " << tempUnit->getActualPos().x << " y : " << tempUnit->getActualPos().y << std::endl;
			      playerInfo.destroyUnit(tempUnit, ((PacketDestroy *)&pack)->isOther);
			      deleteFromKillList(tempUnit);
			    }
			}
		    }
		  else if (pack.type == ADDOTHERUNIT)
		    {
		      //std::cout << "receve addUnit" << std::endl;
		      std::shared_ptr<Unit> tempUnit;
		      std::string confName(((PacketAddOtherUnit *)&pack)->conf, ((PacketAddOtherUnit *)&pack)->len);
		      ConfUnit conf = res.getUnit(confName);
		      std::vector<Pos> path;
		      for (int i = 0; i < ((PacketAddOtherUnit *)&pack)->nbrPos; i += 1)
			path.push_back(((PacketAddOtherUnit *)&pack)->pos[i].get());
		      std::vector<double> cdr;
		      for (int i = 0; i < ((PacketAddOtherUnit *)&pack)->nbrCdr; i += 1)
			cdr.push_back(((PacketAddOtherUnit *)&pack)->cdr[i]);
		      tempUnit.reset(new Unit(conf, res.getSprit()[conf.img], ((PacketAddOtherUnit *)&pack)->posi.get(), ((PacketAddOtherUnit *)&pack)->unitId, ((PacketAddOtherUnit *)&pack)->alegence, res.getWeaponConf(), res.getShotConf(), ((PacketAddOtherUnit *)&pack)->actualHp, ((PacketAddOtherUnit *)&pack)->progress, ((PacketAddOtherUnit *)&pack)->actualIndex, ((PacketAddOtherUnit *)&pack)->moveType, path, cdr));
		      if (((PacketAddOtherUnit *)&pack)->isUpdating)
			{
			  std::shared_ptr<Unit> tempUnit2 = playerInfo.getUnit(((PacketAddOtherUnit *)&pack)->unitId, true);
			  if (tempUnit2.get() != nullptr)
			    {
			      //std::cout << "computeAction tempUnit pos x : " << tempUnit->getActualPos().x << " y : " << tempUnit->getActualPos().y << std::endl;
			      playerInfo.destroyUnit(tempUnit2, ((PacketDestroy *)&pack)->isOther);
			      deleteFromKillList(tempUnit2);
			    }
			}
		      playerInfo.addOther(tempUnit, ((PacketAddOtherUnit *)&pack)->isOther);
		    }
		  else if (pack.type == ADDOTHERBUILDING)
		    {
		      //std::cout << "receve addBuilding" << std::endl;
		      std::shared_ptr<Building> tempBuilding;
		      std::string confName(((PacketAddOtherBuilding *)&pack)->conf, ((PacketAddOtherBuilding *)&pack)->len);
		      ConfBuilding conf = res.getBuild(confName);
		      std::vector<double> cdr;
		      for (int i = 0; i < ((PacketAddOtherBuilding *)&pack)->nbrCdr; i += 1)
			cdr.push_back(((PacketAddOtherBuilding *)&pack)->cdr[i]);
		      if (conf.type == PRODUCTION)
			tempBuilding.reset(new ProdBuilding(conf, res.getSprit()[conf.img], ((PacketAddOtherBuilding *)&pack)->posi.get(), ((PacketAddOtherBuilding *)&pack)->buildId, ((PacketAddOtherBuilding *)&pack)->alegence, res.getWeaponConf(), res.getShotConf(), ((PacketAddOtherBuilding *)&pack)->actualHp, cdr));
		      else if (conf.type == CONSTRUCT)
			tempBuilding.reset(new ConstructBuilding(conf, res.getSprit()[conf.img], ((PacketAddOtherBuilding *)&pack)->posi.get(), ((PacketAddOtherBuilding *)&pack)->buildId, ((PacketAddOtherBuilding *)&pack)->alegence, res.getWeaponConf(), res.getShotConf(), ((PacketAddOtherBuilding *)&pack)->actualHp, cdr));
		      else if (conf.type == TECH)
			tempBuilding.reset(new TechBuilding(conf, res.getSprit()[conf.img], ((PacketAddOtherBuilding *)&pack)->posi.get(), ((PacketAddOtherBuilding *)&pack)->buildId, ((PacketAddOtherBuilding *)&pack)->alegence, res.getWeaponConf(), res.getShotConf(), ((PacketAddOtherBuilding *)&pack)->actualHp, cdr));
		      else
			tempBuilding.reset(new Building(conf, res.getSprit()[conf.img], ((PacketAddOtherBuilding *)&pack)->posi.get(), ((PacketAddOtherBuilding *)&pack)->buildId, ((PacketAddOtherBuilding *)&pack)->alegence, res.getWeaponConf(), res.getShotConf(), ((PacketAddOtherBuilding *)&pack)->actualHp, cdr));

		      //std::cout << "Placed building is other : " << pack.addOtherBuilding.isOther << std::endl;
		      playerInfo.addOther(tempBuilding, ((PacketAddOtherBuilding *)&pack)->isOther);
		    }
		  else if (pack.type == UPDATETARGET)
		    {
		      //std::cout << "receve updateTarget" << std::endl;
		      std::shared_ptr<Unit> tempUnit = nullptr;
		      std::shared_ptr<Building> tempBuild = nullptr;
		      std::vector<std::shared_ptr<Object>> targets;
		      if (!((PacketUpdateTarget *)&pack)->isBuilding && ((PacketUpdateTarget *)&pack)->isEnemy)
			tempUnit = std::static_pointer_cast<Unit>(playerInfo.getOtherObject(((PacketUpdateTarget *)&pack)->unitId, false));
		      else if (((PacketUpdateTarget *)&pack)->isBuilding && ((PacketUpdateTarget *)&pack)->isEnemy)
			tempBuild = std::static_pointer_cast<Building>(playerInfo.getOtherObject(((PacketUpdateTarget *)&pack)->unitId, true));
		      if (tempBuild != nullptr || tempUnit != nullptr)
			{
			  for (int i = 0; i < ((PacketUpdateTarget *)&pack)->otherLen; i += 1)
			    {
			      std::shared_ptr<Object> tempObj = playerInfo.getOtherObject(((PacketUpdateTarget *)&pack)->otherId[i], ((PacketUpdateTarget *)&pack)->isEnemyBuilding[i]);
			      if (tempObj.get() == nullptr && !((PacketUpdateTarget *)&pack)->isEnemyBuilding[i])
				tempObj = playerInfo.getUnit(((PacketUpdateTarget *)&pack)->otherId[i], false);
			      else if (tempObj.get() == nullptr && ((PacketUpdateTarget *)&pack)->isEnemyBuilding[i])
				tempObj = playerInfo.getBuild(((PacketUpdateTarget *)&pack)->otherId[i], false);
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
		      //std::cout << "receve addShot at pos x : " << pack.addShot.pos.get().x << " y : " << pack.addShot.pos.get().y << std::endl;
		      std::shared_ptr<Object> tempObj;
		      std::string str(((PacketAddShot *)&pack)->conf, ((PacketAddShot *)&pack)->len);
		      ConfObj tempConf = res.getShot(str);
		      tempObj.reset(new Object(tempConf, res.getSprit()[tempConf.img], ((PacketAddShot *)&pack)->pos.get(), ((PacketAddShot *)&pack)->buildId, ((PacketAddShot *)&pack)->alegence));
		      playerInfo.addOtherShot(tempObj, ((PacketAddShot *)&pack)->isOther);
		    }
		  else if (pack.type == PATHUNIT)
		    {
		      //std::cout << "receve pathUnit" << std::endl;
		      std::shared_ptr<Unit> tempOUnit = std::static_pointer_cast<Unit>(playerInfo.getOtherObject(((PacketPathUnit *)&pack)->unitId, false));
		      if (tempOUnit.get() != nullptr)
			{
			  //std::cout << "!!!!!!!! compAction GET OBJ GOOD !!!!!!!!" << std::endl;
			  std::vector<Pos> tempPath;
			  for (int i = 0; i < ((PacketPathUnit *)&pack)->nbrPos; i += 1)
			    tempPath.push_back(((PacketPathUnit *)&pack)->pos[i].get());
			  tempOUnit->changePath(tempPath, ((PacketPathUnit *)&pack)->moveType);
			  std::vector<ConformPos> newPos = tempOUnit->getPathLeft();
			  //std::cout << "computeActionClient start Pos x : " << newPos[(int)newPos.size() - 1].x << " y : " << newPos[(int)newPos.size() - 1].y << " end x : " << newPos[0].x << " y : " << newPos[0].y << std::endl;
			  //std::cout << "computeActionClient pack start Pos x : " << pack.pathUnit.pos[0].x << " y : " << pack.pathUnit.pos[0].y << " end x : " << pack.pathUnit.pos[(int)newPos.size() - 1].x << " y : " << pack.pathUnit.pos[(int)newPos.size() - 1].y << std::endl;
			}
		    }
		}
	      clientUdp->loop();
	      //std::cout << "PACKET cli FIN" << std::endl;
	    }
	  if (gameStarted)
	    {
	      playerInfo.computeActions(timePassed, res.getWeaponConf(), res.getShotConf(), true, clientUdp, serverConnected);
	      playerInfo.updateVisionMap();
	      playerInfo.computeShot(true);
	    }
	}
      realTimePassed -= timePassed;
    }
  //std::cout << "end of FUNC client" << std::endl;
}


