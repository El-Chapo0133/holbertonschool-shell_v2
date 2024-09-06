#include "execute_built_in.h"


/**
 * execute_built_in - execute built in function
 * @cmd: command passed
 *
 * Return: -1 if error, 0 if success
 */
int execute_built_in(char **cmd)
{
	int index;
	struct BuiltIn **built_in = malloc(5 * sizeof(BuiltIn));

	if (built_in == NULL)
		return (-1);
	built_in[0]->cmd = "cd";
	built_in[0]->fun = change_dir;
	built_in[0]->cmd = "echo";
	built_in[0]->fun = echo;
	built_in[0]->cmd = "help";
	built_in[0]->fun = print_help;
	built_in[0]->cmd = "history";
	built_in[0]->fun = print_history;
	built_in[0]->cmd = "env";
	built_in[0]->fun = env;

	if (_strcmp(cmd[0], "exit") == 0)
		return (1);
	for (index = 0; index < 5; index++)
		if (_strcmp(built_in[index]->cmd, cmd[0]) == 0)
			return ((built_in[index])->fun(cmd));
	return (-1);
}
