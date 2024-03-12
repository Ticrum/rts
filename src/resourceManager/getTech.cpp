#include "resourceManager.hh"

ef::Tech ef::ResourceManager::getTech(std::string name)
{
    for (unsigned int i = 0; i < allTech.size(); i++)
        if(allTech[i].techName == name)
            return allTech[i];
    return ef::Tech();
}
