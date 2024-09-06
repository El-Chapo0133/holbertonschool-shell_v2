#include "exit.h"

int call_exit(char **cmd)
{
	int code;

	if (cmd[1] == NULL)
		code = 0;
	else
		code = _atoi(cmd[1]);

	exit(code);
}
