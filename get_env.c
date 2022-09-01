#include "shell.h"

/**
 * get_env - get a specific pointer of the env
 * @path: the data to loocking for
 * Return: a pointer to the data in the environ
 */

char *get_env(char *path)
{
	size_t i = 0, j;
	int cont, flag = 0;

	for (; environ[i] != NULL; i++)
	{
		for (j = 0, cont = 0; environ[i][j] == path[j]; ++cont, j++)
		{
			if (cont == 2)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}
	return (environ[i]);
}

/**
 * get_pwd - create a copy of the path pointer of the env
 * Return: a pointer to the data in the environ
 */

char *get_pwd(void)
{
	size_t i = 0, j;
	int cont, flag = 0;
	char *path = "PWD=";

	for (; environ[i] != NULL; i++)
	{
		for (j = 0, cont = 0; environ[i][j] == path[j]; ++cont, j++)
		{
			if (cont == 2)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}
	return (cpstring(environ[i]));
}

/**
 * get_env1 - get a specific pointer of the env
 * Return: a pointer to the data in the environ
 */

int get_env1(void)
{
	size_t i = 0;

	for (; environ[i] != NULL; i++)
	{
	}
	return (i);
}
