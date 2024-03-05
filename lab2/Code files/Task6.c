#include <stdio.h>

/* Define New Enum for Combined FSM */
typedef enum
{
    STATE_0,
    STATE_1,
    STATE_2,
    STATE_3,
    REJECTING_STATE
} CombinedState;

/* Define Combined FSM Struct, as in previous tasks.  */
typedef struct
{
    CombinedState currentState;
} CombinedFSM;

/*
    Initialize the Combined FSM, as in previous tasks.
    - For simplicity, we will not be storing letters ('a', 'b', 'c' and 'd') in attributes.
*/
void initCombinedFSM(CombinedFSM *combinedFsm)
{
    combinedFsm->currentState = STATE_0;
}

/* Process given input_char for the Combined FSM.  */
void processCharCombined(CombinedFSM *combinedFsm, char input_char)
{
    switch (combinedFsm->currentState)
    {
    case STATE_0:
        if (input_char == 'a')
            combinedFsm->currentState = STATE_1;
        else
            combinedFsm->currentState = REJECTING_STATE;
        break;
    case STATE_1:
        if (input_char == 'b' || input_char == 'c')
            combinedFsm->currentState = STATE_2;
        break;
    case STATE_2:
        if (input_char == 'd')
            combinedFsm->currentState = STATE_3;
        break;
    case STATE_3:
        if (input_char != 'd')
            combinedFsm->currentState = REJECTING_STATE;
        break;
    default:
        break;
    }
}

/*
    Running the Combined FSM, as in previous tasks.
    - Simple for loop on all characters as before.
    - Break for loop early on rejection, if you want.
    - Return true if the FSM is in correct accepting state.
 */
int runRegexCombined(CombinedFSM *combinedFsm, const char *str)
{
    int i;
    combinedFsm->currentState = STATE_0;
    for (i = 0; str[i] != '\0'; i++)
    {
        processCharCombined(combinedFsm, str[i]);
        if (combinedFsm->currentState == REJECTING_STATE)
            return 0;
    }
    return combinedFsm->currentState == STATE_3;
}

int main(void)
{

    /* Initialize our FSM object. */
    CombinedFSM combinedFsm;

    /* Some test strings, including the empty string.  */
    char *testStrings[] = {"a", "abd", "acd", "aad", "abdd", "ac", "abcd", "abda", NULL};
    int i;
    int matches;
    /* Run test cases and reset FSM each time. */
    for (i = 0; testStrings[i] != NULL; i++)
    {
        initCombinedFSM(&combinedFsm);
        matches = runRegexCombined(&combinedFsm, testStrings[i]);
        printf("String \"%s\" matches: %s\n", testStrings[i], matches ? "Yes" : "No");
    }
    return 0;
}
