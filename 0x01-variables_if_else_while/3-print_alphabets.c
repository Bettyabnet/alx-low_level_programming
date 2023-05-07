#include <stdio.h>

/**
 * main - Prints the alphabet.
 * 
 * Return: Always 0 (Success)
*/
int main(void)
{
	char i;
	char j;

	for (i = 97; i < 123; i++)
	{
		putchar(i);
	}
	for (j = 65; j < 91; j++)
	{
		putchar(j);
	}
	putchar('\n');
	return (0);
}
