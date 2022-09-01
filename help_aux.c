#include "shell.h"

void help_cd(char *cmd)
{
	char *file;
	int fd, r;
	char *s;

	if (strcmp(cmd, "cd"))
	{
		file = "help_cd";
		fd = open(file, O_RDWR);
		s = malloc(256);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
		}
		free(s);
		fd = close(fd);
	}
}

void help_exit(char *cmd)
{
	char *file;
	int fd, r;
	char *s;

	if (strcmp(cmd, "exit"))
	{
		file = "help_exit";
		fd = open(file, O_RDWR);
		s = malloc(256);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
		}
		free(s);
		fd = close(fd);
	}
}

void help_env(char *cmd)
{
	char *file;
	int fd, r;
	char *s;

	if (strcmp(cmd, "env"))
	{
		file = "help_env";
		fd = open(file, O_RDWR);
		s = malloc(256);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
		}
		free(s);
		fd = close(fd);
	}
}

void help_help(char *cmd)
{
	char *file;
	int fd, r;
	char *s;

	if (strcmp(cmd, "help"))
	{
		file = "help_help";
		fd = open(file, O_RDWR);
		s = malloc(256);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
		}
		free(s);
		fd = close(fd);
	}
}
