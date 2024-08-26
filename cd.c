#include "cd.h"


char *define_target_dir(char **cmd)
{
	if (cmd[1] == NULL)
		return (getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
		return (getenv("OLDPWD"));
	else
		return (cmd[1]);
}

int change_dir(char **cmd)
{
	int status;
	char *current_pwd, *target_dir;

	if (cmd == NULL || cmd[1] == NULL)
		return (-1);

	target_dir = define_target_dir(cmd);
	if (_strcmp(target_dir, "-") == 0)
	{
		target_dir = getenv("OLDPWD");
		if (target_dir == NULL)
			return (-1);
	}

	current_pwd = getenv("PWD");
	if (current_pwd == NULL)
		return (-1);
	status = setenv("OLD_PWD", current_pwd, 1);
	if (status != 0)
		return (status);

	status = chdir(target_dir);
	if (status != 0)
		return (status);
	status = setenv("PWD", target_dir, 1);

	return (status);
}
