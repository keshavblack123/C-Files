#include <stdio.h>

int main(void)
{
    int num = 10;
    int *ptr = &num;

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", (void *)&num);
    printf("Value of ptr: %p\n", (void *)ptr);
    printf("Dereferenced value of ptr: %d\n", *ptr);

    return 0;
}

/*
Value of num: 10
Address of num: 0x7ff7b89c1308
Value of ptr: 0x7ff7b89c1308
Dereferenced value of ptr: 10
*/
