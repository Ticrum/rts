#include "building.hh"

std::string ef::Tech::operator << (std::string text)
{
  return std::string("___--"+techName + "--___\nisSearched: " + std::to_string(isSearched) + "\ntimeToSearch: " + std::to_string( timeToSearch) + "\ncost: " + std::to_string(cost) + "\n---_________---\n") + text;
}
