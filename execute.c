#include "shell.h"
/**
 * execute - execute command
 * @command: pointer to the command line
 * @envp: pointer
 */
void execute(char *command, char *envp[])
{
	int s;
	pid_t pid = fork();
	char *arg[MAX_ARG];
	char *a = strtok(command, " ");
	int j = 0;

	if (pid == 0)
	{
		while (a != NULL)
		{
			arg[j++] = a;
			a = strtok(NULL, " ");
		}
		arg[j] = NULL;
		execve(arg[0], arg, envp);
		perror("./shell");
		exit(0);
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(0);
	}
	else
		waitpid(pid, &s, 0);
}
