#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "private.h"
#include "interface.h"


int int_openFile(char *filePath, int fileOption) {

    int fd;

    if (fileOption == READ_ONLY_MODE) {

        fd = open(filePath, O_RDONLY);
    }
    else if (fileOption == READ_WRITE_MODE) {

        fd = open(filePath, O_WRONLY|O_CREAT, 0644);
    }
    else {
        return WRONG_OPTION;
    }

    if (fd == -1) {

        return SRC_FILE_NOT_FOUND;
    }
    else {

        return fd;
    }
}


int int_closeFile(int fd) {

    if (close(fd) == -1) {

        return CLOSE_FILE_ERROR;
    }
    else {
        return FILE_CLOSED;
    }
}


int int_readFile(char *filePath, char *readBuff, size_t readBuffSize) {

    static int src_fd;
    static unsigned char srcFileStatus = SOURCE_FILE_CLOSED;
    int readCharsCount;

    if (srcFileStatus == SOURCE_FILE_CLOSED) {

        src_fd = int_openFile(filePath, READ_ONLY_MODE);
        srcFileStatus = SOURCE_FILE_OPENED;
    }

    readCharsCount = read(src_fd, readBuff, readBuffSize);

    if (readCharsCount == 0) {

        srcFileStatus = int_closeFile(src_fd);
    }

    return readCharsCount == -1 ? READ_FILE_ERROR : readCharsCount;
}


int int_writeFile(char *filePath, char *writeBuff, size_t writeBuffCount) {

    static int dest_fd;
    static unsigned char destFileStatus = DEST_FILE_CLOSED;
    int writeCharsCount;

    if (destFileStatus == DEST_FILE_CLOSED) {

        dest_fd = int_openFile(filePath, READ_WRITE_MODE);
        destFileStatus = DEST_FILE_OPENED;
    }

    writeCharsCount = write(dest_fd, writeBuff, writeBuffCount);

    if (writeCharsCount == 0) {

        destFileStatus = close(dest_fd);
    }

    return writeCharsCount == -1 ? WRITE_FILE_ERROR : writeCharsCount;
}


int int_copyFile(int argc, char *argv[]) {

    char copyBuff[COPY_BUFF_SIZE];

    int readCharsCount = 1;
    int writeCharCount;

    if (argc != 3) {

        printf("%s", "Not Enough Arguments. It should be three.\n");
        return CP_ARG_COUNT_ERROR;
    }

    while (readCharsCount != 0) {

        readCharsCount = int_readFile(argv[1], copyBuff, sizeof(copyBuff));
        writeCharCount = int_writeFile(argv[2], copyBuff, readCharsCount);
    }

    return readCharsCount == writeCharCount ? COPY_DONE : COPY_ERROR;
}


int int_moveFile(int argc, char *argv[]) {

    char copyBuff[100];

    int readCharsCount = 1;
    int writeCharCount;

    if (argc != 3) {

        printf("%s", "Not Enough Arguments. It should be three.\n");
        return MV_ARG_COUNT_ERROR;
    }

    while (readCharsCount != 0) {

        readCharsCount = int_readFile(argv[1], copyBuff, sizeof(copyBuff));
        writeCharCount = int_writeFile(argv[2], copyBuff, readCharsCount);
    }

    remove(argv[1]);

    return readCharsCount == writeCharCount ? MOVE_DONE : MOVE_ERROR;
}