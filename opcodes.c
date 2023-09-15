#include "monty.h"

/**
 * push - push to the stack
 * @stack: the data structure
 * @line_num: number of the line
*/

void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!isdigit(*arg))
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	(void) line_num;
	new_node->n = atoi(arg);
	new_node->prev = NULL;
	if ((*stack) != NULL)
	{
		new_node->next = (*stack);
		(*stack)->prev = new_node;
	}
	else
		new_node->next = NULL;
	(*stack) = new_node;
}

/**
 * pall - print stack's values
 * @stack: the data structure
 * @line_num: number of the line
*/

void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *move = *stack;

	while (move)
	{
		printf("%d\n", move->n);
		move = move->next;
	}
	(void) line_num;
}
/**
 * pint - print the top of a stack
 * @stack: the stack
 * @line_num : the number of the line
*/

void pint(stack_t **stack, unsigned int line_num)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - removes the top of the stack
 * @stack: our stack
 * @line_num: the line's number
*/

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = ptr->next;
	if (ptr->next != NULL)
		ptr->next->prev = NULL;
	free(ptr);
}

/**
 * swap - swap the top two elements of the stack
 * @stack: the stack
 * @line_num: the line's number
*/

void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *p1 = (*stack);

	if (!(*stack)->next || !(*stack))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
		stack_t *p2 = (*stack)->next;

		p1->next = p2->next;
		p1->prev = p2;
		p2->prev = NULL;
		p2->next = p1;

		(*stack) = p2;
}
