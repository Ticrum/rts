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
  //t_bunny_window *win = bunny_start(1000, 1000, false, "test");
  ef::Camera cam(1000, 1000);
  cam.Init("test");
  cam.ZoomIn(1);
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
  cam.display(cli.playerInfo);
  cli2.computeActions(0.016);
  //cli3.computeActions(0.016);
  
  cli.sendIsReady();
  cli2.sendIsReady();
  //cli3.sendIsReady();
  srv.computeActions(0.016);
  cli.computeActions(0.016);
  cam.display(cli.playerInfo);
  cli2.computeActions(0.016);
  
  //cli3.computeActions(0.016);
  srv.computeActions(0.016);
  cli.computeActions(0.016);
  cam.display(cli.playerInfo);
  cli2.computeActions(0.016);
  //cli3.computeActions(0.016);
  
  ef::Pos pos;
  pos.x = 5;
  pos.y = 5;
  std::shared_ptr<ef::Building> tempBuild = cli.playerInfo.getBuildingAtPos(pos);
  if (tempBuild.get() != nullptr)
    cli.produce(tempBuild->getId(), "UnitProductor", tempBuild->getType());
  pos.x = 7;
  pos.y = 8;
  cli.placeBuilding(pos);
  srv.computeActions(0.016);
  cli.computeActions(0.016);
  cam.display(cli.playerInfo);
  cli2.computeActions(0.016);
  srv.computeActions(0.064);
  cli.computeActions(0.064);
  cam.display(cli.playerInfo);
  cli2.computeActions(0.064);
  //cli3.computeActions(0.032);
  cli.placeBuilding(pos);
  srv.computeActions(0.032);
  cli.computeActions(0.032);
  cam.display(cli.playerInfo);
  cli2.computeActions(0.032);
  //cli3.computeActions(0.032);
  
  tempBuild = cli.playerInfo.getBuildingAtPos(pos);
  if (tempBuild.get() != nullptr)
    {
      std::cout << "test pB type : " << tempBuild->getType() << std::endl;
      cli.produce(tempBuild->getId(), "missingno", tempBuild->getType());
    }
  srv.computeActions(0.048);
  cli.computeActions(0.048);
  cam.display(cli.playerInfo);
  cli2.computeActions(0.048);
  
  srv.computeActions(0.048);
  cli.computeActions(0.048);
  cam.display(cli.playerInfo);
  cli2.computeActions(0.048);
  pos.x += 1;
  std::shared_ptr<ef::Unit> tempUnit = cli.playerInfo.getUnitAtPos(pos);
  if (tempUnit.get() != nullptr)
    {
      std::cout << "yes get unit in test" << std::endl;
      ef::Pos posi[2];
      posi[0].x = 0;
      posi[0].y = 0;
      posi[1].x = 30;
      posi[1].y = 30;
      cli.select(posi[0], posi[1]);
      posi[1].x = 24;
      posi[1].y = 5;
      cli.makePath(posi[1], ef::WALK);
    }
  for (int i = 0; i < 100; i += 1)
    {
      srv.computeActions(0.016);
      cli.computeActions(0.016);
      cam.ZoomIn(0.05);
      ef::AcuPos posi;
      posi.x = 10;
      posi.y = 0;
      cam.Move(posi);
      cam.display(cli.playerInfo);
      cli2.computeActions(0.016);
      //cli3.computeActions(0.016);
      sleep(1);
    }
  std::cout << "/////////end/////////" << std::endl;
  return 0;
}
