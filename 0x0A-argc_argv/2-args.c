#include <stdio.h>
#include "main.h"
/**
 * main - prints all arguments it receives.
 * @argc: counts an argument passed on the program
 * @argv: an array of strings
 *
 * return: always 0 (success)
*/
int main(int argc __attribute__((unused)), char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
