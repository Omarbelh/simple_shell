#include "shell.h"

/**
 * _myexit - exits the shell
 * @customInfo: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if customInfo->argv[0] != "exit"
 */
int _myexit(info_t *customInfo)
{
	int exitCheck;

	if (customInfo->argv[1]) /* If there is an exit argument */
	{
		exitCheck = _erratoi(customInfo->argv[1]);
		if (exitCheck == -1)
		{
			customInfo->status = 2;
			print_error(customInfo, "Invalid number: ");
			_eputs(customInfo->argv[1]);
			_eputchar('\n');
			return (1);
		}
		customInfo->err_num = _erratoi(customInfo->argv[1]);
		return (-2);
	}
	customInfo->err_num = -1;
	return (-2);
}

/**
 * _mycd - alters the current directory of the process
 * @customInfo: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _mycd(info_t *customInfo)
{
	char *s, *dir, buffer[1024];
	int chdirRet;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!customInfo->argv[1])
	{
		dir = _getenv(customInfo, "HOME=");
		if (!dir)
			chdirRet = /* TODO: what should this be? */
				chdir((dir = _getenv(customInfo, "PWD=")) ? dir : "/");
		else
			chdirRet = chdir(dir);
	}
	else if (_strcmp(customInfo->argv[1], "-") == 0)
	{
		if (!_getenv(customInfo, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(customInfo, "OLDPWD=")), _putchar('\n');
		chdirRet = /* TODO: what should this be? */
			chdir((dir = _getenv(customInfo, "OLDPWD=")) ? dir : "/");
	}
	else
		chdirRet = chdir(customInfo->argv[1]);
	if (chdirRet == -1)
	{
		print_error(customInfo, "can't cd to ");
		_eputs(customInfo->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(customInfo, "OLDPWD", _getenv(customInfo, "PWD="));
		_setenv(customInfo, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - alters the current directory of the process
 * @customInfo: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhelp(info_t *customInfo)
{
	char **argArray;

	argArray = customInfo->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*argArray); /* temp att_unused workaround */
	return (0);
}
