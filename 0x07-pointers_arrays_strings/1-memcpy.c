#include "main.h"
/**
 * _memcpy - a function that copies memory area
 * @dest: memory where is stored
 * @src: memory where is copied
 * @n: number of bytes
 *
 * return: copied memory with n bytes changed
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int a = 0;
	int b = n;

	for (;a < b; a++)
	{
		dest[a] = src[a];
		b--;
	}
	return (dest);
}
