#include "resourceManager.hh"
#include "Bpixelarray.hh"

std::map<std::string, std::shared_ptr<ef::Bpixelarray>> &ef::ResourceManager::getSprit()
{
    return sprites;
}
