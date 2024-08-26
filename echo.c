#include "echo.h"

int echo(char **cmd)
{
	int index = 1;

	if (cmd == NULL)
		return (-1);

	while (cmd[index] != NULL)
	{
		PRINT(cmd[index]);
		PRINT(" ");

		index++;
	}
	PRINT("\n");

	return (0);
}
