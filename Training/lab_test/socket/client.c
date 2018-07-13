#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#define MAX 256
int main(void)
{
	int sfd;
	struct sockaddr_in addr;
	struct in_addr sin_addr;

	sfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sfd == -1)
		perror("socket failed\n");
//	bzero(sfd,sizeof(struct sockaddr_in))
	memset(&addr, 0, sizeof(struct sockaddr_in));
	(addr).sin_family = AF_INET;
	(addr).sin_port = htons(80);
//	(addr).sin_addr.s_addr = INADDR_ANY;

	if( -1 == (connect(sfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)))){
		perror("connection failed\n");
	}
	
	char *buf = NULL;
	if(NULL == (buf = (char *)malloc(sizeof(char) * MAX))){
		perror("malloc failed\\\n");
		exit(EXIT_FAILURE);
	}

	fgets(buf,MAX,stdin);

	if(-1 == (write(sfd,buf,MAX))){
		perror("write failedn");
		exit(EXIT_FAILURE);
	}

	if(-1 == (read(sfd,buf,MAX))){
		perror("read failure");
		exit(EXIT_FAILURE);
	}
	printf("%s",buf);
	close(sfd);	
	free(buf);
	return 0;
}
