#include "monty.h"

/**
 * read - read and parse the readen line
 * @input_line: the read line
 * @stack: the stack
 * @line_num: line's num
*/

void read_line(char *input_line, unsigned int line_num, stack_t **stack)
{
    char *opcode = NULL; 

    opcode = strtok(input_line, TOKDELIM);
    if (opcode)
    {
        arg = strtok(NULL, " \t\n");
        if (!strcmp(opcode, "push") && (!arg || !isdigit(*arg)))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			free_stack(*stack);
			free(input_line);
			exit(EXIT_FAILURE);
		}
        else
            execute(opcode, line_num, stack);
    }
}