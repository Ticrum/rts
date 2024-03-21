#include "playerInfo.hh"
#include "Bpixelarray.hh"
#include <stdlib.h>
#include <iostream>
void ef::PlayerInfo::Display(ef::Bpixelarray &px,
                             ef::Camera &cam,
                             bool fog)
{
  Pos casePos;
  Pos pixPos;
  Pos pxSize = px.GetSize();
  Pos mapSize = map.getMapSize();
  mapSize.x = (pxSize.x / mapSize.x) * cam.getZoom();
  mapSize.y = (pxSize.y / mapSize.y) * cam.getZoom();

  for(unsigned int i = 0; i < buildings.size(); i++)
    {
      std::cout<<"BUILD (" << buildings.size()<< ")\n";
      casePos = buildings[i]->getPos();
      pixPos.x = casePos.x * mapSize.x;
      pixPos.y = casePos.y * mapSize.y;
      if(cam.IsIn(pixPos, buildings[i]->getImg()))
	buildings[i]->Display(px, mapSize);
    }
  for(unsigned int i = 0; i < otherBuildings.size(); i++)
    {
      std::cout<<"otherBUILD (" << otherBuildings.size()<< ")\n";
      casePos = otherBuildings[i]->getPos();
      pixPos.x = casePos.x * mapSize.x;
      pixPos.y = casePos.y * mapSize.y;
      if(cam.IsIn(pixPos, otherBuildings[i]->getImg()))
	otherBuildings[i]->Display(px, mapSize);
    }
  for(unsigned int i = 0; i < units.size(); i++)
    {
      std::cout<<"UNIT (" << units.size()<< ")\n";
      casePos = units[i]->getPos();
      pixPos.x = casePos.x * mapSize.x;
      pixPos.y = casePos.y * mapSize.y;
      if(cam.IsIn(pixPos, units[i]->getImg()))
	units[i]->UnitDisplay(px, mapSize);
    }
  for(unsigned int i = 0; i < otherUnits.size(); i++)
    {
      std::cout<<"otherUNIT (" << otherUnits.size()<< ")\n";
      casePos = otherUnits[i]->getPos();
      pixPos.x = casePos.x * mapSize.x;
      pixPos.y = casePos.y * mapSize.y;
      if(cam.IsIn(pixPos, otherUnits[i]->getImg()))
	otherUnits[i]->UnitDisplay(px, mapSize);
    }
                                                           
  for(unsigned int i = 0; i < buildings.size(); i++)
    {
      std::cout<<"BUILD health(" << buildings.size()<< ")\n";
      casePos = buildings[i]->getPos();
      pixPos.x = casePos.x * mapSize.x;
      pixPos.y = casePos.y * mapSize.y;
      if(cam.IsIn(pixPos, buildings[i]->getImg()))
	buildings[i]->DisplayHealth(px, mapSize);
    }
  for(unsigned int i = 0; i < otherBuildings.size(); i++)
    {
      std::cout<<"otherBUILD health(" << otherBuildings.size()<< ")\n";
      casePos = otherBuildings[i]->getPos();
      pixPos.x = casePos.x * mapSize.x;
      pixPos.y = casePos.y * mapSize.y;
      if(cam.IsIn(pixPos, otherBuildings[i]->getImg()))
	otherBuildings[i]->DisplayHealth(px, mapSize);
    }
  for(unsigned int i = 0; i < units.size(); i++)
    {
      std::cout<<"UNIT health(" << units.size()<< ")\n";
      casePos = units[i]->getPos();
      pixPos.x = casePos.x * mapSize.x;
      pixPos.y = casePos.y * mapSize.y;
      if(cam.IsIn(pixPos, units[i]->getImg()))
	units[i]->DisplayHealth(px, mapSize, units[i]->getPathLeft(), units[i]->getProgress());
    }
  for(unsigned int i = 0; i < otherUnits.size(); i++)
    {
      std::cout<<"otherUNIT health(" << otherUnits.size()<< ")\n";
      casePos = otherUnits[i]->getPos();
      pixPos.x = casePos.x * mapSize.x;
      pixPos.y = casePos.y * mapSize.y;
      if(cam.IsIn(pixPos, otherUnits[i]->getImg()))
	otherUnits[i]->DisplayHealth(px, mapSize, otherUnits[i]->getPathLeft(), otherUnits[i]->getProgress());
    }
  
  
  if(!fog)
    return;
  mapSize = visionMap.getMapSize();
  int totalpx = pxSize.x * pxSize.y;
  int rdm;
  t_bunny_color color;
  Pos tmp;
  std::cout << "////DisplayFog////" << std::endl;
  std::cout << "pxSizex : " << pxSize.x << std::endl;
  std::cout << "pxSizey : " << pxSize.y << std::endl;
  std::cout << "mapSizex : " << mapSize.x << std::endl;
  std::cout << "mapSizey : " << mapSize.y << std::endl;
  /*  Pos compt(0);
      while (compt.x < pxSize.x && compt.y)*/



  
  for(int i = 0; i < totalpx; i++)
    {
      //switch(visionMap[(i % pxSize.x + cam.getPos().x) * ((double)mapSize.x / ((double)pxSize.x / cam.getZoom())) + ((i / pxSize.x + cam.getPos().y) * ((double)mapSize.x / ((double)pxSize.x / cam.getZoom()))) * mapSize.x])
      //visionMap[(int)((i % pxSize.x) * ((double)mapSize.x / ((double)pxSize.x))) + (int)((i / pxSize.x) * ((double)mapSize.y / ((double)pxSize.y))) * mapSize.x] = 9;
      //std::cout<< "\n\n___--- PUTE ---___\n";
      //visionMap.print();
      //std::cout << "POS x : " << i % pxSize.x << " y : " << i / pxSize.x << std::endl;
      //usleep(0.05e6);
      switch(visionMap[(int)((i % pxSize.x + cam.getPos().x) * ((double)mapSize.x / ((double)pxSize.x * cam.getZoom()))) + (int)((i / pxSize.x + cam.getPos().y) * ((double)mapSize.y / ((double)pxSize.y * cam.getZoom()))) * mapSize.x])
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
	  color.argb[GREEN_CMP] = 0;
	  color.argb[BLUE_CMP] = 0;
	  color.argb[ALPHA_CMP] = 50 - (rand()%32);
	  tmp.x = i % pxSize.x;
	  tmp.y = i / pxSize.x;
	  px.placePixel(tmp, color.full);
        }
    }
}
