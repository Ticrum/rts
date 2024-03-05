// EFRITS
// project:     rts
// created on:  2024-02-12 - 10:39 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: unit header

#ifndef __UNIT_HH__
#define __UNIT_HH__

#include "weapon.hh"
#include "tcpConnect.hh"

namespace ef
{
  enum MoveType
    {
      RUN,
      WALK,
      STATIC
    };
    struct ConfUnit : public ConfObj
    {
        ConfUnit();
        ConfUnit(std::string file);
        ConfUnit(ConfUnit const &other);
        ConfUnit &operator=(ConfUnit const&other);
        int load(std::string &file);

        int cost;
        double speed;
        double runningSpeed;
        MoveType moveType;
        bool isFlying;
        double timeToProduce;
        std::vector<std::string> weaponConf;
    };

  class Unit : public Object
  {
  public:
    Unit(ConfUnit conf, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf);
    Unit(ConfUnit conf, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf, int actualHp, double _progress, MoveType type, std::vector<Pos> newPath, std::vector<double> cdr);
    double getSpeed();
    double getRunningSpeed();
    void moveUnit(double timePassed);
    std::vector<std::shared_ptr<Object>> fireAllWeapon(double timePassed);
    bool getIsFlying();
    int getActualIndex();
    void changePath(std::vector<Pos> newPath, MoveType type);
    void changeTarget(std::vector<std::shared_ptr<Object>> targets);
    TargetReturn makeTargeting(std::vector<std::shared_ptr<Object>> others);
    void manualTargeting(std::shared_ptr<Object> target);
    void UnitDisplay(Bpixelarray &px,
                     std::vector<std::shared_ptr<Bpixelarray>> &rsrc,
                     Pos caseSize);double getProgress();
    MoveType getMoveType();
    std::vector<ConformPos> getPathLeft();
    std::vector<double> getWeaponsCd();

  private:
    std::vector<Pos> path;
    int actualIndex;
    double progress;
    double speed;
    double runningSpeed;
    MoveType moveType;
    bool isFlying;
    std::vector<Weapon> weapons;
  };
}; // !ef

#endif // __UNIT_HH__
