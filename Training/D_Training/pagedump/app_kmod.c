#include <stdio.h>
#include <fcntl.h>

int main( void )
{

    int fd;
    int pid;
    int var = 20;

	printf("var : %p\ncontents : %d\n",&var,var);
    fd = open("/dev/myChar",O_RDWR);

	 ioctl(fd,NULL,&var);   
 
    if(fd < 0)
        perror("Unable to open the device\n");
    else
        printf("File opened successfully %d\n", fd);

	printf("var : %p\ncontents : %d\n",&var,var);
	//printf("pid : %d\n",getpid());
	//getchar();
    close(fd);

    return 0;

}
