#include <stdio.h>
#include "main.h"
/**
 * main - prints the number of arguments passed into it.
 * @argc: counts an argument passed on the program
 * @argv: an array of strings
 *
 * return: always 0 (success)
*/
int main(int argc, char *argv[])
{
	(void) argv;
		printf("%d\n", argc - 1);

		return (0);
}
