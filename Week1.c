#include <stdio.h>
#include "Week1.h"

int main(int argc, char **argv)
{
    char c = 't';
    print_bits(c);
}

int find_max(int p1, int p2)
{
    return p1 > p2 ? p1 : p2;
}

int fact_loop(int n)
{
    int x = 1;
    if (n > 0)
    {
        while (n > 1)
        {
            x = x * n;
            n--;
        }
    }
    return x;
}

int fact_rec(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * fact_rec(n - 1);
}

int fibo(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (fibo(n - 1) + fibo(n - 2));
}

int is_prime(int x)
{
    int i = x / 2;
    int n;
    for (n = 2; n <= i; n++)
    {
        if (x % n == 0)
            return 0;
    }
    return 1;
}

void print_ascii_table(void)
{
    int i;
    for (i = 0; i <= 127; i++)
    {
        printf("%d in Ascii is %c \n", i, i);
    }
}

void print_bits(char c)
{
    int dec = (int)c;
    int mask = 1;
    int i;
    int out;
    for (i = 0; i <= 8; i++)
    {
        out = c & mask;
        printf("%u", out);
        // printf("%d \n", mask);
        mask = mask << 1;
    }
}
