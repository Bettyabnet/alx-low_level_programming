#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins to make change for an amount of money.
 * @argc: number of arguments
 * @argv: an array of arguments
 *
 * return: always 0 (success), 1 (error)
*/
int main(int argc, char *argv[])
{
	int i, j, k;
	int coin[] = { 25, 10, 5, 2, 1};

	if (argc !=2)
	{
		printf("Error\n");
		return (1);
	}

	i = atoi(argv[1]);
	k = 0;

	if (i < 0)
	{
		printf("0\n");
		return (0);
	}

	for (j = 0; j < 5 && i >= 0; j++)
	{
		while (i >= coin[j])
		{
			k++;
			i -= coin[j];
		}
	}

	printf("%d\n", k);
	return (0);
}
