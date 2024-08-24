#include "execute_built_in.h"


int execute_built_in(char **cmd)
{
	struct BuiltIn built_in[4] = {
		{ "cd", change_dir },
		{ "echo", echo },
		{ "help", print_help },
		{ "history", print_history }
	};

	int index;
	for (index = 0; index < 4; index++)
	{
		if (_strcmp(built_in[index].cmd, cmd[0]) == 0)
		{
			return ((built_in[index]).fun(cmd));
		}
	}
	return (-1);
}
