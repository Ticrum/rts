// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 05/03/2024 12:50:34 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "serverPlayersInfo.hh"
#include "clientPlayerInfo.hh"
#include <iostream>

int main(void)
{
  std::cout << "////start////" << std::endl;
  ef::ServerPlayersInfo srv(30123);
  ef::ClientPlayerInfo cli(32000, 0);
  ef::ClientPlayerInfo cli2(34000, 0);
  //ef::ClientPlayerInfo cli3(58000, 0);
  char i[4];
  i[0] = 127;
  i[1] = 0;
  i[2] = 0;
  i[3] = 1;

  cli.connectToServ(*(int *)&i, 30123);
  cli2.connectToServ(*(int *)&i, 30123);
  //cli3.connectToServ(*(int *)&i, 50123);
  srv.computeActions(0.016);
  cli.computeActions(0.016);
  cli2.computeActions(0.016);
  //cli3.computeActions(0.016);
  cli.sendIsReady();
  cli2.sendIsReady();
  //cli3.sendIsReady();
  srv.computeActions(0.016);
  cli.computeActions(0.016);
  cli2.computeActions(0.016);
  //cli3.computeActions(0.016);
  srv.computeActions(0.016);
  cli.computeActions(0.016);
  cli2.computeActions(0.016);
  //cli3.computeActions(0.016);
  ef::Pos pos;
  pos.x = 0;
  pos.y = 0;
  std::shared_ptr<ef::Building> tempBuild = cli.playerInfo.getBuildingAtPos(pos);
  if (tempBuild.get() != nullptr)
    cli.produce(tempBuild->getId(), "UnitProductor", tempBuild->getType());
  pos.x = 5;
  pos.y = 4;
  cli.placeBuilding(pos);
  srv.computeActions(0.032);
  cli.computeActions(0.032);
  cli2.computeActions(0.032);
  //cli3.computeActions(0.032);
  cli.placeBuilding(pos);
  srv.computeActions(0.032);
  cli.computeActions(0.032);
  cli2.computeActions(0.032);
  //cli3.computeActions(0.032);
  tempBuild = cli.playerInfo.getBuildingAtPos(pos);
  if (tempBuild.get() != nullptr)
    {
      std::cout << "test pB type : " << tempBuild->getType() << std::endl;
      cli.produce(tempBuild->getId(), "misingno", tempBuild->getType());
    }
  for (int i = 0; i < 5; i += 1)
    {
      srv.computeActions(0.016);
      cli.computeActions(0.016);
      cli2.computeActions(0.016);
      //cli3.computeActions(0.016);
    }
  std::cout << "/////////end/////////" << std::endl;
  return 0;
}
