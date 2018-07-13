//Server process
#include <sys/types.h>
#include <sys/socket.h>
#include <error.h>
#include <stdlib.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>

#define HUN 100
int main(int argc,char *argv[])
{
	int soc_des;	
	int done = 1;
	//Socket is created
	if((soc_des = socket(AF_INET,SOCK_STREAM,0)) == -1)
	{
		perror("1.");
		exit(EXIT_FAILURE);
	}
	printf("Socket is created\n");

	//Bind
	struct sockaddr_in sock;
	
	memset(&sock, 0, sizeof(struct sockaddr_in));
	sock.sin_family = AF_INET;
	sock.sin_port = atoi(argv[1]);
	sock.sin_addr.s_addr = INADDR_ANY;

	if(-1 == (bind(soc_des,(struct sockaddr *)&sock, sizeof(sock))))
	{
		perror("2.");
		exit(EXIT_FAILURE);
	}
	
	//Listen
	if(listen(soc_des,2) == -1)
	{
		perror("3.");
		exit(EXIT_FAILURE);
	}

	int pid;
	
	pid = vfork();
	
	if(pid == 0)
	{
	//Accept
	int sd;
	struct sockaddr_in peer;
	int var = sizeof(peer);	
	
	memset(&peer, 0, sizeof(struct sockaddr_in));
	if((sd = accept(soc_des,(struct sockaddr *) &peer,(socklen_t *) &var)) < 0)
	{
		perror("4.");
		exit(EXIT_FAILURE);
	}
	printf("Connection accepted\n");

	//Read
	char buf[HUN];
	char buf1[HUN];

	while(1)
	{
	if(read(sd,buf,HUN) < 0)
	{
		perror("5.");
	}

	printf("-------------CLIENT SENT--------------------\n");
	printf("\t\t%s\n",buf);
	
	printf("Enter the message:");
	scanf("%s",buf1);

	if(write(sd,buf1,HUN) < 0)
	{
		perror("6.");
	}
//	printf("Do you want to quit(yes-0 : no-1 ):");
//	scanf("%d",&done);
	}
	if(close(sd))
	{
		perror("6.");
		exit(EXIT_FAILURE);
	}
	exit(0);
	}
	else if(pid > 0)
	{
	//Accept
        int sd;
        struct sockaddr_in peer;
        int var = sizeof(peer);

        memset(&peer, 0, sizeof(struct sockaddr_in));
        if((sd = accept(soc_des,(struct sockaddr *) &peer,(socklen_t *) &var)) < 0)
        {
                perror("4.");
                exit(EXIT_FAILURE);
        }
        printf("Connection accepted\n");

        //Read
        char buf[HUN];
        char buf1[HUN];

        while(1)
        {
        if(read(sd,buf,HUN) < 0)
        {
                perror("5.");
        }

        printf("-------------CLIENT SENT--------------------\n");
        printf("\t\t%s\n",buf);

        printf("Enter the message:");
        scanf("%s",buf1);

        if(write(sd,buf1,HUN) < 0)
        {
	perror("6.");
        }
       // printf("Do you want to quit(yes-0 : no-1 ):");
       // scanf("%d",&done);
        }
     /*   if(close(sd))
        {
                perror("6.");
                exit(EXIT_FAILURE);
        }*/
//		wait(NULL);
        }
	else
	{
	perror("");
	exit(EXIT_FAILURE);
	}
	printf("DONE WITH SERVER\n");

}

