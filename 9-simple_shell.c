#include "shell.h"

/**
 * _realloc - memory reallocator
 * @ptr: Pointer
 * @old_size: old size
 * @new_size: current size
 * Return: void memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *mem_res;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	mem_res = malloc(new_size);
	if (mem_res == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		array_bytes(mem_res, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(mem_res, ptr, old_size);
		free(ptr);
	}
	return (mem_res);

}

/**
 * free_all - free memory
 * @cmd: command
 * @line: line
 * Return: Void
 */

void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * _memcpy - copies bytes
 * @dest: pointer
 * @src: pointer
 * @n: size of bytes
 * Return: Void Pointer
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
	{
		dest[a] = src[a];
	}
	return (dest);
}

/**
 * array_bytes - bytes of array
 * @x: pointer
 * @d: Integer
 * @len: integer length
 * Return: Void Pointer
 */

void *array_bytes(void *x, int d, unsigned int len)
{
	char *p = x;
	unsigned int n = 0;

	while (n < len)
	{
		*p = d;
		p++;
		n++;
	}
	return (x);
}

/**
 * _calloc -  uses malloc
 * @size: byte size
 * Return: Void Pointer
 */

void *_calloc(unsigned int size)
{
	char *c;
	unsigned int i;

	if (size == 0)
	return (NULL);
	c = malloc(size);
	if (c == NULL)
	return (NULL);
	for (i = 0; i < size; i++)
	{
		c[i] = '\0';
	}
	return (c);
}
