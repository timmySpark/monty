#include "monty.h"
#include <stdio.h>

cmd_t *cmds = NULL;
/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	cmds = (cmd_t *)malloc(sizeof(cmd_t));
	read_code(argv[1]);
	add_hash(cmds->buffer, cmds->buffer2);
	strcpy(cmds->buffer, cmds->buffer2);
	parse();
	executer();
	for (i = 0; i < cmds->line_count; i++)
		free(cmds->lines[i]);
	free(cmds);
	return (0);
}
