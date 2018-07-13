#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/un.h>
int main(int argc, char **argv)
{
	int sockid;
	fd_set rfds;
	char buf[100];
	char buf1[100];
	int pid;
	int a;
	int fd;
	struct sockaddr_in addr;
	socklen_t ret;
	ret = sizeof(struct sockaddr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[1]));
	addr.sin_addr.s_addr = inet_addr("127.0.0.1") ;
	sockid = socket(AF_INET,SOCK_STREAM,6);
	if(sockid == -1)
		perror("failed to create a session:\n");
	if(-1 == connect(sockid,(struct sockaddr *)&addr,ret))
		perror("failed in connect :");
    FD_ZERO(&rfds);
	while(1){
    	FD_SET(0,&rfds);
    	FD_SET(sockid,&rfds);
    fd = select(8,&rfds,NULL,NULL,NULL);
    if(FD_ISSET(0,&rfds )){
		
        if(NULL == fgets(buf1,100,stdin))
            printf("failed in fgets:\n");
        if(-1 == write(sockid,buf1,100))
            perror("failed in write:\n");
    }
    if(FD_ISSET(sockid,&rfds)){
//	printf("Client is waiting for server reply\n");
  	if(0 ==  read(sockid,buf,100)){
//		printf("%s",buf);
		close(sockid);
//		if(strcmp(buff,"exit"){

		
		printf("*******connection terminated*********\n");
//		break;
		exit(0);
		}

	
    printf("received information from client : %s\n",buf);
    }
  }
// continue aaa :  

}
