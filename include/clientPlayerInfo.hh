// EFRITS
// project:     rts
// created on:  2024-02-26 - 16:05 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: clientPlayerInfo header

#ifndef __clientPlayerInfo_HH__
#define __clientPlayerInfo_HH__

#include "playerInfo.hh"
#include "time.h"

namespace ef
{
  class ClientPlayerInfo
  {
  public:
    ClientPlayerInfo(int port, int alegence);
    void computeActions(double realTimePassed);
    void connectToServ(int ip, int port);
    void makePath(Pos dest, MoveType moveType);
    void select(Pos start, Pos end);
    void stopUnit();
    void setTarget(Pos clickPos);
    void placeBuilding(Pos pos);
    void produce(int producerId, std::string unitToProd, BuildingType type);
    void destroyUnit();
    void destroyBuilding();
    bool destroyUnit(int unitId, bool isOther);
    bool destroyBuilding(int buildingId, bool isOther);
    void deleteFromKillList(std::shared_ptr<Object> obj);
    void sendIsReady();

    ResourceManager res;
    PlayerInfo playerInfo;

  private:
    std::shared_ptr<UdpConnect> clientUdp;
    std::shared_ptr<TcpConnect> clientTcp;
    bool gameStarted;
    bool isConnected;
    int clientPort;
    std::shared_ptr<Unit> dummy;
    struct sockaddr_in serverConnected;
    std::vector<std::shared_ptr<Unit>> selectedUnit;
    std::vector<std::shared_ptr<Building>> selectedBuilding;
  };
}

#endif // __clientPlayerInfo_HH__
