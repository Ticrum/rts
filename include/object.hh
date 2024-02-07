#ifndef __OBJECT_HH__
#define __OBJECT_HH__

#include <memory>
#include <vector>

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

    class Object
    {
    public:
        Object();
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

    class Weapon
    {
    public:
        Weapon();
        bool FireAction(double timePassed);
        void setNewTarget(shared_ptr<Object> newTarget);
        int getDmg();
        int getNbrAtt();
        int getRange();

    private:

        int computeDmg();

        int dmg;
        int nbrAtt;
        double cdrMax;
        double cdr;
        int range;
        shared_ptr<Object> target;
    };
}; // !ef

#endif // __OBJECT_HH__
