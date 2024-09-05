#ifndef ENV
#define ENV

#include "hsh.h"
#include <string.h>

extern char **environ;

typedef struct EnvVar
{
	char *env;
	struct EnvVar *next;
} EnvVar;

int print_all_envs(void);
int load_base_env(void);
int insert_new_env(char *cmd);
void free_envs(void);
int env(char **cmd);

#endif
