#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#define SHARED_MEM_NAME ("/SharedBuf")
#define SHARED_MEM_SIZE (4096U)
#define SHARED_MEM_PRIVILEGE (0666U)

int main(void)
{
    int FileDesc = -1;
    int Err = 1;
    void *MappedMem = NULL;

    FileDesc = shm_open(SHARED_MEM_NAME, O_CREAT | O_RDWR, SHARED_MEM_PRIVILEGE);
    if (-1 == FileDesc)
    {
        printf("Can NOT create shared memory\n");
        return 1;
    }

    Err = ftruncate(FileDesc, SHARED_MEM_SIZE);
    if (-1 == Err)
    {
        printf("Can NOT set size for the shared memory\n");
        return 1;
    }

    MappedMem = mmap(NULL, SHARED_MEM_SIZE, PROT_WRITE, MAP_SHARED, FileDesc, 0U);
    if (MAP_FAILED == MappedMem)
    {
        printf("Can NOT map shared memory\n");
        return 1;
    }

    Err = sprintf((char *)MappedMem, "Musa Mahmoud\n");
    if (Err > -1)
    {
        printf("Writing done successfully\n");
    }
    else
    {
        printf("Writing failed\n");
    }

    getchar();

    Err = munmap(NULL, SHARED_MEM_SIZE);
    if (-1 == Err)
    {
        printf("Can NOT unmap shared memory\n");
        return 1;
    }

    Err = close(FileDesc);
    if (-1 == Err)
    {
        printf("Can NOT close file descriptor\n");
        return 1;
    }

    return 0;
}
