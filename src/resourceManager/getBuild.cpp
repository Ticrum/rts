#include "resourceManager.hh"

ef::ConfBuilding ef::ResourceManager::getBuild (std::string name)
{
  for (unsigned int i = 0; i < buildingConf.size(); i++)
    if(buildingConf[i].conf == name)
      return buildingConf[i];
  return ef::ConfBuilding();
}
