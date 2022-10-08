#ifndef INTERFACE_H
#define INTERFACE_H

/*********************echo************************/

#define INPUT_BUFF_SIZE   (300 + 2)  //plus 2 for Null Char and ??? 
#define EXIT_KEYWORD     "exit"

//int int_getUserInput(char *prompt, char* inputBuff, size_t inputBuffSize);
//int int_echoUserInput(char *inputBuff, size_t inputBuffSize);
//int int_callEcho(char *inputBuff, size_t inputBuffSize);

/**********************pwd************************/

#define WD_BUFF_SIZE  (300 + 1)    //plus 1 for Null Char.

int int_pwd(int argc);

/********************cp**************************/

#define READ_ONLY_MODE          0
#define READ_WRITE_MODE         1   

#define COPY_BUFF_SIZE         10

int int_openFile(char *filePath, int fileOption);
int int_closeFile(int fd);
int int_readFile(char *filePath, char *readBuff, size_t readBuffSize);
int int_writeFile(char *filePath, char *writeBuff, size_t writeBuffCount);
int int_copyFile(int argc, char *argv[]);

/********************mv***************************/

#define MV_ARG_COUNT_ERROR -2

#define MOVE_DONE  0
#define MOVE_ERROR -11

int int_moveFile(int argc, char *argv[]) ;

#endif
