#include "main.h"
/**
 * _isalpha - checks for alphabetic character
 *  @c: the character to be checked
 * _isalpha  return: 1 if c is a letter, otherwise put 0.
**/
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
