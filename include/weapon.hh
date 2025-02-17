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
    bool canTargetFly;
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
    Weapon(ConfWeapon conf, int _alegence, ConfObj _shot);
    Weapon(ConfWeapon conf, int _alegence, ConfObj _shot, double _cdr);
    std::shared_ptr<Object> fireAction(double timePassed);
    void setNewTarget(std::shared_ptr<Object> newTarget, bool _isTargetBuild);
    void removeTarget();
    int getDmg();
    int getNbrAtt();
    int getRange();
    double getCdr();
    bool isManual();
    bool hasTarget();
    Pos getTarPos();
    std::shared_ptr<Object> getTarget();
    bool getIsTargetBuild();
    bool getCanTargetFly();

  private:
    int dmg;
    int nbrAtt;
    double cdrMax;
    double cdr;
    int range;
    bool manualTarget;
    bool canTargetFly;
    int alegence;
    ConfObj shot;
    std::shared_ptr<Object> target;
    bool isTargetBuild;
  };
}

#endif // __WEAPON_HH__
