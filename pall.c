#include "monty.h"

/**
 * _pall - prints all values on the stack, starting from
 * the top of the stack
 *
 * @head: head of the linked list
 * @line_num: line number
 * Return: void
 */
void _pall(stack_t **head, unsigned int line_num)
{
	stack_t *temp;
	(void)line_num;

	temp = *head;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
