#include "shell.h"

/**
 * cmd_reader - command reader
 * @filename: name of file
 * @argv: value
 * Return: Always 0
 */

void cmd_reader(char *filename, char **argv)
{
	FILE *fp;
	char *ln = NULL;
	size_t len = 0;
	int _count = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&ln, &len, fp)) != -1)
	{
		_count++;
		fil_exec(ln, _count, fp, argv);

	}
	if (ln)
		free(ln);
	fclose(fp);
	exit(0);
}

/**
 * fil_exec - executes file
 * @line: file line
 * @counter: counts error
 * @fp: describes file
 * @argv: value
 * Return: void
 */

void fil_exec(char *line, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int st = 0;

	cmd = cmd_sort(line);

		if (_strncmp(cmd[0], "exit", 4) == 0)
		{
			shell_exit(cmd, line, fp);
		}
		else if (bui_chk(cmd) == 0)
		{
			st = bui_hnd(cmd, st);
			free(cmd);
		}
		else
		{
			st = cmd_exe(cmd, line, counter, argv);
			free(cmd);
		}
}

/**
 * shell_exit - function to exit from shell
 * @line: line of file
 * @cmd: Command
 * @fd: describes file
 * Return : Case
 */

void shell_exit(char **cmd, char *line, FILE *fd)
{
	int sta_tus, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	sta_tus = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(sta_tus);
}
