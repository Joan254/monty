#include "monty.h"

/**
 * _pop - removes the top element of the stack
 *
 * @head: head of the linked list
 * @line_num: line number
 * Return: void
 */
void _pop(stack_t **head, unsigned int line_num)
{
	stack_t *temp;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		free_glovar();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
