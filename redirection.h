#ifndef REDIRECTION
#define REDIRECTION

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define true 1
#define false 0

/**
 * struct RedirectTo - define the redirection from and to
 * if NULL, no need to redirect
 *
 * @to: redirection for stdout
 * @from: redirection for stdin
 */
typedef struct RedirectTo
{
	char *to;
	char *from;
}

RedirectTo *find_redirections(char **cmd);
void handle_redirections(char **cmd);

#endif
