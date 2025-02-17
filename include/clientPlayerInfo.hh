// EFRITS
// project:     rts
// created on:  2024-02-26 - 16:05 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: clientPlayerInfo header

#ifndef __clientPlayerInfo_HH__
#define __clientPlayerInfo_HH__

#include "playerInfo.hh"
#include "time.h"
#include "apiButton.hh"

namespace ef
{
  class ClientPlayerInfo
  {
  public:
    ClientPlayerInfo(int port, int alegence);
    void computeActions(double realTimePassed);
    void connectToServ(int ip, int port);
    void makePath(Pos dest, MoveType moveType);
    void select(Pos size, Pos start, Pos end, std::function<void(std::string)> func, bool isSame);
    void stopUnit();
    void setTarget(Pos clickPos);
    void placeBuilding(Pos pos);
    void produce(int producerId, std::string unitToProd, BuildingType type);
    void produce(std::string unitToProd);
    void cancel(int producerId, BuildingType type);
    void cancel();
    void destroyUnit();
    void destroyBuilding();
    bool destroyUnit(int unitId, bool isOther);
    bool destroyBuilding(int buildingId, bool isOther);
    void deleteFromKillList(std::shared_ptr<Object> obj);
    void updateSelectedInfo();
    void sendIsReady();
    std::vector<std::shared_ptr<Building>> getSelectedBuildings();
    bool isGameStarted();
    void stockPacket(double timeToPass);

    ResourceManager res;
    ButonManager man;
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
