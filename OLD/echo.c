#include "echo.h"

/**
 * echo - write to stdout arguments
 * @cmd: command passed
 *
 * Return: -1 if error, 0 if success
 */
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
