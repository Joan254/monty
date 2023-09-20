#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 *
 * @head: head of the linked list
 * @line_num: line number
 * Return: void
 */
void _pint(stack_t **head, unsigned int line_num)
{
	(void)line_num;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		free_glovar();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
