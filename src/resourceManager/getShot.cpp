#include "resourceManager.hh"

ef::ConfObj ef::ResourceManager::getShot(std::string name)
{
  for(unsigned int i = 0; i < shot.size(); i++)
    if(shot[i].conf == name)
      return shot[i];
  return ef::ConfObj();
}
