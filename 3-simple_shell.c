#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strncpy - string copy
 * @dest: character
 * @src: character
 * @n: integer
 * Return: character
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	while (i < n && *(src + i))
	{
	*(dest + i) = *(src + i);
	i++;
	}
	while (i < n)
	{
	*(dest + i) = '\0';
	i++;
	}
	return (dest);
}

/**
 * _strlen - string length
 * @s: character
 * Return: integer
 */

int _strlen(char *s)
{
	int i;

		for (i = 0; s[i] != '\0'; i++)
		{
			continue;
		}
		return (i);
}

/**
 * _atoi - integer converter
 * @s: string
 * Return: integer
 */

int _atoi(char *s)
{
int i, d, n, a;

	i = n = 0;
	a = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			a *= -1;
		i++;
	}
	d = i;
	while ((s[d] >= '0') && (s[d] <= '9'))
	{
		n = (n * 10) + a * ((s[d]) - '0');
		d++;
	}
	return (n);
}

/**
 * _puts - print a string
 * @str: character pointer
 * return: void
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
_putchar('\n');
return;
}
