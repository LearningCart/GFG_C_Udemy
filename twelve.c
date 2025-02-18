#include<stdio.h>
#include <string.h>

// Note: Change to 5 and see what happens to extra inputs.,
#define INPUT_STRING_SIZE   (100)
void testcase3(void)
{
    double d;

    d = 12.184758292781271;
    printf("d = %e\n",d);
}
void testcase2(void)
{
    unsigned a; // By default its integer
    printf("Size of unsigned a = %d\n",sizeof(a));
}

void testcase1(void)
{
    char name[INPUT_STRING_SIZE];

    memset(name, 0, INPUT_STRING_SIZE);

    printf("What is your name?\n");
    fgets(name, INPUT_STRING_SIZE, stdin);
    fprintf(stderr, "Hello %s\n",name);

}
int main(int argc, char *argv[])
{
    testcase3();
    return 0;
}
