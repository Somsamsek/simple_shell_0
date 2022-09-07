#include "shell.h"
/**
*help_cd - function  helps cd command to actualize its function
*@cmd: a pointer to a file directory passed
*/
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
/**
*help_exit - this checks the file and command passed for exit function
*@cmd: command passed
*/
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
/**
*help_env - this compares the command passed with the name of command
*@cmd: command passed
*/
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
/**
*help_help - it compares the command passed with actuall command name
*@cmd: command passed
*/
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
