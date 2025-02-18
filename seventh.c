// Below code just checks for global variable.

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

volatile bool buttonpressed = false;
int direction;

void processbutton(void)
{
    extern volatile bool buttonpressed;
    printf("Engine: %s\n", (true == buttonpressed) ? "Start" : "Stop");
}

void processbutton(void);

int uninitializedglobal;

extern int x;
y = 20;
/*
.\seventh.c:21:1: warning: data definition has no type or storage class
   21 | y;
      | ^
.\seventh.c:21:1: warning: type defaults to 'int' in declaration of 'y' [-Wimplicit-int]

.\seventh.c:21:1: warning: data definition has no type or storage class
   21 | y = 20;
      | ^
.\seventh.c:21:1: warning: type defaults to 'int' in declaration of 'y' [-Wimplicit-int]

*/

// extern: declare variable thart are present in other file. During linking it will link with that variable.

int person = 21;
int main(int argc, char **argv)
{
    int uninitializedlocal;
    int person = 42;
    printf("x = %d\n",x);
    printf("y = %d\n",y);

    printf("person is %d years old\n",person);
    {
        int person = 32;
        printf("person is %d years old\n",person);
    }
    printf("person is %d years old\n",person);
    buttonpressed = true;
    processbutton();

    sleep(5);

    buttonpressed = false;
    processbutton();

    printf("uninitialized global = %d\nuninitialized local = %dc\n", uninitializedglobal, uninitializedlocal);

    return 0;
}

int x = 10;