#ifndef USER_INPUT
#define USER_INPUT

#include "_strlen.h"
#include "hsh.h"

char *get_user_input(void);
void remove_comments(char *str);
char **tokenize(char *str);
char **get_user_input_tokenized(void);

#endif
