#include "is_built_in.h"

/**
 * is_built_in - check if a function is built in
 * @str: function to check
 *
 * Return: 1 when is built in, othersie 0
 */
int check_is_built_in(char *str)
{
	char *functions[] = { "cd", "help", "echo", "history" };
	int index;
	for (index = 0; index < 4; index++)
		if (_strcmp(functions[index], str) == 0)
			return (true);
	return (false);
}
