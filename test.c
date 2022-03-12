#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    int i = time(NULL);
    printf("%d", i);
    return 0;
}
