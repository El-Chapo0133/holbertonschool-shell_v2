#ifndef REDIRECTION
#define REDIRECTION

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

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

struct RedirectTo *find_redirections(char **cmd);
void handle_redirections(char **cmd);

#endif
