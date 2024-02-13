#include <stdio.h>
#include <stdlib.h>
#include "week2.h"

int main(int argc, char **argv)
{
    create_pascal_triangle(5);
}

void print_array(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void create_dynamic_array(void)
{
    int *arr;
    int size;
    int i;
    int val;
    printf("Input size of array: ");
    scanf("%d", &size);
    arr = (int *)malloc(size * sizeof(int));
    printf("Address %p, size %d \n", (void *)arr, size);
    for (i = 0; i < size; i++)
    {
        printf("Input %dth element of the array: ", i);
        scanf("%d", &val);
        arr[i] = val;
    }
    print_array(arr, size);
    free(arr);
}

void create_pascal_triangle(int level)
{
    int **triangle;
    int i, j;
    triangle = (int **)malloc(level * sizeof(int *));
    for (i = 1; i <= level; i++)
    {
        triangle[i] = (int *)malloc(i * sizeof(int));
        for (j = 0; j <= i; j++)
        {
            triangle[i][j] = 1;
        }
        print_array(triangle[i], i);
        free(triangle);
    }
}

char *to_uppercase(const char *str)
{
    /* the string has a length of n characters +1 for '\0' */
    char *result = malloc(strlen(str) + 1);
    int i = 0;
    /* example of code when the malloc fails */
    if (result == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    /* we will go through every element one by one
        until we reach '\0' which has a value of 0 */
    while (str[i])
    {
        /* a character is a lower case letter if:
            1- it has a numerical value of at least 'a' [97]
            2- this value is at most 'z' [122]
            */
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            /* offset the value to convert, this offset is 32 or 'a' - 'A' */
            result[i] = str[i] - ('a' - 'A');
        }
        else
        {
            result[i] = str[i];
        }
        i++;
    }
    result[i] = '\0';
    return result;
}

char is_little_endian()
{
    unsigned int num = 1;
    /* If the first byte of the integer is 1, the machine is little-endian
       If the last byte of the integer is 1, the machine is big-endian */
    return *(char *)&num;
}