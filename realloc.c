#include "shell.h"

/**
 * _realloc - reallocates a memory block using malloc
 * @ptr: pointer to the memory previously allocated
 * @old_size: the size in bytes of the allocated space
 * @new_size: the new size
 * Return: a pointer to newly space memory.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p = NULL;
	char *s, *d;
	unsigned int x, y;

	if (old_size == new_size)
		return (ptr);
	if (ptr == 0)
	{
		p = malloc(new_size);
		return (p);
	}
	if (new_size == 0 && ptr != 0)
		free(ptr);
	d = (char *)ptr;
	if (new_size < old_size)
	{
		y = old_size;
		for (; y > new_size; y--)
			free(d + y);
	}
	p = malloc(new_size);
	if (p == 0)
		return (NULL);
	s = (char *)p;
	for (x = 0; x < old_size; x++)
		s[x] = d[x];
	free(ptr);
	return (s);
}
