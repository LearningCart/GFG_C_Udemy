#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int x, y;
    char name[255];
    printf("Please enter first number: ");
    scanf("%d",&x); // OH scanf("%d\n",&x);
    printf("Please enter second number: ");
    scanf("%d",&y);
    printf("Sum of %d and %d is %d\n", x, y, x + y);


    memset(name, 0, 255);

    printf("What is your name?\n");
    scanf("%s",name); // Doesn't read after space., 
    printf("Hello %s, nice to meet you\n");

    printf("Enter X and Y, (space separated): ");
    scanf("%d%d", &x, &y);
    printf("Sum of %d and %d is %d\n", x, y, x + y);

    printf("Enter X and Y, (coma separated): ");
    scanf("%d,%d", &x, &y);
    printf("Sum of %d and %d is %d\n", x, y, x + y);

    return 0;
}