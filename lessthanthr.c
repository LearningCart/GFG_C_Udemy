#include <stdio.h>
#include <string.h>

void testcode(void);

int main(int argc, char *argv[])
{

        testcode();
        return 0;
}

// MAIN TEST CODE STARTS HERE
#include <stdlib.h>
#include <time.h>


#define BREAK_IF_TRUE(condition)        if( (condition) )       { break;}

// Caller needs to free the memory
// Assuming array is really big enough as total!
int *findsmaller(int *array, int total, int threshold, int *totalout)
{
        int *result;
        int totalfound;
        result = NULL;


        do
        {
                BREAK_IF_TRUE(NULL == array || 0 == total || NULL == totalout);

                *totalout = 0;
                totalfound = 0;
                // Get total elements less than threshold
                for (int i = 0; i < total; i++)
                {
                        totalfound += (array[i] < threshold) ? 1: 0;
                }
                *totalout = totalfound;

                result = malloc(total * sizeof(int));

                BREAK_IF_TRUE(NULL == result);

                memset(result, 0, total * sizeof(int));

                // populate array of smaller elements
                for (int i = 0, j = 0; i < total && j < totalfound; i++)
                {
                        if(array[i] < threshold)
                        {
                                result[j] = array[i];
                                j++;
                        }
                }


        }while(0);

        return result;

}



int array[100];
void testcode(void)
{
        int threshold;
        int *lessthanthr;
        int totalout;

        printf("Program to return all the elements smaller than X in new array\n");

        memset(array, 0, sizeof(array));


        // Setting seed for the rand() function
        srand(time(0));

        for(int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
        {
                array[i] = rand() % 255;
        }

        threshold = 0;

        printf("Enter Threshold: ");
        scanf("%d", &threshold);

        totalout = 0;
        lessthanthr = findsmaller(array, 100, threshold, &totalout);

        if(NULL == lessthanthr || 0 == totalout)
        {
                printf("No element is less than %d\n", threshold);

        }else
        {

                printf("%d elements are less than %d\n", totalout, threshold);
                for(int i = 0; i < totalout; i++)
                {
                        printf("%d, ", lessthanthr[i]);
                }
                printf("\n");
                free(lessthanthr);
                lessthanthr = NULL;
        }

}
