#ifndef SHELL_H
#define SHELL_H


/* Libraries */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>

#define TOK_DELIM " \t\r\n\a "
extern char **environ;

/* PROTOTYPES */

void my_interactive_shell(void);
void my_non_interactive_shell(void);
char *read_line(void);
char **split_line(char *line);
int execute_args(char **args);
int new_process(char **args);
char *read_stream(void);
int my_cd(char **args);
int my_exit(char **args);
int my_env();
int my_help();
pid_t fork(void);
pid_t wait(int *wstatus);
char *strtok(char *str, const char *delim);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);



#endif
