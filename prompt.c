#include "shell.h"

/**
 * prompt - print a prompt
 * Return - nothing
 */

void prompt(void)
{
	write(STDIN_FILENO, "New shell $ ", 12);
}
