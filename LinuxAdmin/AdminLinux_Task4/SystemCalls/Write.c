#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define BUF_SIZE  (1024UL)

int Prints(int FileDescriptor, const char *const String);
int Printf(int FileDescriptor, const char *const Format, ...);

int main(void)
{
    int Size = 0U;
    static char Buff[50];
    Size = Prints(1, "Write SysCall\n");
    sprintf(Buff, "The size of printed string = %d\n", Size);
    Prints(1, Buff);

    Size = Printf(1, "Hello%c world! %s %d %f\n", ',', "intake", 45U, 1.23f);
    Printf(1U, "The size of printed string = %d\n", Size);

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

int Printf(int FileDescriptor, const char *const Format, ...)
{
    static unsigned char Buf[BUF_SIZE];
    int WroteSize = 0U, Size = 0U, Idx = 0U, BufIdx = 0U;
    va_list Args;

    va_start(Args, Format);

    if (NULL == Format)
    {
        return -1;
    }

    while ((Format[Idx] != '\0') && (Idx < BUF_SIZE))
    {
        if (('%' == Format[Idx]) && ('\0' != Format[Idx + 1U]))
        {
            switch (Format[Idx + 1U])
            {
            case 'c':
            {
                char Character = (char)va_arg(Args, int);
                BufIdx += sprintf(&Buf[BufIdx], "%c", Character);
                break;
            }
            case 'i':
            case 'd':
            {
                int Integer = va_arg(Args, int);
                BufIdx += sprintf(&Buf[BufIdx], "%i", Integer);
                break;
            }
            case 'u':
            {
                unsigned int UInteger = va_arg(Args, unsigned int);
                BufIdx += sprintf(&Buf[BufIdx], "%u", UInteger);
                break;
            }
            case 'f':
            {
                float Float = (double)va_arg(Args, double);
                BufIdx += sprintf(&Buf[BufIdx], "%f", Float);
                
                break;
            }
            case 's':
            {
                char * String = va_arg(Args, char *);
                BufIdx += sprintf(&Buf[BufIdx], "%s", String);
                break;
            }
            }
            Idx += 2;
        }
        else
        {
            Buf[BufIdx] = Format[Idx];
            BufIdx++;
            Idx++;
        }

    }

    Buf[BufIdx] = '\0';
    WroteSize = write(FileDescriptor, Buf, BufIdx);

    va_end(Args);

    return WroteSize;
}
