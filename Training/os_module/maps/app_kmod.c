#include <stdio.h>
#include <fcntl.h>

int main( void )
{

    int fd;
    
    fd = open("/dev/myChar",O_RDWR);

    ioctl( fd, NULL, NULL );   
 
    if(fd < 0)
        perror("Unable to open the device\n");
    else
        printf("File opened successfully %d\n", fd);

    close(fd);

    return 0;

}
