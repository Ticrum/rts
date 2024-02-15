// EFRITS
// project:     rts
// created on:  2024-02-07 - 16:24 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: tcpConnect & udpConnect testing

//#include <gtest/gtest.h>
#include "tcpConnect.hh"
#include "udpConnect.hh"
#include <cassert>
#include <unistd.h>
/*
TEST(CmpThread, pixelCmp)
{
}
*/
int main(int    nbr,
         char   **inputs)
{
/*
    ef::TcpConnect udp(34512);
    char data[128];
    char i[4];

    i[0] = 127;
    i[1] = 0;
    i[2] = 0;
    i[3] = 1;
    while (1)
    {
  if (udp.loop())
  {
  write(1,"Connection done\n",16);
  }
  //write(1, "paso\n", 5);
  struct sockaddr_in temp = udp.getLastConnected();
  //write(1, "pass\n", 5);
  int lu = udp.getData(data, 128, *(int *)&temp.sin_addr, ntohs(temp.sin_port));
  if (lu != -1 && lu != 0)
  {
  write(1,"Message receve :\n", 17);
  write(1,data,lu);
  udp.sendData("bien recu\n", 10, *(int *)&temp.sin_addr, ntohs(temp.sin_port));
  }
  std::vector<struct sockaddr_in> list = udp.getAllConnected();
  for (int j = 0; j < (int)list.size(); j += 1)
  {
  udp.sendData("ping\n", 5, *(int *)&list[j].sin_addr, ntohs(list[j].sin_port));
  }
            
  // udp
  udp.loop();
  udp.sendData(data, 128, *(int *)i, 54321);
  int lu = udp.getData(data, 128);
  //int lu = -1;
  if (lu != -1)
  {
  write(1,"Message receve :\n", 17);
  write(1,data,lu);
  struct sockaddr_in temp = udp.getSender();
  udp.sendData(data, lu, *(int *)&temp.sin_addr, ntohs(temp.sin_port));
  }
            
  }
        
  testing::InitGoogleTest(&nbr, inputs);
  return RUN_ALL_TESTS();
*/
    return 0;
}
