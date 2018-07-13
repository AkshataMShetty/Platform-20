#include <stdio.h>

#define STRINGIZE(x) #x
#define STRINGIZE_VALUE_OF(x) STRINGIZE(x)


int main(int argc, char *argv[])
{
    printf("%s", STRINGIZE_VALUE_OF(name));
}
