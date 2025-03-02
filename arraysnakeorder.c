#include<stdio.h>

void printSankeOrderSimple(int row, int column, int array[][column])
{
    int printindex = 0;
    int direction  = 1;

    for(int i = 0; i < row; i++)
    {

        // If Even row, print left to right
        if((i % 2) == 0)
        {
            for(int j = 0; j < column; j++)
            {
                printf("%d, ", array[i][j]);
            }
        }
        // for odd rows, print right to left
        else
        {
            for(int j = column - 1; j >= 0; j--)
            {
                printf("%d, ", array[i][j]);
            }
        }
        // Print new line for nex row
        printf("\n");
    }
}


void printSankeOrderAnotherWay(int row, int column, int array[][column])
{
    int printindex = 0;
    int direction  = 1;

    for(int i = 0; i < row; i++)
    {

        // Select the printindex for current row
        printindex = (i % 2) == 0 ? 0 : (column - 1);

        // print the elements at given indexes
        for(int j = 0; j < column; j++)
        {
            printf("%d, ",array[i][printindex]);
            printindex += direction;
        }
        // Reverse the direction.
        direction = (1 ==  direction) ? -1 : 1;


        printf("\n");
    }
}

// #define printSankeOrder printSankeOrderAnotherWay
#define printSankeOrder printSankeOrderSimple

int main(int argc, char *argv[])
{
    int testarray[4][5] = {
        { 0,  1,  2,  3,  4},
        { 9,  8,  7,  6,  5},
        {10, 11, 12, 13, 14},
        {19, 18, 17, 16, 15},
    };

    int testarray2[5][3] = { {0, 1, 2}, {5, 4, 3}, {6, 7, 8}, {11, 10, 9}, {12,13,14} };

    printSankeOrder(4,5, testarray);

    printSankeOrder(5, 3, testarray2);

    return 0;
}
