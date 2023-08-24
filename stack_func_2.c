#include "monty.h"
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
/**
 * nop - Does nothing.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file where the opcode is found.
 * @value: Unused parameter.
 * Return: Nothing.
 */
void nop(stack_t **stack, unsigned int line_number, char *value)
{
	(void)stack;
	(void)line_number;
	(void)value;
}

/**
 * sub - Subtracts the top element of the stack from the second top element
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 * @value: Unused parameter
 */
void sub(stack_t **stack, unsigned int line_number, char *value)
{
	if (stack == NULL ||*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, ERR_SUB, line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number, value);
}