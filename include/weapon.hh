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
    std::string operator << (std::string text);
    int load(std::string &file);

    std::string conf;
    std::string ShotConf;
    int dmg;
    int nbrAtt;
    double cdrMax;
    int range;
    bool manualTarget;
  };
  struct TargetReturn
  {
    std::shared_ptr<Object> unit;
    bool isBuilding;
    std::vector<std::shared_ptr<Object>> target;
    std::vector<bool> isTargetBuilding;
  };


  class Weapon
  {
  public:
    Weapon(ConfWeapon conf, int _alegence);
    Weapon(ConfWeapon conf, int _alegence, double _cdr);
    std::shared_ptr<Object> fireAction(double timePassed);
    void setNewTarget(std::shared_ptr<Object> newTarget);
    int getDmg();
    int getNbrAtt();
    int getRange();
    double getCdr();
    bool isManual();
    bool hasTarget();
    Pos getTarPos();

  private:
    int dmg;
    int nbrAtt;
    double cdrMax;
    double cdr;
    int range;
    bool manualTarget;
    int alegence;
    ConfObj shot;
    std::shared_ptr<Object> target;
  };
}

#endif // __WEAPON_HH__
