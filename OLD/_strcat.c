#include "_strcat.h"

/**
 * _strcat - concatenate an array of strings to
 *	one string separated with spaces
 * @strings: array of strings to concatenate
 *
 * Return: a string
 */
char *_strcat(char **strings)
{
	char *buf = malloc(sizeof(char) * USER_INPUT_MAX_SIZE);
	int index = 0, c_index = 0, s_index;

	if (strings == NULL)
		return (NULL);
	while (strings[index] != NULL)
	{
		for (s_index = 0;
			s_index < _strlen(strings[index]);
			s_index++)
		{
			if (c_index >= USER_INPUT_MAX_SIZE)
				buf = realloc(buf, sizeof(char) * c_index);
			buf[c_index++] = strings[index][s_index];
		}
		if (strings[++index] != NULL)
		{
			if (c_index >= USER_INPUT_MAX_SIZE)
				buf = realloc(buf, sizeof(char) * c_index);
			buf[c_index++] = ' ';
		}
	}

	return (buf);
}
