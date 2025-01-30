
#define GPIO_GPFSELn_BASE_ADDR ((volatile unsigned int *)(0x3F200000))
#define GPIO_GPSETn_BASE_ADDR ((volatile unsigned int *)(0x3F20001C))

void main(void)
{
    volatile unsigned int *ptr = (volatile unsigned int *)GPIO_GPFSELn_BASE_ADDR;

    ptr += 2;
    *ptr |= ((unsigned int)1 << 18);

    ptr = GPIO_GPSETn_BASE_ADDR;

    *ptr |= ((unsigned int)1 << 26);

    while (1);
}
