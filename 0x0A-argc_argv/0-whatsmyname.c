#include <stdio.h>
#include "main.h"

/**
 * main - prints its name
 * @argc: counts an argument passed on the program
 * @argv: an array of strings
 *
 * return: always 0 (success)
*/
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}
