/* Conditional debug string -> Release build no logs., debug build, logs.*/
#include <stdio.h>

#ifdef DEBUGBUILD
#define LOG(string_format, ...) do {\
     printf("%s()->%d: ", __func__, __LINE__);     \
     printf(string_format, ##__VA_ARGS__);          \
} while (0)
#else
#define LOG(fmt, ...)
#endif

void testfunction(void)
{
     LOG("This is a test function");
}
int main(int argc, char **argv)
{
     LOG("This is the information : %s\n","Some info\n");
     LOG("This is another data : %f\n",23.92);
     LOG("Code is working.,\n",3);
     testfunction();
     printf("Done\n");
     return 0;
}

