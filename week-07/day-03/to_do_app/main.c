#include <stdio.h>
#include <stdlib.h>

void info(void);
void commands(void);
int main()
{
    info();
    while(1){
    commands();
    continue;
    }
    return 0;
}

void info(void){
    printf("Command Line Todo application\n");
    printf("=============================\n\n");
    printf("Command line arguments:\n"
            "-l   Lists all the tasks\n"
            "-a   Adds a new task\n"
            "-r   Removes an task\n"
            "-c   Completes an task\n\n");
}

void commands(){
    char list[2] = "-l";
    char* command = (char*)malloc(50);
    gets(command);
    if (command[1] == list[1] && command[0] == list[0]){
        info();
    }
    else
        printf("Not a valid command");
}
