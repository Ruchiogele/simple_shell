#include "shell.h"

/**
 * pr_num - displays numbers
 * @n: int
 * Return: Void
 */

void pr_num(unsigned int n)
{
	unsigned int a = n;

	if ((a / 10) > 0)
		pr_num(a / 10);

	_putchar(a % 10 + '0');
}

/**
 * pr_num_in - print numbers
 * @n: int
 * Return: void
 */

void pr_num_in(int n)
{
	unsigned int a = n;

	if (n < 0)
	{
		_putchar('-');
		a = -a;
	}
	if ((a / 10) > 0)
		pr_num(a / 10);

	_putchar(a % 10 + '0');
}
