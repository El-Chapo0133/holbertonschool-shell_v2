#include "env.h"


static struct EnvVar *EnvVars;

/**
 * print_all_envs - print_all_envs
 *
 * Return: -1 if error, 0 if success
 */
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

/**
 * load_base_env - load base envs
 *
 * Return: -1 if error, 0 if success
 */
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

/**
 * insert_new_env - insert new env
 * @env: new env to insert
 *
 * Return: -1 if error, 0 if success
 */
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

/**
 * free_envs - free all envs
 *
 * Return: void
 */
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

/**
 * env - print all env if they exists
 * @cmd: command passed
 *
 * Return: -1 if error, 0 if success
 */
int env(char **cmd)
{
	if (cmd == NULL)
		return (-1);
	print_all_envs();
	return (0);
}
