#include <stdio.h>

int main(int argc, char *argv[])
{
    float a;
    double b;
    a = 0.2;
    a = a * 1.68;
    b = 0.2;
    b = b * 1.68;
    printf("%f and %f are %s\n", a, b,  (a == b) ? "equal" : "not equal");
    printf("a = 0x%08X\nb = 0x%08X\n", a, b);
    return 0;
}