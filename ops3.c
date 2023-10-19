#include "monty.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *pchar - Prints char at top of stack
 *@stack: Top of stack
 *@line_number: Line number
 *
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	if (top->n >= 0 && top->n <= 127)
		printf("%c\n", (char)top->n);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_all(top);
		exit(EXIT_FAILURE);
	}
}
/**
 *pstr - Prints string starting at top of stack
 *@stack: Top of stack
 *@line_number: Line number
 *
 *
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	(void)line_number;
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	current = *stack;

	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		printf("%c\n", (char)current->n);
		current = current->next;
	}
}
