#include <stdio.h>
#include <string.h>

#include "private.h"
#include "interface.h"

int main(int argc, char *argv[]) {

    for(int i = 1; argv[i] != NULL; i++) {

        printf("%s ", argv[i]);
    }
    printf("\n");
}