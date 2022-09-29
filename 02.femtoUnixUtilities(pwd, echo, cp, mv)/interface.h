#ifndef INTERFACE_H
#define INTERFACE_H

/*********************echo************************/

#define INPUT_BUFF_SIZE   (300 + 2)  //plus 2 for Null Char and ??? 
#define EXIT_KEYWORD     "exit"

int int_getUserInput(char *prompt, char* inputBuff, size_t inputBuffSize);
int int_echoUserInput(char *inputBuff, size_t inputBuffSize);
int int_callEcho(char *inputBuff, size_t inputBuffSize);

/**********************pwd************************/

#define MAX_LEN_OF_WD  (300 + 1)    //plus 1 for Null Char.

int int_pwd(char *wdBuff, size_t wdBuffSize);

/*************************************************/

#endif