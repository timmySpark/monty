#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *executer - Tokenizes, pairs and executes commands
 *
 */
void executer(void)
{
	int i = 0, line_number = 1;
	stack_t *stack = NULL;

	for (i = 0; i < cmds->line_count; i++)
	{
		char *endptr;
		int num;

		cmds->args[0] = NULL;
		cmds->args[1] = NULL;
		tokenizer(i);
		if (cmds->args[0] == NULL || cmds->args[0][0] == '#'
	|| cmds->args[0][0] == '\0')
		{
			line_number++;
			continue;
		}
		if (strcmp(cmds->args[0], "push") == 0)
		{
			if (cmds->args[1] == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_all(stack);
				exit(EXIT_FAILURE);
			}

			num = (int)strtol(cmds->args[1], &endptr, 10);
			if (endptr == cmds->args[1] || *endptr != '\0')
			{
				fprintf(stderr, "L%d: usage: push integer\n",
line_number);
				free_all(stack);
				exit(EXIT_FAILURE);
			}
			cmds->num = num;
		}
		check_op(&stack, line_number);
		line_number++;
	}
	free_stack(stack);
}
