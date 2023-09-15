#include "monty.h"

/**
 * free_stack - free a stack
 * @stack: our data structure
*/

void free_stack(stack_t *stack)
{
	stack_t *move;

	if (!stack)
		return;
	while (stack != NULL)
	{
		move = stack->next;
		free(stack);
		stack = move;
	}
}
