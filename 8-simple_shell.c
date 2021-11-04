#include "shell.h"

/**
 * history - history
 * @input: Input
 * Return: Always 0
 */

int history(char *input)
{
	char *_fname = ".simple_shell_history";
	ssize_t f_n, f;
	int in_len = 0;

	if (!_fname)
		return (-1);
	f_n = open(_fname, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (f_n < 0)
		return (-1);
	if (input)
	{
		while (input[in_len])
			in_len++;
		f = write(f_n, input, in_len);
		if (f < 0)
			return (-1);
	}
	return (1);
}
/**
 * free_env - function that frees env. var
 * @env:  env. var
 * Return: void
 */
void free_env(char **env)
{
	int a;

	for (a = 0; env[a]; a++)
	{
		free(env[a]);
	}
}
