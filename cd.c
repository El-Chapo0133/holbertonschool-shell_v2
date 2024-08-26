#include "cd.h"

int change_dir(char **cmd)
{
	int status;

	if (cmd == NULL || cmd[1] == NULL)
		return (-1);

	status = chdir(cmd[1]);

	return (status);
}
