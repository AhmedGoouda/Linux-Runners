#include <stdio.h>
#include <string.h>

#include "private.h"
#include "interface.h"

#define SELECTED_MAN 2

#if SELECTED_MAN == 1
int main() {
    char inputBuff[INPUT_BUFF_SIZE];
    int_callEcho(inputBuff, sizeof(inputBuff));
}

#elif SELECTED_MAN == 2
int main() {

    char cwd[MAX_LEN_OF_WD];
    int_pwd(cwd, sizeof(cwd));
}
#endif