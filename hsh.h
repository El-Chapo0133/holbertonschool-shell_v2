#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "_strlen.h"
#include "_strcat.h"
#include "user_input.h"
#include "is_built_in.h"
#include "history.h"
#include "execute_built_in.h"
#include "env.h"
#include "exec_bin.h"

#define true 1
#define false 0
#define END_SUCCESS 0
#define END_ERROR 1
#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define USER_INPUT_MAX_SIZE 128

#endif
