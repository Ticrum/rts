// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/06/2024 11:33:58 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "udpConnect.hh"

void ef::UdpConnect::popBuffer(bool isBack)
{
  if (isBack)
    {
      buffer.pop_back();
      sockBuffer.pop_back();
      resultBuffer.pop_back();
    }
  else
    {
      for (int i = 0; i < (int)buffer.size() - 1; i += 1)
	buffer[i] = buffer[i + 1];
      buffer.pop_back();
      for (int i = 0; i < (int)sockBuffer.size() - 1; i += 1)
	sockBuffer[i] = sockBuffer[i + 1];
      sockBuffer.pop_back();
      for (int i = 0; i < (int)resultBuffer.size() - 1; i += 1)
	resultBuffer[i] = resultBuffer[i + 1];
      resultBuffer.pop_back();
    }
}

