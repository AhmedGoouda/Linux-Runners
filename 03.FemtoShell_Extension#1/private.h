#ifndef PRIV_H
#define PRIV_H

/*echo*/
#define OK_INPUT         0
#define NULL_INPUT       1
#define EMPTY_INPUT      2
#define LONG_INPUT       3
#define INPUT_EXIT       4


/*pwd*/
#define WD_ARG_COUNT_ERROR -1
#define WD_LEN_IS_OK       0
#define WD_LEN_IS_TOO_LONG 1


/*cp*/
#define WRONG_OPTION           -5

#define SRC_FILE_NOT_FOUND     -2

#define FILE_CLOSED             0
#define CLOSE_FILE_ERROR       -7

#define SOURCE_FILE_CLOSED      0
#define SOURCE_FILE_OPENED      1
#define READ_FILE_ERROR        -6

#define DEST_FILE_CLOSED        0
#define DEST_FILE_OPENED        1
#define WRITE_FILE_ERROR       -4

#define CP_ARG_COUNT_ERROR     -3

#define COPY_DONE   0
#define COPY_ERROR -10

#endif