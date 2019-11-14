#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

#define MYPORT 22222
#define BUF_LEN 32

int main () {

int sock, len;
struct sockaddr_in serv;
socklen_t addlen = sizeof(serv);
char buf[BUF_LEN];

sock = socket(PF_INET, SOCK_STREAM, 0);

serv.sin_family = AF_INET;
serv.sin_port = htons(MYPORT);
inet_aton("192.168.1.102",&serv.sin_addr);

connect(sock, (struct sockaddr *) &serv, addlen);

scanf("%s", buf);
len=send(sock, buf, strlen(buf)+1, 0);

}