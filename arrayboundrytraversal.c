#include<stdio.h>

void printBoundaryOrder(int row, int column, int array[][column])
{
    int i = 0;

    do
    {
        if(0 >= row || 0 >= column)
        {
            // Invalid arguments, don't do anything., 
            break;
        }
        
        // Boundary case 1
        if(1 == row)
        {
            for(i = 0; i < column; i++)
            {
                printf("%d, ", array[0][i]);        
            }
            // Done handling this case., 
            break;
        }

        if(1 == column )
        {
            for(i = 0; i < row; i++)
            {
                printf("%d, ", array[i][0]);        
            }
            // Done handling this case as well
            break;
        }

        // Else other non boundary cases., 
                
        // Print first row
        for(i = 0; i < column; i++)
        {
            printf("%d, ", array[0][i]);
        }
        printf("\n");

        // Print last column starting from next row
        for(i = 1; i < row; i++)
        {
            printf("%d, ", array[i][column - 1]);
        }
        printf("\n");

        // Print last row in right to left exclusing last column element
        // as it is already printed, we don't want to print it again.
        for(i = column  - 2; i >= 0; i--)
        {
            printf("%d, ", array[row - 1][i]);
        }
        printf("\n");

        // Print first column, bottom up., excluding last row element
        // as it is already printed, we don't want to print it again.
        for(i = row - 2; i >= 1; i--)
        {
            printf("%d, ", array[i][0]);
        }
        printf("\n");

    } while (0);
   
}

int main(int argc, char *argv[])
{
    int testarray1[4][5] = {
        { 0,  1,  2,  3,  4},
        { 9,  8,  7,  6,  5},
        {10, 11, 12, 13, 14},
        {19, 18, 17, 16, 15},
    };

    int testarray2[5][3] = { {0, 1, 2}, {5, 4, 3}, {6, 7, 8}, {11, 10, 9}, {12,13,14} };

    int testarray3[10][10] = {
        { 1,  1,  1,  1,  1, 1,  1,  1,  1,  1},
        { 1,  0,  0,  0,  0, 0,  0,  0,  0,  1},
        { 1,  0,  0,  0,  0, 0,  0,  0,  0,  1},
        { 1,  0,  0,  0,  0, 0,  0,  0,  0,  1},
        { 1,  0,  0,  0,  0, 0,  0,  0,  0,  1},
        { 1,  0,  0,  0,  0, 0,  0,  0,  0,  1},
        { 1,  0,  0,  0,  0, 0,  0,  0,  0,  1},
        { 1,  0,  0,  0,  0, 0,  0,  0,  0,  1},
        { 1,  0,  0,  0,  0, 0,  0,  0,  0,  1},
        { 1,  1,  1,  1,  1, 1,  1,  1,  1,  1},
        
    };

    int testarray4[10][1] = {
        { 1 },
        { 2 },
        { 3 },
        { 4 },
        { 5 },
        { 6 },
        { 7 },
        { 8 },
        { 9 },
        { 10},
        
    };

    
    int testarray5[1][10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 , 10 };
    
    printf("\n------------- TEST CASE 1 -------------\n");
    printBoundaryOrder(4,5, testarray1);

    printf("\n------------- TEST CASE 2 -------------\n");
    printBoundaryOrder(5, 3, testarray2);

    printf("\n------------- TEST CASE 3 -------------\n");
    printBoundaryOrder(10, 10, testarray3);

    // Boundary case 1
    printf("\n------------- TEST CASE 4 -------------\n");
    printBoundaryOrder(10, 1, testarray4);

    // Boundary case 2
    printf("\n------------- TEST CASE 5 -------------\n");
    printBoundaryOrder(1, 10, testarray5);

    return 0;
}
