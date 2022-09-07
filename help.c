#include "shell.h"

/**
 * help - help builtin command
 * @abc: array of functions
 * @cmd: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */

int help(char *cmd, char **abc)
{
	(void)cmd;

	if (abc[1] == NULL)
	{
		help_help(cmd);
		return (7);
	}
	else
	{
		if (abc[1][1] == 'd')
		{
			help_cd(cmd);
			return (7);
		}
		if (abc[1][1] == 'x')
		{
			help_exit(cmd);
			return (7);
		}
		if (abc[1][1] == 'n')
		{
			help_env(cmd);
			return (7);
		}
	}
	return (7);
}
