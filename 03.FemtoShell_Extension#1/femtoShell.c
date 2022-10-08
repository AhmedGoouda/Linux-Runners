/**********Please Note**********/
/*This is an initial code, it still needs refinement, refactoring, and optimization*/
/*1. I'll make my own strtok and a general tokenizer int_tokenizer(char *buff, char delimeter, char **tokens)*/
/*2. Check if the local var is exist and overwrite its value instead of saving a duplicated varName with different values*/
/*3. solve the var name issue in case of comparing with the fargv[1], as var name is 50 chars length string >>>> SOLVED*/
/*4. check returns of charPtr_getUserInput*/
/*5. edit echo in the assignment2 and make it a functio here, not just a run from main*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>


char *femtoShellCommands[] = {"fexit", "fecho", "fpwd", "fcp", "fmv", "fset", "fexport"};
enum femtoShellCommands {fexit, fecho, fpwd, fcp, fmv, fset, fexport};

int int_exitFemtoShell(void) {

    printf("%s", "GoodBye\n");
    return 0;
}

char* charPtr_getUserInput(char *prompt, char* inputBuff, size_t inputBuffSize) {
    char extraChars;
    
    if (prompt != NULL) {
        printf("%s", prompt);
        fflush(stdout);
    }
    
    if (fgets(inputBuff, inputBuffSize, stdin) == NULL) {
        //return -1;
    }
    
    if (inputBuff[0] == '\n') {
        //return -2;
    }
    
    if (inputBuff[strlen(inputBuff) - 1] != '\n') {
        while ((extraChars = getchar() != '\n') && (extraChars != EOF));
        //return -3;
    }
    
    inputBuff[strlen(inputBuff) - 1] = '\0';
    return inputBuff;
}



char** charArrPtr_tokenizeUserInput(char* inputBuff, int *tokensCount) {

    const char delimiter[2] = " ";
    char *token;
    static char *tokens[15];
    int i;

    for (i = 0; i < 15; i++) {

        tokens[i] = NULL;
    }

    i = 0;

    /* get the first token */
    token = strtok(inputBuff, delimiter);

    /* walk through other tokens */
    while( token != NULL ) {
        tokens[i] = token;
        token = strtok(NULL, delimiter);
        i++;
    }

    *tokensCount = i;
   
    return tokens;
}


char** charArrPtr_tokenizeUserInputVariable(char* inputBuff, int *tokensCount) {

    const char delimiter[2] = "=";
    char *token;
    static char *tokens[15];
    int i;

    for (i = 0; i < 15; i++) {

        tokens[i] = NULL;
    }

    i = 0;

    /* get the first token */
    token = strtok(inputBuff, delimiter);

    /* walk through other tokens */
    while( token != NULL ) {
        tokens[i] = token;
        token = strtok(NULL, delimiter);
        i++;
    }

    *tokensCount = i;
   
    return tokens;
}



int int_parseUserInput(int argumentsCount ,char **arguments) {

    if (argumentsCount == 0) {

        return -2;
    }

    for (int i = 0; i < (sizeof(femtoShellCommands) / sizeof(*femtoShellCommands)); i++) {

        if(!strcmp(arguments[0], femtoShellCommands[i])) {

            return i;
            break;
        }
    }

    return -1;
}


extern char** environ;

struct var {

    char name[50];
    char value[50];

}localVar[100];


int int_runFemtoShell(void) {

    int fargc;
    char **fargv;
    char userInputBuff[300];
    char *userInput;
    int userCommand;
    int forkRet;
    static int varIndex = 0;
    int setenvRet;
    
    while (1) {

        userInput = charPtr_getUserInput("It's the femto shell >> ", userInputBuff, sizeof(userInputBuff));

        char* equalPostion = strchr(userInputBuff, '=');

        if(equalPostion == NULL) {

            fargv = charArrPtr_tokenizeUserInput(userInput, &fargc);
        }
        else if (equalPostion != NULL){

            fargv = charArrPtr_tokenizeUserInputVariable(userInputBuff, &fargc);

            strcpy(localVar[varIndex].name, fargv[0]);
            strcpy(localVar[varIndex].value, fargv[1]);

            varIndex++;
            continue;
        }

        userCommand = int_parseUserInput(fargc, fargv);

        if (userCommand == -2) {

            continue;
        }
        else if (userCommand == fexit) {

            break;
        }
        else if (userCommand == fset) {

            for (int i = 0; i < varIndex; i++) {

                printf("localVar[%d]: %s = %s\n", i, localVar[i].name, localVar[i].value);
            }

            continue;
        }
        else if (userCommand == fexport) {

            setenvRet = -2;
                
            for (int i = 0; i < varIndex; i++) {

                if (!strcmp(fargv[1], localVar[i].name)) {

                    setenvRet = setenv(localVar[i].name, localVar[i].value, 1);
                    break;
                }
            }

            if (setenvRet == -2) {

                printf("Couldn't export [%s], variable doesn't exist.\n", fargv[1]);
            }

            continue;
        }

        forkRet = fork();

        if (forkRet < 0) {

            return -1;
        }
        else if (forkRet > 0) {
            
            int childStatus;
            wait(&childStatus);

        }
        else if (forkRet == 0) {

            int execveStatus = execvp(fargv[0], fargv);
            if (execveStatus == -1) {
                printf("Command doesn't exist is femto shell or main shell\n");
                return -1;
            }
        }

    }

    return 0;
}



int main(int argc, char *argv[]) {

    int_runFemtoShell();

}
