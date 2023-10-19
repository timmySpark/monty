#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *monty_div - Divides topmost nodes
 *@stack: Stack
 *@line_number: Line number
 *
 *
 *
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	int len, stack_0 = 0, stack_1 = 0, result = 0;

	stack_t *stack_zero = *stack;
	stack_t *stack_one = *stack, *current = *stack;

	len = stack_len(current);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_all(current);
		exit(EXIT_FAILURE);
	}

	stack_0 = num_at_index(stack_zero, 0);
	if (stack_0 == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(current);
		exit(EXIT_FAILURE);
	}
	stack_1 = num_at_index(stack_one, 1);
	result = stack_1 - stack_0;

	delete_stack_at_index(stack, 0);
	delete_stack_at_index(stack, 0);

	cmds->num = result;
	push(stack, line_number);
}

/**
 *mul - Multiplies topmost nodes
 *@stack: Stack
 *@line_number: Line number
 *
 *
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int len, stack_0 = 0, stack_1 = 0, result = 0;

	stack_t *stack_zero = *stack;
	stack_t *stack_one = *stack, *current = *stack;

	len = stack_len(current);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all(current);
		exit(EXIT_FAILURE);
	}

	stack_0 = num_at_index(stack_zero, 0);
	stack_1 = num_at_index(stack_one, 1);
	result = stack_1 * stack_0;

	delete_stack_at_index(stack, 0);
	delete_stack_at_index(stack, 0);

	cmds->num = result;
	push(stack, line_number);
}

/**
 *mod - Performs mod between topmost nodes
 *@stack: Stack
 *@line_number: Line number
 *
 *
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int len, stack_0 = 0, stack_1 = 0, result = 0;

	stack_t *stack_zero = *stack;
	stack_t *stack_one = *stack, *current = *stack;

	len = stack_len(current);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all(current);
		exit(EXIT_FAILURE);
	}

	stack_0 = num_at_index(stack_zero, 0);
	if (stack_0 == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(current);
		exit(EXIT_FAILURE);
	}
	stack_1 = num_at_index(stack_one, 1);
	result = stack_1 % stack_0;

	delete_stack_at_index(stack, 0);
	delete_stack_at_index(stack, 0);

	cmds->num = result;
	push(stack, line_number);
}


/**
 * add - adds the two top elements
 * @line_number: line number
 * @stack: Stack
 *
 * Return: Exit Failure
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *val1 = *stack, *val2 = *stack;
	stack_t *temp = *stack;
	int len = 0, num1 = 0, num2 = 0, sum = 0;

	len = stack_len(temp);

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all(temp);
		exit(EXIT_FAILURE);
	}

	num1 = num_at_index(val1, 0);
	num2 = num_at_index(val2, 1);
	sum = num1 + num2;

	delete_stack_at_index(stack, 0);
	(*stack)->n = sum;
}
