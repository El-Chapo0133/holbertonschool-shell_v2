#include "help.h"

int print_help(char **cmd)
{
	DIR *d;
	struct dirent *dir;
	int index = 0;

	if (cmd == NULL)
		return (-1);

	d = opendir("/bin");
	
	PRINT("=================== HSH Help ===================\n\n");
	PRINT(" > cd : change directory\n");
	PRINT(" > echo : echo a text\n");
	PRINT(" > history : print commands history\n");
	PRINT(" > help : print help\n");
	PRINT(" > env : print or add a environnement variable\n");
	
	if (d)
	{
		PRINT("\n================= BIN Commands =================\n");
		while ((dir = readdir(d)) != NULL) {
			if (_strcmp(dir->d_name, ".") == 0 || _strcmp(dir->d_name, "..") == 0 || _strcmp(dir->d_name, "[") == 0)
				continue;
			
			/* print result in 3 rows */
			PRINT(" ");
			PRINT(dir->d_name);
			if (++index % 3 == 0)
				PRINT("\n");
			else
			{
				PRINT("\t");
				if (_strlen(dir->d_name) < 7)
					PRINT("\t");
			}
		}
		closedir(d);
	}
	
	PRINT("\n================================================\n");

	return (0);
}
