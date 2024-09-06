#ifndef ENV
#define ENV

#include "hsh.h"
#include <string.h>

extern char **environ;

/**
 * struct EnvVar - node of linked list envs
 * @env: env name '=' env values
 * @next: next node in linked list
 */
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
