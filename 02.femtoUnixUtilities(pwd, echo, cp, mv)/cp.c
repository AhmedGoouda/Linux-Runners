/*** Under Developing ***/


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "private.h"
#include "interface.h"

#define ARG_COUNT_ERROR         1
#define SRC_FILE_NOT_FOUND      2
#define DEST_FILE_ERROR         3
#define WRITE_FILE_ERROR        4
#define WRITE_SUCCESS           5
#define NO_OF_READ_BYTES        100

int main(int argc, char* argv[]) {

    /*Check the numer of arguments*/
    if (argc != 3) {

        printf("%s", "Not Enough Arguments\n");
        return ARG_COUNT_ERROR;
    }

    /*Open source File*/
    int sourceFile_fd = open(argv[1], O_RDONLY);

    if (sourceFile_fd == (-1)) {

        return SRC_FILE_NOT_FOUND;
    }
    else {

        //return sourceFile_fd;
        printf("%s", "SRC Opened\n");
    }

    /*Open or Creat and Open the destination file*/
    int destinationFile_fd = open(argv[2], O_WRONLY|O_CREAT, 0644);

    if (destinationFile_fd == (-1)) {

        return DEST_FILE_ERROR;
    }
    else {

        //return destinationFile_fd;
        printf("%s", "Dest Created\n");
    }

    char srcFileBuff[NO_OF_READ_BYTES];
    long int numberOfReadBytes = read(sourceFile_fd, srcFileBuff, sizeof(srcFileBuff));

    /*Write in Destination File*/
    int writeFlag = write(destinationFile_fd, srcFileBuff, numberOfReadBytes);

    if (writeFlag == (-1)) {

        return WRITE_FILE_ERROR;
    }
    else {
        
        printf("%s", "Write Success\n");
        return WRITE_SUCCESS;
    }
}