#include "env.h"


extern char **environ;
static struct EnvVar *EnvVars;

int print_all_envs(void)
{
	struct EnvVar *head = EnvVars;

	while (head != NULL)
	{
		PRINT(head->env);
		PRINT("\n");

		head = head->next;
	}
	return (0);
}

int load_base_env(void)
{
	int index = 0, status;

	while (environ[index] != NULL)
	{
		status = insert_new_env(environ[index++]);
		if (status != 0)
			return (-1);
	}
	return (0);
}

int insert_new_env(char *env)
{
	struct EnvVar *head = EnvVars;
	struct EnvVar *new_env = malloc(sizeof(EnvVar));
	new_env->env = env;
	new_env->next = NULL;

	if (EnvVars == NULL)
	{
		EnvVars = new_env;
		return (0);
	}

	while (head->next != NULL)
		head = head->next;
	head->next = new_env;

	return (0);
}

void free_envs(void)
{
	struct EnvVar *temp;
	while (EnvVars != NULL)
	{
		temp = EnvVars->next;
		free(EnvVars->env);
		free(EnvVars);
		EnvVars = temp;
	}
}

int env(char **cmd)
{
	if (cmd == NULL)
		return (-1);
	print_all_envs();
	return (0);
}
