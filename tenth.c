#include<stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *ch = "Hello World\n";
    for(; ch != NULL && *ch != '\n'; ch++  )
    {
        putchar(*ch);
        sleep(1);
    }

    printf("Value of x is %d\n"); // Don't provide argument., prints garbage., 
    return 0;
}