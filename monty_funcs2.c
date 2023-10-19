#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 *
 * Description:
 * The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one.
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *top;

	(void) line_number;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	top = (*stack);
	temp = top;

	(*stack) = top->next;
	(*stack)->prev = NULL;

	while (temp->next)
		temp = temp->next;

	temp->next = top;
	top->prev = temp;
	top->next = NULL;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer to the stack (or queue)
 * @line_number: line number in the file
 *
 * Description:
 * The last element of the stack becomes the top one,
 *
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;

	(void) line_number;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	while (last->next)
		last = last->next;

	last->prev->next = NULL;
	last->next = *stack;

	(*stack)->prev = last;
	*stack = last;
	last->prev = NULL;
}

