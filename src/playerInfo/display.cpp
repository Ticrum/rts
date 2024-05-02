// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 24/04/2024 17:05:31 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

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
  AcuPos rationMapPix;
  rationMapPix.x = (pxSize.x * cam.getZoom()) / (double)map.getMapSize().x;
  rationMapPix.y = (pxSize.y * cam.getZoom()) / (double)map.getMapSize().y;
  AcuPos camPos = cam.getPos();
  //clear map
  if (fog)
    {
      for (int i = 0; i < pxSize.x * pxSize.y; i += 1)
	{
	  int index = (int)((i % pxSize.x + cam.getPos().x * cam.getZoom()) * ((double)map.getMapSize().x / ((double)pxSize.x * cam.getZoom()))) + (int)((i / pxSize.x + cam.getPos().y * cam.getZoom()) * ((double)map.getMapSize().y / ((double)pxSize.y * cam.getZoom()))) * map.getMapSize().x;
	  if (index < map.getMapSize().x * map.getMapSize().y && index >= 0 && i % pxSize.x > -cam.getPos().x && i % pxSize.x < (-cam.getPos().x + pxSize.x * cam.getZoom()))
	    {
	      pixPos.x = i % pxSize.x;
	      pixPos.y = i / pxSize.x;
	      if (map[index] == 0)
		{
		  t_bunny_color tempColor;
		  tempColor.full = GREEN;
		  tempColor.argb[GREEN_CMP] = tempColor.argb[GREEN_CMP] - 50;
		  px.placePixel(pixPos, tempColor.full);
		}
	      else if (map[index] == 1)
		px.placePixel(pixPos, BLUE);
	    }
	}
    }
  //display unit & building
  for(unsigned int i = 0; i < buildings.size(); i++)
    {
      //std::cout<<"BUILD (" << buildings.size()<< ")\n";
      casePos = buildings[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      //if(cam.IsIn(pixPos, buildings[i]->getImg()))
      buildings[i]->Display(px, rationMapPix, camPos, cam.getZoom());
    }
  for(unsigned int i = 0; i < otherBuildings.size(); i++)
    {
      //std::cout<<"otherBUILD (" << otherBuildings.size()<< ")\n";
      casePos = otherBuildings[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      //if(cam.IsIn(pixPos, otherBuildings[i]->getImg()))
      otherBuildings[i]->Display(px, rationMapPix, camPos, cam.getZoom());
    }
  for(unsigned int i = 0; i < units.size(); i++)
    {
      //std::cout<<"UNIT (" << units.size()<< ")\n";
      casePos = units[i]->getActualPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      //if(cam.IsIn(pixPos, units[i]->getImg()))
      units[i]->UnitDisplay(px, rationMapPix, camPos, cam.getZoom());
    }
  for(unsigned int i = 0; i < otherUnits.size(); i++)
    {
      //std::cout<<"otherUNIT (" << otherUnits.size()<< ")\n";
      casePos = otherUnits[i]->getActualPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      //if(cam.IsIn(pixPos, otherUnits[i]->getImg()))
      otherUnits[i]->UnitDisplay(px, rationMapPix, camPos, cam.getZoom());
    }

  for(unsigned int i = 0; i < buildings.size(); i++)
    {
      //std::cout<<"BUILD health(" << buildings.size()<< ")\n";
      casePos = buildings[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      //if(cam.IsIn(pixPos, buildings[i]->getImg()))
      buildings[i]->DisplayHealth(px, rationMapPix, camPos, cam.getZoom());
    }
  for(unsigned int i = 0; i < otherBuildings.size(); i++)
    {
      //std::cout<<"otherBUILD health(" << otherBuildings.size()<< ")\n";
      casePos = otherBuildings[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      //if(cam.IsIn(pixPos, otherBuildings[i]->getImg()))
      otherBuildings[i]->DisplayHealth(px, rationMapPix, camPos, cam.getZoom());
    }
  for(unsigned int i = 0; i < units.size(); i++)
    {
      //std::cout<<"UNIT health(" << units.size()<< ")\n";
      casePos = units[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      //if(cam.IsIn(pixPos, units[i]->getImg()))
      units[i]->DisplayHealth(px, rationMapPix, camPos, cam.getZoom(), units[i]->getPartPath(), units[i]->getProgress());
    }
  for(unsigned int i = 0; i < otherUnits.size(); i++)
    {
      //std::cout<<"otherUNIT health(" << otherUnits.size()<< ")\n";
      casePos = otherUnits[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      //if(cam.IsIn(pixPos, otherUnits[i]->getImg()))
      otherUnits[i]->DisplayHealth(px, rationMapPix, camPos, cam.getZoom(), otherUnits[i]->getPartPath(), otherUnits[i]->getProgress());
    }
  
  // display fog
  if(!fog)
    return;
  rationMapPix.x = visionMap.getMapSize().x;
  rationMapPix.y = visionMap.getMapSize().y;
  int totalpx = pxSize.x * pxSize.y;
  int rdm;
  t_bunny_color color;
  Pos tmp;

  for(int i = 0; i < totalpx; i++)
    {
      int index = (int)((i % pxSize.x + cam.getPos().x * cam.getZoom()) * ((double)rationMapPix.x / ((double)pxSize.x * cam.getZoom()))) + (int)((i / pxSize.x + cam.getPos().y * cam.getZoom()) * ((double)rationMapPix.y / ((double)pxSize.y * cam.getZoom()))) * rationMapPix.x;
      if (index < visionMap.getMapSize().x * visionMap.getMapSize().y && index >= 0 && i % pxSize.x > -cam.getPos().x && i % pxSize.x < (-cam.getPos().x + pxSize.x * cam.getZoom()))
	{
	  switch(visionMap[index])
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
	      color.argb[ALPHA_CMP] = 100 - (rand()%32);
	      tmp.x = i % pxSize.x;
	      tmp.y = i / pxSize.x;
	      px.placePixel(tmp, color.full);
	    }
	}
      else
	{
	  rdm = rand() % 31;
	  color.argb[RED_CMP] = rdm;
	  color.argb[GREEN_CMP] = rdm;
	  color.argb[BLUE_CMP] = rdm;
	  color.argb[ALPHA_CMP] = 255 - (rdm%15);
	  tmp.x = i % pxSize.x;
	  tmp.y = i / pxSize.x;
	  px.placePixel(tmp, color.full);
	}
    }
  // display minimap
  pxSize.x = pxSize.x * 0.3;
  pxSize.y = pxSize.y * 0.3;
  rationMapPix.x = (pxSize.x) / (double)map.getMapSize().x;
  rationMapPix.y = (pxSize.y) / (double)map.getMapSize().y;
  for(int i = 0; i < pxSize.x * pxSize.y; i++)
    {
      int index = (int)((i % pxSize.x) / (double)rationMapPix.x) + (int)((i / pxSize.x) / (double)rationMapPix.y) * map.getMapSize().x;
      if (index < visionMap.getMapSize().x * visionMap.getMapSize().y && index >= 0 && i % pxSize.x > 0 && i % pxSize.x < pxSize.x)
	{
	  switch(visionMap[index])
	    {
	    case 0:
	      color.argb[RED_CMP] = 0;
	      color.argb[GREEN_CMP] = 0;
	      color.argb[BLUE_CMP] = 0;
	      color.argb[ALPHA_CMP] = 255;
	      tmp.x = i % (int)pxSize.x;
	      tmp.y = i / pxSize.x + (pxSize.y * 2);
	      px.placePixel(tmp, color.full);
	      break;
	    case 1:
	      color.argb[RED_CMP] = 0;
	      color.argb[GREEN_CMP] = 100;
	      color.argb[BLUE_CMP] = 0;
	      color.argb[ALPHA_CMP] = 255;
	      tmp.x = i % (int)pxSize.x;
	      tmp.y = i / pxSize.x + (pxSize.y * 2);
	      px.placePixel(tmp, color.full);
	      break;
	    case 2:
	      color.argb[RED_CMP] = 0;
	      color.argb[GREEN_CMP] = 180;
	      color.argb[BLUE_CMP] = 0;
	      color.argb[ALPHA_CMP] = 255;
	      tmp.x = i % (int)pxSize.x;
	      tmp.y = i / pxSize.x + (pxSize.y * 2);
	      px.placePixel(tmp, color.full);
	    }
	}
      else
	{
	  rdm = rand() % 31;
	  color.argb[RED_CMP] = rdm;
	  color.argb[GREEN_CMP] = rdm;
	  color.argb[BLUE_CMP] = rdm;
	  color.argb[ALPHA_CMP] = 255 - (rdm%15);
	  tmp.x = i % (int)pxSize.x;
	  tmp.y = i / pxSize.x + (pxSize.y * 2);
	  px.placePixel(tmp, color.full);
	}
    }
  int decal = pxSize.y * 2;
  for(unsigned int i = 0; i < buildings.size(); i++)
    {
      casePos = buildings[i]->getPos();
      tmp.x = casePos.x * rationMapPix.x;
      tmp.y = casePos.y * rationMapPix.y + (decal);
      color.full = GREEN;
      px.placePixel(tmp, color.full);
      tmp.x += 1;
      px.placePixel(tmp, color.full);
      tmp.x -= 2;
      px.placePixel(tmp, color.full);
      tmp.x += 1;
      tmp.y += 1;
      px.placePixel(tmp, color.full);
      tmp.y -= 2;
      px.placePixel(tmp, color.full);
    }
  for(unsigned int i = 0; i < units.size(); i++)
    {
      casePos = units[i]->getActualPos();
      tmp.x = casePos.x * rationMapPix.x;
      tmp.y = casePos.y * rationMapPix.y + (decal);
      color.full = GREEN;
      px.placePixel(tmp, color.full);
    }
  for(unsigned int i = 0; i < otherBuildings.size(); i++)
    {
      casePos = otherBuildings[i]->getPos();
      tmp.x = casePos.x * rationMapPix.x;
      tmp.y = casePos.y * rationMapPix.y + (decal);
      color.full = RED;
      px.placePixel(tmp, color.full);
      tmp.x += 1;
      px.placePixel(tmp, color.full);
      tmp.x -= 2;
      px.placePixel(tmp, color.full);
      tmp.x += 1;
      tmp.y += 1;
      px.placePixel(tmp, color.full);
      tmp.y -= 2;
      px.placePixel(tmp, color.full);
    }
  for(unsigned int i = 0; i < otherUnits.size(); i++)
    {
      casePos = otherUnits[i]->getActualPos();
      tmp.x = casePos.x * rationMapPix.x;
      tmp.y = casePos.y * rationMapPix.y + (decal);
      color.full = RED;
      px.placePixel(tmp, color.full);
    }
  Pos start;
  start.x = cam.getPos().x * 0.3;
  start.y = cam.getPos().y * 0.3 + decal;
  Pos end;
  end.x = start.x + pxSize.x / cam.getZoom();
  end.y = start.y + pxSize.y / cam.getZoom();
  tmp = start;
  color.full = WHITE;
  while (tmp.x < end.x)
    {
      px.placePixel(tmp, color.full);
      tmp.x += 1;
    }
  while (tmp.y < end.y)
    {
      px.placePixel(tmp, color.full);
      tmp.y += 1;
    }
  while (tmp.x > start.x)
    {
      px.placePixel(tmp, color.full);
      tmp.x -= 1;
    }
  while (tmp.y > start.y)
    {
      px.placePixel(tmp, color.full);
      tmp.y -= 1;
    }
}
