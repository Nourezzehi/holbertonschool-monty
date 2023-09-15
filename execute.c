#include "monty.h"

/**
 * execute - execute the given line
 * @stack: the given stack
 * @opcode: the read opcode
 * @line_num: number of the given line
*/

void execute(char *opcode, unsigned int line_num, stack_t **stack)
{
	unsigned int i = 0;
	instruction_t tab[] = {
	   {"pall", pall},
	   {"push", push},
	   {"pint", pint},
	   {"pop", pop},
	   {"swap", swap},
	   {"add", add},
	   {"nop", nop},
	   {NULL, NULL}
	};
	while ((tab + i)->opcode != NULL)
	{
		if (!strcmp(opcode, (tab + i)->opcode))
		{
			(tab + i)->f(stack, line_num);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
