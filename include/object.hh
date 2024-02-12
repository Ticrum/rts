// EFRITS
// project:     rts
// created on:  2024-02-09 - 11:21 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: object header

#ifndef __OBJECT_HH__
#define __OBJECT_HH__

#include <vector>
#include <cstdint>
#include <string>

namespace ef
{
    struct ConformPos
    {
        uint16_t x;
        uint16_t y;
    };

    struct Pos
    {
        ConformPos get();

        int x;
        int y;
    };

    struct ConfObj
    {
        ConfObj(std::string file);

        std::string conf;
        int imgId;
        Pos objSize;
        int maxhp;
        int armor;
        int rangeOfVision;
    };

    class Object
    {
    public:
        Object(ConfObj conf, Pos _pos, int _objId, int _alegence);
        void takeDmg(int nbrDmg, int dmg);
        Pos getPos();
        void setPos(int x, int y);
        int getImgId();
        Pos getObjSize();
        int getHp();
        int getArmor();
        int getRangeOfVision();
        int getAlegence();

    protected:
        int objId;
        Pos pos;
        int imgId;
        Pos objSize;
        int hp;
        int maxhp;
        int armor;
        int rangeOfVision;
        int alegence;
    };
}; // !ef

#endif // __OBJECT_HH__
