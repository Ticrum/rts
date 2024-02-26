// EFRITS
// project:     rts
// created on:  2024-02-13 - 15:42 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: makeTargeting implementation

#include "building.hh"

ef::TargetReturn ef::Building::makeTargeting(std::vector<std::shared_ptr<Object>> others)
{
    int minDist;
    int actualDist;
    std::shared_ptr<Object> bestTarget;
    TargetReturn tar;

    tar.isBuilding = true;
    for (int i = 0; i < (int)weapons.size(); i += 1)
    {
        if (!weapons[i].hasTarget())
        {
            minDist = 999999;
            for (int j = 0; j < (int)others.size(); j += 1)
                if ((actualDist = getPos().isInRange(others[j]->getPos(), weapons[i].getRange(), weapons[i].getRange())) != -1 && getAlegence() != others[j]->getAlegence())
                    if (actualDist < minDist)
                    {
                        minDist = actualDist;
                        bestTarget = others[j];
                    }
            weapons[i].setNewTarget(bestTarget);
            tar.target.push_back(bestTarget);
        }
    }
    return tar;
}


