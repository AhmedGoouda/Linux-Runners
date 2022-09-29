#ifndef INTERFACE_H
#define INTERFACE_H


#define MAX_INPUT_SIZE   300
#define EXIT_KEYWORD     "exit"


int int_getUserInput(char *prompt, char* inputBuff, size_t inputBuffSize);
int int_echoUserInput(char *inputBuff);
int int_callEcho(char *inputBuff);


#endif