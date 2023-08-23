#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 * @value: Value to push onto the stack
 */
void push(stack_t **stack, unsigned int line_number, char *value)
{
	stack_t *my_stack;
	(void)line_number;

	my_stack = malloc(sizeof(stack_t));
	if (my_stack == NULL)
	{
		fprintf(stderr, ERR_MALLOC);
		exit(EXIT_FAILURE);
	}

	new->n = atoi(value);
	new->prev = NULL;
	if (*stack == NULL)
	{
		my_stack->next = NULL;
		my_stack->prev = NULL;
		*stack = my_stack;
	}
	else
	{
		my_stack->next = *stack;
		my_stack->prev = NULL;
		(*stack)->prev = my_stack;
		*stack = my_stack;
	}
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * @value: unused parameter
 */
void pall(stack_t **stack, unsigned int line_number, char *value)
{
	stack_t *temp = *stack;

	(void)value;
	(void)line_number;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file where the opcode is found.
 * @value: Unused parameter.
 */
void pint(stack_t **stack, unsigned int line_number, char *value)
{
	(void)value;

	if (*stack == NULL)
	{
		fprintf(stderr, ERR_PINT, line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
