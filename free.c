#include "shell.h"
/**
 * freeAll - fee al the buf
 * @buf: an arrays of pointers
 * Return: nothing
 */
void freeAll(char **buf)
{
	int i = 0, cont = 0;

	while (buf[i] != NULL)
		cont++, i++;

	if (buf != NULL)
	{
		while (cont >= 0)
		{
			free(buf[cont]);
			cont--;
		}
		free(buf);
	}
}
/**
 * check - fee al the buf
 * @s: error
 * @buff: an arrays of pointers
 * @buffer: buffer
 * @cont: cont
 * Return: nothing
 */
void check(int s, char **buff, char *buffer, int cont)
{
	if (s == 0 && buff[0][0] != '\n')
		writes0(buff);
	if (s == 3 && buff[0][0] != '\n')
		writes3(buff, cont);
	if (buffer[0] != '\n' && buffer[0] != '\0')
		freeAll(buff);
	free(buffer);
}
