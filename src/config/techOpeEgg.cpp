#include "building.hh"

ef::Tech &ef::Tech::operator=(ef::Tech const &other)
{
  techName  = other.techName;
  isSearched = other.isSearched;
  timeToSearch = other.timeToSearch;
  cost = other.cost;
  return *this;
}
