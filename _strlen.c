#include "_strlen.h"

/**
 * _strlen - count the quantity of char in string
 * @str: string to count chars
 *
 * Return: quantity of char
 */
int _strlen(char *str)
{
	int index;

	for (index = 0; str[index] != '\0'; index++);
	return (index);
}
