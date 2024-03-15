#include "weapon.hh"

ef::ConfWeapon::ConfWeapon(ConfWeapon const &other)
  :conf(other.conf),
   ShotConf(other.ShotConf),
   dmg (other.dmg),
   nbrAtt (other.nbrAtt),
   cdrMax (other.cdrMax),
   range (other.range),
   manualTarget (other.manualTarget)
{}
