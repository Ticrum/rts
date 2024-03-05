#include "resourceManager.hh"

ef::ConfObj ef::ResourceManager::getShot(std::string name)
{
  for(unsigned int i = 0; i < shot.size(); i++)
    if(shot[i].conf == name)
      return shot[i];
  ConfObj error;
  error.maxhp = -1;
  error.imgId = -1;
  error.dmg = -1;
  return error;
}
