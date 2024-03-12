#include "unit.hh"

std::string ef::ConfUnit::operator<<(std::string text)
{
  std::string toto;
  toto = (ConfObj)(*this) << "";
  toto += "------------\ncost : " + std::to_string(cost) + "\nspeed : " + std::to_string(speed) + "\nrunningSpeed : " +std::to_string(runningSpeed) + "\nmoveType : " + std::to_string(moveType) + "\nIsFlying : " + std::to_string(isFlying) + "\ntimeToProduce : " + std::to_string(timeToProduce) + "\nweaponConf : (" + std::to_string(weaponConf.size()) + ") | ";
  for(unsigned int i = 0; i < weaponConf.size(); i++)
      toto += weaponConf[i]+ ",";
  return toto + "\n---__________---\n" + text;
}
