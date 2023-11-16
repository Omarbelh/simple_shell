#include "shell.h"

/**
 * _myenv - prints the current environment
 * @customInfo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *customInfo)
{
	print_list_str(customInfo->env);
	return (0);
}

/**
 * _getenv - gets the value of an environment variable
 * @customInfo: Structure containing potential arguments. Used to maintain
 * @name: environment variable name
 *
 * Return: the value
 */
char *_getenv(info_t *customInfo, const char *name)
{
	list_t *node = customInfo->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @customInfo: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *customInfo)
{
	if (customInfo->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(customInfo, customInfo->argv[1], customInfo->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @customInfo: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *customInfo)
{
	int i;

	if (customInfo->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i <= customInfo->argc; i++)
		_unsetenv(customInfo, customInfo->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates environment linked list
 * @customInfo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *customInfo)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	customInfo->env = node;
	return (0);
}
