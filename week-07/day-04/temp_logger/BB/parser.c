#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "rs232/rs232.h"
#include "parser.h"
#include "printer.h"
#include "string.h"

int parser_port = -1;
char content[1024];

char* content_array(){
    char* array = (char*)malloc(50);
    char* array2 = (char*)malloc(sizeof(array)*2);
    //if  (sizeof(array)/2 <)
    memcpy(array2, array, 50);
    array = array2;
    return array;
}
int get_port_name()
{
	clear_screen();
	printf("Please enter the name of the serial port you want to use!\n");
	char port_name[PORT_NAME_MAX_LEN];
	fgets(port_name, PORT_NAME_MAX_LEN - 1, stdin);

	// Remove \r and \n characters
	for (int i = 0; i < PORT_NAME_MAX_LEN; i++) {
		if (port_name[i] == '\r' || port_name[i] == '\n')
			port_name[i] = '\0';
	}

	// Find the index of that port
	parser_port = comFindPort(port_name);

	if (parser_port < 0) {
		printf("%s not exists!\n", port_name);
		return -1;
	} else {
		printf("%s port exists, saved.\n", port_name);
	}

	return 0;
}

int open_port()
{
	clear_screen();
	if (parser_port < 0) {
		printf("Port not set!\n");
		return -1;
	}

	comClose(parser_port);
	if(!comOpen(parser_port, BAUD_RATE)) {
		printf("Port can not be opened. Try to set the port again!\n");
		return -1;
	} else {
		printf("Port opened successfully!\n");
		return 0;
	}
}

int close_port()
{
	clear_screen();
	if (parser_port < 0) {
		printf("Port not set!\n");
		return -1;
	}

	comClose(parser_port);
	printf("Port closed.\n");
	return 0;
}


int get_line_from_port(char *buff, int buff_len)
{
	if (parser_port < 0) {
		printf("Port not set!\n");
		return -1;
	}

	// Put data into the
	char ch;
	int i = 0;
	int bytes = comRead(parser_port, &ch, 1);
	// If there is no data on the port, exit
	if (bytes <= 0) {
		return 0;
	}
	// This loop will read until a \n character. If the buffer is too small, then
	// the characters will be discarded after the size limit is reached.
	while (ch != '\n') {
		// Check if there is enough space in the buffer
		if (i < (buff_len - 1)) {
			// Check if we are not near the end of the line (cr character)
			if (ch != '\r') {
				buff[i] = ch;
				i++;
			}
		}
		while (comRead(parser_port, &ch, 1) == 0);
	}
	// Put terminating zero at the end
	buff[i] = '\0';

	return i;
}

int log_data()
{
	// Check if port set up properly
	if (parser_port < 0) {
		printf("Port not set!\n");
		return -1;
	}

	// Get a line of data from the port
	// If there is no data on the port, then do nothing
	char buff[PORT_BUFFER_LEN];
	if (get_line_from_port(buff, PORT_BUFFER_LEN) > 0) {
		// Put the data into the logfile
        //Printing the buffer
		printf("%s\n",buff);
		strcat(content, "\n");
		strcat(content, buff);
	}

	return 0;
}
void filtered(){
    FILE *fptr;
    fptr = fopen("log.txt", "w");
    fprintf(fptr, content);
    fclose(fptr);
    fptr = fopen("log.txt", "r");
    char* year, *month, *day, *hour, *minute, *sec, *temp;
    char single_line[150];
    char single_line2[150];
    while(!feof(fptr)){
        fgets(single_line, 150, fptr);
        strcpy(single_line2, single_line);
        year = strtok(single_line, ".: ");
        month = strtok(NULL, ".: ");
        day = strtok(NULL, ".: ");
        hour = strtok(NULL, ".: ");
        minute = strtok(NULL, ".: ");
        sec = strtok(NULL, ".: ");
        temp = strtok(NULL, ".: ");
        if  (atoi(month) > 0 && atoi(month) < 13 && atoi(day) < 32 && atoi(day) > 0 && atoi(hour) < 25 && atoi(hour) >= 0 && atoi(minute) < 61 && atoi(minute) >= 0 && atoi(sec) >= 0 && atoi(sec) < 61 && strlen(temp) < 4){
            printf("%s", single_line2);
        }
    }
    fclose(fptr);
    strcpy(content, "");
}
