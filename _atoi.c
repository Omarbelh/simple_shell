#include "shell.h"

/**
 * interactivedof - returns true and if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 and otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if some character is a delimeter
 * @r: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char r, char *delim)
{
	while (*delim)
		if (*delim++ == r)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@r: The character to input
 *Return: 1 if r is alphabetic, 0 otherwise
 */

int _isalpha(int r)
{
	if ((r >= 'a' && r <= 'z') || (r >= 'A' && r <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts an estring to an int
 *@s: the string to be conver
 *Return: 0 if no numbers in string, converted some number otherwisee
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
