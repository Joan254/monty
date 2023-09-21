#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack
 * @head: head of the linked list
 * @line_num: line number
 *
 * Return: no return
 */
void _pchar(stack_t **head, unsigned int line_num)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
		free_glovar();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n >= 128)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
		free_glovar();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
