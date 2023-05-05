#include "main.h"
/**
 * _strncat - concatenate two strings
 * using at most n bytes from src
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: dest
*/
char *_strncat(char *dest, char *src, int n)
{
	int A;
	int B;

	A = 0;
	while (dest[A] != '\0')
	{
		A++;
	}

	B = 0;
	while (B < n && src[B] != '\0')
	{
		dest[A] = src[B];
		A++;
		B++;
	}

	dest[A] = '\0';
	return (dest);
}
