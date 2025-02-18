#include <stdio.h>
#include <string.h>

void testcode(void);

int main(int argc, char *argv[])
{

        testcode();
        return 0;
}

// MAIN TEST CODE STARTS HERE


#define BREAK_IF_TRUE(condition)        if( (condition) )       { break;}

// Caller needs to free the memory
// Assuming array is really big enough as total!
int findlargest(int *array, int total)
{
        int result;
        result = -1;

        do
        {
                BREAK_IF_TRUE(NULL == array || total <= 0 );

                // Get largest elemnt in array
                for (int i = 0; i < total; i++)
                {
                        if(array[i] > result)
                        {
                            result = array[i];
                        }
                }
        }while(0);

        return result;

}

#include <stdlib.h>
#include <time.h>

#define MAX_RANGE   (127)

int *GetRandomBuffer(int size)
{
    int *resultbuffer;
    resultbuffer = NULL;
    do
    {  
        BREAK_IF_TRUE (size <= 0);

        resultbuffer = malloc(size * sizeof(int));

        BREAK_IF_TRUE(NULL == resultbuffer);

        memset(resultbuffer, 0, size);

        // Setting seed for the rand() function
        srand(time(0));
        // Fill up with random value
        for(int i = 0; i < size; i++)
        {
                resultbuffer[i] = rand() % MAX_RANGE;
        }
        
    } while (0);
    return resultbuffer;
}

void testcode(void)
{
        int *buffer;
        
        printf("Program to return maximum in random array in range of %d\n", MAX_RANGE);

        buffer = GetRandomBuffer(100);

        if(NULL == buffer)
        {
            printf("Failed to allocate buffer of %d elements with random value", 100);
            return;
        }

        printf("Maximum of random buffer is : %d\n", findlargest(buffer, 100));
}
