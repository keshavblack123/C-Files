// Only using stdio, no string library needed for this.
#include <stdio.h>
// We will assume that the strings read by the Tokenizer
// can be processed as an array of maximum 20 Tokens.
#define MAX_TOKENS 20
// We will assume that the numbers in strings read by the Tokenizer
// consist of maximum 20 digits.
#define MAX_DIGITS 20

// Struct for CFG symbols.
// - symbol: A single character containing the representation of the CFGSymbol.
// - is_terminal: An int, which indicates whether the symbol is terminal (0 = false, 1 = true)
// - is_start: An int, which indicates whether the symbol is a start symbol (0 = false, 1 = true)
typedef struct
{
    char symbol;
    int is_terminal;
    int is_start;
} CFGSymbol;

// Generic function to initialize a CFGSymbol.
void init_CFGSymbol(CFGSymbol *symbol, char text, int is_terminal, int is_start)
{
    symbol->is_start = is_start;
    symbol->is_terminal = is_terminal;
    symbol->symbol = text;
}

// Specific initializers for different types of symbols (terminal symbol).
void init_Terminal(CFGSymbol *symbol, char text)
{
    symbol->is_terminal = 1;
    symbol->symbol = text;
    symbol->is_start = 0;
}

// A simple tokenizer function.
// Behaves as explained in instructions.
void tokenizeString(char *str, CFGSymbol *symbols, int *symbol_count, CFGSymbol *plus, CFGSymbol *n)
{
    // Initialize indexing and symbol count.
    int i = 0;
    int start = 0;
    *symbol_count = 0;

    // Browse through string on character at a time.
    // Stop	if maximal number of tokens is reached.
    // (Will not happen for our test cases)
    while (str[i])
    {
        if (i > MAX_TOKENS)
        {
            printf("max tokens reached");
            break;
        }
        // If the current character is '+', add the plus CFGSymbol to the symbols array.
        if (str[i] == '+')
            symbols[(*symbol_count)++] = *plus;

        // If the current character is a digit, it might be the start of a number.
        // Mark the start of the number using the variable start.
        else if (str[i] >= '0' && str[i] <= '9')
        {
            start = i;

            // Keep incrementing i to find the end of the number.
            // Keep in mind the MAX_DIGITS constraint.
            while (str[i + 1] >= '0' && str[i + 1] <= '9' && (i - start) < MAX_DIGITS)
                i++;

            // Add a single CFGsymbol n to represent the number.
            symbols[(*symbol_count)++] = *n;
            // (Note: No need to decrement 'i' since we want to start reading the next character.)
        }
        else
        {
            // Handle non-digit and non-plus characters if necessary?
            printf("Not a valid token");
        }
        i++;
    }
}

// Some test cases
int main(void)
{
    CFGSymbol plus, n;
    CFGSymbol symbols1[MAX_TOKENS], symbols2[MAX_TOKENS];
    int symbol_count1 = 0;
    int symbol_count2 = 0;
    int i;
    char str1[] = "17+4+526";
    char str2[] = "74++26+";

    // Initialize terminal symbols for Tokenizer.
    init_Terminal(&plus, '+');
    init_Terminal(&n, 'n');

    // Test case #1 for Tokenizer
    tokenizeString(str1, symbols1, &symbol_count1, &plus, &n);
    printf("--- Test case 1\nString: %s\nTokens: ", str1);
    for (i = 0; i < symbol_count1; ++i)
    {
        printf("Token(%c) ", symbols1[i].symbol);
    }
    printf("\n");

    // Test case #2 for Tokenizer
    tokenizeString(str2, symbols2, &symbol_count2, &plus, &n);
    printf("--- Test case 2\nString: %s\nTokens: ", str2);
    for (i = 0; i < symbol_count2; ++i)
    {
        printf("Token(%c) ", symbols2[i].symbol);
    }
    printf("\n");

    return 0;
}
