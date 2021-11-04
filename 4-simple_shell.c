#include "shell.h"

/**
 * bui_hnd - function for builtins
 * @cmd: Command
 * @er: last status
 * Return: Always 0
 */

int bui_hnd(char **cmd, int er)
{
	 bui_lt b_in[] = {
		{"cd", ch_dir},
		{"env", dis_env},
		{"help", help_dis},
		{"echo", echo_bul},
		{"history", his_display},
		{NULL, NULL}
	};
	int i = 0;

	while ((b_in + i)->command)
	{
		if (_strcmp(cmd[0], (b_in + i)->command) == 0)
		{
			return ((b_in + i)->fun(cmd, er));
		}
		i++;
	}
	return (-1);
}

/**
 * cmd_exe - executes commands
 * @cmd: Command
 * @input: Input
 * @c: case
 * @argv: value
 * Return: 0, success
 */

int cmd_exe(char **cmd, char *input, int c, char **argv)
{
	int ca_se;
	pid_t p_id;

	if (*cmd == NULL)
	{
		return (-1);
	}

	p_id = fork();
	if (p_id == -1)
	{
		perror("Error");
		return (-1);
	}

	if (p_id == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			Pa_th(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&ca_se);
	return (0);
}

/**
 * sgn_hnd - gets signals
 * @sgn: Signal
 * Return: Void
 */

void sgn_hnd(int sgn)
{
	if (sgn == SIGINT)
	{
		DISPLAY("\n$ ");
	}
}
