// EFRITS
// project:     rts
// created on:  2024-02-12 - 17:28 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: playerinfo header

#ifndef __PLAYERINFO_HH__
#define __PLAYERINFO_HH__

#include "resourceManager.hh"
#include "map.hh"
#include "pathfinder.hh"
#include "udpConnect.hh"
#include "camera.hh"
#include "udpConnect.hh"
#include "com.hh"

namespace ef
{
  struct Killed
  {
    std::shared_ptr<Object> obj;
    double time;
    bool isOther;
  };

  class PlayerInfo
  {
  public:
    PlayerInfo(ResourceManager & res, int _alegence, bool isClient);
    void makePath(std::shared_ptr<Unit> unit, Pos dest, MoveType moveType);
    void stopUnit(std::shared_ptr<Unit> unit);
    void setTarget(std::shared_ptr<Unit> unit, std::shared_ptr<Object> other, bool isTargetBuild);
    void setTarget(std::shared_ptr<Building> build, std::shared_ptr<Object> other, bool isTargetBuild);
    void refreshTarget(std::shared_ptr<Unit> unit, std::vector<std::shared_ptr<Object>> targets);
    void refreshTarget(std::shared_ptr<Building> build, std::vector<std::shared_ptr<Object>> targets);
    std::vector<TargetReturn> computeActions(double timePassed, std::vector<ConfWeapon> & weaponsConf, std::vector<ConfObj> & shotConf, bool moveOther, std::shared_ptr<UdpConnect> & serverUdp, struct sockaddr_in & clients);
    std::vector<std::shared_ptr<Object>> finishAction(double timePassed);
    void computeShot(bool isClient);
    void placeBuilding(std::shared_ptr<Building> building);
    std::shared_ptr<ef::Building> placeBuilding(Pos pos);
    bool canPlaceBuilding(Pos pos);
    bool produce(std::shared_ptr<ProdBuilding> producer, ConfUnit newUnit);
    void cancel(std::shared_ptr<ProdBuilding> producer);
    bool produce(std::shared_ptr<TechBuilding> producer, Tech newSearch);
    void cancel(std::shared_ptr<TechBuilding> producer);
    bool produce(std::shared_ptr<ConstructBuilding> producer, ConfBuilding newBuilding);
    void cancel(std::shared_ptr<ConstructBuilding> producer);
    bool destroyUnit(std::shared_ptr<Unit> unit, bool isOther);
    bool destroyBuilding(std::shared_ptr<Building> building, bool isOther);
    void addOther(std::shared_ptr<Unit> unit, bool isOther);
    void addOther(std::shared_ptr<Building> building, bool isOther);
    void addOtherShot(std::shared_ptr<Object> shot, bool isOther);
    bool isInVision(std::shared_ptr<Object> obj);
    bool isInVisionUnit(std::shared_ptr<Unit> unit);
    std::vector<std::shared_ptr<Unit>> selectUnit(Pos start, Pos end);
    std::vector<std::shared_ptr<Unit>> selectSameUnit(Pos start, Pos end);
    std::vector<std::shared_ptr<Building>> selectBuilding(Pos start, Pos end);
    std::vector<std::shared_ptr<Building>> selectSameBuilding(Pos start, Pos end);
    void modifyMoneyGain(int money);
    void Display(Bpixelarray &px,
                 ef::Camera &cam,
                 bool fog);
    std::vector<ef::Killed> & getKillList();
    std::shared_ptr<Unit> getUnit(int unitId, bool isOther);
    std::shared_ptr<Building> getBuild(int buildId, bool isOther);
    std::shared_ptr<Object> getOtherObject(int otherId, bool isBuilding);
    void updateOther();
    void updateOther(std::vector<std::shared_ptr<Unit>> newUnit, std::shared_ptr<UdpConnect> udp, struct sockaddr_in client);
    void updateOther(std::vector<std::shared_ptr<Building>> newBuilding, std::shared_ptr<UdpConnect> udp, struct sockaddr_in client);
    Map & getVisionMap();
    std::vector<std::shared_ptr<Building>> getBuildingInVision(Map vision);
    std::vector<std::shared_ptr<Unit>> getUnitInVision(Map vision);
    std::shared_ptr<Unit> getUnitAtPos(Pos pos);
    std::shared_ptr<Building> getBuildingAtPos(Pos pos);
    std::shared_ptr<Building> getFirstBuild();
    void updateVisionMap();
    std::string getMoney();
    int getIntMoney();
    std::string getEnergy();
    int getIntEnergy();
    std::vector<std::shared_ptr<Unit>> & getUnits();
    std::vector<std::shared_ptr<Unit>> & getOtherUnits();
    std::vector<std::shared_ptr<Building>> & getBuild();
    std::vector<std::shared_ptr<Building>> & getOtherBuild();
    std::vector<std::shared_ptr<Building>> & getProducedBuilding();

  private:
    int alegence;
    int money;
    int moneyGain;
    double moneyCooldown;
    int totalEnergy;
    int actualEnergy;
    Map map;
    Map buildingMap;
    Map visionMap; //0: quepouik | 1: gnn? | 2 : i see
    Pathfinder path;
    std::shared_ptr<Building> rallyPoint;
    ResourceManager & res;
    std::vector<std::shared_ptr<Building>> buildings;
    std::vector<std::shared_ptr<Unit>> units;
    std::vector<std::shared_ptr<Unit>> otherUnits;
    std::vector<std::shared_ptr<Building>> otherBuildings;
    std::vector<Killed> killList;
    std::vector<std::shared_ptr<Building>> producedBuilding;
    std::vector<std::shared_ptr<Tech>> searchedTech;
    std::vector<std::shared_ptr<Object>> shots;
    std::vector<std::shared_ptr<Object>> otherShots;
  };
}; // !ef

#endif // __PLAYERINFO_HH__
