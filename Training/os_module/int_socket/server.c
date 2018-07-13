#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 2
#define BUF 256

int main(int argc, char *argv[])
{
	int server_fd;
	int max_fd;
	int client_fd[MAX];
	int tempfd;
	int newfd;
	fd_set readfd;
	int index;
	unsigned int port ; 
	char *buf = NULL;

	struct sockaddr_in my_addr;
	socklen_t addrlen = sizeof(struct sockaddr_in);
	
	struct timeval timeout1;
	timeout1.tv_sec = 5;
	
	if(argc != 2){
		printf("invalid command\n");
		exit(1);
	}
	port = atoi(argv[1]);
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_fd == -1){
		printf("socket failed\n");
		exit(1);
	}

	memset(&my_addr, 0, addrlen);

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(port);
	my_addr.sin_addr.s_addr = INADDR_ANY;

	if((bind(server_fd, (struct sockaddr*)&my_addr, sizeof(struct sockaddr_in)))== -1){ 
		printf("bind failed\n");
		exit(1);
	}

	if(listen(server_fd,10)){
		printf("listen failed\n");
		exit(1);
	}
	
	printf("waiting for connection\n");

	if(NULL == (buf = malloc(sizeof(char *)))){
		printf("malloc failed\n");
		exit(1);
	}

	for(index = 0; index < MAX; index++){
		client_fd[index] = 0;
	}

	while(1){
		FD_ZERO(&readfd);

		FD_SET(server_fd,&readfd);

		max_fd = server_fd;

		for(index = 0; index < MAX; index++){
			tempfd = client_fd[index];

			if(tempfd > 0){
				FD_SET(tempfd, &readfd);
			}

			if(tempfd > max_fd){
				max_fd = tempfd;
			}
		}
		
		
//	timeout1.tv_sec = 5;
		if(0 > (select(max_fd+1, &readfd, NULL, NULL, NULL))){
			printf("select failed\n");
			exit(1);
		}
		
		if(FD_ISSET(server_fd, &readfd)){
			newfd = accept(server_fd, (struct sockaddr*)&my_addr, &addrlen);
			if(newfd == -1){
				printf("accept failed\n");
				exit(1);
			}
			printf("client %d connected\n",newfd);

			for(index = 0; index < MAX; index++){

				if(client_fd[index] == 0){
					client_fd[index] = newfd;
					break;
				}
			}

		}

		for(index = 0; index < MAX; index++){
			tempfd = client_fd[index];

			if(FD_ISSET(tempfd, &readfd)){
				if(0 != read(tempfd, buf, BUF)){
					printf("msg received from client - %s\n",buf);
				

					if(NULL == fgets(buf, BUF, stdin)){
						printf("fgets failed\n");
						exit(1);
					}

					if(-1 == write(tempfd, buf, BUF)){
						printf("write failed\n");
						exit(1);
					}
				}
				else{
					printf("connection closed -> %d\n",tempfd);
					FD_CLR(tempfd, &readfd);
					close(tempfd); 
					client_fd[index] = 0;
				}
			}
		}
	}
	close(server_fd);
	return 0;
}
