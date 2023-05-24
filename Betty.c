#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	printf("Counting numbers from 1 to 10:\n");

	for (i = 1; i <= 10; i++)
	{
		printf("%d\n", i);
	}

	return (0);
}
