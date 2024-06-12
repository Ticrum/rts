// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 03/06/2024 16:40:05 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "ia.hh"

//#include <iostream>

void ef::Ia::manageBuildProduction()
{
  if (MainBuild.size() == 0)
    return;
  std::vector<std::shared_ptr<Building>> & tempBuildProd = cli.playerInfo.getProducedBuilding();
  if (unitToProd == -1)
    {
      //std::cout << "manageBuildProduction ia energy : " << cli.playerInfo.getIntEnergy() << std::endl;
      if (tempBuildProd.size() == 0)
	cli.select(size, MainBuild[0]->getPos(), MainBuild[0]->getPos(), singleCommand, false);
      if (tempBuildProd.size() == 0 && cli.playerInfo.getIntMoney() > 450 && internalEnergy < 70 && !resourceFilled)
	{
	  singleCommand("produce Reactor");
	  internalEnergy += 100;
	}
      else if (tempBuildProd.size() == 0 && cli.playerInfo.getIntMoney() > 400 && (nbrMoneyP / 1 > nbrProd || resourceFilled))
	{
	  singleCommand("produce UnitProductor");
	  internalEnergy -= 20;
	  nbrProd += 1;
	}
      else if (tempBuildProd.size() == 0 && cli.playerInfo.getIntMoney() > 700 && !resourceFilled)
	{
	  singleCommand("produce moneyProducer");
	  internalEnergy -= 40;
	  nbrMoneyP += 1;
	}
      else if (tempBuildProd.size() > 0)
	{
	  //std::cout << "manageBuildProduction ia " << std::endl;
	  if (!placeBuild())
	    {
	      unitToProd = 20 / nbrProd;
	      resourceFilled = true;
	    }
	}
    }
  if (nbrMoneyP % 5 == 0 && nbrMoneyP != 0 && unitToProd == -1)
    unitToProd = 20 / nbrProd;
}

