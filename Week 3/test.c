#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, char **argv)
{
    int (*max_func)(int a, int b) = max;
    printf("maxno = %d\n", max_func(8, 3));
    return 0;
}
