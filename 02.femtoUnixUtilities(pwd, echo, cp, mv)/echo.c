#include <stdio.h>
#include <string.h>

#include "private.h"
#include "interface.h"

int int_getUserInput(char *prompt, char* inputBuff, size_t inputBuffSize) {
    char extraChars;
    
    if (prompt != NULL) {
        printf("%s", prompt);
        fflush(stdout);
    }
    
    if (fgets(inputBuff, inputBuffSize, stdin) == NULL) {
        return NULL_INPUT;
    }
    
    if (inputBuff[0] == '\n') {
        return EMPTY_INPUT;
    }
    
    if (inputBuff[strlen(inputBuff) - 1] != '\n') {
        while ((extraChars = getchar() != '\n') && (extraChars != EOF));
        return LONG_INPUT;
    }
    
    inputBuff[strlen(inputBuff) - 1] = '\0';
    return OK_INPUT;
}

int int_echoUserInput(char *inputBuff, size_t inputBuffSize) {
    int getInputRetValue = int_getUserInput("Say Something >> ", inputBuff, inputBuffSize);
    
    if (!strcmp(inputBuff, EXIT_KEYWORD)) {
        printf("%s", "GoodBye\n");
        return INPUT_EXIT;
    }
    
    switch (getInputRetValue) {
        case NULL_INPUT: printf("%s", "Null Pointer\n"); break;
        case EMPTY_INPUT: /*printf("%s", "Empty Input\n");*/ break;
        case LONG_INPUT:
            printf("Too long Input.\nPlease increase the size of the input buffer, current size is %d.\n", (INPUT_BUFF_SIZE));
            break;
        case OK_INPUT:
            printf("You said >> %s\n", inputBuff);
            break;
    }
    
    return getInputRetValue;
}

int int_callEcho(char *inputBuff, size_t inputBuffSize) {
    int echoRetValue;
    
    while(1) {
        echoRetValue = int_echoUserInput(inputBuff, inputBuffSize);
        
        if (echoRetValue == INPUT_EXIT) {
            break;
        }
        else {
            continue;
        }
    }
    return echoRetValue;
}