// Find second largest in array., 
#include <stdio.h>
#include <string.h>

#define BREAK_IF_TRUE(condition)        if( (condition) )       {\
    printf("Invalid parameters %s(%d)\n", __func__, __LINE__);\
    break;\
}

#define TEXT_ALIGNMENT  "%-60s"
// Main
void testcode(void);

int main(int argc, char *argv[])
{

        testcode();
        return 0;
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
        printf(TEXT_ALIGNMENT, "Resultant buffer is:");
        for(int i = 0; i < size; i++)
        {
                printf("%03d, ", resultbuffer[i]);
        }
        printf("\n");
#endif
        
    } while (0);

    
    return resultbuffer;
}

///////////////////////// GetRandomBuffer: End


// MAIN TEST CODE STARTS HERE


void rotate_array_left_by1(int *array, int size)
{
    do
    {
        BREAK_IF_TRUE(NULL == array || 0 >= size);


        // Take the first element
        int temp = array[0];

        // Rotate remaining elements by one
        for(int i = 0; i < (size - 1); i++)
        {
            array[i] = array[i+1];
        }

        // Put first element at the last position
        array[size-1] = temp;

    } while (0);
    
}

// Choose implementation before calling., 
void (*rotate_array_left_by_n) (int *array, int size, int n);

// Simple implementation: O(N^2) time complexity (check again) and O(0) space complexity
void rotate_array_left_by_n_simple(int *array, int size, int n)
{
    do
    {
        BREAK_IF_TRUE(NULL == array || 0 >= size || 0 >= n || n >=  size);

        for(int i = 0; i < n; i++)
        {
            rotate_array_left_by1(array, size);
        }

    } while (0);
}

// Implementation with O(n) time complexity but needs O(N) space complexity
void rotate_array_left_by_n_temp_dbuff(int *array, int size, int n)
{
    
    do
    {
        BREAK_IF_TRUE(NULL == array || 0 >= size || 0 >= n || n >=  size);

        int tempbuff[n];
        memset(tempbuff, 0, n * sizeof(int));

        // Copy first N elements to rotate in temp buffer
        for(int i = 0; i < n; i++)
        {
            tempbuff[i] = array[i];
        }

        // Copy remaining elements from n position onwards
        for(int i = n; i < size; i++)
        {
            array[i-n] = array[i];
        }

        // Copy temp buffer at the end of the buffer
        for(int i = 0; i < n; i++)
        {
            array[size - n + i] = tempbuff[i];
        }

    } while (0);
}

// More optimized approach
// Reverse array of size 'size' starting from start to end., 
void reverse(int *array, int size, int start, int end)
{
    int temp;
    do
    {
        BREAK_IF_TRUE(  NULL == array   || // Array must be there
                        0 >= size       || // Array size can't be negative
                        0 >  start      || // Start can be 0 but not less than 0,
                        0 >=  end       || // end of array can not be negative
                        start >= end    || // Can not start before end
                        end >= size);      // end must be smaller than array size

        while(start < end)
        {
            // Swap both to reverse (Just like string reverse !)
            temp            = array[start];
            array[start]    = array[end] ;
            array[end]      = temp;

            start++;
            end--;
        }
    }
    while(0);
}

// Best solution: O(n) time complexity and O(1) (temp variable) space complexity
void rotate_array_left_by_n_optimal(int *array, int size, int n)
{
    do
    {
        BREAK_IF_TRUE(NULL == array || 0 >= size || 0 >= n || n >=  size);

        // First we rotate first N elemets as they will be reversed and 'slotted' at the end in final stage
        // if N = 3:
        // [0, 1, 2, 3, 4, 5] (Step 1 ->) [2, 1, 0, 3, 4, 5]
        reverse(array, size, 0, n-1);

        // Now we reverse remaining elements to create mirror image of an array
        // [0, 1, 2, 3, 4, 5] (Step 1 ->) [2, 1, 0, 3, 4, 5] (Step 2 ->) [2, 1, 0, 5, 4, 3]
        reverse(array, size, n, size-1);

        // Now we have 'mirror' image of what we need, so revers it to get what we actually need.
        // [0, 1, 2, 3, 4, 5] (Step 1 ->) [2, 1, 0, 3, 4, 5] (Step 2 ->) [2, 1, 0, 5, 4, 3] (Step 3 ->) [3, 4, 5, 0, 1, 2]
        reverse(array, size, 0, size-1);

        // What we started: [0, 1, 2, 3, 4, 5], what we wanted             -> [3, 4, 5, 0, 1, 2]
        // What we have after flipping the mirror image of array in step 3 -> [3, 4, 5, 0, 1, 2]
        // So, it is the solution we need

    } while (0);
}




#define ARRAY_SIZE      (10)

void printarray(int *array, int size)
{
    if(NULL == array || 0 >= size)
    {
        printf("Invalid arguments: %s(%d)\n", __FUNCTION__, __LINE__);
        return;
    }

    // NOTE: Assuming array is 'really' of size 'size'
    for(int i = 0; i < size; i++)
    {
        printf("%03d, ", array[i]);
    }
}


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

        printf(TEXT_ALIGNMENT, "Before rotation: ");
        printarray(buffer, ARRAY_SIZE);
        printf("\n");

        rotate_array_left_by1(buffer, ARRAY_SIZE);

        printf(TEXT_ALIGNMENT, "After rotation 1 and before left rotation by 3: ");
        printarray(buffer, ARRAY_SIZE);
        printf("\n");

        // rotate_array_left_by_n = rotate_array_left_by_n_simple;
        // rotate_array_left_by_n = rotate_array_left_by_n_temp_dbuff;
        rotate_array_left_by_n    = rotate_array_left_by_n_optimal;

        // Call it. 
        rotate_array_left_by_n(buffer, ARRAY_SIZE, 3);

        printf(TEXT_ALIGNMENT, "After left rotation by 3: ");
        printarray(buffer, ARRAY_SIZE);
        printf("\n");

        
}

