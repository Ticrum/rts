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
  ef::ServerPlayersInfo srv(50123);
  ef::ClientPlayerInfo cli(51000, 0);
  ef::ClientPlayerInfo cli2(52000, 0);
  ef::ClientPlayerInfo cli3(53000, 0);
  char i[4];
  i[0] = 127;
  i[1] = 0;
  i[2] = 0;
  i[3] = 1;

  cli.connectToServ(*(int *)&i, 50123);
  cli2.connectToServ(*(int *)&i, 50123);
  cli3.connectToServ(*(int *)&i, 50123);
  srv.computeActions(0.5);
  cli.computeActions(0.5);
  cli2.computeActions(0.5);
  cli3.computeActions(0.5);
  cli.sendIsReady();
  cli2.sendIsReady();
  cli3.sendIsReady();
  srv.computeActions(0.5);
  cli.computeActions(0.5);
  cli2.computeActions(0.5);
  cli3.computeActions(0.5);
  srv.computeActions(0.5);
  cli.computeActions(0.5);
  cli2.computeActions(0.5);
  cli3.computeActions(0.5);
  cli.produce(0, "LATHOURES.dabsic", ef::CONSTRUCT);
  for (int i = 0; i < 5; i += 1)
    {
      srv.computeActions(0.5);
      cli.computeActions(0.5);
      cli2.computeActions(0.5);
      cli3.computeActions(0.5);
    }
  std::cout << "/////////end/////////" << std::endl;
  return 0;
}
