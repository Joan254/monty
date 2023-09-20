#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 *
 * @head: head of the linked list
 * @line_num: line number
 * Return: void
 */
void _add(stack_t **head, unsigned int line_num)
{
	int i = 0;
	stack_t *temp = NULL;

	temp = *head;

	for (; temp != NULL; temp = temp->next, i++)
		;

	if (i < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		free_glovar();
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp->n += (*head)->n;
	_pop(head, line_num);
}
