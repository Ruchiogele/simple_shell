#include "shell.h"

/**
* read_input - reads input
* Return: Input
*/

char *read_input(void)
{
	int i, b_ff_size = BUFSIZE, r_i;
	char c = 0;
	char *b_ff = malloc(b_ff_size);

	if (b_ff == NULL)
	{
		free(b_ff);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		r_i = read(STDIN_FILENO, &c, 1);
		if (r_i == 0)
		{
			free(b_ff);
			exit(EXIT_SUCCESS);
		}
		b_ff[i] = c;
		if (b_ff[0] == '\n')
		{
			free(b_ff);
			return ("\0");
		}
		if (i >= b_ff_size)
		{
			b_ff = _realloc(b_ff, b_ff_size, b_ff_size + 1);
			if (b_ff == NULL)
			{
				return (NULL);
			}
		}
	}
	b_ff[i] = '\0';
	rem_else_hash(b_ff);
	return (b_ff);
}

/**
 * rem_else_hash - clears all else following hash
 * @buff: input
 * Return: void
 */

void rem_else_hash(char *buff)
{
	int i;

		for (i = 0; buff[i] != '\0'; i++)
		{
			if (buff[i] == '#')
			{
			buff[i] = '\0';
			break;
			}
	}
}
