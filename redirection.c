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
		if (cmd[index] == '>' && cmd[index + 1] != NULL)
		{
			fd = open(cmd[index + 1], 0_CREAT);
			dup2(fd, 1);
			close(fd);
			index++;
		}
		else if (cmd[index] == '|' && cmd[index + 1] != NULL)
		{
			fd = open(cmd[index + 1], 0_RDONLY);
			dup2(fd, 0);
			close(fd);
			index++;
		}
	}
}
