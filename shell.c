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
 * is_exit - check if the command is exit
 * @cmd: pointer to the command
 * Return: 1 if the command is exit
 */
int is_exit(char *cmd)
{
	if (cmd[0] == 'e' && cmd[1] == 'x' && cmd[2] == 'i'
		&& cmd[3] == 't' && cmd[4] == '\0')
		return (1);
	return (0);
}

/**
 * _atoi - Convert a string to an integer
 * @str: The string to convert
 * Return: integer
 */
int _atoi(const char *str)
{
	int num = 0;
	int sign = 1;

	while (*str == ' ' || *str == '\t' || *str == '\n')
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

/**
 * main - Simple shell program
 * Return: Always 0
 */
int main(int argc, char *argv[], char *envp[])
{
	char *line = NULL;
	size_t len = 0;
	char **args;
	int status, r, i;

	while (1)
	{
		r = getline(&line, &len, stdin);
		if (r == -1)
		{
			exit(EXIT_FAILURE);
		}
		args = split_line(line);
		if (is_exit(args[0]) && argc == 1)
		{
			if (args[1] == NULL)
			{
				free(line);
				free(args);
				exit(EXIT_SUCCESS);
			}
			else
			{
				status = _atoi(args[1]);
				free(line);
				free(args);
				exit(status);
			}
		}
		if (args[0][0] == 'e' && args[0][1] == 'n'
			&& args[0][2] == 'v' && args[0][3] == '\0')
		{
			for (i = 0; envp[i] != NULL; i++)
			{
				printf("%s\n", envp[i]);
			}
			continue;
		}
		if (args[0] == NULL)
			continue;
		if (access(args[0], F_OK) == -1)
		{
			printf("%s: Command not found.\n", args[0]);
			continue;
		}
		else
		{
			status = execve(args[0], args, envp);
			if (status == -1)
				perror(argv[0]);
		free(line);
		free(args);
		}
	}
	return (0);
}
