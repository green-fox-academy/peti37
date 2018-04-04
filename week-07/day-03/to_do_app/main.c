#include <stdio.h>
#include <stdlib.h>
void info(void);
void commands(void);
void write_new_task(void);
void delete_line(void);
void complete_task(void);
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
            "-i   List all the commands\n"
            "-l   Lists all the tasks\n"
            "-a   Adds a new task\n"
            "-r   Removes an task\n"
            "-c   Completes an task\n\n");
}

void commands(){
    char comm[2] = "-i";
    char add[2] = "-a";
    char list[2] = "-l";
    char remove[2] = "-r";
    char comp[2] = "-c";

    char* command = (char*)malloc(2);
    gets(command);

    if (command[1] == comm[1] && command[0] == comm[0])
        info();
    else if (command[1] == add[1] && command[0] == add[0]){
        write_new_task();
    }
    else if (command[1] == list[1] && command[0] == list[0]){
        read_all_tasks();
        printf("\n");
    }
    else if (command[1] == remove[1] && command[0] == remove[0]){
        delete_line();
        printf("\n");
        read_all_tasks();
    }
    else if (command[1] == comp[1] && command[0] == comp[0]){
        complete_task();
        printf("\n");
        read_all_tasks();
    }
    else{
        //system("@cls||clear");
        printf("Not a valid command, use '-i' for the commands.\n");
    }
}

void write_new_task(void){
    char task[50];
    FILE *fptr;
    fptr = fopen("tasks.txt", "a+");
    printf("Enter new task:\n");
    gets(task);
    int len;
    fseek(fptr, 0, SEEK_END);
    len = ftell(fptr);
    if  (len != 0)
        putc('\n', fptr);
    fprintf(fptr, "[ ] %s", task);
    fclose(fptr);
}

void read_all_tasks(void){
    FILE *fptr;
    fptr = fopen("tasks.txt", "r");
    char single_line[150];
    int number_lines = 0;
    while(!feof(fptr)){
        fgets(single_line, 150, fptr);
        printf("%d. %s", number_lines, single_line);
        number_lines++;
    }
    fclose(fptr);
}

void delete_line(void){
    int index;
    FILE *fptr;
    FILE *fptr_temp;
    fptr = fopen("tasks.txt", "r");
    fptr_temp = fopen("tasks_temp.txt", "w");
    printf("Enter the index of the task:");
    scanf("%d", &index);
    char single_line[150];
    int counter = 0;
    while(!feof(fptr)){
        fgets(single_line, 150, fptr);
        if  (index != counter){
                fprintf(fptr_temp, "%s", single_line);
        }
        counter++;
    }
    fclose(fptr);
    fclose(fptr_temp);
    fptr = fopen("tasks.txt", "w");
    fptr_temp = fopen("tasks_temp.txt", "r");
    while(!feof(fptr_temp)){
        fgets(single_line, 150, fptr_temp);
        fprintf(fptr, "%s", single_line);
    }
    fclose(fptr);
    fclose(fptr_temp);
    remove("tasks_temp.txt");
}

void complete_task(void){
    int index;
    FILE *fptr;
    FILE *fptr_temp;
    fptr = fopen("tasks.txt", "r");
    fptr_temp = fopen("tasks_temp.txt", "w");
    printf("Enter the index of the task:\n ");
    scanf("%d", &index);
    char single_line[150];
    int counter = 0;
    while(!feof(fptr)){
        fgets(single_line, 150, fptr);
        if  (index == counter){
                single_line[1] = 'x';
        }
        fprintf(fptr_temp, "%s", single_line);
        counter++;
    }
    fclose(fptr);
    fclose(fptr_temp);
    fptr = fopen("tasks.txt", "w");
    fptr_temp = fopen("tasks_temp.txt", "r");
    while(!feof(fptr_temp)){
        fgets(single_line, 150, fptr_temp);
        fprintf(fptr, "%s", single_line);
    }
    fclose(fptr);
    fclose(fptr_temp);
    remove("tasks_temp.txt");
}

