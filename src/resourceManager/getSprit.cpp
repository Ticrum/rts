#include "resourceManager.hh"
#include "Bpixelarray.hh"

std::vector<std::shared_ptr<ef::Bpixelarray>> ef::ResourceManager::getSprit()
{
    return sprites;
}
