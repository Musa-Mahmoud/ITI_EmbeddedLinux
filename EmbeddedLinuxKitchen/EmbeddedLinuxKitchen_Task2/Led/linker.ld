
ENTRY(_start)

SECTIONS
{
    . = 0x80000;
    .text :
    {
        *(.startup*)
        *(.text*)
        *(.rotext*)
    }

    .data :
    {
        *(.data*)
    }

    .bss : 
    {
        *(.bss*)
        *(COMMON)
    }
}
