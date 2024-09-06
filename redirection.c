#include "redirection.h"


/**
 * find_redirection - find the redirection in command
 * @cmd: command passed
 *
 * Return: struct with both redirection or NULL
 */
struct RedirectTo *find_redirections(char **cmd)
{
	RedirectTo *redirect = malloc(sizeof(RedirectTo));
	int index, fd;

	if (redirect == NULL)
		return (NULL);

	for (index = 0; cmd[index] != NULL; index++)
	{
		if (cmd[index] == '>' && cmd[index + 1] != NULL)
		{
			redirect->to = cmd[index + 1]
			index++;
		}
		else if (cmd[index] == '|' && cmd[index + 1] != NULL)
		{
			redirect->from = cmd[index + 1];
			index++;
		}
	}

	return (redirect);
}

/**
 * handle_redirections - handle the redirection based on command
 * @cmd: command passed
 *
 * Return: void
 */
void handle_redirections(char **cmd)
{
	RedirecTo *redirect = find_redirections(cmd);

	if (redirect == NULL)
		return;
	if (redirect->to != NULL)
	{
		fd = open(redirect->to, 0_CREAT);
		dup2(fd, 1);
		close(fd);
	}
	else if (redirect->from != NULL)
	{
		fd = open(redirect->from, 0_RDONLY);
		dup2(fd, 0);
		close(fd);
	}
}
