#include "shell.h"
/**
 * input: get the command from the user
 */
void input(void)
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
			perror("getline");
			exit(0);
		}
		while (command[i] != '\n')
			i++;
		command[i] = '\0';
		execute(command, env);
	}
}