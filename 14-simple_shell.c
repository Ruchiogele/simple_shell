#include "shell.h"

/**
 * cmd_sort - comand sort
 * @input: input
 * Return: sorted char
 */
char **cmd_sort(char *input)
{
	char **_tks;
	char *_tk;
	int i, buff_size = BUFSIZE;

	if (input == NULL)
		return (NULL);
	_tks = malloc(sizeof(char *) * buff_size);
	if (!_tks)
	{
		perror("hsh");
		return (NULL);
	}

	_tk = str_tok(input, "\n ");
	for (i = 0; _tk; i++)
	{
		_tks[i] = _tk;
		_tk = str_tok(NULL, "\n ");
	}
	_tks[i] = NULL;

	return (_tks);
}
