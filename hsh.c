#include "hsh.h"


int main(void)
{
	char **user_input_tokenized;
	int is_built_in, status;

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
			if (status != 0)
				PRINT("ERROR ON BUILT_IN");
		}
		else
			PRINT("This function is NOT built in\n");

		/* append command to history */
		append_cmd(_strcat(user_input_tokenized));
	}

	/* free the linked list history */
	free_history();

	return (END_SUCCESS);	
}
