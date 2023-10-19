#include "monty.h"

/**
 *tokenizer - Splits lines into command tokens
 *@i: ith line
 *
 *Return: Nothing
 */
void tokenizer(int i)
{
	char *token = NULL;
	size_t j = 0;

	token = strtok(cmds->lines[i], " ");
	while (j < MAX_ARGS && token != NULL)
	{
		cmds->args[j] = token;
		token = strtok(NULL, " ");
		j++;
	}
}

/**
 * check_op - Checks opcode and pairs it with respective command
 * @stack: Head node in stack_t list
 * @line_number: Line number
 *
 */
void check_op(stack_t **stack, int line_number)
{
	unsigned long int j;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"nop", monty_nop},
		{"sub", sub},
		{"mul", mul},
		{"div", monty_div},
		{"mod", mod},
		{"add", add}
	};
	void (*executor)(stack_t **stack, unsigned int line_number) = NULL;

	for (j = 0; j < sizeof(ops) / sizeof(ops[0]); j++)
	{
		if (strcmp(cmds->args[0], ops[j].opcode) == 0)
		{
			executor = ops[j].f;
			break;
		}
	}
	if (executor != NULL)
		executor(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmds->args[0]);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
}
