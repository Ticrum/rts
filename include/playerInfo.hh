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

namespace ef
{
    class PlayerInfo
    {
    public:
        PlayerInfo(ResourceManager & res);
        void makePath(std::shared_ptr<Unit> unit, Pos dest, MoveType moveType);
        void stopUnit(std::shared_ptr<Unit> unit);
        void setTarget(std::shared_ptr<Unit> unit, std::shared_ptr<Object> other);
        void computeActions(double timePassed, std::vector<ConfWeapon> & weaponsConf);
        void finishAction(double timePassed);
        void placeBuilding(std::shared_ptr<Building> building);
        bool placeBuilding(Pos pos);
        bool canPlaceBuilding(Pos pos);
        void produce(std::shared_ptr<ProdBuilding> producer, ConfUnit newUnit);
        void produce(std::shared_ptr<TechBuilding> producer, Tech newSearch);
        void produce(std::shared_ptr<ConstructBuilding> producer, ConfBuilding newBuilding);
        bool destroyUnit(std::shared_ptr<Unit> unit, bool isOther);
        bool destroyBuilding(std::shared_ptr<Building> building, bool isOther);
        void addOther(std::shared_ptr<Unit> unit);
        void addOther(std::shared_ptr<Building> building);
        bool isInVision(std::shared_ptr<Object> obj);
        std::vector<std::shared_ptr<Unit>> selectUnit(Pos start, Pos end);
        std::vector<std::shared_ptr<Building>> selectBuilding(Pos start, Pos end);
        void modifyMoneyGain(int money);
        void Display(Bpixelarray &px,
                     std::vector<Bpixelarray> &rsrc,
                     ef::Camera &cam,
                     bool fog);
        std::vector<std::shared_ptr<ef::Object>> & getKillList();
        std::shared_ptr<Unit> getUnit(int unitId);
        std::shared_ptr<Building> getBuild(int buildId);
        std::shared_ptr<Object> getOtherObject(int otherId, bool isBuilding);

    private:
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
        std::vector<std::shared_ptr<ef::Object>> killList;
        std::vector<std::shared_ptr<Building>> producedBuilding;
        std::vector<std::shared_ptr<Tech>> searchedTech;
    };

    class ClientPlayerInfo
    {
    public:
        ClientPlayerInfo();
        void makePath(Pos dest, MoveType moveType);
        void selectUnit(Pos start, Pos end);
        void selectBuilding(Pos start, Pos end);
        void stopUnit();
        void setTarget();
        void placeBuilding(std::string building);
        void produce(int producerId, std::string unitToProd, bool isTech);
        bool DestroyUnit();
        bool DestroyBuilding();
        bool destroyUnit(int unitId, bool isOther);
        bool destroyBuilding(int buildingId, bool isOther);

        PlayerInfo playerInfo;

    private:
        std::vector<std::shared_ptr<Unit>> selectedUnit;
        std::vector<std::shared_ptr<Building>> selectedBuilding;
        std::shared_ptr<UdpConnect> connectUdp;
    };
}; // !ef

#endif // __PLAYERINFO_HH__
