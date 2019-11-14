#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

#define MYPORT 22222
#define BUF_LEN 32

int main() {

int so, sd, len;
struct sockaddr_in loc, rem;
socklen_t addlen = sizeof(loc);
char buf[BUF_LEN];

so = socket(PF_INET, SOCK_STREAM, 0);

loc.sin_family = AF_INET;
loc.sin_port = htons(MYPORT);
inet_aton("192.168.1.102",&loc.sin_addr);

bind(so, (struct sockaddr *) &loc, addlen);

listen(so, 10);
sd=accept(so, (struct sockaddr *) &rem, &addlen);
len=recv(sd, buf, BUF_LEN, 0);

printf("%s\n",buf);

}