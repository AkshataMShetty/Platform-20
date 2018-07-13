/*client program - using socket programing*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#define MAX 256

int main(int argc,char *argv[])
{
	int sock_fd;
	uint16_t port_no = atoi(argv[1]);
	//to get socket session descriptor
	if((sock_fd = socket(AF_INET,SOCK_STREAM,0)) == -1){
		perror("soket descriptor not given\n");
		exit(1);
	}
	
	struct sockaddr_in addr;
	bzero(&addr,sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port_no);
	addr.sin_addr.s_addr = inet_addr("172.16.10.78");

	//to initiate communication with server	
	if((-1 == connect(sock_fd,(const struct sockaddr *)&addr,(socklen_t)sizeof(struct sockaddr)))){
		perror("connection failed\n");
		exit(1);
	}
 
	char *buf = NULL;
	if(NULL == (buf = malloc(sizeof(char) * MAX))){
   	  	perror("malloc failed");
      	exit(1);
  	}
//	int status = 3;
	while(1){
	 
	fgets(buf,MAX,stdin);
	write(sock_fd, buf, MAX);
//	memset(buf,0,MAX);
	read(sock_fd,buf,MAX);
   printf("%s",buf);
//	status--;
	}
	close(sock_fd);

	return 0;
}
	
	
