#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#define PORT_NAME_MAX_LEN   32
#define PORT_BUFFER_LEN     512
#define BAUD_RATE 115200

int get_port_name();
int open_port();
int close_port();
int log_data();
void filtered();

#endif // PARSER_H_INCLUDED
