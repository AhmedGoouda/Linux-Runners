#include <stdio.h>
#include <unistd.h>

#include "private.h"
#include "interface.h"

int int_pwd(char *wdBuff, size_t wdBuffSize) {

    if (getcwd(wdBuff, wdBuffSize) != NULL) {

        printf("Current Working Directory: %s\n", getcwd(wdBuff, wdBuffSize));
        return WD_LEN_IS_OK;
    }
    else {

        printf("Too long directory.\nPlease increase the size of the cwd buffer, current size is %d.\n", MAX_LEN_OF_WD);
        return WD_LEN_IS_TOO_LONG;
    }
}