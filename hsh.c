#include "hsh.h"


int main(void)
{
	char **user_input_tokenized;
	int index = 0, is_built_in;

	while (true)
	{
		/* print hsh prompt */
		PRINT("hsh> ");

		/* get and tokenize user input */
		user_input_tokenized = get_user_input_tokenized();
		if (user_input_tokenized[0] == NULL)
			continue;
		
		/* execute user input */
		is_built_in = check_is_built_in(user_input_tokenized[0]);
		if (is_built_in)
			PRINT("This function is built in");
		else
			PRINT("This function is NOT built in");

		index++;
		printf("%d\n", index);
	}

	return (END_SUCCESS);	
}
