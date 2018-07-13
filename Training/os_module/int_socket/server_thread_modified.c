#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/un.h>
#include<pthread.h>
#include<stdlib.h>
int arr[10];
pthread_t thid;
char buf[100];
char buf1[100];
char buf2[100];
int sockid,nfd,sok;
int temp1;
int temp;
int status;
//int rfds;
fd_set rfds;
fd_set wfds;
int fd;
int i = 0;
int j = 0;
int k = 0;
int s = 0;
struct sockaddr_in addr;
socklen_t ret;
int main(int argc, char **argv)
{
	nfd = 3;
	ret = sizeof(struct sockaddr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[1]));
	addr.sin_addr.s_addr = inet_addr("127.0.0.1") ;
	if(	(sockid = socket(AF_INET, SOCK_STREAM, 6)) == -1)
		perror("socket failed");
	if(-1 == bind(sockid, (struct sockaddr *)&addr, ret))
		perror("bind fail:\n");
	if(-1 == listen(sockid, 100))
		perror("listen fail");
	
	FD_ZERO(&rfds);

	FD_SET(sockid,&rfds);
	
	FD_SET(0,&rfds);
	while(1){
		
        for(j = 0; j<i ; j++){
			FD_SET(0,&rfds);
			FD_SET(sockid,&rfds);
			FD_SET(arr[j],&rfds);
			}
		select(8, &rfds, NULL, NULL, NULL);
/*
		struct timeval timeout;
                timeout.tv_sec = 10;
                timeout.tv_usec = 0;


                if (setsockopt (nfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0)
                        error("setsockopt failed\n");
*/		
		if(FD_ISSET(sockid,&rfds)){
			printf("s = %d\n",s);
       	 	nfd = accept(sockid,(struct sockaddr *) &addr,&ret);
        	printf("new client joined:%d\n",nfd);
        	arr[i] = nfd;
        	i++;
        	printf("the following clients are waiting for the service choose one:\n");
        	for(j = 0; j<i ; j++){
            	printf("client no : %d\n",arr[j]);
       			}
			}



/*
                struct timeval timeout;      
                timeout.tv_sec = 10;
                timeout.tv_usec = 0;
*/
//                if (setsockopt (nfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,sizeof(timeout)) < 0)
  //                      error("setsockopt failed\n");

                //if (setsockopt (sockid, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout,sizeof(timeout)) < 0)
                  //      error("setsockopt failed\n");




		
			if(FD_ISSET(0, &rfds )){
			__fpurge(stdin);
			if(NULL == fgets(buf1, 100, stdin))
					printf("failed in fgets:\n");
			sscanf(buf1, "%d %[^\n]", &temp1, buf2);
			if(-1 == write(temp1,buf2,100))
				perror("failed in write:\n");
		}
	



	for(k = 4; k < 10; k++){
		if(FD_ISSET(k, &rfds)){
   			if(0 == read(k, buf, 100)){
			//	read(k,buf,100);
			//	if(strcmp(buf,"exit")){

				close(k);
				printf("********connection terminate*********\n");
				//exit(0);
			}
			
			
			printf("received information from client : %s\n",buf);
			}
			}
}
	close(sockid);
}
