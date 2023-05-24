#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * exit_builtin - Exit the program
 */
void exit_builtin(void)
{
	exit(0);
}

/**
 * handle_input - Handle user input
 * @input_str: The input command string
 */
void handle_input(char *input_str)
{
	if (strcmp(input_str, "exit") == 0)
	{
		exit_builtin();
	}
	else
	{
		printf("Unknown input: %s\n", input_str);
	}
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
	char input[1024];

	while (1)
	{
		printf("sh $ ");
		fgets(input, 1024, stdin);
		input[strcspn(input, "\n")] = '\0';
		handle_input(input);
	}

	return (0);
}

