// EFRITS
// project:     rts
// created on:  2024-02-13 - 11:36 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: produce2 implementation

#include "playerInfo.hh"

bool ef::PlayerInfo::produce(std::shared_ptr<TechBuilding> producer,
                             Tech newSearch)
{
    if (money < newSearch.cost)
        return false;
    money -= newSearch.cost;
    producer->addSearchToList(newSearch);
    return true;
}

