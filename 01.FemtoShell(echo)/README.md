# Assignment #1: Femto Shell

Write a femto shell program in c language that echoes any command entered by the user. The shell will have only one built-in command "exit". If the user entered "exit", the shell will reply with "Good Bye" and terminate.

## Sample output with max input length size 10

```bash
Say Something >> Hi
You said >> Hi
Say Something >> 
Say Something >> Hello
You said >> Hello
Say Something >> Hello Eng. Reda
Input is too long, Max length is 10
Say Something >> what
You said >> what
Say Something >> exit
GoodBye
```

## Sample output with max input length size 300

```bash
Say Something >> Hi
You said >> Hi
Say Something >> 
Say Something >> 
Say Something >> Hello
You said >> Hello
Say Something >> Thank you Eng. Reda
You said >> Thank you Eng. Reda
Say Something >> Keep Seeking, Keep Learning
You said >> Keep Seeking, Keep Learning
Say Something >> Goodbye
You said >> Goodbye
Say Something >> exit
GoodBye
```

## compilation command(s) used

```shell
gcc -o myfemtoShell femtoShell.c
```

or

```shell
gcc -o myfemtoShell prog.c main.c 
```

> Please Note Below:

You can view all the code combined in the file 'femtoShell.c`, or divided in the other files.
