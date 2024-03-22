#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::Display(Bpixelarray &px,
                                    ef::Camera &cam)
{
    for(int i=0; i < (int) playersInfo.size(); i++)
        playersInfo[i]->Display(px,cam,true);
    Pos casePos;
    Pos pixPos;
    Pos pxSize = px.GetSize();
    Pos mapSize = trueMap.getMapSize();
    mapSize.x = pxSize.x / mapSize.x;
    mapSize.y = pxSize.y / mapSize.y;
    for(int i=0; i < (int) neutralBuildings.size(); i++)
      if(cam.IsIn(neutralBuildings[i]->getPos(), neutralBuildings[i]->getImg()))
	neutralBuildings[i]->Display(px, mapSize, cam.getPos());
}
