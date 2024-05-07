// EFRITS
// project:     rts
// created on:  2024-02-21 - 11:00 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: computeActions implementation

#include "serverPlayersInfo.hh"

#include <iostream>

void ef::ServerPlayersInfo::computeActions(double realTimePassed)
{
  double timePassed = 0.016;
  while (realTimePassed > 0)
    {
      Packet pack;

      while (serverTcp->loop() && !gameStarted)
	{
	  //std::cout << "client Connected" << std::endl;
	  clientConnected.push_back(serverTcp->getLastConnected());
	  //std::cout << "server" << (int)ntohs(clientConnected.back().sin_port) << std::endl;
	  clientReady.push_back(false);
	  std::shared_ptr<PlayerInfo> tempPlayer;
	  tempPlayer.reset(new PlayerInfo(res, playersInfo.size(), false));
	  playersInfo.push_back(tempPlayer);
	}
      if (gameStarted)
	for (int i = 0; i < (int)playersInfo.size(); i += 1)
	  {
	    updateOther();
	    playersInfo[i]->computeActions(timePassed, res.getWeaponConf(), res.getShotConf(), false, serverUdp, clientConnected[i]);
	  }
      // tcp read
      serverTcp->loop();
      for (int i = 0; i < (int)clientConnected.size(); i += 1)
	{
	  if (!gameStarted && serverTcp->getData((char *)&pack, sizeof(pack), clientConnected[i]) != -1 && pack.type == CLIENTINFO)
	    {
	      //std::cout << "port receve serv : " << pack.clientInfo.port << std::endl;
	      clientConnected[i].sin_port = htons(pack.clientInfo.port);
	      serverUdp->loop();
	      serverUdp->sendData("test", 4, clientConnected[i]);
	    }
	}

      // udp read
      serverUdp->loop();
      while (serverUdp->getData((char *)&pack, sizeof(pack)) != -1)
	{
	  //std::cout << "packet receve serv : " << pack.type << std::endl;
	  int playerId = -1;
	  for (int i = 0; i < (int)clientConnected.size(); i += 1)
	    {
	      struct sockaddr_in tempAddr = serverUdp->getSender();
	      if (clientConnected[i].sin_port == tempAddr.sin_port && memcmp((char *)&clientConnected[i].sin_addr, (char *)&tempAddr.sin_addr, sizeof(in_addr)) == 0)
		playerId = i;
	    }
	  if (playerId != -1)
	    {
	      if (!gameStarted)
		{
		  //std::cout << "serv pass check" << std::endl;
		  if (pack.type == ISREADY)
		    {
		      //std::cout << "packet is ready" << std::endl;
		      clientReady[playerId] = pack.ready.isReady;
		    }
		  int compt = 0;
		  for (int i = 0; i < (int)clientReady.size(); i += 1)
		    if (clientReady[i])
		      compt += 1;
		  if (compt == (int)clientReady.size())
		    {
		      //std::cout << "GAME HAS STARTED" << std::endl;
		      gameStarted = true;
		      Packet pack;
		      pack.type = GAMESTART;
		      pack.gameStart.isStart = true;
		      for (int i = 0; i < (int)clientConnected.size(); i += 1)
			{
			  serverUdp->sendData((char *)&pack, sizeof(Packet), clientConnected[i]);
			  std::shared_ptr<Building> newBuilding = playersInfo[i]->getFirstBuild();
			  Packet pack2;
			  pack2.type = ADDOTHERBUILDING;
			  pack2.addOtherBuilding.buildId = newBuilding->getId();
			  pack2.addOtherBuilding.alegence = newBuilding->getAlegence();
			  pack2.addOtherBuilding.posi = newBuilding->getPos().get();
			  pack2.addOtherBuilding.len = newBuilding->getConf().size();
			  memcpy(pack2.addOtherBuilding.conf, &newBuilding->getConf()[0], newBuilding->getConf().size());
			  pack2.addOtherBuilding.actualHp = newBuilding->getHp();
			  //std::cout << "build hp is : " << newBuilding->getHp() << std::endl;
			  pack2.addOtherBuilding.isActive = true;
			  pack2.addOtherBuilding.nbrCdr = 0;
			  pack2.addOtherBuilding.isOther = false;
			  serverUdp->loop();
			  serverUdp->sendData((char *)&pack2, sizeof(Packet), clientConnected[i]);
			}
		    }
		}
	      else
		{
		  if (pack.type == MOVEUNIT)
		    makePath(pack.moveUnit.unitId, pack.moveUnit.dest.get(), pack.moveUnit.moveType, playerId);
		  else if (pack.type == SETTARGET)
		    setTarget(pack.setTarget.unitId, pack.setTarget.otherId, playerId, pack.setTarget.isBuilding);
		  else if (pack.type == PLACEBUILD)
		    placeBuilding(pack.placeBuild.pos.get(), playerId);
		  else if (pack.type == PRODUCE)
		    {
		      std::string str(pack.produce.conf, pack.produce.len);
		      //std::cout << "server producing : " << str << std::endl;
		      produce(pack.produce.producerId, str, playerId, pack.produce.buildType);
		    }
		}
	    }
	  serverUdp->loop();
	  //std::cout << "end of loop" << std::endl;
	}
      if (gameStarted)
	{
	  for (int i = 0; i < (int)playersInfo.size(); i += 1)
	    {
	      playersInfo[i]->updateVisionMap();
	      std::vector<std::shared_ptr<ef::Object>> tempObj = playersInfo[i]->finishAction(timePassed);
	      for (int j = 0; j < (int)tempObj.size(); j += 1)
		{
		  pack.type = ADDSHOT;
		  pack.addShot.buildId = tempObj[j]->getId();
		  pack.addShot.alegence = tempObj[j]->getAlegence();
		  pack.addShot.pos = tempObj[j]->getPos().get();
		  pack.addShot.len = tempObj[j]->getConf().size();
		  memcpy(pack.addShot.conf, &tempObj[j]->getConf()[0], pack.addShot.len);
		  pack.addShot.isOther = false;
		  playersInfo[i]->addOtherShot(tempObj[j], false);
		  serverUdp->sendData((char *)&pack, sizeof(Packet), clientConnected[i]);
		  pack.addShot.isOther = true;
		  for (int k = i + 1; k < (int)playersInfo.size() + i; k += 1)
		    if (playersInfo[k % (int)playersInfo.size()]->isInVision(tempObj[j]))
		      {
			playersInfo[k % (int)playersInfo.size()]->addOtherShot(tempObj[j], true);
			serverUdp->sendData((char *)&pack, sizeof(Packet), clientConnected[k % (int)playersInfo.size()]);
		      }
		}
	      //std::cout << "compute shot called serv" << std::endl;
	      playersInfo[i]->computeShot(false);
	      Packet tempPack;
	      std::vector<ef::Killed> & kill = playersInfo[i]->getKillList();
	      for (int j = 0; j < (int)kill.size(); j += 1)
		{
		  tempPack.type = DESTROY;
		  tempPack.destroy.unitId = kill[j].obj->getId();
		  tempPack.destroy.isOther = false;
		  std::shared_ptr<ef::Unit> tempUnit = static_pointer_cast<ef::Unit>(kill[j].obj);
		  if (tempUnit.get() != nullptr)
		    tempPack.destroy.isBuilding = false;
		  else
		    tempPack.destroy.isBuilding = true;
		  serverUdp->loop();
		  if (!serverUdp->sendData((char *)&tempPack, sizeof(Packet), clientConnected[i]))
		    j -= 1;
		  else
		    {
		      std::cout << "serverPlayerInfo send death of unit" << std::endl;
		      tempPack.destroy.isOther = true;
		      std::shared_ptr<Unit> temp;
		      std::shared_ptr<Building> temp2;
		      for (int k = i + 1; k < i + (int)clientConnected.size(); k += 1)
			{
			  if ((temp = playersInfo[k % playersInfo.size()]->getUnit(kill[j].obj->getId(), true)) != nullptr)//playersInfo[k % playersInfo.size()]->isInVision(kill[j].obj))
			    {
			      std::cout << "serverPlayerInfo send to : " << k % clientConnected.size() << std::endl;
			      playersInfo[k % playersInfo.size()]->destroyUnit(temp, true);
			      serverUdp->sendData((char *)&tempPack, sizeof(Packet), clientConnected[k % clientConnected.size()]);
			      playersInfo[i]->destroyUnit(static_pointer_cast<Unit>(kill[j].obj), true);
			    }
			  else if ((temp2 = playersInfo[k % playersInfo.size()]->getBuild(kill[j].obj->getId(), true)) != nullptr)//playersInfo[k % playersInfo.size()]->isInVision(kill[j].obj))
			    {
			      std::cout << "serverPlayerInfo (build) send to : " << k % clientConnected.size() << std::endl;
			      tempPack.destroy.isBuilding = true;
			      playersInfo[k % playersInfo.size()]->destroyBuilding(temp2, true);
			      serverUdp->sendData((char *)&tempPack, sizeof(Packet), clientConnected[k % clientConnected.size()]);
			      playersInfo[i]->destroyBuilding(static_pointer_cast<Building>(kill[j].obj), true);
			    }
			}
		    }
		}
	      kill.clear();
	    }
	}
      realTimePassed -= timePassed;
    }
  //std::cout << "end of FUNC serv" << std::endl;
}

