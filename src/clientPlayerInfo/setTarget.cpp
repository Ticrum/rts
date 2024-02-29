// EFRITS
// project:     rts
// created on:  2024-02-27 - 12:27 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: setTarget implementation

#include "clientPlayerInfo.hh"

void ef::ClientPlayerInfo::setTarget(Pos clickPos)
{
    std::shared_ptr<Unit> tempUnit = playerInfo.getUnitAtPos(clickPos);
    std::shared_ptr<Building> tempBuilding = playerInfo.getBuildingAtPos(clickPos);
    if (tempUnit.get() != nullptr)
    {
        for (int i = 0; i < (int)selectedUnit.size(); i += 1)
        {
            playerInfo.setTarget(selectedUnit[i], tempUnit);
            Packet pack;
            pack.type = SETTARGET;
            pack.setTarget.unitId = selectedUnit[i]->getId();
            pack.setTarget.otherId = tempUnit->getId();
            pack.setTarget.isBuilding = false;
            clientUdp->sendData((char *)&pack, sizeof(Packet), serverConnected);
        }
    }
    else if (tempBuilding.get() != nullptr)
    {
        for (int i = 0; i < (int)selectedBuilding.size(); i += 1)
        {
            playerInfo.setTarget(selectedBuilding[i], tempUnit);
            Packet pack;
            pack.type = SETTARGET;
            pack.setTarget.unitId = selectedBuilding[i]->getId();
            pack.setTarget.otherId = tempUnit->getId();
            pack.setTarget.isBuilding = true;
            clientUdp->sendData((char *)&pack, sizeof(Packet), serverConnected);
        }
    }
}

