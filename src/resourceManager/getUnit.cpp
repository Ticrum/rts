#include "resourceManager.hh"

ef::ConfUnit ef::ResourceManager::getUnit(std::string name)
{
    for (unsigned int i = 0; i < unitConf.size(); i++)
        if((unitConf[i]).conf == name)
            return unitConf[i];
    return ef::ConfUnit();
}
