#ifndef SHELL_H
#define SHELL_H
/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define BUFF_SIZE 1024

/* Prototypes */

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *stream);
pid_t fork(void);ssize_t write(int fd, const void *buf, size_t count);



#endif
