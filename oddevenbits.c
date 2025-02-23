// Program to group all the odd bits to the left and
// all the even bits to the right.
// Jatin Gandhi

#include <stdio.h>

// Data size
#define DATASIZE_64BIT

#if defined(DATASIZE_8BIT)
typedef unsigned char  uint8_t;

typedef uint8_t data_type_t;
data_type_t testdata[] = {0x99, 0x11, 0x22, 0x55, 0xAA};
#elif defined(DATASIZE_16BIT)
typedef unsigned short uint16_t;

typedef uint16_t data_type_t;
data_type_t testdata[] = {0x9999, 0x1111, 0x2222, 0x5555, 0xAAAA};
#elif defined(DATASIZE_32BIT)
typedef unsigned int   uint32_t;

typedef uint32_t data_type_t;
data_type_t testdata[] = {0x99999999, 0x11111111, 0x22222222, 0x55555555, 0xAAAAAAAA};
#else
// Assume 64 bit data if nothing is defined
typedef unsigned long long int uint64_t;

typedef uint64_t data_type_t;
data_type_t testdata[] = {0x9999999999999999, 0x1111111111111111, 0x2222222222222222, 0x5555555555555555, 0xAAAAAAAAAAAAAAAA};
#endif



data_type_t consolidateOddEvenBits(data_type_t data);

void test(data_type_t data)
{
    data_type_t out = 0;

    out = consolidateOddEvenBits(data);

    #ifdef DATASIZE_64BIT
    printf("Consolidated odd and even bits of 0x%0llX = 0x%0llX\n", data, out);
    #else
    printf("Consolidated odd and even bits of 0x%0X = 0x%0X\n", data, out);
    #endif
}

// Test Code
int main(int argc, char *argv)
{
    for (int i = 0; i < sizeof(testdata)/sizeof(testdata[0]); i++)
    {
        test(testdata[i]);
    }
    return 0;
}


// Function to consolidate all the odd bits to the left and
// all the even bits to the right.
// Multiply with 8 to get size in bits
#define sizeof_in_bits(x)   (sizeof((x)) * 8)

data_type_t consolidateOddEvenBits(data_type_t data)
{
    data_type_t      out;
    data_type_t  oddbits;
    data_type_t evenbits;
    
    out      = 0;
    oddbits  = 0;
    evenbits = 0;

    for(int i = 0; i < sizeof_in_bits(data); i++)
    {
        if(0 == i % 2)
        {
            // Even bit at given position is set position is set
            // Accumulate that bit., after shifting existing bits.,
            evenbits <<= 1;

            evenbits |= (data & (1 << i)) ? 1 : 0;
        }else
        {
            // Odd bit at given position is set position is set
            // Accumulate that bit.,  after shifting existing bits.,
            oddbits <<= 1;

            oddbits |= (data & (1 << i)) ? 1 : 0;
        }
    }

    // Move accumulated odd bits to upper half., 
    out  = oddbits << (sizeof_in_bits(data) / 2); // 1, 3, 5, 7...
    // Merge odd bits accumulated to the right portion of out,
    out |= evenbits; // 0, 2, 4, 6, ...
    return out;
}
