#include "shell.h"

/**
 * main - main simple_shell code
 * @argc: Argument Count
 * @argv: Argument Value
 * Return: Exit value of sta_tus
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *_inp, **cmd;
	int _count = 0, sta_tus = 1, _xt = 0;

	if (argv[1] != NULL)
		cmd_reader(argv[1], argv);
	signal(SIGINT, sgn_hnd);
	while (sta_tus)
	{
		_count++;
		if (isatty(STDIN_FILENO))
			prompt();
		_inp = read_input();
		if (_inp[0] == '\0')
		{
			continue;
		}
		history(_inp);
		cmd = cmd_sort(_inp);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			bui_ex(cmd, _inp, argv, _count);
		}
		else if (bui_chk(cmd) == 0)
		{
			_xt = bui_hnd(cmd, _xt);
			free_all(cmd, _inp);
			continue;
		}
		else
		{
			_xt = cmd_exe(cmd, _inp, _count, argv);

		}
		free_all(cmd, _inp);
	}
	return (sta_tus);
}

/**
 * bui_chk - function for builtin check
 * @cmd: Command
 * Return: -1
 */

int bui_chk(char **cmd)
{
	bui_lt fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int a = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + a)->command)
	{
		if (_strcmp(cmd[0], (fun + a)->command) == 0)
			return (0);
		a++;
	}
	return (-1);
}

/**
 * env_var_arr - function that creates env. array. variable
 * @_env: evironment variable array
 * Return: Void
 */

void env_var_arr(char **_env)
{
	int i;

	for (i = 0; environ[i]; i++)
		_env[i] = _strdup(environ[i]);
	_env[i] = NULL;
}
