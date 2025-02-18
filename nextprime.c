#include <stdio.h>
#include <stdbool.h>

// Function to check if number is prime
// Number is divisiable only by itself., 
// Start from 2 and search if any number divides it without remainder,.,
// if any number divies it without remainder, its not a prime number
bool isPrime(int n)
{
    int i;
    bool retval = false;
    
    do
    {
            
        if(0 == n || 1 == n)
        {
            retval = false;
            break;
        }

        retval = true;
        i = 2;

        while (i < n)
        {
            if(n % i == 0)
            {
                retval = false;
                break;
            }
            i++;
        }
    } while (0);

    return retval;
}

int main(int argc, char *argv[])
{
    int n;
    int m;
    int i;
    bool isprime;
    
    i = m = n = 0;

    printf("Enter the prime mumber: ");
    scanf("%d",&n);

    // printf("%d is %sPrime Number\n", n, true == isPrime(n) ? "" : "Not a ");

    // if(false == isPrime(n))
    // {
    //     printf("Please enter valid prime number\n");
    //     return -1;
    // }

    // Find next prime number 
    for(i = 1; i < n; i++)
    {

        m = n + i;
        if (true == isPrime(m))
        {
            printf("Next prime number after %d is %d\n", n, m);
            break;
        }
    }

    return 0;
}
