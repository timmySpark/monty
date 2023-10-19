#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *push - Adds new node at the head of a dlistint_t list
 *@stack: Pointer to Pointer to first node
 *@line_number: Line number
 *
 *Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;

	(void)line_number;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = cmds->num;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (*stack == NULL)
		*stack = newNode;
	else
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
		*stack = newNode;
	}
}

/**
 *pall - Prints data in a dlistint_t list
 *@stack: Head of list
 *@line_number: Line number
 *
 *
 *Return: Number of node
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	if (*stack == NULL || !*stack)
		return;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 *sub - Subtracts top node from second to top node
 *@stack: Stack list
 *@line_number: Line number
 *
 *
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int len, stack_0 = 0, stack_1 = 0, result = 0;

	stack_t *stack_zero = *stack;
	stack_t *stack_one = *stack, *current = *stack;

	len = stack_len(current);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all(current);
		exit(EXIT_FAILURE);
	}

	stack_0 = num_at_index(stack_zero, 0);
	stack_1 = num_at_index(stack_one, 1);
	result = stack_1 - stack_0;

	delete_stack_at_index(stack, 0);
	delete_stack_at_index(stack, 0);

	cmds->num = result;
	push(stack, line_number);
}


/**
 *swap - Swap top values in stack
 *@stack: Pointer to pointer to stack_t list
 *@line_number: Line number
 *
 *
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int len, first, next;
	stack_t *head = *stack, *current = *stack;

	len = stack_len(head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	first = current->n;
	next = current->next->n;

	delete_stack_at_index(stack, 0);
	delete_stack_at_index(stack, 0);

	cmds->num = first;
	push(stack, line_number);
	cmds->num = next;
	push(stack, line_number);
}
