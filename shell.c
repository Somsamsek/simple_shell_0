#include "shell.h"
/**
 * main - execute a simple shell
 * Return: nothing
 */
int main(void)
{
	char *buffer = NULL, **buff = NULL, *path, *cpath;
	ssize_t d = 0;
	size_t bufsize = (4096 * 2);
	int status, s = 5, cont = 0, e = 0, en = 0;

	while (1)
	{
		signal(SIGINT, sigintHandler), prompt();
		buffer = _calloc(bufsize, sizeof(char));
		if (buffer == NULL)
			free(buffer), ret();
		d = getline1(&buffer, &bufsize, stdin);
		if (d == -1 || d == EOF)
			free(buffer), ret();
		s = 5, cont++, spaces(buffer);
		en = get_env1();
		if (environ[0] != NULL && en == 38)
			path = get_env("PATH="), cpath = cpstring(path),
				buffer = compare_path(buffer, cpath);
		if (buffer[0] != '\n' && buffer[0] != '\0')
		{
			buff = getargs(buffer);
			if (buff == NULL)
				free(buffer), freeAll(buff), ret();
			if (buff[0] != NULL)
				s = coincidence(buff, buffer);
		}
		if (s == -1 && buff[0] != NULL && fork() == 0)
		{
			status = execve(buff[0], buff, environ);
			if (status == -1 && buff[0] != NULL)
				writeexe(buff, cont);
			freeAll(buff), free(buffer), ret();
		}
		else
			wait(&e), extstatus(&e);
		check(s, buff, buffer, cont);
	}
	return (0);
}
/**
 * ret - return function
 *return: nothing
 */
void ret(void)
{
	exit(0);
}
/**
 * extstatus - status function
 * @p: status error
 * Return: status
 */
int extstatus(int *p)
{
	static int status;

	if (p != NULL)
		status = *p;
	return (status);
}
/**
 * writeexe - writes if not found
 * @buff: buffer
 * @cont: cont
 *return: nothing
 */
void writeexe(char **buff, int cont)
{
	char *p;

	_puts2("hsh: ");
	p = unatoi(cont);
	_puts2(p);
	_puts2(" ");
	_puts2(buff[0]);
	_puts2(": not found");
	_puts2("\n");
	free(p);
}
/**
 * writes0 - writes if not file
 * @buff: buffer
 *return: nothing
 */
void writes0(char **buff)
{
	_puts2("hsh: cd: ");
	_puts2(buff[1]);
	_puts2(": No such file or directory");
	_puts2("\n");
}
