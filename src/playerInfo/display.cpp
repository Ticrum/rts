#include "playerInfo.hh"
#include "Bpixelarray.hh"
#include <stdlib.h>

void ef::PlayerInfo::Display(ef::Bpixelarray &px,
                             std::vector<ef::Bpixelarray> &rsrc,
                             ef::Camera &cam,
                             bool fog)
{
    Pos casePos;
    Pos pixPos;
    Pos pxSize = px.GetSize();
    Pos mapSize = map.getMapSize();
    mapSize.x = pxSize.x / mapSize.x;
    mapSize.y = pxSize.y / mapSize.y;
    for(unsigned int i = 0; units.size(); i++)
    {
        casePos = units[i]->getPos();
        pixPos.x = casePos.x * mapSize.x;
        pixPos.y = casePos.y * mapSize.y;
        if(cam.IsIn(pixPos, rsrc[units[i]->getImgId()]))
            units[i]->UnitDisplay(px, rsrc, mapSize);
    }
    if(fog)
        for(unsigned int i = 0; otherUnits.size(); i++)
        {
            casePos = otherUnits[i]->getPos();
            pixPos.x = casePos.x * mapSize.x;
            pixPos.y = casePos.y * mapSize.y;
            if(cam.IsIn(pixPos, rsrc[otherUnits[i]->getImgId()]))
                otherUnits[i]->UnitDisplay(px, rsrc, mapSize);
        }
    for(unsigned int i = 0; buildings.size(); i++)
        {
            casePos = buildings[i]->getPos();
            pixPos.x = casePos.x * mapSize.x;
            pixPos.y = casePos.y * mapSize.y;
            if(cam.IsIn(pixPos, rsrc[buildings[i]->getImgId()]))
                buildings[i]->Display(px, rsrc, mapSize);
        }
    if(fog)
        for(unsigned int i = 0; otherBuildings.size(); i++)
        {
            casePos = otherBuildings[i]->getPos();
            pixPos.x = casePos.x * mapSize.x;
            pixPos.y = casePos.y * mapSize.y;
            if(cam.IsIn(pixPos, rsrc[otherBuildings[i]->getImgId()]))
                otherBuildings[i]->Display(px, rsrc, mapSize);
        }

    if(fog)
        return;
    mapSize = visionMap.getMapSize();
    mapSize.x = mapSize.x * mapSize.y;
    pxSize.y = pxSize.x * pxSize.y;
    int rdm;
    t_bunny_color color;
    Pos tmp;
    for(int i = 0; i < pxSize.y; i++)
    {
        switch(visionMap[(i/pxSize.y) * mapSize.x])
        {
        case 0:
            rdm = rand() % 31;
            color.argb[RED_CMP] = rdm;
            color.argb[GREEN_CMP] = rdm;
            color.argb[BLUE_CMP] = rdm;
            color.argb[ALPHA_CMP] = 255 - (rdm%21);
            tmp.x = i % pxSize.x;
            tmp.y = i / pxSize.x;
            px.placePixel(tmp, color.full);
            break;
        case 1:
            color.argb[RED_CMP] = 0;
            color.argb[GREEN_CMP] = 0;
            color.argb[BLUE_CMP] = 0;
            color.argb[ALPHA_CMP] = 100 - (rand()%41);
            tmp.x = i % pxSize.x;
            tmp.y = i / pxSize.x;
            px.placePixel(tmp, color.full);
        }
    }
}
