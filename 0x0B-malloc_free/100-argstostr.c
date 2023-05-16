#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all arguments of the program into a string;
 *             arguments are separated by a new line in the string.
 * @ac: The number of arguments passed to the program.
 * @av: An array of pointers to the arguments.
 *
 * Return: If ac == 0, av == NULL, or the function fails - NULL.
 *         Otherwise - a pointer to the new string.
 */
char *argstostr(int ac, char **av)
{
	int i = 0, j = 0, k = 0, l = 0;
char *ch;

	if (ac == 0 || av == NULL)
	return (NULL);
		for (; i < ac; i++)
		{
		j = 0;
			for (; av[i][j] != '\0'; j++)
			k++;
		}
ch = malloc(k + ac + 1 * sizeof(char));
	if (ch == NULL)
	return (NULL);
		for (i = 0; i < ac; i++)
		{
		j = 0;
			for (; av[i][j] != '\0'; j++)
			{
			ch[l] = av[i][j];
			l++;
			}
		ch[l] = '\n';
		l++;
		}
return (ch);
}
