#include "monty.h"

/**
 * _rotl - rotates the stack to the top, the top element
 * of the stack becomes the last one, and the second top
 * element of the stack becomes the first one
 * @head: head of the linked list
 * @line_num: line number
 *
 * Return: no return
 */
void _rotl(stack_t **head, unsigned int line_num)
{
	stack_t *temp1 = NULL;
	stack_t *temp2 = NULL;
	(void)line_num;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	temp1 = (*head)->next;
	temp2 = *head;

	for (; temp2->next != NULL; temp2 = temp2->next)
		;

	temp1->prev = NULL;
	temp2->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp2;
	*head = temp1;
}
