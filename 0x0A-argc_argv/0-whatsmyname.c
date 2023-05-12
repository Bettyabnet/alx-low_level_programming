#include <stdio.h>
#include "main.h"

/**
 * main prints its name
 * @argc: counts an argument passed on the program
 * @argv: an array of strings
 *
 * return: 0.
*/
int main(int argc __attribute__((unused)), char *argv[])
{
	printf ("%s\n", *argv);
	return (0);
}
