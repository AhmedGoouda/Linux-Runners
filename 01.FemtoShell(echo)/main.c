#include <stdio.h>
#include <string.h>

#include "private.h"
#include "interface.h"


int main() {
    char inputBuff[INPUT_BUFF_SIZE];
    int_callEcho(inputBuff, sizeof(inputBuff));
}