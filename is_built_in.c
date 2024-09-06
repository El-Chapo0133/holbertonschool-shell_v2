#include "is_built_in.h"

/**
 * check_is_built_in - check if a function is built in
 * @str: function to check
 *
 * Return: 1 when is built in, othersie 0
 */
int check_is_built_in(char *str)
{
	char *functions[] = { "exit", "cd", "help", "echo", "history", "env" };
	int index;

	for (index = 0; index < 6; index++)
		if (_strcmp(functions[index], str) == 0)
			return (true);
	return (false);
}
