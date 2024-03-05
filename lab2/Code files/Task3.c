#include <stdio.h>

/* Define the FSM states, as in Task 2. */
typedef enum
{
    INITIAL_STATE,
    ACCEPTING_STATE
} State;

/* Define the FSM states for concatenated RegEx FSM */
typedef enum
{
    STATE_0,
    STATE_1,
    STATE_2
} ConcatState;

/* Define the FSM struct with an added field for the letter, as in Task 2. */
typedef struct
{
    State currentState;
    char targetLetter;
} FSM;

/*
Define the ConcatFSM struct to handle the two FSM objects for concatenation "ab".
    - currentState: Current state of the ConcatFSM.
    - firstLetter: First letter to search for.
    - secondLetter: Second letter to search for.
*/
typedef struct
{
    ConcatState currentState;
    char firstLetter;
    char secondLetter;
} ConcatFSM;

/* Initialize the FSM with the target letter, as in Task 2. */
void initFSM(FSM *fsm, char letter)
{
    fsm->currentState = INITIAL_STATE;
    fsm->targetLetter = letter;
}

/*
    Initialize the ConcatFSM with two FSM objects.
    - Set initial state as ???.
    - Fetch targetLetter attributes from both FSMs and assign correctly to ConcatFSM attributes.
*/
void initConcatFSM(ConcatFSM *concatFsm, FSM *fsm1, FSM *fsm2)
{
    concatFsm->currentState = STATE_0;
    concatFsm->firstLetter = fsm1->targetLetter;
    concatFsm->secondLetter = fsm2->targetLetter;
}

/*
    Process a character input for the ConcatFSM.
    - Implements the correct transition logic for our FSM.
*/
void processCharConcat(ConcatFSM *concatFsm, char input_char)
{
    switch (concatFsm->currentState)
    {
    case STATE_0:
        if (input_char == concatFsm->firstLetter)
            concatFsm->currentState = STATE_1;
        break;
    case STATE_1:
        if (input_char == concatFsm->secondLetter)
            concatFsm->currentState = STATE_2;
        else
            concatFsm->currentState = STATE_0;
    case STATE_2:
        break;
    default:
        break;
    }
}

/* Run the concatenated FSM for entire input string. */
int runRegexConcat(ConcatFSM *concatFsm, const char *str)
{
    int i;
    concatFsm->currentState = STATE_0;
    for (i = 0; str[i] != '\0'; i++)
    {
        processCharConcat(concatFsm, str[i]);
        if (concatFsm->currentState == STATE_2)
            return 1;
    }
    return 0;
}

int main(void)
{
    /* Create our three FSMs objects. */
    FSM fsmA, fsmB;
    ConcatFSM concatFsm;

    /* Our two test case strings. */
    const char *testString = "Hello, world!";
    const char *testString2 = "Hablo, world!";

    /* Initialize our three FSMs. */
    initFSM(&fsmA, 'a');
    initFSM(&fsmB, 'b');
    initConcatFSM(&concatFsm, &fsmA, &fsmB);

    /* Test case 1. */
    if (runRegexConcat(&concatFsm, testString))
        printf("The string \"%s\" contains 'ab'.\n", testString);
    else
        printf("The string \"%s\" does not contain 'ab'.\n", testString);

    /* Test case 2.
       Remember to reset the FSM. */
    initConcatFSM(&concatFsm, &fsmA, &fsmB);
    if (runRegexConcat(&concatFsm, testString2))
        printf("The string \"%s\" contains 'ab'.\n", testString2);
    else
        printf("The string \"%s\" does not contain 'ab'.\n", testString2);

    return 0;
}
