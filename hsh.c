#include "hsh.h"

struct sigaction old_action;

void sigint_handler(int sig_no)
{
	/* handler for any signals */
}

int main(void)
{
	char **user_input_tokenized;
	int is_built_in, status;
	struct sigaction s_action;

	memset(&s_action, 0, sizeof(s_action));
	s_action.sa_handler = &sigint_handler;
	sigaction(SIGINT, &s_action, &old_action);
	/* load the existants ENV */
	load_base_env();
	while (true)
	{
		/* print hsh prompt */
		PRINT("hsh> ");
		/* get and tokenize user input */
		user_input_tokenized = get_user_input_tokenized();
		/* when no user input, skip to next loop */
		if (user_input_tokenized == NULL)
			continue;
		/* execute user input */
		is_built_in = check_is_built_in(user_input_tokenized[0]);
		if (is_built_in)
		{
			status = execute_built_in(user_input_tokenized);
			if (status == 1)
				exit(END_SUCCESS);
			else if (status != 0)
				PRINT("ERROR ON BUILT_IN\n");
		}
		else
		{
			status = execute_bin(user_input_tokenized);
			if (status != 0)
				PRINT("ERROR ON BIN EXECVP\n");
		}
		/* append command to history */
		append_cmd(_strcat(user_input_tokenized));
	}
	free_history();
	free_envs();
	return (END_SUCCESS);
}
