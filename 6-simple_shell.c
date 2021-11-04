#include "shell.h"

/**
 * Pa_th -  searches $PATH
 * @cmd: comand
 * Return: Always 0
 */

int Pa_th(char **cmd)
{
	char *pa_th, *v, *cmpth;
	struct stat buf;

	pa_th = get_env_name("PATH");
	v = str_tok(pa_th, ":");
	while (v != NULL)
	{
		cmpth = cmd_retrv(*cmd, v);
		if (stat(cmpth, &buf) == 0)
		{
			*cmd = _strdup(cmpth);
			free(cmpth);
			free(pa_th);
			return (0);
		}
		free(cmpth);
		v = str_tok(NULL, ":");
	}
	free(pa_th);

	return (1);
}

/**
 * cmd_retrv - retreiver
 * @token: token
 * @value: dir
 * Return: command path
 */

char *cmd_retrv(char *token, char *value)
{
	char *cmd;
	size_t lgt;

	lgt = _strlen(value) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * lgt);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, lgt);

	cmd = _strcat(cmd, value);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd);
}

/**
 * get_env_name - get name of env. var.
 * @name: env. var.
 * Return: value
 */

char *get_env_name(char *name)
{
	size_t e_n, e_v;
	char *value;
	int i, d, n;

	e_n = _strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], e_n) == 0)
		{
			e_v = _strlen(environ[i]) - e_n;
			value = malloc(sizeof(char) * e_v);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			n = 0;
			for (d = e_n + 1; environ[i][d]; d++, n++)
			{
				value[n] = environ[i][d];
			}
			value[n] = '\0';

			return (value);
		}
	}

	return (NULL);
}
