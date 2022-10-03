# Assignment #2 Femto Unix Utilities

Femto Unix Utilities (pwd, echo, cp, mv). Write the following simple unix  utilities:

1. pwd: print working directory.
1. echo: print a user input string on stdout (for example:  echo Hello World).
1. cp: copy a file to another file and keep the original one (equivalent to copy/paste).
1. mv: move a file to another file and remove the original one (equivalent to cut/paste).

## compilation command(s) used

1. echo
    
    ```bash
    gcc -o myecho echo.c main.c
    ```

1. pwd
    
    ```bash
    gcc -o mypwd pwd.c main.c
    ```

1. cp
    
    ```bash
    gcc -o mycp cp.c main.c
    ```

1. mv
    
    ```bash
    gcc -o mymv mv.c main.c
    ```