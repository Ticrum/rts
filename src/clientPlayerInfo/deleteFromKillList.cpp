// EFRITS
// project:     rts
// created on:  2024-03-01 - 13:11 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: deleteFromKillList implementation

#include "clientPlayerInfo.hh"

void ef::ClientPlayerInfo::deleteFromKillList(std::shared_ptr<Object> obj)
{
    std::vector<std::shared_ptr<ef::Object>> tempKill = playerInfo.getKillList();
    for (int i = 0; i < (int)tempKill.size(); i += 1)
        if (tempKill[i]->getId() == obj->getId())
        {
            std::shared_ptr<Object> tempObj = tempKill[i];
            tempKill[i] = tempKill[tempKill.size() - 1];
            tempKill[tempKill.size() - 1] = tempObj;
            tempKill.pop_back();
        }
}

