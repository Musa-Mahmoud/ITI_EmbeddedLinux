#include <stdio.h>
#include <unistd.h>

int Prints(int FileDescriptor, const char *const String);

int main(void)
{
    static char Buf[50];
    int Size = Prints(1, "Write SysCall\n");

    sprintf(Buf, "The size of printed string = %d\n", Size);
    Prints(1, Buf);

    return 0;
}

int Prints(int FileDescriptor, const char *const String)
{
    int WroteSize = 0, Size = 0, Idx = 0;

    if (NULL == String)
    {
        return -1;
    }

    while (String[Idx] != '\0')
    {
        Size++;
        Idx++;
    }

    WroteSize = write(FileDescriptor, String, Size);

    return WroteSize;
}
