#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lab1.h"

int main(int argc, char **argv)
{

    /*if (argc == NULL)
    {
        printf("Please provide a file");
        return 1;
    }*/
    char *c = file_to_str(argv[1]);
    float *frequency = malloc(NUM_LETTERS * sizeof(float));
    char *upper = to_uppercase(c);
    calculate_letter_frequency(upper, frequency);
    /*printf("%s \n", to_uppercase(c));*/
}

/* DO NOT MODIFY THIS FUNCTION */
char *file_to_str(const char *x)
{
    FILE *y;
    char *z;
    size_t s;
    size_t i;
    y = fopen(x, "r");
    if (!y)
    {
        printf("Err");
        return NULL;
    }
    fseek(y, 0, 2);
    s = ftell(y);
    rewind(y);
    z = (char *)malloc((s + 1) * sizeof(char));
    if (!z)
    {
        printf("Err");
        fclose(y);
        return NULL;
    }
    for (i = 0; i < s; i++)
    {
        z[i] = fgetc(y);
    }
    z[s] = '\0';
    return z;
}

void calculate_letter_frequency(char *text, float *frequency)
{
    int i = 0;
    float total = 0;
    float differenceEnglish, differenceFrench;
    while (text[i])
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            frequency[text[i] - 'A'] += 1;
            total++;
        }
        i++;
    }

    for (i = 0; i < 26; i++)
    {
        frequency[i] = frequency[i] / total;
    }

    differenceEnglish = calculate_difference(frequency, englishFreq);
    differenceFrench = calculate_difference(frequency, frenchFreq);

    if (differenceEnglish < differenceFrench)
    {
        printf("The text is likely to be English\n");
    }
    else
    {
        printf("The text is likely to be French\n");
    }
    printf("difference in English: %f\n", differenceEnglish);
    printf("difference in French: %f\n", differenceFrench);
}

float calculate_difference(const float *observedFreq, const float *expectedFreq)
{
    int i = 0;
    float total = 0;
    for (i = 0; i < 26; i++)
    {
        total += pow((observedFreq[i] - expectedFreq[i]), 2);
    }
    return total;
}

char *to_uppercase(const char *str)
{
    /* the string has a length of n characters +1 for '\0' */
    char *result = malloc(strlen(str) + 1);
    int i = 0;

    if (result == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
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
