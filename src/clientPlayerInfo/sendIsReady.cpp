// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 06/03/2024 11:06:20 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "clientPlayerInfo.hh"

void ef::ClientPlayerInfo::sendIsReady()
{
  if (isConnected)
    {
      Packet pack;
      pack.type = ISREADY;
      pack.ready.isReady = true;
      clientUdp->sendData((char *)&pack, sizeof(Packet), serverConnected);
    }
}

