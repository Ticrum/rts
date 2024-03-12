// EFRITS
// project:     rts
// created on:  2024-03-01 - 13:11 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: deleteFromKillList implementation

#include "clientPlayerInfo.hh"

void ef::ClientPlayerInfo::deleteFromKillList(std::shared_ptr<Object> obj)
{
    std::vector<Killed> tempKill = playerInfo.getKillList();
    for (int i = 0; i < (int)tempKill.size(); i += 1)
        if (tempKill[i].obj->getId() == obj->getId())
        {
            Killed tempObj = tempKill[i];
            tempKill[i] = tempKill[tempKill.size() - 1];
            tempKill[tempKill.size() - 1] = tempObj;
            tempKill.pop_back();
        }
}

