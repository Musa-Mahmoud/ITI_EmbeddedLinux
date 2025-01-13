#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd = -1;

    if ((argc < 2) || (NULL == argv))
    {
        return 1;
    }

    fd = open("/sys/class/leds/input1::capslock/brightness", O_RDWR);

    if (NULL == argv[1])
    {
        return 1;
    }
    
    if (('1' != argv[1][0]) && ('0' != argv[1][0]))
    {
        return 1;
    }
    
    dprintf(fd, "%c\n", argv[1][0]);

    return 0;
}
