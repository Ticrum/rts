// EFRITS
// project:     rts
// created on:  2024-02-07 - 10:46 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: tcpConnect implementation

#include "tcpConnect.hh"

ef::TcpConnect::TcpConnect(int port)
  :
  s(sizeof(struct sockaddr))
{
  pollfd tempfd;

  tempfd.fd = socket(AF_INET, SOCK_STREAM, 0);
  if (tempfd.fd == -1)
    perror("socket");
  tempfd.events = POLLOUT | POLLIN;
  fds.push_back(tempfd);
  mySock.sin_family = AF_INET;
  mySock.sin_port = (in_port_t)htons(port);
  mySock.sin_addr = (struct in_addr)INADDR_ANY;
  int temp = 1;
  setsockopt(fds[0].fd, SOL_SOCKET, SO_REUSEADDR, &temp, 1);
  if (bind(fds[0].fd, (struct sockaddr *)&mySock, (socklen_t)s) == -1)
    perror("bind");
  if (listen(fds[0].fd, 1024) == -1)
    perror("listen");
}

ef::TcpConnect::~TcpConnect()
{
  for (int i = 0; i < (int)fds.size(); i += 1)
    close(fds[i].fd);
}

