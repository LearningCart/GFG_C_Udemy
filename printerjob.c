#include <stdio.h>
#include <stdbool.h>

void testcase1(void);
int main(int argc, char *argv[])
{
    testcase1();
    return 0;
}
// Printer gave error., so print even pages., 
void testcase1(void)
{
    int current;
    int upto;
    int temp;
    bool evenpages;

    current   = 0;
    upto      = 0;
    evenpages = true;

    printf("Enter upto number: ");
    scanf("%d",&upto);
    printf("even(non zero) sequence or odd(0) seq ?");
    scanf("%d",&temp);

    evenpages = (0 != temp);
    printf("Going to generate %d sequence of %s pages\n", upto, true == evenpages  ? "even" : "odd");

    for(current = (true == evenpages) ? 2 : 1; current < upto; current += 2)
    {
        printf("%d,", current);
    }

}
