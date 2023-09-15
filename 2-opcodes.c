#include "monty.h"

/**
 * add - add the top 2 elements of the stack
 * @stack: the stack
 * @line_number: num of the line
 */

void add(stack_t **stack, unsigned int line_number)
{

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
		(*stack)->next->n += (*stack)->n;
		pop(stack, line_number);
}

/**
 * nop - nothing to do
 * @stack: the stack
 * @line_number: num of the line
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
