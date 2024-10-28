#ifndef RUSH_02_H
#define RUSH_02_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 4096

typedef struct s_dict {
    unsigned long long key;
    char *value;
    struct s_dict *next;
} t_dict;

// dict_parser.c
t_dict *parse_dict(const char *filename);
int process_buffer(char *buffer, t_dict **dict);
int process_line(char *line, t_dict **dict);
int add_to_dict(t_dict **dict, unsigned long long key, char *value);
void free_dict(t_dict *dict);

// number_converter.c
int convert_and_print(t_dict *dict, const char *number_str);
int print_number(t_dict *dict, unsigned long long num);
int print_triple(t_dict *dict, unsigned long long num);
int print_word(t_dict *dict, unsigned long long num);

// utils.c
char *trim(char *str);
int is_valid_number(const char *str);

#endif