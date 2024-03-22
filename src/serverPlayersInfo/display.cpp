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
    mapSize.x = (pxSize.x * cam.getZoom()) / mapSize.x;
    mapSize.y = (pxSize.y * cam.getZoom()) / mapSize.y;
    for(int i=0; i < (int) neutralBuildings.size(); i++)
      if(cam.IsIn(neutralBuildings[i]->getPos(), neutralBuildings[i]->getImg()))
	neutralBuildings[i]->Display(px, mapSize, cam.getPos());
}
