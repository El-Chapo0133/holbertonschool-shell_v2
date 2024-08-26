#include "exec_bin.h"

int execute_bin(char **cmd)
{
	pid_t pid;
	int cmd_length = 0, index, status;
	char **arguments;

	if (cmd == NULL || cmd[1] == NULL)
		return (-1);

	/* Build the argument list as execvp want it */
	while (cmd[cmd_length++] != NULL);

	arguments = malloc(sizeof(char*) * (cmd_length + 1));
	if (arguments == NULL) /* Memory error :( */
		return (-1);
	
	for (index = 0; index < cmd_length; index++)
		arguments[index] = cmd[index];

	pid = fork();
	if (pid == -1) /* Problems :( */
		return (-1);
	if (pid == 0)
	{
		/* child process */
		status = execvp(cmd[0], arguments);
		if (status == -1)
		{
			PRINT(cmd[0]);
			PRINT(" command not found\n");
			return (-1);
		}

		return (0);
	}
	return (0);
}
