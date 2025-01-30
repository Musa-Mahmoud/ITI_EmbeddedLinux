
void main(void);

__attribute__((naked, section(".startup"))) 
void _start()
{
    main();
}
