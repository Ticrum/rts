// EFRITS
// project:     rts
// created on:  2024-02-12 - 12:24 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: produceUnit implementation

#include "building.hh"

std::shared_ptr<ef::Unit> ef::ProdBuilding::produceUnit(double timePassed,
                                                        std::vector<ConfWeapon> & weaponsConf,
							std::map<std::string, std::shared_ptr<Bpixelarray>> & imgs)
{
    std::shared_ptr<Unit> newUnit;

    if (!onHold)
        timeLeft -= timePassed;
    if (timeLeft <= 0)
    {
        if (unitProd.size() > 0)
        {
            Pos tempPos = getPos();
            tempPos.x += 1;
            newUnit.reset(new Unit(unitProd[0],imgs[unitProd[0].img], tempPos, rand(), alegence, weaponsConf));
            std::vector<ConfUnit> tempVect = unitProd;
            unitProd.clear();
            for (int i = 0; i < (int)tempVect.size() - 1; i += 1)
                unitProd.push_back(tempVect[i + 1]);
            if (unitProd.size() > 0)
                timeLeft = unitProd[0].timeToProduce;
        }
    }
    else
        newUnit = nullptr;
    return newUnit;
}

