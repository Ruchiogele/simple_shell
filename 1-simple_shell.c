#include "shell.h"

/**
 * de_lim - checks for char to match any *
 * @c: char
 * @str: str
 * Return: Always 1, else return 0
 */

unsigned int de_lim(char c, const char *str)
{
	unsigned int a;

	for (a = 0; str[a] != '\0'; a++)
	{
		if (c == str[a])
			return (1);
	}
	return (0);
}

/**
 * str_tok - takes string token
 * @str: String
 * @delim: de_limiter
 * Return: pointer to next token Or NULL
 */

char *str_tok(char *str, const char *delim)
{
	static char *tok;
	static char *nxt;
	unsigned int i;

	if (str != NULL)
		nxt = str;
	tok = nxt;
	if (tok == NULL)
		return (NULL);
	for (i = 0; tok[i] != '\0'; i++)
	{
		if (de_lim(tok[i], delim) == 0)
			break;
	}
	if (nxt[i] == '\0' || nxt[i] == '#')
	{
		nxt = NULL;
		return (NULL);
	}
	tok = nxt + i;
	nxt = tok;
	for (i = 0; nxt[i] != '\0'; i++)
	{
		if (de_lim(nxt[i], delim) == 1)
			break;
	}
	if (nxt[i] == '\0')
		nxt = NULL;
	else
	{
		nxt[i] = '\0';
		nxt = nxt + i + 1;
		if (*nxt == '\0')
			nxt = NULL;
	}
	return (tok);
}
