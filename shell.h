#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

#define DELIM " \t\n"
extern char **environ;


char *read_line(void);
char **tokenizer(char *line);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _execute(char **command, char **argv, int idx);
char *_getpath(char *command);
void free_array(char **command);
void reverse_string(char *str, int len);
void printerror(char *name, char *cmd, int ind);
char *_itoa(int n);
char *_getenv(char *variable);
int is_builtin(char *command);
void handle_builtin(char **command, char **argv, int *status, int idx);
void exit_shell(char **command, char **argv, int *status, int idx);
void print_env(char **command, int *status);
int is_positive(char *str);
int _atoi(char *str);

#endif
