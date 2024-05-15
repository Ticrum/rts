#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::Display(Bpixelarray &px,
                                    ef::Camera &cam)
{
    for(int i=0; i < (int) playersInfo.size(); i++)
      playersInfo[i]->Display(px,cam,false);
    Pos casePos;
    Pos pixPos;
    Pos pxSize = px.GetSize();
    AcuPos mapSize;
    mapSize.x = (pxSize.x * cam.getZoom()) / trueMap.getMapSize().x;
    mapSize.y = (pxSize.y * cam.getZoom()) / trueMap.getMapSize().y;
    for(int i=0; i < (int) neutralBuildings.size(); i++)
      if(cam.IsIn(neutralBuildings[i]->getPos(), mapSize, neutralBuildings[i]->getImg()))
	neutralBuildings[i]->Display(px, mapSize, cam.getPos(), cam.getZoom());
}
