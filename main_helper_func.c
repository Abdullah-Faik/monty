#include "monty.h"

/**
 * is_number - checks if string is a number
 * @str: string to check
 * Return: 1 if true, 0 if false
 */
int is_number(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	if (str[0] == '-')
		i = 1;
	for (; str[i] != '\0'; i++)
	{
		if (isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}

/**
 * operationfunc - function that checks for opcode
 * @opcode: opcode to check
 * @line_number: line number
 * @stack: pointer to stack
 * @value: Value associated with the opcode (if applicable)
 */
void operationfunc(char *opcode, unsigned int line_number, stack_t **stack,
char *value)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"pall", pall},
		{"push", push},
		{"pint", pint},
		{NULL, NULL}};

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number, value);
			return;
		}
		i++;
	}
	fprintf(stderr, ERR_INST, line_number, opcode);
	exit(EXIT_FAILURE);
}
