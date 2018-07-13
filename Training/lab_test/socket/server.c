#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#define MAX 256
int main(void)
{
	int newfd,cfd;
	struct sockaddr_in my_addr;
	struct in_addr sin_addr;

	cfd = socket(AF_INET, SOCK_STREAM, 0);
	if(cfd == -1)
		perror("socket failed");
//	bzero(my_addr,sizeof(my_addr));
	memset(&my_addr,0,sizeof(struct sockaddr_in));
	(my_addr).sin_family = AF_INET;
	(my_addr).sin_port = htons(80);
//	(my_addr).sin_addr.s_addr = INADDR_ANY;

	if(-1 == (bind(cfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr_in)))){
		perror("binding failed");
	}

	if(-1 == (listen(cfd, 50))){
		perror("listen failed");
	}
	int len = sizeof(struct sockaddr_in);
	newfd = accept(cfd,(struct sockaddr *)&my_addr, &len);
	if (newfd == -1){
		perror("accept failed");
	}

	char *buf = NULL;
	if(NULL == (buf = (char *) malloc(sizeof(char) * MAX))){
		perror("MALLOC failed");
		exit(EXIT_FAILURE);
	}


	if (-1 == (read(newfd,buf,MAX))){
		perror("read failed");
		exit(EXIT_FAILURE);
	}
	printf("%s",buf);

	fgets(buf,MAX,stdin);
	if(-1 == (write(newfd,buf,MAX))){
		perror("write failed");
		exit(EXIT_FAILURE);
	}

	close(newfd);
	close(cfd);
	free(buf);
	return 0;
}
