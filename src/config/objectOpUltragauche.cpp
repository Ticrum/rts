#include "object.hh"

std::string ef::ConfObj::operator<<(std::string text)
{
  return std::string("___--" + conf + "("+ conformConf+ ")--___\nimg : "+ img + "\nobjSize : "+ std::to_string(objSize.x) + "; " + std::to_string(objSize.y) + "\nmaxhp : " + std::to_string(maxhp)+ "\narmor : " + std::to_string(armor) + "\nrangeOfVision : " + std::to_string(rangeOfVision) + "\nnbrDMG : " + std::to_string(nbrDmg) + "\ndmg : " + std::to_string(dmg) + "\n" + text);
}
