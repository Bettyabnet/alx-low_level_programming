#include "main.h"
/**
 *  _strcat - concatenates two strings
 *  @src: input value
 *  @dest: input value
*/
char *_strcat(char *dest, char *src)
{
	int T;
	int K;

	T = 0;
	while (dest[T] != '\0')
	{
		T++;
	}
	K = 0;
	while (src[K] != '\0')
	{
		dest[T] = src[K];
		T++;
		K++;
	}

	dest[T] = '\0';
	return (dest);
}
