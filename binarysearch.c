#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_ELEMENTS  20
#define BREAK_IF_TRUE(condition)        if( (condition) )       { break;}

int array[TOTAL_ELEMENTS];

void testcase1(void);
void testcase2(void);
void testcase3(void);

int main(int argc, char *argv[])
{
    testcase1();
    testcase2();
    testcase3();
    return 0;
}

int linear_search(const int *array, int size, int data)
{
    int index;
    index = -1;
    do
    {
        BREAK_IF_TRUE(NULL == array || 0 >= size)
        
        for(int i = 0; i < size; i++)
        {
            if(array[i] == data)
            {
                index = i;
                break;
            }
        }

    } while (0);
   
    return index;
}


int binary_search(const int *array, int size, int data)
{
    int index;
    int low;
    int high;
    int mid;
    index = -1;

    do
    {
        BREAK_IF_TRUE(NULL == array || 0 >= size)

        low = 0;
        high = size - 1;
        mid = (low + high) / 2;
        index = -1;
        while(low <= mid)
        {
            if(data < array[mid])
            {
                // data is in lower half., 
                high = mid - 1;
                mid = (low + high) / 2;

            }else if (data == array[mid])
            {
                // Found it., 
                index = mid;
                break;
            }
            else
            {
                // Data is in upper half., 
                low = mid  + 1;
                mid = (low + high) / 2;
            }
        }
    } while (0);
   
    return index;
}

void testcase1(void)
{
    int foundat;

    for(int i = 0; i < TOTAL_ELEMENTS; i++)
    {
        array[i] = i + 1;
    }
    foundat = -1;
    foundat = linear_search(array, TOTAL_ELEMENTS, 14);

    printf("Data : %d was %sfound (%d)\n", 14, -1 == foundat ? "Not " : "", foundat);
    
    foundat = -1;
    foundat = linear_search(array, TOTAL_ELEMENTS, 24);

    printf("Data : %d was %sfound (%d)\n", 24, -1 == foundat ? "Not " : "", foundat);
    
}

void testcase2(void)
{
    int foundat;

    for(int i = 0; i < TOTAL_ELEMENTS; i++)
    {
        array[i] = i + 1;
    }
    foundat = -1;
    foundat = binary_search(array, TOTAL_ELEMENTS, 14);

    printf("Data : %d was %sfound (%d)\n", 14, -1 == foundat ? "Not " : "", foundat);
    
    foundat = -1;
    foundat = binary_search(array, TOTAL_ELEMENTS, 24);

    printf("Data : %d was %sfound (%d)\n", 24, -1 == foundat ? "Not " : "", foundat);
    
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
        return mid;
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

void testcase3(void)
{
    int foundat;

    for(int i = 0; i < TOTAL_ELEMENTS; i++)
    {
        array[i] = i + 1;
    }
    foundat = -1;
    foundat = binary_search_recursive(array, TOTAL_ELEMENTS, 14, 0, TOTAL_ELEMENTS - 1);

    printf("Data : %d was %sfound (%d)\n", 14, -1 == foundat ? "Not " : "", foundat);
    
    foundat = -1;
    foundat = binary_search_recursive(array, TOTAL_ELEMENTS, 24, 0, TOTAL_ELEMENTS - 1);

    printf("Data : %d was %sfound (%d)\n", 24, -1 == foundat ? "Not " : "", foundat);
    
}
