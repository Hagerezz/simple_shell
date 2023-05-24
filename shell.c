#include "shell.h"

/**
 * split_line - Split a line into an array of tokens
 * @line: The input line to be split
 * Return: An array of tokens
 */
char **split_line(char *line)
{
    int bufsize = MAX_ARGS;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, DELIMITER);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += MAX_ARGS;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, DELIMITER);
    }
    tokens[position] = NULL;
    return (tokens);
}

/**
 * main - Simple shell program
 * Return: Always 0
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    char **args;
    int status;
    pid_t pid;
    char *s = "./shell: No such file or directory\n";
    while (1)
    {
        write(STDOUT_FILENO, "#cisfun$ ", 9);
        getline(&line, &len, stdin);
        args = split_line(line);

        if (args[0] == NULL)
            continue;

        if (access(args[0], F_OK) == -1)
        {
            write(STDOUT_FILENO, s, 35);
            continue;
        }
        else
        {
            pid = fork();
            if (pid == 0)
            {
                execve(args[0], args, NULL);
                perror("./shell");
                exit(0);
            }
            else if (pid < 0)
            {
                perror("fork");
                exit(0);
            }
            else
                waitpid(pid, &status, 0);
        }
        free(line);
        free(args);
    }
    return (0);
}