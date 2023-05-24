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
    int i = 0;

    while (line[i] != '\n')
        i++;
    line[i] = '\0';
    if (!tokens)
    {
        exit(EXIT_FAILURE);
    }

    token = strtok(line, DELIMITER);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;
        token = strtok(NULL, DELIMITER);
    }
    tokens[position] = NULL;
    return (tokens);
}

/**
 * main - Simple shell program
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
    char *line = NULL;
    size_t len = 0;
    char **args;
    int status;
    pid_t pid;
    char *s = "./shell: No such file or directory\n";
    int r;

    while (1)
    {
        write(STDOUT_FILENO, "#cisfun$ ", 9);
        r = getline(&line, &len, stdin);
        if (r == -1 || argc != 1)
        {
            exit(EXIT_FAILURE);
        }
        
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
                perror(argv[0]);
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