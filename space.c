#include "shell.h"
/**
 * spaces - remove the spaces at the begining of the buffer
 * @buffer: buffer
 * Return: the same buffer without spaces
 */
void spaces(char *buffer)
{
	int i = 0, j = 0;

	if (buffer[i] == 32 || buffer[i] == 9)
	{
		while (buffer[i] == 32 || buffer[i] == 9)
		{
			i++;
		}
		while (buffer[i] != '\0')
		{
			buffer[j] = buffer[i];
			i++;
			j++;
		}
		while (buffer[j] != '\0')
		{
			buffer[j] = '\0';
		}
	}
}
/**
 * cpstring - create a exact copy os a string
 * @path: the string to copy
 * Return: the copied string
 */
char *cpstring(char *path)
{
	char *cpath;
	int i = 0;

	cpath = _calloc((_strlen(path) + 1), sizeof(char));
	if (!cpath)
	{
		free(cpath);
		return (cpath);
	}
	while (path[i] != '\0')
	{
		cpath[i] = path[i];
		i++;
	}

	return (cpath);
}
/**
 * cd_fun - cd function
 * @buff: an arrays of pointers
 * @buffer: buffer
 * Return:1 with success and 0 in error
 */
int cd_fun(char *buff __attribute__((unused)), char **buffer)
{
	char *dir, *pwd;
	unsigned int i, cont, flag = 0;

	pwd = get_pwd(), pwd = _strtok(pwd, "="), pwd = _strtok(NULL, "\0");
	if (buffer[1] == NULL)
		chdir("/home");
	else
	{
		if (buffer[1][0] == '.' && buffer[1][1] == '.' && buffer[1][2] == '\0')
			dir = "..";
		else if (buffer[1][0] == '-' && buffer[1][1] == '\0')
			dir = oldpwd();
		else if (buffer[1][0] == '/')
		{
			i = 0, cont = 0;
			while (buffer[1][i] == pwd[i])
			{
				cont++;
				if (cont == _strlen(buffer[1]))
					dir = buffer[1], flag = 1;
				i++;
			}
			if (!flag)
			{
				return (0);
			}
		}
		else
			dir = str_concat("./", buffer[1]);
		if (chdir(dir) == -1)
		{
			return (0);
		}
	}
	getcwd(pwd, 1024);
	changepwd(pwd);
	return (1);
}
/**
 * changepwd - change pwd and oldpwd
 * @pwd:pwd
 * Return: nothing
 */
void changepwd(char *pwd)
{
	int j, z;
	char *OLDPWD, *PWD;

	PWD = get_env("PWD=");
	OLDPWD = get_env("OLDPWD=");
	for (j = 4, z = 7; PWD[j] != '\0'; j++, z++)
		OLDPWD[z] = PWD[j];
	while (OLDPWD[z] != '\0')
		OLDPWD[z] = '\0', z++;
	for (j = 4, z = 0; pwd[z] != '\0'; j++, z++)
		PWD[j] = pwd[z];
	while (PWD[j] != '\0')
		PWD[j] = '\0', j++;
}
/**
 * oldpwd - function cd
 * Return: nothing
 */
char *oldpwd(void)
{
	char *OLDPWD, *copy;
	int len, x = 0;

	OLDPWD = get_env("OLDPWD=");
	len = _strlen(OLDPWD);
	copy = malloc(len * sizeof(char));

	while (OLDPWD[x] != '\0')
		copy[x] = OLDPWD[x], x++;
	copy = _strtok(copy, "=");
	copy = _strtok(NULL, "\0");
	return (copy);
}
