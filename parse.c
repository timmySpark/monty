#include "monty.h"
#include <stdio.h>
#include <string.h>

/**
 *rmv_space - Removes unnecessary character from input string
 *@cmd: Input string
 *
 *Return: Corrected string
 */
char *rmv_space(char *cmd)
{
	int i, j = 0;
	char *cmd_clean;
	bool prev_space = (cmd[0] == ' ' || cmd[0] == '\t');

	cmd_clean = malloc(strlen(cmd) + 1);

	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == ' ' || cmd[i] == '\t')
		{
			if (!prev_space)
				cmd_clean[j++] = cmd[i];
			prev_space = true;
		}
		else
		{
			cmd_clean[j++] = cmd[i];
			prev_space = false;
		}
	}
	cmd_clean[j] = '\0';
	free(cmd);
	cmd = cmd_clean;
	return (cmd);
}

/**
 *parse - Splits buffer into lines
 *
 */
void parse(void)
{
	char *buffer = cmds->buffer;
	char *token = NULL;
	/*int *i = &(cmds->line_count);*/
	int j = 0;

	token = strtok(buffer, "\n");
	while (j < MAX_LINES && token != NULL)
	{
		cmds->lines[j] = _strdup(token);
		token = strtok(NULL, "\n");
		cmds->lines[j] = rmv_space(cmds->lines[j]);
		j++;
	}
	cmds->line_count = j;
}


#include <stdio.h>
#include <string.h>

/**
 * add_hash - Adds '#' between successive newline characters in a string.
 * @inputString: The input string to be modified.
 * @outputString: The output string where the modified string is stored.
 */
void add_hash(char *inputString, char *outputString)
{
	int i, j = 0;
	int newlineCount = 0;

	for (i = 0; inputString[i] != '\0'; i++)
	{
		if (inputString[i] == '\n')
		{
			if (newlineCount == 0)
			{
				outputString[j++] = inputString[i];
				newlineCount = 0;
			}
			else
			{
				outputString[j++] = '\n';
				outputString[j++] = '#';
				outputString[j++] = '\n';
			}
			newlineCount++;
		}
		else
		{
			newlineCount = 0;
			outputString[j++] = inputString[i];
		}
	}
	outputString[j] = '\0';
}
