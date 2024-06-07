// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 06/06/2024 18:08:45 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "udpConnect.hh"

#include <iostream>

void ef::UdpConnect::stockData(double timeToPass,
			       int len)
{
  struct sockaddr_in tempSock;
  while (timeToPass > 0)
    {
      //std::cout << "stockData udpconnect time to pass" << std::endl;
      int startTime = clock();
      loop();
      std::shared_ptr<char> tempChar;
      tempChar.reset(new char[len]);
      buffer.push_back(tempChar);
      sockBuffer.push_back(tempSock);
      resultBuffer.push_back(0);
      int result = 0;
      if (fd[0].revents & POLLIN)
        result = recvfrom(fd[0].fd, buffer[buffer.size() - 1].get(), len, 0, (struct sockaddr *)&sockBuffer[sockBuffer.size() - 1], (socklen_t *)&s);
      if (result == 0)
	popBuffer(true);
      else
	{
	  std::cout << "stockData udpconnect receve message" << std::endl;
	  resultBuffer[resultBuffer.size() - 1] = result;
	}
      int stop = clock();
      timeToPass -= (double)(stop - startTime) / CLOCKS_PER_SEC;
    }
}

