#include "shell.h"

/**
 * execute - execute command
 * @command: pointer to the command line
 * @env: pointer
 */
void execute(char *command, char *env[])
{
	int status;
	pid_t pid;
	char *args[MAX_ARG];
	char *token;
	int i;

	pid = fork();
	if (pid == 0)
	{
		token = strtok(command, " ");
		i = 0;

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		execve(args[0], args, env);
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
