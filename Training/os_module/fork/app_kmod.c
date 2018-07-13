#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int a = 30;

int main( void )
{

    int fd;
	    
    pid_t pid ;

    fd = open("/dev/myChar",O_RDWR);

   if(fd < 0)
        perror("Unable to open the device\n");
    else
      {
	 pid = fork();

        if( pid == 0)
        {
                printf(" Inside child \n");
                ioctl( fd, &a, NULL);
                printf(" Leaving child process\n");
        }
        else if( pid > 0)
        {	
		
                printf(" Inside Parent process\n");
                ioctl( fd, &a, NULL);
//		wait(NULL);
                printf(" Leaving Parent process\n");
		
        }
        else
        {
                printf(" Fork error\n");
                exit(0);
        }


	}
    close(fd);
	
    return 0;

}
