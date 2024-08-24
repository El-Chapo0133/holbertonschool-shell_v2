#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_input.h"
#include "hsh.h"

void remove_coments(char *str)
{
	int index, length = _strlen(str);
	int is_comment = false;
	for (index = 0; index < length; index++)
	{
		if (str[index] == '#')
		{
			str[index] = '\0';
			is_comment = true;
		}
		else if (is_comment)
		{
			str[index] = '\0';
		}
	}
}

char *get_user_input(void)
{
	char *buf = malloc(sizeof(char) * USER_INPUT_MAX_SIZE);
	int index, bits_read;
	char c = 0;

	if (buf == NULL)
	{
		PRINT("Memory error :(");
		return (NULL);
	}

	index = 0;
	while (true)
	{
		fflush(stdin);
		// read 1 char from stdin fd
		bits_read = read(STDIN_FILENO, &c, 1);
		if (bits_read == 0)
		{
			/* problems */
			free(buf);
			exit(END_ERROR);
		}
		/* break when EOF of new-line */
		if (c == EOF || c == '\n')
			break;

		/* in case max-size is exceeded, realloc with new-size */
		if (index >= USER_INPUT_MAX_SIZE)
		{
			buf = realloc(buf, sizeof(char) * (USER_INPUT_MAX_SIZE + index));
			if (buf == NULL)
			{
				PRINT("Memory error :(");
				return (NULL);
			}
		}

		buf[index++] = c;
	}

	remove_coments(buf);

	return (buf);
}

char **tokenize(char *str)
{
	const char *separator = " ";

	int index = 0;
	char **buf = malloc(sizeof(char*) * 1);
	char *token = strtok(str, separator);

	if (token == NULL)
	{
		/* problems :( */
		return (NULL);
	}
	while (true)
	{
		/* set token to buf */
		buf[index] = token;
		index++;

		/* get next token, break if no token */
		token = strtok(NULL, separator);
		if (token == NULL)
			break;

		/* reallocate for next token */
		buf = realloc(buf, sizeof(char*) * (index + 1));
	}

	return (buf);
}

char **get_user_input_tokenized(void)
{
	return (tokenize(get_user_input()));
}
