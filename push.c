#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @head: head of the linked list
 * @line_num: line number
 * Return: void
 */
void _push(stack_t **head, unsigned int line_num)
{
	int n, j;

	if (!glovar.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		free_glovar();
		exit(EXIT_FAILURE);
	}

	for (j = 0; glovar.arg[j] != '\0'; j++)
	{
		if (!isdigit(glovar.arg[j]) && glovar.arg[j] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			free_glovar();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(glovar.arg);

	if (glovar.lifo == 1)
		add_dnodeint(head, n);
	else
		add_dnodeint_end(head, n);
}
