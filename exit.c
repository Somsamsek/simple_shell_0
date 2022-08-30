#include "shell.h"

/**
 * sigintHandler - avoid ctrl + c
 * @sig_num: value that received
 * Return: nothing
 */

void sigintHandler(int sig_num __attribute__((unused)))
{
	write(1, "\nNew shell $ ", 13);
}
