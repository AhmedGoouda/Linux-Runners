#include <stdio.h>
#include <string.h>

void vid_echoMessage(void);

int main(){

    vid_echoMessage();

    return 0;
}


void vid_promptMessage(void)
{
    printf("%s", "Say Something: ");
}

void vid_takeUserInput(char *input)
{
    gets(input);
}


unsigned char u8_checkUserInput(char *input)
{
    char exitKeyword[] = "exit";
    return strcmp(input, exitKeyword);

}

void vid_repeatInput(char *input)
{
    printf("You said: %s\n", input);
}

void vid_exit(void)
{
    printf("%s", "Goodbye\n");
}

void vid_echoMessage(void)
{
    char message[50];
    void vid_promptMessage(void);
    void vid_takeUserInput(char*);
    unsigned char u8_checkUserInput(char*);
    void vid_repeatInput(char*);
    void vid_exit(void);


    vid_promptMessage();
    vid_takeUserInput(message);

    while (u8_checkUserInput(message) != 0)
    {
        vid_repeatInput(message);
        vid_promptMessage();
        vid_takeUserInput(message);
    }
    
    vid_exit();
}