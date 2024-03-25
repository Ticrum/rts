#include "playerInfo.hh"
#include "Bpixelarray.hh"
#include <stdlib.h>

void ef::PlayerInfo::Display(ef::Bpixelarray &px,
                             ef::Camera &cam,
                             bool fog)
{
  Pos casePos;
  Pos pixPos;
  Pos pxSize = px.GetSize();
  Pos rationMapPix = map.getMapSize();
  rationMapPix.x = (pxSize.x * cam.getZoom()) / rationMapPix.x;
  rationMapPix.y = (pxSize.y * cam.getZoom()) / rationMapPix.y;
  AcuPos camPos = cam.getPos();
  
   for(unsigned int i = 0; i < buildings.size(); i++)
    {
      //std::cout<<"BUILD (" << buildings.size()<< ")\n";
      casePos = buildings[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      //if(cam.IsIn(pixPos, buildings[i]->getImg()))
	buildings[i]->Display(px, rationMapPix, camPos);
    }
  for(unsigned int i = 0; i < otherBuildings.size(); i++)
    {
      //std::cout<<"otherBUILD (" << otherBuildings.size()<< ")\n";
      casePos = otherBuildings[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      //if(cam.IsIn(pixPos, otherBuildings[i]->getImg()))
	otherBuildings[i]->Display(px, rationMapPix, camPos);
    }
  for(unsigned int i = 0; i < units.size(); i++)
    {
      //std::cout<<"UNIT (" << units.size()<< ")\n";
      casePos = units[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      //if(cam.IsIn(pixPos, units[i]->getImg()))
	units[i]->UnitDisplay(px, rationMapPix, camPos);
    }
  for(unsigned int i = 0; i < otherUnits.size(); i++)
    {
      //std::cout<<"otherUNIT (" << otherUnits.size()<< ")\n";
      casePos = otherUnits[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      //if(cam.IsIn(pixPos, otherUnits[i]->getImg()))
	otherUnits[i]->UnitDisplay(px, rationMapPix, camPos);
    }
                                                           
  for(unsigned int i = 0; i < buildings.size(); i++)
    {
      //std::cout<<"BUILD health(" << buildings.size()<< ")\n";
      casePos = buildings[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      //if(cam.IsIn(pixPos, buildings[i]->getImg()))
	buildings[i]->DisplayHealth(px, rationMapPix, camPos);
    }
  for(unsigned int i = 0; i < otherBuildings.size(); i++)
    {
      //std::cout<<"otherBUILD health(" << otherBuildings.size()<< ")\n";
      casePos = otherBuildings[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      //if(cam.IsIn(pixPos, otherBuildings[i]->getImg()))
	otherBuildings[i]->DisplayHealth(px, rationMapPix, camPos);
    }
  for(unsigned int i = 0; i < units.size(); i++)
    {
      //std::cout<<"UNIT health(" << units.size()<< ")\n";
      casePos = units[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      //if(cam.IsIn(pixPos, units[i]->getImg()))
	units[i]->DisplayHealth(px, rationMapPix, camPos, units[i]->getPartPath(), units[i]->getProgress());
    }
  for(unsigned int i = 0; i < otherUnits.size(); i++)
    {
      //std::cout<<"otherUNIT health(" << otherUnits.size()<< ")\n";
      casePos = otherUnits[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      //if(cam.IsIn(pixPos, otherUnits[i]->getImg()))
	otherUnits[i]->DisplayHealth(px, rationMapPix, camPos, otherUnits[i]->getPartPath(), otherUnits[i]->getProgress());
    }
  
  
  if(!fog)
    return;
  rationMapPix = visionMap.getMapSize();
  int totalpx = pxSize.x * pxSize.y;
  int rdm;
  t_bunny_color color;
  Pos tmp;

  for(int i = 0; i < totalpx; i++)
    {
      switch(visionMap[(int)((i % pxSize.x + cam.getPos().x) * ((double)rationMapPix.x / ((double)pxSize.x * cam.getZoom()))) + (int)((i / pxSize.x + cam.getPos().y) * ((double)rationMapPix.y / ((double)pxSize.y * cam.getZoom()))) * rationMapPix.x])
        {
	case 0:
	  rdm = rand() % 31;
	  color.argb[RED_CMP] = rdm;
	  color.argb[GREEN_CMP] = rdm;
	  color.argb[BLUE_CMP] = rdm;
	  color.argb[ALPHA_CMP] = 255 - (rdm%15);
	  tmp.x = i % pxSize.x;
	  tmp.y = i / pxSize.x;
	  px.placePixel(tmp, color.full);
	  break;
        case 1:
	  color.argb[RED_CMP] = 0;
	  color.argb[GREEN_CMP] = 40;
	  color.argb[BLUE_CMP] = 0;
	  color.argb[ALPHA_CMP] = 50 - (rand()%32);
	  tmp.x = i % pxSize.x;
	  tmp.y = i / pxSize.x;
	  px.placePixel(tmp, color.full);
        }
    }
}
