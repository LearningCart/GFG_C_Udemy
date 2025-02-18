#include<stdio.h>
#include<stdbool.h>

#define BREAK_IF_TRUE(condition)        if( (condition) )       { break;}

#define SIZE    (10)

bool issorted(int *array, int size)
{
    // Assume it is not sorted
    bool sorted = false;

    do
    {
        BREAK_IF_TRUE(NULL == array || size <= 0);
        
        // Now since parameters are okay, assume sorted.
        sorted = true; 
        for(int i = 1; i < size; i++ )
        {
            // If current element is less than previous element,
            // it is not sorted
            if(array[i] < array[i - 1])
            {
                sorted = false;
                break;
            }
        }
    } while (0);
    
    return sorted;
}

int main(int argc, char *argv[])
{
    int array1[SIZE];
    int array2[SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        array1[i] = i+1;
        array2[i] = i+1;
    }

    printf("Array is %s sorted\n", (issorted(array1, SIZE)) ? "" : "Not");

    array2[6] = 9; // ;-)

    printf("Array is %s sorted\n", (issorted(array2, SIZE)) ? "" : "Not");

    return 0;
}