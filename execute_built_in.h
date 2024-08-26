#include <stdio.h>
#include <stdlib.h>
#include "_strcmp.h"
#include "hsh.h"

#ifndef BUILT_IN
#define BUILT_IN

/* BUILT-IN INCLUDES */
#include "history.h"
#include "cd.h"
#include "help.h"
#include "echo.h"
#include "env.h"

typedef struct BuiltIn
{
	char *cmd;
	int (*fun)(char **tokens);
} BuiltIn;

int execute_built_in(char **cmd);
#endif
