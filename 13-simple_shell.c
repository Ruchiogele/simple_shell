#include "shell.h"

/**
 * err_pr - prints errors
 * @argv: argument
 * @c: count
 * @cmd: Command
 */

void err_pr(char **argv, int c, char **cmd)
{
	char *k = _itoa(c);

	DISPLAY(argv[0]);
	DISPLAY(": ");
	DISPLAY(k);
	DISPLAY(": ");
	DISPLAY(cmd[0]);
	DISPLAY(": Illegal number: ");
	DISPLAY(cmd[1]);
	DISPLAY("\n");
	free(k);
}
