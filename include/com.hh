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
      ADDSHOT,
      CLIENTINFO,
      CANCEL,
      SYNC
    };

  struct PacketReady
  {
    PackType type;
    int datalen;
    bool isReady;
  };

  struct PacketMoveUnit
  {
    PackType type;
    int datalen;
    int unitId;
    ConformPos dest;
    MoveType moveType;
  };

  struct PacketPathUnit
  {
    PackType type;
    int datalen;
    int unitId;
    MoveType moveType;
    int nbrPos;
    ConformPos pos[128];
  };

  struct PacketSetTarget
  {
    PackType type;
    int datalen;
    int unitId;
    int otherId;
    bool isBuilding;
  };

  struct PacketUpdateTarget
  {
    PackType type;
    int datalen;
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
    int datalen;
    ConformPos pos;
  };

  struct PacketAddOtherUnit
  {
    PackType type;
    int datalen;
    int unitId;
    int alegence;
    ConformPos posi;
    int len;
    char conf[128];
    int actualHp;
    double progress;
    int actualIndex;
    MoveType moveType;
    int nbrPos;
    ConformPos pos[64];
    int nbrCdr;
    double cdr[10];
    bool isOther;
    bool isUpdating;
  };

  struct PacketAddOtherBuilding
  {
    PackType type;
    int datalen;
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
    int datalen;
    int producerId;
    int len;
    char conf[128];
    BuildingType buildType;
  };

  struct PacketDestroy
  {
    PackType type;
    int datalen;
    int unitId;
    bool isOther;
    bool isBuilding;
  };

  struct PacketGameStart
  {
    PackType type;
    int datalen;
    bool isStart;
  };

  struct PacketAddShot
  {
    PackType type;
    int datalen;
    int buildId;
    int alegence;
    ConformPos pos;
    int len;
    bool isOther;
    char conf[128];
  };

  struct PacketClientInfo
  {
    PackType type;
    int datalen;
    int port;
  };

  struct PacketCancel
  {
    PackType type;
    int datalen;
    int producerId;
    BuildingType buildType;
  };

  struct PacketSync
  {
    PackType type;
    int datalen;
    int unitId;
    int alegence;    
  };

  struct Packet
  {
    PackType type;
    int datalen;
    char buffer[600];
  };
}; // !ef

#endif // __COM_HH__

