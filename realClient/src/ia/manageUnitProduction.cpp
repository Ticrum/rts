// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 12:21:01 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "ia.hh"

void ef::Ia::manageUnitProduction()
{
  if (unitToProd > 0)
    {
      std::vector<std::shared_ptr<Building>> & tempBuilds = cli.playerInfo.getBuild();
      for (int i = 0; i < (int)tempBuilds.size(); i += 1)
	if (tempBuilds[i]->getConf() == "UnitProductor")
	  {
	    cli.select(size, tempBuilds[i]->getPos(), tempBuilds[i]->getPos(), singleCommand, true);
	    break;
	  }
      if (cli.playerInfo.getIntMoney() > 100 * nbrProd)
	{
	  singleCommand("produce baseSoldier");
	  unitToProd -= 1;
	}
    }
}

