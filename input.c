#include "shell.h"
/**
 * input - get the command from the user
 * Return: 0 Always
 */
void input(void)
{
	char *command = NULL;
	char *envp[] = {NULL};
	const char *line = "#cisfun$ ";
	size_t len = 0;
	ssize_t r;
	int i = 0;

	while (TRUE)
	{
		write(STDOUT_FILENO, line, 9);
		r = getline(&command, &len, stdin);
		if (r == -1)
		{
			perror("getline");
			exit(0);
		}
		while (command[i] != '\n')
			i++;
		command[i] = '\0';
		execute(command, envp);
	}
}
