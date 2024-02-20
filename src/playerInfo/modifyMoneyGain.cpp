// EFRITS
// project:     rts
// created on:  2024-02-13 - 12:59 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: modifyMoneyGain implementation

#include "playerInfo.hh"

void ef::PlayerInfo::modifyMoneyGain(int money)
{
    moneyGain += money;
    if (moneyGain < 0)
        moneyGain = 0;
}

