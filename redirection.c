#include "redirection.h"

/**
 * handle_redirections - handle the redirection based on command
 * @cmd: command passed
 *
 * Return: void
 */
void handle_redirections(char **cmd)
{
	int index, fd;
	for (index = 0; cmd[index] != NULL; index++)
	{
		if (_strcmp(cmd[index], ">") == 0 && cmd[index + 1] != NULL)
		{
			fd = open(cmd[index + 1], O_CREAT);
			dup2(fd, 1);
			close(fd);
			index++;
		}
		else if (_strcmp(cmd[index], "|") == 0 && cmd[index + 1] != NULL)
		{
			fd = open(cmd[index + 1], O_RDONLY);
			dup2(fd, 0);
			close(fd);
			index++;
		}
	}
}
