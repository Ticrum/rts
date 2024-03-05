// EFRITS
// project:     rts
// created on:  2024-02-22 - 12:02 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: updateOther2 implementation

#include "playerInfo.hh"

void ef::PlayerInfo::updateOther(std::vector<std::shared_ptr<Building>> newBuilding,
                                 std::shared_ptr<UdpConnect> udp,
                                 struct sockaddr_in client)
{
    for (int i = 0; i < (int)newBuilding.size(); i += 1)
    {
        bool hasFind = false;
        for (int j = 0; j < (int)otherBuildings.size(); j += 1)
            if (otherBuildings[j]->getId() == newBuilding[i]->getId())
            {
                hasFind = true;
                break;
            }
        if (!hasFind)
        {
            Packet pack;
            pack.type = ADDOTHERBUILDING;
            pack.addOtherBuilding.isOther = true;
            pack.addOtherBuilding.buildId = newBuilding[i]->getId();
            pack.addOtherBuilding.alegence = newBuilding[i]->getAlegence();
            pack.addOtherBuilding.posi = newBuilding[i]->getPos().get();
            memcpy(pack.addOtherBuilding.conf, &newBuilding[i]->getConf()[0], newBuilding[i]->getConf().size());
            pack.addOtherBuilding.len = newBuilding[i]->getHp();
            pack.addOtherBuilding.isActive = newBuilding[i]->getIsActive();
            std::vector<double> weaponCd = newBuilding[i]->getWeaponsCd();
            for (int j = 0; j < (int)weaponCd.size(); j += 1)
                pack.addOtherBuilding.cdr[j] = weaponCd[j];
            pack.addOtherBuilding.nbrCdr = weaponCd.size();
            udp->sendData((char *)&pack, sizeof(Packet), client);
            otherBuildings.push_back(newBuilding[i]);
        }
    }
}
