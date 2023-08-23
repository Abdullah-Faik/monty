#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 * @value: Unused parameter
 */
void pop(stack_t **stack, unsigned int line_number, char *value)
{
	stack_t *temp;

	(void)value;
	if (*stack == NULL)
	{
		fprintf(stderr, ERR_POP, line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack == NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 * @value: Unused parameter
 */
void add(stack_t **stack, unsigned int line_number, char *value)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, ERR_ADD, line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number, value);
}
