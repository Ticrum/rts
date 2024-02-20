#include "playerInfo.hh"


void ef::ServerPlayersInfo::Display(Bpixelarray &px,
                                    std::vector<Bpixelarray> &rsrc,
                                    ef::Camera &cam)
{
    for(int i=0; i < (int) playersInfo.size(); i++)
        playersInfo[i].Display(px,rsrc,cam,false);
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
        if(cam.IsIn(pixPos, rsrc[neutralBuildings[i]->getImgId()]))
            neutralBuildings[i]->Display(px, rsrc, mapSize);
    }
}
