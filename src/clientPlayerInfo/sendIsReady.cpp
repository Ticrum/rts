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
      PacketReady pack;
      pack.type = ISREADY;
      pack.datalen = sizeof(PacketReady);
      pack.isReady = true;
      clientUdp->sendData((char *)&pack, pack.datalen, serverConnected);
    }
}

