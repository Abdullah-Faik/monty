#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element
 *       of the stack by the top element of the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 * @value: Unused parameter
 */
void mod(stack_t **stack, unsigned int line_number, char *value)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, ERR_MOD, line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, ERR_DIV_2, line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number, value);
}
