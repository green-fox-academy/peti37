#include <stdio.h>
#include <stdlib.h>
int counter;

void info(void);
void commands(void);
void write_new_task(void);

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
            "-r   List all the commands\n"
            "-l   Lists all the tasks\n"
            "-a   Adds a new task\n"
            "-r   Removes an task\n"
            "-c   Completes an task\n\n");
}

void commands(){
    char comm[2] = "-r";
    char add[2] = "-a";
    char list[2] = "-l";

    char* command = (char*)malloc(2);
    gets(command);

    if (command[1] == comm[1] && command[0] == comm[0])
        info();
    else if (command[1] == add[1] && command[0] == add[0])
        write_new_task();
    else if (command[1] == list[1] && command[0] == list[0])
        read_all_tasks();
    else{
        system("@cls||clear");
        printf("Not a valid command, use '-r' for the commands.\n");
    }
}

void write_new_task(void){
    char task[50];
    FILE *fptr;
    fptr = fopen("tasks.txt", "a");
    printf("Enter new task:\n");
    gets(task);
    putc('\n', fptr);
    fprintf(fptr, "%d. ", counter);
    fputs("[ ] ", fptr);
    fputs(task, fptr);
    fclose(fptr);
    counter++;
}

void read_all_tasks(void){
    FILE *fptr;
    fptr = fopen("tasks.txt", "r");
    char single_line[150];

    while(!feof(fptr)){
        fgets(single_line, 150, fptr);
        printf("%s", single_line);
    }
    fclose(fptr);
}

void delete_line(void){
    char index;
    FILE *fptr;
    fptr = fopen("tasks.txt", "r+");
    printf("Enter the index of the task:\n");
    gets(index);
}


