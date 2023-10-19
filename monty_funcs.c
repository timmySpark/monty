#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * pint_err - an error that is fired if stack is empty
 * @line_number: line number
 * 
 * Return: Exit Failure
 */
int pint_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pop_err - an error that is fired if stack is empty
 * @line_number: line number
 * 
 * Return: Exit Failure
 */
int pop_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * monty_pint - prints the value of the top of the stack
 * @stack: struct_t stack
 * @line_number: line number
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		pint_err(line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}


/**
 * monty_pop - removes the top element of the stack
 * @stack: struct_t stack
 * @line_number: line number
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		pop_err(line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	delete_stack_at_index(stack, 0);
}

/**
 * monty_nop - Does nothing
 * @stack: struct_t stack
 * @line_number: line number
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void) (*stack);
	(void) (line_number);
}

