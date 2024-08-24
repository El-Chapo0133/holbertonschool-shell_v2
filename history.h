#ifndef HISTORY
#define HISTORY

#include "hsh.h"

/**
 * struct HistoryNode - node of linked list history
 * @cmd: command used
 * @next: next node in linked list
 */
typedef struct HistoryNode
{
	char *cmd;
	struct HistoryNode *next;
} HistoryNode;

void append_cmd(char *cmd);
int print_history(char **cmd);
void free_history(void);
#endif
