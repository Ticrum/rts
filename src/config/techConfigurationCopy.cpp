#include "building.hh"

ef::Tech::Tech(ef::Tech const &other)
  :techName(other.techName),
   isSearched(other.isSearched),
   timeToSearch(other.timeToSearch),
   cost(other.cost)
{}
