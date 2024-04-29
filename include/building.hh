// EFRITS
// project:     rts
// created on:  2024-02-12 - 11:19 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: building header

#ifndef __BUILDING_HH__
#define __BUILDING_HH__

#include "unit.hh"
#include <map>

namespace ef
{
  class ButonManager;
  enum BuildingType
    {
      PRODUCTION,
      CONSTRUCT,
      TECH,
      DEFENCE,
      ENERGY,
      MONEY
    };/*if you add a BuildingType don't forget to update;
	the if line 26 in "src/config/buildingLoad.cpp",
	Building.type in "resours/building/conf/tamplate"
      */

  struct ConfBuilding : public ConfObj
  {
    ConfBuilding();
    ConfBuilding(std::string file);
    ConfBuilding(ConfBuilding const &other);
    ConfBuilding &operator=(ConfBuilding const&other);
    int load(std::string &file);
    std::string operator<<(std::string text);

    int cost;
    double timeToProduce;
    BuildingType type;
    bool canBeTarget;
    int energyCost;
    int energyProduction;
    int moneyProduction;
    std::string butons;
    std::vector<std::string> weaponConf;
  };

  std::string extract(unsigned int start,
		      std::string &source,
		      char stop);

  class Building : public Object
  {
  public:
    Building(ConfBuilding conf, std::shared_ptr<ef::Bpixelarray>_img, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf);
    Building(ConfBuilding conf, std::shared_ptr<ef::Bpixelarray>_img, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf, int actualHp, std::vector<double> cdr);
    std::vector<std::shared_ptr<Object>> fireAllWeapon(double timePassed);
    void changeTarget(std::vector<std::shared_ptr<Object>> targets);
    BuildingType getType();
    bool getCanBeTarget();
    int getEnergyCost();
    bool getIsActive();
    void setIsActive(bool newState);
    int getEnergyProduction();
    int getMoneyProduction();
    void displayButon(ButonManager &manager, std::map<std::string, std::shared_ptr<Bpixelarray>> &sprits);
    void removeButon(ButonManager &manager);
    TargetReturn makeTargeting(std::vector<std::shared_ptr<Object>> others, bool isBuilding);
    void manualTargeting(std::shared_ptr<Object> target, bool isTargetBuild);
    std::vector<double> getWeaponsCd();

  protected:
    BuildingType type;
    bool canBeTarget;
    int energyCost;
    int energyProduction;
    int moneyProduction;
    bool isActive;
    std::string butons;
    unsigned int groupButon;
    std::vector<Weapon> weapons;
  };

  class ProdBuilding : public Building
  {
  public:
    ProdBuilding(ConfBuilding conf, std::shared_ptr<ef::Bpixelarray>_img, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf);
    ProdBuilding(ConfBuilding conf, std::shared_ptr<ef::Bpixelarray>_img, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf, int actualHp, std::vector<double> cdr);
    std::shared_ptr<Unit> produceUnit(double timePassed,
				      std::vector<ConfWeapon> & weaponsConf,
				      std::map<std::string, std::shared_ptr<Bpixelarray>> & imgs);
    void addUnitToProd(ConfUnit newUnit);
    bool getOnHold();
    void setOnHold(bool newState);

  private:
    double timeLeft;
    bool onHold;
    std::vector<ConfUnit> unitProd;
  };

  class ConstructBuilding : public Building
  {
  public:
    ConstructBuilding(ConfBuilding conf, std::shared_ptr<ef::Bpixelarray>_img, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf);
    ConstructBuilding(ConfBuilding conf, std::shared_ptr<ef::Bpixelarray>_img, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf, int actualHp, std::vector<double> cdr);
    std::shared_ptr<Building> produceBuilding(double timePassed,
					      std::vector<ConfWeapon> & weaponsConf,
					      std::map<std::string, std::shared_ptr<Bpixelarray>> & imgs);
    void addBuildingToProd(ConfBuilding newBuilding);
    bool getOnHold();
    void setOnHold(bool newState);

  private:
    double timeLeft;
    bool onHold;
    std::vector<ConfBuilding> buildingProd;
  };

  struct Tech
  {
    Tech();
    Tech(std:: string file);
    Tech(Tech const &other);
    Tech &operator=(Tech const &other);
    int load(std::string &file);
    std::string operator << (std::string text);

    std::string techName;
    bool isSearched;
    double timeToSearch;
    int cost;
  };

  class TechBuilding : public Building
  {
  public:
    TechBuilding(ConfBuilding conf, std::shared_ptr<ef::Bpixelarray>_img, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf);
    TechBuilding(ConfBuilding conf, std::shared_ptr<ef::Bpixelarray>_img, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf, int actualHp, std::vector<double> cdr);
    std::shared_ptr<Tech> searchTech(double timePassed);
    void addSearchToList(Tech newSearch);
    bool getOnHold();
    void setOnHold(bool newState);

  private:
    double timeLeft;
    bool onHold;
    std::vector<Tech> techResearch;
  };
}; // !ef

#endif // __BUILDING_HH__
