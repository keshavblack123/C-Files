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
    int i;
    for (i = 7; i >= 0; i--)
    {
        printf("%d", (c >> i) & 1);
    }
}

/* This version of the code assumes that a long is 8 bytes (64 bits)
It should deliver the right output on Mac OS and likely Linux
*/
void print_float_bits(double f)
{
    long now_a_long = *(long *)&f;
    int i;
    for (i = 63; i >= 0; i--)
    {
        printf("%ld", (now_a_long >> i) & 1);
    }
    printf("\n");
}

/* This version of the code assumes that a long is 4 bytes (32 bits)
Therefore, the double needs to be cast in a long long instead
It should deliver the right output on Windows

void print_float_bits_windows(double f)
{
    long long now_a_long = *(long long *) &f;
    int i;
    for (i = 63; i >= 0; i--) {
        printf("%lld", (now_a_long >> i) & 1);
    }
    printf("\n");
}
*/
