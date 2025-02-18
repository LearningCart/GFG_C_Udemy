// Static variables
#include<stdio.h>

int testfunctions(void);

void testcase1(void);
void testcase2(void);

int main(int argc, char *argv[])
{
    static int x;
    printf("%d\n",x);

    // testcase1();
    testcase2();
    return 0;
}

int testfunctions(void);

void testcase1(void)
{
    int x;
    printf("%d\n",x);

    for(x = 0; x < 15; x++)
    {
        testfunctions();
    }
    
}
int testfunctions(void)
{
    static int callcount = 0;
    callcount++;
    // Every fifth count, it will do something.,  in this case print
    if(callcount % 5 == 0)
    {
        printf("OK\n");
    }
}

// Note we can expand this idea to a state machine table 
// array of an array of function pointers too insted of 
// setting handler, we can say fn **statemachine= statemachine1

void CallCallback(void (*fn) (void));

void first_handler(void)
{
    printf("first_handler\n");
}
void second_handler(void)
{
    printf("second_handler\n");
}
void default_handler(void)
{
    printf("default handler\n");
}

void testcase2(void)
{
    CallCallback(NULL);

    CallCallback(first_handler);
    CallCallback(NULL);
    CallCallback(NULL);
    CallCallback(NULL);
    CallCallback(second_handler);
    CallCallback(NULL);
    CallCallback(NULL);
    CallCallback(NULL);
    CallCallback(NULL);
    CallCallback(NULL);
    CallCallback(NULL);
    CallCallback(NULL);
    CallCallback(default_handler); // Restore default handler


}

void CallCallback(void (*fn) (void))
{
    extern void default_handler(void);
    static void (*handler) (void) = default_handler;

    // Override with new handler.
    if(NULL != fn)
    {
        handler = fn;
    }
    // Call handler
    handler();

}
// default value is 0
// they will exist in the memory even if the function all is over.
// value will persist in memory
// static global varibales have internal linkage., 
// TODO: two c file in same program with same static variable name
// Static global won't be accessible to other file (after preprocessing step)
// it will not be avilable.