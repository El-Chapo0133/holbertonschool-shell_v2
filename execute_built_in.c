#include "execute_built_in.h"


/**
 * execute_built_in - execute built in function
 * @cmd: command passed
 *
 * Return: -1 if error, 0 if success
 */
int execute_built_in(char **cmd)
{
	struct *BuiltIn built_in = malloc(5 * sizeof(BuiltInt));

	if (built_in == NULL)
		return (-1);
	built_in[0] = { "cd", change_dir };
	built_in[1] = { "echo", echo };
	built_in[2] = { "help", print_help };
	built_in[3] = { "history", print_history };
	built_in[4] = { "env", env };

	int index;

	if (_strcmp(cmd[0], "exit") == 0)
		return (1);
	for (index = 0; index < 5; index++)
		if (_strcmp(built_in[index].cmd, cmd[0]) == 0)
			return ((built_in[index]).fun(cmd));
	return (-1);
}
