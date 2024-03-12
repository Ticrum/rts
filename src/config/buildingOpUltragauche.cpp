#include "building.hh"

std::string ef::ConfBuilding::operator<<(std::string text)
{
  std::string toto;
  toto = (ConfObj)(*this) << "";
  toto += "cost : " + std::to_string(cost) + "\ntimeToProduce" + std::to_string(timeToProduce) + "\ntype : " + std::to_string(type) + "\ncanBeTarget : " + std::to_string(canBeTarget) + "\nenergyCost : " + std::to_string(energyCost) + "\nenergyProduction : " + std::to_string(energyProduction) + "\nmoneyProduction : " + std::to_string(moneyProduction) + "\nweaponConf : (" + std::to_string(weaponConf.size()) + ") | ";
  for(unsigned int i = 0; i < weaponConf.size(); i++)
      toto += weaponConf[i] + ",";
  return toto + "\n---__________---\n" + text;
}
