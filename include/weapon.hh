// EFRITS
// project:     rts
// created on:  2024-02-09 - 11:21 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: weapon header

#ifndef __WEAPON_HH__
#define __WEAPON_HH__

#include "object.hh"

namespace ef
{

    class ConfWeapon
    {
    public:
        ConfWeapon();
        ConfWeapon(std::string file);
        ConfWeapon(ConfWeapon const &other);
        ConfWeapon &operator=(ConfWeapon const&other);
        int load(std::string &file);

        std::string conf;
        int dmg;
        int nbrAtt;
        double cdrMax;
        int range;
        bool manualTarget;
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
        bool isManual();

    private:
        int dmg;
        int nbrAtt;
        double cdrMax;
        double cdr;
        int range;
        bool manualTarget;
        std::shared_ptr<Object> target;
    };
}

#endif // __WEAPON_HH__
