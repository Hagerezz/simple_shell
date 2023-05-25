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
#define DELIMITER " \t\r\n\a"
#define MAX_COMMAND_LENGTH 1024

char **split_line(char *line);
int is_exit(char *cmd);
int _atoi(const char *str);
#endif
