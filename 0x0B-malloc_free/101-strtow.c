#include "main.h"
#include <stdlib.h>

/**
 * ch_free_grid - frees a 2 dimensional array.
 * @grid: multidimensional array of char.
 * @height: height of the array.
 *
 * Return: no return
 */
char **strtow(char *str)
{
	 if (str == NULL || str[0] == '\0') 
	 {
		 return NULL;
	 }
	 int num_words = 0;
	 for (int i = 0; str[i] != '\0'; i++) {
		 if (str[i] == ' ')
		 {
			 num_words++;
		 }
	 }
	 char **words = malloc(sizeof(char *) * (num_words + 1));
	 if (words == NULL)
	 {
		 return NULL;
	 }

	 int word_index = 0;
	 for (int i = 0; str[i] != '\0'; i++)
	 {
		 if (str[i] == ' ')
		 {
			 words[word_index++] = strndup(str + i + 1, strlen(str + i + 1));
		 }
	 }
	 words[word_index] = NULL;

	 return words;
}
