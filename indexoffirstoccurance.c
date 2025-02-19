#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_ELEMENTS  20
#define BREAK_IF_TRUE(condition)        if( (condition) )       { break;}


int array[TOTAL_ELEMENTS];

void testcase1(void);

int main(int argc, char *argv[])
{
    testcase1();
    return 0;
}


// Omitted argument check for simplicity
int binary_search_recursive(const int *array, int size, int data, int start, int end)
{
    int index;
    int mid;

    if(start > end)
    {
        return -1;
    }
    
    mid = (start + end) / 2;
    if(data == array[mid])
    {
        // If this is the first element or if previous element is not same as this one,
        // than the element at mid is the first occurance., 
        if(mid == 0 || array[ mid - 1 ] != array[mid])
        {
            return mid;
        }else
        {
            // Else continue searching in lower half than mid., as we need  previous first
            // occurance.,
            return binary_search_recursive(array, size, data, start, mid - 1 );
        }
        int i;
    }else if(array[mid] > data)
    {
        // If data is less than mid, search lower half,  mid -1 becomes end
        return binary_search_recursive(array, size, data, start, mid - 1 );
    }else
    {
        // data is greater than array[mid], search in upper half, mid+1 becomes start
        return binary_search_recursive(array, size, data, mid+1, end );
    }
    return -1;
}

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

void testcase1(void)
{
    int foundat;
    int dataarray[] = {10, 10, 10, 13, 13, 13, 15, 15, 15, 15, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17};

    for(int i = 0; i < TOTAL_ELEMENTS; i++)
    {
        array[i] = dataarray[i];
    }

    printf("Input array: \n");
    printarray(array, TOTAL_ELEMENTS);
    printf("\n");

    printf("First occurance of %d is %d\n", 15, binary_search_recursive(array, TOTAL_ELEMENTS, 15, 0, TOTAL_ELEMENTS - 1));
    printf("First occurance of %d is %d\n", 17, binary_search_recursive(array, TOTAL_ELEMENTS, 17, 0, TOTAL_ELEMENTS - 1));


}
