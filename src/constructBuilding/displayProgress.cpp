// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 13/05/2024 11:47:04 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "building.hh"
#include "Bpixelarray.hh"

#include <iostream>

void ef::ConstructBuilding::displayProgress(ef::Bpixelarray &px,
					    ef::AcuPos caseSize,
					    ef::AcuPos camStart,
					    double zoom)
{
  Pos tmp;

  if (buildingProd.size() > 0)
    {
      tmp.x = ((double)pos.x) * caseSize.x;
      tmp.y = ((double)pos.y) * caseSize.y;
      tmp.y -= camStart.y * zoom;
      tmp.x -= camStart.x * zoom;

      AcuPos size = caseSize;

      size.x *= objSize.x;

      double tempon = (timeLeft * size.x) / buildingProd[0].timeToProduce;
      //std::cout << "displayProgress in constructbuilding tempon : " << tempon << " timeLeft : " << timeLeft << std::endl;

      size.y = (1 + zoom / 2.0) * objSize.y;

      Pos square;

      square.x = tmp.x;
      square.y = tmp.y - ((objSize.y * caseSize.y) / 4) + size.y;

      Pos max = px.GetSize();
      while(square.y - (tmp.y - ((objSize.y * caseSize.y) / 4) + size.y) < size.y)
	{
	  if(square.x >= 0 && square.x < max.x && square.y >= 0 && square.y < max.y)
	    px.placePixel(square, (square.x - tmp.x < tempon)? BLACK: WHITE);
	  //px.GetSetPixel(square.x, square.y) = (square.x - tmp.x < tempon)? BLACK: WHITE;
	  square.x++;
	  if(size.x <= square.x - tmp.x)
	    {
	      square.y ++;
	      square.x = tmp.x;
	    }
	}
    }
}
