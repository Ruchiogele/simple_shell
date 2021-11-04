#include "shell.h"

/**
 * his_display - history display
 * @c: Command
 * @s: last status
 * Return: Always 0
 */

int his_display(__attribute__((unused))char **c, __attribute__((unused))int s)
{
	char *_fname = ".simple_shell_history";
	FILE *h_d;
	char *_ln = NULL;
	size_t st_len = 0;
	int _count = 0;
	char *k;

	h_d = fopen(_fname, "r");
	if (h_d == NULL)
	{
		return (-1);
	}
	while ((getline(&_ln, &st_len, h_d)) != -1)
	{
		_count++;
		k = _itoa(_count);
		DISPLAY(k);
		free(k);
		DISPLAY(" ");
		DISPLAY(_ln);

	}
	if (_ln)
		free(_ln);
	fclose(h_d);
	return (0);
}

/**
 * pr_echo - prints echo
 * @cmd: command
 * Return: Always 0
 */

int pr_echo(char **cmd)
{
	pid_t p_ech;
	int status;

	p_ech = fork();
	if (p_ech == 0)
	{
	if (execve("/bin/echo", cmd, environ) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (p_ech < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(p_ech, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
