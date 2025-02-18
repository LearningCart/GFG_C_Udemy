#include <stdio.h>

const double PI = 3.14;
// const int i; // Uninitialized global const is set to 0 by def. 
int main(int argc, char *argv[])
{
    const int r = 10; // Declare constant.., can't directly modify., (through pointer yes, but then what is the use?!)
    // const int i; // Some garbage constant value., every run it is different.., 
    // i++; // error: increment of read-only variable 'i'
    printf("i = %d\n",r);
    printf("Low Precision 2 Pi r = %f\n", 2 * PI * r);

    // Ignoring 
    #if 0
    // Experiment
    double *ptr = NULL;
    ptr = &PI; //  .\eight.c:13:19: warning: initialization discards 'const' qualifier from pointer target type [-Wdiscarded-qualifiers]
    
    *ptr = 3.14325; // Crash here.,  Program received signal SIGSEGV, Segmentation fault. as it may be configured to genereate fault when
                    // accessing read only data.,  Check c compiler version

    printf("High precisoin 2 Pi r = %f\n", 2 * PI * r);
    #endif
    {
        // Override global constant with local one., (normal or constant anything will work)
        const double PI = 3.143257;
        printf("High precisoin 2 Pi r = %f\n", 2 * PI * r);
    }

    return 0;
}

// Macro are global scope., 
// But constant are limited scope since they are variables., 

// gcc .\eight.c -std=c99 -pedantic -g -o .\a.exe