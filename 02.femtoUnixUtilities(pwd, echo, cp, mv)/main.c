#include <stdio.h>
#include <string.h>

#include "private.h"
#include "interface.h"

#define SELECTED_MAN 4

#if SELECTED_MAN == 1
int main() {
    char inputBuff[INPUT_BUFF_SIZE];
    int_callEcho(inputBuff, sizeof(inputBuff));
}

#elif SELECTED_MAN == 2
int main(int argc, char *argv[]) {

    int_pwd(argc);
}


#elif SELECTED_MAN == 3
int main(int argc, char *argv[]) {

    int_copyFile(argc, argv);
}

#elif SELECTED_MAN == 4
int main(int argc, char *argv[]) {

    int_moveFile(argc, argv);
}


#endif