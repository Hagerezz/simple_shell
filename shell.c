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
		tokens[position++] = token;
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
	int status, r;

	while (1)
	{
		printf("#cisfun$ ");
		r = getline(&line, &len, stdin);
		if (r == -1)
        {
		exit(EXIT_FAILURE);
        }
	args = split_line(line);

		if (args[0] == NULL)
			continue;
		if (access(args[0], F_OK) == -1)
		{
			printf("%s: Command not found.\n", args[0]);
			continue;  /* Do not fork if command does not exist */
		}
		else
		{
			status = execve(args[0], args, NULL);
			if (status == -1)
				perror("execve");
		}
	}
	free(line);
	free(args);
	return (0);
}
