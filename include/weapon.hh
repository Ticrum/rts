// EFRITS
// project:     rts
// created on:  2024-02-09 - 11:21 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: weapon header

#ifndef __WEAPON_HH__
#define __WEAPON_HH__

#include <memory>
#include "object.hh"

namespace ef
{

    struct ConfWeapon
    {
        ConfWeapon(std::string file);

        std::string conf;
        int dmg;
        int nbrAtt;
        double cdrMax;
        int range;
    };

    class Weapon
    {
    public:
        Weapon(ConfWeapon conf);
        bool fireAction(double timePassed);
        void setNewTarget(std::shared_ptr<Object> newTarget);
        int getDmg();
        int getNbrAtt();
        int getRange();

    private:
        int dmg;
        int nbrAtt;
        double cdrMax;
        double cdr;
        int range;
        std::shared_ptr<Object> target;
    };
}

#endif // __WEAPON_HH__