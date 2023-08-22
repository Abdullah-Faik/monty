#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, ERR_MALLOC);
		exit(EXIT_FAILURE);
	}

	if (is_number(glob_val) == 0)
	{
		fprintf(stderr, ERR_PUSH, line_number);
		free(new);
		exit(EXIT_FAILURE);
	}

	new->n = glob_val;
	new->prev = NULL;
	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
	} else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

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
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, ERR_PINT, line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
