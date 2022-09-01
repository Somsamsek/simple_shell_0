#include "shell.h"

/**
 * count - count the number of words
 * @buff: data catched for the getline
 * @l: delimiter
 * Return: a duble poirnte to the buffer
 */

int count(char *buff, char *l)
{
	int i = 0, j = 0;

	if (l != NULL)
	{
		while (buff && buff[i] != '\0')
		{
			if (buff[i] != l[0] && buff[i] != '\n')
			{
				if (buff[i + 1] == l[0] || buff[i + 1] == '\0'
						|| buff[i + 1] == '\n')
					j++;
			}
			i++;
		}
	}
	return (j);
}

/**
 * getargs - create a arrays of pointer with all the arguments
 * @buffer: data catched for the getline
 * Return: a double pointer to the buffer
 */

char **getargs(char *buffer)
{
	char **buff = NULL, *token;
	size_t cont = 0, i, y = 0;

	cont = count(buffer, " ");
	buff = malloc(sizeof(char *) * (cont + 1));
	if (!buff)
	{
		free(buffer);
		free(buff);
		exit(0);
	}
	token = _strtok(buffer, " ");
	while (token != NULL && token[0] != '\n')
	{
		buff[y] = _calloc((_strlen(token) + 1), sizeof(char));
		if (buff[y] == NULL)
		{
			free(buffer);
			freeAll(buff);
			exit(0);
		}
		for (i = 0; i <= (_strlen(token) - 1); i++)
			buff[y][i] = token[i];
		if (buff[y][i - 1] == '\n')
			buff[y][i - 1] = '\0';
		else
			buff[y][i] = '\0';
		y++;
		token = _strtok(NULL, " ");
	}
	buff[y] = NULL;
	return (buff);
}
