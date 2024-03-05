// EFRITS
// project:     rts
// created on:  2024-02-27 - 11:27 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: selectUnit implementation

#include "clientPlayerInfo.hh"

void ef::ClientPlayerInfo::select(Pos start,
                                  Pos end)
{
    selectedUnit = playerInfo.selectUnit(start, end);
    selectedBuilding = playerInfo.selectBuilding(start, end);
}

