// EFRITS
// project:     rts
// created on:  2024-02-16 - 17:28 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: serverPlayersInfo header

#ifndef __SERVERPLAYERINFO_HH__
#define __SERVERPLAYERINFO_HH__

#include "playerInfo.hh"
#include "com.hh"
#include "udpConnect.hh"
#include "tcpConnect.hh"

namespace ef
{
    class ServerPlayersInfo
    {
    public:
        ServerPlayersInfo(int port);
        void makePath(int unitId, Pos dest, MoveType moveType, int playerId);
        void stopUnit(int unitId, int playerId);
        void setTarget(int unitId, int otherId, int playerId, bool isBuilding);
        void computeActions(double timePassed);
        void placeBuilding(Pos pos, int playerId);
        void produce(int producerId, std::string unitToProd, int playerId, BuildingType type);
        bool destroy(int unitId, bool isOther, int playerId, bool isBuilding);
        void addOther(int buildId, std::string build, Pos pos, int playerId, BuildingType type);
        void addOther(int unitId, std::string unit, Pos pos, int playerId);

    private:
        Map trueMap;
        std::shared_ptr<UdpConnect> serverUdp;
        std::shared_ptr<TcpConnect> serverTcp;
        ResourceManager res;
        std::vector<struct sockaddr_in> clientConnected;
        std::vector<PlayerInfo> playersInfo;
        std::vector<std::shared_ptr<Building>> neutralBuildings;
    };
}; // !ef

#endif // __SERVERPLAYERINFO_HH__
