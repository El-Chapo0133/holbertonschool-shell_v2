#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "_strlen.h"
#include "user_input.h"
#include "is_built_in.h"

#define true 1
#define false 0
#define END_SUCCESS 0
#define END_ERROR 1
#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))

#endif
