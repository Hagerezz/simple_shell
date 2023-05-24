#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define MAX_ARGS 64

char **split_line(char *line);
void execute(char *command, char *env[]);
int main(void);
#endif