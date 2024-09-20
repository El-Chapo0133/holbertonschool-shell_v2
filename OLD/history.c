#include "history.h"

static struct HistoryNode *head_history;

/**
 * append_cmd - append a command to linked list history
 * @cmd: command used
 *
 * Return: void
 */
void append_cmd(char *cmd)
{
	struct HistoryNode *node = malloc(sizeof(HistoryNode));
	struct HistoryNode *temp_head;

	if (node == NULL)
	{
		PRINT("Memory error :(");
		exit(END_ERROR);
	}
	node->cmd = cmd;
	node->next = NULL;

	/* first node */
	if (head_history == NULL)
	{
		head_history = node;
	}
	/* move to last node and append */
	else
	{
		temp_head = head_history;
		while (temp_head != NULL)
		{
			if (temp_head->next == NULL)
			{
				temp_head->next = node;
				break;
			}
			temp_head = temp_head->next;
		}
	}
}

/**
 * print_history - print the linked list with an index to each
 * @cmd: command passed
 *
 * Return: void
 */
int print_history(char **cmd)
{
	int index = 0, bits;
	char *buf = malloc(sizeof(char) * 7);
	HistoryNode *node = head_history;

	if (cmd == NULL)
		return (-1);
	while (node != NULL)
	{
		/* convert int index to char* with format */
		bits = sprintf(buf, " %d  ", index);
		if (bits == 0) /* Problems :( */
			break;

		/* write history as " <index>  <cmd>\n" */
		PRINT(buf);
		PRINT(node->cmd);
		PRINT("\n");

		index++;
		node = node->next;
	}
	return (0);
}

/**
 * free_history - free the whole linked list
 *
 * Return: void
 */
void free_history(void)
{
	struct HistoryNode *next;

	while (head_history != NULL)
	{
		next = head_history->next;
		free(head_history->cmd);
		free(head_history);
		head_history = next;
	}
}
