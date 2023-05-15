#include "main.h"
#include <stdio.h>
/**
 * main - entry point
 * @argc: No of command line arguments
 * @argv: Array name
 * Return: always 0 (success)
*/
int main(int argc, char *argv[])
{
	int i, j, k;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	i = atoi(argv[1]);
	j = atoi(argv[2]);
	k = i * j;
	printf("%d\n", ans);
	return (0);
}
