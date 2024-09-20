#ifndef REDIRECTION
#define REDIRECTION

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "_strcmp.h"

void handle_redirections(char **cmd);

#endif
