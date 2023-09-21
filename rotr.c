#include "monty.h"

/**
 * _rotr - rotates the stack to the bottom, the last element
 * of the stack becomes the top element of the stack
 * @head: head of the linked list
 * @line_num: line number
 *
 * Return: no return
 */
void _rotr(stack_t **head, unsigned int line_num)
{
	stack_t *temp = NULL;
	(void)line_num;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	temp = *head;

	for (; temp->next != NULL; temp = temp->next)
		;

	temp->prev->next = NULL;
	temp->next = *head;
	temp->prev = NULL;
	(*head)->prev = temp;
	*head = temp;
}
