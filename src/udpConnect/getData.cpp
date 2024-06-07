// EFRITS
// project:     rts
// created on:  2024-02-06 - 17:30 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getData implementation

#include "udpConnect.hh"

int ef::UdpConnect::getData(char *data,
                            int len)
{
  if (buffer.size() > 0)
    {
      memcpy(data, buffer[0].get(), len);
      sockGet = sockBuffer[0];
      int result = resultBuffer[0];
      popBuffer(false);
      return result;
    }
  if (fd[0].revents & POLLIN)
    {
      int result = recvfrom(fd[0].fd, data, len, 0, (struct sockaddr *)&sockGet, (socklen_t *)&s);
      if (result == 0)
	return -1;
      return result;
    }
  return -1;
}

