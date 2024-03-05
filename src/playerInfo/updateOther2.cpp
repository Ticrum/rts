// EFRITS
// project:     rts
// created on:  2024-02-22 - 12:02 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: updateOther2 implementation

#include "playerInfo.hh"

void ef::PlayerInfo::updateOther(std::vector<std::shared_ptr<Unit>> newUnit,
                                 std::shared_ptr<UdpConnect> udp,
                                 struct sockaddr_in client)
{
    for (int i = 0; i < (int)newUnit.size(); i += 1)
    {
        bool hasFind = false;
        for (int j = 0; j < (int)otherUnits.size(); j += 1)
            if (otherUnits[j]->getId() == newUnit[i]->getId())
            {
                hasFind = true;
                break;
            }
        if (!hasFind)
        {
            Packet pack;
            pack.type = ADDOTHERUNIT;
            pack.addOtherUnit.unitId = newUnit[i]->getId();
            pack.addOtherUnit.isOther = true;
            pack.addOtherUnit.alegence = newUnit[i]->getAlegence();
            pack.addOtherUnit.posi = newUnit[i]->getPos().get();
            memcpy(pack.addOtherUnit.conf, &newUnit[i]->getConf()[0], newUnit[i]->getConf().size());
            pack.addOtherUnit.len = newUnit[i]->getConf().size();
            pack.addOtherUnit.actualHp = newUnit[i]->getHp();
            pack.addOtherUnit.progress = newUnit[i]->getProgress();
            pack.addOtherUnit.moveType = newUnit[i]->getMoveType();
            std::vector<ConformPos> newPos = newUnit[i]->getPathLeft();
            for (int j = 0; j < (int)newPos.size(); j += 1)
                pack.addOtherUnit.pos[j] = newPos[j];
            pack.addOtherUnit.nbrPos = newPos.size();
            std::vector<double> weaponCd = newUnit[i]->getWeaponsCd();
            for (int j = 0; j < (int)weaponCd.size(); j += 1)
                pack.addOtherUnit.cdr[j] = weaponCd[j];
            pack.addOtherUnit.nbrCdr = weaponCd.size();
            udp->sendData((char *)&pack, sizeof(Packet), client);
            otherUnits.push_back(newUnit[i]);
        }
    }
}

