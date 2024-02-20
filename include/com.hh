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
        ADDOTHER,
        PRODUCE,
        DESTROY
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
        int nbrPos;
        ConformPos pos;
    };

    struct PacketSetTarget
    {
        PackType type;
        int unitId;
        int otherId;
        bool isBuilding;
    };

    struct PacketPlaceBuilding
    {
        PackType type;
        Pos pos;
    };

    struct PacketAddOther
    {
        PackType type;
        int unitId;
        int len;
        char conf[128];
        bool isBuilding;
    };

    struct PacketProduce
    {
        PackType type;
        int producerId;
        int len;
        char conf[128];
        bool isTech;
    };

    struct PacketDestroy
    {
        PackType type;
        int unitId;
        bool isOther;
        bool isBuilding;
    };

    union Packet
    {
        PackType type;
        PacketReady ready;
        PacketMoveUnit moveUnit;
        PacketPathUnit pathUnit;
        PacketSetTarget setTarget;
        PacketPlaceBuilding placeBuild;
        PacketAddOther addOther;
        PacketProduce produce;
        PacketDestroy destroy;
    };
}; // !ef

#endif // __COM_HH__

