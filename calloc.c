#include "shell.h"

/**
 * _calloc - create a malloc and set all positions at '\0'
 * @nmemb: # of positions
 * @size: size of type of data
 * Return: a pointer to the first element of the alocation
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p = NULL;
	unsigned int x;

	if (nmemb == 0 || size == 0)
		return (p);
	p = malloc(nmemb * size);
	if (p == 0)
		return (NULL);
	for (x = 0; x < (nmemb * size); x++)
		*(p + x) = '\0';
	return (p);
}
