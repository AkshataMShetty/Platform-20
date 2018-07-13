#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#define MAX 256

int main(int argc, char **argv)
{
	int client_id[2], server_id;
	int fdmax;
	struct sockaddr_in server, client;
	fd_set readfd;
	int client_no;
	int ret;
	char buf[MAX];
	uint16_t port_no = atoi(argv[1]);
	int i = 0;

	socklen_t len = sizeof(struct sockaddr_in);

	server_id = socket(AF_INET, SOCK_STREAM, 0);
	if(server_id == -1)
	{
		perror("connection failed\n");
		exit(EXIT_FAILURE);
	}

	memset(&server, 0 , sizeof(struct sockaddr_in));
	server.sin_family = AF_INET;
	server.sin_port = htons(port_no);
	server.sin_addr.s_addr = INADDR_ANY;

	if((bind(server_id, (struct sockaddr*)&server, sizeof(struct sockaddr_in))) == -1){
		perror("bind failed\n");
		exit(EXIT_FAILURE);
	}
	listen(server_id,4);
	
	printf("waiting for connection\n");
	
	FD_ZERO(&readfd);
	fdmax = server_id;
	while(1){
		FD_SET(server_id, &readfd);
		printf("fdmax = %d\n",fdmax);
		if(select(fdmax+1, &readfd, NULL, NULL, NULL) < 0)
		{
			perror("select\n");
			exit(EXIT_FAILURE);
		}

		if(FD_ISSET(server_id, &readfd))
		{
			if((client_id[i] = accept(server_id, (struct sockaddr *)&client,&len)) == -1)
			{
				perror("accept failed");
				exit(EXIT_FAILURE);
			}
			printf("new client %d connected \n",client_id[i]);
			FD_SET(client_id[i],&readfd);
			fdmax = client_id[i];
			i++;
			
		}
		else
		{	
			for(client_no = server_id + 1; client_no <= fdmax ; client_no++)
			{
				if(FD_ISSET(client_no, &readfd))
				{
					ret = recv(client_no, buf, MAX, 0);
					if(ret == 0){
						printf("client %d disconnected\n",client_no);
						FD_CLR(client_no, &readfd);
						close(client_no);
						FD_SET(client_id[--i], &readfd);
						break;
					}
					else{
						printf("received from client %d is %s\n",client_no, buf);
					}
				}
			}
	
		}	
	}
	close(client_id);
	close(server_id);
	return 0;
}
