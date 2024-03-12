#include "weapon.hh"

std::string ef::ConfWeapon::operator << (std::string text)
{
  return std::string("___--" + conf + "--___\nShotConf: " + ShotConf + "\ndmg : "+ std::to_string(dmg) + "\nnbrAtt : "+ std::to_string(nbrAtt) + "\ncbrMax : " + std::to_string(cdrMax) + "\nrange : " + std::to_string(range) + "\ntarget : " + std::to_string(manualTarget) + "\n---_______---\n") + text;
}
