#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lab1.h"

int main(int argc, char **argv)
{
    char *c;

    float *frequency;
    char *upper;

    char **splitSentences;

    int numofWordPairs = 2;
    char *out;
    words *w, *w1;
    words **list;
    char *lower;
    /* PART 1: Detect language*/
    if (argc != 2)
    {
        printf("Please provide a relevant file\n");
        return 1;
    }
    c = file_to_str(argv[1]);

    frequency = malloc(NUM_LETTERS * sizeof(float));
    upper = to_uppercase(c);
    calculate_letter_frequency(upper, frequency);

    /*PART 2: Splitting into sentences*/
    splitSentences = split_sentences(c);
    print_string_array(splitSentences);
    free_sentences(splitSentences);

    /*PART 2: Replacing words*/
    /*char *cTest = "On a bRiGHt and Sunny day, the dAY is Bright and sunny.";*/
    w = input_words("bright", "dark");
    w1 = input_words("day", "night");
    list = (words **)malloc(numofWordPairs * sizeof(words *));
    lower = to_lowercase(c);
    list[0] = w;
    list[1] = w1;
    out = change_wording(lower, list);
    printf("%s\n", out);
    free_words(w);
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

char *to_lowercase(const char *str)
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
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            result[i] = str[i] + ('a' - 'A');
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

char **split_sentences(const char *text)
{
    int sentenceLength = 1;
    int noOfSentences = 1;
    int i;
    char *sentence = malloc(sentenceLength * sizeof(char));
    char **result = malloc(noOfSentences * sizeof(char *));
    i = 0;
    while (text[i])
    {
        sentence = realloc(sentence, (sentenceLength + 1) * sizeof(char));
        sentence[sentenceLength - 1] = text[i];
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence[sentenceLength] = '\0';
            result = realloc(result, noOfSentences * sizeof(char *));
            result[noOfSentences - 1] = sentence;
            noOfSentences++;

            sentenceLength = 0;
            sentence = NULL;
        }
        sentenceLength++;
        i++;
    }
    result[noOfSentences - 1] = NULL;
    return result;
}

void print_string_array(char **strings)
{
    int i = 0;
    while (strings[i])
    {
        printf("%s\n", strings[i]);
        i++;
    }
}

void free_sentences(char **sentences)
{
    int i = 0;
    while (sentences[i])
    {
        free(sentences[i]);
        i++;
    }
    free(sentences);
}

char *change_wording(const char *text, words **list)
{
    int i = 0;
    char *original = strdup(text);
    char *out = malloc(strlen(text) + 1);
    char *pos;
    char *nextPos = original;
    strncpy(original, text, strlen(text));
    if (original == NULL || out == NULL)
    {
        perror("Memory allocation failed\n");
        exit(1);
    }
    while (list[i])
    {
        pos = original;
        while ((nextPos = strstr(pos, list[i]->originalWord)) != NULL)
        {
            out = realloc(out, strlen(original) - list[i]->oLength + list[i]->rLength + 1);
            if (out == NULL)
            {
                printf("memory reallocation failed\n");
                exit(1);
            }
            strncat(out, pos, nextPos - pos);
            strncat(out, list[i]->replacementWord, list[i]->rLength);
            pos = nextPos + list[i]->oLength;
        }
        strcat(out, pos);
        strcpy(original, out);
        strcpy(out, "");
        i++;
    }
    return original;
}

words *input_words(char *o, char *r)
{
    words *result = (words *)malloc(sizeof(words));
    result->originalWord = (char *)malloc(strlen(o) * sizeof(char) + 1);
    result->replacementWord = (char *)malloc(strlen(r) * sizeof(char) + 1);
    strcpy(result->originalWord, o);
    strcpy(result->replacementWord, r);
    result->oLength = strlen(o);
    result->rLength = strlen(r);

    return result;
}

void free_words(words *this)
{
    free(this->originalWord);
    free(this->replacementWord);
    free(this);
}

void print_words(words *this)
{
    printf("Original word: %s, Replacement word: %s\n length: %d, legnth: %d\n",
           this->originalWord, this->replacementWord, this->oLength, this->rLength);
}
