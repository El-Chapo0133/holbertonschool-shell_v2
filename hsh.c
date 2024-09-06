#include "hsh.h"

struct sigaction old_action;

/**
 * sigint_handler - handler for a sigaction
 * @sig_no: number of sigint passed
 *
 * Return: void
 */
void sigint_handler(int sig_no)
{
	/* handler for any signals */
	if (sig_no == 2)
		return;
}

void restore_fds(int fd_stdout_save, int fd_stdin_save)
{
	dup2(fd_stdout_save, 1);
	dup2(fd_stdin_save, 0);
}

/**
 * main - this is the main function, are you dumb or what
 *
 * Return: exit code
 */
int main(void)
{
	char **user_input_tokenized;
	int is_built_in, status, fd_stdout_save = dup(1), fd_stdin_save = dup(0);
	struct sigaction s_action;

	memset(&s_action, 0, sizeof(s_action));
	s_action.sa_handler = &sigint_handler;
	sigaction(SIGINT, &s_action, &old_action);
	load_base_env();
	while (true)
	{
		PRINT("hsh> ");
		user_input_tokenized = get_user_input_tokenized();
		if (user_input_tokenized == NULL)
			continue;
		handle_redirections(user_input_tokenized);
		is_built_in = check_is_built_in(user_input_tokenized[0]);
		if (is_built_in)
		{
			status = execute_built_in(user_input_tokenized);
			if (status != 0)
				PRINT("ERROR ON BUILT_IN\n");
		}
		else
		{
			status = execute_bin(user_input_tokenized);
			if (status != 0)
				PRINT("ERROR ON BIN EXECVP\n");
		}
		append_cmd(_strcat(user_input_tokenized));
		restore_fds(fd_stdout_save, fd_stdin_save);
	}
	free_history();
	free_envs();
	return (END_SUCCESS);
}
