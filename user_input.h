#ifndef USER_INPUT
#define USER_INPUT
#define USER_INPUT_MAX_SIZE 128

#include "_strlen.h"

#endif

char *get_user_input(void);
void remove_comments(char *str);
char **tokenize(char *str);
char **get_user_input_tokenized(void);
