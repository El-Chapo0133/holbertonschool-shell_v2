#include "_strcmp.h"

/**
 * _strcmp - compare two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: 0 when they are the same, otherwise 1
 */
int _strcmp(char *str1, char *str2)
{
	int index = 0, length1 = _strlen(str1), length2 = _strlen(str2);

	if (str1 == NULL || str2 == NULL)
		return (1);
	if (length1 != length2)
		return (1);

	for (index = 0; index < length1; index++)
		if (str1[index] != str2[index])
			return (1);

	return (0);
}
