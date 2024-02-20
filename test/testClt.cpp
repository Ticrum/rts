#include "tcpConnect.hh"
#include "udpConnect.hh"

int main(void)
{
    /*
    ef::TcpConnect tcp(54321);
    char data[128];
    char i[4];

    i[0] = 127;
    i[1] = 0;
    i[2] = 0;
    i[3] = 1;
    //tcp.connectClient(*(int *)i, 12345);
    //tcp.sendData("test", 4, *(int *)i, 12345);
    tcp.loop();
    sleep(1);
    tcp.connectClient(*(int *)i, 34512);
    while (1)
        {
            tcp.loop();
            tcp.sendData("test\n", 5, *(int *)i, 34512);
            printf("pass\n");
            int lu = tcp.getData(data, 128, *(int *)&i, 34512);
            if (lu != -1 && lu != 0)
            {
                write(1,"Message lu :\n", 13);
                write(1,data,lu);
            }
            
              // udp
            tcp.loop();
            tcp.sendData("test\n", 5, *(int *)i, 12345);
            //printf("clientLoop\n");
            
            sleep(1);
        }
*/
}
