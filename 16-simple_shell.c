#include "shell.h"

/**
 * prompt - prompts
 */

void prompt(void)
{
	DISPLAY("$ ");
}

/**
 * print_error - error display
 * @input: input
 * @counter: counter
 * @argv: value
 * Return: Void
 */

void print_error(char *input, int counter, char **argv)
{
	char *c;

	DISPLAY(argv[0]);
	DISPLAY(": ");
	c = _itoa(counter);
	DISPLAY(c);
	free(c);
	DISPLAY(": ");
	DISPLAY(input);
	DISPLAY(": not found\n");
}
