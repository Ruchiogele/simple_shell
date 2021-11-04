#include "shell.h"

/**
 * bui_ex - exit builtin
 * @cmd: Command
 * @input: input
 * @argv: code
 * @c: count execution
 */

void bui_ex(char **cmd, char *input, char **argv, int c)
{
	int sta_tus, f = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][f])
	{
		if (_isalpha(cmd[1][f++]) != 0)
		{
			err_pr(argv, c, cmd);
			break;
		}
		else
		{
			sta_tus = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(sta_tus);
		}
	}
}


/**
 * ch_dir - to switch between directories
 * @cmd: command
 * @er: last executed command
 * Return: Always 0 (success) else, 1
 */

int ch_dir(char **cmd, __attribute__((unused))int er)
{
	int _val = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		_val = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		_val = chdir(getenv("OLDPWD"));
	}
	else
		_val = chdir(cmd[1]);

	if (_val == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (_val != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * dis_env - function to display env. variable
 * @cmd: Command
 * @er: last executed command status
 * Return: Always 0
 */

int dis_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int er)
{
size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * help_dis - help display
 * @cmd: Command
 * @er: last executed command status
 * Return: Always 0, else -1
 */

int help_dis(char **cmd, __attribute__((unused))int er)
{
	int dh, hd, r = 1;
	char c;

	dh = open(cmd[1], O_RDONLY);
	if (dh < 0)
	{
		perror("Error");
		return (0);
	}
	while (r > 0)
	{
		r = read(dh, &c, 1);
		hd = write(STDOUT_FILENO, &c, r);
		if (hd < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}

/**
 * echo_bul - function that handles echo
 * @st: last status
 * @cmd: Command
 * Return: Always 0, else echo
 */

int echo_bul(char **cmd, int st)
{
	char *_pth;
	unsigned int  pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		pr_num_in(st);
		DISPLAY("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		pr_num(pid);
		DISPLAY("\n");

	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		_pth = get_env_name("PATH");
		DISPLAY(_pth);
		DISPLAY("\n");
		free(_pth);

	}
	else
		return (pr_echo(cmd));

	return (1);
}
