#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::Display(Bpixelarray &px,
                                    ef::Camera &cam)
{
    for(int i=0; i < (int) playersInfo.size(); i++)
        playersInfo[i]->Display(px,cam,false);
    Pos casePos;
    Pos pixPos;
    Pos pxSize = px.GetSize();
    Pos mapSize = trueMap.getMapSize();
    mapSize.x = pxSize.x / mapSize.x;
    mapSize.y = pxSize.y / mapSize.y;
    for(int i=0; i < (int) neutralBuildings.size(); i++)
    {
        casePos = neutralBuildings[i]->getPos();
        pixPos.x = casePos.x * mapSize.x;
        pixPos.y = casePos.y * mapSize.y;
        if(cam.IsIn(pixPos, neutralBuildings[i]->getImg()))
            neutralBuildings[i]->Display(px, mapSize);
    }
}
