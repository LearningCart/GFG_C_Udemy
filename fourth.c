#include <stdio.h>

int main (int argc, char *argv[])
{
    volatile float a;

    for (a = 0.1; a < 1; a += 0.1)
    {
        printf("%f binary is 0x%016X\n", a, a);
    }
    printf("------------------------\n");
    for (a = 1.0; a < 10.0; a+=0.5)
    {
        printf("%f binary is 0x%016X\n", a, a);
    }
    return 0;
}
