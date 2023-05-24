#include "shell.h"

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 128

/**
 * main: get the command from the user
 * Return: 0 Always
 */
int main()
{
    char *command = NULL;
    char *env[] = {NULL};
    const char *line = "#cisfun$ ";
    size_t len = 0;
    ssize_t r;
    int i = 0;

    while (1)
    {
        write(STDOUT_FILENO, line, 9);
        r = getline(&command, &len, stdin);
        if (r == -1)
        {
            exit(0);
        }
        while (command[i] != '\n')
            i++;
        command[i] = '\0';
        execute(command, env);
    }
    return 0;
}

/**
 * execute - execute command
 * @command: pointer to the command line
 * @env: pointer
 */
void execute(char *command, char *env[])
{
    int status;
    pid_t pid;
    char *args[MAX_ARGS];
    char *token = strtok(command, " ");
    int i = 0;
    char *s = "./shell: No such file or directory\n";

    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
	if (access(args[0], F_OK) != -1)
	{
	    pid = fork();
	    if (pid == 0)
	    {
		execve(args[0], args, env);
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
	    return;
	}
	write(STDOUT_FILENO, s, 35);
}