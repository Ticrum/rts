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
  int startTime = clock();
  Pos casePos;
  Pos pixPos;
  Pos pxSize = px.GetSize();
  AcuPos rationMapPix;
  t_bunny_color color;
  rationMapPix.x = (pxSize.x * cam.getZoom()) / (double)map.getMapSize().x;
  rationMapPix.y = (pxSize.y * cam.getZoom()) / (double)map.getMapSize().y;
  AcuPos camPos = cam.getPos();
  //clear map
  if (fog)
    {
      /*Acu*/Pos mapSize;
      mapSize.x = map.getMapSize().x;
      mapSize.y = map.getMapSize().y;
      /*Acu*/Pos limit;
      limit.x = ((camPos.x * cam.getZoom() + (double)pxSize.x) / rationMapPix.x) +1;
      limit.y = ((camPos.y * cam.getZoom() + (double)pxSize.y) / rationMapPix.y) +1;
      AcuPos rectSize;
      rectSize.x = rationMapPix.x;
      rectSize.y = rationMapPix.y;
      /*Acu*/Pos cursor;
      cursor.x = (camPos.x * cam.getZoom()) / rationMapPix.x -1;
      cursor.y = (camPos.y * cam.getZoom()) / rationMapPix.y -1;
      Pos casePx;
      /*std::cout << "__-PL INFO-__\npxSize : " << pxSize.x << " : " << pxSize.y <<
	"\nzoom : " << cam.getZoom()<<
	"\nmapSize : "<< mapSize.x << " | "<< mapSize.y <<
	"\nrationMapPix : " << rationMapPix.x << " | " << rationMapPix.y <<
	"\ncamPos : " << camPos.x << " | " << camPos.y <<
	"\nlimit : " << limit.x << " | " << limit.y <<
	"\ncursor : " << cursor.x << " | "<< cursor.y<<
	"\n--_________--" << std::endl;*/
      /*casePx.x = cursor.x * rationMapPix.x - (camPos.x * cam.getZoom());
	casePx.y = cursor.y * rationMapPix.y - (camPos.y * cam.getZoom());
	Pos caseStart(casePx);*/
      while(cursor.x + mapSize.x * cursor.y < limit.x + mapSize.x *  limit.y)
	{
	  if(cursor.x >= 0 && cursor.x < mapSize.x &&
	     cursor.y >= 0 && cursor.y < mapSize.y)
	    {
	      switch(map[cursor.x + cursor.y * mapSize.x])
		{
		case 0:
		  color.full = GREEN;
		  color.argb[GREEN_CMP] = 170;
		  color.argb[RED_CMP] = 30;
		  
		  break;
		case 1:
		  color.full = BLUE;
		}
	    }
	  else
	    {
	      color.argb[RED_CMP] = 200;
	      color.argb[GREEN_CMP] = 200;
	      color.argb[BLUE_CMP] = 200;
	      color.argb[ALPHA_CMP] = 255;
	    }
	  if(color.argb[ALPHA_CMP] != 0)
	    {
	      casePx.x = cursor.x * rationMapPix.x - (camPos.x * cam.getZoom());
	      casePx.y = cursor.y * rationMapPix.y - (camPos.y * cam.getZoom());
	      px.rectangle(casePx, rectSize, color.full, color.full);
	    }
	  /*if(casePx.y >= caseStart.y + (rationMapPix.y *(div-1)) /div)
	    {*/
	  if(cursor.x >= limit.x)
	    {
	      cursor.x = (camPos.x* cam.getZoom()) / rationMapPix.x;
	      cursor.y ++;
	    }
	  else
	    cursor.x ++;
	  /*casePx.x = cursor.x * rationMapPix.x - (camPos.x * cam.getZoom());
	    casePx.y = cursor.y * rationMapPix.y - (camPos.y * cam.getZoom());
	    caseStart.x = casePx.x;
	    caseStart.y = casePx.y;
	    }
	    else
	    {
	    if(casePx.x >= caseStart.x + rationMapPix.x)
	    {
	    casePx.x = cursor.x * rationMapPix.x - (camPos.x * cam.getZoom());
	    casePx.y += rectSize.y;
	    }
	    else
	    casePx.x += rectSize.x;
	    }*/
	}
      /*
	for (int i = 0; i < pxSize.x * pxSize.y; i += 1)
	{
	int index = (int)((i % pxSize.x + camPos.x * cam.getZoom()) * ((double)map.getMapSize().x / ((double)pxSize.x * cam.getZoom()))) + (int)((i / pxSize.x + camPos.y * cam.getZoom()) * ((double)map.getMapSize().y / ((double)pxSize.y * cam.getZoom()))) * map.getMapSize().x;
	if (index < map.getMapSize().x * map.getMapSize().y && index >= 0 && i % pxSize.x > -camPos.x && i % pxSize.x < (-camPos.x + pxSize.x * cam.getZoom()))
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
	if (px.pixVec.length > 70000)
	{
	bunny_set_geometry(&px.GetClip()->buffer, BGY_PIXELS, (t_bunny_vertex_array *)&px.pixVec, NULL);
	px.pixVec.length = 0;
	}
	}
	}
      */
    }
  if (px.recVec.length > 0)
    bunny_set_geometry(&px.GetClip()->buffer, BGY_QUADS, (t_bunny_vertex_array *)&px.recVec, NULL);
  px.recVec.length = 0;
  //display unit & building
  for(unsigned int i = 0; i < buildings.size(); i++)
    {
      //std::cout<<"BUILD (" << buildings.size()<< ")\n";
      casePos = buildings[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      if(cam.IsIn(pixPos, rationMapPix, buildings[i]->getImg()))
	buildings[i]->Display(px, rationMapPix, camPos, cam.getZoom());
    }
  for(unsigned int i = 0; i < otherBuildings.size(); i++)
    {
      //std::cout<<"otherBUILD (" << otherBuildings.size()<< ")\n";
      casePos = otherBuildings[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      if(cam.IsIn(pixPos, rationMapPix, otherBuildings[i]->getImg()))
	otherBuildings[i]->Display(px, rationMapPix, camPos, cam.getZoom());
    }
  for(unsigned int i = 0; i < units.size(); i++)
    {
      //std::cout<<"UNIT (" << units.size()<< ")\n";
      casePos = units[i]->getActualPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      if(cam.IsIn(pixPos, rationMapPix, units[i]->getImg()))
	units[i]->UnitDisplay(px, rationMapPix, camPos, cam.getZoom());
    }
  for(unsigned int i = 0; i < otherUnits.size(); i++)
    {
      //std::cout<<"otherUNIT (" << otherUnits.size()<< ")\n";
      casePos = otherUnits[i]->getActualPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      if(cam.IsIn(pixPos, rationMapPix, otherUnits[i]->getImg()))
	otherUnits[i]->UnitDisplay(px, rationMapPix, camPos, cam.getZoom());
    }

  for(unsigned int i = 0; i < buildings.size(); i++)
    {
      //std::cout<<"BUILD health(" << buildings.size()<< ")\n";
      casePos = buildings[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      if(cam.IsIn(pixPos, rationMapPix, buildings[i]->getImg()))
	{
	  buildings[i]->DisplayHealth(px, rationMapPix, camPos, cam.getZoom());
	  buildings[i]->displayProgress(px, rationMapPix, camPos, cam.getZoom(), buildings[i]);
	}
    }
  for(unsigned int i = 0; i < otherBuildings.size(); i++)
    {
      //std::cout<<"otherBUILD health(" << otherBuildings.size()<< ")\n";
      casePos = otherBuildings[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      if(cam.IsIn(pixPos, rationMapPix, otherBuildings[i]->getImg()))
	otherBuildings[i]->DisplayHealth(px, rationMapPix, camPos, cam.getZoom());
    }
  for(unsigned int i = 0; i < units.size(); i++)
    {
      //std::cout<<"UNIT health(" << units.size()<< ")\n";
      casePos = units[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      if(cam.IsIn(pixPos, rationMapPix, units[i]->getImg()))
	units[i]->DisplayHealth(px, rationMapPix, camPos, cam.getZoom(), units[i]->getPartPath(), units[i]->getProgress());
    }
  for(unsigned int i = 0; i < otherUnits.size(); i++)
    {
      //std::cout<<"otherUNIT health(" << otherUnits.size()<< ")\n";
      casePos = otherUnits[i]->getPos();
      pixPos.x = casePos.x * rationMapPix.x;
      pixPos.y = casePos.y * rationMapPix.y;
      if(cam.IsIn(pixPos, rationMapPix, otherUnits[i]->getImg()))
	otherUnits[i]->DisplayHealth(px, rationMapPix, camPos, cam.getZoom(), otherUnits[i]->getPartPath(), otherUnits[i]->getProgress());
    }
  if (px.recVec.length > 0)
    bunny_set_geometry(&px.GetClip()->buffer, BGY_QUADS, (t_bunny_vertex_array *)&px.recVec, NULL);
  px.recVec.length = 0;
  
  // display fog
  
  int rdm;
  Pos tmp;

  if(fog)
    {
      /*Pos ttMaxMap(visionMap.getMapSize());
      Pos ttChariot(0);
      while(ttChariot.x + ttMaxMap.x * ttChariot.y < ttMaxMap.y * ttMaxMap.x)
	{
	  if((ttChariot.x + ttChariot.y) % 2 == 0)
	    visionMap[ttChariot.x + ttChariot.y * ttMaxMap.x] = 3;
	  else
	    visionMap[ttChariot.x + ttChariot.y * ttMaxMap.x] = 4;
	  if(ttChariot.x == ttMaxMap.x)
	    {
	      ttChariot.y ++;
	      ttChariot.x = 0;
	    }
	  else
	    ttChariot.x ++;
	    }*/
      double div = 1.0;
      /*Acu*/Pos mapSize;
      /*Acu*/Pos limit;
      AcuPos rectSize;
      /*Acu*/Pos cursor;
      Pos casePx;
      mapSize.x = visionMap.getMapSize().x;
      mapSize.y = visionMap.getMapSize().y;
      limit.x = ((camPos.x * cam.getZoom() + (double)pxSize.x) / rationMapPix.x) +1;
      limit.y = ((camPos.y * cam.getZoom() + (double)pxSize.y) / rationMapPix.y) +1;
      rectSize.x = rationMapPix.x / div;
      rectSize.y = rationMapPix.y / div;
      cursor.x = (camPos.x * cam.getZoom()) / rationMapPix.x -1;
      cursor.y = (camPos.y * cam.getZoom()) / rationMapPix.y -1;
      /*std::cout << "__-PL INFO-__\npxSize : " << pxSize.x << " : " << pxSize.y <<
	"\nzoom : " << cam.getZoom()<<
	"\nmapSize : "<< mapSize.x << " | "<< mapSize.y <<
	"\nrationMapPix : " << rationMapPix.x << " | " << rationMapPix.y <<
	"\ncamPos : " << camPos.x << " | " << camPos.y <<
	"\nlimit : " << limit.x << " | " << limit.y <<
	"\ncursor : " << cursor.x << " | "<< cursor.y<<
	"\n--_________--" << std::endl;*/
      /*casePx.x = cursor.x * rationMapPix.x - (camPos.x * cam.getZoom());
	casePx.y = cursor.y * rationMapPix.y - (camPos.y * cam.getZoom());*/
      casePx.x = cursor.x * rationMapPix.x - (camPos.x * cam.getZoom());
      casePx.y = cursor.y * rationMapPix.y - (camPos.y * cam.getZoom());
      Pos caseStart(casePx);
      while(cursor.x + mapSize.x * cursor.y < limit.x + mapSize.x *  limit.y)
	{
	  /*while(casePx.y >= caseStart.y + rationMapPix.y)
	    {*/
   if(cursor.x >= 0 && cursor.x < mapSize.x &&
	 	 cursor.y >= 0 && cursor.y < mapSize.y)
		{
		  switch(visionMap[cursor.x + cursor.y * mapSize.x])
		    {
		    case 0:
		      rdm = rand() % 21;
		      color.argb[RED_CMP] = 10 + rdm;
		      color.argb[GREEN_CMP] = 10 + rdm;
		      color.argb[BLUE_CMP] = 10 + rdm;
		      color.argb[ALPHA_CMP] = 255 - (10 + rdm%15);
		      break;
		    case 1:
		      color.argb[RED_CMP] = 10;
		      color.argb[GREEN_CMP] = 10;
		      color.argb[BLUE_CMP] = 10;
		      color.argb[ALPHA_CMP] = 120 - (rand()%30);
		      break;
		    case 2:
		      color.argb[ALPHA_CMP] = 0;
		    }
		}
	      else
		{
		  color.argb[RED_CMP] = 255;
		  color.argb[GREEN_CMP] = 255;
		  color.argb[BLUE_CMP] = 255;
		  color.argb[ALPHA_CMP] = 255;
		}
	      if(color.argb[ALPHA_CMP] != 0)
		{
		  casePx.x = cursor.x * rationMapPix.x - (camPos.x * cam.getZoom());
      casePx.y = cursor.y * rationMapPix.y - (camPos.y * cam.getZoom());
      px.rectangle(casePx, rectSize, color.full, color.full);
		}
	  /*    if(casePx.x >= caseStart.x + rationMapPix.x)
		{
		  casePx.x = cursor.x * rationMapPix.x - (camPos.x * cam.getZoom());
		  casePx.y += rectSize.y;
		}
	      else
		casePx.x += rectSize.x;
	    }*/
	  if(cursor.x >= limit.x)
	    {
	      cursor.x = (camPos.x* cam.getZoom()) / rationMapPix.x;
	      cursor.y ++;
	    }
	  else
	    cursor.x ++;
      	}
      /*for(int i = 0; i < totalpx; i++)
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
	    }*/
    }
  if (px.recVec.length > 0)
    bunny_set_geometry(&px.GetClip()->buffer, BGY_QUADS, (t_bunny_vertex_array *)&px.recVec, NULL);
  px.recVec.length = 0;
  // display minimap
  pxSize.x = pxSize.x * 0.3;
  pxSize.y = pxSize.y * 0.3;
  rationMapPix.x = (pxSize.x) / (double)map.getMapSize().x;
  rationMapPix.y = (pxSize.y) / (double)map.getMapSize().y;
  int decal = pxSize.y * 2.35;
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
	      tmp.y = i / pxSize.x + (decal);
	      px.placePixel(tmp, color.full);
	      break;
	    case 1:
	      color.argb[RED_CMP] = 0;
	      color.argb[GREEN_CMP] = 100;
	      color.argb[BLUE_CMP] = 0;
	      color.argb[ALPHA_CMP] = 255;
	      tmp.x = i % (int)pxSize.x;
	      tmp.y = i / pxSize.x + (decal);
	      px.placePixel(tmp, color.full);
	      break;
	    case 2:
	      color.argb[RED_CMP] = 0;
	      color.argb[GREEN_CMP] = 180;
	      color.argb[BLUE_CMP] = 0;
	      color.argb[ALPHA_CMP] = 255;
	      tmp.x = i % (int)pxSize.x;
	      tmp.y = i / pxSize.x + (decal);
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
	  tmp.y = i / pxSize.x + (decal);
	  px.placePixel(tmp, color.full);
	}
      if (px.pixVec.length > 12000)
	{
	  bunny_set_geometry(&px.GetClip()->buffer, BGY_PIXELS, (t_bunny_vertex_array *)&px.pixVec, NULL);
	  px.pixVec.length = 0;
	}
    }
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
  if (px.pixVec.length > 0)
    bunny_set_geometry(&px.GetClip()->buffer, BGY_PIXELS, (t_bunny_vertex_array *)&px.pixVec, NULL);
  px.pixVec.length = 0;
  if (px.lineVec.length > 0)
    bunny_set_geometry(&px.GetClip()->buffer, BGY_LINES, (t_bunny_vertex_array *)&px.lineVec, NULL);
  px.lineVec.length = 0;
  int stop = clock();
  std::cout << "display in playerinfo time passed : " << (double)(stop - startTime) / CLOCKS_PER_SEC << std::endl;
}
