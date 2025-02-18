// Find second largest in array., 
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
// TODO: Find optimized solution as it runs the loop twice., 
//       find a way to figure this out in single iteration
int find2ndlargest(int *array, int total)
{
        int result, largest;
        result = -1;
        largest = -1;

        do
        {
                BREAK_IF_TRUE(NULL == array || total <= 0 );

                // Get largest elemnt in array
                for (int i = 0; i < total; i++)
                {
                        if( array[i] > largest )
                        {
                                largest = array[i];
                        } 
                }

                // Now find second largest
                for (int i = 0; i < total; i++)
                {
                        if( array[i] > result && array[i] < largest )
                        {
                                result = array[i];
                        } 
                }


        }while(0);

        return result;

}

// Find second largest in single iteration
int find2ndlargest_single(int *array, int total)
{
        int result, largest;
        result = -1; // No vice president yet., 
        largest = 0; // start by making first person a president 

        do
        {
                BREAK_IF_TRUE(NULL == array || total <= 0 );

                // Get 2nd largest elemnt in array
                for (int i = 0; i < total; i++)
                {
                        if( array[i] > array[largest] )
                        {
                                // Found someone more powerful  than current president
                                // So, current president becomes vice president
                                result = largest;
                                // And more powerful person that we just found becomes president
                                largest = i;
                        }else if(array[i] == array[largest]) 
                        {
                                // Found someone as powerful as current president, 
                                // Don't change the president.
                        }else
                        {
                                // Found someone less powerful than current president.,
                                // Lets check if that person is more powerful than current vice president
                                // NOTE: result == -1 and array[i] > array[result] can be combined with or, 
                                // but keeping them separate make it more clear.
                                if(result == -1)
                                {
                                        // There is no vice president at all.,
                                        // make second most powerful person we found as
                                        // a vice president.,
                                        result = i;
                                }else if (array[i] > array[result])
                                {
                                        // There is a vice president however, 
                                        // we found second more powerful person than current vice president.,
                                        // Elect new second most powerful person as a vice president.,
                                        result = i;
                                }else
                                {
                                        // Do nothing as current vice president is second most
                                        // powerful person so far., 
                                }
                        }
                
                }
        }while(0);

        return result >= 0 ? array[result] : -1;

}
///////////////////////// GetRandomBuffer: Begin


#include <stdlib.h>
#include <time.h>

// To check the generated buffer on terminal
#define PRINT_GENERATED_BUFFER

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
#ifdef PRINT_GENERATED_BUFFER
        printf("Resultant buffer is: { ");
        for(int i = 0; i < size; i++)
        {
                printf("%d, ", resultbuffer[i]);
        }
        printf(" }\n");
#endif
        
    } while (0);

    
    return resultbuffer;
}

///////////////////////// GetRandomBuffer: End

#define ARRAY_SIZE      (10)
void testcode(void)
{
        int *buffer;
        
        printf("Program to return maximum in random array in range of %d\n", MAX_RANGE);

        buffer = GetRandomBuffer(ARRAY_SIZE);

        if(NULL == buffer)
        {
            printf("Failed to allocate buffer of %d elements with random value", ARRAY_SIZE);
            return;
        }

        printf("2nd largest of random buffer is : %d\n", find2ndlargest(buffer, ARRAY_SIZE));

        // Test with same elements should return -1;
        for(int i = 0; i < ARRAY_SIZE; i++)
        {
                buffer[i] = 10;
        }
        printf("2nd largest of random buffer is : %d\n", find2ndlargest(buffer, ARRAY_SIZE));

        // free and allocate new buffer
        memset(buffer, 0, ARRAY_SIZE * sizeof(int));
        free(buffer);

        buffer = GetRandomBuffer(ARRAY_SIZE);

        if(NULL == buffer)
        {
            printf("Failed to allocate buffer of %d elements with random value", ARRAY_SIZE);
            return;
        }
        printf("Single Iteration: 2nd largest of random buffer is : %d\n", find2ndlargest(buffer, ARRAY_SIZE));

        // Test with same elements should return -1;
        for(int i = 0; i < ARRAY_SIZE; i++)
        {
                buffer[i] = 10;
        }
        printf("Single Iteration: 2nd largest of random buffer is : %d\n", find2ndlargest(buffer, ARRAY_SIZE));

}
