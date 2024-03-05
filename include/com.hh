// EFRITS
// project:     rts
// created on:  2024-02-19 - 12:17 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: com header

#ifndef __COM_HH__
#define __COM_HH__

#include "object.hh"

namespace ef
{
  enum PackType
    {
      ISREADY,
      MOVEUNIT,
      PATHUNIT,
      SETTARGET,
      PLACEBUILD,
      ADDOTHERUNIT,
      ADDOTHERBUILDING,
      PRODUCE,
      DESTROY,
      UPDATETARGET,
      GAMESTART,
      ADDSHOT
    };

  struct PacketReady
  {
    PackType type;
    bool isReady;
  };

  struct PacketMoveUnit
  {
    PackType type;
    int unitId;
    ConformPos dest;
    MoveType moveType;
  };

  struct PacketPathUnit
  {
    PackType type;
    int unitId;
    MoveType moveType;
    int nbrPos;
    ConformPos pos[128];
  };

  struct PacketSetTarget
  {
    PackType type;
    int unitId;
    int otherId;
    bool isBuilding;
  };

  struct PacketUpdateTarget
  {
    PackType type;
    int unitId;
    int otherLen;
    int otherId[20];
    bool isEnemyBuilding[20];
    bool isBuilding;
    bool isEnemy;
  };

  struct PacketPlaceBuilding
  {
    PackType type;
    ConformPos pos;
  };

  struct PacketAddOtherUnit
  {
    PackType type;
    int unitId;
    int alegence;
    ConformPos posi;
    int len;
    char conf[128];
    int actualHp;
    double progress;
    MoveType moveType;
    int nbrPos;
    ConformPos pos[64];
    int nbrCdr;
    double cdr[10];
    bool isOther;
  };

  struct PacketAddOtherBuilding
  {
    PackType type;
    int buildId;
    int alegence;
    ConformPos posi;
    int len;
    char conf[128];
    int actualHp;
    bool isActive;
    int nbrCdr;
    double cdr[10];
    bool isOther;
  };

  struct PacketProduce
  {
    PackType type;
    int producerId;
    int len;
    char conf[128];
    BuildingType buildType;
  };

  struct PacketDestroy
  {
    PackType type;
    int unitId;
    bool isOther;
    bool isBuilding;
  };

  struct PacketGameStart
  {
    PackType type;
    bool isStart;
  };

  struct PacketAddShot
  {
    PackType type;
    int buildId;
    int alegence;
    ConformPos pos;
    int len;
    char conf[128];
  };

  union Packet
  {
    PackType type;
    PacketGameStart gameStart;
    PacketReady ready;
    PacketMoveUnit moveUnit;
    PacketPathUnit pathUnit;
    PacketSetTarget setTarget;
    PacketPlaceBuilding placeBuild;
    PacketAddOtherUnit addOtherUnit;
    PacketAddOtherBuilding addOtherBuilding;
    PacketProduce produce;
    PacketDestroy destroy;
    PacketUpdateTarget updateTarget;
    PacketAddShot addShot;
  };
}; // !ef

#endif // __COM_HH__

