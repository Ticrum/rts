#ifndef __PLAYERINFO_HH__
#define __PLAYERINFO_HH__

#include "unit.hh"
#include "building.hh"
#include "map.hh"
#include "udpServer.hh"

namespace ef
{
    class PlayerInfo
    {
    public:
        PlayerInfo();
        void makePath(shared_ptr<Unit> unit, Pos dest, MoveType moveType);
        void stopUnit(shared_ptr<Unit> unit);
        void setTarget(shared_ptr<Unit> unit, shared_ptr<Unit> other);
        void setTarget(shared_ptr<Unit> unit, shared_ptr<Building> other);
        void computeActions(double timePassed);
        void placeBuilding(shared_ptr<Building> building);
        void produce(shared_ptr<ProdBuilding> producer, shared_ptr<Unit> unitToProd);
        void produce(shared_ptr<TechBuilding> producer, shared_ptr<Tech> unitToProd);
        bool destroyUnit(shared_ptr<Unit> unit, bool isOther);
        bool destroyBuilding(shared_ptr<Building> building, bool isOther);
        void addOther(shared_ptr<Unit> unit);
        void addOther(shared_ptr<Building> building);
        bool isInVision(shared_ptr<Object> obj);
        vector<shared_ptr<Unit>> selectUnit(Pos start, Pos end);
        vector<shared_ptr<Building>> selectBuilding(Pos start, Pos end);
        void addMoneyGain(int money);
        void loseMoneyGain(int money);

    private:
        int money;
        int moneyGain;
        int totalEnergy;
        int actualEnergy;
        vector<shared_ptr<Building>> buildings;
        vector<shared_ptr<Unit>> units;
        vector<shared_ptr<Unit>> otherUnits;
        vector<shared_ptr<Buildings>> otherBuildings;
        shared_ptr<Building> rallyPoint;
        Map map;
        Map visionMap;
    };

    class ServerPlayersInfo
    {
    public:
        ServerPlayersInfo();
        void makePath(int unitId, Pos dest, MoveType moveType, int PlayerId);
        void stopUnit(int unitId, int PlayerId);
        void setTarget(int unitId, shared_ptr<Unit> other, int PlayerId);
        void setTarget(int unitId, shared_ptr<Building> other, int PlayerId);
        void computeActions(double timePassed);
        void placeBuilding(string building, int PlayerId);
        void produce(int producerId, string unitToProd, int PlayerId, bool isTech);
        bool destroyUnit(int unitId, bool isOther, int PlayerId);
        bool destroyBuilding(int buildingId, bool isOther, int PlayerId);

    private:
        vector<PlayerInfo> playersInfo;
        Map trueMap;
        vector<shared_ptr<Building>> neutralBuildings;
        shared_ptr<UdpServer> serverUdp;
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
        void placeBuilding(string building);
        void produce(int producerId, string unitToProd, bool isTech);
        bool DestroyUnit();
        bool DestroyBuilding();
        bool destroyUnit(int unitId, bool isOther);
        bool destroyBuilding(int buildingId, bool isOther);

        PlayerInfo playerInfo;

    private:
        vector<shared_ptr<Unit>> selectedUnit;
        vector<shared_ptr<Building>> selectedBuilding;
        shared_ptr<UdpConnect> connectUdp;
    }
}; // !ef

#endif // __PLAYERINFO_HH__
