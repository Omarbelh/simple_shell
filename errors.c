#include "shell.h"

/**
 * _eputs - prints an input string
 * @customStr: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *customStr)
{
	int i = 0;

	if (!customStr)
		return;
	while (customStr[i] != '\0')
	{
		_eputchar(customStr[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char customC)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (customC == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (customC != BUF_FLUSH)
		buf[i++] = customC;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @customC: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char customC, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (customC == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (customC != BUF_FLUSH)
		buf[i++] = customC;
	return (1);
}

/**
 * _putsfd - prints an input string
 * @customStr: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of characters put
 */
int _putsfd(char *customStr, int fd)
{
	int i = 0;

	if (!customStr)
		return (0);
	while (*customStr)
	{
		i += _putfd(*customStr++, fd);
	}
	return (i);
}
