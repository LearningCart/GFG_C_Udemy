#include <stdio.h>
#include <stdbool.h>

int listitems[100];

int main(int argc, char *argv[])
{
    bool b;
    
    printf("b %2u \n", sizeof(b));
    printf("b %2u \n", sizeof(bool));
    printf("c %2u \n", sizeof(char));
    printf("uc %2u \n", sizeof(unsigned char));
    printf("s %2u \n", sizeof(short));
    printf("us %2u \n", sizeof(unsigned short));
    printf("u %2u \n", sizeof(unsigned));
    printf("i %2u \n", sizeof(int));
    printf("ui %2u \n", sizeof(unsigned int));
    printf("l %2u \n", sizeof(long));
    printf("ll %2u \n", sizeof(long long));
    printf("ull %2u \n", sizeof(unsigned long long));
    printf("f %2u \n", sizeof(float));
    printf("dbl %2u \n", sizeof(double));

    int x, y;
    double z;
    x = 10;
    y = 11;
    z = 12.02;

    printf("e %2u \n", sizeof((x + y) * (z)));

    printf("X Before: %d\n", x);
    printf("size of i++ = %2u\n", sizeof(x++)); // return type is evaluated compile time and statement is not 'executed' run time. 
    printf("X After: %d\n", x);

    printf("Size of array (total bytes): %d\n", sizeof(listitems));
    printf("Size of array /size of first element = %d\n", sizeof(listitems)/sizeof(listitems[0]));

    return 0;
}
